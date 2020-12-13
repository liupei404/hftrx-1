/*
 * usbd_cdc.c
 * Проект HF Dream Receiver (КВ приёмник мечты)
 * автор Гена Завидовский mgs2001@mail.ru
 * UA1ARN
*/

#include "hardware.h"

#if WITHUSBHW && WITHUSBRNDIS

#include <stdbool.h>
#include <stddef.h>
#include "rndis_protocol.h"


#include "formats.h"
#include "usb_core.h"

#include "lwip/opt.h"
#include "lwip/init.h"
#include "lwip/pbuf.h"
#include "lwip/netif.h"
#include "netif/etharp.h"

//
//#define RNDIS_CONTROL_OUT_PMAADDRESS                    (0x08 * 4)                //8 bytes per EP
//#define RNDIS_CONTROL_IN_PMAADDRESS                     (RNDIS_CONTROL_OUT_PMAADDRESS + USB_MAX_EP0_SIZE)
//#define RNDIS_NOTIFICATION_IN_PMAADDRESS                (RNDIS_CONTROL_IN_PMAADDRESS + USB_MAX_EP0_SIZE)
//#define RNDIS_DATA_IN_PMAADDRESS                        (RNDIS_NOTIFICATION_IN_PMAADDRESS + RNDIS_NOTIFICATION_IN_SZ)
//#define RNDIS_DATA_OUT_PMAADDRESS                       (RNDIS_DATA_IN_PMAADDRESS + USBD_RNDIS_IN_BUFSIZE)

#define RNDIS_MTU                                       1500                           // MTU value
#if WITHUSBDEV_HSDESC
	#define ETH_LINK_SPEED                                  480000000                       // bits per sec
#else /* WITHUSBDEV_HSDESC */
	#define ETH_LINK_SPEED                                  12000000                       // bits per sec
#endif /* WITHUSBDEV_HSDESC */
#define RNDIS_VENDOR                                    "fetisov"                      // NIC vendor name
#define STATION_HWADDR                                  0x30,0x89,0x84,0x6A,0x96,0xAA  // station MAC
#define PERMANENT_HWADDR                                0x30,0x89,0x84,0x6A,0x96,0xAA  // permanent MAC

#define ETH_HEADER_SIZE                 14
#define ETH_MIN_PACKET_SIZE             60
#define ETH_MAX_PACKET_SIZE             (ETH_HEADER_SIZE + RNDIS_MTU)
#define RNDIS_HEADER_SIZE               (sizeof (rndis_data_packet_t))
#define RNDIS_RX_BUFFER_SIZE            (ETH_MAX_PACKET_SIZE + RNDIS_HEADER_SIZE)

typedef void (*rndis_rxproc_t)(const uint8_t *data, int size);
static rndis_state_t rndis_state;
static rndis_rxproc_t rndis_rxproc = NULL;

static usb_eth_stat_t usb_eth_stat = { 0, 0, 0, 0 };

static int rndis_rx_start(void);
static uint8_t *rndis_rx_data(void);
static uint16_t rndis_rx_size(void);

static int rndis_tx_start(uint8_t *data, uint16_t size);
static int rndis_tx_started(void);

static int rndis_can_send(void);
static int rndis_send(const void *data, int size);

static int outputs = 0;


static struct netif rndis_netif_data;

// Transceiving Ethernet packets
static err_t rndis_linkoutput_fn(struct netif *netif, struct pbuf *p)
{
	PRINTF("rndis_linkoutput_fn\n");
    int i;
    struct pbuf *q;
    static char data[RNDIS_MTU + 14 + 4];
    int size = 0;
    for (i = 0; i < 200; i++)
    {
        if (rndis_can_send()) break;
        local_delay_ms(1);
    }
    for(q = p; q != NULL; q = q->next)
    {
        if (size + q->len > RNDIS_MTU + 14)
            return ERR_ARG;
        memcpy(data + size, (char *)q->payload, q->len);
        size += q->len;
    }
    if (!rndis_can_send())
        return ERR_USE;
    rndis_send(data, size);
    outputs++;
    return ERR_OK;
}


static err_t output_fn(struct netif *netif, struct pbuf *p, ip_addr_t *ipaddr)
{
  return etharp_output(netif, p, ipaddr);
}

static err_t netif_init_cb(struct netif *netif)
{
	PRINTF("rndis netif_init_cb\n");
  LWIP_ASSERT("netif != NULL", (netif != NULL));
  netif->mtu = RNDIS_MTU;
  netif->flags = NETIF_FLAG_BROADCAST | NETIF_FLAG_ETHARP | NETIF_FLAG_LINK_UP | NETIF_FLAG_UP;
  netif->state = NULL;
  netif->name[0] = 'E';
  netif->name[1] = 'X';
  netif->linkoutput = rndis_linkoutput_fn;
  netif->output = output_fn;
  return ERR_OK;
}
/*
TIMER_PROC(tcp_timer, TCP_TMR_INTERVAL * 1000, 1, NULL)
{
  tcp_tmr();
}
*/


typedef struct rndisbuf_tag
{
	LIST_ENTRY item;
	struct pbuf *frame;
} ALIGNX_END rndisbuf_t;


static LIST_ENTRY rndis_free;
static LIST_ENTRY rndis_ready;

static void rndis_buffers_initialize(void)
{
	static RAMFRAMEBUFF rndisbuf_t sliparray [64];
	unsigned i;

	InitializeListHead(& rndis_free);	// Незаполненные
	InitializeListHead(& rndis_ready);	// Для обработки

	for (i = 0; i < (sizeof sliparray / sizeof sliparray [0]); ++ i)
	{
		rndisbuf_t * const p = & sliparray [i];
		InsertHeadList(& rndis_free, & p->item);
	}
}

static int rndis_buffers_alloc(rndisbuf_t * * tp)
{
	if (! IsListEmpty(& rndis_free))
	{
		const PLIST_ENTRY t = RemoveTailList(& rndis_free);
		rndisbuf_t * const p = CONTAINING_RECORD(t, rndisbuf_t, item);
		* tp = p;
		return 1;
	}
	if (! IsListEmpty(& rndis_ready))
	{
		const PLIST_ENTRY t = RemoveTailList(& rndis_ready);
		rndisbuf_t * const p = CONTAINING_RECORD(t, rndisbuf_t, item);
		* tp = p;
		return 1;
	}
	return 0;
}

static int rndis_buffers_ready_user(rndisbuf_t * * tp)
{
	system_disableIRQ();
	if (! IsListEmpty(& rndis_ready))
	{
		const PLIST_ENTRY t = RemoveTailList(& rndis_ready);
		system_enableIRQ();
		rndisbuf_t * const p = CONTAINING_RECORD(t, rndisbuf_t, item);
		* tp = p;
		return 1;
	}
	system_enableIRQ();
	return 0;
}


static void rndis_buffers_release(rndisbuf_t * p)
{
	InsertHeadList(& rndis_free, & p->item);
}

static void rndis_buffers_release_user(rndisbuf_t * p)
{
	system_disableIRQ();
	rndis_buffers_release(p);
	system_enableIRQ();
}

// сохранить принятый
static void rndis_buffers_rx(rndisbuf_t * p)
{
	InsertHeadList(& rndis_ready, & p->item);
}

static void on_packet(const uint8_t *data, int size)
{
	rndisbuf_t * p;
	if (rndis_buffers_alloc(& p) != 0)
	{
		struct pbuf *frame;
		frame = pbuf_alloc(PBUF_RAW, size, PBUF_POOL);
		if (frame == NULL)
		{
			rndis_buffers_release(p);
			return;
		}
		memcpy(frame->payload, data, size);
		frame->len = size;

		p->frame = frame;
		rndis_buffers_rx(p);
	}
}



// Receiving Ethernet packets
// user-mode function
void usb_polling(void)
{
	rndisbuf_t * p;
	if (rndis_buffers_ready_user(& p) != 0)
	{
		err_t e = ethernet_input(p->frame, & rndis_netif_data);
		if (e != ERR_OK)
		{
			  /* This means the pbuf is freed or consumed,
			     so the caller doesn't have to free it again */
		}

		rndis_buffers_release_user(p);
	}
}

struct netif  * getNetifData(void)
{
	return &rndis_netif_data;
}

void init_netif(void)
{
	rndis_buffers_initialize();

	static const  uint8_t hwaddrv [6]  = { HWADDR };

	static ip_addr_t netmask;// [4] = NETMASK;
	static ip_addr_t gateway;// [4] = GATEWAY;

	IP4_ADDR(& netmask, myNETMASK [0], myNETMASK [1], myNETMASK [2], myNETMASK [3]);
	IP4_ADDR(& gateway, myGATEWAY [0], myGATEWAY [1], myGATEWAY [2], myGATEWAY [3]);

	static ip_addr_t vaddr;// [4]  = IPADDR;
	IP4_ADDR(& vaddr, myIP [0], myIP [1], myIP [2], myIP [3]);

	struct netif  *netif = &rndis_netif_data;
	netif->hwaddr_len = 6;
	memcpy(netif->hwaddr, hwaddrv, 6);

	netif = netif_add(netif, & vaddr, & netmask, & gateway, NULL, netif_init_cb, ip_input);
	netif_set_default(netif);

	while (!netif_is_up(&rndis_netif_data))
		;

	rndis_rxproc = on_packet;		// разрешаем принимать пакеты даптеру и отправляьь в LWIP
}

static void USBD_RNDIS_ColdInit(void)
{
}

/*
* The MIT License (MIT)
*
* Copyright (c) 2015 by Sergey Fetisov <fsenok@gmail.com>
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

/*
* version: 1.0 demo (7.02.2015)
*/

// RNDIS to USB Mapping https://msdn.microsoft.com/en-us/library/windows/hardware/ff570657(v=vs.85).aspx
//
//#include "usbd_conf.h"
//#include "usbd_rndis.h"
//#include "usbd_desc.h"
//#include "usbd_ctlreq.h"

/*******************************************************************************
Private constants
*******************************************************************************/

const uint32_t OIDSupportedList[] =
{
  OID_GEN_SUPPORTED_LIST,
  OID_GEN_HARDWARE_STATUS,
  OID_GEN_MEDIA_SUPPORTED,
  OID_GEN_MEDIA_IN_USE,
  //    OID_GEN_MAXIMUM_LOOKAHEAD,
  OID_GEN_MAXIMUM_FRAME_SIZE,
  OID_GEN_LINK_SPEED,
  //    OID_GEN_TRANSMIT_BUFFER_SPACE,
  //    OID_GEN_RECEIVE_BUFFER_SPACE,
  OID_GEN_TRANSMIT_BLOCK_SIZE,
  OID_GEN_RECEIVE_BLOCK_SIZE,
  OID_GEN_VENDOR_ID,
  OID_GEN_VENDOR_DESCRIPTION,
  OID_GEN_VENDOR_DRIVER_VERSION,
  OID_GEN_CURRENT_PACKET_FILTER,
  //    OID_GEN_CURRENT_LOOKAHEAD,
  //    OID_GEN_DRIVER_VERSION,
  OID_GEN_MAXIMUM_TOTAL_SIZE,
  OID_GEN_PROTOCOL_OPTIONS,
  OID_GEN_MAC_OPTIONS,
  OID_GEN_MEDIA_CONNECT_STATUS,
  OID_GEN_MAXIMUM_SEND_PACKETS,
  OID_802_3_PERMANENT_ADDRESS,
  OID_802_3_CURRENT_ADDRESS,
  OID_802_3_MULTICAST_LIST,
  OID_802_3_MAXIMUM_LIST_SIZE,
  OID_802_3_MAC_OPTIONS
};

#define OID_LIST_LENGTH (sizeof(OIDSupportedList) / sizeof(*OIDSupportedList))
#define ENC_BUF_SIZE    (OID_LIST_LENGTH * 4 + 32)

/*******************************************************************************
Private function definitions
*******************************************************************************/
static void response_available(USBD_HandleTypeDef *pdev);

/*********************************************
RNDIS Device library callbacks
*********************************************/
static USBD_StatusTypeDef  usbd_rndis_init                         (USBD_HandleTypeDef *pdev, uint_fast8_t cfgidx);
static USBD_StatusTypeDef  usbd_rndis_deinit                       (USBD_HandleTypeDef *pdev, uint_fast8_t cfgidx);
static USBD_StatusTypeDef  usbd_rndis_setup                        (USBD_HandleTypeDef *pdev, const USBD_SetupReqTypedef *req);
static USBD_StatusTypeDef  usbd_rndis_ep0_recv                     (USBD_HandleTypeDef *pdev);
static USBD_StatusTypeDef  usbd_rndis_data_in                      (USBD_HandleTypeDef *pdev, uint_fast8_t epnum);
static USBD_StatusTypeDef  usbd_rndis_data_out                     (USBD_HandleTypeDef *pdev, uint_fast8_t epnum);
static USBD_StatusTypeDef  usbd_rndis_sof                          (USBD_HandleTypeDef *pdev);
static USBD_StatusTypeDef  rndis_iso_in_incomplete                 (USBD_HandleTypeDef *pdev, uint_fast8_t epnum);
static USBD_StatusTypeDef  rndis_iso_out_incomplete                (USBD_HandleTypeDef *pdev, uint_fast8_t epnum);

/*******************************************************************************
Private variables
*******************************************************************************/
static USBD_HandleTypeDef *hold_pDev;

static uint8_t station_hwaddr[6] = { STATION_HWADDR };
static uint8_t permanent_hwaddr[6] = { PERMANENT_HWADDR };
static rndis_state_t rndis_state = rndis_uninitialized;
static uint32_t oid_packet_filter = 0x0000000;
static USBALIGN_BEGIN uint8_t encapsulated_buffer [ENC_BUF_SIZE] USBALIGN_END;

static uint16_t rndis_tx_data_size = 0;
static int rndis_tx_transmitting = false;
static int rndis_tx_ZLP = false;
static USBALIGN_BEGIN uint8_t usb_rx_buffer [USBD_RNDIS_OUT_BUFSIZE] USBALIGN_END ;
static USBALIGN_BEGIN uint8_t rndis_rx_buffer [RNDIS_RX_BUFFER_SIZE]  USBALIGN_END;
static uint16_t rndis_rx_data_size = 0;
static int rndis_rx_started = false;
static uint8_t *rndis_tx_ptr = NULL;
static int rndis_first_tx = 1;
static int rndis_tx_size = 0;
static int rndis_sended = 0;

static int rndis_rx_start(void)
{
  if (rndis_rx_started)
    return false;

  ASSERT(hold_pDev != NULL);
  rndis_rx_started = 1;
  USBD_LL_PrepareReceive(hold_pDev,
                         USBD_EP_RNDIS_OUT,
						 usb_rx_buffer,
						 USBD_RNDIS_OUT_BUFSIZE);
  return 1;
}

static uint8_t *rndis_rx_data(void)
{
  if (rndis_rx_size())
    return rndis_rx_buffer + RNDIS_HEADER_SIZE;
  else
    return NULL;
}

static uint16_t rndis_rx_size(void)
{
  if (!rndis_rx_started)
    return rndis_rx_data_size;
  else
    return 0;
}

/* __weak */ void rndis_rx_ready_cb(void)
{
}

int rndis_tx_start(uint8_t *data, uint16_t size)
{
	unsigned sended;
	static uint8_t first [USBD_RNDIS_IN_BUFSIZE];
	rndis_data_packet_t *hdr;

  //if tx buffer is already transfering or has incorrect length
  if ((rndis_tx_transmitting) || (size > ETH_MAX_PACKET_SIZE) || (size == 0))
  {
    usb_eth_stat.txbad++;
    return false;
  }

  rndis_tx_transmitting = 1;
  rndis_tx_ptr = data;
  rndis_tx_data_size = size;


  hdr = (rndis_data_packet_t *)first;
  memset(hdr, 0, RNDIS_HEADER_SIZE);
  hdr->MessageType = REMOTE_NDIS_PACKET_MSG;
  hdr->MessageLength = RNDIS_HEADER_SIZE + size;
  hdr->DataOffset = RNDIS_HEADER_SIZE - offsetof(rndis_data_packet_t, DataOffset);
  hdr->DataLength = size;

  sended = USBD_RNDIS_IN_BUFSIZE - RNDIS_HEADER_SIZE;
  if (sended > size)
    sended = size;
  memcpy(first + RNDIS_HEADER_SIZE, data, sended);
  rndis_tx_ptr += sended;
  rndis_tx_data_size -= sended;


  //http://habrahabr.ru/post/248729/
  if (hdr->MessageLength % USBD_RNDIS_IN_BUFSIZE == 0)
    rndis_tx_ZLP = 1;

  ASSERT(hold_pDev != NULL);
  //We should disable USB_OUT(EP3) IRQ, because if IRQ will happens with locked HAL (__HAL_LOCK()
  //in USBD_LL_Transmit()), the program will fail with big probability
  USBD_LL_Transmit (hold_pDev,
                    USBD_EP_RNDIS_IN,
                    (uint8_t *)first,
                    USBD_RNDIS_IN_BUFSIZE);

  //Increment error counter and then decrement in data_in if OK
  usb_eth_stat.txbad++;

  return 1;
}

int rndis_tx_started(void)
{
  return rndis_tx_transmitting;
}

/*__weak */void rndis_tx_ready_cb(void)
{
}
/*******************************************************************************
                            /API functions
*******************************************************************************/

static USBD_StatusTypeDef usbd_rndis_init(USBD_HandleTypeDef  *pdev, uint_fast8_t cfgidx)
{

	USBD_LL_OpenEP(pdev,
				 USBD_EP_RNDIS_OUT,
				 USBD_EP_TYPE_BULK,
				 USBD_RNDIS_OUT_BUFSIZE);

	USBD_LL_OpenEP(pdev,
				 USBD_EP_RNDIS_INT,
				 USBD_EP_TYPE_INTR,
				 USBD_RNDIS_INT_SIZE);

	USBD_LL_OpenEP(pdev,
				 USBD_EP_RNDIS_IN,
				 USBD_EP_TYPE_BULK,
				 USBD_RNDIS_IN_BUFSIZE);
  /*
  USBD_LL_PrepareReceive(pdev,
                         USBD_EP_RNDIS_OUT,
                         rndis_rx_buffer,
                         RNDIS_RX_BUFFER_SIZE);  */
  hold_pDev = pdev;
  ASSERT(hold_pDev != NULL);

  rndis_rx_start();
  return USBD_OK;
}

static USBD_StatusTypeDef  usbd_rndis_deinit(USBD_HandleTypeDef  *pdev, uint_fast8_t cfgidx)
{
	USBD_LL_CloseEP(pdev, USBD_EP_RNDIS_INT);
	USBD_LL_CloseEP(pdev, USBD_EP_RNDIS_IN);
	USBD_LL_CloseEP(pdev, USBD_EP_RNDIS_OUT);
	return USBD_OK;
}

static USBD_StatusTypeDef usbd_rndis_setup(USBD_HandleTypeDef  *pdev, const USBD_SetupReqTypedef *req)
{
	const uint_fast8_t interfacev = LO_BYTE(req->wIndex);
	if (interfacev != INTERFACE_RNDIS_CONTROL && interfacev != INTERFACE_RNDIS_DATA)
		   return USBD_OK;
 switch (req->bmRequest & USB_REQ_TYPE_MASK)
  {
  case USB_REQ_TYPE_CLASS :
    if (req->wLength != 0) // is data setup packet?
    {
      /* Check if the request is Device-to-Host */
      if (req->bmRequest & 0x80)
      {
        USBD_CtlSendData (pdev,
                          encapsulated_buffer,
                          ((rndis_generic_msg_t *)encapsulated_buffer)->MessageLength);
      }
      else /* Host-to-Device requeset */
      {
        USBD_CtlPrepareRx (pdev,
                           encapsulated_buffer,
                           req->wLength);
      }
    }
    return USBD_OK;

  default:
    return USBD_OK;
  }
}

#define INFBUF ((uint32_t *)(encapsulated_buffer + sizeof(rndis_query_cmplt_t)))

static void rndis_query_cmplt32(USBD_HandleTypeDef  *pdev, int status, uint32_t data)
{
  rndis_query_cmplt_t *c;
  c = (rndis_query_cmplt_t *)encapsulated_buffer;
  c->MessageType = REMOTE_NDIS_QUERY_CMPLT;
  c->MessageLength = sizeof(rndis_query_cmplt_t) + 4;
  c->InformationBufferLength = 4;
  c->InformationBufferOffset = 16;
  c->Status = status;
  *(uint32_t *)(c + 1) = data;
  response_available(pdev);
}

static void rndis_query_cmplt(USBD_HandleTypeDef  *pdev, int status, const void *data, int size)
{
  rndis_query_cmplt_t *c;
  c = (rndis_query_cmplt_t *)encapsulated_buffer;
  c->MessageType = REMOTE_NDIS_QUERY_CMPLT;
  c->MessageLength = sizeof(rndis_query_cmplt_t) + size;
  c->InformationBufferLength = size;
  c->InformationBufferOffset = 16;
  c->Status = status;
  memcpy(c + 1, data, size);
  response_available(pdev);
}

#define MAC_OPT NDIS_MAC_OPTION_COPY_LOOKAHEAD_DATA | \
NDIS_MAC_OPTION_RECEIVE_SERIALIZED  | \
  NDIS_MAC_OPTION_TRANSFERS_NOT_PEND  | \
    NDIS_MAC_OPTION_NO_LOOPBACK

static const char * const rndis_vendor = RNDIS_VENDOR;

static void rndis_query(USBD_HandleTypeDef  *pdev)
{
  switch (((rndis_query_msg_t *)encapsulated_buffer)->Oid)
  {
  case OID_GEN_SUPPORTED_LIST:         rndis_query_cmplt(pdev, RNDIS_STATUS_SUCCESS, OIDSupportedList, 4 * OID_LIST_LENGTH); return;
  case OID_GEN_VENDOR_DRIVER_VERSION:  rndis_query_cmplt32(pdev, RNDIS_STATUS_SUCCESS, 0x00001000);  return;
  case OID_802_3_CURRENT_ADDRESS:      rndis_query_cmplt(pdev, RNDIS_STATUS_SUCCESS, &station_hwaddr, 6); return;
  case OID_802_3_PERMANENT_ADDRESS:    rndis_query_cmplt(pdev, RNDIS_STATUS_SUCCESS, &permanent_hwaddr, 6); return;
  case OID_GEN_MEDIA_SUPPORTED:        rndis_query_cmplt32(pdev, RNDIS_STATUS_SUCCESS, NDIS_MEDIUM_802_3); return;
  case OID_GEN_MEDIA_IN_USE:           rndis_query_cmplt32(pdev, RNDIS_STATUS_SUCCESS, NDIS_MEDIUM_802_3); return;
  case OID_GEN_PHYSICAL_MEDIUM:        rndis_query_cmplt32(pdev, RNDIS_STATUS_SUCCESS, NDIS_MEDIUM_802_3); return;
  case OID_GEN_HARDWARE_STATUS:        rndis_query_cmplt32(pdev, RNDIS_STATUS_SUCCESS, 0); return;
  case OID_GEN_LINK_SPEED:             rndis_query_cmplt32(pdev, RNDIS_STATUS_SUCCESS, ETH_LINK_SPEED / 100); return;
  case OID_GEN_VENDOR_ID:              rndis_query_cmplt32(pdev, RNDIS_STATUS_SUCCESS, 0x00FFFFFF); return;
  case OID_GEN_VENDOR_DESCRIPTION:     rndis_query_cmplt(pdev, RNDIS_STATUS_SUCCESS, rndis_vendor, strlen(rndis_vendor) + 1); return;
  case OID_GEN_CURRENT_PACKET_FILTER:  rndis_query_cmplt32(pdev, RNDIS_STATUS_SUCCESS, oid_packet_filter); return;
  case OID_GEN_MAXIMUM_FRAME_SIZE:     rndis_query_cmplt32(pdev, RNDIS_STATUS_SUCCESS, ETH_MAX_PACKET_SIZE - ETH_HEADER_SIZE); return;
  case OID_GEN_MAXIMUM_TOTAL_SIZE:     rndis_query_cmplt32(pdev, RNDIS_STATUS_SUCCESS, ETH_MAX_PACKET_SIZE); return;
  case OID_GEN_TRANSMIT_BLOCK_SIZE:    rndis_query_cmplt32(pdev, RNDIS_STATUS_SUCCESS, ETH_MAX_PACKET_SIZE); return;
  case OID_GEN_RECEIVE_BLOCK_SIZE:     rndis_query_cmplt32(pdev, RNDIS_STATUS_SUCCESS, ETH_MAX_PACKET_SIZE); return;
  case OID_GEN_MEDIA_CONNECT_STATUS:   rndis_query_cmplt32(pdev, RNDIS_STATUS_SUCCESS, NDIS_MEDIA_STATE_CONNECTED); return;
  //	case OID_GEN_CURRENT_LOOKAHEAD:      rndis_query_cmplt32(pdev, RNDIS_STATUS_SUCCESS, RNDIS_RX_BUFFER_SIZE); return;
  case OID_GEN_RNDIS_CONFIG_PARAMETER: rndis_query_cmplt32(pdev, RNDIS_STATUS_SUCCESS, 0); return;
  case OID_802_3_MAXIMUM_LIST_SIZE:    rndis_query_cmplt32(pdev, RNDIS_STATUS_SUCCESS, 1); return;
  case OID_802_3_MULTICAST_LIST:       rndis_query_cmplt32(pdev, RNDIS_STATUS_NOT_SUPPORTED, 0); return;
  case OID_802_3_MAC_OPTIONS:          rndis_query_cmplt32(pdev, RNDIS_STATUS_NOT_SUPPORTED, 0); return;
  case OID_GEN_MAC_OPTIONS:            rndis_query_cmplt32(pdev, RNDIS_STATUS_SUCCESS, /*MAC_OPT*/ 0); return;
  case OID_802_3_RCV_ERROR_ALIGNMENT:  rndis_query_cmplt32(pdev, RNDIS_STATUS_SUCCESS, 0); return;
  case OID_802_3_XMIT_ONE_COLLISION:   rndis_query_cmplt32(pdev, RNDIS_STATUS_SUCCESS, 0); return;
  case OID_802_3_XMIT_MORE_COLLISIONS: rndis_query_cmplt32(pdev, RNDIS_STATUS_SUCCESS, 0); return;
  case OID_GEN_XMIT_OK:                rndis_query_cmplt32(pdev, RNDIS_STATUS_SUCCESS, usb_eth_stat.txok); return;
  case OID_GEN_RCV_OK:                 rndis_query_cmplt32(pdev, RNDIS_STATUS_SUCCESS, usb_eth_stat.rxok); return;
  case OID_GEN_RCV_ERROR:              rndis_query_cmplt32(pdev, RNDIS_STATUS_SUCCESS, usb_eth_stat.rxbad); return;
  case OID_GEN_XMIT_ERROR:             rndis_query_cmplt32(pdev, RNDIS_STATUS_SUCCESS, usb_eth_stat.txbad); return;
  case OID_GEN_RCV_NO_BUFFER:          rndis_query_cmplt32(pdev, RNDIS_STATUS_SUCCESS, 0); return;
  default:                             rndis_query_cmplt(pdev, RNDIS_STATUS_FAILURE, NULL, 0); return;
  }
}

#undef INFBUF
#define INFBUF ((uint32_t *)((uint8_t *)&(m->RequestId) + m->InformationBufferOffset))
#define CFGBUF ((rndis_config_parameter_t *) INFBUF)
#define PARMNAME  ((uint8_t *)CFGBUF + CFGBUF->ParameterNameOffset)
#define PARMVALUE ((uint8_t *)CFGBUF + CFGBUF->ParameterValueOffset)
#define PARMVALUELENGTH	CFGBUF->ParameterValueLength
#define PARM_NAME_LENGTH 25 /* Maximum parameter name length */

static void rndis_handle_config_parm(const char *data, int keyoffset, int valoffset, int keylen, int vallen)
{
  //	if (strncmp(parmname, "rawmode", 7) == 0)
  //	{
  //		if (parmvalue[0] == '0')
  //		{
  //			usbstick_mode.raw = 0;
  //		}
  //		else
  //		{
  //			usbstick_mode.raw = 1;
  //		}
  //	}
}

static void rndis_packetFilter(uint32_t newfilter)
{
  if (newfilter & NDIS_PACKET_TYPE_PROMISCUOUS)
  {
    //		USB_ETH_HOOK_SET_PROMISCIOUS_MODE(1);
  }
  else
  {
    //		USB_ETH_HOOK_SET_PROMISCIOUS_MODE(false);
  }
}

static void rndis_handle_set_msg(void  *pdev)
{
	rndis_set_cmplt_t *c;
	rndis_set_msg_t *m;
	rndis_Oid_t oid;

	c = (rndis_set_cmplt_t *)encapsulated_buffer;
	m = (rndis_set_msg_t *)encapsulated_buffer;

	/* Never have longer parameter names than PARM_NAME_LENGTH */
	/*
	char parmname[PARM_NAME_LENGTH+1];
	uint8_t i;
	int8_t parmlength;
	*/

	/* The parameter name seems to be transmitted in uint16_t, but */
	/* we want this in uint8_t. Hence have to throw out some info... */

	/*
	if (CFGBUF->ParameterNameLength > (PARM_NAME_LENGTH*2))
	{
		parmlength = PARM_NAME_LENGTH * 2;
	}
	else
	{
		parmlength = CFGBUF->ParameterNameLength;
	}
	i = 0;
	while (parmlength > 0)
	{
		// Convert from uint16_t to char array.
		parmname[i] = (char)*(PARMNAME + 2*i); // FSE! FIX IT!
		parmlength -= 2;
		i++;
	}
	*/

	oid = m->Oid;
	c->MessageType = REMOTE_NDIS_SET_CMPLT;
	c->MessageLength = sizeof(rndis_set_cmplt_t);
	c->Status = RNDIS_STATUS_SUCCESS;

	switch (oid)
	{
		/* Parameters set up in 'Advanced' tab */
		case OID_GEN_RNDIS_CONFIG_PARAMETER:
			{
                rndis_config_parameter_t *p;
				char *ptr = (char *)m;
				ptr += sizeof(rndis_generic_msg_t);
				ptr += m->InformationBufferOffset;
				p = (rndis_config_parameter_t *)ptr;
				rndis_handle_config_parm(ptr, p->ParameterNameOffset, p->ParameterValueOffset, p->ParameterNameLength, p->ParameterValueLength);
			}
			break;

		/* Mandatory general OIDs */
		case OID_GEN_CURRENT_PACKET_FILTER:
			oid_packet_filter = *INFBUF;
			if (oid_packet_filter)
			{
				rndis_packetFilter(oid_packet_filter);
				rndis_state = rndis_data_initialized;
			}
			else
			{
				rndis_state = rndis_initialized;
			}
			break;

		case OID_GEN_CURRENT_LOOKAHEAD:
			break;

		case OID_GEN_PROTOCOL_OPTIONS:
			break;

		/* Mandatory 802_3 OIDs */
		case OID_802_3_MULTICAST_LIST:
			break;

		/* Power Managment: fails for now */
		case OID_PNP_ADD_WAKE_UP_PATTERN:
		case OID_PNP_REMOVE_WAKE_UP_PATTERN:
		case OID_PNP_ENABLE_WAKE_UP:
		default:
			c->Status = RNDIS_STATUS_FAILURE;
			break;
	}

	response_available(pdev);

	return;
}

static int sended = 0;

static USBD_StatusTypeDef usbd_cdc_transfer(void *pdev)
{
	hold_pDev = pdev;
	  ASSERT(hold_pDev != NULL);
	if (sended != 0 || rndis_tx_ptr == NULL || rndis_tx_size <= 0)
		return USBD_OK;
	if (rndis_first_tx)
	{
		static uint8_t first [USBD_RNDIS_IN_BUFSIZE];
		rndis_data_packet_t *hdr;

		hdr = (rndis_data_packet_t *)first;
		memset(hdr, 0, sizeof(rndis_data_packet_t));
		hdr->MessageType = REMOTE_NDIS_PACKET_MSG;
		hdr->MessageLength = sizeof(rndis_data_packet_t) + rndis_tx_size;
		hdr->DataOffset = sizeof(rndis_data_packet_t) - offsetof(rndis_data_packet_t, DataOffset);
		hdr->DataLength = rndis_tx_size;

		sended = USBD_RNDIS_IN_BUFSIZE - sizeof(rndis_data_packet_t);
		if (sended > rndis_tx_size) sended = rndis_tx_size;
		memcpy(first + sizeof(rndis_data_packet_t), rndis_tx_ptr, sended);

		  ASSERT(hold_pDev != NULL);
		USBD_LL_Transmit(hold_pDev,
						USBD_EP_RNDIS_IN,
						(uint8_t *)&first,
						sizeof(rndis_data_packet_t) + sended);
	}
	else
	{
		int n = rndis_tx_size;
		if (n > USBD_RNDIS_IN_BUFSIZE)
			n = USBD_RNDIS_IN_BUFSIZE;

		USBD_LL_Transmit(hold_pDev,
						USBD_EP_RNDIS_IN,
						rndis_tx_ptr,
						n);
		sended = n;
	}
	return USBD_OK;
}

// Control Channel      https://msdn.microsoft.com/en-us/library/windows/hardware/ff546124(v=vs.85).aspx
static USBD_StatusTypeDef usbd_rndis_ep0_recv(USBD_HandleTypeDef  *pdev)
{
	const USBD_SetupReqTypedef * const req = & pdev->request;
	const uint_fast8_t interfacev = LO_BYTE(req->wIndex);
	if (interfacev != INTERFACE_RNDIS_CONTROL && interfacev != INTERFACE_RNDIS_DATA)
		   return USBD_OK;

  switch (((rndis_generic_msg_t *)encapsulated_buffer)->MessageType)
  {
  case REMOTE_NDIS_INITIALIZE_MSG:
    {
      rndis_initialize_cmplt_t *m;
      m = ((rndis_initialize_cmplt_t *)encapsulated_buffer);
      //m->MessageID is same as before
      m->MessageType = REMOTE_NDIS_INITIALIZE_CMPLT;
      m->MessageLength = sizeof(rndis_initialize_cmplt_t);
      m->MajorVersion = RNDIS_MAJOR_VERSION;
      m->MinorVersion = RNDIS_MINOR_VERSION;
      m->Status = RNDIS_STATUS_SUCCESS;
      m->DeviceFlags = RNDIS_DF_CONNECTIONLESS;
      m->Medium = RNDIS_MEDIUM_802_3;
      m->MaxPacketsPerTransfer = 1;
      m->MaxTransferSize = RNDIS_RX_BUFFER_SIZE;
      m->PacketAlignmentFactor = 0;
      m->AfListOffset = 0;
      m->AfListSize = 0;
      rndis_state = rndis_initialized;
      response_available(pdev);
    }
    break;

  case REMOTE_NDIS_QUERY_MSG:
    rndis_query(pdev);
    break;

  case REMOTE_NDIS_SET_MSG:
    rndis_handle_set_msg(pdev);
    break;

  case REMOTE_NDIS_RESET_MSG:
    {
      rndis_reset_cmplt_t * m;
      m = ((rndis_reset_cmplt_t *)encapsulated_buffer);
      rndis_state = rndis_uninitialized;
      m->MessageType = REMOTE_NDIS_RESET_CMPLT;
      m->MessageLength = sizeof(rndis_reset_cmplt_t);
      m->Status = RNDIS_STATUS_SUCCESS;
      m->AddressingReset = 1; /* Make it look like we did something */
      //	m->AddressingReset = 0; //Windows halts if set to 1 for some reason
      response_available(pdev);
    }
    break;

  case REMOTE_NDIS_KEEPALIVE_MSG:
    {
      rndis_keepalive_cmplt_t * m;
      m = (rndis_keepalive_cmplt_t *)encapsulated_buffer;
      m->MessageType = REMOTE_NDIS_KEEPALIVE_CMPLT;
      m->MessageLength = sizeof(rndis_keepalive_cmplt_t);
      m->Status = RNDIS_STATUS_SUCCESS;
    }
    // We have data to send back
    response_available(pdev);
    break;

  default:
    break;
  }
  return USBD_OK;
}

// Data Channel         https://msdn.microsoft.com/en-us/library/windows/hardware/ff546305(v=vs.85).aspx
//                      https://msdn.microsoft.com/en-us/library/windows/hardware/ff570635(v=vs.85).aspx
static USBD_StatusTypeDef usbd_rndis_data_in(USBD_HandleTypeDef*pdev, uint_fast8_t epnum)
{
	epnum &= 0x0F;
	if (epnum == (USBD_EP_RNDIS_IN & 0x0F))
	{
		rndis_first_tx = false;
		rndis_sended += sended;
		rndis_tx_size -= sended;
		rndis_tx_ptr += sended;
		sended = 0;
		usbd_cdc_transfer(pdev);

	}
	return USBD_OK;
}

static void handle_packet(const uint8_t *data, int size)
{
	rndis_data_packet_t *p;
	p = (rndis_data_packet_t *)data;
	if (size < sizeof(rndis_data_packet_t)) return;
	if (p->MessageType != REMOTE_NDIS_PACKET_MSG || p->MessageLength != size) return;
	if (p->DataOffset + offsetof(rndis_data_packet_t, DataOffset) + p->DataLength != size)
	{
		usb_eth_stat.rxbad++;
		return;
	}
	usb_eth_stat.rxok++;
	if (rndis_rxproc != NULL)
		rndis_rxproc(&rndis_rx_buffer[p->DataOffset + offsetof(rndis_data_packet_t, DataOffset)], p->DataLength);
	/*
  if (size < RNDIS_HEADER_SIZE)
  {
    usb_eth_stat.rxbad++;
    return;
  }
  //To exclude Rx ZLP bug
  if ((pheader->MessageType != REMOTE_NDIS_PACKET_MSG) ||
      ((pheader->MessageLength != size) && (pheader->MessageLength != size - 1)))
  {
    usb_eth_stat.rxbad++;
    return;
  }
  size = pheader->MessageLength;
  if (pheader->DataOffset + offsetof(rndis_data_packet_t, DataOffset) + pheader->DataLength != size)
  {
    usb_eth_stat.rxbad++;
    return;
  }
  if (!rndis_rx_started)
  {
    usb_eth_stat.rxbad++;
    return;
  }
  rndis_rx_data_size = pheader->DataLength;
  rndis_rx_started = false;

  usb_eth_stat.rxok++;
  rndis_rx_ready_cb();
  */
}

// Data Channel         https://msdn.microsoft.com/en-us/library/windows/hardware/ff546305(v=vs.85).aspx
static USBD_StatusTypeDef usbd_rndis_data_out(USBD_HandleTypeDef *pdev, uint_fast8_t epnum)
{
	static int rndis_received = 0;
	if (epnum == USBD_EP_RNDIS_OUT)
	{
		PCD_EPTypeDef *ep = &(((PCD_HandleTypeDef*)(pdev->pData))->OUT_ep[epnum]);
		if (rndis_received + ep->xfer_count > RNDIS_RX_BUFFER_SIZE)
		{
			usb_eth_stat.rxbad++;
			rndis_received = 0;
		}
		else
		{
			if (rndis_received + ep->xfer_count <= RNDIS_RX_BUFFER_SIZE)
			{
				memcpy(&rndis_rx_buffer[rndis_received], usb_rx_buffer, ep->xfer_count);
				rndis_received += ep->xfer_count;
				if (ep->xfer_count != USBD_RNDIS_OUT_BUFSIZE)
				{
					handle_packet(rndis_rx_buffer, rndis_received);
					rndis_received = 0;
				}
			}
			else
			{
					rndis_received = 0;
					usb_eth_stat.rxbad++;
			}
		}
		USBD_LL_PrepareReceive(hold_pDev,
							   USBD_EP_RNDIS_OUT,
							   usb_rx_buffer,
							   USBD_RNDIS_OUT_BUFSIZE);
		  //	DCD_EP_PrepareRx(pdev, USBD_EP_RNDIS_OUT, (uint8_t*)usb_rx_buffer, USBD_RNDIS_OUT_BUFSIZE);
	}
  //  PCD_EPTypeDef *ep = &((PCD_HandleTypeDef*)pdev->pData)->OUT_ep[epnum];
   // handle_packet((rndis_data_packet_t*)rndis_rx_buffer, RNDIS_RX_BUFFER_SIZE - ep->xfer_len - USBD_RNDIS_OUT_BUFSIZE + ep->xfer_count);
  return USBD_OK;
}

// Start Of Frame event management
static USBD_StatusTypeDef usbd_rndis_sof(USBD_HandleTypeDef *pdev)
{
	return usbd_cdc_transfer(pdev);
}

static USBD_StatusTypeDef rndis_iso_in_incomplete(USBD_HandleTypeDef *pdev, uint_fast8_t epnum)
{
	return usbd_cdc_transfer(pdev);
}

static USBD_StatusTypeDef rndis_iso_out_incomplete(USBD_HandleTypeDef *pdev, uint_fast8_t epnum)
{
	USBD_LL_PrepareReceive(pdev,
							USBD_EP_RNDIS_OUT,
							usb_rx_buffer,
							USBD_RNDIS_OUT_BUFSIZE);
	return USBD_OK;
}

static void response_available(USBD_HandleTypeDef *pdev)
{
	static USBALIGN_BEGIN uint8_t sendState [8] USBALIGN_END;
	uint_fast32_t code = 0x01;
	uint_fast32_t reserved0 = 0x09;

	ASSERT(USBD_RNDIS_INT_SIZE == sizeof sendState);
	sendState [0] = LO_BYTE(code);
	sendState [1] = HI_BYTE(code);
	sendState [2] = HI_24BY(code);
	sendState [3] = HI_32BY(code);
	sendState [4] = LO_BYTE(reserved0);
	sendState [5] = HI_BYTE(reserved0);
	sendState [6] = HI_24BY(reserved0);
	sendState [7] = HI_32BY(reserved0);

	system_disableIRQ();
	USBD_LL_Transmit (pdev, USBD_EP_RNDIS_INT, sendState, USBD_RNDIS_INT_SIZE);
	system_enableIRQ();
}


int rndis_can_send(void)
{
	system_disableIRQ();
	int f = rndis_tx_size <= 0 && hold_pDev != NULL;
	system_enableIRQ();
	return f;
}

int rndis_send(const void *data, int size)
{
	ASSERT(data != NULL);
	ASSERT(hold_pDev != NULL);
	//rndis_tx_start(data, size);
/*
	while (transmit_ok == 1)
	transmit_ok = 1;
	USBD_LL_Transmit (pDev,
				      USBD_EP_RNDIS_IN,
	                  (uint8_t *)data,
					  size);
*/

	system_disableIRQ();

	if (size <= 0 ||
		size > ETH_MAX_PACKET_SIZE ||
		rndis_tx_size > 0 || hold_pDev == NULL)

		{
			system_enableIRQ();
			return false;
		}


	rndis_first_tx = 1;
	rndis_tx_ptr = (uint8_t *)data;
	rndis_tx_size = size;
	rndis_sended = 0;


	ASSERT(hold_pDev != NULL);
	usbd_cdc_transfer(hold_pDev);
	system_enableIRQ();

	return 1;
}

const USBD_ClassTypeDef USBD_CLASS_RNDIS =
{
	USBD_RNDIS_ColdInit,
	usbd_rndis_init,
	usbd_rndis_deinit,
	usbd_rndis_setup,
	NULL,
	usbd_rndis_ep0_recv,
	usbd_rndis_data_in,
	usbd_rndis_data_out,
	usbd_rndis_sof,
	rndis_iso_in_incomplete,
	rndis_iso_out_incomplete,
};


#endif /* WITHUSBHW && WITHUSBRNDIS */


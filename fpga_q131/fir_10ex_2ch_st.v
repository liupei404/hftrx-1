// Generated by FIR Compiler
// ************************************************************
// THIS IS A WIZARD-GENERATED FILE. DO NOT EDIT THIS FILE!
// ************************************************************
// Copyright (C) 1991-2005 Altera Corporation
// Any megafunction design, and related net list (encrypted or decrypted),
// support information, device programming or simulation file, and any other
// associated documentation or information provided by Altera or a partner
// under Altera's Megafunction Partnership Program may be used only to
// program PLD devices (but not masked PLD devices) from Altera.  Any other
// use of such megafunction design, net list, support information, device
// programming or simulation file, or any other related documentation or
// information is prohibited for any other purpose, including, but not
// limited to modification, reverse engineering, de-compiling, or use with
// any other silicon devices, unless such use is explicitly licensed under
// a separate agreement with Altera or a megafunction partner.  Title to
// the intellectual property, including patents, copyrights, trademarks,
// trade secrets, or maskworks, embodied in any such megafunction design,
// net list, support information, device programming or simulation file, or
// any other related documentation or information provided by Altera or a
// megafunction partner, remains with Altera, the megafunction partner, or
// their respective licensors.  No other licenses, including any licenses
// needed under any third party's intellectual property, are provided herein.
// 00
// altera message_off 10036
(* altera_attribute = "-name MESSAGE_DISABLE 15400; -name MESSAGE_DISABLE 14130; -name MESSAGE_DISABLE 10036; -name MESSAGE_DISABLE 12020; -name MESSAGE_DISABLE 12030; -name MESSAGE_DISABLE 12010; -name MESSAGE_DISABLE 12110; -name MESSAGE_DISABLE 14320; -name MESSAGE_DISABLE 13410" *)
module fir_10ex_2ch_st (clk, 
              rst, 
              data_in, 
              clk_en, 
              coef_set, 
              rdy_to_ld, 
              done, 
              input_ch_id, 
              output_ch_id, 
              fir_result); 
parameter DATA_WIDTH  = 32;
parameter COEF_WIDTH  = 20;
parameter COEF_SET_WIDTH = 4;
parameter ACCUM_WIDTH = 56;

parameter CH_WIDTH = 5;
input clk, rst;
input [DATA_WIDTH-1:0] data_in;
input clk_en;
input [COEF_SET_WIDTH-1:0] coef_set; 
output [CH_WIDTH -1:0] input_ch_id; 
output [CH_WIDTH -1:0] output_ch_id; 
output rdy_to_ld;
wire rdy_to_ld;
wire rdy_int;
wire data_ld;
output done;
wire done;
wire done_int;
output [ACCUM_WIDTH-1:0] fir_result;
wire tdl_ld;
wire sa_rst;
wire sa_inv;
wire pre_rdy;
wire sym_rst;
wire addr_low;
assign addr_low = 1'b0;
wire [COEF_SET_WIDTH-1 :0]coef_set_dly;
delay_trig_cen coef_set_reg(.clk(clk),.gclk_en(clk_en),.enable(pre_rdy), .data_in(coef_set),.data_out(coef_set_dly));
defparam coef_set_reg.IN_WIDTH = COEF_SET_WIDTH;
defparam coef_set_reg.WHOLE_DELAY = 1;
defparam coef_set_reg.FINE_DELAY = 1;
wire ser_eab_0_n;
wire ser_eab_1_n;
wire ser_dat_0_n;
par_ld_ser_tdl_nc Utdl_0_a(.clk(clk), .clk_en(clk_en), .rst(rst), .data_in(data_in), .tdl_ld(pre_rdy),.data_out(ser_eab_0_n) );
defparam Utdl_0_a.WIDTH = 32;
assign ser_dat_0_n = ser_eab_0_n; 
wire ser_dat_1_n;
wire ser_dat_2_n;
wire ser_dat_3_n;
wire ser_dat_4_n;
wire ser_dat_5_n;
wire ser_dat_6_n;
wire ser_dat_7_n;
wire ser_dat_8_n;
wire ser_dat_9_n;
wire ser_dat_10_n;
wire ser_dat_11_n;
wire ser_dat_12_n;
wire ser_dat_13_n;
wire ser_dat_14_n;
wire ser_dat_15_n;
wire ser_dat_16_n;
wire ser_dat_17_n;
wire ser_dat_18_n;
wire ser_dat_19_n;
wire ser_dat_20_n;
wire ser_dat_21_n;
wire ser_dat_22_n;
wire ser_dat_23_n;
wire ser_dat_24_n;
wire ser_dat_25_n;
wire ser_dat_26_n;
wire ser_dat_27_n;
wire ser_dat_28_n;
wire ser_dat_29_n;
wire ser_dat_30_n;
wire ser_dat_31_n;
wire ser_dat_32_n;
wire ser_dat_33_n;
wire ser_dat_34_n;
wire ser_dat_35_n;
wire ser_dat_36_n;
wire ser_dat_37_n;
wire ser_dat_38_n;
wire ser_dat_39_n;
wire ser_dat_40_n;
wire ser_dat_41_n;
wire ser_dat_42_n;
wire ser_dat_43_n;
wire ser_dat_44_n;
wire ser_dat_45_n;
wire ser_dat_46_n;
wire ser_dat_47_n;
wire ser_dat_48_n;
wire ser_dat_49_n;
wire ser_dat_50_n;
wire ser_dat_51_n;
wire ser_dat_52_n;
wire ser_dat_53_n;
wire ser_dat_54_n;
wire ser_dat_55_n;
wire ser_dat_56_n;
wire ser_dat_57_n;
wire ser_dat_58_n;
wire ser_dat_59_n;
wire ser_dat_60_n;
wire ser_dat_61_n;
wire ser_dat_62_n;
wire ser_dat_63_n;
wire ser_dat_64_n;
wire ser_dat_65_n;
wire ser_dat_66_n;
wire ser_dat_67_n;
wire ser_dat_68_n;
wire ser_dat_69_n;
wire ser_dat_70_n;
wire ser_dat_71_n;
wire ser_dat_72_n;
wire [72:0]tdl_data_0_n;
eab_tdl_strat Utdl_0_n (
  .clk(clk),
  .clk_en(clk_en),
  .data_ld(data_ld),
  .rst(tdl_ld),
  .grst(rst), 
  .data_in(ser_eab_0_n),
  .data_out(tdl_data_0_n),
  .ntdl(ser_eab_1_n) 
);
defparam Utdl_0_n.CORE_WIDTH = 73;
defparam Utdl_0_n.MEM_CORE = "AUTO";
defparam Utdl_0_n.DEPTH = 640;
defparam Utdl_0_n.DEPTH_ADDR = 10;
defparam Utdl_0_n.WIDTH = 32;
defparam Utdl_0_n.INIT_FILE = "fir_10ex_2ch_zero.hex";
assign ser_dat_1_n = tdl_data_0_n[0];
assign ser_dat_2_n = tdl_data_0_n[1];
assign ser_dat_3_n = tdl_data_0_n[2];
assign ser_dat_4_n = tdl_data_0_n[3];
assign ser_dat_5_n = tdl_data_0_n[4];
assign ser_dat_6_n = tdl_data_0_n[5];
assign ser_dat_7_n = tdl_data_0_n[6];
assign ser_dat_8_n = tdl_data_0_n[7];
assign ser_dat_9_n = tdl_data_0_n[8];
assign ser_dat_10_n = tdl_data_0_n[9];
assign ser_dat_11_n = tdl_data_0_n[10];
assign ser_dat_12_n = tdl_data_0_n[11];
assign ser_dat_13_n = tdl_data_0_n[12];
assign ser_dat_14_n = tdl_data_0_n[13];
assign ser_dat_15_n = tdl_data_0_n[14];
assign ser_dat_16_n = tdl_data_0_n[15];
assign ser_dat_17_n = tdl_data_0_n[16];
assign ser_dat_18_n = tdl_data_0_n[17];
assign ser_dat_19_n = tdl_data_0_n[18];
assign ser_dat_20_n = tdl_data_0_n[19];
assign ser_dat_21_n = tdl_data_0_n[20];
assign ser_dat_22_n = tdl_data_0_n[21];
assign ser_dat_23_n = tdl_data_0_n[22];
assign ser_dat_24_n = tdl_data_0_n[23];
assign ser_dat_25_n = tdl_data_0_n[24];
assign ser_dat_26_n = tdl_data_0_n[25];
assign ser_dat_27_n = tdl_data_0_n[26];
assign ser_dat_28_n = tdl_data_0_n[27];
assign ser_dat_29_n = tdl_data_0_n[28];
assign ser_dat_30_n = tdl_data_0_n[29];
assign ser_dat_31_n = tdl_data_0_n[30];
assign ser_dat_32_n = tdl_data_0_n[31];
assign ser_dat_33_n = tdl_data_0_n[32];
assign ser_dat_34_n = tdl_data_0_n[33];
assign ser_dat_35_n = tdl_data_0_n[34];
assign ser_dat_36_n = tdl_data_0_n[35];
assign ser_dat_37_n = tdl_data_0_n[36];
assign ser_dat_38_n = tdl_data_0_n[37];
assign ser_dat_39_n = tdl_data_0_n[38];
assign ser_dat_40_n = tdl_data_0_n[39];
assign ser_dat_41_n = tdl_data_0_n[40];
assign ser_dat_42_n = tdl_data_0_n[41];
assign ser_dat_43_n = tdl_data_0_n[42];
assign ser_dat_44_n = tdl_data_0_n[43];
assign ser_dat_45_n = tdl_data_0_n[44];
assign ser_dat_46_n = tdl_data_0_n[45];
assign ser_dat_47_n = tdl_data_0_n[46];
assign ser_dat_48_n = tdl_data_0_n[47];
assign ser_dat_49_n = tdl_data_0_n[48];
assign ser_dat_50_n = tdl_data_0_n[49];
assign ser_dat_51_n = tdl_data_0_n[50];
assign ser_dat_52_n = tdl_data_0_n[51];
assign ser_dat_53_n = tdl_data_0_n[52];
assign ser_dat_54_n = tdl_data_0_n[53];
assign ser_dat_55_n = tdl_data_0_n[54];
assign ser_dat_56_n = tdl_data_0_n[55];
assign ser_dat_57_n = tdl_data_0_n[56];
assign ser_dat_58_n = tdl_data_0_n[57];
assign ser_dat_59_n = tdl_data_0_n[58];
assign ser_dat_60_n = tdl_data_0_n[59];
assign ser_dat_61_n = tdl_data_0_n[60];
assign ser_dat_62_n = tdl_data_0_n[61];
assign ser_dat_63_n = tdl_data_0_n[62];
assign ser_dat_64_n = tdl_data_0_n[63];
assign ser_dat_65_n = tdl_data_0_n[64];
assign ser_dat_66_n = tdl_data_0_n[65];
assign ser_dat_67_n = tdl_data_0_n[66];
assign ser_dat_68_n = tdl_data_0_n[67];
assign ser_dat_69_n = tdl_data_0_n[68];
assign ser_dat_70_n = tdl_data_0_n[69];
assign ser_dat_71_n = tdl_data_0_n[70];
assign ser_dat_72_n = tdl_data_0_n[71];
// --- ROM LUTs ---- 
wire [19:0] lut_val_0_n;
ram_lut_cen Ur0_n(.gclk_en(clk_en), .clk_in(clk), .clk_out(clk), .addr_in( {coef_set_dly[3],coef_set_dly[2],coef_set_dly[1],coef_set_dly[0],ser_dat_4_n,ser_dat_3_n,ser_dat_2_n,ser_dat_1_n,ser_dat_0_n } ), .wr_en(1'b0),.data_out( lut_val_0_n[7:0]) ) ;
defparam Ur0_n.device_family = "CYCLONEIII";
defparam Ur0_n.init_file = "fir_10ex_2ch_coef_0.hex";
defparam Ur0_n.data_width = 8;
defparam Ur0_n.addr_width = 9;
defparam Ur0_n.depth = 320;
defparam Ur0_n.mem_core = "M4K";
assign lut_val_0_n[19] = lut_val_0_n[7];
assign lut_val_0_n[18] = lut_val_0_n[7];
assign lut_val_0_n[17] = lut_val_0_n[7];
assign lut_val_0_n[16] = lut_val_0_n[7];
assign lut_val_0_n[15] = lut_val_0_n[7];
assign lut_val_0_n[14] = lut_val_0_n[7];
assign lut_val_0_n[13] = lut_val_0_n[7];
assign lut_val_0_n[12] = lut_val_0_n[7];
assign lut_val_0_n[11] = lut_val_0_n[7];
assign lut_val_0_n[10] = lut_val_0_n[7];
assign lut_val_0_n[9] = lut_val_0_n[7];
assign lut_val_0_n[8] = lut_val_0_n[7];
wire [19:0] lut_val_1_n;
ram_lut_cen Ur1_n(.gclk_en(clk_en), .clk_in(clk), .clk_out(clk), .addr_in( {coef_set_dly[3],coef_set_dly[2],coef_set_dly[1],coef_set_dly[0],ser_dat_8_n,ser_dat_7_n,ser_dat_6_n,ser_dat_5_n } ), .wr_en(1'b0),.data_out( lut_val_1_n[9:0]) ) ;
defparam Ur1_n.device_family = "CYCLONEIII";
defparam Ur1_n.init_file = "fir_10ex_2ch_coef_1.hex";
defparam Ur1_n.data_width = 10;
defparam Ur1_n.addr_width = 8;
defparam Ur1_n.depth = 160;
defparam Ur1_n.mem_core = "M4K";
assign lut_val_1_n[19] = lut_val_1_n[9];
assign lut_val_1_n[18] = lut_val_1_n[9];
assign lut_val_1_n[17] = lut_val_1_n[9];
assign lut_val_1_n[16] = lut_val_1_n[9];
assign lut_val_1_n[15] = lut_val_1_n[9];
assign lut_val_1_n[14] = lut_val_1_n[9];
assign lut_val_1_n[13] = lut_val_1_n[9];
assign lut_val_1_n[12] = lut_val_1_n[9];
assign lut_val_1_n[11] = lut_val_1_n[9];
assign lut_val_1_n[10] = lut_val_1_n[9];
wire [19:0] lut_val_2_n;
ram_lut_cen Ur2_n(.gclk_en(clk_en), .clk_in(clk), .clk_out(clk), .addr_in( {coef_set_dly[3],coef_set_dly[2],coef_set_dly[1],coef_set_dly[0],ser_dat_12_n,ser_dat_11_n,ser_dat_10_n,ser_dat_9_n } ), .wr_en(1'b0),.data_out( lut_val_2_n[11:0]) ) ;
defparam Ur2_n.device_family = "CYCLONEIII";
defparam Ur2_n.init_file = "fir_10ex_2ch_coef_2.hex";
defparam Ur2_n.data_width = 12;
defparam Ur2_n.addr_width = 8;
defparam Ur2_n.depth = 160;
defparam Ur2_n.mem_core = "M4K";
assign lut_val_2_n[19] = lut_val_2_n[11];
assign lut_val_2_n[18] = lut_val_2_n[11];
assign lut_val_2_n[17] = lut_val_2_n[11];
assign lut_val_2_n[16] = lut_val_2_n[11];
assign lut_val_2_n[15] = lut_val_2_n[11];
assign lut_val_2_n[14] = lut_val_2_n[11];
assign lut_val_2_n[13] = lut_val_2_n[11];
assign lut_val_2_n[12] = lut_val_2_n[11];
wire [19:0] lut_val_3_n;
ram_lut_cen Ur3_n(.gclk_en(clk_en), .clk_in(clk), .clk_out(clk), .addr_in( {coef_set_dly[3],coef_set_dly[2],coef_set_dly[1],coef_set_dly[0],ser_dat_16_n,ser_dat_15_n,ser_dat_14_n,ser_dat_13_n } ), .wr_en(1'b0),.data_out( lut_val_3_n[12:0]) ) ;
defparam Ur3_n.device_family = "CYCLONEIII";
defparam Ur3_n.init_file = "fir_10ex_2ch_coef_3.hex";
defparam Ur3_n.data_width = 13;
defparam Ur3_n.addr_width = 8;
defparam Ur3_n.depth = 160;
defparam Ur3_n.mem_core = "M4K";
assign lut_val_3_n[19] = lut_val_3_n[12];
assign lut_val_3_n[18] = lut_val_3_n[12];
assign lut_val_3_n[17] = lut_val_3_n[12];
assign lut_val_3_n[16] = lut_val_3_n[12];
assign lut_val_3_n[15] = lut_val_3_n[12];
assign lut_val_3_n[14] = lut_val_3_n[12];
assign lut_val_3_n[13] = lut_val_3_n[12];
wire [19:0] lut_val_4_n;
ram_lut_cen Ur4_n(.gclk_en(clk_en), .clk_in(clk), .clk_out(clk), .addr_in( {coef_set_dly[3],coef_set_dly[2],coef_set_dly[1],coef_set_dly[0],ser_dat_20_n,ser_dat_19_n,ser_dat_18_n,ser_dat_17_n } ), .wr_en(1'b0),.data_out( lut_val_4_n[13:0]) ) ;
defparam Ur4_n.device_family = "CYCLONEIII";
defparam Ur4_n.init_file = "fir_10ex_2ch_coef_4.hex";
defparam Ur4_n.data_width = 14;
defparam Ur4_n.addr_width = 8;
defparam Ur4_n.depth = 160;
defparam Ur4_n.mem_core = "M4K";
assign lut_val_4_n[19] = lut_val_4_n[13];
assign lut_val_4_n[18] = lut_val_4_n[13];
assign lut_val_4_n[17] = lut_val_4_n[13];
assign lut_val_4_n[16] = lut_val_4_n[13];
assign lut_val_4_n[15] = lut_val_4_n[13];
assign lut_val_4_n[14] = lut_val_4_n[13];
wire [19:0] lut_val_5_n;
ram_lut_cen Ur5_n(.gclk_en(clk_en), .clk_in(clk), .clk_out(clk), .addr_in( {coef_set_dly[3],coef_set_dly[2],coef_set_dly[1],coef_set_dly[0],ser_dat_24_n,ser_dat_23_n,ser_dat_22_n,ser_dat_21_n } ), .wr_en(1'b0),.data_out( lut_val_5_n[14:0]) ) ;
defparam Ur5_n.device_family = "CYCLONEIII";
defparam Ur5_n.init_file = "fir_10ex_2ch_coef_5.hex";
defparam Ur5_n.data_width = 15;
defparam Ur5_n.addr_width = 8;
defparam Ur5_n.depth = 160;
defparam Ur5_n.mem_core = "M4K";
assign lut_val_5_n[19] = lut_val_5_n[14];
assign lut_val_5_n[18] = lut_val_5_n[14];
assign lut_val_5_n[17] = lut_val_5_n[14];
assign lut_val_5_n[16] = lut_val_5_n[14];
assign lut_val_5_n[15] = lut_val_5_n[14];
wire [19:0] lut_val_6_n;
ram_lut_cen Ur6_n(.gclk_en(clk_en), .clk_in(clk), .clk_out(clk), .addr_in( {coef_set_dly[3],coef_set_dly[2],coef_set_dly[1],coef_set_dly[0],ser_dat_28_n,ser_dat_27_n,ser_dat_26_n,ser_dat_25_n } ), .wr_en(1'b0),.data_out( lut_val_6_n[15:0]) ) ;
defparam Ur6_n.device_family = "CYCLONEIII";
defparam Ur6_n.init_file = "fir_10ex_2ch_coef_6.hex";
defparam Ur6_n.data_width = 16;
defparam Ur6_n.addr_width = 8;
defparam Ur6_n.depth = 160;
defparam Ur6_n.mem_core = "M4K";
assign lut_val_6_n[19] = lut_val_6_n[15];
assign lut_val_6_n[18] = lut_val_6_n[15];
assign lut_val_6_n[17] = lut_val_6_n[15];
assign lut_val_6_n[16] = lut_val_6_n[15];
wire [19:0] lut_val_7_n;
ram_lut_cen Ur7_n(.gclk_en(clk_en), .clk_in(clk), .clk_out(clk), .addr_in( {coef_set_dly[3],coef_set_dly[2],coef_set_dly[1],coef_set_dly[0],ser_dat_32_n,ser_dat_31_n,ser_dat_30_n,ser_dat_29_n } ), .wr_en(1'b0),.data_out( lut_val_7_n[16:0]) ) ;
defparam Ur7_n.device_family = "CYCLONEIII";
defparam Ur7_n.init_file = "fir_10ex_2ch_coef_7.hex";
defparam Ur7_n.data_width = 17;
defparam Ur7_n.addr_width = 8;
defparam Ur7_n.depth = 160;
defparam Ur7_n.mem_core = "M4K";
assign lut_val_7_n[19] = lut_val_7_n[16];
assign lut_val_7_n[18] = lut_val_7_n[16];
assign lut_val_7_n[17] = lut_val_7_n[16];
wire [19:0] lut_val_8_n;
ram_lut_cen Ur8_n(.gclk_en(clk_en), .clk_in(clk), .clk_out(clk), .addr_in( {coef_set_dly[3],coef_set_dly[2],coef_set_dly[1],coef_set_dly[0],ser_dat_35_n,ser_dat_34_n,ser_dat_33_n } ), .wr_en(1'b0),.data_out( lut_val_8_n[19:0]) ) ;
defparam Ur8_n.device_family = "CYCLONEIII";
defparam Ur8_n.init_file = "fir_10ex_2ch_coef_8.hex";
defparam Ur8_n.data_width = 20;
defparam Ur8_n.addr_width = 7;
defparam Ur8_n.depth = 80;
defparam Ur8_n.mem_core = "M4K";
wire [19:0] lut_val_9_n;
ram_lut_cen Ur9_n(.gclk_en(clk_en), .clk_in(clk), .clk_out(clk), .addr_in( {coef_set_dly[3],coef_set_dly[2],coef_set_dly[1],coef_set_dly[0],ser_dat_38_n,ser_dat_37_n,ser_dat_36_n } ), .wr_en(1'b0),.data_out( lut_val_9_n[19:0]) ) ;
defparam Ur9_n.device_family = "CYCLONEIII";
defparam Ur9_n.init_file = "fir_10ex_2ch_coef_9.hex";
defparam Ur9_n.data_width = 20;
defparam Ur9_n.addr_width = 7;
defparam Ur9_n.depth = 80;
defparam Ur9_n.mem_core = "M4K";
wire [19:0] lut_val_10_n;
ram_lut_cen Ur10_n(.gclk_en(clk_en), .clk_in(clk), .clk_out(clk), .addr_in( {coef_set_dly[3],coef_set_dly[2],coef_set_dly[1],coef_set_dly[0],ser_dat_42_n,ser_dat_41_n,ser_dat_40_n,ser_dat_39_n } ), .wr_en(1'b0),.data_out( lut_val_10_n[16:0]) ) ;
defparam Ur10_n.device_family = "CYCLONEIII";
defparam Ur10_n.init_file = "fir_10ex_2ch_coef_10.hex";
defparam Ur10_n.data_width = 17;
defparam Ur10_n.addr_width = 8;
defparam Ur10_n.depth = 160;
defparam Ur10_n.mem_core = "M4K";
assign lut_val_10_n[19] = lut_val_10_n[16];
assign lut_val_10_n[18] = lut_val_10_n[16];
assign lut_val_10_n[17] = lut_val_10_n[16];
wire [19:0] lut_val_11_n;
ram_lut_cen Ur11_n(.gclk_en(clk_en), .clk_in(clk), .clk_out(clk), .addr_in( {coef_set_dly[3],coef_set_dly[2],coef_set_dly[1],coef_set_dly[0],ser_dat_46_n,ser_dat_45_n,ser_dat_44_n,ser_dat_43_n } ), .wr_en(1'b0),.data_out( lut_val_11_n[15:0]) ) ;
defparam Ur11_n.device_family = "CYCLONEIII";
defparam Ur11_n.init_file = "fir_10ex_2ch_coef_11.hex";
defparam Ur11_n.data_width = 16;
defparam Ur11_n.addr_width = 8;
defparam Ur11_n.depth = 160;
defparam Ur11_n.mem_core = "M4K";
assign lut_val_11_n[19] = lut_val_11_n[15];
assign lut_val_11_n[18] = lut_val_11_n[15];
assign lut_val_11_n[17] = lut_val_11_n[15];
assign lut_val_11_n[16] = lut_val_11_n[15];
wire [19:0] lut_val_12_n;
ram_lut_cen Ur12_n(.gclk_en(clk_en), .clk_in(clk), .clk_out(clk), .addr_in( {coef_set_dly[3],coef_set_dly[2],coef_set_dly[1],coef_set_dly[0],ser_dat_50_n,ser_dat_49_n,ser_dat_48_n,ser_dat_47_n } ), .wr_en(1'b0),.data_out( lut_val_12_n[14:0]) ) ;
defparam Ur12_n.device_family = "CYCLONEIII";
defparam Ur12_n.init_file = "fir_10ex_2ch_coef_12.hex";
defparam Ur12_n.data_width = 15;
defparam Ur12_n.addr_width = 8;
defparam Ur12_n.depth = 160;
defparam Ur12_n.mem_core = "M4K";
assign lut_val_12_n[19] = lut_val_12_n[14];
assign lut_val_12_n[18] = lut_val_12_n[14];
assign lut_val_12_n[17] = lut_val_12_n[14];
assign lut_val_12_n[16] = lut_val_12_n[14];
assign lut_val_12_n[15] = lut_val_12_n[14];
wire [19:0] lut_val_13_n;
ram_lut_cen Ur13_n(.gclk_en(clk_en), .clk_in(clk), .clk_out(clk), .addr_in( {coef_set_dly[3],coef_set_dly[2],coef_set_dly[1],coef_set_dly[0],ser_dat_54_n,ser_dat_53_n,ser_dat_52_n,ser_dat_51_n } ), .wr_en(1'b0),.data_out( lut_val_13_n[13:0]) ) ;
defparam Ur13_n.device_family = "CYCLONEIII";
defparam Ur13_n.init_file = "fir_10ex_2ch_coef_13.hex";
defparam Ur13_n.data_width = 14;
defparam Ur13_n.addr_width = 8;
defparam Ur13_n.depth = 160;
defparam Ur13_n.mem_core = "M4K";
assign lut_val_13_n[19] = lut_val_13_n[13];
assign lut_val_13_n[18] = lut_val_13_n[13];
assign lut_val_13_n[17] = lut_val_13_n[13];
assign lut_val_13_n[16] = lut_val_13_n[13];
assign lut_val_13_n[15] = lut_val_13_n[13];
assign lut_val_13_n[14] = lut_val_13_n[13];
wire [19:0] lut_val_14_n;
ram_lut_cen Ur14_n(.gclk_en(clk_en), .clk_in(clk), .clk_out(clk), .addr_in( {coef_set_dly[3],coef_set_dly[2],coef_set_dly[1],coef_set_dly[0],ser_dat_58_n,ser_dat_57_n,ser_dat_56_n,ser_dat_55_n } ), .wr_en(1'b0),.data_out( lut_val_14_n[12:0]) ) ;
defparam Ur14_n.device_family = "CYCLONEIII";
defparam Ur14_n.init_file = "fir_10ex_2ch_coef_14.hex";
defparam Ur14_n.data_width = 13;
defparam Ur14_n.addr_width = 8;
defparam Ur14_n.depth = 160;
defparam Ur14_n.mem_core = "M4K";
assign lut_val_14_n[19] = lut_val_14_n[12];
assign lut_val_14_n[18] = lut_val_14_n[12];
assign lut_val_14_n[17] = lut_val_14_n[12];
assign lut_val_14_n[16] = lut_val_14_n[12];
assign lut_val_14_n[15] = lut_val_14_n[12];
assign lut_val_14_n[14] = lut_val_14_n[12];
assign lut_val_14_n[13] = lut_val_14_n[12];
wire [19:0] lut_val_15_n;
ram_lut_cen Ur15_n(.gclk_en(clk_en), .clk_in(clk), .clk_out(clk), .addr_in( {coef_set_dly[3],coef_set_dly[2],coef_set_dly[1],coef_set_dly[0],ser_dat_62_n,ser_dat_61_n,ser_dat_60_n,ser_dat_59_n } ), .wr_en(1'b0),.data_out( lut_val_15_n[11:0]) ) ;
defparam Ur15_n.device_family = "CYCLONEIII";
defparam Ur15_n.init_file = "fir_10ex_2ch_coef_15.hex";
defparam Ur15_n.data_width = 12;
defparam Ur15_n.addr_width = 8;
defparam Ur15_n.depth = 160;
defparam Ur15_n.mem_core = "M4K";
assign lut_val_15_n[19] = lut_val_15_n[11];
assign lut_val_15_n[18] = lut_val_15_n[11];
assign lut_val_15_n[17] = lut_val_15_n[11];
assign lut_val_15_n[16] = lut_val_15_n[11];
assign lut_val_15_n[15] = lut_val_15_n[11];
assign lut_val_15_n[14] = lut_val_15_n[11];
assign lut_val_15_n[13] = lut_val_15_n[11];
assign lut_val_15_n[12] = lut_val_15_n[11];
wire [19:0] lut_val_16_n;
ram_lut_cen Ur16_n(.gclk_en(clk_en), .clk_in(clk), .clk_out(clk), .addr_in( {coef_set_dly[3],coef_set_dly[2],coef_set_dly[1],coef_set_dly[0],ser_dat_66_n,ser_dat_65_n,ser_dat_64_n,ser_dat_63_n } ), .wr_en(1'b0),.data_out( lut_val_16_n[10:0]) ) ;
defparam Ur16_n.device_family = "CYCLONEIII";
defparam Ur16_n.init_file = "fir_10ex_2ch_coef_16.hex";
defparam Ur16_n.data_width = 11;
defparam Ur16_n.addr_width = 8;
defparam Ur16_n.depth = 160;
defparam Ur16_n.mem_core = "M4K";
assign lut_val_16_n[19] = lut_val_16_n[10];
assign lut_val_16_n[18] = lut_val_16_n[10];
assign lut_val_16_n[17] = lut_val_16_n[10];
assign lut_val_16_n[16] = lut_val_16_n[10];
assign lut_val_16_n[15] = lut_val_16_n[10];
assign lut_val_16_n[14] = lut_val_16_n[10];
assign lut_val_16_n[13] = lut_val_16_n[10];
assign lut_val_16_n[12] = lut_val_16_n[10];
assign lut_val_16_n[11] = lut_val_16_n[10];
wire [19:0] lut_val_17_n;
ram_lut_cen Ur17_n(.gclk_en(clk_en), .clk_in(clk), .clk_out(clk), .addr_in( {coef_set_dly[3],coef_set_dly[2],coef_set_dly[1],coef_set_dly[0],ser_dat_71_n,ser_dat_70_n,ser_dat_69_n,ser_dat_68_n,ser_dat_67_n } ), .wr_en(1'b0),.data_out( lut_val_17_n[7:0]) ) ;
defparam Ur17_n.device_family = "CYCLONEIII";
defparam Ur17_n.init_file = "fir_10ex_2ch_coef_17.hex";
defparam Ur17_n.data_width = 8;
defparam Ur17_n.addr_width = 9;
defparam Ur17_n.depth = 320;
defparam Ur17_n.mem_core = "M4K";
assign lut_val_17_n[19] = lut_val_17_n[7];
assign lut_val_17_n[18] = lut_val_17_n[7];
assign lut_val_17_n[17] = lut_val_17_n[7];
assign lut_val_17_n[16] = lut_val_17_n[7];
assign lut_val_17_n[15] = lut_val_17_n[7];
assign lut_val_17_n[14] = lut_val_17_n[7];
assign lut_val_17_n[13] = lut_val_17_n[7];
assign lut_val_17_n[12] = lut_val_17_n[7];
assign lut_val_17_n[11] = lut_val_17_n[7];
assign lut_val_17_n[10] = lut_val_17_n[7];
assign lut_val_17_n[9] = lut_val_17_n[7];
assign lut_val_17_n[8] = lut_val_17_n[7];
wire [19:0] lut_val_18_n;
ram_lut_cen Ur18_n(.gclk_en(clk_en), .clk_in(clk), .clk_out(clk), .addr_in( {coef_set_dly[3],coef_set_dly[2],coef_set_dly[1],coef_set_dly[0],ser_dat_72_n } ), .wr_en(1'b0),.data_out( lut_val_18_n[0:0]) ) ;
defparam Ur18_n.device_family = "CYCLONEIII";
defparam Ur18_n.init_file = "fir_10ex_2ch_coef_18.hex";
defparam Ur18_n.data_width = 1;
defparam Ur18_n.addr_width = 5;
defparam Ur18_n.depth = 20;
defparam Ur18_n.mem_core = "M4K";
assign lut_val_18_n[19] = lut_val_18_n[0];
assign lut_val_18_n[18] = lut_val_18_n[0];
assign lut_val_18_n[17] = lut_val_18_n[0];
assign lut_val_18_n[16] = lut_val_18_n[0];
assign lut_val_18_n[15] = lut_val_18_n[0];
assign lut_val_18_n[14] = lut_val_18_n[0];
assign lut_val_18_n[13] = lut_val_18_n[0];
assign lut_val_18_n[12] = lut_val_18_n[0];
assign lut_val_18_n[11] = lut_val_18_n[0];
assign lut_val_18_n[10] = lut_val_18_n[0];
assign lut_val_18_n[9] = lut_val_18_n[0];
assign lut_val_18_n[8] = lut_val_18_n[0];
assign lut_val_18_n[7] = lut_val_18_n[0];
assign lut_val_18_n[6] = lut_val_18_n[0];
assign lut_val_18_n[5] = lut_val_18_n[0];
assign lut_val_18_n[4] = lut_val_18_n[0];
assign lut_val_18_n[3] = lut_val_18_n[0];
assign lut_val_18_n[2] = lut_val_18_n[0];
assign lut_val_18_n[1] = lut_val_18_n[0];
wire [20:0] tree_l_0_n_0_n;
sadd_lpm_cen Uaddl_0_n_0_n (.clk(clk),  .gclk_en(clk_en), .ain(lut_val_0_n), .bin(lut_val_1_n), .res(tree_l_0_n_0_n) );
defparam Uaddl_0_n_0_n.IN_WIDTH = 20;
defparam Uaddl_0_n_0_n.PIPE_DEPTH = 1;
wire [20:0] tree_l_0_n_1_n;
sadd_lpm_cen Uaddl_0_n_1_n (.clk(clk),  .gclk_en(clk_en), .ain(lut_val_2_n), .bin(lut_val_3_n), .res(tree_l_0_n_1_n) );
defparam Uaddl_0_n_1_n.IN_WIDTH = 20;
defparam Uaddl_0_n_1_n.PIPE_DEPTH = 1;
wire [20:0] tree_l_0_n_2_n;
sadd_lpm_cen Uaddl_0_n_2_n (.clk(clk),  .gclk_en(clk_en), .ain(lut_val_4_n), .bin(lut_val_5_n), .res(tree_l_0_n_2_n) );
defparam Uaddl_0_n_2_n.IN_WIDTH = 20;
defparam Uaddl_0_n_2_n.PIPE_DEPTH = 1;
wire [20:0] tree_l_0_n_3_n;
sadd_lpm_cen Uaddl_0_n_3_n (.clk(clk),  .gclk_en(clk_en), .ain(lut_val_6_n), .bin(lut_val_7_n), .res(tree_l_0_n_3_n) );
defparam Uaddl_0_n_3_n.IN_WIDTH = 20;
defparam Uaddl_0_n_3_n.PIPE_DEPTH = 1;
wire [20:0] tree_l_0_n_4_n;
sadd_lpm_cen Uaddl_0_n_4_n (.clk(clk),  .gclk_en(clk_en), .ain(lut_val_8_n), .bin(lut_val_9_n), .res(tree_l_0_n_4_n) );
defparam Uaddl_0_n_4_n.IN_WIDTH = 20;
defparam Uaddl_0_n_4_n.PIPE_DEPTH = 1;
wire [20:0] tree_l_0_n_5_n;
sadd_lpm_cen Uaddl_0_n_5_n (.clk(clk),  .gclk_en(clk_en), .ain(lut_val_10_n), .bin(lut_val_11_n), .res(tree_l_0_n_5_n) );
defparam Uaddl_0_n_5_n.IN_WIDTH = 20;
defparam Uaddl_0_n_5_n.PIPE_DEPTH = 1;
wire [20:0] tree_l_0_n_6_n;
sadd_lpm_cen Uaddl_0_n_6_n (.clk(clk),  .gclk_en(clk_en), .ain(lut_val_12_n), .bin(lut_val_13_n), .res(tree_l_0_n_6_n) );
defparam Uaddl_0_n_6_n.IN_WIDTH = 20;
defparam Uaddl_0_n_6_n.PIPE_DEPTH = 1;
wire [20:0] tree_l_0_n_7_n;
sadd_lpm_cen Uaddl_0_n_7_n (.clk(clk),  .gclk_en(clk_en), .ain(lut_val_14_n), .bin(lut_val_15_n), .res(tree_l_0_n_7_n) );
defparam Uaddl_0_n_7_n.IN_WIDTH = 20;
defparam Uaddl_0_n_7_n.PIPE_DEPTH = 1;
wire [20:0] tree_l_0_n_8_n;
sadd_lpm_cen Uaddl_0_n_8_n (.clk(clk),  .gclk_en(clk_en), .ain(lut_val_16_n), .bin(lut_val_17_n), .res(tree_l_0_n_8_n) );
defparam Uaddl_0_n_8_n.IN_WIDTH = 20;
defparam Uaddl_0_n_8_n.PIPE_DEPTH = 1;
wire [20:0] tree_l_0_n_9_n;
sadd_lpm_cen Uaddl_0_n_9_n (.clk(clk),  .gclk_en(clk_en), .ain(lut_val_18_n), .bin(20'd0), .res(tree_l_0_n_9_n) );
defparam Uaddl_0_n_9_n.IN_WIDTH = 20;
defparam Uaddl_0_n_9_n.PIPE_DEPTH = 1;

wire [21:0] tree_l_1_n_0_n;
sadd_lpm_cen Uaddl_1_n_0_n (.clk(clk),  .gclk_en(clk_en), .ain(tree_l_0_n_0_n), .bin(tree_l_0_n_1_n), .res(tree_l_1_n_0_n) );
defparam Uaddl_1_n_0_n.IN_WIDTH = 21;
defparam Uaddl_1_n_0_n.PIPE_DEPTH = 1;
wire [21:0] tree_l_1_n_1_n;
sadd_lpm_cen Uaddl_1_n_1_n (.clk(clk),  .gclk_en(clk_en), .ain(tree_l_0_n_2_n), .bin(tree_l_0_n_3_n), .res(tree_l_1_n_1_n) );
defparam Uaddl_1_n_1_n.IN_WIDTH = 21;
defparam Uaddl_1_n_1_n.PIPE_DEPTH = 1;
wire [21:0] tree_l_1_n_2_n;
sadd_lpm_cen Uaddl_1_n_2_n (.clk(clk),  .gclk_en(clk_en), .ain(tree_l_0_n_4_n), .bin(tree_l_0_n_5_n), .res(tree_l_1_n_2_n) );
defparam Uaddl_1_n_2_n.IN_WIDTH = 21;
defparam Uaddl_1_n_2_n.PIPE_DEPTH = 1;
wire [21:0] tree_l_1_n_3_n;
sadd_lpm_cen Uaddl_1_n_3_n (.clk(clk),  .gclk_en(clk_en), .ain(tree_l_0_n_6_n), .bin(tree_l_0_n_7_n), .res(tree_l_1_n_3_n) );
defparam Uaddl_1_n_3_n.IN_WIDTH = 21;
defparam Uaddl_1_n_3_n.PIPE_DEPTH = 1;
wire [21:0] tree_l_1_n_4_n;
sadd_lpm_cen Uaddl_1_n_4_n (.clk(clk),  .gclk_en(clk_en), .ain(tree_l_0_n_8_n), .bin(tree_l_0_n_9_n), .res(tree_l_1_n_4_n) );
defparam Uaddl_1_n_4_n.IN_WIDTH = 21;
defparam Uaddl_1_n_4_n.PIPE_DEPTH = 1;

wire [22:0] tree_l_2_n_0_n;
sadd_lpm_cen Uaddl_2_n_0_n (.clk(clk),  .gclk_en(clk_en), .ain(tree_l_1_n_0_n), .bin(tree_l_1_n_1_n), .res(tree_l_2_n_0_n) );
defparam Uaddl_2_n_0_n.IN_WIDTH = 22;
defparam Uaddl_2_n_0_n.PIPE_DEPTH = 1;
wire [22:0] tree_l_2_n_1_n;
sadd_lpm_cen Uaddl_2_n_1_n (.clk(clk),  .gclk_en(clk_en), .ain(tree_l_1_n_2_n), .bin(tree_l_1_n_3_n), .res(tree_l_2_n_1_n) );
defparam Uaddl_2_n_1_n.IN_WIDTH = 22;
defparam Uaddl_2_n_1_n.PIPE_DEPTH = 1;
wire [22:0] tree_l_2_n_2_n;
sadd_lpm_cen Uaddl_2_n_2_n (.clk(clk),  .gclk_en(clk_en), .ain(tree_l_1_n_4_n), .bin(22'd0), .res(tree_l_2_n_2_n) );
defparam Uaddl_2_n_2_n.IN_WIDTH = 22;
defparam Uaddl_2_n_2_n.PIPE_DEPTH = 1;

wire [23:0] tree_l_3_n_0_n;
sadd_lpm_cen Uaddl_3_n_0_n (.clk(clk),  .gclk_en(clk_en), .ain(tree_l_2_n_0_n), .bin(tree_l_2_n_1_n), .res(tree_l_3_n_0_n) );
defparam Uaddl_3_n_0_n.IN_WIDTH = 23;
defparam Uaddl_3_n_0_n.PIPE_DEPTH = 1;
wire [23:0] tree_l_3_n_1_n;
sadd_lpm_cen Uaddl_3_n_1_n (.clk(clk),  .gclk_en(clk_en), .ain(tree_l_2_n_2_n), .bin(23'd0), .res(tree_l_3_n_1_n) );
defparam Uaddl_3_n_1_n.IN_WIDTH = 23;
defparam Uaddl_3_n_1_n.PIPE_DEPTH = 1;

wire [24:0] tree_l_4_n_0_n;
sadd_lpm_cen Uaddl_4_n_0_n (.clk(clk),  .gclk_en(clk_en), .ain(tree_l_3_n_0_n), .bin(tree_l_3_n_1_n), .res(tree_l_4_n_0_n) );
defparam Uaddl_4_n_0_n.IN_WIDTH = 24;
defparam Uaddl_4_n_0_n.PIPE_DEPTH = 1;

wire [24:0] mac_res;
assign mac_res=tree_l_4_n_0_n;
wire [24:0] atree_res;
mac_tl Umtl (.clk(clk), 
             .data_in(mac_res),
             .data_out(atree_res));
defparam Umtl.DATA_WIDTH = 25;

// ---- Adder Tree Complete ---- 


wire [30:0] shft;
wire [25:0] accum;
scale_accum_cen Usa (.gclk_en(clk_en),  .clk(clk), .rst(sa_rst), .inv(sa_inv), .ain(atree_res), .accum_out(accum) );
defparam Usa.WIDTH_A = 25;


ser_shft_cen Usershft(.gclk_en(clk_en),  .clk(clk), .rst(1'b0), .ain(accum[0]), .shft_out(shft) );
defparam Usershft.SHIFT_WIDTH = 31;


wire    [56:0] fir_int_res;
scale_shft_comb_cen Usscx (.gclk_en(clk_en), .clk(clk), .ce(done_int), .accum(accum), .shft(shft), .res(fir_int_res) );
defparam Usscx.WIDTH_ACCM = 26;
defparam Usscx.WIDTH_SHFT = 31;
defparam Usscx.WIDTH_RES = 57;

assign fir_result = fir_int_res[ACCUM_WIDTH-1:0];
assign rdy_to_ld = rdy_int;
ser_ctrl_cen Usc (.rst(rst), .clk(clk), .clk_en(clk_en), 
              .rdy_to_ld(rdy_int), .sym_rst(sym_rst), 
              .pre_rdy(pre_rdy), .data_ld(data_ld),
              .sa_rst_out(sa_rst), .ser_inv_out(sa_inv), 
		.input_ch_id(input_ch_id),
		.output_ch_id(output_ch_id),
              .tdl_ld(tdl_ld), .done_int(done_int), .done(done) ); 

defparam Usc.REG_LEN =32; 
defparam Usc.PIPE_DLY =9; 
defparam Usc.RST_DLY =23; 
defparam Usc.INV_DLY =24; 
defparam Usc.DONE_DLY =22; 
defparam Usc.DONE_HLD =3; 
defparam Usc.DONE_CNT_BIT =2; 
defparam Usc.CH_WIDTH =5; 
defparam Usc.NUM_CH =20; 

endmodule

-- ================================================================================
-- Legal Notice: Copyright (C) 1991-2006 Altera Corporation
-- Any megafunction design, and related net list (encrypted or decrypted),
-- support information, device programming or simulation file, and any other
-- associated documentation or information provided by Altera or a partner
-- under Altera's Megafunction Partnership Program may be used only to
-- program PLD devices (but not masked PLD devices) from Altera.  Any other
-- use of such megafunction design, net list, support information, device
-- programming or simulation file, or any other related documentation or
-- information is prohibited for any other purpose, including, but not
-- limited to modification, reverse engineering, de-compiling, or use with
-- any other silicon devices, unless such use is explicitly licensed under
-- a separate agreement with Altera or a megafunction partner.  Title to
-- the intellectual property, including patents, copyrights, trademarks,
-- trade secrets, or maskworks, embodied in any such megafunction design,
-- net list, support information, device programming or simulation file, or
-- any other related documentation or information provided by Altera or a
-- megafunction partner, remains with Altera, the megafunction partner, or
-- their respective licensors.  No other licenses, including any licenses
-- needed under any third party's intellectual property, are provided herein.
-- ================================================================================
--

-- Generated by: FIR Compiler 13.1
-- Generated on: Sep 3, 2018 3:35:36 PM

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;


library auk_dspip_lib;
use auk_dspip_lib.auk_dspip_lib_pkg_fir_131.all;


entity fir_20ex_2ch_ast is

  port(
    clk                : in  std_logic;
    reset_n            : in  std_logic;
    ast_sink_ready     : out std_logic;
    ast_source_data    : out std_logic_vector (32 -1 downto 0);
    ast_sink_data      : in  std_logic_vector (32 -1 downto 0);
    ast_sink_valid     : in  std_logic;
    ast_source_valid    : out std_logic;    
    ast_source_ready   : in  std_logic;
    ast_source_eop     : out std_logic;
    ast_source_sop     : out std_logic;
      ast_source_channel : out std_logic;
      ast_sink_eop       : in  std_logic;
    ast_sink_sop       : in  std_logic;
    ast_sink_error     : in  std_logic_vector (1 downto 0);
    ast_source_error    : out std_logic_vector (1 downto 0)
    );
attribute altera_attribute : string;
attribute altera_attribute of fir_20ex_2ch_ast:entity is "-name MESSAGE_DISABLE 15400; -name MESSAGE_DISABLE 14130; -name MESSAGE_DISABLE 12020; -name MESSAGE_DISABLE 12030; -name MESSAGE_DISABLE 12010; -name MESSAGE_DISABLE 12110; -name MESSAGE_DISABLE 14320; -name MESSAGE_DISABLE 13410; -name MESSAGE_DISABLE 10036";
end fir_20ex_2ch_ast;


-- Warnings Suppression On
-- altera message_off 10036


architecture struct of fir_20ex_2ch_ast is

  signal channel_out         : std_logic_vector(1 -1 downto 0);
  signal core_channel_out    : std_logic_vector(1 -1 downto 0);
  signal at_source_channel   : std_logic_vector(1 -1 downto 0);
  signal sink_packet_error   : std_logic_vector(1 downto 0);
  signal data_in             : std_logic_vector(32 -1 downto 0);
  signal data_out            : std_logic_vector(32 -1 downto 0);
  signal core_out            : std_logic_vector(32 -1 downto 0);
  signal ready               : std_logic;
  signal reset_fir           : std_logic;
  signal sink_ready_ctrl     : std_logic;
  signal sink_stall          : std_logic;
  signal source_packet_error : std_logic_vector(1 downto 0);
  signal source_stall        : std_logic;
  signal source_valid_ctrl   : std_logic;
  signal stall               : std_logic;
  signal valid               : std_logic;
  signal core_valid          : std_logic;
  signal enable_in           : std_logic;
  signal stall_delayed       : std_logic;
  constant ENABLE_PIPELINE_DEPTH_c : natural := 0;
  
  component fir_20ex_2ch_st_wr is
    port (
      rst         : in std_logic;
      clk         : in std_logic;
      clk_en      : in std_logic;
      rdy_to_ld   : out std_logic;
      done        : out std_logic;
       output_ch_id : out std_logic_vector(1 - 1 downto 0);
      input_ch_id : out std_logic_vector(1 - 1 downto 0);
          data_in      : in  std_logic_vector(32 - 1 downto 0);
      fir_result   : out std_logic_vector(32 - 1 downto 0));
  end component fir_20ex_2ch_st_wr;
  
begin
  sink : auk_dspip_avalon_streaming_sink_fir_131
    generic map (
      WIDTH_g          => 32,
      PACKET_SIZE_g    => 2,
      PFC_MODE_g       => true,
      FIFO_DEPTH_g     => 20,
      FAMILY_g         => "Cyclone IV E",
      MEM_TYPE_g       => "Auto")
    port map (
      clk             => clk,
      reset_n         => reset_n,
      data            => data_in,
      sink_ready_ctrl => sink_ready_ctrl,
      sink_stall      => sink_stall,
      packet_error    => sink_packet_error,
      at_sink_ready   => ast_sink_ready,
      at_sink_valid   => ast_sink_valid,
      at_sink_data    => ast_sink_data,
      at_sink_sop     => ast_sink_sop,
      at_sink_eop     => ast_sink_eop,
      at_sink_error   => ast_sink_error);

  source : auk_dspip_avalon_streaming_source_fir_131
    generic map (
      WIDTH_g         => 32,
      multi_channel_g => true,
      packet_size_g   => 2)
    port map (
      clk               => clk,
      reset_n           => reset_n,
      data              => data_out,
      data_count        => channel_out,
      source_valid_ctrl => source_valid_ctrl,
      design_stall      => stall_delayed,
      source_stall      => source_stall,
      packet_error      => source_packet_error,
      at_source_ready   => ast_source_ready,
      at_source_valid   => ast_source_valid,
      at_source_data    => ast_source_data,
      at_source_channel => at_source_channel,
      at_source_sop     => ast_source_sop,
      at_source_eop     => ast_source_eop,
      at_source_error   => ast_source_error);
         ast_source_channel <= at_source_channel(0);
   
  intf_ctrl : auk_dspip_avalon_streaming_controller_fir_131
    port map (
      clk                 => clk,
      ready               => ready,
      reset_n             => reset_n,
      sink_packet_error   => sink_packet_error,
      sink_stall          => sink_stall,
      source_stall        => source_stall,
      valid               => valid,
      reset_design        => reset_fir,
      sink_ready_ctrl     => sink_ready_ctrl,
      source_packet_error => source_packet_error,
      source_valid_ctrl   => source_valid_ctrl,
      stall               => stall);

  fircore: fir_20ex_2ch_st_wr
    port map (
      rst          => reset_fir,
      clk          => clk,
      clk_en       => enable_in,
      rdy_to_ld    => ready,
      done         => core_valid,
       output_ch_id => core_channel_out,
      input_ch_id => open,
          data_in      => data_in,
      fir_result   => core_out);


  data_out <= core_out;
   channel_out <= core_channel_out;
   valid <= core_valid;
  
enable_in <= not stall;

no_enable_pipeline: if ENABLE_PIPELINE_DEPTH_c = 0 generate
    stall_delayed <= stall;
end generate no_enable_pipeline;  

enable_pipeline: if ENABLE_PIPELINE_DEPTH_c > 0 generate
  delay_core_enable : process (clk, reset_n)
    variable stall_delay : std_logic_vector(ENABLE_PIPELINE_DEPTH_c downto 0);
  begin  -- process delay_core_enable
    if reset_n = '0' then  
      stall_delay := (others => '0');
    elsif rising_edge(clk) then
      stall_delay := stall_delay(stall_delay'high-1 downto 0) & stall;
    end if;
    stall_delayed <= stall_delay(stall_delay'high);
  end process delay_core_enable;      
end generate enable_pipeline;    
end struct;




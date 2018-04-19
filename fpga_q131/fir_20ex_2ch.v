// megafunction wizard: %FIR Compiler v13.1%
// GENERATION: XML

// ============================================================
// Megafunction Name(s):
// 			fir_20ex_2ch_ast
// ============================================================
// Generated by FIR Compiler 13.1 [Altera, IP Toolbench 1.3.0 Build 182]
// ************************************************************
// THIS IS A WIZARD-GENERATED FILE. DO NOT EDIT THIS FILE!
// ************************************************************
// Copyright (C) 1991-2018 Altera Corporation
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


module fir_20ex_2ch (
	clk,
	reset_n,
	ast_sink_data,
	ast_sink_valid,
	ast_source_ready,
	ast_sink_sop,
	ast_sink_eop,
	ast_sink_error,
	ast_source_data,
	ast_sink_ready,
	ast_source_valid,
	ast_source_sop,
	ast_source_eop,
	ast_source_channel,
	ast_source_error);


	input		clk;
	input		reset_n;
	input	[31:0]	ast_sink_data;
	input		ast_sink_valid;
	input		ast_source_ready;
	input		ast_sink_sop;
	input		ast_sink_eop;
	input	[1:0]	ast_sink_error;
	output	[31:0]	ast_source_data;
	output		ast_sink_ready;
	output		ast_source_valid;
	output		ast_source_sop;
	output		ast_source_eop;
	output		ast_source_channel;
	output	[1:0]	ast_source_error;


	fir_20ex_2ch_ast	fir_20ex_2ch_ast_inst(
		.clk(clk),
		.reset_n(reset_n),
		.ast_sink_data(ast_sink_data),
		.ast_sink_valid(ast_sink_valid),
		.ast_source_ready(ast_source_ready),
		.ast_sink_sop(ast_sink_sop),
		.ast_sink_eop(ast_sink_eop),
		.ast_sink_error(ast_sink_error),
		.ast_source_data(ast_source_data),
		.ast_sink_ready(ast_sink_ready),
		.ast_source_valid(ast_source_valid),
		.ast_source_sop(ast_source_sop),
		.ast_source_eop(ast_source_eop),
		.ast_source_channel(ast_source_channel),
		.ast_source_error(ast_source_error));
endmodule

// =========================================================
// FIR Compiler Wizard Data
// ===============================
// DO NOT EDIT FOLLOWING DATA
// @Altera, IP Toolbench@
// Warning: If you modify this section, FIR Compiler Wizard may not be able to reproduce your chosen configuration.
// 
// Retrieval info: <?xml version="1.0"?>
// Retrieval info: <MEGACORE title="FIR Compiler"  version="13.1"  build="182"  iptb_version="1.3.0 Build 182"  format_version="120" >
// Retrieval info:  <NETLIST_SECTION class="altera.ipbu.flowbase.netlist.model.FIRModelClass"  active_core="fir_20ex_2ch_ast" >
// Retrieval info:   <STATIC_SECTION>
// Retrieval info:    <PRIVATES>
// Retrieval info:     <NAMESPACE name = "parameterization">
// Retrieval info:      <PRIVATE name = "use_mem" value="1"  type="BOOLEAN"  enable="1" />
// Retrieval info:      <PRIVATE name = "mem_type" value="M512"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "filter_rate" value="Decimation"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "filter_factor" value="20"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "coefficient_scaling_type" value="Signed Binary Fractional"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "coefficient_scaling_factor" value="1.6777216E7"  type="STRING"  enable="0" />
// Retrieval info:      <PRIVATE name = "coefficient_bit_width" value="25"  type="INTEGER"  enable="0" />
// Retrieval info:      <PRIVATE name = "coefficient_binary_point_position" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "number_of_input_channels" value="2"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "input_number_system" value="Signed Binary"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "input_bit_width" value="32"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "input_binary_point_position" value="0"  type="INTEGER"  enable="0" />
// Retrieval info:      <PRIVATE name = "output_bit_width_method" value="Actual Coefficients"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_number_system" value="Custom Resolution"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_bit_width" value="32"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_bits_right_of_binary_point" value="32"  type="INTEGER"  enable="0" />
// Retrieval info:      <PRIVATE name = "output_bits_removed_from_lsb" value="24"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_lsb_remove_type" value="Truncate"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_msb_remove_type" value="Truncate"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "flow_control" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "flow_control_input" value="Slave Sink"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "flow_control_output" value="Master Source"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "device_family" value="Cyclone IV E"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "structure" value="Distributed Arithmetic : Fully Serial Filter"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "pipeline_level" value="1"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "clocks_to_compute" value="3"  type="INTEGER"  enable="0" />
// Retrieval info:      <PRIVATE name = "number_of_serial_units" value="2"  type="INTEGER"  enable="0" />
// Retrieval info:      <PRIVATE name = "data_storage" value="M9K"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "coefficient_storage" value="Logic Cells"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "multiplier_storage" value="Logic Cells"  type="STRING"  enable="0" />
// Retrieval info:      <PRIVATE name = "force_non_symmetric_structure" value="1"  type="BOOLEAN"  enable="0" />
// Retrieval info:      <PRIVATE name = "coefficients_reload" value="0"  type="BOOLEAN"  enable="0" />
// Retrieval info:      <PRIVATE name = "coefficients_reload_sgl_clock" value="0"  type="BOOLEAN"  enable="1" />
// Retrieval info:      <PRIVATE name = "max_clocks_to_compute" value="4"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "set_1" value="Low Pass Set, Floating, Low Pass, Blackman, 729, 1920000.0, 42000.0, 3750000.0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.03001E-6, -1.02188E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.40024E-6, 2.01565E-6, 2.68031E-6, 3.37989E-6, 4.09716E-6, 4.81223E-6, 5.50295E-6, 6.1453E-6, 6.714E-6, 7.18315E-6, 7.52689E-6, 7.72022E-6, 7.73976E-6, 7.56459E-6, 7.17706E-6, 6.56356E-6, 5.71529E-6, 4.62889E-6, 3.30701E-6, 1.75876E-6, 0.0, -1.94649E-6, -4.05104E-6, -6.27731E-6, -8.58267E-6, -1.09188E-5, -1.32324E-5, -1.54663E-5, -1.75604E-5, -1.9453E-5, -2.10822E-5, -2.23875E-5, -2.33112E-5, -2.38003E-5, -2.38078E-5, -2.32942E-5, -2.22296E-5, -2.05942E-5, -1.83803E-5, -1.55928E-5, -1.22502E-5, -8.38492E-6, -4.04381E-6, 0.0, 5.80895E-6, 1.11587E-5, 1.66626E-5, 2.22113E-5, 2.76871E-5, 3.29662E-5, 3.79207E-5, 4.24216E-5, 4.63415E-5, 4.95575E-5, 5.19541E-5, 5.34267E-5, 5.38838E-5, 5.32507E-5, 5.14714E-5, 4.85116E-5, 4.436E-5, 3.90306E-5, 3.25635E-5, 2.50256E-5, 1.65107E-5, 7.13901E-6, -2.94401E-6, -1.35693E-5, -2.45464E-5, -3.56668E-5, -4.67069E-5, -5.74324E-5, -6.76023E-5, -7.69741E-5, -8.53089E-5, -9.23761E-5, -9.79596E-5, -1.01863E-4, -1.03913E-4, -1.03967E-4, -1.01918E-4, -9.76944E-5, -9.12678E-5, -8.26538E-5, -7.19143E-5, -5.91587E-5, -4.45437E-5, -2.82723E-5, -1.05924E-5, 8.2068E-6, 2.77983E-5, 4.78228E-5, 6.78939E-5, 8.76057E-5, 1.0654E-4, 1.24273E-4, 1.40387E-4, 1.54476E-4, 1.66156E-4, 1.75076E-4, 1.80924E-4, 1.83434E-4, 1.82399E-4, 1.77673E-4, 1.69178E-4, 1.56912E-4, 1.40946E-4, 1.21433E-4, 9.86032E-5, 7.27648E-5, 4.43015E-5, 1.36672E-5, -1.86198E-5, -5.19848E-5, -8.5806E-5, -1.19425E-4, -1.52158E-4, -1.83312E-4, -2.12192E-4, -2.38121E-4, -2.60454E-4, -2.7859E-4, -2.91984E-4, -3.00169E-4, -3.0276E-4, -2.99468E-4, -2.90113E-4, -2.74626E-4, -2.53062E-4, -2.25598E-4, -1.92537E-4, -1.54308E-4, -1.11461E-4, -6.46589E-5, -1.46731E-5, 3.76316E-5, 9.13089E-5, 1.45347E-4, 1.98688E-4, 2.50244E-4, 2.98921E-4, 3.4364E-4, 3.83359E-4, 4.17094E-4, 4.43943E-4, 4.63107E-4, 4.73908E-4, 4.75811E-4, 4.68435E-4, 4.51572E-4, 4.25192E-4, 3.89457E-4, 3.44717E-4, 2.91518E-4, 2.30593E-4, 1.62855E-4, 8.93867E-5, 1.14256E-5, -6.96569E-5, -1.52377E-4, -2.35163E-4, -3.16387E-4, -3.94389E-4, -4.67516E-4, -5.34151E-4, -5.92746E-4, -6.41857E-4, -6.80176E-4, -7.06562E-4, -7.20069E-4, -7.19972E-4, -7.05789E-4, -6.77298E-4, -6.34555E-4, -5.77895E-4, -5.07943E-4, -4.25606E-4, -3.32066E-4, -2.28768E-4, -1.174E-4, 0.0, 1.21742E-4, 2.45182E-4, 3.68097E-4, 4.88061E-4, 6.02622E-4, 7.09351E-4, 8.05893E-4, 8.90011E-4, 9.59636E-4, 0.00101292, 0.00104825, 0.00106436, 0.00106026, 0.00103537, 9.89462E-4, 9.22745E-4, 8.35821E-4, 7.29714E-4, 6.05858E-4, 4.66081E-4, 3.12582E-4, 1.47904E-4, -2.5112E-5, -2.03366E-4, -3.83554E-4, -5.62227E-4, -7.35852E-4, -9.00879E-4, -0.00105381, -0.00119127, -0.00131008, -0.0014073, -0.00148035, -0.001527, -0.0015455, -0.00153455, -0.00149341, -0.00142191, -0.00132043, -0.00118997, -0.00103213, -8.49077E-4, -6.43548E-4, -4.18801E-4, -1.78576E-4, 7.29702E-5, 3.31323E-4, 5.91691E-4, 8.49089E-4, 0.00109843, 0.00133461, 0.00155262, 0.00174764, 0.00191514, 0.00205097, 0.00215146, 0.0022135, 0.00223462, 0.00221307, 0.00214784, 0.00203875, 0.00188646, 0.00169248, 0.00145916, 0.0011897, 8.88092E-4, 5.59089E-4, 2.08118E-4, -1.58787E-4, -5.35086E-4, -9.13836E-4, -0.00128782, -0.00164965, -0.00199195, -0.00230743, -0.0025891, -0.00283035, -0.00302512, -0.00316804, -0.00325451, -0.00328088, -0.00324448, -0.00314378, -0.00297838, -0.00274912, -0.00245805, -0.00210849, -0.00170499, -0.00125326, -7.60145E-4, -2.33532E-4, 3.1778E-4, 8.84194E-4, 0.00145547, 0.00202087, 0.00256938, 0.00308986, 0.00357125, 0.00400281, 0.00437426, 0.00467606, 0.00489956, 0.00503721, 0.00508271, 0.00503122, 0.00487946, 0.00462586, 0.00427064, 0.00381586, 0.0032655, 0.00262545, 0.00190346, 0.00110913, 2.53808E-4, -6.49562E-4, -0.00158654, -0.00254141, -0.00349735, -0.00443666, -0.00534107, -0.00619192, -0.00697049, -0.00765827, -0.00823729, -0.00869033, -0.0090013, -0.00915546, -0.0091397, -0.00894278, -0.00855557, -0.00797123, -0.00718538, -0.00619624, -0.00500471, -0.00361446, -0.0020319, -2.6623E-4, 0.0016707, 0.00376445, 0.00599812, 0.00835257, 0.0108066, 0.0133372, 0.0159199, 0.018529, 0.0211379, 0.0237194, 0.0262461, 0.028691, 0.0310273, 0.0332294, 0.0352727, 0.0371342, 0.038793, 0.0402302, 0.0414294, 0.0423767, 0.0430613, 0.0434752, 0.0436137, 0.0434752, 0.0430613, 0.0423767, 0.0414294, 0.0402302, 0.038793, 0.0371342, 0.0352727, 0.0332294, 0.0310273, 0.028691, 0.0262461, 0.0237194, 0.0211379, 0.018529, 0.0159199, 0.0133372, 0.0108066, 0.00835257, 0.00599812, 0.00376445, 0.0016707, -2.6623E-4, -0.0020319, -0.00361446, -0.00500471, -0.00619624, -0.00718538, -0.00797123, -0.00855557, -0.00894278, -0.0091397, -0.00915546, -0.0090013, -0.00869033, -0.00823729, -0.00765827, -0.00697049, -0.00619192, -0.00534107, -0.00443666, -0.00349735, -0.00254141, -0.00158654, -6.49562E-4, 2.53808E-4, 0.00110913, 0.00190346, 0.00262545, 0.0032655, 0.00381586, 0.00427064, 0.00462586, 0.00487946, 0.00503122, 0.00508271, 0.00503721, 0.00489956, 0.00467606, 0.00437426, 0.00400281, 0.00357125, 0.00308986, 0.00256938, 0.00202087, 0.00145547, 8.84194E-4, 3.1778E-4, -2.33532E-4, -7.60145E-4, -0.00125326, -0.00170499, -0.00210849, -0.00245805, -0.00274912, -0.00297838, -0.00314378, -0.00324448, -0.00328088, -0.00325451, -0.00316804, -0.00302512, -0.00283035, -0.0025891, -0.00230743, -0.00199195, -0.00164965, -0.00128782, -9.13836E-4, -5.35086E-4, -1.58787E-4, 2.08118E-4, 5.59089E-4, 8.88092E-4, 0.0011897, 0.00145916, 0.00169248, 0.00188646, 0.00203875, 0.00214784, 0.00221307, 0.00223462, 0.0022135, 0.00215146, 0.00205097, 0.00191514, 0.00174764, 0.00155262, 0.00133461, 0.00109843, 8.49089E-4, 5.91691E-4, 3.31323E-4, 7.29702E-5, -1.78576E-4, -4.18801E-4, -6.43548E-4, -8.49077E-4, -0.00103213, -0.00118997, -0.00132043, -0.00142191, -0.00149341, -0.00153455, -0.0015455, -0.001527, -0.00148035, -0.0014073, -0.00131008, -0.00119127, -0.00105381, -9.00879E-4, -7.35852E-4, -5.62227E-4, -3.83554E-4, -2.03366E-4, -2.5112E-5, 1.47904E-4, 3.12582E-4, 4.66081E-4, 6.05858E-4, 7.29714E-4, 8.35821E-4, 9.22745E-4, 9.89462E-4, 0.00103537, 0.00106026, 0.00106436, 0.00104825, 0.00101292, 9.59636E-4, 8.90011E-4, 8.05893E-4, 7.09351E-4, 6.02622E-4, 4.88061E-4, 3.68097E-4, 2.45182E-4, 1.21742E-4, 0.0, -1.174E-4, -2.28768E-4, -3.32066E-4, -4.25606E-4, -5.07943E-4, -5.77895E-4, -6.34555E-4, -6.77298E-4, -7.05789E-4, -7.19972E-4, -7.20069E-4, -7.06562E-4, -6.80176E-4, -6.41857E-4, -5.92746E-4, -5.34151E-4, -4.67516E-4, -3.94389E-4, -3.16387E-4, -2.35163E-4, -1.52377E-4, -6.96569E-5, 1.14256E-5, 8.93867E-5, 1.62855E-4, 2.30593E-4, 2.91518E-4, 3.44717E-4, 3.89457E-4, 4.25192E-4, 4.51572E-4, 4.68435E-4, 4.75811E-4, 4.73908E-4, 4.63107E-4, 4.43943E-4, 4.17094E-4, 3.83359E-4, 3.4364E-4, 2.98921E-4, 2.50244E-4, 1.98688E-4, 1.45347E-4, 9.13089E-5, 3.76316E-5, -1.46731E-5, -6.46589E-5, -1.11461E-4, -1.54308E-4, -1.92537E-4, -2.25598E-4, -2.53062E-4, -2.74626E-4, -2.90113E-4, -2.99468E-4, -3.0276E-4, -3.00169E-4, -2.91984E-4, -2.7859E-4, -2.60454E-4, -2.38121E-4, -2.12192E-4, -1.83312E-4, -1.52158E-4, -1.19425E-4, -8.5806E-5, -5.19848E-5, -1.86198E-5, 1.36672E-5, 4.43015E-5, 7.27648E-5, 9.86032E-5, 1.21433E-4, 1.40946E-4, 1.56912E-4, 1.69178E-4, 1.77673E-4, 1.82399E-4, 1.83434E-4, 1.80924E-4, 1.75076E-4, 1.66156E-4, 1.54476E-4, 1.40387E-4, 1.24273E-4, 1.0654E-4, 8.76057E-5, 6.78939E-5, 4.78228E-5, 2.77983E-5, 8.2068E-6, -1.05924E-5, -2.82723E-5, -4.45437E-5, -5.91587E-5, -7.19143E-5, -8.26538E-5, -9.12678E-5, -9.76944E-5, -1.01918E-4, -1.03967E-4, -1.03913E-4, -1.01863E-4, -9.79596E-5, -9.23761E-5, -8.53089E-5, -7.69741E-5, -6.76023E-5, -5.74324E-5, -4.67069E-5, -3.56668E-5, -2.45464E-5, -1.35693E-5, -2.94401E-6, 7.13901E-6, 1.65107E-5, 2.50256E-5, 3.25635E-5, 3.90306E-5, 4.436E-5, 4.85116E-5, 5.14714E-5, 5.32507E-5, 5.38838E-5, 5.34267E-5, 5.19541E-5, 4.95575E-5, 4.63415E-5, 4.24216E-5, 3.79207E-5, 3.29662E-5, 2.76871E-5, 2.22113E-5, 1.66626E-5, 1.11587E-5, 5.80895E-6, 0.0, -4.04381E-6, -8.38492E-6, -1.22502E-5, -1.55928E-5, -1.83803E-5, -2.05942E-5, -2.22296E-5, -2.32942E-5, -2.38078E-5, -2.38003E-5, -2.33112E-5, -2.23875E-5, -2.10822E-5, -1.9453E-5, -1.75604E-5, -1.54663E-5, -1.32324E-5, -1.09188E-5, -8.58267E-6, -6.27731E-6, -4.05104E-6, -1.94649E-6, 0.0, 1.75876E-6, 3.30701E-6, 4.62889E-6, 5.71529E-6, 6.56356E-6, 7.17706E-6, 7.56459E-6, 7.73976E-6, 7.72022E-6, 7.52689E-6, 7.18315E-6, 6.714E-6, 6.1453E-6, 5.50295E-6, 4.81223E-6, 4.09716E-6, 3.37989E-6, 2.68031E-6, 2.01565E-6, 1.40024E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.02188E-6, -1.03001E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "number_of_sets" value="1"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_full_bit_width" value="57"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_full_bits_right_of_binary_point" value="55"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "coefficient_reload_bit_width" value="24"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "logic_cell" value="1639"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "m512" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "m4k" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "m144k" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "m9k" value="6"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "m20k" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "mlab" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "megaram" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "dsp_block" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "input_clock_period" value="32"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_clock_period" value="640"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "throughput" value="640"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "memory_units" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:     </NAMESPACE>
// Retrieval info:     <NAMESPACE name = "simgen_enable">
// Retrieval info:      <PRIVATE name = "matlab_enable" value="1"  type="BOOLEAN"  enable="1" />
// Retrieval info:      <PRIVATE name = "testbench_enable" value="1"  type="BOOLEAN"  enable="1" />
// Retrieval info:      <PRIVATE name = "testbench_simulation_clock_period" value="10.0"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "language" value="Verilog HDL"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "enabled" value="0"  type="BOOLEAN"  enable="1" />
// Retrieval info:     </NAMESPACE>
// Retrieval info:     <NAMESPACE name = "simgen">
// Retrieval info:      <PRIVATE name = "filename" value="fir_20ex_2ch.vo"  type="STRING"  enable="1" />
// Retrieval info:     </NAMESPACE>
// Retrieval info:     <NAMESPACE name = "quartus_settings">
// Retrieval info:      <PRIVATE name = "DEVICE" value="EP4CE22E22I7"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "FAMILY" value="Cyclone IV E"  type="STRING"  enable="1" />
// Retrieval info:     </NAMESPACE>
// Retrieval info:     <NAMESPACE name = "serializer"/>
// Retrieval info:    </PRIVATES>
// Retrieval info:    <FILES/>
// Retrieval info:    <PORTS/>
// Retrieval info:    <LIBRARIES/>
// Retrieval info:   </STATIC_SECTION>
// Retrieval info:  </NETLIST_SECTION>
// Retrieval info: </MEGACORE>
// =========================================================

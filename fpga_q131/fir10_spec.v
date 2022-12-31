// megafunction wizard: %FIR Compiler v13.1%
// GENERATION: XML

// ============================================================
// Megafunction Name(s):
// 			fir10_spec_ast
// ============================================================
// Generated by FIR Compiler 13.1 [Altera, IP Toolbench 1.3.0 Build 182]
// ************************************************************
// THIS IS A WIZARD-GENERATED FILE. DO NOT EDIT THIS FILE!
// ************************************************************
// Copyright (C) 1991-2022 Altera Corporation
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


module fir10_spec (
	clk,
	reset_n,
	ast_sink_data,
	ast_sink_valid,
	ast_source_ready,
	ast_sink_sop,
	ast_sink_eop,
	ast_sink_error,
	coef_we,
	coef_in,
	ast_source_data,
	ast_sink_ready,
	ast_source_valid,
	ast_source_sop,
	ast_source_eop,
	ast_source_channel,
	ast_source_error);


	input		clk;
	input		reset_n;
	input	[27:0]	ast_sink_data;
	input		ast_sink_valid;
	input		ast_source_ready;
	input		ast_sink_sop;
	input		ast_sink_eop;
	input	[1:0]	ast_sink_error;
	input		coef_we;
	input	[31:0]	coef_in;
	output	[27:0]	ast_source_data;
	output		ast_sink_ready;
	output		ast_source_valid;
	output		ast_source_sop;
	output		ast_source_eop;
	output		ast_source_channel;
	output	[1:0]	ast_source_error;


	fir10_spec_ast	fir10_spec_ast_inst(
		.clk(clk),
		.reset_n(reset_n),
		.ast_sink_data(ast_sink_data),
		.ast_sink_valid(ast_sink_valid),
		.ast_source_ready(ast_source_ready),
		.ast_sink_sop(ast_sink_sop),
		.ast_sink_eop(ast_sink_eop),
		.ast_sink_error(ast_sink_error),
		.coef_we(coef_we),
		.coef_in(coef_in),
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
// Retrieval info:  <NETLIST_SECTION class="altera.ipbu.flowbase.netlist.model.FIRModelClass"  active_core="fir10_spec_ast" >
// Retrieval info:   <STATIC_SECTION>
// Retrieval info:    <PRIVATES>
// Retrieval info:     <NAMESPACE name = "parameterization">
// Retrieval info:      <PRIVATE name = "use_mem" value="1"  type="BOOLEAN"  enable="1" />
// Retrieval info:      <PRIVATE name = "mem_type" value="M512"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "filter_rate" value="Decimation"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "filter_factor" value="10"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "coefficient_scaling_type" value="Signed Binary Fractional"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "coefficient_scaling_factor" value="2.147483648E9"  type="STRING"  enable="0" />
// Retrieval info:      <PRIVATE name = "coefficient_bit_width" value="32"  type="INTEGER"  enable="0" />
// Retrieval info:      <PRIVATE name = "coefficient_binary_point_position" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "number_of_input_channels" value="2"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "input_number_system" value="Signed Binary"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "input_bit_width" value="28"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "input_binary_point_position" value="0"  type="INTEGER"  enable="0" />
// Retrieval info:      <PRIVATE name = "output_bit_width_method" value="Bit Width Only"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_number_system" value="Custom Resolution"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_bit_width" value="28"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_bits_right_of_binary_point" value="28"  type="INTEGER"  enable="0" />
// Retrieval info:      <PRIVATE name = "output_bits_removed_from_lsb" value="31"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_lsb_remove_type" value="Truncate"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_msb_remove_type" value="Truncate"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "flow_control" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "flow_control_input" value="Slave Sink"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "flow_control_output" value="Master Source"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "device_family" value="Cyclone IV E"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "structure" value="Variable/Fixed Coefficient : Multi-Cycle"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "pipeline_level" value="3"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "clocks_to_compute" value="64"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "number_of_serial_units" value="2"  type="INTEGER"  enable="0" />
// Retrieval info:      <PRIVATE name = "data_storage" value="M9K"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "coefficient_storage" value="M9K"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "multiplier_storage" value="DSP Blocks"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "force_non_symmetric_structure" value="0"  type="BOOLEAN"  enable="1" />
// Retrieval info:      <PRIVATE name = "coefficients_reload" value="1"  type="BOOLEAN"  enable="1" />
// Retrieval info:      <PRIVATE name = "coefficients_reload_sgl_clock" value="1"  type="BOOLEAN"  enable="1" />
// Retrieval info:      <PRIVATE name = "max_clocks_to_compute" value="64"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "set_1" value="Low Pass Set, Floating, Low Pass, Blackman, 1024, 960000.0, 44000.0, 3750000.0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.12762E-6, 1.36158E-6, 1.50144E-6, 1.5169E-6, 1.38631E-6, 1.10022E-6, 0.0, 0.0, 0.0, -1.25115E-6, -1.92268E-6, -2.50315E-6, -2.92539E-6, -3.12975E-6, -3.07081E-6, -2.72344E-6, -2.08738E-6, -1.18994E-6, 0.0, 1.14377E-6, 2.39952E-6, 3.56842E-6, 4.53484E-6, 5.19087E-6, 5.44719E-6, 5.24308E-6, 4.55462E-6, 3.40015E-6, 1.84218E-6, 0.0, -2.02965E-6, -4.03613E-6, -5.85446E-6, -7.30748E-6, -8.23677E-6, -8.51854E-6, -8.0774E-6, -6.89687E-6, -5.02519E-6, -2.57571E-6, 0.0, 3.31628E-6, 6.28405E-6, 8.91691E-6, 1.09611E-5, 1.21975E-5, 1.24633E-5, 1.16701E-5, 9.81683E-6, 6.99531E-6, 3.38816E-6, 0.0, -5.06856E-6, -9.22994E-6, -1.28549E-5, -1.55967E-5, -1.71647E-5, -1.73528E-5, -1.60627E-5, -1.33189E-5, -9.27316E-6, -4.19916E-6, 1.52488E-6, 7.44308E-6, 1.30572E-5, 1.78678E-5, 2.14173E-5, 2.3332E-5, 2.33592E-5, 2.13953E-5, 1.75027E-5, 1.19134E-5, 5.01722E-6, -2.66314E-6, -1.05109E-5, -1.78633E-5, -2.40667E-5, -2.85332E-5, -3.07946E-5, -3.05485E-5, -2.76927E-5, -2.23436E-5, -1.48364E-5, -5.70743E-6, 4.34283E-6, 1.45019E-5, 2.39097E-5, 3.17302E-5, 3.72241E-5, 3.98167E-5, 3.91544E-5, 3.51454E-5, 2.79789E-5, 1.8122E-5, 6.29179E-6, -6.59455E-6, -1.94896E-5, -3.1299E-5, -4.09735E-5, -4.75996E-5, -5.04841E-5, -4.9222E-5, -4.37436E-5, -3.43348E-5, -2.16272E-5, -6.55918E-6, 9.6914E-6, 2.57975E-5, 4.03898E-5, 5.21711E-5, 6.00302E-5, 6.3143E-5, 6.10551E-5, 5.37344E-5, 4.15913E-5, 2.54608E-5, 6.54894E-6, -1.36555E-5, -3.34959E-5, -5.1282E-5, -6.54322E-5, -7.46113E-5, -7.78537E-5, -7.46592E-5, -6.50528E-5, -4.96028E-5, -2.93929E-5, -5.94979E-6, 1.88698E-5, 4.30237E-5, 6.44508E-5, 8.12441E-5, 9.18185E-5, 9.5056E-5, 9.04176E-5, 7.80095E-5, 5.85976E-5, 3.35664E-5, 4.82364E-6, -2.53417E-5, -5.44399E-5, -7.99834E-5, -9.96971E-5, -1.11718E-4, -1.14766E-4, -1.08275E-4, -9.24605E-5, -6.83333E-5, -3.76383E-5, -2.73317E-6, 3.35894E-5, 6.83228E-5, 9.84931E-5, 1.21411E-4, 1.34906E-4, 1.37531E-4, 1.28704E-4, 1.08789E-4, 7.90938E-5, 4.1792E-5, 0.0, -4.35981E-5, -8.47111E-5, -1.20044E-4, -1.46442E-4, -1.61402E-4, -1.63303E-4, -1.51568E-4, -1.26748E-4, -9.05131E-5, -4.55442E-5, 4.65924E-6, 5.60484E-5, 1.04348E-4, 1.4541E-4, 1.75564E-4, 1.91944E-4, 1.92752E-4, 1.77441E-4, 1.46803E-4, 1.02939E-4, 4.91261E-5, -1.04258E-5, -7.08968E-5, -1.27245E-4, -1.74623E-4, -2.0879E-4, -2.2649E-4, -2.25749E-4, -2.06082E-4, -1.68579E-4, -1.15857E-4, -5.18849E-5, 1.83057E-5, 8.90166E-5, 1.5434E-4, 2.08648E-4, 2.47073E-4, 2.6594E-4, 2.63106E-4, 2.38187E-4, 1.92639E-4, 1.29686E-4, 5.41064E-5, -2.81318E-5, -1.10332E-4, -1.85612E-4, -2.47477E-4, -2.90374E-4, -3.10182E-4, -3.046E-4, -2.73391E-4, -2.18457E-4, -1.43737E-4, -5.49383E-5, 4.08969E-5, 1.35945E-4, 2.22233E-4, 2.92305E-4, 3.39861E-4, 3.60311E-4, 3.51214E-4, 3.12533E-4, 2.46708E-4, 1.58513E-4, 5.47252E-5, -5.63946E-5, -1.65752E-4, -2.64157E-4, -3.43094E-4, -3.9545E-4, -4.16149E-4, -4.02627E-4, -3.55117E-4, -2.76699E-4, -1.73121E-4, -5.23822E-5, 7.5875E-5, 2.01129E-4, 3.12836E-4, 4.01314E-4, 4.58574E-4, 4.7903E-4, 4.6003E-4, 4.02152E-4, 3.09239E-4, 1.8816E-4, 4.83101E-5, -9.9105E-5, -2.41966E-4, -3.68228E-4, -4.66928E-4, -5.29132E-4, -5.48731E-4, -5.23022E-4, -4.53018E-4, -3.43459E-4, -2.02509E-4, -4.11525E-5, 1.27645E-4, 2.89979E-4, 4.32139E-4, 5.41762E-4, 6.08897E-4, 6.269E-4, 5.93062E-4, 5.08939E-4, 3.80324E-4, 2.16863E-4, 3.13498E-5, -1.61273E-4, -3.45105E-4, -5.04594E-4, -6.25847E-4, -6.97823E-4, -7.1333E-4, -6.69714E-4, -5.69195E-4, -4.18791E-4, -2.29854E-4, -1.72211E-5, 2.01938E-4, 4.09498E-4, 5.87873E-4, 7.21492E-4, 7.98147E-4, 8.10094E-4, 7.54803E-4, 6.35295E-4, 4.60016E-4, 2.42267E-4, 0.0, -2.49506E-4, -4.83255E-4, -6.82203E-4, -8.28945E-4, -9.10023E-4, -9.17138E-4, -8.47965E-4, -7.06487E-4, -5.02808E-4, -2.52454E-4, 2.47942E-5, 3.06453E-4, 5.69148E-4, 7.90541E-4, 9.51218E-4, 0.00103638, 0.00103716, 9.51553E-4, 7.84677E-4, 5.48558E-4, 2.61269E-4, -5.44353E-5, -3.72902E-4, -6.67657E-4, -9.13588E-4, -0.00108907, -0.00117785, -0.00117053, -0.00106549, -8.69227E-4, -5.95979E-4, -2.66735E-4, 9.23683E-5, 4.52101E-4, 7.82506E-4, 0.00105538, 0.00124665, 0.0013385, 0.00132096, 0.00119298, 9.62649E-4, 6.46783E-4, 2.69712E-4, -1.38571E-4, -5.44781E-4, -9.15029E-4, -0.00121764, -0.00142582, -0.00152004, -0.00148979, -0.00133468, -0.00106472, -6.99697E-4, -2.67804E-4, 1.96558E-4, 6.55471E-4, 0.00107058, 0.00140629, 0.00163274, 0.00172852, 0.00168254, 0.00149527, 0.00117897, 7.56912E-4, 2.61726E-4, -2.67086E-4, -7.86282E-4, -0.00125239, -0.00162531, -0.00187173, -0.00196809, -0.00190272, -0.00167714, -0.00130626, -8.17416E-4, -2.48442E-4, 3.55234E-4, 9.44184E-4, 0.00146899, 0.00188435, 0.00215296, 0.00224878, 0.00215952, 0.00188797, 0.00145215, 8.84233E-4, 2.2816E-4, -4.6366E-4, -0.00113451, -0.00172798, -0.00219263, -0.00248642, -0.00258043, -0.00246161, -0.00213427, -0.00162018, -9.57211E-4, -1.96631E-4, 6.00815E-4, 0.00136968, 0.00204514, 0.00256837, 0.0028916, 0.00298239, 0.00282674, 0.00243073, 0.00182061, 0.00104117, 1.52535E-4, -7.74373E-4, -0.00166342, -0.00243941, -0.00303437, -0.00339338, -0.00347949, -0.00327736, -0.00279512, -0.00206443, -0.00113856, -8.86332E-5, 0.00100171, 0.00204286, 0.00294646, 0.00363276, 0.00403747, 0.00411764, 0.0038558, 0.00326235, 0.00237553, 0.00125924, -1.38623E-6, -0.00130628, -0.0025482, -0.00362133, -0.00443003, -0.00489715, -0.00497098, -0.00463052, -0.00388829, -0.0027906, -0.00141499, 1.3491E-4, 0.0017369, 0.00325951, 0.00457241, 0.00555714, 0.00611737, 0.00618765, 0.00574014, 0.00478852, 0.00338869, 0.00163614, -3.40038E-4, -0.00238609, -0.00433493, -0.00601905, -0.00728409, -0.008002, -0.00808274, -0.00748355, -0.00621488, -0.00434256, -0.00198557, 6.90395E-4, 0.00348332, 0.00616873, 0.00851603, 0.0103062, 0.0113498, 0.0115035, 0.0106845, 0.00888087, 0.00615787, 0.0026586, -0.00140073, -0.00574097, -0.0100352, -0.0139279, -0.0170575, -0.0190798, -0.0196922, -0.0186557, -0.015814, -0.0111081, -0.00458487, 0.00359998, 0.0131867, 0.0238223, 0.0350777, 0.0464699, 0.0574882, 0.0676229, 0.0763938, 0.0833781, 0.0882347, 0.0907246, 0.0907246, 0.0882347, 0.0833781, 0.0763938, 0.0676229, 0.0574882, 0.0464699, 0.0350777, 0.0238223, 0.0131867, 0.00359998, -0.00458487, -0.0111081, -0.015814, -0.0186557, -0.0196922, -0.0190798, -0.0170575, -0.0139279, -0.0100352, -0.00574097, -0.00140073, 0.0026586, 0.00615787, 0.00888087, 0.0106845, 0.0115035, 0.0113498, 0.0103062, 0.00851603, 0.00616873, 0.00348332, 6.90395E-4, -0.00198557, -0.00434256, -0.00621488, -0.00748355, -0.00808274, -0.008002, -0.00728409, -0.00601905, -0.00433493, -0.00238609, -3.40038E-4, 0.00163614, 0.00338869, 0.00478852, 0.00574014, 0.00618765, 0.00611737, 0.00555714, 0.00457241, 0.00325951, 0.0017369, 1.3491E-4, -0.00141499, -0.0027906, -0.00388829, -0.00463052, -0.00497098, -0.00489715, -0.00443003, -0.00362133, -0.0025482, -0.00130628, -1.38623E-6, 0.00125924, 0.00237553, 0.00326235, 0.0038558, 0.00411764, 0.00403747, 0.00363276, 0.00294646, 0.00204286, 0.00100171, -8.86332E-5, -0.00113856, -0.00206443, -0.00279512, -0.00327736, -0.00347949, -0.00339338, -0.00303437, -0.00243941, -0.00166342, -7.74373E-4, 1.52535E-4, 0.00104117, 0.00182061, 0.00243073, 0.00282674, 0.00298239, 0.0028916, 0.00256837, 0.00204514, 0.00136968, 6.00815E-4, -1.96631E-4, -9.57211E-4, -0.00162018, -0.00213427, -0.00246161, -0.00258043, -0.00248642, -0.00219263, -0.00172798, -0.00113451, -4.6366E-4, 2.2816E-4, 8.84233E-4, 0.00145215, 0.00188797, 0.00215952, 0.00224878, 0.00215296, 0.00188435, 0.00146899, 9.44184E-4, 3.55234E-4, -2.48442E-4, -8.17416E-4, -0.00130626, -0.00167714, -0.00190272, -0.00196809, -0.00187173, -0.00162531, -0.00125239, -7.86282E-4, -2.67086E-4, 2.61726E-4, 7.56912E-4, 0.00117897, 0.00149527, 0.00168254, 0.00172852, 0.00163274, 0.00140629, 0.00107058, 6.55471E-4, 1.96558E-4, -2.67804E-4, -6.99697E-4, -0.00106472, -0.00133468, -0.00148979, -0.00152004, -0.00142582, -0.00121764, -9.15029E-4, -5.44781E-4, -1.38571E-4, 2.69712E-4, 6.46783E-4, 9.62649E-4, 0.00119298, 0.00132096, 0.0013385, 0.00124665, 0.00105538, 7.82506E-4, 4.52101E-4, 9.23683E-5, -2.66735E-4, -5.95979E-4, -8.69227E-4, -0.00106549, -0.00117053, -0.00117785, -0.00108907, -9.13588E-4, -6.67657E-4, -3.72902E-4, -5.44353E-5, 2.61269E-4, 5.48558E-4, 7.84677E-4, 9.51553E-4, 0.00103716, 0.00103638, 9.51218E-4, 7.90541E-4, 5.69148E-4, 3.06453E-4, 2.47942E-5, -2.52454E-4, -5.02808E-4, -7.06487E-4, -8.47965E-4, -9.17138E-4, -9.10023E-4, -8.28945E-4, -6.82203E-4, -4.83255E-4, -2.49506E-4, 0.0, 2.42267E-4, 4.60016E-4, 6.35295E-4, 7.54803E-4, 8.10094E-4, 7.98147E-4, 7.21492E-4, 5.87873E-4, 4.09498E-4, 2.01938E-4, -1.72211E-5, -2.29854E-4, -4.18791E-4, -5.69195E-4, -6.69714E-4, -7.1333E-4, -6.97823E-4, -6.25847E-4, -5.04594E-4, -3.45105E-4, -1.61273E-4, 3.13498E-5, 2.16863E-4, 3.80324E-4, 5.08939E-4, 5.93062E-4, 6.269E-4, 6.08897E-4, 5.41762E-4, 4.32139E-4, 2.89979E-4, 1.27645E-4, -4.11525E-5, -2.02509E-4, -3.43459E-4, -4.53018E-4, -5.23022E-4, -5.48731E-4, -5.29132E-4, -4.66928E-4, -3.68228E-4, -2.41966E-4, -9.9105E-5, 4.83101E-5, 1.8816E-4, 3.09239E-4, 4.02152E-4, 4.6003E-4, 4.7903E-4, 4.58574E-4, 4.01314E-4, 3.12836E-4, 2.01129E-4, 7.5875E-5, -5.23822E-5, -1.73121E-4, -2.76699E-4, -3.55117E-4, -4.02627E-4, -4.16149E-4, -3.9545E-4, -3.43094E-4, -2.64157E-4, -1.65752E-4, -5.63946E-5, 5.47252E-5, 1.58513E-4, 2.46708E-4, 3.12533E-4, 3.51214E-4, 3.60311E-4, 3.39861E-4, 2.92305E-4, 2.22233E-4, 1.35945E-4, 4.08969E-5, -5.49383E-5, -1.43737E-4, -2.18457E-4, -2.73391E-4, -3.046E-4, -3.10182E-4, -2.90374E-4, -2.47477E-4, -1.85612E-4, -1.10332E-4, -2.81318E-5, 5.41064E-5, 1.29686E-4, 1.92639E-4, 2.38187E-4, 2.63106E-4, 2.6594E-4, 2.47073E-4, 2.08648E-4, 1.5434E-4, 8.90166E-5, 1.83057E-5, -5.18849E-5, -1.15857E-4, -1.68579E-4, -2.06082E-4, -2.25749E-4, -2.2649E-4, -2.0879E-4, -1.74623E-4, -1.27245E-4, -7.08968E-5, -1.04258E-5, 4.91261E-5, 1.02939E-4, 1.46803E-4, 1.77441E-4, 1.92752E-4, 1.91944E-4, 1.75564E-4, 1.4541E-4, 1.04348E-4, 5.60484E-5, 4.65924E-6, -4.55442E-5, -9.05131E-5, -1.26748E-4, -1.51568E-4, -1.63303E-4, -1.61402E-4, -1.46442E-4, -1.20044E-4, -8.47111E-5, -4.35981E-5, 0.0, 4.1792E-5, 7.90938E-5, 1.08789E-4, 1.28704E-4, 1.37531E-4, 1.34906E-4, 1.21411E-4, 9.84931E-5, 6.83228E-5, 3.35894E-5, -2.73317E-6, -3.76383E-5, -6.83333E-5, -9.24605E-5, -1.08275E-4, -1.14766E-4, -1.11718E-4, -9.96971E-5, -7.99834E-5, -5.44399E-5, -2.53417E-5, 4.82364E-6, 3.35664E-5, 5.85976E-5, 7.80095E-5, 9.04176E-5, 9.5056E-5, 9.18185E-5, 8.12441E-5, 6.44508E-5, 4.30237E-5, 1.88698E-5, -5.94979E-6, -2.93929E-5, -4.96028E-5, -6.50528E-5, -7.46592E-5, -7.78537E-5, -7.46113E-5, -6.54322E-5, -5.1282E-5, -3.34959E-5, -1.36555E-5, 6.54894E-6, 2.54608E-5, 4.15913E-5, 5.37344E-5, 6.10551E-5, 6.3143E-5, 6.00302E-5, 5.21711E-5, 4.03898E-5, 2.57975E-5, 9.6914E-6, -6.55918E-6, -2.16272E-5, -3.43348E-5, -4.37436E-5, -4.9222E-5, -5.04841E-5, -4.75996E-5, -4.09735E-5, -3.1299E-5, -1.94896E-5, -6.59455E-6, 6.29179E-6, 1.8122E-5, 2.79789E-5, 3.51454E-5, 3.91544E-5, 3.98167E-5, 3.72241E-5, 3.17302E-5, 2.39097E-5, 1.45019E-5, 4.34283E-6, -5.70743E-6, -1.48364E-5, -2.23436E-5, -2.76927E-5, -3.05485E-5, -3.07946E-5, -2.85332E-5, -2.40667E-5, -1.78633E-5, -1.05109E-5, -2.66314E-6, 5.01722E-6, 1.19134E-5, 1.75027E-5, 2.13953E-5, 2.33592E-5, 2.3332E-5, 2.14173E-5, 1.78678E-5, 1.30572E-5, 7.44308E-6, 1.52488E-6, -4.19916E-6, -9.27316E-6, -1.33189E-5, -1.60627E-5, -1.73528E-5, -1.71647E-5, -1.55967E-5, -1.28549E-5, -9.22994E-6, -5.06856E-6, 0.0, 3.38816E-6, 6.99531E-6, 9.81683E-6, 1.16701E-5, 1.24633E-5, 1.21975E-5, 1.09611E-5, 8.91691E-6, 6.28405E-6, 3.31628E-6, 0.0, -2.57571E-6, -5.02519E-6, -6.89687E-6, -8.0774E-6, -8.51854E-6, -8.23677E-6, -7.30748E-6, -5.85446E-6, -4.03613E-6, -2.02965E-6, 0.0, 1.84218E-6, 3.40015E-6, 4.55462E-6, 5.24308E-6, 5.44719E-6, 5.19087E-6, 4.53484E-6, 3.56842E-6, 2.39952E-6, 1.14377E-6, 0.0, -1.18994E-6, -2.08738E-6, -2.72344E-6, -3.07081E-6, -3.12975E-6, -2.92539E-6, -2.50315E-6, -1.92268E-6, -1.25115E-6, 0.0, 0.0, 0.0, 1.10022E-6, 1.38631E-6, 1.5169E-6, 1.50144E-6, 1.36158E-6, 1.12762E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "number_of_sets" value="1"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_full_bit_width" value="70"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_full_bits_right_of_binary_point" value="58"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "coefficient_reload_bit_width" value="32"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "logic_cell" value="981"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "m512" value="1"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "m4k" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "m144k" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "m9k" value="17"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "m20k" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "mlab" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "megaram" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "dsp_block" value="2"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "input_clock_period" value="64"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_clock_period" value="640"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "throughput" value="640"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "memory_units" value="1"  type="INTEGER"  enable="1" />
// Retrieval info:     </NAMESPACE>
// Retrieval info:     <NAMESPACE name = "simgen_enable">
// Retrieval info:      <PRIVATE name = "matlab_enable" value="1"  type="BOOLEAN"  enable="1" />
// Retrieval info:      <PRIVATE name = "testbench_enable" value="1"  type="BOOLEAN"  enable="1" />
// Retrieval info:      <PRIVATE name = "testbench_simulation_clock_period" value="10.0"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "language" value="Verilog HDL"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "enabled" value="0"  type="BOOLEAN"  enable="1" />
// Retrieval info:     </NAMESPACE>
// Retrieval info:     <NAMESPACE name = "simgen">
// Retrieval info:      <PRIVATE name = "filename" value="fir10_spec.vo"  type="STRING"  enable="1" />
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

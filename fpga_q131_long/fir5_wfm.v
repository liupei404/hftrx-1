// megafunction wizard: %FIR Compiler v13.1%
// GENERATION: XML

// ============================================================
// Megafunction Name(s):
// 			fir5_wfm_ast
// ============================================================
// Generated by FIR Compiler 13.1 [Altera, IP Toolbench 1.3.0 Build 182]
// ************************************************************
// THIS IS A WIZARD-GENERATED FILE. DO NOT EDIT THIS FILE!
// ************************************************************
// Copyright (C) 1991-2021 Altera Corporation
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


module fir5_wfm (
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
	input	[27:0]	ast_sink_data;
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


	fir5_wfm_ast	fir5_wfm_ast_inst(
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
// Retrieval info:  <NETLIST_SECTION class="altera.ipbu.flowbase.netlist.model.FIRModelClass"  active_core="fir5_wfm_ast" >
// Retrieval info:   <STATIC_SECTION>
// Retrieval info:    <PRIVATES>
// Retrieval info:     <NAMESPACE name = "parameterization">
// Retrieval info:      <PRIVATE name = "use_mem" value="1"  type="BOOLEAN"  enable="1" />
// Retrieval info:      <PRIVATE name = "mem_type" value="M512"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "filter_rate" value="Decimation"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "filter_factor" value="5"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "coefficient_scaling_type" value="Signed Binary Fractional"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "coefficient_scaling_factor" value="4194304.0"  type="STRING"  enable="0" />
// Retrieval info:      <PRIVATE name = "coefficient_bit_width" value="23"  type="INTEGER"  enable="0" />
// Retrieval info:      <PRIVATE name = "coefficient_binary_point_position" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "number_of_input_channels" value="2"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "input_number_system" value="Signed Binary"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "input_bit_width" value="28"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "input_binary_point_position" value="0"  type="INTEGER"  enable="0" />
// Retrieval info:      <PRIVATE name = "output_bit_width_method" value="Actual Coefficients"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_number_system" value="Custom Resolution"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_bit_width" value="32"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_bits_right_of_binary_point" value="32"  type="INTEGER"  enable="0" />
// Retrieval info:      <PRIVATE name = "output_bits_removed_from_lsb" value="18"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_lsb_remove_type" value="Truncate"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_msb_remove_type" value="Truncate"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "flow_control" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "flow_control_input" value="Slave Sink"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "flow_control_output" value="Master Source"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "device_family" value="Cyclone IV E"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "structure" value="Variable/Fixed Coefficient : Multi-Cycle"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "pipeline_level" value="2"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "clocks_to_compute" value="24"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "number_of_serial_units" value="2"  type="INTEGER"  enable="0" />
// Retrieval info:      <PRIVATE name = "data_storage" value="M9K"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "coefficient_storage" value="M9K"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "multiplier_storage" value="DSP Blocks"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "force_non_symmetric_structure" value="1"  type="BOOLEAN"  enable="1" />
// Retrieval info:      <PRIVATE name = "coefficients_reload" value="0"  type="BOOLEAN"  enable="1" />
// Retrieval info:      <PRIVATE name = "coefficients_reload_sgl_clock" value="0"  type="BOOLEAN"  enable="1" />
// Retrieval info:      <PRIVATE name = "max_clocks_to_compute" value="24"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "set_1" value="Low Pass Set, Floating, Low Pass, Blackman, 959, 960000.0, 80000.0, 3750000.0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.06861E-6, 0.0, 0.0, 0.0, 0.0, -1.54513E-6, -1.83649E-6, -1.62776E-6, 0.0, 0.0, 1.43744E-6, 2.42062E-6, 2.83668E-6, 2.48227E-6, 1.35652E-6, 0.0, -2.10414E-6, -3.5118E-6, -4.07769E-6, -3.53696E-6, -1.91762E-6, 0.0, 2.92217E-6, 4.84388E-6, 5.58764E-6, 4.81816E-6, 2.60217E-6, 0.0, -3.88882E-6, -6.4205E-6, -7.37209E-6, -6.32794E-6, -3.404E-6, 0.0, 5.03271E-6, 8.2789E-6, 9.47191E-6, 8.10497E-6, 4.35427E-6, 0.0, -6.3441E-6, -1.0417E-5, -1.18872E-5, -1.0145E-5, -5.43858E-6, 1.13249E-6, 7.86481E-6, 1.28872E-5, 1.46748E-5, 1.25021E-5, 6.70203E-6, -1.35514E-6, -9.57529E-6, -1.56789E-5, -1.78266E-5, -1.51631E-5, -8.11918E-6, 1.62571E-6, 1.15337E-5, 1.88626E-5, 2.14186E-5, 1.82006E-5, 9.7523E-6, -1.89679E-6, -1.37074E-5, -2.24165E-5, -2.54315E-5, -2.15894E-5, -1.15618E-5, 2.22699E-6, 1.61743E-5, 2.64329E-5, 2.9964E-5, 2.54243E-5, 1.36306E-5, -2.55042E-6, -1.88856E-5, -3.08749E-5, -3.49824E-5, -2.96648E-5, -1.59015E-5, 2.94611E-6, 2.19423E-5, 3.58604E-5, 4.06118E-5, 3.44318E-5, 1.84821E-5, -3.3259E-6, -2.52756E-5, -4.13341E-5, -4.68005E-5, -3.96656E-5, -2.12939E-5, 3.79306E-6, 2.90137E-5, 4.74432E-5, 5.37039E-5, 4.55173E-5, 2.44729E-5, -4.23308E-6, -3.30639E-5, -5.41103E-5, -6.12486E-5, -5.19042E-5, -2.79153E-5, 4.77762E-6, 3.75857E-5, 6.15162E-5, 6.9625E-5, 5.90121E-5, 3.17904E-5, -5.28139E-6, -4.2458E-5, -6.95567E-5, -7.8733E-5, -6.67308E-5, -3.59646E-5, 5.90891E-6, 4.78765E-5, 7.84513E-5, 8.88031E-5, 7.52858E-5, 4.06451E-5, -6.47942E-6, -5.36869E-5, -8.80645E-5, -9.97043E-5, -8.45349E-5, -4.56638E-5, 7.19503E-6, 6.01259E-5, 9.86594E-5, 1.11712E-4, 9.47483E-5, 5.12711E-5, -7.83449E-6, -6.70014E-5, -1.10064E-4, -1.2466E-4, -1.05747E-4, -5.72597E-5, 8.64253E-6, 7.45961E-5, 1.22592E-4, 1.38873E-4, 1.17852E-4, 6.39282E-5, -9.35223E-6, -8.26751E-5, -1.36028E-4, -1.54145E-4, -1.30841E-4, -7.10254E-5, 1.02561E-5, 9.15727E-5, 1.50741E-4, 1.70858E-4, 1.45093E-4, 7.89036E-5, -1.10362E-5, -1.01006E-4, -1.66473E-4, -1.8876E-4, -1.60339E-4, -8.72626E-5, 1.20382E-5, 1.11366E-4, 1.83649E-4, 2.08294E-4, 1.77019E-4, 9.65146E-5, -1.28876E-5, -1.22318E-4, -2.01963E-4, -2.2916E-4, -1.94814E-4, -1.06305E-4, 1.39886E-5, 1.34316E-4, 2.21907E-4, 2.51871E-4, 2.14231E-4, 1.17113E-4, -1.49048E-5, -1.46966E-4, -2.43118E-4, -2.76071E-4, -2.34899E-4, -1.28523E-4, 1.61043E-5, 1.60793E-4, 2.66165E-4, 3.02348E-4, 2.57397E-4, 1.41088E-4, -1.70834E-5, -1.75339E-4, -2.90624E-4, -3.30291E-4, -2.81295E-4, -1.54329E-4, 1.83793E-5, 1.91205E-4, 3.17145E-4, 3.60571E-4, 3.07256E-4, 1.68876E-4, -1.94159E-5, -2.07868E-4, -3.45243E-4, -3.92714E-4, -3.34788E-4, -1.84185E-4, 2.08044E-5, 2.26009E-4, 3.75654E-4, 4.27484E-4, 3.64643E-4, 2.0097E-4, -2.18913E-5, -2.45036E-4, -4.07831E-4, -4.64347E-4, -3.96265E-4, -2.18617E-4, 2.33669E-5, 2.6572E-4, 4.42605E-4, 5.04165E-4, 4.30505E-4, 2.37931E-4, -2.44956E-5, -2.87395E-4, -4.79367E-4, -5.46342E-4, -4.66744E-4, -2.58228E-4, 2.60511E-5, 3.10927E-4, 5.19052E-4, 5.91851E-4, 5.05938E-4, 2.8041E-4, -2.72118E-5, -3.3558E-4, -5.60986E-4, -6.40038E-4, -5.47408E-4, -3.03721E-4, 2.88382E-5, 3.62321E-4, 6.06224E-4, 6.91995E-4, 5.92228E-4, 3.29171E-4, -3.00195E-5, -3.90343E-4, -6.54032E-4, -7.4702E-4, -6.39662E-4, -3.55932E-4, 3.17063E-5, 4.20726E-4, 7.05593E-4, 8.06337E-4, 6.90916E-4, 3.85131E-4, -3.28956E-5, -4.52592E-4, -7.60125E-4, -8.69204E-4, -7.45206E-4, -4.15874E-4, 3.46307E-5, 4.87145E-4, 8.18953E-4, 9.37001E-4, 8.03886E-4, 4.49413E-4, -3.58145E-5, -5.23446E-4, -8.81264E-4, -0.00100896, -8.66142E-4, -4.84799E-4, 3.75846E-5, 5.62831E-4, 9.48546E-4, 0.00108664, 9.33498E-4, 5.23422E-4, -3.87484E-5, -6.04316E-4, -0.00101998, -0.00116928, -0.00100513, -5.64291E-4, 4.05388E-5, 6.49387E-4, 0.00109724, 0.00125865, 0.00108277, 6.08957E-4, -4.16677E-5, -6.97032E-4, -0.00117953, -0.00135404, -0.00116563, -6.56409E-4, 4.34627E-5, 7.48914E-4, 0.00126878, 0.00145749, 0.00125568, 7.08383E-4, -4.45414E-5, -8.04023E-4, -0.00136427, -0.00156841, -0.00135223, -7.6389E-4, 4.63248E-5, 8.64236E-4, 0.00146823, 0.00168918, 0.00145757, 8.24896E-4, -4.73378E-5, -9.286E-4, -0.00158012, -0.00181943, -0.00157122, -8.90489E-4, 4.90929E-5, 9.99265E-4, 0.0017026, 0.00196204, 0.00169591, 9.62939E-4, -5.00248E-5, -0.00107542, -0.00183543, -0.00211705, -0.0018315, -0.00104151, 5.17346E-5, 0.00115959, 0.00198189, 0.00228804, 0.00198138, 0.00112891, -5.25709E-5, -0.00125124, -0.00214232, -0.00247576, -0.00214606, -0.00122474, 5.42185E-5, 0.00135348, 0.00232096, 0.00268494, 0.00232995, 0.00133236, -5.4945E-5, -0.0014663, -0.0025192, -0.00291762, -0.00253472, -0.00145207, 5.6514E-5, 0.0015937, 0.00274285, 0.00318043, 0.00276655, 0.0015883, -5.71178E-5, -0.00173676, -0.00299529, -0.00347782, -0.00302929, -0.00174267, 5.85924E-5, 0.00190109, 0.00328524, 0.00381997, 0.00333237, 0.00192161, -5.90618E-5, -0.00208987, -0.00362003, -0.0042162, -0.00368412, -0.00212947, 6.04273E-5, 0.00231194, 0.00401426, 0.00468392, 0.00410067, 0.00237686, -6.07521E-5, -0.00257512, -0.00448394, -0.00524321, -0.00460035, -0.00267429, 6.19949E-5, 0.00289556, 0.00505729, 0.00592847, 0.00521522, 0.00304236, -6.21666E-5, -0.00329273, -0.00577231, -0.00678744, -0.00598974, -0.00350806, 6.32747E-5, 0.00380266, 0.00669499, 0.00790251, 0.00700181, 0.00412123, -6.32869E-5, -0.00448068, -0.00793247, -0.00941051, -0.00838214, -0.0049647, 6.42498E-5, 0.00543369, 0.00968963, 0.0115758, 0.0103882, 0.00620689, -6.40979E-5, -0.00687396, -0.0123885, -0.0149586, -0.0135798, -0.00822224, 6.49072E-5, 0.00932045, 0.0170915, 0.0210228, 0.0194844, 0.0120845, -6.45889E-5, -0.0144158, -0.0274017, -0.0351266, -0.0342009, -0.0225378, 6.52381E-5, 0.031702, 0.0685581, 0.105515, 0.137047, 0.158238, 0.165704, 0.158238, 0.137047, 0.105515, 0.0685581, 0.031702, 6.52381E-5, -0.0225378, -0.0342009, -0.0351266, -0.0274017, -0.0144158, -6.45889E-5, 0.0120845, 0.0194844, 0.0210228, 0.0170915, 0.00932045, 6.49072E-5, -0.00822224, -0.0135798, -0.0149586, -0.0123885, -0.00687396, -6.40979E-5, 0.00620689, 0.0103882, 0.0115758, 0.00968963, 0.00543369, 6.42498E-5, -0.0049647, -0.00838214, -0.00941051, -0.00793247, -0.00448068, -6.32869E-5, 0.00412123, 0.00700181, 0.00790251, 0.00669499, 0.00380266, 6.32747E-5, -0.00350806, -0.00598974, -0.00678744, -0.00577231, -0.00329273, -6.21666E-5, 0.00304236, 0.00521522, 0.00592847, 0.00505729, 0.00289556, 6.19949E-5, -0.00267429, -0.00460035, -0.00524321, -0.00448394, -0.00257512, -6.07521E-5, 0.00237686, 0.00410067, 0.00468392, 0.00401426, 0.00231194, 6.04273E-5, -0.00212947, -0.00368412, -0.0042162, -0.00362003, -0.00208987, -5.90618E-5, 0.00192161, 0.00333237, 0.00381997, 0.00328524, 0.00190109, 5.85924E-5, -0.00174267, -0.00302929, -0.00347782, -0.00299529, -0.00173676, -5.71178E-5, 0.0015883, 0.00276655, 0.00318043, 0.00274285, 0.0015937, 5.6514E-5, -0.00145207, -0.00253472, -0.00291762, -0.0025192, -0.0014663, -5.4945E-5, 0.00133236, 0.00232995, 0.00268494, 0.00232096, 0.00135348, 5.42185E-5, -0.00122474, -0.00214606, -0.00247576, -0.00214232, -0.00125124, -5.25709E-5, 0.00112891, 0.00198138, 0.00228804, 0.00198189, 0.00115959, 5.17346E-5, -0.00104151, -0.0018315, -0.00211705, -0.00183543, -0.00107542, -5.00248E-5, 9.62939E-4, 0.00169591, 0.00196204, 0.0017026, 9.99265E-4, 4.90929E-5, -8.90489E-4, -0.00157122, -0.00181943, -0.00158012, -9.286E-4, -4.73378E-5, 8.24896E-4, 0.00145757, 0.00168918, 0.00146823, 8.64236E-4, 4.63248E-5, -7.6389E-4, -0.00135223, -0.00156841, -0.00136427, -8.04023E-4, -4.45414E-5, 7.08383E-4, 0.00125568, 0.00145749, 0.00126878, 7.48914E-4, 4.34627E-5, -6.56409E-4, -0.00116563, -0.00135404, -0.00117953, -6.97032E-4, -4.16677E-5, 6.08957E-4, 0.00108277, 0.00125865, 0.00109724, 6.49387E-4, 4.05388E-5, -5.64291E-4, -0.00100513, -0.00116928, -0.00101998, -6.04316E-4, -3.87484E-5, 5.23422E-4, 9.33498E-4, 0.00108664, 9.48546E-4, 5.62831E-4, 3.75846E-5, -4.84799E-4, -8.66142E-4, -0.00100896, -8.81264E-4, -5.23446E-4, -3.58145E-5, 4.49413E-4, 8.03886E-4, 9.37001E-4, 8.18953E-4, 4.87145E-4, 3.46307E-5, -4.15874E-4, -7.45206E-4, -8.69204E-4, -7.60125E-4, -4.52592E-4, -3.28956E-5, 3.85131E-4, 6.90916E-4, 8.06337E-4, 7.05593E-4, 4.20726E-4, 3.17063E-5, -3.55932E-4, -6.39662E-4, -7.4702E-4, -6.54032E-4, -3.90343E-4, -3.00195E-5, 3.29171E-4, 5.92228E-4, 6.91995E-4, 6.06224E-4, 3.62321E-4, 2.88382E-5, -3.03721E-4, -5.47408E-4, -6.40038E-4, -5.60986E-4, -3.3558E-4, -2.72118E-5, 2.8041E-4, 5.05938E-4, 5.91851E-4, 5.19052E-4, 3.10927E-4, 2.60511E-5, -2.58228E-4, -4.66744E-4, -5.46342E-4, -4.79367E-4, -2.87395E-4, -2.44956E-5, 2.37931E-4, 4.30505E-4, 5.04165E-4, 4.42605E-4, 2.6572E-4, 2.33669E-5, -2.18617E-4, -3.96265E-4, -4.64347E-4, -4.07831E-4, -2.45036E-4, -2.18913E-5, 2.0097E-4, 3.64643E-4, 4.27484E-4, 3.75654E-4, 2.26009E-4, 2.08044E-5, -1.84185E-4, -3.34788E-4, -3.92714E-4, -3.45243E-4, -2.07868E-4, -1.94159E-5, 1.68876E-4, 3.07256E-4, 3.60571E-4, 3.17145E-4, 1.91205E-4, 1.83793E-5, -1.54329E-4, -2.81295E-4, -3.30291E-4, -2.90624E-4, -1.75339E-4, -1.70834E-5, 1.41088E-4, 2.57397E-4, 3.02348E-4, 2.66165E-4, 1.60793E-4, 1.61043E-5, -1.28523E-4, -2.34899E-4, -2.76071E-4, -2.43118E-4, -1.46966E-4, -1.49048E-5, 1.17113E-4, 2.14231E-4, 2.51871E-4, 2.21907E-4, 1.34316E-4, 1.39886E-5, -1.06305E-4, -1.94814E-4, -2.2916E-4, -2.01963E-4, -1.22318E-4, -1.28876E-5, 9.65146E-5, 1.77019E-4, 2.08294E-4, 1.83649E-4, 1.11366E-4, 1.20382E-5, -8.72626E-5, -1.60339E-4, -1.8876E-4, -1.66473E-4, -1.01006E-4, -1.10362E-5, 7.89036E-5, 1.45093E-4, 1.70858E-4, 1.50741E-4, 9.15727E-5, 1.02561E-5, -7.10254E-5, -1.30841E-4, -1.54145E-4, -1.36028E-4, -8.26751E-5, -9.35223E-6, 6.39282E-5, 1.17852E-4, 1.38873E-4, 1.22592E-4, 7.45961E-5, 8.64253E-6, -5.72597E-5, -1.05747E-4, -1.2466E-4, -1.10064E-4, -6.70014E-5, -7.83449E-6, 5.12711E-5, 9.47483E-5, 1.11712E-4, 9.86594E-5, 6.01259E-5, 7.19503E-6, -4.56638E-5, -8.45349E-5, -9.97043E-5, -8.80645E-5, -5.36869E-5, -6.47942E-6, 4.06451E-5, 7.52858E-5, 8.88031E-5, 7.84513E-5, 4.78765E-5, 5.90891E-6, -3.59646E-5, -6.67308E-5, -7.8733E-5, -6.95567E-5, -4.2458E-5, -5.28139E-6, 3.17904E-5, 5.90121E-5, 6.9625E-5, 6.15162E-5, 3.75857E-5, 4.77762E-6, -2.79153E-5, -5.19042E-5, -6.12486E-5, -5.41103E-5, -3.30639E-5, -4.23308E-6, 2.44729E-5, 4.55173E-5, 5.37039E-5, 4.74432E-5, 2.90137E-5, 3.79306E-6, -2.12939E-5, -3.96656E-5, -4.68005E-5, -4.13341E-5, -2.52756E-5, -3.3259E-6, 1.84821E-5, 3.44318E-5, 4.06118E-5, 3.58604E-5, 2.19423E-5, 2.94611E-6, -1.59015E-5, -2.96648E-5, -3.49824E-5, -3.08749E-5, -1.88856E-5, -2.55042E-6, 1.36306E-5, 2.54243E-5, 2.9964E-5, 2.64329E-5, 1.61743E-5, 2.22699E-6, -1.15618E-5, -2.15894E-5, -2.54315E-5, -2.24165E-5, -1.37074E-5, -1.89679E-6, 9.7523E-6, 1.82006E-5, 2.14186E-5, 1.88626E-5, 1.15337E-5, 1.62571E-6, -8.11918E-6, -1.51631E-5, -1.78266E-5, -1.56789E-5, -9.57529E-6, -1.35514E-6, 6.70203E-6, 1.25021E-5, 1.46748E-5, 1.28872E-5, 7.86481E-6, 1.13249E-6, -5.43858E-6, -1.0145E-5, -1.18872E-5, -1.0417E-5, -6.3441E-6, 0.0, 4.35427E-6, 8.10497E-6, 9.47191E-6, 8.2789E-6, 5.03271E-6, 0.0, -3.404E-6, -6.32794E-6, -7.37209E-6, -6.4205E-6, -3.88882E-6, 0.0, 2.60217E-6, 4.81816E-6, 5.58764E-6, 4.84388E-6, 2.92217E-6, 0.0, -1.91762E-6, -3.53696E-6, -4.07769E-6, -3.5118E-6, -2.10414E-6, 0.0, 1.35652E-6, 2.48227E-6, 2.83668E-6, 2.42062E-6, 1.43744E-6, 0.0, 0.0, -1.62776E-6, -1.83649E-6, -1.54513E-6, 0.0, 0.0, 0.0, 0.0, 1.06861E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "number_of_sets" value="1"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_full_bit_width" value="52"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_full_bits_right_of_binary_point" value="49"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "coefficient_reload_bit_width" value="23"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "logic_cell" value="1059"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "m512" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "m4k" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "m144k" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "m9k" value="13"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "m20k" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "mlab" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "megaram" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "dsp_block" value="8"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "input_clock_period" value="24"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_clock_period" value="120"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "throughput" value="120"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "memory_units" value="8"  type="INTEGER"  enable="1" />
// Retrieval info:     </NAMESPACE>
// Retrieval info:     <NAMESPACE name = "simgen_enable">
// Retrieval info:      <PRIVATE name = "matlab_enable" value="1"  type="BOOLEAN"  enable="1" />
// Retrieval info:      <PRIVATE name = "testbench_enable" value="1"  type="BOOLEAN"  enable="1" />
// Retrieval info:      <PRIVATE name = "testbench_simulation_clock_period" value="10.0"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "language" value="Verilog HDL"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "enabled" value="0"  type="BOOLEAN"  enable="1" />
// Retrieval info:     </NAMESPACE>
// Retrieval info:     <NAMESPACE name = "simgen">
// Retrieval info:      <PRIVATE name = "filename" value="fir5_wfm.vo"  type="STRING"  enable="1" />
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
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
// Copyright (C) 1991-2023 Altera Corporation
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
	input	[27:0]	coef_in;
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
// Retrieval info:      <PRIVATE name = "coefficient_scaling_factor" value="1.34217728E8"  type="STRING"  enable="0" />
// Retrieval info:      <PRIVATE name = "coefficient_bit_width" value="28"  type="INTEGER"  enable="0" />
// Retrieval info:      <PRIVATE name = "coefficient_binary_point_position" value="0"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "number_of_input_channels" value="2"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "input_number_system" value="Signed Binary"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "input_bit_width" value="28"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "input_binary_point_position" value="0"  type="INTEGER"  enable="0" />
// Retrieval info:      <PRIVATE name = "output_bit_width_method" value="Bit Width Only"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_number_system" value="Custom Resolution"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_bit_width" value="28"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_bits_right_of_binary_point" value="28"  type="INTEGER"  enable="0" />
// Retrieval info:      <PRIVATE name = "output_bits_removed_from_lsb" value="27"  type="INTEGER"  enable="1" />
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
// Retrieval info:      <PRIVATE name = "force_non_symmetric_structure" value="1"  type="BOOLEAN"  enable="1" />
// Retrieval info:      <PRIVATE name = "coefficients_reload" value="1"  type="BOOLEAN"  enable="1" />
// Retrieval info:      <PRIVATE name = "coefficients_reload_sgl_clock" value="1"  type="BOOLEAN"  enable="1" />
// Retrieval info:      <PRIVATE name = "max_clocks_to_compute" value="64"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "set_1" value="Low Pass Set, Floating, Low Pass, Blackman, 768, 960000.0, 44000.0, 3750000.0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.16801E-6, -1.48074E-6, -1.70618E-6, -1.79591E-6, -1.70839E-6, -1.41534E-6, 0.0, 0.0, 0.0, 1.64063E-6, 2.62165E-6, 3.51484E-6, 4.21363E-6, 4.61591E-6, 4.63552E-6, 4.21354E-6, 3.32799E-6, 2.00084E-6, 0.0, -1.65564E-6, -3.71494E-6, -5.69273E-6, -7.39106E-6, -8.61591E-6, -9.19665E-6, -9.00519E-6, -7.97292E-6, -6.10348E-6, -3.47985E-6, 0.0, 3.30889E-6, 6.94917E-6, 1.03312E-5, 1.31222E-5, 1.50125E-5, 1.57466E-5, 1.51513E-5, 1.31593E-5, 9.82449E-6, 5.32754E-6, 0.0, -5.84395E-6, -1.16342E-5, -1.68841E-5, -2.10834E-5, -2.3775E-5, -2.46008E-5, -2.33413E-5, -1.99461E-5, -1.45509E-5, -7.47931E-6, 0.0, 9.56642E-6, 1.81717E-5, 2.58208E-5, 3.17765E-5, 3.53988E-5, 3.6209E-5, 3.39426E-5, 2.85871E-5, 2.04004E-5, 9.90545E-6, -2.13827E-6, -1.47862E-5, -2.69801E-5, -3.76332E-5, -4.57245E-5, -5.03917E-5, -5.1017E-5, -4.72958E-5, -3.92828E-5, -2.74087E-5, -1.24652E-5, 4.44246E-6, 2.19735E-5, 3.86542E-5, 5.29985E-5, 6.36368E-5, 6.94408E-5, 6.96359E-5, 6.38877E-5, 5.23563E-5, 3.57089E-5, 1.50911E-5, -7.94688E-6, -3.15619E-5, -5.37614E-5, -7.25674E-5, -8.61881E-5, -9.31826E-5, -9.2603E-5, -8.41022E-5, -6.7995E-5, -4.52651E-5, -1.75143E-5, 1.31431E-5, 4.4237E-5, 7.31353E-5, 9.72623E-5, 1.14322E-4, 1.22511E-4, 1.20694E-4, 1.08538E-4, 8.65749E-5, 5.62023E-5, 1.96026E-5, -2.0406E-5, -6.05803E-5, -9.75099E-5, -1.27901E-4, -1.48864E-4, -1.58178E-4, -1.54513E-4, -1.37584E-4, -1.08224E-4, -6.83594E-5, -2.09016E-5, 3.04622E-5, 8.15473E-5, 1.28006E-4, 1.65691E-4, 1.91019E-4, 2.013E-4, 1.95004E-4, 1.71946E-4, 1.33354E-4, 8.18305E-5, 2.11872E-5, -4.38276E-5, -1.07893E-4, -1.65544E-4, -2.11629E-4, -2.41763E-4, -2.52732E-4, -2.42813E-4, -2.11981E-4, -1.61987E-4, -9.62733E-5, -1.97574E-5, 6.15295E-5, 1.40908E-4, 2.11593E-4, 2.67262E-4, 3.02612E-4, 3.1385E-4, 2.99074E-4, 2.58507E-4, 1.94564E-4, 1.11731E-4, 1.62658E-5, -8.42616E-5, -1.81562E-4, -2.673E-4, -3.338E-4, -3.74716E-4, -3.85625E-4, -3.64472E-4, -3.11833E-4, -2.30962E-4, -1.27624E-4, -9.69179E-6, 1.13436E-4, 2.31573E-4, 3.34581E-4, 4.13224E-4, 4.59985E-4, 4.69762E-4, 4.40387E-4, 3.72918E-4, 2.71661E-4, 1.43927E-4, 0.0, -1.49989E-4, -2.92207E-4, -4.14901E-4, -5.07055E-4, -5.59838E-4, -5.67425E-4, -5.27595E-4, -4.42043E-4, -3.16376E-4, -1.59771E-4, 1.56712E-5, 1.95847E-4, 3.65769E-4, 5.10799E-4, 6.17895E-4, 6.76761E-4, 6.80812E-4, 6.27851E-4, 5.20402E-4, 3.65659E-4, 1.75037E-4, -3.66518E-5, -2.52327E-4, -4.54004E-4, -6.24278E-4, -7.47807E-4, -8.12671E-4, -8.11489E-4, -7.42186E-4, -6.08346E-4, -4.19093E-4, -1.88504E-4, 6.54129E-5, 3.22102E-4, 5.60111E-4, 7.5886E-4, 9.00403E-4, 9.71018E-4, 9.625E-4, 8.73023E-4, 7.07499E-4, 4.77382E-4, 1.99914E-4, -1.03142E-4, -4.0718E-4, -6.86735E-4, -9.17586E-4, -0.00107883, -0.00115476, -0.00113631, -0.00102205, -8.18551E-4, -5.4007E-4, -2.07597E-4, 1.52693E-4, 5.11471E-4, 8.38621E-4, 0.00110574, 0.00128857, 0.00136916, 0.00133758, 0.00119299, 9.43989E-4, 6.08191E-4, 2.11037E-4, -2.16106E-4, -6.38388E-4, -0.00102029, -0.00132856, -0.00153512, -0.0016195, -0.00157086, -0.00138916, -0.00108548, -6.81494E-4, -2.07908E-4, 2.97777E-4, 7.94216E-4, 0.00123956, 0.00159493, 0.0018278, 0.00191485, 0.00184428, 0.00161708, 0.0012474, 7.61729E-4, 1.97107E-4, -4.01678E-4, -9.85579E-4, -0.00150526, -0.00191521, -0.00217767, -0.00226603, -0.0021674, -0.00188411, -0.00143401, -8.4946E-4, -1.75096E-4, 5.35528E-4, 0.00122411, 0.00183233, 0.00230671, 0.00260322, 0.00269129, 0.00255677, 0.00220363, 0.00165426, 9.48159E-4, 1.39216E-4, -7.08303E-4, -0.00152478, -0.00224087, -0.00279328, -0.00313026, -0.0032163, -0.00303562, -0.00259416, -0.00191984, -0.00106098, -8.29592E-5, 9.36594E-4, 0.00191386, 0.00276558, 0.00341598, 0.00380337, 0.00388573, 0.00364497, 0.00308924, 0.00225326, 0.00119641, -1.31922E-6, -0.00124512, -0.00243274, -0.00346261, -0.00424235, -0.00469673, -0.0047746, -0.00445407, -0.0037455, -0.00269196, -0.00136697, 1.30241E-4, 0.00168191, 0.00316062, 0.00443943, 0.00540232, 0.00595425, 0.0060299, 0.00560037, 0.00467729, 0.0033137, 0.00160169, -3.33236E-4, -0.00234082, -0.00425703, -0.00591679, -0.00716732, -0.00788121, -0.00796812, -0.00738409, -0.00613771, -0.00429237, -0.00196438, 6.83229E-4, 0.00345088, 0.00611608, 0.0084496, 0.0102331, 0.011277, 0.0114372, 0.0106296, 0.00884058, 0.00613351, 0.00264956, -0.00139671, -0.0057274, -0.0100163, -0.0139081, -0.0170406, -0.0190688, -0.0196885, -0.018659, -0.0158222, -0.0111174, -0.00459021, 0.00360466, 0.0132077, 0.0238657, 0.0351485, 0.0465716, 0.0576225, 0.0677891, 0.076589, 0.0835972, 0.0884709, 0.0909696, 0.0909696, 0.0884709, 0.0835972, 0.076589, 0.0677891, 0.0576225, 0.0465716, 0.0351485, 0.0238657, 0.0132077, 0.00360466, -0.00459021, -0.0111174, -0.0158222, -0.018659, -0.0196885, -0.0190688, -0.0170406, -0.0139081, -0.0100163, -0.0057274, -0.00139671, 0.00264956, 0.00613351, 0.00884058, 0.0106296, 0.0114372, 0.011277, 0.0102331, 0.0084496, 0.00611608, 0.00345088, 6.83229E-4, -0.00196438, -0.00429237, -0.00613771, -0.00738409, -0.00796812, -0.00788121, -0.00716732, -0.00591679, -0.00425703, -0.00234082, -3.33236E-4, 0.00160169, 0.0033137, 0.00467729, 0.00560037, 0.0060299, 0.00595425, 0.00540232, 0.00443943, 0.00316062, 0.00168191, 1.30241E-4, -0.00136697, -0.00269196, -0.0037455, -0.00445407, -0.0047746, -0.00469673, -0.00424235, -0.00346261, -0.00243274, -0.00124512, -1.31922E-6, 0.00119641, 0.00225326, 0.00308924, 0.00364497, 0.00388573, 0.00380337, 0.00341598, 0.00276558, 0.00191386, 9.36594E-4, -8.29592E-5, -0.00106098, -0.00191984, -0.00259416, -0.00303562, -0.0032163, -0.00313026, -0.00279328, -0.00224087, -0.00152478, -7.08303E-4, 1.39216E-4, 9.48159E-4, 0.00165426, 0.00220363, 0.00255677, 0.00269129, 0.00260322, 0.00230671, 0.00183233, 0.00122411, 5.35528E-4, -1.75096E-4, -8.4946E-4, -0.00143401, -0.00188411, -0.0021674, -0.00226603, -0.00217767, -0.00191521, -0.00150526, -9.85579E-4, -4.01678E-4, 1.97107E-4, 7.61729E-4, 0.0012474, 0.00161708, 0.00184428, 0.00191485, 0.0018278, 0.00159493, 0.00123956, 7.94216E-4, 2.97777E-4, -2.07908E-4, -6.81494E-4, -0.00108548, -0.00138916, -0.00157086, -0.0016195, -0.00153512, -0.00132856, -0.00102029, -6.38388E-4, -2.16106E-4, 2.11037E-4, 6.08191E-4, 9.43989E-4, 0.00119299, 0.00133758, 0.00136916, 0.00128857, 0.00110574, 8.38621E-4, 5.11471E-4, 1.52693E-4, -2.07597E-4, -5.4007E-4, -8.18551E-4, -0.00102205, -0.00113631, -0.00115476, -0.00107883, -9.17586E-4, -6.86735E-4, -4.0718E-4, -1.03142E-4, 1.99914E-4, 4.77382E-4, 7.07499E-4, 8.73023E-4, 9.625E-4, 9.71018E-4, 9.00403E-4, 7.5886E-4, 5.60111E-4, 3.22102E-4, 6.54129E-5, -1.88504E-4, -4.19093E-4, -6.08346E-4, -7.42186E-4, -8.11489E-4, -8.12671E-4, -7.47807E-4, -6.24278E-4, -4.54004E-4, -2.52327E-4, -3.66518E-5, 1.75037E-4, 3.65659E-4, 5.20402E-4, 6.27851E-4, 6.80812E-4, 6.76761E-4, 6.17895E-4, 5.10799E-4, 3.65769E-4, 1.95847E-4, 1.56712E-5, -1.59771E-4, -3.16376E-4, -4.42043E-4, -5.27595E-4, -5.67425E-4, -5.59838E-4, -5.07055E-4, -4.14901E-4, -2.92207E-4, -1.49989E-4, 0.0, 1.43927E-4, 2.71661E-4, 3.72918E-4, 4.40387E-4, 4.69762E-4, 4.59985E-4, 4.13224E-4, 3.34581E-4, 2.31573E-4, 1.13436E-4, -9.69179E-6, -1.27624E-4, -2.30962E-4, -3.11833E-4, -3.64472E-4, -3.85625E-4, -3.74716E-4, -3.338E-4, -2.673E-4, -1.81562E-4, -8.42616E-5, 1.62658E-5, 1.11731E-4, 1.94564E-4, 2.58507E-4, 2.99074E-4, 3.1385E-4, 3.02612E-4, 2.67262E-4, 2.11593E-4, 1.40908E-4, 6.15295E-5, -1.97574E-5, -9.62733E-5, -1.61987E-4, -2.11981E-4, -2.42813E-4, -2.52732E-4, -2.41763E-4, -2.11629E-4, -1.65544E-4, -1.07893E-4, -4.38276E-5, 2.11872E-5, 8.18305E-5, 1.33354E-4, 1.71946E-4, 1.95004E-4, 2.013E-4, 1.91019E-4, 1.65691E-4, 1.28006E-4, 8.15473E-5, 3.04622E-5, -2.09016E-5, -6.83594E-5, -1.08224E-4, -1.37584E-4, -1.54513E-4, -1.58178E-4, -1.48864E-4, -1.27901E-4, -9.75099E-5, -6.05803E-5, -2.0406E-5, 1.96026E-5, 5.62023E-5, 8.65749E-5, 1.08538E-4, 1.20694E-4, 1.22511E-4, 1.14322E-4, 9.72623E-5, 7.31353E-5, 4.4237E-5, 1.31431E-5, -1.75143E-5, -4.52651E-5, -6.7995E-5, -8.41022E-5, -9.2603E-5, -9.31826E-5, -8.61881E-5, -7.25674E-5, -5.37614E-5, -3.15619E-5, -7.94688E-6, 1.50911E-5, 3.57089E-5, 5.23563E-5, 6.38877E-5, 6.96359E-5, 6.94408E-5, 6.36368E-5, 5.29985E-5, 3.86542E-5, 2.19735E-5, 4.44246E-6, -1.24652E-5, -2.74087E-5, -3.92828E-5, -4.72958E-5, -5.1017E-5, -5.03917E-5, -4.57245E-5, -3.76332E-5, -2.69801E-5, -1.47862E-5, -2.13827E-6, 9.90545E-6, 2.04004E-5, 2.85871E-5, 3.39426E-5, 3.6209E-5, 3.53988E-5, 3.17765E-5, 2.58208E-5, 1.81717E-5, 9.56642E-6, 0.0, -7.47931E-6, -1.45509E-5, -1.99461E-5, -2.33413E-5, -2.46008E-5, -2.3775E-5, -2.10834E-5, -1.68841E-5, -1.16342E-5, -5.84395E-6, 0.0, 5.32754E-6, 9.82449E-6, 1.31593E-5, 1.51513E-5, 1.57466E-5, 1.50125E-5, 1.31222E-5, 1.03312E-5, 6.94917E-6, 3.30889E-6, 0.0, -3.47985E-6, -6.10348E-6, -7.97292E-6, -9.00519E-6, -9.19665E-6, -8.61591E-6, -7.39106E-6, -5.69273E-6, -3.71494E-6, -1.65564E-6, 0.0, 2.00084E-6, 3.32799E-6, 4.21354E-6, 4.63552E-6, 4.61591E-6, 4.21363E-6, 3.51484E-6, 2.62165E-6, 1.64063E-6, 0.0, 0.0, 0.0, -1.41534E-6, -1.70839E-6, -1.79591E-6, -1.70618E-6, -1.48074E-6, -1.16801E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0"  type="STRING"  enable="1" />
// Retrieval info:      <PRIVATE name = "number_of_sets" value="1"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_full_bit_width" value="66"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "output_full_bits_right_of_binary_point" value="54"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "coefficient_reload_bit_width" value="28"  type="INTEGER"  enable="1" />
// Retrieval info:      <PRIVATE name = "logic_cell" value="904"  type="INTEGER"  enable="1" />
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
// Retrieval info:      <PRIVATE name = "memory_units" value="2"  type="INTEGER"  enable="1" />
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

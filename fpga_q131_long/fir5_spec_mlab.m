%                                                                                                          
%THIS IS A WIZARD GENERATED FILE. DO NOT EDIT THIS FILE!                                                   
%                                                                                                          
%--------------------------------------------------------------------------------------------------------- 
%This Model Only Support Single Channel Input Data. 
%Please input:                                      
%data vector: 		stimulation(1:n)                
%FILTER PARAMETER  
%Input Data Width: 28
%Decimation Factor: 5
%MSB Truncated Bits:
%MSB Satuated Bits :
%LSB Truncated bits:
%LSB Rounded bits  :
%FIR Width (Full Calculation Width Before Output Width Adjust) :32 
%-----------------------------------------------------------------------------------------------------------
%MegaWizard Scaled Coefficient Values
 function  output = fir5_spec_mlab(stimulation, output);
 coef_matrix=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,18,24,23,0,0,-21,-35,-37,-27,0,21,44,54,46,21,0,-50,-72,-70,-44,0,50,87,97,75,24,-40,-96,-124,-112,-60,18,96,147,152,105,18,-82,-162,-192,-159,-68,53,165,228,218,132,0,-149,-252,-276,-207,-63,112,261,329,290,150,-50,-246,-369,-374,-252,-37,203,387,451,365,150,-127,-377,-512,-481,-285,19,331,549,591,435,125,-244,-549,-683,-592,-297,114,506,746,745,493,62,-410,-765,-878,-700,-277,259,731,979,907,526,-49,-633,-1029,-1094,-794,-213,465,1015,1246,1067,522,-222,-922,-1340,-1324,-861,-89,744,1360,1543,1214,464,-472,-1285,-1698,-1555,-884,111,1106,1768,1860,1331,335,-811,-1727,-2096,-1774,-844,404,1561,2237,2186,1399,114,-1254,-2250,-2526,-1963,-721,807,2117,2762,2503,1395,-218,-1814,-2855,-2973,-2098,-489,1338,2777,3334,2791,1294,-685,-2499,-3535,-3419,-2153,-124,2012,3543,3936,3022,1067,-1307,-3318,-4280,-3839,-2097,402,2844,4410,4547,3166,683,-2105,-4272,-5075,-4202,-1896,1115,3843,5367,5140,3187,109,-3096,-5359,-5895,-4473,-1512,2041,5015,6398,5681,3043,-689,-4296,-6569,-6709,-4609,-907,3204,6360,7478,6127,2690,-1742,-5714,-7886,-7480,-4562,-38,4624,7869,8572,6430,2081,-3082,-7354,-9283,-8161,-4281,1135,6318,9528,9641,6536,1165,-4737,-9212,-10727,-8697,-3707,2653,8294,11313,10631,6382,-110,-6732,-11277,-12172,-9024,-2780,4554,10557,13188,11483,5900,-1795,-9086,-13528,-13565,-9072,-1435,6875,13101,15110,12125,5018,-3943,-11812,-15934,-14839,-8761,395,9649,15913,17022,12477,3654,-6608,-14918,-18453,-15916,-8002,2781,12904,18971,18856,12445,1722,-9840,-18403,-21034,-16708,-6697,5798,16668,22243,20532,11927,-872,-13695,-22263,-23611,-17110,-4735,9527,20965,25689,21956,10802,-4234,-18230,-26488,-26109,-17003,-1992,14060,25822,29260,23016,8932,-8488,-23512,-31066,-28437,-16246,1682,19506,31273,32899,23582,6152,-13782,-29627,-35987,-30491,-14668,6470,26003,37364,36545,23497,2253,-20309,-36689,-41249,-32147,-12055,12614,33742,44175,40131,22561,-3038,-28337,-44872,-46870,-33251,-8122,20448,43006,51836,43586,20512,-10108,-38258,-54451,-52908,-33608,-2462,30473,54234,60581,46841,16973,-19543,-50699,-65886,-59494,-32943,5551,43499,68168,70833,49828,11355,-32313,-66725,-80000,-66902,-30833,16980,60944,86152,83397,52480,2636,-50173,-88326,-98374,-75717,-26532,33828,85563,110857,99940,54739,-11207,-76714,-119671,-124405,-87267,-18495,60463,123512,148396,124384,56553,-34935,-120641,-171114,-166757,-105077,-2732,108634,191847,216211,168294,57880,-83243,-209868,-277133,-255458,-141966,35628,224595,361406,391040,285912,58689,-235482,-508982,-662225,-609768,-305183,242186,963703,1742868,2439508,2921031,3092930,2921031,2439508,1742868,963703,242186,-305183,-609768,-662225,-508982,-235482,58689,285912,391040,361406,224595,35628,-141966,-255458,-277133,-209868,-83243,57880,168294,216211,191847,108634,-2732,-105077,-166757,-171114,-120641,-34935,56553,124384,148396,123512,60463,-18495,-87267,-124405,-119671,-76714,-11207,54739,99940,110857,85563,33828,-26532,-75717,-98374,-88326,-50173,2636,52480,83397,86152,60944,16980,-30833,-66902,-80000,-66725,-32313,11355,49828,70833,68168,43499,5551,-32943,-59494,-65886,-50699,-19543,16973,46841,60581,54234,30473,-2462,-33608,-52908,-54451,-38258,-10108,20512,43586,51836,43006,20448,-8122,-33251,-46870,-44872,-28337,-3038,22561,40131,44175,33742,12614,-12055,-32147,-41249,-36689,-20309,2253,23497,36545,37364,26003,6470,-14668,-30491,-35987,-29627,-13782,6152,23582,32899,31273,19506,1682,-16246,-28437,-31066,-23512,-8488,8932,23016,29260,25822,14060,-1992,-17003,-26109,-26488,-18230,-4234,10802,21956,25689,20965,9527,-4735,-17110,-23611,-22263,-13695,-872,11927,20532,22243,16668,5798,-6697,-16708,-21034,-18403,-9840,1722,12445,18856,18971,12904,2781,-8002,-15916,-18453,-14918,-6608,3654,12477,17022,15913,9649,395,-8761,-14839,-15934,-11812,-3943,5018,12125,15110,13101,6875,-1435,-9072,-13565,-13528,-9086,-1795,5900,11483,13188,10557,4554,-2780,-9024,-12172,-11277,-6732,-110,6382,10631,11313,8294,2653,-3707,-8697,-10727,-9212,-4737,1165,6536,9641,9528,6318,1135,-4281,-8161,-9283,-7354,-3082,2081,6430,8572,7869,4624,-38,-4562,-7480,-7886,-5714,-1742,2690,6127,7478,6360,3204,-907,-4609,-6709,-6569,-4296,-689,3043,5681,6398,5015,2041,-1512,-4473,-5895,-5359,-3096,109,3187,5140,5367,3843,1115,-1896,-4202,-5075,-4272,-2105,683,3166,4547,4410,2844,402,-2097,-3839,-4280,-3318,-1307,1067,3022,3936,3543,2012,-124,-2153,-3419,-3535,-2499,-685,1294,2791,3334,2777,1338,-489,-2098,-2973,-2855,-1814,-218,1395,2503,2762,2117,807,-721,-1963,-2526,-2250,-1254,114,1399,2186,2237,1561,404,-844,-1774,-2096,-1727,-811,335,1331,1860,1768,1106,111,-884,-1555,-1698,-1285,-472,464,1214,1543,1360,744,-89,-861,-1324,-1340,-922,-222,522,1067,1246,1015,465,-213,-794,-1094,-1029,-633,-49,526,907,979,731,259,-277,-700,-878,-765,-410,62,493,745,746,506,114,-297,-592,-683,-549,-244,125,435,591,549,331,19,-285,-481,-512,-377,-127,150,365,451,387,203,-37,-252,-374,-369,-246,-50,150,290,329,261,112,-63,-207,-276,-252,-149,0,132,218,228,165,53,-68,-159,-192,-162,-82,18,105,152,147,96,18,-60,-112,-124,-96,-40,24,75,97,87,50,0,-44,-70,-72,-50,0,21,46,54,44,21,0,-27,-37,-35,-21,0,0,23,24,18,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
 INTER_FACTOR  = 1;         
 DECI_FACTOR  =  5;
 MSB_RM  = 2;
 MSB_TYPE  = 0;
 LSB_RM  = 20;
 LSB_TYPE  = 0;
 FIR_WIDTH  = 32 + MSB_RM + LSB_RM;
 OUT_WIDTH  = 32 ;  %32
  DATA_WIDTH = 28;
 data_type = 1;

 % check size of inputs. 
 [DX,DY] = size(stimulation);
 [CX,CY] = size(coef_matrix); 
 if (CX ~= DY * INTER_FACTOR) 
    fprintf('WARNING : coef_matrix size and input data size is not match\n'); 
 end 
   
 %fill coef_matrix to length of data with the latest coef set 
 if (CX < DY * INTER_FACTOR) 
   for i= CX +1:DY * INTER_FACTOR 
     coef_matrix(i,:) = coef_matrix(CX,:); 
   end 
 end
  
        %check if input is integer 
       	int_sti=round(stimulation); 
	    T = (int_sti ~= stimulation); 
	    if (max(T)~=0) 
	        fprintf('WARNING : Integer Input Expected: Rounding Fractional Input to Nearest Integer...\n'); 
	    end 
	     
	    %Input overflow check 
	    switch  data_type 
	    case 1 
	        %set max/min for signed 
	        maxdat = 2^(DATA_WIDTH-1)-1; 
	        mindat = -maxdat-1; 
	    case 2 
	        %set max/min for unsigned 
	        maxdat = 2^DATA_WIDTH-1; 
	        mindat = 0; 
	    end 

	    if(data_type == 2)
	    	if(abs(coef_matrix) == coef_matrix)
	    		FIR_WIDTH = FIR_WIDTH +1;
	    	end
	    end

	    %Saturating Input Value 
	    a=find(int_sti>maxdat); 
	    b=find(int_sti<mindat); 
	    if (~isempty(a)|~isempty(b)) 
	 	    fprintf('WARNING : Input Amplitude Exceeds MAXIMUM/MINIMUM allowable values - saturating input values...\n'); 
	            lena = length (a); 
	            lenb = length (b); 
	            for i =1:lena 
	        	    fprintf('%d > %d \n', int_sti(a(i)), maxdat); 
			        int_sti(a(i)) = maxdat; 
		        end 
		    for i =1:lenb 
			    fprintf('%d < %d \n', int_sti(b(i)), mindat); 
			    int_sti(b(i)) = mindat; 
		    end 
	    end 
         
	    % Add interpolation 
   	    inter_sti = zeros(1, INTER_FACTOR * length(int_sti)); 
	    inter_sti(1:INTER_FACTOR:INTER_FACTOR * length(int_sti)) = int_sti; 
 
         
        for i = 1 : DY *INTER_FACTOR 
    	    coef_current = coef_matrix(i,:); 
            output_temp(i) = simp_adaptive (inter_sti, coef_current, i); 
        end 
	% Truncate output 
	len1 = length(output_temp); 
	 
	    switch  LSB_TYPE 
	    case 0 
	        %truncate 
            out_dec = bi_trunc_lsb(output_temp,LSB_RM,FIR_WIDTH); 
	    case 1 
	        %round 
            out_dec = bi_round(output_temp,LSB_RM, FIR_WIDTH); 
	    end 
         
 	    switch  MSB_TYPE 
	    case 0 
	        %truncate 
            out_dec = bi_trunc_msb(out_dec,MSB_RM,FIR_WIDTH-LSB_RM); 
	    case 1 
	        %round 
            out_dec = bi_satu(out_dec,MSB_RM, FIR_WIDTH-LSB_RM); 
	    end 
 	    
    	% choose decimation output in phase=DECI_FACTOR-1  
     	if(DECI_FACTOR == 1) 
     		output = out_dec; 
     	else
     		output = out_dec;%(DECI_FACTOR:DECI_FACTOR:len1);
 	end  
 	       
  	function[output, outindex] = simp_adaptive (int_sti, coef_current, data_index, output) 
	%Simulation is the whole input sequence 
	%coef_current is the current coefficient set 
	%data_index gives the last data to use 
	%outputs are the sum of input and coef multiplication 
	%outindex is the next data_index 
    
	sti_current = zeros(length(coef_current),1); 
	 
	data_length = length(int_sti); 
	 
	%Check data index 
	if (data_index > data_length) 
		fprintf('ERROR: DATA INDEX IS LARGER THAN DATA LENGTH!!!\n'); 
		return; 
	end 
	for i = 1: length(coef_current) 
	   if ((data_index -i+1)>0 & (data_index - i+1)<=data_length) 
	      sti_current(i,1) = int_sti(data_index - i+1); 
	   end 
	end 
	 
	outindex= data_index+1; 
	output = coef_current * sti_current; 
	% end of function simp_adaptive 
 
	function output = bi_round(data_in,LSB_RM,ORI_WIDTH, output) 
	% LSB_RM is the bit to lose in LSB 
	% ORI_WIDTH is the original data width
	data = round (data_in / 2^LSB_RM);       
	output = bi_satu(data,0,ORI_WIDTH - LSB_RM); 
	%end of function bi_trunc_lsb 
	 
	function output = bi_trunc_lsb(data_in,LSB_RM,ORI_WIDTH, output) 
	% LSB_RM is the bit to lose in LSB 
	% ORI_WIDTH is the original data width 
	%2's complement system 
	output = bitshift(2^ORI_WIDTH*(data_in<0) + data_in, -LSB_RM) - 2^(ORI_WIDTH-LSB_RM) *(data_in<0); 
	% end of function bi_round 
	 
	function output = bi_trunc_msb(data_in,MSB_RM,ORI_WIDTH, output) 
	% MSB_RM is the bit to lose in LSB 
	% ORI_WIDTH is the original data width 
	%2's complement system 
	data = 2^ORI_WIDTH * (data_in < 0)+ data_in; 
	erase_num = 2^(ORI_WIDTH - MSB_RM) - 1; 
	data = bitand(data, erase_num); 
	output = data - 2^(ORI_WIDTH - MSB_RM)*(bitget(data,ORI_WIDTH - MSB_RM)); 
	%end of bi_trunc_msb 
	 
	function output = bi_satu(data_in,MSB_RM,ORI_WIDTH, output) 
	% MSB_RM is the bit to lose in LSB 
	% ORI_WIDTH is the original data width 
	%2's complement system 
	maxdat = 2^(ORI_WIDTH - MSB_RM - 1)-1; 
	mindat = 2^(ORI_WIDTH - MSB_RM - 1)*(-1); 
	data_in(find(data_in > maxdat)) = maxdat; 
	data_in(find(data_in < mindat)) = mindat; 
	output = data_in; 
	%end of bi_satu  
         

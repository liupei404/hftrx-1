%                                                                                                          
%THIS IS A WIZARD GENERATED FILE. DO NOT EDIT THIS FILE!                                                   
%                                                                                                          
%--------------------------------------------------------------------------------------------------------- 
%This Model Only Support Single Channel Input Data. 
%Please input:                                      
%data vector: 		stimulation(1:n)                
%FILTER PARAMETER  
%Input Data Width: 28
%Decimation Factor: 20
%MSB Truncated Bits:
%MSB Satuated Bits :
%LSB Truncated bits:
%LSB Rounded bits  :
%FIR Width (Full Calculation Width Before Output Width Adjust) :28 
%-----------------------------------------------------------------------------------------------------------
%MegaWizard Scaled Coefficient Values
 function  output = fir_20a_rx_2ch_mlab(stimulation, output);
 coef_matrix=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,20,26,32,39,45,51,58,63,68,73,76,79,80,80,78,75,70,64,56,45,34,20,0,0,-29,-47,-67,-87,-107,-127,-146,-165,-182,-197,-211,-222,-230,-236,-238,-236,-230,-221,-207,-189,-167,-140,-110,-77,-40,0,43,87,133,179,225,271,315,356,395,430,460,485,504,516,521,519,508,490,463,427,383,332,272,206,133,55,-28,-115,-204,-294,-385,-474,-560,-642,-718,-787,-847,-898,-938,-965,-980,-980,-967,-938,-894,-835,-761,-673,-571,-457,-331,-194,-49,103,259,418,578,736,889,1036,1173,1299,1411,1506,1584,1641,1676,1689,1677,1641,1579,1491,1379,1243,1083,901,700,481,246,0,-255,-517,-780,-1041,-1297,-1543,-1775,-1990,-2184,-2353,-2494,-2604,-2680,-2720,-2722,-2684,-2607,-2489,-2331,-2134,-1899,-1630,-1327,-995,-638,-260,135,540,952,1363,1768,2160,2535,2885,3204,3488,3731,3928,4075,4167,4203,4180,4095,3950,3743,3475,3150,2769,2337,1858,1338,783,199,-404,-1021,-1641,-2256,-2858,-3436,-3982,-4488,-4944,-5343,-5677,-5939,-6124,-6227,-6243,-6171,-6009,-5755,-5412,-4982,-4468,-3876,-3211,-2482,-1697,-865,0,895,1799,2703,3594,4457,5282,6053,6760,7389,7931,8374,8709,8930,9029,9003,8847,8561,8145,7602,6936,6153,5262,4272,3194,2043,833,-422,-1704,-2995,-4277,-5532,-6741,-7886,-8948,-9911,-10757,-11472,-12043,-12457,-12704,-12777,-12670,-12380,-11907,-11252,-10420,-9419,-8259,-6951,-5512,-3957,-2307,-583,1194,2998,4805,6590,8325,9987,11548,12984,14271,15389,16315,17033,17528,17785,17797,17557,17061,16311,15310,14068,12595,10907,9022,6963,4754,2423,0,-2483,-4992,-7492,-9948,-12324,-14583,-16691,-18615,-20322,-21783,-22971,-23863,-24439,-24682,-24582,-24130,-23325,-22169,-20671,-18841,-16699,-14267,-11572,-8646,-5524,-2245,1147,4609,8092,11548,14928,18182,21260,24115,26701,28974,30894,32426,33537,34202,34399,34114,33338,32069,30313,28082,25394,22276,18760,14886,10698,6247,1589,-3217,-8106,-13012,-17866,-22600,-27142,-31424,-35378,-38941,-42050,-44651,-46691,-48127,-48921,-49043,-48474,-47201,-45221,-42541,-39179,-35162,-30525,-25316,-19590,-13411,-6852,0,7081,14277,21498,28645,35615,42306,48617,54445,59695,64274,68096,71082,73161,74273,74368,73408,71369,68239,64021,58732,52404,45084,36833,27728,17859,7329,-3744,-15233,-26999,-38894,-50763,-62445,-73773,-84577,-94689,-103939,-112160,-119193,-124883,-129083,-131658,-132487,-131458,-128480,-123475,-116384,-107168,-95808,-82304,-66678,-48975,-29259,-7616,15847,41003,67707,95794,125084,155382,186479,218152,250175,282309,314308,345929,376927,407056,436075,463752,489863,514191,536540,556722,574568,589931,602681,612712,619938,624297,625755,624297,619938,612712,602681,589931,574568,556722,536540,514191,489863,463752,436075,407056,376927,345929,314308,282309,250175,218152,186479,155382,125084,95794,67707,41003,15847,-7616,-29259,-48975,-66678,-82304,-95808,-107168,-116384,-123475,-128480,-131458,-132487,-131658,-129083,-124883,-119193,-112160,-103939,-94689,-84577,-73773,-62445,-50763,-38894,-26999,-15233,-3744,7329,17859,27728,36833,45084,52404,58732,64021,68239,71369,73408,74368,74273,73161,71082,68096,64274,59695,54445,48617,42306,35615,28645,21498,14277,7081,0,-6852,-13411,-19590,-25316,-30525,-35162,-39179,-42541,-45221,-47201,-48474,-49043,-48921,-48127,-46691,-44651,-42050,-38941,-35378,-31424,-27142,-22600,-17866,-13012,-8106,-3217,1589,6247,10698,14886,18760,22276,25394,28082,30313,32069,33338,34114,34399,34202,33537,32426,30894,28974,26701,24115,21260,18182,14928,11548,8092,4609,1147,-2245,-5524,-8646,-11572,-14267,-16699,-18841,-20671,-22169,-23325,-24130,-24582,-24682,-24439,-23863,-22971,-21783,-20322,-18615,-16691,-14583,-12324,-9948,-7492,-4992,-2483,0,2423,4754,6963,9022,10907,12595,14068,15310,16311,17061,17557,17797,17785,17528,17033,16315,15389,14271,12984,11548,9987,8325,6590,4805,2998,1194,-583,-2307,-3957,-5512,-6951,-8259,-9419,-10420,-11252,-11907,-12380,-12670,-12777,-12704,-12457,-12043,-11472,-10757,-9911,-8948,-7886,-6741,-5532,-4277,-2995,-1704,-422,833,2043,3194,4272,5262,6153,6936,7602,8145,8561,8847,9003,9029,8930,8709,8374,7931,7389,6760,6053,5282,4457,3594,2703,1799,895,0,-865,-1697,-2482,-3211,-3876,-4468,-4982,-5412,-5755,-6009,-6171,-6243,-6227,-6124,-5939,-5677,-5343,-4944,-4488,-3982,-3436,-2858,-2256,-1641,-1021,-404,199,783,1338,1858,2337,2769,3150,3475,3743,3950,4095,4180,4203,4167,4075,3928,3731,3488,3204,2885,2535,2160,1768,1363,952,540,135,-260,-638,-995,-1327,-1630,-1899,-2134,-2331,-2489,-2607,-2684,-2722,-2720,-2680,-2604,-2494,-2353,-2184,-1990,-1775,-1543,-1297,-1041,-780,-517,-255,0,246,481,700,901,1083,1243,1379,1491,1579,1641,1677,1689,1676,1641,1584,1506,1411,1299,1173,1036,889,736,578,418,259,103,-49,-194,-331,-457,-571,-673,-761,-835,-894,-938,-967,-980,-980,-965,-938,-898,-847,-787,-718,-642,-560,-474,-385,-294,-204,-115,-28,55,133,206,272,332,383,427,463,490,508,519,521,516,504,485,460,430,395,356,315,271,225,179,133,87,43,0,-40,-77,-110,-140,-167,-189,-207,-221,-230,-236,-238,-236,-230,-222,-211,-197,-182,-165,-146,-127,-107,-87,-67,-47,-29,0,0,20,34,45,56,64,70,75,78,80,80,79,76,73,68,63,58,51,45,39,32,26,20,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
 INTER_FACTOR  = 1;         
 DECI_FACTOR  =  20;
 MSB_RM  = 1;
 MSB_TYPE  = 0;
 LSB_RM  = 24;
 LSB_TYPE  = 0;
 FIR_WIDTH  = 28 + MSB_RM + LSB_RM;
 OUT_WIDTH  = 28 ;  %28
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
         

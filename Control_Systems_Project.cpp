
// Beware: Lines marked compulsory1-20 must be there for this simulation software 
// to function properly !!  
// The user can change the other lines according to his/her simulation and must 
// then save the file under its own name. 

/*****************************************************************************/
/**********                     Basic simulation                    **********/
/*****************************************************************************/

#pragma hdrstop								        							// compulsory1
#include "SIMPROTO_2017.H"                                                      // compulsory2
#include "SIMINCDF_2017.H"                                                      // compulsory3
#include "SIMULDCL_2017.H"                                                      // compulsory4
#include "Graphics.h"                                                           // compulsory5

/*****************************************************************************/
/**********             PARAMETERS, CONSTANTS & VARIABLES           **********/
/*****************************************************************************/

const double SF	        =	1.13035;  	
		
const double Ngear	    =	SF*15.0;

const double Rm         =	12.0;  	        	    // ohms

const double Lm		    = 	0.005;   				// Henries

const double Km	        =	0.1;					//	Nm/A

const double Jm         =  1.0e-5; 					// kg.m^2

const double Jp	       	=  	1.0e-4; 				// kg.m^2

const double Jc		    =	1.0e-2;					// kg.m^2

const double Kfrm       =	0.0001;					// Nm/(rad/s)

const double Kfrc       =	0.0005;					// Nm/(rad/s)

const double Kfrp 		=	0.0002;					//Nm/9rad/s)

const double Kshaft		=	SF*2.5;					// Nm/rad/s

const double ZG			=	0.7;

const double WG	  		=	2.0*PI*500.0;

const double Jb			=	Jp-(Jc/Ngear);

const double Jpc		=	Jp+(Jc/(Ngear*Ngear));

const double Kfrpc 		=	Kfrp+(Kfrc/(Ngear*Ngear));

const double p 			=	1.0/(2.0*PI*20.0);

const double Kstab		=	4500.0;

const double Te			=	1.0/(2.0*PI*10.0);

const double Tf			=	1.0/(2.0*PI*4.0);

const double Ktrk		=	80.0;

const double Znt 		=	0.065;

const double Znb 		=	0.35;

const double Wn 		=	2.0*PI*85.0;


const double fsamp		=	1000.0;         //Hertz

const double Tsamp		=	(1.0/fsamp);    //s

const double A			=	1.0+((2.0*p)/Tsamp);

const double B 			=	1.0-((2.0*p)/Tsamp);

const double C 			=	(2.0/Tsamp);

const double D 			=	((-2.0)/Tsamp);

const double M 			=	(4.0/(Tsamp*Tsamp))+((4.0*Znb*Wn)/Tsamp)+(Wn*Wn);

const double N 			=	(4.0/(Tsamp*Tsamp))+((4.0*Znb*Wn)/Tsamp)+(Wn*Wn);

const double E 			=	(-8.0/(Tsamp*Tsamp))+(2.0*Wn*Wn);

const double F 			=	(4.0/(Tsamp*Tsamp))-((4.0*Znt*Wn)/Tsamp)+(Wn*Wn);

const double G 			=	(-8.0/(Tsamp*Tsamp))+(2.0*Wn*Wn);

const double H 			=	(4.0/(Tsamp*Tsamp))-((4.0*Znt*Wn)/Tsamp)+(Wn*Wn);


/*****************************************************************************/
/**********                     MAIN PROGRAM                        **********/
/*****************************************************************************/

#pragma argsused  // pragma suppresses "calling argument not used" warnings		// compulsory6
BOOL WINAPI DllEntryPoint(						        						// compulsory7
HINSTANCE hinst, DWORD reason, LPVOID reserved)				        			// compulsory8
{									        									// compulsory9
return TRUE;								        							// compulsory10
}									        									// compulsory11
__declspec(dllexport)							        						// compulsory12

void SIMUL_C(void)                                                              // compulsory13
{                                                                               // compulsory14
/**********                     INITIALIZATION 	                    **********/

//  SETSIGNAL(0.05,V4);

/*****************************************************************************/
/**********                     PROGRAM LOOP                        **********/
/*****************************************************************************/

  for (Tsimulc=0.1*TDELT; Tsimulc<TEND; Tsimulc=Tsimulc+TDELT)                  // compulsory15
  {                                                                             // compulsory16
    JMsimulc=-1; JSsimulc=-1; JDsimulc=-1; JDLHsimulc=-1;                       // compulsory17
 


// Questions 5, 6, 7 and 8 
//  BODECALC(V159, 0.1, V159, V181);                                  
//	BODECALC(V184, 0.0001, V184, V181);								
//	BODECALC(V183, 0.0001, V183, V181);								
//	BODECALC(V179, 0.0001, V179, V178);								
//	BODECALC(V189, 0.0001, V189, V187);								
//	BODECALC(V188, 0.0001, V188, V187);								
	



//Question 9
//	TRIANGLE(0.1, 0.5, 0.0, 0.5, V188);								
//	FMLINSWP(0.1, PI/2.0, 1.0, 5.0, 40.0, 10.0, V179);



//Question 11
	TRIANGLE(0.1, 0.5, 0.0, 0.5, V188);								
  FMLINSWP(0.1, PI/2.0, 1.0, 5.0, 40.0, 10.0, V179);
	


// Questions 5, 6, 7, and 9
//	BODECALC(V184, 0.00001, V184, V192);								
//	BODECALC(V191, 0.0000000001, V184, V192);									
//	BODECALC(V189, 0.0001, V189, V187);								
//	BODECALC(V188, 0.0001, V189, V187);								
//  BODECALC(V1,0.05,V1,V2);
//  BODECALC(V1,0.1,V1,V117);


//	Question 11

    DIFF(V159, V160, V161);                             				// V161 = V159 - V160
    LEADLAG(V161, 0.0, 1.0, Lm, Rm, V162);              				// V162 = V161 * ( 0.0 + 1.0)/ (Lm + Rm)
	GAIN(V162, Km, V163);                               				// V163 = V162 * Km
	DIFF(V163, V164, V165);                             				// V165 = V163 - V164
	
	DIFF(V165, V171, V166);                             				// V166 = V165 - V171
	INTEGR(V166, 1.0/Jm, V167);                         				// V167 = V166 * (1.0 / Jm)
	DIFF(V167, V179, V168);                             				// V168 = V167 - V179
	
	GAIN(V168, Kfrm, V164);                             				// V164 = V168 * Kfrm
	GAIN(V168, Km, V160);                               				// V160 = V168 * Km

	INTEGR(V168, 1.0, V169);                            				// V169 = V168 * (1.0 / S)
	DIFF(V169, V180, V170);                             				// V170 = V169 - V180
	GAIN(V170, Kshaft, V171);                           				// V171 = V170 * Kshaft
	
	DIFF(V171, V172, V173);                             				// V173 = V171 - V172
	DIFF(V173, V175, V174);                             				// V174 = V173 - V175
	INTEGR(V174, (1.0/Jpc), V176);                      				// V176 = V174 * (1.0 * Jpc)
	
	GAIN(V176, Kfrpc, V173);                            				// V173 = V176 * Kfrpc
	INTEGR(V176, 1.0, V180);                            				// V180 = V176 * 1.0
	
	GAIN(V176, (1.0/Ngear), V177);                      				// V177 = V176 * (1.0 / Ngear)
	DIFF(V177, V179, V178);                            					// V178 = V177 - V179
	DERIV(V179, 1.0, V182);                             				// V182 = V179 * 1.0
	GAIN(V182, Jb, V172);                               				// V172 = V182 * Jb
	
    BIQUAD(V178, 0.0, 0.0, WG*WG, 1.0, 2.0*ZG*WG, WG*WG, V181);    		// V181 = [0.0 + .0.0 + (WG * WG)] / [1.0 + (2*ZG*WG) + (WG * WG)]
	LIMIT(((100.0/360.0)*2*PI), ((-100.0/360.0)*2*PI), V181);
	
	INTEGR(V178, 1.0, V187);                                       		// V187 = V178 * 1.0
	
	DIFF(V188, V187, V189);                                        		// V189 = V188 - V187                           
	LIMIT(((2.0/360.0)*2*PI), ((-2.0/360.0)*2*PI), V189);          		// V189
	GAIN(V189, Ktrk, V190);                                        		// V190 = V189 * Ktrk
	LEADLAG(V190, Te, 1.0, Tf, 1.0, V183);                         		// V190 = (Te + 1.0) / (Tf + 1.0)
	
	
	/*DIFF(V183, V181, V184);                                        	// V184 = V183 - V181
	LEADLAG(V184, p, 1.0, 1.0, 0.0, V185);                         		// V185 = (p + 1.0) / (1.0 + 0.0)
	BIQUAD(V185, 1.0, 2.0*Znt*Wn, Wn*Wn, 1.0, 2.0*Znb*Wn, Wn*Wn, V186); // V186 = [1.0 + (2.0*Znt*Wn) + (Wn*Wn)] / [1.0 + (2.0*Znb*Wn) + (Wn*Wn)]
	GAIN(V186, Kstab, V159); */                                      	// V159 = V186 * Kstab
	
	
	A2D(V181, Tsamp, -1.745, +1.745, 16384L, V192);
	A2D(V183, Tsamp, -1.745, +1.745, 16384L, V191);
	
	ZDIFF(V191, V192, V184);
	ZLEADLAG(V184, A, B, C, D, V185);
	ZBIQUAD(V185, M, E, F, N, G, H, V186);
	ZGAIN(V186, Kstab, V193);
	
	D2A(V193, V159);
	LIMIT(24.0, -24.0, V159);
	




    //GAUSSNOISE(0.6,0.0,0.01,V116);
    // V116 = Gaussian noise, starting at 0.6 s, average 0, and RMS noise of 0.01
    // RMS(V116,0.7,V118);
    // V118 = RMS of V116, start to calculate it at 0.7 s
    // SUM(V20,V116,V117);                         // V117 = V20+V116
    //BIQUAD(V117,0.0,0.0,WG*WG,1.0,2.0*ZG*WG,WG*WG,V21);
    // V21 = V117*(WG^2/(s^2+2.ZG.WG.s+WG^2)
    // LEADLAG(V21,TAU1,1.0,TAU2,1.0,V2);

/**********                  GRAPHING SECTION                       **********/

    YTDRAW(	V188,   	V189,  	V0,                                          	
			V1005, 	V181,   	V2,
			V159,  	V162,  	V0,
			V179, 	V178,  	V0,
			V128,  	V129,  	V0,
			V62, 	V0,   	V0,
			V64,  	V0,  	V0,
			V153, 	V0,   	V0,
			V103, 	V104,	V0 );

    XYDRAW(	V1, 	V20,
			V117, 	V21,
			V21, 	V2,
			V0, 	V0,
			V0, 	V0,
			V0, 	V0,
			V0, 	V0,
			V0, 	V0,
			V0, 	V0,
			V0, 	V0,
			V0, 	V0 	);

   // XYZ1DRAW(	V1,     V2,     V3); 
			
/*****************************************************************************/

  }	// End of PROGRAM LOOP                                     	        		// compulsory18
}	// End of void SIMUL_C(void)  					        					// compulsory19

#pragma package(smart_init)						        						// compulsory20

/*****************************************************************************/
/**********                    END OF PROGRAM                       **********/
/*****************************************************************************/


#pragma once

#include "hKnihovny.hpp"
#include "hDefinice.hpp"
#include "hVypisDoInputSouboru.hpp"
#include "hFunkceHlavniNabidky.hpp"
#include "hOstatniFunkce.hpp"

void fNabidka(bool &LED, bool &konec, float &T, float &ventProc, short int &modVent, short int &modT){
	short int volbaUvodni;	//ulozeni ascii kodu z hlavni  nabidky
	short int volbaT;		//ulozeni ascii kodu z nabidky modu teploty
	short int volbaVent;	//ulozeni ascii kodu z nabidky modu ventilatoru
	
	////////////////////////////////////////////////////////////////
	//                   Zacatek hlavni nabidky                   //
	////////////////////////////////////////////////////////////////
		
		//Vyvolani hlavni nabidky
		
			volbaUvodni = fUvodniNabidka(modVent, modT);
			
		////////////////////////////////////////////////////////////////
		//                 Hlavni rozhodovaci switch                  //
		////////////////////////////////////////////////////////////////
		
			switch(volbaUvodni) { //SW0
				
				//Pri stisknuti <0> nebo <esc> dojde k ukonceni
				
					case volbaNula:
		    			konec = 1;
		    		break; //Konec <SW0 : case volbaNula>
		    
		  			case volbaEsc:
		  				konec = 1;
		    		break; //Konec <SW0 : case volbaEsc>
		    		
		   		//Pri stisknuti <1> dojde k prepnuti stavu LED
	    
				    case volbaJedna:
				    	if (LED==1){
						LED=0;}
				    	else {
						LED=1;}					
						system("cls");
				   	break; //Konec <SW0 : case volbaJedna>
				   	
				//Pri stisknuti <2> se vyvola nabidka zmeny modu vent.
	  
			    case volbaDva:
			    	
			    	//Vycisteni konzole a vypis uvodniho textu + info. tabulky
				  		system("cls");
				  		fUvodniVypis();
						fStavovaTabulka(LED, modVent, ventProc, modT, T);
					
					//Vyvolani nabidky pro volbu modu vent.
					
			  			volbaVent = fNabidkaVent(modT);
			  			
			  			////////////////////////////////////////////////////////////////
						//           Rozhodovaci switch pro mod ventilatoru           //
						////////////////////////////////////////////////////////////////
				  			
							switch (volbaVent){ //SW1
							  	
							  	//Pri stisknuti <a> se chod vent. nastavi na auto
							  	
					  				case volbaA:
					  					modVent = 1;
					  				break; //Konec <SW1 : case volbaA>
				  					
				  				//Pri stisknuti <b> se vent. prepnou na manual
					  				
									case volbaB:
					  					
					  					//Vycisteni konzole a vypis uvodniho textu + info. tabulky
						  					system("cls");
									  		fUvodniVypis();
											fStavovaTabulka(LED, modVent, ventProc, modT, T);
											
					  					modVent = 2;
					  					
					  					//Vyvolani prvniho nastaveni hodnoty vent.
											ventProc = fPrvniNastaveniVent();			  					
					  				break; //Konec <SW1 : case volbaB>
				  					
				  				//Pri stisknuti <c> se vent. vypnou
					  				case volbaC:
					  					modVent = 0;
					  				break; //Konec <SW1 : case volbaC>
					  		} //Konec <SW1>
			  			
			  	break; //Konec <SW0 : case volbaDva>
			  	
			  	//Pri stisknuti <3> se pri manualnich vent. zapne zmena hodnoty vent.
			  	//pokud neni manualni ovladani zapnuto, pak se vyvola nabidka zmeny
				//modu ovladani teploty 
	  
			    case volbaTri:
			    	
			    	//Vycisteni konzole a vypis uvodniho textu + info. tabulky
				  		system("cls");
				  		fUvodniVypis();
				  		fStavovaTabulka(LED, modVent, ventProc, modT, T);
				  		
				  	//Pripad zapnuteho manualniho ovladani vent.
				  	
				  		if (modVent == 2){
				  			ventProc = fNastaveniVent();}
				  			
				  	//Pripad vypnuteho manualniho ovladani vent.
				  	//           =>vyvolani nabidky zmeny modu T
				  	
				  		else{
				  			volbaT = fNabidkaT(modVent, modT);
							  	
								////////////////////////////////////////////////////////////////
								//             Rozhodovaci switch pro mod teploty             //
								////////////////////////////////////////////////////////////////	
									
									switch (volbaT){ //SW2
									
										//Pri stisknuti <a> se prepne mod na manualni a vyvola se
										//nabidka prvniho nastaveni teploty
									
									  		case volbaA:
									  			system("cls");
										  		fUvodniVypis();
										  		fStavovaTabulka(LED, modVent, ventProc, modT, T);
									  			modT=0;
									  			T = fPrvniNastaveniT(modVent);
									  		break; //Konec <SW2 : case volbaA>
									  		
									  	//Pri stisknuti <b> se teplota bude dale nahodne generovat
								  		
											case volbaB:
												modT = 1;
											break; //Konec <SW2 : case volbaB>
											
										//Pri stisknuti <c> se bude v budoucnu nastavovat
										//linearni zmena T s casem
										
											case volbaC:
												modT = 2;
											break; //Konec <SW2 : case volbaC>
											
										//Pri stisknuti <d> se bude v budoucnu nastavovat
										//harmonicky prubeh T v case
										
											case volbaD:
												modT = 3;
											break; //Konec <SW2 : case volbaD>
									} //Konec SW2
						} //Konec else vetve v <SW0 : case volbaTri>
			  	break; //Konec <SW0 : case volbaTri>
			  	
			  	//Pri stisknuti <4> se pri zapnutem manualnim ovladani vent.
			  	//vyvola nabidka zmeny modu T. Pokud neni zapnuto manualni
			  	//ovladani vent. a pokud je zaroven zapnute manualni nastavovani
				//teploty, tak se vyvola nabidka zmeny teploty.
	  	
				    case volbaCtyri:
				  		system("cls");
				  		fUvodniVypis();
				  		fStavovaTabulka(LED, modVent, ventProc, modT, T);
				  		
				  		//Pripad zapnuteho manualniho nastavovani vent.
				  		
					  		if (modVent == 2){			  		
					  			
								volbaT = fNabidkaT(modVent, modT);
								
								switch (volbaT){ //SW2
									
									//Pri stisknuti <a> se prepne mod na manualni a vyvola se
									//nabidka prvniho nastaveni teploty
								
								  		case volbaA:
								  			system("cls");
									  		fUvodniVypis();
									  		fStavovaTabulka(LED, modVent, ventProc, modT, T);
								  			modT=0;
								  			T = fPrvniNastaveniT(modVent);
								  		break; //Konec <SW2 : case volbaA>
								  		
								  	//Pri stisknuti <b> se teplota bude dale nahodne generovat
							  		
										case volbaB:
											modT = 1;
										break; //Konec <SW2 : case volbaB>
										
									//Pri stisknuti <c> se bude v budoucnu nastavovat
									//linearni zmena T s casem
									
										case volbaC:
											modT = 2;
										break; //Konec <SW2 : case volbaC>
										
									//Pri stisknuti <d> se bude v budoucnu nastavovat
									//harmonicky prubeh T v case
									
										case volbaD:
											modT = 3;
										break; //Konec <SW2 : case volbaD>
									} //Konec SW2
							}
							
						//Pripad vypnuteho manualniho nastavovani vent. a zapnuteho
						//manualniho nastavovani teploty
							
							else{
								if (modT == 0){
								T = fNastaveniT(modVent);}
							}
					break; //Konec <SW0 : case volbaCtyri>
			  	
		  		//Pri stisknuti <5> se vyvola nabidka zmeny hodnoty teploty, pokud
		  		//jsou zapnuta manualni ovladani teploty i vent. 
		  
				    case volbaPet:
				  		if (modT == 0){
						    system("cls");
					  		fUvodniVypis();
					  		fStavovaTabulka(LED, modVent, ventProc, modT, T);
							T = fNastaveniT(modVent);}
				  	break; //Konec <SW0 : case volbaPet>

				//Stisknuti jakekoliv jine klavesy cyklus ignoruje
		} //Konec SW0
			
		////////////////////////////////////////////////////////////////
		//                  Konec hlavniho switche                    //
		////////////////////////////////////////////////////////////////
			
			
	
	////////////////////////////////////////////////////////////////
	//                    Konec hlavni nabidky                    //
	////////////////////////////////////////////////////////////////
}

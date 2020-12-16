/**************************************************************************
Hlavní èást 2. Programu.

	Program naèitá hodnoty z 1. Programu, které vyhodnocuje a ukladá do souborù .txt.
***************************************************************************/
#include "hKnihovny.hpp"
#include "hCteniZInputSouboru.hpp"
#include "hVypisDoOutputSouboru.hpp"

using namespace std;



/*----- PROTOTYPY FUNKCÍ -----*/
float fKontrolaTep(float T, bool LED,float Tkrit); 
float fVentAuto(float T);	
float fVentManual(float vent);	
/*----------------------------*/




int main() {
	//system("Color B0");
	/*-----Deklarace promennych-----*/
	float T,vent, napetiVent;
	float Tkrit = 80;												// nastaveni kriticke teploty
	short int napetiLED,modVent;
	bool LED;
	bool stavNacteni = false;
	bool stop;														// promnenna pro zastaveni hlavni smycky														
	/*------------------------------*/
	

	/*-----Zacatek hlavni smycky-----*/	
	while(stop!=true){
	
		system("cls");
		
		
		/*-----Volani funkce nacitani hodnot z programu 1-----*/
		
		fCteniZInputSouboru(LED,T,vent,modVent, stavNacteni);
		
		/*----------------------------------------------------*/
		if (stavNacteni == 1){					//kontrola nacteni souboru
			
			
							
			sleep(0.5);
			
					
		}
		else {
			
			system("cls");				
					
		
		
		
 		cout <<"Nactene hodnoty z programu 1. jsou: "<<"LED= "<<LED<<"; T= "<<T<<"; vent= "<<vent<<"; modVent= "<<modVent<<endl;
	
	
		/*-----Volani funkce kontroly teploty-----*/	
		napetiLED=fKontrolaTep(T,LED,Tkrit);					
		/*----------------------------------------*/
	
	
	
	
		/*-----Rozhodovani o napeti ventilatoru-----*/
		switch(modVent){										// NASTAVENI VSTUPNIHO NAPETI VENTLITORU DLE MODU
			
			case 0:												// stav pro prepinac v poloze off
		
			napetiVent=0;
		
	
			break;
			case 1:												// stav pro prepinac v poloze auto
		
			napetiVent=fVentAuto(T);					// DOPSAT
			
		
			break;
			case 2 :											// stav pro prepinac v poloze manual
		
			napetiVent=fVentManual(vent);    
			
		
			break;
			}
		/*------------------------------------------*/
		
	
	
		/*-----Ulozeni do Textaku-----*/	
		fVypisDoOutputSouboru(T,napetiLED,napetiVent,modVent,vent); 
		/*------------------------------*/
	
	
		sleep(1);
		cout<<endl<<"Konec smycky!!"<<endl;
		//cin>>stop;
		sleep(1);										// èeka 2 vteøiny
		
		
	}

	
	}
	/*-------------------------------*/
	

return 0;
}


/*-----Funkce kontroly teploty a nasledne nastaveni hodnoty napetiLED-----*/
float fKontrolaTep(float T, bool LED, float Tkrit){
	
	float napetiLED;
	
	
	if(T>=Tkrit){
		
		napetiLED=999;											// FUNKCE BLIKANI		
	
	}
	else{
		
		switch(LED){											// NASTAVENI LED 
			
			case 0 :											//  prepinac v poloze OFF
		
			napetiLED=0;
		
	
			break;
			case 1 :											// prepinac v poloze ON
		
			napetiLED=5;			
		
			break;	
		
		}
		
	}
	
return napetiLED;
}
/*------------------------------------------------------------------------*/



/*-----Funkce prevod napeti na ventilatorech dle procent z vent-----*/
float fVentManual(float vent){
	float napetiVent;
			
	napetiVent=0.05*vent;										// prevod procenta na napeti
		
	return napetiVent;
}
/*------------------------------------------------------------------*/


/*-----Funkce nastaveni napeti na ventilatorech dle vstupniho napeti-----*/
float fVentAuto(float T){										// možno vymyslet neco sofistikovanejsiho
	float napetiVent;
	float Tmax = 60;
	float Tmin = 20;
	float A = 5/(Tmax - Tmin);
	float B = A*Tmin;
	
	if (T>=Tmin && T<=Tmax){
		napetiVent=A*T-B;
	}
	else if(T > Tmax){
		napetiVent=5;
	}else{
		napetiVent=0;
	}
	
	return napetiVent;
	
}
/*-----------------------------------------------------------------------*/

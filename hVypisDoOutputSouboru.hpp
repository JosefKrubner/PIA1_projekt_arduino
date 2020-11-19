
/************************************************************************************************************************************
Výpis výstupních hodnot z 2._program do textových souborù: outputLED.txt; outputT.txt; outputVent.txt; outputVentStatus.txt; outputVentProc.txt
**************************************************************************************************************************************/

#pragma once
#include "hKnihovny.hpp"
using namespace std;


void fVypisDoOutputSouboru(float T, float napetiLED,float napetiVent,short int modVent, float vent){

															//  KONTROLA ULOZENI DAT !!!! pridat
ofstream SoubT("outputT.txt");
ofstream SoubLED("outputLED.txt");
ofstream SoubnapetiVent("outputVent.txt");
ofstream SoubmodVent("outputVentStatus.txt");
ofstream Soubvent("outputVentProc.txt");


SoubT<<T;
SoubLED<<napetiLED;
SoubnapetiVent<<napetiVent;
SoubmodVent<<modVent;
Soubvent<< vent;



SoubT.close();
SoubLED.close();
SoubnapetiVent.close();
SoubmodVent.close();
Soubvent.close();




cout<<"Ulozene hodnoty jsou: "<<"T=  "<<T<<"; napetiLED=  "<<napetiLED<<"; napetiVent=  "<<napetiVent<<"; modVent=  "<<modVent<<"; vent=  "<<vent<<endl; 


}

	
	

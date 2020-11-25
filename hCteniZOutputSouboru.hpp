/***************************************************************************************************************************
Ètení dat z output souboru 2. programu
****************************************************************************************************************************/

#pragma once
#include "hKnihovny.hpp"

using namespace std;

void fCteniZOutputSouboru(short int &LED, float &T, float &vent, float &nVent, short int &modVent){
	
short int pomLED;
float pomT, pomvent, napetiVent;


ifstream SoubLED("outputLED.txt");
ifstream SoubT("outputT.txt");
ifstream SoubnapetiVent("outputVent.txt");
ifstream SoubmodVent("outputVentStatus.txt");
ifstream Soubvent("outputVentProc.txt");

SoubLED >> pomLED;
SoubT >> pomT;
SoubnapetiVent >> napetiVent;
SoubmodVent >> modVent;
Soubvent >> pomvent;

LED = pomLED;
T = pomT;
vent = pomvent;
nVent = napetiVent;
modVent = modVent;

SoubLED.close();
SoubT.close();
SoubnapetiVent.close();
SoubmodVent.close();
Soubvent.close();

}

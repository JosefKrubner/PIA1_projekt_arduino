
/************************************************************************************************************************************
Ètení výstpupních hodnot z 1._program uložených v textových souborech: inputLED.txt; inputT.txt; inputVent.txt; inputVentStatus.txt
**************************************************************************************************************************************/

#pragma once
#include "hKnihovny.hpp"
using namespace std;


 void fCteniZInputSouboru(bool &LED, float &T,float &vent, short int &modVent){

	
																	// 	PRIDAT KONTROLU NAHRANI DAT Z TXT
bool pomLED;
float pomT, pomvent;
short int pommodVent;



ifstream soubLED("inputLED.txt");
ifstream soubT("inputT.txt");
ifstream soubVent("inputVent.txt");
ifstream soubVentStatus("inputVentStatus.txt");

soubLED>> pomLED;
soubT >> pomT;
soubVent>> pomvent;
soubVentStatus>> pommodVent;

LED=pomLED;
T=pomT;
vent=pomvent;
modVent=pommodVent;

soubLED.close();
soubT.close();
soubVent.close();
soubVentStatus.close();



}

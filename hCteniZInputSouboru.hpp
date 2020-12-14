
/************************************************************************************************************************************
Ètení výstpupních hodnot z 1._program uložených v textových souborech: inputLED.txt; inputT.txt; inputVent.txt; inputVentStatus.txt
**************************************************************************************************************************************/

#pragma once
#include "hKnihovny.hpp"
using namespace std;


 void fCteniZInputSouboru(bool &LED, float &T,float &vent, short int &modVent,bool &stavNacteni){

	
																 
bool pomLED;
float pomT, pomvent;
short int pommodVent;
bool pomstavNacteni = false;



ifstream soubLED("inputLED.txt");
ifstream soubT("inputT.txt");
ifstream soubVent("inputVent.txt");
ifstream soubVentStatus("inputVentStatus.txt");
																				//	KONTROLU NAHRANI DAT Z TXT
if (soubLED==NULL){
	cout<<"vstupni textovy dokument inputLED.txt se nepodarilo nacist\t"<<endl;
	pomstavNacteni=true;
}
if (soubT==NULL){
	cout<<"vstupni textovy dokument inputT.txt se nepodarilo nacist\t"<<endl;
	pomstavNacteni=true;
}
if (soubVent==NULL){
	cout<<"vstupni textovy dokument inputVent.txt se nepodarilo nacist\t"<<endl;
	pomstavNacteni=true;
}
if (soubVentStatus==NULL){
	cout<<"vstupni textovy dokument inputVentStatus.txt se nepodarilo nacist\t"<<endl;
	pomstavNacteni=true;
}


soubLED>> pomLED;
soubT >> pomT;
soubVent>> pomvent;
soubVentStatus>> pommodVent;

LED=pomLED;
T=pomT;
vent=pomvent;
modVent=pommodVent;
stavNacteni=pomstavNacteni;

soubLED.close();
soubT.close();
soubVent.close();
soubVentStatus.close();



}

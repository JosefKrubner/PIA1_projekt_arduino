#pragma once

#include "hKnihovny.hpp"

using namespace std;

void fVypisDoInputSouboru(float T, bool LED, short int modVent, float ventProc){
	ofstream fileT("inputT.txt");
	ofstream fileLED("inputLED.txt");	
	ofstream fileModVent("inputVentStatus.txt");
	ofstream fileVentProc("inputVent.txt");
	
	fileT << T;
	fileLED << LED;
	fileModVent << modVent;
	fileVentProc << ventProc;
	
	fileT.close();
	fileLED.close();
	fileModVent.close();
	fileVentProc.close();
}

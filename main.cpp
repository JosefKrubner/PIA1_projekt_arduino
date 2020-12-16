/***************************************************************************************************************************
3. program:
Program informuje o èinnosti LED, pøekroèení povolené teploty, aktuální teplotì, modu ventilátoru a velikosti jeho napìtí.
****************************************************************************************************************************/

#include "hKnihovny.hpp"
#include "hCteniZOutputSouboru.hpp"


using namespace std;

int main(){
	//system("Color B0");
	/*----------------Deklarace promennych---------------*/
	float T, vent, nVent;
	short int modVent, procVent, LED;
	/*---------------------------------------------------*/
	
	while(true){
		system("cls");
		/*------------Nacteni hodnot z programu 2--------------*/
		fCteniZOutputSouboru(LED, T, vent, nVent, modVent);					
		/*-----------------------------------------------------*/
		
		
		/*----------------Vypis na obrazovku-------------------*/
		
		//Teplota
			cout <<"Teplota tisku je " << T << " stupnu C" << endl;
		
		//LED zapnuto/vypnuto
		if(LED == 0){
			cout <<"LED osvetleni je vypnuto." << endl;
		} else if(LED == 5){
			cout <<"LED osvetleni je zapnuto." << endl;
		} else{
			cout <<"Byla prekrocena povolena teplota tisku!" << endl;
		};
		
		//mod a mira chodu ventilatoru
		if(modVent == 0){
			cout << "Ventilator je vypnuty." << endl;
		} else if(modVent == 1){
			cout << "Ventilator pracuje v automatickem rezimu s aktualnim napetim " << nVent << " V." << endl;
		} else{
			cout << "Ventilator pracuje v manualnim rezimu s aktualnim napetim " << nVent << " V." << endl;
		};
		//if(getch() == 27) break;
		sleep(2);
	}
	
	
	/*-----------------------------------------------------*/
	
	
	
	return 0;
}

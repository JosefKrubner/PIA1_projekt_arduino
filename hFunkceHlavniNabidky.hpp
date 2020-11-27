#pragma once

#include "hKnihovny.hpp"

using namespace std;

//------------------------------------------------------------------------//
//------------------------------------------------------------------------//
//------------------------------------------------------------------------//
	//Vypisuje uvodni text do konzole	
		void fUvodniVypis(){
			cout << "----------------------------------------\n\n";
			cout << "      GENERATOR VSTUPNICH DAT             \n";
			cout << "                                    V2.1      \n";
			cout << "----------------------------------------\n";
		}	
//------------------------------------------------------------------------//
//------------------------------------------------------------------------//
//------------------------------------------------------------------------//
	//Vypisuje momentalni nastaveni vystupu 
		void fStavovaTabulka(bool LED, short int modVent, float ventProc, short int modT, float T){			
			//Vypsani stavu LED - zapnuto/vypnuto				
				cout << "| Stav LED: \t\t  ";
					if (LED == 1){
						cout << "| ZAPNUTO " << endl;}
					else {
						cout << "| VYPNUTO " << endl;}						
			//Vypsani aktualniho rezimu ventilatoru						
				cout << "| Rezim ventilatoru: \t  ";
					switch (modVent){
						case 0:
							cout << "| VYPNUTO " << endl;
							break;
						case 1:
							cout << "| AUTOMATICKY " << endl;
							break;
						case 2:
							cout << "| MANUALNI " << endl;
							break;
					}					
			//Pro manualni ovladani vent. vypise nastavenou hodnotu					
				if (modVent == 2){
					cout << "| Mira chodu ventilatoru: | " << ventProc << " % " << endl;}					
			//Vypise aktualni rezim ovladani teploty 					
				cout << "| Rezim teploty: \t  ";
					switch (modT){
						case 0:
							cout << "| KONSTANTNI " << endl;
							break;
						case 1:
							cout << "| NAHODNA " << endl;
							break;
						case 2:
							cout << "| LINEARNI PRUBEH" << endl;
							break;
						case 3:
							cout << "| HARMONICKY PRUBEH" << endl;
							break;
					}					
			//Vypise aktualni nastavenou teplotu					
				cout << "| Aktualni teplota: \t  | " << T << " stupnu\t" <<endl;
				cout << "----------------------------------------\n";
		}
//------------------------------------------------------------------------//
//------------------------------------------------------------------------//
//------------------------------------------------------------------------//		
	//Vypise hlavni nabidku v zavislosti na nastavenych modech ovladani
		short int fUvodniNabidka(short int modVent, short int modT){
			if (modVent == 2){
				//Vypis, pokud je nastavene manualni ovladani vent. i teploty
					if (modT == 0){
						cout << "\nPro vyber stiskni pozadovanou klavesu    \n";
						cout << "\n    <1> Zapnout/vypnout LED\n";
						cout <<   "    <2> Zmenit mod chodu ventilatoru\n";
						cout <<   "    <3> Zmenit hodnotu chodu ventilatoru\n";
						cout <<   "    <4> Zmenit nastaveni rezimu teploty\n";
						cout <<   "    <5> Zmenit hodnotu teploty\n\n";
						cout <<   "    <0> Exit\n";}						
				//Vypis, pokud je nastavene pouze manualni ovladani vent.				
					else {
						cout << "\nPro vyber stiskni pozadovanou klavesu    \n";
						cout << "\n    <1> Zapnout/vypnout LED\n";
						cout <<   "    <2> Zmenit mod chodu ventilatoru\n";
						cout <<   "    <3> Zmenit hodnotu chodu ventilatoru\n";
						cout <<   "    <4> Zmenit nastaveni rezimu teploty\n\n";
						cout <<   "    <0> Exit\n";
					}
			}
			else{				
				//Vypis, pokud je nastavene pouze manualni ovladani teploty				
					if (modT == 0){
							cout << "\nPro vyber stiskni pozadovanou klavesu    \n";
							cout << "\n    <1> Zapnout/vypnout LED\n";
							cout <<   "    <2> Zmenit mod chodu ventilatoru\n";
							cout <<   "    <3> Zmenit nastaveni rezimu teploty\n";
							cout <<   "    <4> Zmenit hodnotu teploty\n\n";
							cout <<   "    <0> Exit\n";}							
				//Vypis, pokud neni nic ovladano manualne (teplota, ani vent.)				
					else{
						cout << "\nPro vyber stiskni pozadovanou klavesu    \n";
						cout << "\n    <1> Zapnout/vypnout LED\n";
						cout <<   "    <2> Zmenit mod chodu ventilatoru\n";
						cout <<   "    <3> Zmenit nastaveni rezimu teploty\n\n";
						cout <<   "    <0> Exit\n";}
			}				
			//Funkce vraci ascii kod stisknute klavesy			
				return getch();
		}		
//------------------------------------------------------------------------//
//------------------------------------------------------------------------//
//------------------------------------------------------------------------//
	//Vyvolá nabidku zmeny modu chodu vent.	
		short int fNabidkaVent(short int modT){			
			//Pokud je zapnuto manualni nastavovani teploty
			if (modT == 0){
				cout << "\nPro vyber stiskni pozadovanou klavesu    \n";
				cout << "\n    <1> Zapnout/vypnout LED\n";
				cout <<   "    <2> Zmenit mod chodu ventilatoru\n";
				cout <<   "                <a> Automaticky chod\n";
				cout <<   "                <b> Manualni rizeni\n";
				cout <<   "                <c> Vypnuto\n";
				cout <<   "    <3> Zmenit nastaveni rezimu teploty\n";
				cout <<   "    <4> Zmenit hodnotu teploty\n\n";
				cout <<   "    <0> Exit\n";				
			}
			//Pokud je vypnuto manualni nastavovani teploty
			else{
				cout << "\nPro vyber stiskni pozadovanou klavesu    \n";
				cout << "\n    <1> Zapnout/vypnout LED\n";
				cout <<   "    <2> Zmenit mod chodu ventilatoru\n";
				cout <<   "                <a> Automaticky chod\n";
				cout <<   "                <b> Manualni rizeni\n";
				cout <<   "                <c> Vypnuto\n";
				cout <<   "    <3> Zmenit nastaveni rezimu teploty\n\n";
				cout <<   "    <0> Exit\n";	
			}
			
			//Funkce vraci ascii kod stisknute klavesy			
				return getch();
		}		
//------------------------------------------------------------------------//
//------------------------------------------------------------------------//
//------------------------------------------------------------------------//
	//Vyvola nabidku zmeny modu teploty	
		short int fNabidkaT(short int modVent, short int modT){	
			if (modVent == 2){					
					//Pokud jsou zapnuta manualni ovladani vent. i teploty
					if (modT == 0){
						cout << "\nPro vyber stiskni pozadovanou klavesu    \n";
						cout << "\n    <1> Zapnout/vypnout LED\n";
						cout <<   "    <2> Zmenit mod chodu ventilatoru\n";
						cout <<   "    <3> Zmenit hodnotu chodu ventilatoru\n";
						cout <<   "    <4> Zmenit nastaveni rezimu teploty\n";
						cout <<   "                   <a> Manualni nastaveni \n";
						cout <<   "                   <b> Nahodne generovani \n";
						cout <<   "                   <c> Linearni prubeh --in progress--\n";
						cout <<   "                   <d> Harmonicky prubeh --in progress-- \n";
						cout <<   "    <5> Zmenit hodnotu teploty\n\n";
						cout <<   "    <0> Exit\n";}					
					//Pokud je zapnuto pouze manualni ovladani vent.
					else {
						cout << "\nPro vyber stiskni pozadovanou klavesu    \n";
						cout << "\n    <1> Zapnout/vypnout LED\n";
						cout <<   "    <2> Zmenit mod chodu ventilatoru\n";
						cout <<   "    <3> Zmenit hodnotu chodu ventilatoru\n";
						cout <<   "    <4> Zmenit nastaveni rezimu teploty\n";
						cout <<   "                   <a> Manualni nastaveni \n";
						cout <<   "                   <b> Nahodne generovani \n";
						cout <<   "                   <c> Linearni prubeh --in progress--\n";
						cout <<   "                   <d> Harmonicky prubeh --in progress-- \n\n";
						cout <<   "    <0> Exit\n";
					}
			}
			else{
				//Pokud je zapnuto pouze manualni ovladani teploty
				if (modT == 0){
						cout << "\nPro vyber stiskni pozadovanou klavesu    \n";
						cout << "\n    <1> Zapnout/vypnout LED\n";
						cout <<   "    <2> Zmenit mod chodu ventilatoru\n";
						cout <<   "    <3> Zmenit nastaveni rezimu teploty\n";
						cout <<   "                   <a> Manualni nastaveni \n";
						cout <<   "                   <b> Nahodne generovani \n";
						cout <<   "                   <c> Linearni prubeh --in progress--\n";
						cout <<   "                   <d> Harmonicky prubeh --in progress-- \n";
						cout <<   "    <4> Zmenit hodnotu teploty\n\n";
						cout <<   "    <0> Exit\n";}						
				//Pokud jsou obe manualni ovladani neaktivni
				else{
					cout << "\nPro vyber stiskni pozadovanou klavesu    \n";
					cout << "\n    <1> Zapnout/vypnout LED\n";
					cout <<   "    <2> Zmenit mod chodu ventilatoru\n";
					cout <<   "    <3> Zmenit nastaveni rezimu teploty\n";
					cout <<   "                   <a> Manualni nastaveni \n";
					cout <<   "                   <b> Nahodne generovani \n";
					cout <<   "                   <c> Linearni prubeh --in progress--\n";
					cout <<   "                   <d> Harmonicky prubeh --in progress-- \n";
					cout <<   "    <0> Exit\n";}
			}			
			//Funkce vraci ascii kod stisknute klavesy			
				return getch();
		}		
//------------------------------------------------------------------------//
//------------------------------------------------------------------------//
//------------------------------------------------------------------------//
	//Funkce pro prvni manualni nastaveni vent.		
		float fPrvniNastaveniVent(){
			float vent;			
			cout << "\nPro vyber stiskni pozadovanou klavesu    \n";
			cout << "\n    <1> Zapnout/vypnout LED\n";
			cout <<   "    <2> Zmenit mod chodu ventilatoru\n";
			cout <<   "                <b> Manualni rizeni\n";
			cout <<   "                           Zadej hodnotu a stiskni <enter>: ";
			cin >> vent;			
			//Pokud by mela nastavena hodnota presahnout interval <0,100> %, tak
			//zadanou hodnotu upravi, aby davala smysl -> zapornym hodnotam zmeni
			//znamenko a cokoliv vyssi, nez 100 nastavi na 100.
			if (vent < 0) {
			vent = 0-vent;}
			if (vent > 100) {
			vent = 100;}			
			return vent;
		}
//------------------------------------------------------------------------//
//------------------------------------------------------------------------//
//------------------------------------------------------------------------//
	//Funkce pro manualni nastaveni vent.
		float fNastaveniVent(){
			float vent;			
			cout << "\nPro vyber stiskni pozadovanou klavesu    \n";
			cout << "\n    <1> Zapnout/vypnout LED\n";
			cout <<   "    <2> Zmenit mod chodu ventilatoru\n";
			cout <<   "    <3> Zmenit hodnotu chodu ventilatoru\n";
			cout <<   "              Zadej hodnotu a stiskni <enter>: ";
			cin >> vent;			
			//Pokud by mela nastavena hodnota presahnout interval <0,100> %, tak
			//zadanou hodnotu upravi, aby davala smysl -> zapornym hodnotam zmeni
			//znamenko a cokoliv vyssi, nez 100 nastavi na 100.
			if (vent < 0) {
			vent = 0-vent;}
			if (vent > 100) {
			vent = 100;}			
			return vent;
		}
//------------------------------------------------------------------------//
//------------------------------------------------------------------------//
//------------------------------------------------------------------------//
	//Funkce pro prvni manualni nastaveni teploty
		float fPrvniNastaveniT(short int modVent){			
			float T;			
			if (modVent == 2){
						//Vzhled nabidky pro zapnute manualni ovladani vent.
						cout << "\nPro vyber stiskni pozadovanou klavesu    \n";
						cout << "\n    <1> Zapnout/vypnout LED\n";
						cout <<   "    <2> Zmenit mod chodu ventilatoru\n";
						cout <<   "    <3> Zmenit hodnotu chodu ventilatoru\n";
						cout <<   "    <4> Zmenit nastaveni rezimu teploty\n";
						cout <<   "                   <a> Manualni nastaveni\n";
						cout <<   "                              Zadej pozadovanou hodnotu a stiskni <enter>: ";}						
					else {
						//Vzhled nabidky pro vypnute manualni ovladani vent.
						cout << "\nPro vyber stiskni pozadovanou klavesu    \n";
						cout << "\n    <1> Zapnout/vypnout LED\n";
						cout <<   "    <2> Zmenit mod chodu ventilatoru\n";
						cout <<   "    <3> Zmenit nastaveni rezimu teploty\n";
						cout <<   "                   <a> Manualni nastaveni\n ";
						cout <<   "                              Zadej pozadovanou hodnotu a stiskni <enter>: ";
					}
			//Zde se zadani uzivatelem nijak nekotroluje :)
			cin >> T;
			return T;
		}		
//------------------------------------------------------------------------//
//------------------------------------------------------------------------//
//------------------------------------------------------------------------//
	//Funkce pro manualni nastaveni teploty
		float fNastaveniT(short int modVent){			
			float T;
			if (modVent == 2){
				//Vzhled nabidky pro zapnute manualni ovladani vent.
				cout << "\nPro vyber stiskni pozadovanou klavesu    \n";
				cout << "\n    <1> Zapnout/vypnout LED\n";
				cout <<   "    <2> Zmenit mod chodu ventilatoru\n";
				cout <<   "    <3> Zmenit hodnotu chodu ventilatoru\n";
				cout <<   "    <4> Zmenit nastaveni rezimu teploty\n";
				cout <<   "    <5> Zmenit hodnotu teploty\n";
				cout <<   "                       Zadej pozadovanou hodnotu a stiskni <enter>: ";
			}
			else {
				//Vzhled nabidky pro vypnute manualni ovladani vent.
				cout << "\nPro vyber stiskni pozadovanou klavesu    \n";
				cout << "\n    <1> Zapnout/vypnout LED\n";
				cout <<   "    <2> Zmenit mod chodu ventilatoru\n";
				cout <<   "    <3> Zmenit nastaveni rezimu teploty\n";
				cout <<   "    <4> Zmenit hodnotu teploty\n";
				cout <<   "                       Zadej pozadovanou hodnotu a stiskni <enter>: ";
			}					
			//Zde se zadani uzivatelem nijak nekotroluje :)
			cin >> T;
			return T;
		}

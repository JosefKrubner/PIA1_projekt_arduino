#include "hKnihovny.hpp"
#include "hDefinice.hpp"
#include "hVypisDoInputSouboru.hpp"
#include "hFunkceHlavniNabidky.hpp"
#include "hOstatniFunkce.hpp"
#include "hNabidkaSwitch.hpp"

using namespace std;

int main(int argc, char** argv) {
	//Nastaveni barev konzole
		system("Color B0");
	//------------------------------------------------------------------------//
		//Deklarace a inicializace pozivanych promennych
			bool LED=0;				//Led vypnuto/zapnuto
			bool konec=0;			//Pro vyskoceni ze smycky=konec programu
			float T=25.45;			//Nastaveni teploty
			float ventProc=56.; 	//Nastaveni vykonu ventilatoru
			short int modVent=1;	//Nastaveni modu chodu ventilatoru
						// 0-vypnuto	1-auto	2-manual
			short int modT=1;		//Nastaveni modu nastaveni teploty
							// 0-manualni	1-nahodna	tbd.:(2,3 - linearni, harmonicky)
	//------------------------------------------------------------------------//
		//Inicializace pocitani casu = prostredek pro nahodne teploty
			srand(time(NULL));		
	//------------------------------------------------------------------------//
		//Hlavni smycka programu
			while(true){
				//------------------------------------------------------------//
					//Pri nastavenem nahodnem generovani teploty vygeneruje teplotu
						if (modT == 1){
							T = fNahodnaTeplota();
						}
				//------------------------------------------------------------//
					//Vypsani promennych do input souboru pro hlavni program					
						fVypisDoInputSouboru(T, LED, modVent, ventProc);						
				//------------------------------------------------------------//
					//Vycisteni konzole					
						system("cls"); 																
				//------------------------------------------------------------//
					//Vypis uvodniho textu a stavove tabulky					
						fUvodniVypis();
						fStavovaTabulka(LED, modVent, ventProc, modT, T);				
				//Volani hlavni nabidky	
					fNabidka(LED, konec, T, ventProc, modVent, modT);						
					// Podminka pro vyskoceni z programu						
						if (konec == 1) {
							break;}							
			}//Konec hlavni smycky programu			
	//------------------------------------------------------------------------//			
		//Cekani na klavesu (pri spouseni mimo IDE)		
		cout << "Program ukoncen. Stiskni libovolnou klavesu...";
		getch();					
	return 0;
}

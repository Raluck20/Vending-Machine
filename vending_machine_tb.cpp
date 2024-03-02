#include "vending_machine_tb.h"
#include "vending_machine.h"
#include <iostream>

const char* state_to_string(State state) {
    switch (state) {
        case START: return "START";
        case INTRODUCERE_MONEDA: return "INTRODUCERE_MONEDA";
        case MONEDA_25_LEI: return "MONEDA_25_LEI";
        case MONEDA_5_10_LEI: return "MONEDA_5_10_LEI";
        case NUMARARE_MONEDA: return "NUMARARE_MONEDA";
        case ELIBERARE_BAUTURA: return "ELIBERARE_BAUTURA";
        case ELIBERARE_REST: return "ELIBERARE_REST";
        case BUTON_THANK_YOU: return "BUTON_THANK_YOU";
        default: return "STARE NECUNOSCUTA";
    }
}

void vending_machine_test() {
		State stare_curenta = START;
	    bool bautura_eliberata = false;
	    bool buton_TY_apasat = false;
	    ap_uint<5> moneda;
	    int rest = 0;
	    int suma = 0;

	    std::cout<<"Test1: cand introducem 25 lei\n";
	    moneda = 25;
	    vending_machine(moneda, stare_curenta, bautura_eliberata, buton_TY_apasat,rest,suma);


	    std::cout<<"\nTest2: cand introducem o bancnota de 5 lei si doua de 10 lei\n";
	    bautura_eliberata = false;
	    stare_curenta = START;
	    rest = 0;
	    suma = 0;

	    moneda = 5;
	    std::cout<<"Introducem 5 lei\n";
	    vending_machine(moneda, stare_curenta, bautura_eliberata, buton_TY_apasat,rest,suma);
	    std::cout << "Stare dupa introducerea monedei de 5 lei: " <<  state_to_string(stare_curenta) << std::endl;
	    std::cout << "Bautura eliberata: " << bautura_eliberata << std::endl;

	    std::cout<<"Introducem inca 10 lei\n";
	    moneda = 10;
	    vending_machine(moneda, stare_curenta, bautura_eliberata, buton_TY_apasat,rest,suma);
	    std::cout << "Stare dupa introducerea monedei de 10 lei: " <<  state_to_string(stare_curenta) << std::endl;
	    std::cout << "Bautura eliberata: " << bautura_eliberata << std::endl;
	    std::cout<<"Mai introducem inca 10 lei\n";
	    vending_machine(moneda, stare_curenta, bautura_eliberata, buton_TY_apasat,rest,suma);


	    bautura_eliberata = false;

	    std::cout<<"\nTest3: daca nu s-ar fi eliberat mai devreme bautura si mai introduceam 10 lei\n";
	    vending_machine(moneda, stare_curenta, bautura_eliberata, buton_TY_apasat,rest,suma);
	    std::cout << "Stare dupa introducerea monedei de 10 lei: " <<  state_to_string(stare_curenta) << std::endl;

}

int main() {
	vending_machine_test();
	return 0;
}

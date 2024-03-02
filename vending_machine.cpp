#include "vending_machine.h"
#include <iostream>
#define PRICE 25

void vending_machine(ap_uint<5> moneda, State &stare_curenta, bool &bautura_eliberata, bool &buton_TY_apasat, int &rest, int &suma) {
    // Verificam daca suntem in starea BUTON_THANK_YOU si butonul a fost apasat
    if (stare_curenta == BUTON_THANK_YOU && buton_TY_apasat) {
        std::cout << "Multumim!\n";
        // Eliberam restul daca este necesar
        if (rest > 0) {
            std::cout << "Rest eliberat: " << rest << " lei.\n";
        }
        // Resetam starea automatului pentru urmatorul client
        suma = 0;
        rest = 0;
        stare_curenta = START;
        bautura_eliberata = false;
        buton_TY_apasat = false;
        return;
    }

    // Procesam moneda introdusa
    if (moneda > 0) {
        stare_curenta = INTRODUCERE_MONEDA;
        suma += moneda;
        // Setam starea corespunzatoare in functie de valoarea monedei
        if (moneda == 25) {
            stare_curenta = MONEDA_25_LEI;
        } else if (moneda == 5 || moneda == 10) {
            stare_curenta = MONEDA_5_10_LEI;
        }
    }

    // Verificam daca suma acumulata este suficienta pentru a elibera bautura
    if (suma >= PRICE && !bautura_eliberata) {
        bautura_eliberata = true;
        rest = suma - PRICE;
        stare_curenta = (rest > 0) ? ELIBERARE_REST : ELIBERARE_BAUTURA;
        std::cout << "Bautura racoritoare a fost eliberata.\n";
        // Anuntam clientul daca trebuie sa astepte restul
        if (rest > 0) {
            std::cout << "Asteptati restul: " << rest << " lei.\n";
        } else {
            std::cout << "Multumim! Asteptam urmatorul client.\n";
        }
    }

    // Dupa eliberarea bauturii, setam starea pentru butonul THANK YOU
    if (stare_curenta == ELIBERARE_BAUTURA) {
        stare_curenta = BUTON_THANK_YOU;
    }
}

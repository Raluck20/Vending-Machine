#ifndef VENDING_MACHINE_H_
#define VENDING_MACHINE_H_

#include <ap_int.h>


enum State {
    START,
    INTRODUCERE_MONEDA,
    MONEDA_25_LEI,
    MONEDA_5_10_LEI,
    NUMARARE_MONEDA,
    ELIBERARE_BAUTURA,
    ELIBERARE_REST,
    BUTON_THANK_YOU
};

void vending_machine(ap_uint<5> moneda, State &stare_curenta, bool &bautura_eliberata, bool &buton_TY_apasat, int &rest, int &suma);

#endif

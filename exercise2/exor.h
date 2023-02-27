#ifndef EXOR_H
#define EXOR_H

#include <systemc.h>

#include "nand.h"

// TODO: Insert your code here
SC_MODULE(exor){
    sc_in<bool> A;
    sc_in<bool> B;
    sc_out<bool> Z;

    nand a, b, c, d;

    sc_signal<bool> h1,h2,h3;

    SC_CTOR(exor):A("A"),B("B"), Z("Z"),a("NAND_A"),b("NAND_B"),c("NAND_C"),d("NAND_D"), h1("h_a->cb"), h2("h_b->d"),h3("h_b->b")
    { 
        a.A.bind(A);
        a.B.bind(B);
        a.Z.bind(h1);
        c.A.bind(A);
        c.B.bind(h1);
        c.Z.bind(h2);
        b.A.bind(h1);
        b.B.bind(B);
        b.Z.bind(h3);
        d.A.bind(h2);
        d.B.bind(h3);
        d.Z.bind(Z);
    }
};
#endif // EXOR_H

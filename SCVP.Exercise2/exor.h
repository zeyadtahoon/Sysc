#ifndef EXOR_H
#define EXOR_H

#include <systemc.h>

#include "nand.h"

SC_MODULE(exor){
    
    sc_in<bool>A;
    sc_in<bool>B;
    sc_out<bool>Z;

    nand a,b,c,d;
    sc_signal<bool> h1,h2,h3;

    SC_CTOR(exor):a("NAND A"),b("NAND B"),c("NAND C"),d("NAND D"),A("A"),B("B"),Z("Z"),h1("H1"),h2("H2"),h3("H3"){
        
        a.A.bind(A);
        c.A.bind(A);
        a.B.bind(B);
        b.B.bind(B);
        a.Z.bind(h1);
        c.B.bind(h1);
        b.A.bind(h1);
        c.Z.bind(h2);
        b.Z.bind(h3);
        d.A.bind(h2);
        d.B.bind(h3);
        d.Z.bind(Z);


        
    }
    
};

#endif // EXOR_H

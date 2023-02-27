#ifndef NAND_H
#define NAND_H

#include <systemc.h>
#include <iostream>

// TODO: Insert your code here
SC_MODULE(nand){
    sc_in<bool> A;
    sc_in<bool> B;
    sc_out<bool>Z;

    SC_CTOR(nand){
        SC_METHOD(do_nand);
        sensitive << A << B;
    }
    void do_nand(){
        Z.write(!(A.read()&&B.read()));
    }

};
#endif

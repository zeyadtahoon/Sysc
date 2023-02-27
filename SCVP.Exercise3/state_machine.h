#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <systemc.h>

SC_MODULE(stateMachine){
    sc_in<char> input;
    sc_in<bool> clk;
    enum base {Start, G, GA, GAA, GAAG};

    SC_CTOR(stateMachine){
        SC_METHOD(process);
        sensitive <<clk.pos();
        dont_initialize();
    }
    //base state=Start;
    void process();


};

#endif // STATE_MACHINE_H



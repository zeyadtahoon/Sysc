#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

using namespace std;
#include <systemc.h>


SC_MODULE(stateMachine){

    public:
    sc_in<char>in;
    sc_in<bool> clk;
    enum base {Start, G, GA, GAA, GAAG};
    int counter=0;
    SC_CTOR(stateMachine): in("in"),clk("clk"){
        SC_METHOD(process);
        sensitive <<clk.pos();
        dont_initialize();
    }
    base state=Start;
    void process();
    

 };

#endif // STATE_MACHINE_H



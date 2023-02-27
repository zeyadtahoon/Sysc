#include <systemc.h>

#include "stim.h"
#include "exor.h"
#include "mon.h"

int sc_main(int, char**)
{
    sc_signal<bool> sigA, sigB, sigZ;
    sc_clock TestClk("TestClock", 10, SC_NS,0.5, 1, SC_NS);

    stim Stim1("Stimulus");
    Stim1.A(sigA);
    Stim1.B(sigB);

    exor DUT("exor");
    DUT.A(sigA);
    DUT.B(sigB);
    DUT.Z(sigZ);

    Monitor mon("Monitor");
    mon.A(sigA);
    mon.B(sigB);
    mon.Z(sigZ);


    sc_trace_file* Tf;
    Tf = sc_create_vcd_trace_file("traces");
    //((vcd_trace_file*)Tf)->sc_set_vcd_time_unit(-9);
    sc_trace(Tf, sigA  , "A" );
    sc_trace(Tf, sigB  , "B" );
    sc_trace(Tf, sigZ  , "Z" );
    sc_trace(Tf, DUT.h1, "S1");
    sc_trace(Tf, DUT.h2, "S2");
    sc_trace(Tf, DUT.h3, "S3");


    sc_start();  // run forever
    sc_close_vcd_trace_file(Tf);
    
    return 0;
}

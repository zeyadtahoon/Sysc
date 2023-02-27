#include <systemc.h>
#include "place.h"
#include "transition.h"
#include "subnet.h"

// Toplevel:
// TODO
SC_MODULE(Toplevel){
    //transition t1 {"t1"};
    //transition t2 {"t2"};
////////////////// normal petrinets
    // transition<1,2> t1 {"t1"}; //modification for multiport
    // transition<2,1> t2 {"t2"};
    // transition<1,1> t3 {"t3"};
  ////////////////////////////////////////////
////////////////////////////////////////////////// Transitions for Modelling a Single Memory Bank
        // transition <1,1>ACT{"ACT"};
        // transition <1,1>PRE{"PRE"};
        // transition <1,1>RD{"RD"};
        // transition <1,1>WR{"WR"};

////////////////// normal petrinets
    //place p1,p2,p3,p4;
    //place <1,1>p1,p2,p3,p4; //// modification for templated channels
 ////////////////////////////////////////////
//////////////////////////////////////////////////Places for Modelling a Single Memory Bank       
    // place <1,1>IDLE;
    // place<3,2>ACTIVE;

    //////////////////Modelling Building Hierarchical PNs

    place<1,1>IDLE;
    subnet s1{"s1"},s2{"s2"};

    SC_CTOR(Toplevel){

        // //p1.addTokens(1);
        // p1.addTokens();  //// modification for templated channels
        ////////////////////////////////////Modelling a Single Memory Bank 
        IDLE.addTokens();
        IDLE.addTokens();

////////////////////////////////binding for normal petrinets
        // t1.in.bind(p1);
        // t1.out.bind(p2);
        // t1.out.bind(p3);

        // t2.in.bind(p2);
        // t2.in.bind(p4);
        // t2.out.bind(p1);
        
        // t3.in.bind(p3);
        // t3.out.bind(p4);

        //////////////////Modelling a Single Memory Bank
        // ACT.in.bind(IDLE);
        // ACT.out.bind(ACTIVE);
        // RD.in.bind(ACTIVE);
        // RD.out.bind(ACTIVE);
        // PRE.in.bind(ACTIVE);
        // PRE.out.bind(IDLE);
        // WR.in.bind(ACTIVE);
        // WR.out.bind(ACTIVE);

        //////////////////Modelling Building Hierarchical PNs
        s1.ACT.in.bind(IDLE);
        s2.ACT.in.bind(IDLE);
        s1.PRE.out.bind(IDLE);
        s2.PRE.out.bind(IDLE);
        SC_THREAD(process);
    }
    void process(){
    /*
        while (true){
            wait(10, SC_NS);
            t1.fire();
            wait(10, SC_NS);
            t1.fire();
            wait(10, SC_NS);
            t2.fire();
            sc_stop();
        }
    */
   /*
        while (true){                   //
            wait(10, SC_NS);            //
            t1.fire();                  //
            wait(10, SC_NS);            //
            t2.fire();                  //              
            wait(10, SC_NS);            //
            t3.fire();                  //
            wait(10, SC_NS);            //
            t2.fire();                  //
            sc_stop();                  //      
        }
    */
   /////////////////////////////////////////////Test Modelling a Single Memory Bank 

        // while(true){

        //     wait(10, SC_NS);
        //     ACT.fire();
        //     wait(10, SC_NS);
        //     ACT.fire();
        //     wait(10, SC_NS);
        //     RD.fire();
        //     wait(10, SC_NS);
        //     WR.fire();
        //     wait(10, SC_NS);
        //     PRE.fire();
        //     wait(10, SC_NS);
        //     ACT.fire();
        //     sc_stop();
        // }
        while (true){
            wait(10, SC_NS);
            s1.ACT.fire();
            wait(10, SC_NS);
            s1.ACT.fire();
            wait(10, SC_NS);
            s1.RD.fire();
            wait(10, SC_NS);
            s1.WR.fire();
            wait(10, SC_NS);
            s1.PRE.fire();
            wait(10, SC_NS);
            s1.ACT.fire();
            wait(10, SC_NS);
            s2.ACT.fire();
            wait(10, SC_NS);
            s2.ACT.fire();
            wait(10, SC_NS);
            s1.PRE.fire();
            wait(10, SC_NS);
            s2.PRE.fire();
            wait(10, SC_NS);
            sc_stop();
    }  
    }         
};
int sc_main(int, char**){
    // TODO
    Toplevel t("t");
    sc_start();
    return 0;
}

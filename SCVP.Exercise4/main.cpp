#include <systemc.h>

#include "place.h"
#include "transition.h"
#include "subnet.h"
using namespace std;

// Toplevel:
// TODO


/////////////normalllllllllll

// SC_MODULE(toplevel){
//     transition t1 {"t1"};
//     transition t2 {"t2"};
    
//     place p1,p2;

//     SC_CTOR(toplevel){

//         p1.addTokens(1);
//         t1.in.bind(p1);
//         t1.out.bind(p2);
//         t2.in.bind(p2);
//         t2.out.bind(p1);

//         SC_THREAD(process);

    
//     }
//     void process(){
//         while (true) {
//             wait(10, SC_NS);
//             t1.fire();
//             wait(10, SC_NS);
//             t1.fire();
//             wait(10, SC_NS);
//             t2.fire();
//             sc_stop();
//             }
//     }
// };

// int sc_main(int, char**)
// {
//     // TODO
//     toplevel t("t");
//     sc_start();
//     return 0;
// }

// SC_MODULE(toplevel){
//     transition <1,2>t1 {"t1"};
//     transition <2,1>t2 {"t2"};
//     transition <1,1>t3 {"t3"};
    
//     place p1,p2,p3,p4;

//     SC_CTOR(toplevel){

//         p1.addTokens();

//         t1.in.bind(p1);
//         t1.out.bind(p2);
//         t1.out.bind(p3);
//         t2.in.bind(p2);
//         t2.in.bind(p4);
//         t2.out.bind(p1);
//         t3.in.bind(p3);
//         t3.out.bind(p4);

//         SC_THREAD(process);

    
//     }
//     void process(){
//         while (true){
//             wait(10, SC_NS);
//             t1.fire();
//             wait(10, SC_NS);
//             t2.fire();
//             wait(10, SC_NS);
//             t3.fire();
//             wait(10, SC_NS);
//             t2.fire();
//             wait(10, SC_NS);
//             sc_stop();
//         }
//     }
// };
// int sc_main(int, char**)
// {
//     // TODO
//     toplevel t("t");
//     sc_start();
//     return 0;
// }

////////////////for templated

// SC_MODULE(toplevel){
//     transition <1,2>t1 {"t1"};
//     transition <2,1>t2 {"t2"};
//     transition <1,1>t3 {"t3"};
    
//     place <1,1> p1,p2,p3,p4;

//     SC_CTOR(toplevel){

//         p1.addTokens();

//         t1.in.bind(p1);
//         t1.out.bind(p2);
//         t1.out.bind(p3);
//         t2.in.bind(p2);
//         t2.in.bind(p4);
//         t2.out.bind(p1);
//         t3.in.bind(p3);
//         t3.out.bind(p4);

//         SC_THREAD(process);

    
//     }
//     void process(){
//         while (true){
//             wait(10, SC_NS);
//             t1.fire();
//             wait(10, SC_NS);
//             t2.fire();
//             wait(10, SC_NS);
//             t3.fire();
//             wait(10, SC_NS);
//             t2.fire();
//             wait(10, SC_NS);
//             sc_stop();
//         }
//     }
// };
// int sc_main(int, char**)
// {
//     // TODO
//     toplevel t("t");
//     sc_start();
//     return 0;
// }

////////////////////memory bank
// SC_MODULE(toplevel){
//     transition <1,1>ACT,WR,PRE,RD;
    
//     place <1,1> IDLE;
//     place <3,3>ACTIVE;
    

//     SC_CTOR(toplevel):ACT("ACT"),WR("WR"),RD("RD"),PRE("PRE"){

//         IDLE.addTokens();

//         ACT.in.bind(IDLE);
//         ACT.out.bind(ACTIVE);
//         RD.out.bind(ACTIVE);
//         RD.in.bind(ACTIVE);
//         PRE.in.bind(ACTIVE);
//         PRE.out.bind(IDLE);
//         WR.in.bind(ACTIVE);
//         WR.out.bind(ACTIVE);

//         SC_THREAD(process);

    
//     }
//     void process(){
//         while (true){
//             wait(10, SC_NS);
//             ACT.fire();
//             wait(10, SC_NS);
//             ACT.fire();
//             wait(10, SC_NS);
//             RD.fire();
//             wait(10, SC_NS);
//             WR.fire();
//             wait(10, SC_NS);
//             PRE.fire();
//             wait(10, SC_NS);
//             ACT.fire();
//             sc_stop();
//         }
//     }
// };
// int sc_main(int, char**)
// {
//     // TODO
//     toplevel t("t");
//     sc_start();
//     return 0;
// }


/////////////Building Hierarchical PNs

SC_MODULE(toplevel){
    subnet s1,s2;
    
    place <1,1> IDLE;
    
    

    SC_CTOR(toplevel):s1("s1"),s2("s2"){

        IDLE.addTokens();
        IDLE.addTokens();

        s1.ACT.in.bind(IDLE);
        s1.PRE.out.bind(IDLE);

        s2.ACT.in.bind(IDLE);
        s2.PRE.out.bind(IDLE);

        SC_THREAD(process);

    
    }
    void process(){
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
int sc_main(int, char**)
{
    // TODO
    toplevel t("t");
    sc_start();
    return 0;
}
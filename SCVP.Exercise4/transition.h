#ifndef TRANSITION_H
#define TRANSITION_H

#include <systemc.h>
#include "place.h"
using namespace std;
// Transition:
// TODO
///////////////////////////////////////////////normallllllll////////////////////
// SC_MODULE(transition){
    
//     sc_port<placeInterface>in;
//     sc_port<placeInterface>out;
    

// SC_CTOR (transition){}
//     void fire(){
//         if(in->testTokens()>=1){
//             std::cout << this->name() << ": Fired" << std::endl;
//             in->removeTokens(1);
//             out->addTokens(1);
//         }else 
//             std::cout << this->name() << ": NOT Fired" << std::endl;

        
//     }
    
// };

// #endif // TRANSITION_H

// template<unsigned int N=1,unsigned int M=1>
// SC_MODULE(transition){
  
//     public:
//     sc_port<placeInterface, N, SC_ALL_BOUND> in;
//     sc_port<placeInterface, M, SC_ALL_BOUND> out;


// SC_CTOR (transition){}
//     void fire(){
//         bool flagtokensavailabe=true;
//         for(int i=0;i<N;i++){
//             if(in[i]->testTokens()<1)
//                 flagtokensavailabe=false;
//         }
//         if(flagtokensavailabe){
//             std::cout << this->name() << ": Fired" << std::endl;
//             for(int i=0;i<N;i++){
//                 in[i]->removeTokens(1);
//             }
//             for(int i=0;i<M;i++){
//                 out[i]->addTokens(1);
//             }
//         }else 
//             std::cout << this->name() << ": NOT Fired" << std::endl;

        
//     }
    
// };

// #endif // TRANSITION_H
///////////////////////////////for templated
// template<unsigned int N=1,unsigned int M=1>
// SC_MODULE(transition){
  
//     public:
//     sc_port<placeInterface, N, SC_ALL_BOUND> in;
//     sc_port<placeInterface, M, SC_ALL_BOUND> out;


// SC_CTOR (transition){}
//     void fire(){
//         bool flagtokensavailabe=true;
//         for(int i=0;i<N;i++){
//             if(!(in[i]->testTokens()))
//                 flagtokensavailabe=false;
//         }
//         if(flagtokensavailabe){
//             std::cout << this->name() << ": Fired" << std::endl;
//             for(int i=0;i<N;i++){
//                 in[i]->removeTokens();
//             }
//             for(int i=0;i<M;i++){
//                 out[i]->addTokens();
//             }
//         }else 
//             std::cout << this->name() << ": NOT Fired" << std::endl;

        
//     }
    
// };

// #endif // TRANSITION_H

///////////////////for Implementation of Inhibitor Arcs

template<unsigned int N=1, unsigned int M=1, unsigned int L=0>
SC_MODULE(transition){
  
    public:
    sc_port<placeInterface, N, SC_ALL_BOUND> in;
    sc_port<placeInterface, M, SC_ALL_BOUND> out;
    sc_port<placeInterface, L, SC_ZERO_OR_MORE_BOUND> inhibitors;

SC_CTOR (transition){}
    void fire(){
        bool no_inhibitors = true;
        for (int i = 0; i < L; i++)
        {
            if (inhibitors[i]->testTokens()==1)
                no_inhibitors=false;
        }

        bool flagtokensavailabe=true;
        for(int i=0;i<N;i++){
            if(!(in[i]->testTokens()))
                flagtokensavailabe=false;
        }
        if(flagtokensavailabe && no_inhibitors ){
            std::cout << this->name() << ": Fired" << std::endl;
            for(int i=0;i<N;i++){
                in[i]->removeTokens();
            }
            for(int i=0;i<M;i++){
                out[i]->addTokens();
            }
        }else 
            std::cout << this->name() << ": NOT Fired" << std::endl;

        
    }
    
};

#endif // TRANSITION_H
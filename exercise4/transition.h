#ifndef TRANSITION_H
#define TRANSITION_H
using namespace std;
#include <systemc.h>

#include "place.h"

// Transition:
// TODO

//template<unsigned int N = 1, unsigned int M = 1>  /// modification for multiple ports
template<unsigned int N=1, unsigned int M=1, unsigned int L=0>               ////Implementation of Inhibitor Arcs
SC_MODULE(transition){

    //sc_port<placeInterface>in;
    //sc_port<placeInterface>out;

    sc_port<placeInterface, N, SC_ALL_BOUND>in;    //modification for multiple ports
    sc_port<placeInterface, M, SC_ALL_BOUND>out;   //modification for multiple ports

    sc_port<placeInterface, L, SC_ZERO_OR_MORE_BOUND> inhibitors; ////Implementation of Inhibitor Arcs

    SC_CTOR(transition){}

    void fire(){

    /*    
        if (in->testTokens()>=1){
            cout << this->name() << ": Fired" << endl;
            in->removeTokens(1);
            out->addTokens(1);
        }else{
            
            cout << this->name() << ": NOT Fired" <<endl;
        }
    */ 
    //modification for multiport

    /*
        bool allinputs=false;
        for(int i=0;i<N; i++){
           if (in[i]->testTokens()>=1) 
            allinputs=true;
           else
           allinputs=false;
        }


        if (allinputs){
            cout << this->name() << ": Fired" << endl;
            for(int i=0;i<N; i++)
                //in[i]->removeTokens(1);
                in[i]->removeTokens(); // modification for templated channels
            for(int j=0;j<M;j++)
                //out[j]->addTokens(1);          
                out[j]->addTokens(); // modification for templated channels
        }
        else
            cout << this->name() << ": NOT Fired" <<endl;

    }
    */
   ///////////modification for Implementation of Inhibitor Arcs
   
        bool no_inhibitors = true;
        for (int i = 0; i < L; i++)
        {
            if (inhibitors[i]->testTokens()==1)
                no_inhibitors=false;
        }
        bool allinputs=false;
        for(int x=0;x<N; x++){
           if (in[x]->testTokens()>=1) 
            allinputs=true;
           else
           allinputs=false;
        }


        if (allinputs && no_inhibitors){
            cout << this->name() << ": Fired" << endl;
            for(int i=0;i<N; i++)
                //in[i]->removeTokens(1);
                in[i]->removeTokens(); // modification for templated channels
            for(int j=0;j<M;j++)
                //out[j]->addTokens(1);          
                out[j]->addTokens(); // modification for templated channels
        }
        else
            cout << this->name() << ": NOT Fired" <<endl;

    }


};

#endif // TRANSITION_H



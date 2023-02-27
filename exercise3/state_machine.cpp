#include <iostream>

#include "state_machine.h"



//stateMachine::base state;
   /*void stateMachine::process(){
        switch (state){
            case Start:
                switch (in.read()){
                    case 'A':
                        state=Start;
                        break;
                    case 'C':
                        state=Start;
                        break;
                    case 'T':
                        state=Start;
                        break;
                    case 'G':
                        state=G;
                        break;    
                }
                break;
            case G:
                switch (in.read()){
                    case 'A':
                        state=GA;
                        break;
                    case 'C':
                        state=Start;
                        break;
                    case 'T':
                        state=Start;
                        break;
                    case 'G':
                        state=G;
                        break;      
                }
                break;
            case GA:
                switch (in.read()){
                    case 'A':
                        state=GAA;
                        break;
                    case 'C':
                        state=Start;
                        break;
                    case 'T':
                        state=Start;
                        break;
                    case 'G':
                        state=G ;
                        break;     
                }
                break;
            case GAA:
                switch (in.read()){
                    case 'A':
                        state=Start;
                        break;
                    case 'C':
                        state=Start;
                        break;
                    case 'T':
                        state=Start;
                        break;
                    case 'G': cout<<"i was here"<<endl;cout<<sc_time_stamp()<<" "<<endl;
                        state=GAAG;
                        break;
                    }
                break;
            case GAAG: cout<<"i am here"<<endl;
                        cout<<sc_time_stamp()<<" "<<endl;
                switch (in.read()){
                    case 'A':
                        state=Start;
                        break;
                    case 'C':
                        state=Start;
                        break;
                    case 'T':
                        state=Start;
                        break;
                    case 'G':
                        state=G;
                        break;
                    }
                break;
            }

    */
    
    //second regex
    void stateMachine::process(){
        switch (state){
            case Start:counter++;
                switch (in.read()){
                    case 'A':
                        state=Start;
                        break;
                    case 'C':
                        state=Start;
                        break;
                    case 'T':
                        state=Start;
                        break;
                    case 'G':
                        state=G;
                        break;    
                }
                break;
            case G:
                switch (in.read()){
                    case 'A':
                        state=GA;
                        break;
                    case 'C':
                        state=Start;
                        break;
                    case 'T':
                        state=Start;
                        break;
                    case 'G':
                        state=G;
                        break;      
                }
                break;
            case GA:
                switch (in.read()){
                    case 'A':
                        state=GAA;
                        break;
                    case 'C':
                        state=Start;
                        break;
                    case 'T':
                        state=Start;
                        break;
                    case 'G':
                        state=G ;
                        break;     
                }
                break;
            case GAA:
                switch (in.read()){
                    case 'A':
                        state=GAA;
                        break;
                    case 'C':
                        state=Start;
                        break;
                    case 'T':
                        state=Start;
                        break;
                    case 'G': //cout<<"i was here"<<endl;cout<<sc_time_stamp()<<" "<<endl;
                        state=GAAG;
                        break;
                    }
                break;
            case GAAG: cout<<"i am here"<<"   counter ="<<counter<<endl;
                        cout<<sc_time_stamp()<<" "<<endl;
                switch (in.read()){
                    case 'A':
                        state=Start;
                        break;
                    case 'C':
                        state=Start;
                        break;
                    case 'T':
                        state=Start;
                        break;
                    case 'G':
                        state=G;
                        break;
                    }
                break;
            }

    
    
    
    
    
    }






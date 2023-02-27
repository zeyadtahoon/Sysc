#ifndef PLACE_H
#define PLACE_H

#include <systemc.h>

// Place Interface:
// TODO
using namespace std;

////////////////////for normal and multi ports
// class placeInterface:public sc_interface{
//     public:
//     virtual void addTokens(unsigned int n) = 0;
//     virtual void removeTokens(unsigned int n) = 0;
//     virtual unsigned int testTokens() = 0;
// };
// // Place Channel:
// // TODO
// class place:public placeInterface{
//     private :
//     unsigned int tokens;

//     public:
//     place(int tokens=0):tokens(tokens){

//     }
//     void addTokens(unsigned int n){
//         tokens+=n;
//     }
//     void removeTokens(unsigned int n){
//         tokens-=n;
//     }
//     unsigned int testTokens(){
//         return tokens;
//     }
// };

// #endif // PLACE_H
/////////////////////////////////// for templated 


class placeInterface:public sc_interface{
    public:
    virtual void addTokens() = 0;
    virtual void removeTokens() = 0;
    virtual bool testTokens() = 0;
};
// Place Channel:
// TODO
template<unsigned int Win = 1, unsigned int Wout = 1>
class place:public placeInterface{
    private :
    unsigned int tokens;

    public:
    place(int tokens=0):tokens(tokens){

    }
    void addTokens(){
        tokens+=Win;
    }
    void removeTokens( ){
        tokens-=Wout;
    }
    bool testTokens(){
        return tokens>=Wout;
    }
};

#endif // PLACE_H

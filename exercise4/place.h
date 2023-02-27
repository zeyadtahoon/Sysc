#ifndef PLACE_H
#define PLACE_H

#include <systemc.h>

class placeInterface:public sc_interface{

    public:
    // virtual void addTokens(unsigned int n) = 0;
    // virtual void removeTokens(unsigned int n) = 0;
    // virtual unsigned int testTokens() = 0;
    virtual void addTokens() = 0;
    virtual void removeTokens() = 0;
    virtual bool testTokens() = 0;
};
template<unsigned int Win = 1, unsigned int Wout = 1>
class place:public placeInterface{
    private :
    unsigned int tokens;

    public:

    place (unsigned int tokens=0): tokens(tokens){}

    // void addTokens(unsigned int n){
    //     tokens+=n;
    // }
    // void removeTokens(unsigned int n){
    //     tokens-=n;
    // }

    // unsigned int testTokens(){
    //         return tokens;
    // }
    //modification for teplated channel //////////////////////
    void addTokens(){
        tokens+=Win;
    }
    void removeTokens(){
        tokens-=Wout;
    }
    bool testTokens(){
        return tokens>=Wout;
    }

};

// Place Channel:
// TODO

#endif // PLACE_H

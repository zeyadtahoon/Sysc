#ifndef SUBNET_H
#define SUBNET_H

#include <systemc.h>

#include "place.h"
#include "transition.h"

// Subnet:
// TODO

SC_MODULE(subnet){

    transition <1,1,1>ACT{"ACT"};
    transition <1,1>PRE{"PRE"};
    transition <1,1>RD{"RD"};
    transition <1,1>WR{"WR"};

    place<1,1>ACTIVE;


    SC_CTOR(subnet){
        ACT.out.bind(ACTIVE);
        RD.in.bind(ACTIVE);
        RD.out.bind(ACTIVE);
        PRE.in.bind(ACTIVE);
        ACT.inhibitors(ACTIVE);
        WR.in.bind(ACTIVE);
        WR.out.bind(ACTIVE);

    }
};

#endif // SUBNET_H

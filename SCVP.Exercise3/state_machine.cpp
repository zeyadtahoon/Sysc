#include <iostream>

#include "state_machine.h"


stateMachine::base state;
int cnt;
int locater;
// void stateMachine::process(){
//     switch (state)
//     {
//     case Start:
//         state=(input.read()=='G'?G:Start);locater++;
//         break;
    
//     case G:
//         state=(input.read()=='A'?GA:(input.read()=='G'?G:Start));locater++;
//         break;

//     case GA:
//         state=(input.read()=='A'?GAA:(input.read()=='G'?G:Start));locater++;
//         break;

//     case GAA:
//         state=(input.read()=='G'?GAAG:Start);locater++;
//         break;

//     case GAAG:
//         state=(input.read()=='G'?G:Start);locater++;
//         cout<<"cnt =" <<cnt++<<endl;
//         cout<<"where =" <<locater<<endl;
//         break; 

//     default:
//         break;
//     }

// }
void stateMachine::process(){
    switch (state)
    {
    case Start:
        state=(input.read()=='G'?G:Start);locater++;
        break;
    
    case G:
        state=(input.read()=='A'?GA:(input.read()=='G'?G:Start));locater++;
        break;

    case GA:
        state=(input.read()=='A'?GAA:(input.read()=='G'?G:Start));locater++;
        break;

    case GAA:
        state=(input.read()=='G'?GAAG:(input.read()=='A'?GAA:Start));locater++;
        break;

    case GAAG:
        state=(input.read()=='G'?G:Start);locater++;
        cout<<"cnt =" <<cnt++<<endl;
        cout<<"where =" <<locater<<endl;
        break; 

    default:
        break;
    }
}
// TODO
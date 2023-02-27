#include <unistd.h>
#include <systemc.h>

#include "kpn.h"

template void kpn<unsigned int>::kpn_add();
template void kpn<unsigned int>::kpn_delay();
template void kpn<unsigned int>::kpn_spilt();


template<class T> void kpn<T>::kpn_add(){
        while (true){
            b.write( a.read() + c.read());
            
        }
}
template<class T> void  kpn<T>::kpn_spilt(){
        int temp;
        for (int i=0;i<10;i++){
            temp=b.read();
            a.write(temp);
            d.write(temp);
            e.write(temp);
            std::cout<<"e value::= "<<e.read()<<endl;
            
        }
        sc_stop();
    }
template<class T> void kpn<T>::kpn_delay(){
        while (true){
            c.write( d.read());
            
        }
    }

// ADD THINGS HERE

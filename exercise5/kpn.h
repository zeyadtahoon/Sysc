#ifndef KPN_H
#define KPN_H

#include <systemc.h>
template<class T>
SC_MODULE(kpn)
{
private:
    // ADD THINGS HERE
    sc_fifo<T>a,b,c,d;
    sc_signal<T> e;
    void kpn_add();
    void kpn_spilt();
    void kpn_delay();

public:
    SC_CTOR(kpn) :a(10),b(10),c(10),d(10),e("e",0)// : ADD THINGS HERE
    {   
        b.write(1);
        c.write(0);
        SC_THREAD(kpn_add);
        SC_THREAD(kpn_spilt);
        SC_THREAD(kpn_delay);
        


        sensitive << a.data_read_event() << a.data_written_event()
                  << b.data_read_event() << b.data_written_event()
                  << c.data_read_event() << c.data_written_event()
                  << d.data_read_event() << d.data_written_event();

        // ADD THINGS HERE
    }
};
#endif // KPN_H
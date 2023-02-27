#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <tlm.h>
#include <systemc.h>
template<int size=1024>
class memory:public sc_module,tlm::tlm_fw_transport_if<>{

    private:
    unsigned int mem[1024];

    public:
    tlm::tlm_target_socket<>tSocket;

    SC_CTOR(memory){
        tSocket.bind(*this);

    }



    void b_transport(tlm::tlm_generic_payload &trans, sc_time &delay)
    {
        if(trans.get_address() >= 1024){
            SC_REPORT_FATAL(this->name(),"Out of Range");
        }


    
        if(trans.get_command() == tlm::TLM_WRITE_COMMAND)
            {
                memcpy(&mem[trans.get_address()], // destination
                    trans.get_data_ptr(),      // source
                    trans.get_data_length());  // size
            }
            else // (trans.get_command() == tlm::TLM_READ_COMMAND)
            {
                memcpy(trans.get_data_ptr(),      // destination
                    &mem[trans.get_address()], // source
                    trans.get_data_length());  // size
            }

            delay = delay + sc_time(40, SC_NS);

            trans.set_response_status( tlm::TLM_OK_RESPONSE );
    }


    

    // Dummy method
    virtual tlm::tlm_sync_enum nb_transport_fw(
            tlm::tlm_generic_payload& trans,
            tlm::tlm_phase& phase,
            sc_time& delay )
    {
        SC_REPORT_FATAL(this->name(),"nb_transport_fw is not implemented");
        return tlm::TLM_ACCEPTED;
    }

    // Dummy method
    bool get_direct_mem_ptr(tlm::tlm_generic_payload& trans,
                            tlm::tlm_dmi& dmi_data)
    {
        SC_REPORT_FATAL(this->name(),"get_direct_mem_ptr is not implemented");
        return false;
    }

    // Dummy method
    unsigned int transport_dbg(tlm::tlm_generic_payload& trans)
    {
        SC_REPORT_FATAL(this->name(),"transport_dbg is not implemented");
        return 0;
    }


};
// TODO: add your code here

#endif // MEMORY_H

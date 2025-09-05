#include <systemc.h>
#include "mac.h"
#include "stimulus.h"
#include "monitor.h"

SC_MODULE(Top){
    sc_signal<int> top_a, top_b, top_c, top_o;

    Stimulus* stim;
    MAC* mac;
    Monitor* mon;

    sc_trace_file* tf;

    SC_CTOR(Top){

        //create modules
        stim = new Stimulus("stim");
        mac = new MAC("mac");
        mon = new Monitor("mon");

        //connect ports to signals
        stim->a(top_a);
        stim->b(top_b);
        stim->c(top_c);

        mac->a(top_a);
        mac->b(top_b);
        mac->c(top_c);
        mac->o(top_o);

        mon->o(top_o);
        mon->a(top_a);
        mon->b(top_b);
        mon->c(top_c);

        tf = sc_create_vcd_trace_file("../trace/trace_file");
        tf->set_time_unit(1, SC_NS);
        sc_trace(tf, top_a, "top_a");
        sc_trace(tf, top_b, "top_b");
        sc_trace(tf, top_c, "top_c");
        sc_trace(tf, top_o, "top_o");
    }

    //delete modules and close trace file when done
    ~Top(){
        delete stim;
        delete mac;
        delete mon;
        sc_close_vcd_trace_file(tf);
    }
};
#include <systemc.h>
#include "mac.h"
#include "stimulus.h"
#include "monitor.h"

SC_MODULE(Top){
    sc_signal<int> top_a, top_b, top_c, top_o;

    Stimulus* stim;
    MAC* mac;
    Monitor* mon;

    SC_CTOR(Top){

        stim = new Stimulus("stim");
        mac = new MAC("mac");
        mon = new Monitor("mon");

        stim->a(top_a);
        stim->b(top_b);
        stim->c(top_c);

        mac->a(top_a);
        mac->b(top_b);
        mac->c(top_c);
        mac->o(top_o);

        mon->o(top_o);
    }

    ~Top(){
        delete stim;
        delete mac;
        delete mon;
    }
};
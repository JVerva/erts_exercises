#include <systemc.h>

SC_MODULE(Stimulus){
    sc_out<int> a, b, c;

    SC_CTOR(Stimulus){
        SC_THREAD(stimuli);
    }

    void stimuli();
};
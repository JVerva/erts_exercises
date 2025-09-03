#include <iostream>
#include "systemc.h"

SC_MODULE(MAC){
    sc_in<int> a, b, c;
    sc_out<int> o;
    
    sc_signal<int> x;

    SC_CTOR(MAC){
        SC_THREAD(multiply);
        sensitive << a << b;
        SC_THREAD(add);
        sensitive << x;
    }

    void multiply();
    void add();
}
;
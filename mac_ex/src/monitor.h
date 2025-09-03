#include <systemc.h>

SC_MODULE(Monitor){
    sc_in<int> o;
    
    SC_CTOR(Monitor){
        SC_THREAD(print);
        sensitive << o;
    }

    void print(){
        while(true){
            wait();
            std::cout << "Output: " << o.read() << std::endl;
        }
    }
};
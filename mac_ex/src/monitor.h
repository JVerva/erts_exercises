#include <systemc.h>

SC_MODULE(Monitor){
    sc_in<int> a;
    sc_in<int> b;
    sc_in<int> c;
    sc_in<int> o;

    sc_event ready;
    
    SC_CTOR(Monitor){
        SC_THREAD(print_a);
        sensitive << a;
        SC_THREAD(print_b);
        sensitive << b;
        SC_THREAD(print_c);
        sensitive << c;
        SC_THREAD(print_o);
        sensitive << o;
        SC_THREAD(check);
        sensitive << ready;
    }

    void print_o(){
        while(true){
            wait();
            std::cout << "Output: " << o.read() << std::endl;
            ready.notify();
        }
    }

    void print_a(){
        while(true){
            wait();
            std::cout << "Input A: " << a.read() << std::endl;
        }
    }

    void print_b(){
        while(true){
            wait();
            std::cout << "Input B: " << b.read() << std::endl;
        }
    }

    void print_c(){
        while(true){
            wait();
            std::cout << "Input C: " << c.read() << std::endl;
        }
    }

    void check(){
        while(true){
            wait();
            if(o.read() != (a.read() * b.read() + c.read())){
                std::cout << "Error: Output does not match AND of inputs!" << std::endl;
            }else{
                std::cout << "Output is correct." << std::endl;
            }
        }
    }
};
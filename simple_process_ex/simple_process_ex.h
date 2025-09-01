#ifndef SIMPLE_PROCESS_EX_H
#define SIMPLE_PROCESS_EX_H
#include <systemc.h>

SC_MODULE(simple_process_ex) {
  
  SC_CTOR(simple_process_ex) {
    SC_THREAD(my_thread_process);
    SC_THREAD(clock);
    SC_METHOD(counter);
      sensitive << clk.posedge_event();
  }

  sc_signal<sc_logic> clk;
  sc_signal<int> count;

  void my_thread_process(void);
  void clock(void);
  void counter(void);
};
#endif

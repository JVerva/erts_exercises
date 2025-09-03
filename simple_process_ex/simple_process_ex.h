#ifndef SIMPLE_PROCESS_EX_H
#define SIMPLE_PROCESS_EX_H
#include <systemc.h>

SC_MODULE(simple_process_ex) {
  
  // Ports and signals
  sc_fifo<int> fifo;
  sc_signal<sc_logic> clk;
  sc_signal<int> count;
  
  SC_CTOR(simple_process_ex) {
    SC_THREAD(my_thread_process);
    SC_THREAD(clock);
    SC_METHOD(counter);
      sensitive << clk.posedge_event();
      dont_initialize();
    SC_THREAD(sender);
    SC_THREAD(printer);
  }

  // Process declarations
  void my_thread_process(void);
  void clock(void);
  void counter(void);
  void sender(void);
  void printer(void);
};
#endif

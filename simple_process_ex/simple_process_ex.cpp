#include "simple_process_ex.h"
void simple_process_ex::my_thread_process(void) {
  std::cout << "my_thread_process executed within "
            << name() 
            << std::endl;
}

void simple_process_ex::clock(void) {
  while (true) {
    clk.write(SC_LOGIC_0);
    wait(5, SC_NS);
    clk.write(SC_LOGIC_1);
    wait(5, SC_NS);
  }
}

void simple_process_ex::counter(void) {
  count.write(count.read() + 1);
}

void simple_process_ex::sender(void) {
  while (true)
  {
    fifo.write(count.read());
    wait(10, SC_NS);
  }
}

void simple_process_ex::printer(void) {
  while (true)
  {
      std::cout << "Counter value: " << fifo.read() << " at simulation time: " << sc_time_stamp() <<std::endl;
  }
}

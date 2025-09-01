#include "simple_process_ex.h"
void simple_process_ex::my_thread_process(void) {
  std::cout << "my_thread_process executed within "
            << name() 
            << std::endl;
}

void simple_process_ex::clock(void) {
  while (true) {
    wait(0.5, SC_SEC);
    clk.write(SC_LOGIC_0);
    cout << "Clock tick at: " << sc_time_stamp() << std::endl;
    wait(0.5, SC_SEC);
    clk.write(SC_LOGIC_1);
  }
}

void simple_process_ex::counter(void) {
  count.write(count.read() + 1);
  std::cout << "Counter value: " << count.read() << std::endl;
}

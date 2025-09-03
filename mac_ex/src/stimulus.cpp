#include "stimulus.h"

void Stimulus::stimuli(){
    a.write(2);
    b.write(3);
    c.write(4);
    wait(10, SC_NS);

    a.write(5);
    b.write(6);
    c.write(7);
    wait(10, SC_NS);

    a.write(8);
    b.write(9);
    c.write(10);
    wait(10, SC_NS);

    sc_stop();
}
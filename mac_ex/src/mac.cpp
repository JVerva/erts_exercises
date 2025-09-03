#include "mac.h"

void MAC::multiply(){
    while(true){
        wait();
        x.write(a.read() * b.read());
    }
}

void MAC::add(){
    while(true){
        wait();
        o.write(x.read() + c.read());
    }
}
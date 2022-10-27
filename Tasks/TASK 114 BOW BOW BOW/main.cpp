#include "mbed.h"
#include <cstdio>


// main() runs in its own thread in the OS

DigitalOut red(PC_2,1);
DigitalOut amber(PC_3,1);
DigitalOut green(PC_6,1);


void RedLight() {
    red = 1;
    amber = 0; 
    green = 0;
    wait_us(2000000); 
}

void AmberLight() {
    red = 1;
    amber = 1; 
    green = 0;
    wait_us(2000000); 
}
void GreenLight() {
    red = 0;
    amber = 0; 
    green = 1;
    wait_us(2000000); 
}

void AmberFlash(){
    red = 0;
    green = 0;
     int count = 0;
     
    while(count < 4) {
     count = count + 1;
    amber = !amber;
    printf("boow");
    wait_us(2000000);
    } 
    count = 0;
    wait_us(2000000);
}
int main()
{
    while (true) {
    RedLight();
    AmberLight();
    GreenLight();
    AmberFlash();
    }
}


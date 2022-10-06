// You need this to use the Module Support Board
#include "uop_msb.h"
using namespace uop_msb;

#define WAIT_TIME_MS 250 * 1000
int dotTime = 150 * 1000;
int DashTime = 450 * 1000;
DigitalOut greenLED(TRAF_GRN1_PIN);
Buzzer buzz;
Buttons buttons;

// TIP: (I suggest you read this!)
//
// Press the black reset button to restart the code (and stop the sound)
// Otherwise, the noise can be "distracting" :)
void Dot(){
    buzz.playTone("C");
    greenLED = 1;
   wait_us(dotTime); 
    buzz.rest();
    greenLED = 0;
}

void Dash(){
    buzz.playTone("B");
    greenLED = 1;
   wait_us(DashTime); 
    buzz.rest();
    greenLED = 0;
}

void wordSpace()
{
    wait_us(dotTime * 6); 
}

void LetterSpace()
{
    wait_us(dotTime * 3); 
}

void SymbolSpace()
{
    wait_us(dotTime); 
}

void S() {
    Dot();
    SymbolSpace();
    Dot();
    SymbolSpace();
    Dot();
    LetterSpace();
}


void O() {
    Dash();
     SymbolSpace();
    Dash();
     SymbolSpace();
    Dash();
    LetterSpace();
}

int main()
{
    //Wait for the BLUE button to be pressed (otherwise this becomes super annoying!)

    
    //Repeat everything "forever" (until the power is removed or the chip is reset)
     while (true)
    {
        if (buttons.BlueButton == 1) {
          S();
          O();
          S();
        wordSpace();
        }
      
    }
    while (false)
    {
        //On for 500ms
        greenLED = 1;
        buzz.playTone("C");
        wait_us(WAIT_TIME_MS);
        buzz.playTone("D");
        wait_us(WAIT_TIME_MS);
        buzz.playTone("E");
        wait_us(WAIT_TIME_MS);
        buzz.playTone("F");
        wait_us(WAIT_TIME_MS);
        buzz.playTone("A");
        wait_us(WAIT_TIME_MS);
        buzz.playTone("B");
        wait_us(WAIT_TIME_MS);
        buzz.playTone("C");
        wait_us(WAIT_TIME_MS);  //500ms


        //Off for 500ms
        greenLED = 0;
        buzz.playTone("C", Buzzer::HIGHER_OCTAVE);
        wait_us(WAIT_TIME_MS);  //500ms

        //Pause
        buzz.rest();
        wait_us(WAIT_TIME_MS);

    }
    
}
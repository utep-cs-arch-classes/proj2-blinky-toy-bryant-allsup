#include <msp430.h>
#include "led.h"
#include "switches.h"

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
  led_update();
}

void led_update(){
  if (switch_state_changed) {
    char ledFlags = 0; /* by default, no LEDs on */
    
    //       or      (1/0)            Translation to bellow:led flags gets green or red
    
    ledFlags |= switch_state_down ? LED_GREEN : 0; //true or false is true green else false
    ledFlags |= switch_state_down ? 0 : LED_RED; // if false red

    //       subtracts ones from leds in order to show 
    
    P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags;         // set bits for on leds
  }
  switch_state_changed = 0;
}


#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachines.h"

char switch1, switch2, switch3, switch4, switch_state_changed; /* effectively boolean */

int state; //should be a global variable for everything that #includes switches.h

//changing p1 to p2 ar the ports for the lauchboard buttons
static char 
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */ //activate switches
  P2IE |= SWITCHES;		/* enable interrupts from switches */ // enable interrupts
  P2OUT |= SWITCHES;		/* pull-ups for switches */ //able to turn on
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */ //able to turn off swithces
  switch_update_interrupt_sense();
  //led_update();
  state=3;
  state_advance();
}

void
switch_interrupt_handler() //Starting point of interrupt
{
  //Can multiple switches be active at once?
  char p2val = switch_update_interrupt_sense();

  //if this is basically an if statement can I do more?
  switch1 = (p2val & SW1) ? 0 : 1; /* 0 when SW1 is up */
  switch2 = (p2val & SW2) ? 0 : 1; //if s2 then true else false
  switch3 = (p2val & SW3) ? 0 : 1; //cannot assign state = # on the same line side
  switch4 = (p2val & SW4) ? 0 : 1; 


  if(switch1)
    {state = 1;}
  if(switch2)
    {state = 2;}
  if(switch3)
    {state = 3;}
  if(switch4)
    {state = 4;}
  //if switches 0-3 switch 1 sets red off, switch 2 red on
  //if switches 1-4 switch 1 sets all off, switch 2 green on and switch 3 green and red on 
  //switch_state_changed = 1; not in use like in button demo
  state_advance(); //could move back to not check all switches
}

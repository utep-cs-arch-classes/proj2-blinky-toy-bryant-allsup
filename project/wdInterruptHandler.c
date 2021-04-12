#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;

  switch(state){
  case 1:
    {//calls();
    }
    break;
  case 2:
    if(++blink_count==125)
      {bright();}
    break;
  case 3:
    {
      if(++blink_count==125)
	{bright();}
    }
    break;
  case 4:
    {}
    break;
  }
  state_advance();
}



//3/31 1:14:00 Goes over blinking

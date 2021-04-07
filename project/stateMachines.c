#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"



void state_advance()		/* alternate between toggling red & green */
{
  
  char changed = 0;  


  switch(state)
    {
    case 1 :
      green_on = 0;
      red_on = 0;
      changed = 1; 
      break;
    case 2:
      green_on = 0;
      red_on = 1;
      changed = 1;
      break;
    case 3:
      green_on = 1;
      red_on = 0;
      changed = 1;
      break;
    case 4:
      green_on = 1;
      red_on = 1;
      changed = 1;
      break;
    }
  
  
  led_changed = changed;
  led_update();
}




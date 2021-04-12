#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "state.s"


char count = 0;
static enum{off=0,dim=1,on=2}brightness;
int sound = 1000;

void bright()
{brightness = (brightness+1)%3;}

void counter()
{count = (count+1)%3;}

void state_advance()		/* alternate between toggling red & green */
{
  char changed = 0; 

  switch(state)
    {
    case 1 :
      case_one();
      changed=1;
      break;
    case 2:
      case_two();
      changed=1;
      break;
    case 3:
      case_three();
      changed=1;
      break;
    case 4:
      case_four();
      changed=1;
      break;
    }
  
  
  led_changed = changed;
  led_update();
}

void case_one()
{
  green_on = 0;
  red_on=0;
  buzzer_set_period(0);
}
void case_two()
{
  counter();
  green_on=0;
  red_on=(count<1);
  sound=1000;
  buzzer_set_period(sound);
}
void case_three()
{
  counter();
  green_on=(count<1);
  red_on=0;
  sound+=100;
  buzzer_set_period(sound);
}
void case_four()
{
  green_on = 1;
  red_on=1;
  sound-=100;
  buzzer_set_period(sound);
}

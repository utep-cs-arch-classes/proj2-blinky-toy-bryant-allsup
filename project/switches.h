#ifndef switches_included
#define switches_included

#define SW1 BIT0  //switch1 is p2.0  
#define SW2 BIT1  //1
#define SW3 BIT2  //4
#define SW4 BIT3  //8


#define SWITCHES (SW1|SW2|SW3|SW4)		/* only 1 switch on this board */



void switch_init();
void switch_interrupt_handler();

extern char switch1, switch2, switch3, switch4, switch_state_changed; /* effectively boolean */
extern int state;

#endif // included

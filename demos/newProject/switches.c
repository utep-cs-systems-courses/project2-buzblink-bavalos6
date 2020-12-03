#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachineBuzz.h"

char switch_state_down, switch_state_changed; /* effectively boolean */
char s_1, s_2, s_3, s_4; //Switches 

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
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  led_update();
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  s_1 = (p2val & SW1) ? 0:1;
  s_2 = (p2val & SW2) ? 0:1;
  s_3 = (p2val & SW3) ? 0:1;
  s_4 = (p2val & SW4) ? 0:1;
  switch_state_down = (s_1 || s_2 || s_3 || s_4);
  switch_state_changed = 1;
  buttonBuzzer();
  led_update();
}


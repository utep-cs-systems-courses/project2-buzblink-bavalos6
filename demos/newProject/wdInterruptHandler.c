#include <msp430.h>
#include "stateMachines.h"
#include "stateMachineBuzz.h"
#include "buzzer.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  if (++blink_count == 50 && (i <= 17 )) {
    buzzer_play_sound();
    i++;
    blink_count = 0;
  }
  if(i<17 && i>0){
    dim();
  }
}

#include <msp430.h>
#include "stateMachineBuzz.h"
#include "buzzer.h"
#include "switches.h"

void buttonBuzzer(){
  if(s_1){
    arreglo = &ruidosLocos[0];
  }
  else if(s_2){
    arreglo = &ruidosLocos2[0];
  }
  else if(s_3){
    arreglo = &ruidosLocos3[0];
  }
  else if(s_4){
    arreglo = &ruidosLocos4[0];
  }
}

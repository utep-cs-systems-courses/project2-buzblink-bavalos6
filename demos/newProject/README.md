## Description of Lab 2
Lab 2 consists in state machines programmed to make the switches play
different songs depending on the state we are located on. When a song is being
played the green led will flash and will dim while the song is being played
and right when the song ends the green led will turn off and red led wil turn on.

File    | Description
------- | -----------
Buzzer  | Stores arrays with notes (array = song) for each switch and has iterates through each note 
Button  | Uses interrupts to detect when a switch is pressed or released.
Buzzer  | Emits a single continuous note from the buzzer.

## How to Use

The Makefile in this direcory contains rules to run the Makefile in each demo directory. Use **make** in this directory to build all demo programs and the timer library. Once the programs are built, you can load the program onto the MSP430 by changing into the corresponding demo directory and using **make load**.

You may use **mspdebug rf2500 "erase"** to clear a program from the MSP430.

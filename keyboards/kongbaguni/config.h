#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0000
#define DEVICE_VER      0x0003
#define MANUFACTURER    kongbaguni
#define PRODUCT         42key
#define DESCRIPTION     42key handwired keyboard

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
*/
// https://deskthority.net/wiki/Arduino_Pro_Micro#Pinout 참고할것.
/* 
Pro MICRO

    D3	==|	|==	RAW (+5V from USB)
    D2  |	  |	GND
   GND	|	  |	Reset
   GND	|	  |	Vcc (+3V*)
    D1	|	  |	F4	
    D0	|	  |	F5	
    D4	|	  |	F6	
    C6	|	  |	F7	
    D7	|	  |	B1	        
    E6	|	  |	B3
    B4	|	  |	B2	
    B5	|=====|	B6

 Proton C
 5V ======|  |=======	A9
GNF |		 		|	A10
DFU | A3  5v D- D+	|	GND
3.3V|		 		|	GND
A2	|	*   * * *	|	B7      // BOOTO A3 C15 C14
A1 	|		 		|	B6
A0  |		 		|	B5
B8	|		 		|	B4
B13 |		 	C13	|	B3
B14 |		 		|	B2
B15 |		 		|	B1
B9	|A14 A13 	RST	|	B0  	

B10 |===============|	A4
B11 |				|	A5
B12 | 				|	A6
A14 |				|	A7
A13 |				|	A8
RST |===============|	A15

Encoder

D3		--####--  B2 ZZ
GND		--####
D2 		--####--  D4 |<-DIOD
*/ 	 
#define MATRIX_ROW_PINS { B5, B6, B4, B2 }
#define MATRIX_COL_PINS { E6, D7, C6, D4, D0, D1, F4, F5, F6, F7, B1, B3 }

#define ENCODERS_PAD_A { D3 }
#define ENCODERS_PAD_B { D2 }
#define ENCODER_RESOLUTION 1

#define UNUSED_PINS

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define TAPPING_TERM 200

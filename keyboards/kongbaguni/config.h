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
#define MATRIX_ROWS 5
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

 

*/ 	

#define MATRIX_COL_PINS { C6, D7, E6, B4, B5, B6, B2, B3, B1, F7, F6, F5 }
#define MATRIX_ROW_PINS { D3, D2, D1, D0, D4 }

#define ENCODERS_PAD_A { B3, B4 }
#define ENCODERS_PAD_B { C6, C7 }
#define ENCODER_RESOLUTION 4

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

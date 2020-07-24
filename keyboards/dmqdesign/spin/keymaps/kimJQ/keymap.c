/* Copyright 2019-2020 DMQ Design
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "midi.h"
#include "qmk_midi.h"
#define ________ KC_TRNS
#define xxxxxxxx KC_NO

#define K_COPY LCTL(KC_C)

enum layers
{
  _BL,
  _FL,
  _TL
};

enum custom_keycodes {
  // xxxxxxxx,
  MECRO_01 = 3,
  MECRO_02,
  MECRO_03,
  MECRO_04
};

uint8_t currentLayer;

//The below layers are intentionally empty in order to give a good starting point for how to configure multiple layers.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BL] = LAYOUT(/* Base */
                KC_KP_7, KC_KP_8, KC_KP_9, TO(_BL),
                KC_KP_4, KC_KP_5, KC_KP_6, TO(_FL),
                KC_KP_1, KC_KP_2, KC_KP_3, TO(_TL),
                KC_KP_0, KC_DOT,  KC_COMM
                ),

    [_FL] = LAYOUT(/* Base */
                K_COPY,   KC_LPRN,   KC_RPRN,    ________,
                KC_MINS,  KC_SLSH,   KC_DOT,    ________,
                xxxxxxxx, KC_UP,     xxxxxxxx,  ________,
                KC_LEFT,  KC_DOWN,   KC_RIGHT
                ),

    [_TL] = LAYOUT(/* Base */
                K_COPY,   MECRO_01, MECRO_02, ________,
                MECRO_03, KC_F2,    KC_F3,     ________,
                KC_F4,    KC_UP,    MECRO_04,   ________,
                KC_LEFT,  KC_DOWN,  KC_RIGHT
                )
};

void encoder_update_user(uint8_t index, bool clockwise) {
   switch (index) {
       case 0:
       if (clockwise) {
         rgblight_increase();
       } else {
         rgblight_toggle();
       }
       break ;

       case 1:
       if (clockwise) {
         tap_code(KC_VOLU);
       } else {
         tap_code(KC_VOLD);
        }
       break ;

       case 2:
       if (clockwise) {
          register_code(KC_LCTL);
          tap_code(KC_F12);
          unregister_code(KC_LCTL);
       } else {
          tap_code(KC_F12);
       }
       break ;
   }
   
}

layer_state_t layer_state_set_user(layer_state_t state) { //This will run every time the layer is updated
    currentLayer = get_highest_layer(state);

    switch (currentLayer) {
        case _BL:
            setrgb(RGB_WHITE, &led[0]); //Set the top LED to white for the bottom layer
            setrgb(0, 0, 0, &led[1]);
            setrgb(0, 0, 0, &led[2]);
            break;
        case _FL:
            setrgb(0, 0, 0, &led[0]); //Set the middle LED to white for the middle layer
            setrgb(RGB_WHITE, &led[1]);
            setrgb(0, 0, 0, &led[2]);
            break;
        case _TL:
            setrgb(0, 0, 0, &led[0]);
            setrgb(0, 0, 0, &led[1]);
            setrgb(RGB_WHITE, &led[2]); //Set the bottom LED to white for the top layer
            break;
    }
    rgblight_set();
    return state;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
 
  switch (keycode) {
    // 붙여넣기 직후 백스페이스 두번 직후 F2
    case MECRO_01:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("v") "\b\b" SS_DELAY(100));  
        tap_code(KC_F2);
      } else {
      }
      return false;
    //0 입력 직후 엔터
     case MECRO_02:
      if (record->event.pressed) {
        SEND_STRING("0\n");
      } else {
      }
      return false;
      // 붙여넣기 후 백스페이스 한번 뒤 엔터
     case MECRO_03:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("v") "\b\n");  
      } else {
      }
      return false;

     case MECRO_04:
      if (record->event.pressed) {
        SEND_STRING("=");
        tap_code(KC_UP);
        SEND_STRING("+");
        tap_code(KC_LEFT);
        tap_code(KC_LEFT);
        SEND_STRING("-");
        tap_code(KC_LEFT);
      } else {
        
      }
      return false;

  }
     
  return true;
}


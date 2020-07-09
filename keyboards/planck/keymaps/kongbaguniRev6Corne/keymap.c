#include "planck.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_uk.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _MAC,
  _LOWER,
  _MLWR,
  _RAISE,
  _MRSE,
  _FUNC,
  _MFNC,
  _FUNC2,
  _MFNC2,
  _ADJUST,
  _MOUSE
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  MAC,
  FUNC,
  MFNC,
  FUNC2,
  MFNC2,
  LOWER,
  MLWR,
  RAISE,
  MRSE,
  MOUSE,
  DYNAMIC_MACRO_RANGE
};

#include "dynamic_macro.h"

#define TAB MT(MOD_LCTL,KC_TAB)

#define RSHFT MT(MOD_RSFT, KC_ENT)

#define M1START DYN_REC_START1
#define M1_PLAY DYN_MACRO_PLAY1

#define M2START DYN_REC_START1
#define M2_PLAY DYN_MACRO_PLAY1

#define MACSTOP DYN_REC_STOP

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_QWERTY] = LAYOUT_planck_grid(
  KC_ESC,     KC_Q,       KC_W,        KC_E,      KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,      KC_O,      KC_P,       KC_BSPC,
  TAB    ,    KC_A,       KC_S,        KC_D,      KC_F,    KC_G,    KC_H,    KC_J,    KC_K,      KC_L,      KC_SCLN,    KC_QUOT,
  KC_LSFT,    KC_Z,       KC_X,        KC_C,      KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,   KC_DOT,    KC_SLSH,    RSHFT,
  XXXXXXX,    XXXXXXX,    XXXXXXX,     KC_LGUI,   LOWER,   KC_SPC , KC_SPC,  RAISE,   KC_RALT,   XXXXXXX,   XXXXXXX,    XXXXXXX
),


[_FUNC] = LAYOUT_planck_grid(
  XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,  KC_DEL,
  XXXXXXX, KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, KC_PAUS, KC_INS,   KC_HOME,  KC_END,   KC_PGUP, KC_PGDN, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
  _______, _______, _______, _______, _______, _______, _______,  MO(_MOUSE), _______, _______, _______, _______
),

[_LOWER] = LAYOUT_planck_grid(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_PERC,   KC_CIRC,    KC_AMPR,    KC_ASTR,      KC_LPRN,   KC_RPRN,     KC_PIPE,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_MINS,    KC_EQL,     KC_LCBR,      KC_RCBR,   KC_PIPE,     KC_GRV,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_UNDS,    KC_PLUS,    KC_LBRC,      KC_RBRC,   KC_BSLS,     KC_TILD,
  XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_BSPC,   KC_DEL,     _______,    _______,      XXXXXXX,   XXXXXXX,     XXXXXXX
),


[_RAISE] = LAYOUT_planck_grid(
  KC_GRV,       KC_1,    KC_2,     KC_3,     KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_BSLS,
  _______,      KC_F6,   KC_F7,    KC_F8,    KC_F9,   KC_F10,  XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, XXXXXXX, 
  _______,      KC_F11,  KC_F12,   XXXXXXX,  XXXXXXX, KC_MS_BTN1, KC_MS_BTN2, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, _______,
  XXXXXXX,      XXXXXXX, XXXXXXX,  _______,  _______, KC_ENT, KC_ENT,  _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
), 


[_ADJUST] = LAYOUT_planck_grid(
  KC_PWR,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, M1START,  M2START,   XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  RESET,
  RGB_TOG,  RGB_MOD, RGB_RMOD,XXXXXXX, XXXXXXX, MACSTOP,  MACSTOP,   XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,
  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, M1_PLAY,  M2_PLAY,   XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,
  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX
),


[_MOUSE] = LAYOUT_planck_grid(
    KC_ESC ,      _______,      _______,      _______, _______, _______,   _______, _______,     _______,     _______,     _______, _______,
    KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, _______, _______, _______,   _______, KC_MS_BTN4, KC_MS_BTN1,  KC_MS_UP,   KC_MS_BTN2, KC_MS_BTN5, 
    KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, _______, _______, _______,   _______, _______, KC_MS_LEFT,  KC_MS_DOWN, KC_MS_RIGHT,  _______, 
    _______,      _______,      _______,      _______, _______, _______,   _______, _______,     _______,    _______,      _______, _______
),


[_FUNC2] = LAYOUT_planck_grid(
    _______,  _______,    M(1),       _______,    _______,    _______, M(5),    _______, _______, _______, _______, _______,
    _______,  _______,    M(3),       M(7),       _______,    _______, _______, M(10),   _______, _______, _______, _______,
    _______,  LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), _______, _______, _______, _______, _______, _______, M(98)  ,
    _______,  _______,    _______,    _______,    _______,    _______, _______, _______, _______, _______, _______, _______
),

[_MAC] = LAYOUT_planck_grid(
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    MFNC,     _______, _______, _______, MLWR,    _______, _______, MRSE,    _______, _______, _______, MFNC2
),

[_MLWR] = LAYOUT_planck_grid(
    _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_MRSE] = LAYOUT_planck_grid(
    _______,  _______,  M(2),    _______, _______, _______, _______,       _______,    _______, _______,    _______,        _______,
    _______,  _______,  _______, _______, _______, _______, _______,       LCTL(KC_A), _______, LCTL(KC_E), _______,        LGUI(KC_EQL),
    _______,  _______,  _______, _______, _______, _______, LALT(KC_LEFT), _______,    _______, _______,    LALT(KC_RIGHT), LGUI(KC_MINS),
    _______,  _______,  _______, _______, _______, _______, _______,       _______,    _______, _______,    _______,        _______
),

[_MFNC]= LAYOUT_planck_grid(
    _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, LGUI(KC_PENT),
    _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_MFNC2] = LAYOUT_planck_grid(
    _______,  _______,    M(2),       _______,    _______,    _______, M(6),    _______, _______, _______, _______, _______,
    _______,  _______,    M(4),       M(8),       _______,    _______, _______, M(10),   _______, _______, _______, _______,
    _______,  LGUI(KC_Z), LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), _______, _______, _______, _______, _______, _______, M(99)  ,
    _______,  _______,    _______,    _______,    _______,    _______, _______, _______, _______, _______, _______, _______
)

};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  if (!process_record_dynamic_macro(keycode, record)) {
      return false;
  }

   switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case MLWR:
      if (record->event.pressed) {
        layer_on(_LOWER);
        layer_on(_MLWR);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        layer_off(_MLWR);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case MRSE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        layer_on(_MRSE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        layer_off(_MRSE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case MFNC:
      if (record->event.pressed) {
        layer_on(_FUNC);
        layer_on(_MFNC);
      } else {
        layer_off(_FUNC);
        layer_off(_MFNC);
      }
      return false;
    case MFNC2:
      if (record->event.pressed) {
        layer_on(_FUNC2);
        layer_on(_MFNC2);
      } else {
        layer_off(_FUNC2);
        layer_off(_MFNC2);
      }
      return false;
    }
  return true;
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t keycode, uint8_t opt) {
  // These would trigger when you hit a key mapped as M(0)
  if (record->event.pressed) {
    switch(keycode) {
      case 0: // Some custom string here
        SEND_STRING("");
        return false;

      case 1: // Word Select
        SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_RIGHT) SS_DOWN(X_LSHIFT) SS_TAP(X_LEFT) SS_UP(X_LSHIFT) SS_UP(X_LCTRL));
        return false;

      case 2: // Word Select Mac
        SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_RIGHT) SS_DOWN(X_LSHIFT) SS_TAP(X_LEFT) SS_UP(X_LSHIFT) SS_UP(X_LALT));
        return false;

      case 3: // Line Select
        SEND_STRING(SS_TAP(X_HOME) SS_DOWN(X_LSHIFT) SS_TAP(X_END) SS_UP(X_LSHIFT));
        return false;

      case 4: // Line Select Mac
        SEND_STRING(SS_LCTRL("a") SS_DOWN(X_LSHIFT) SS_LCTRL("e") SS_UP(X_LSHIFT));
        return false;

      case 5: // Line Delete
        SEND_STRING(SS_TAP(X_HOME) SS_DOWN(X_LSHIFT) SS_TAP(X_END) SS_UP(X_LSHIFT));
        SEND_STRING(SS_TAP(X_BSPACE));
        return false;

      case 6: // Line Delete Mac
        SEND_STRING(SS_LCTRL("a") SS_DOWN(X_LSHIFT) SS_LCTRL("e") SS_UP(X_LSHIFT));
        SEND_STRING(SS_TAP(X_BSPACE));
        return false;

      case 7: // Duplicate Selection
        SEND_STRING(SS_LCTRL("c") SS_TAP(X_RIGHT) SS_LCTRL("v"));
        return false;

      case 8: // Duplicate Selection Mac
        SEND_STRING(SS_LGUI("c") SS_TAP(X_RIGHT) SS_LGUI("v"));
        return false;

      case 9: // Join line
        SEND_STRING(SS_TAP(X_END) SS_TAP(X_DELETE));
        return false;

      case 10: // Join line Mac
        SEND_STRING(SS_LCTRL("e") SS_TAP(X_DELETE));
        return false;

      case 98: // Print mode
        SEND_STRING("PC");
        return false;

      case 99: // Print mode
        SEND_STRING("OSX");
        return false;
    }
  }
  return MACRO_NONE;
};

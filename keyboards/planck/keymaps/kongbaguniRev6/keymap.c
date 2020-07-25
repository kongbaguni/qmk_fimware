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
#define M_TAB MT(MOD_LCTL,KC_TAB)
#define M_GUI MT(MOD_LGUI,KC_BSPC)
#define M_RSFT MT(MOD_RSFT, KC_ENT) 
#define M_ALT MT(MOD_LALT,KC_CAPS)

#define L_RAISE LT(_RAISE, KC_ENT)
#define L_LOWER LT(_LOWER, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ;:  | "    |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shft |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |  ,<  |  .>  |  /?  | Shft |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Fn   | Ctrl | Alt  | GUI  |Lower | Space| Space|Raise | LEFT |down  | up   | right|
 * `-----------------------------------------------------------------------------------'
 */

  //KC_BTN2 : menu

[_QWERTY] = LAYOUT_planck_grid(
  KC_ESC,    KC_Q,       KC_W,        KC_E,      KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,      KC_O,      KC_P,       KC_BSPC,
  M_TAB,     KC_A,       KC_S,        KC_D,      KC_F,    KC_G,    KC_H,    KC_J,   KC_K,      KC_L,      KC_SCLN,    KC_QUOT,
  KC_LSFT,   KC_Z,       KC_X,        KC_C,      KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,   KC_DOT,    KC_SLSH,    M_RSFT,
  MO(_FUNC), KC_LCTL,    M_ALT,     M_GUI,     L_LOWER, L_LOWER , L_RAISE,  L_RAISE,   KC_LEFT,   KC_DOWN,   KC_UP,      KC_RIGHT
),

/* Function
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |      | 
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F11 |  F12 | pscr | slck |  F15 |  F16 |  F17 |  F18 |  F19 |  F20 |      | 
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | mouse|      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNC] = LAYOUT_planck_grid(
  XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,  KC_DEL,
  XXXXXXX, KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, KC_PAUS, KC_INS,   KC_HOME,  KC_END,   KC_PGUP, KC_PGDN, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
  _______, _______, _______, _______, _______, _______, _______,  MO(_MOUSE), _______, _______, _______, _______
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  |   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   _  |   =  |   {  |   }  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|  \|  |  `¬  |  #~  |  '@  |  -_  |  =+  |  #~  |  [{  |  ]}  |  '@  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Lower | Del  |Space |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH,  KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR,   KC_LPRN,  KC_RPRN,  KC_PIPE,
  _______, _______, _______, _______, _______, _______,  KC_MINS, KC_EQL,  KC_LCBR,   KC_RCBR,  KC_PIPE,  KC_GRV,
  _______, _______, _______, _______, _______, _______,  KC_UNDS, KC_PLUS, KC_LBRC,   KC_RBRC,  KC_BSLS,  KC_TILD,
  _______, _______, _______, _______, _______, KC_BSPC,  KC_DEL,  RAISE,  KC_MNXT,  KC_VOLD,  KC_VOLU,  KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RGBTOG|RGBMOD|RGBRMD|      |      |      |      |      |   -  |   +  |   [  |   ]  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  Next| Vol- | Vol+ | Play |      | mute |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | enter       |######|      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
  KC_GRV,   KC_1,    KC_2,     KC_3,     KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_BSLS,
  RGB_TOG,  RGB_MOD, RGB_RMOD, _______,  _______, _______, _______, _______, _______, KC_UP,   _______,  _______,
  KC_MNXT,  KC_VOLD, KC_VOLU,  KC_MPLY,  KC_MUTE, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______,
  _______,  _______, _______,  _______,  LOWER,   KC_ENT,  KC_ENT,  _______, _______, _______, _______,  _______
), 

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | ???? | Reset|Qwerty|      |      | REC1 | REC2 |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | CAPS |      |      |      |      | PLAY1| PLAY2| Mute | Vol+ | Play |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | PC/MC|      |      |      |      | STOP | STOP | Prev | Vol- | Next |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
  KC_PWR,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DYN_REC_START1,  DYN_REC_START2,  XXXXXXX,             XXXXXXX,           XXXXXXX,              XXXXXXX,  RESET,
  KC_CAPS,  MU_ON, MU_OFF, XXXXXXX, XXXXXXX, DYN_MACRO_PLAY1, DYN_MACRO_PLAY2, KC_AUDIO_MUTE,       KC_AUDIO_VOL_UP,   KC_MEDIA_PLAY_PAUSE,  XXXXXXX,  XXXXXXX,
  TG(_MAC), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DYN_REC_STOP,    DYN_REC_STOP,    KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN, KC_MEDIA_NEXT_TRACK,  XXXXXXX,  XXXXXXX,
  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Mouse
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | ACC0 | ACC1 | ACC2 |      |      |      |      |      | BTN1 |  UP  | BTN2 |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | ACC0 | ACC1 | ACC2 |      |      |      |      |      | LEFT | DOWN |RIGHT |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_planck_grid(
    KC_ESC ,      _______,      _______,      _______, _______, _______,   _______, _______,     _______,     _______,     _______, _______,
    KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, _______, _______, _______,   _______, KC_MS_BTN4, KC_MS_BTN1,  KC_MS_UP,   KC_MS_BTN2, KC_MS_BTN5, 
    KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, _______, _______, _______,   _______, _______, KC_MS_LEFT,  KC_MS_DOWN, KC_MS_RIGHT,  _______, 
    _______,      _______,      _______,      _______, _______, _______,   _______, _______,     _______,    _______,      _______, _______
),

/* Function 2 (Right hand side)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |WRDSEL|      |      |      | LNDEL|      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | LNSEL| DUP  |      |      |      |      |LNJOIN|      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | UNDO | CUT  | COPY | PASTE|      |      |      |      |      |      | MODE |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
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

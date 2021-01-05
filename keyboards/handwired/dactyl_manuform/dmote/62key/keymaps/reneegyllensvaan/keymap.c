#include "rgblight.h"
#include "62key.h"
#include <keymap_colemak.h>
#include <sendstring_colemak.h>


// Automatic Layer ID:
enum layer_names {
    _QWERTY,   // OS-side Colemak. Default.
    _COLEMAK,  // Keyboard-side Colemak. Portability, emergency.
    _RAISE,
    _LOWER,
    _MIRROR,
    _FUNCTION
};

// Shorthand:
#define COLEMAK DF(_COLEMAK)
#define QWERTY DF(_QWERTY)
#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define MIRROR MO(_MIRROR)
#define FUNCTION MO(_FUNCTION)

#define RMEH_ENT MT(MOD_RGUI | MOD_RALT | MOD_RALT, KC_ENT)
#define RGUI_ENT MT(MOD_RGUI, KC_ENT)
#define LMOUSE KC_MS_BTN1
#define RMOUSE KC_MS_BTN2
#define SCROLLD KC_MS_WH_DOWN
#define SCROLLU KC_MS_WH_UP

// FIXME: Add `MOUSEKEY_ENABLE = yes` to `rules.mk`
// Add `COMMAND_ENABLE = yes` to rules.mk
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_62key(
    KC_VOLD, KC_VOLU, CM_W,    CM_F,    CM_P,    CM_G,
    KC_TAB,  CM_Q,    CM_R,    CM_S,    CM_T,    CM_D,
    KC_ESC,  CM_A,    CM_X,    CM_C,    CM_V,    CM_B,
    KC_NO,   CM_Z, KC_MS_LEFT, KC_MS_UP, KC_MS_RIGHT,
                              KC_MS_DOWN,          KC_LALT,  KC_LSFT,
                                              KC_LGUI,   KC_SPC,   RAISE,
                                                MIRROR, LCTL_T(KC_ESC),

                 CM_J,    CM_L,    CM_U,    CM_Y,   KC_MPLY, FUNCTION,
                 CM_H,    CM_N,    CM_E,    CM_I,   CM_SCLN, KC_BSLS,
                 CM_K,    CM_M,    KC_COMM, KC_DOT, CM_O,    KC_QUOT,
                          LMOUSE,  SCROLLU, RMOUSE, KC_SLSH, KC_NO,
   RCTL_T(KC_ESC),  RGUI_ENT,      SCROLLD,
    KC_RSFT, RAISE, KC_TAB,
        KC_RALT, KC_RGUI
),

[_COLEMAK] = LAYOUT_62key(
    KC_VOLD, KC_VOLU, KC_W,    KC_F,    KC_P,    KC_G,
    KC_TAB,  KC_Q,    KC_R,    KC_S,    KC_T,    KC_D,
    KC_ESC,  KC_A,    KC_X,    KC_C,    KC_V,    KC_B,
    KC_NO,   KC_Z, KC_MS_LEFT, KC_MS_UP, KC_MS_RIGHT,
                             KC_MS_DOWN,          _______, _______,
                                             _______, _______, _______,
                                                 _______, _______,

                 KC_J,    KC_L,    KC_U,    KC_Y,    _______, _______,
                 KC_H,    KC_N,    KC_E,    KC_I,    KC_SCLN, _______,
                 KC_K,    KC_M,    _______, _______, KC_O,    _______,
                          _______, _______, _______, _______, _______,
        _______, _______,          _______,
    _______, _______, _______,
        _______, _______
),

[_MIRROR] = LAYOUT_62key(
    _______, _______, CM_Y,    CM_U,    CM_L,    CM_J,
    KC_TAB,  CM_SCLN, CM_I,    CM_E,    CM_N,    CM_H,
    KC_ESC,  CM_O,    CM_DOT,  CM_COMM, CM_M,    CM_K,
    KC_NO,   CM_SLSH, RMOUSE,  SCROLLU, LMOUSE,
                               SCROLLD,           _______, _______,
                                              _______, _______, _______,
                                                  _______, _______,

                 CM_G,    CM_P,    CM_F,    CM_W,   _______, _______,
                 CM_D,    CM_T,    CM_S,    CM_R,   CM_Q,    KC_BSLS,
                 CM_B,    CM_V,    KC_C,    CM_X,   CM_A,    KC_QUOT,
                      KC_MS_LEFT,  KC_MS_UP, KC_MS_RIGHT, CM_Z, KC_NO,
       _______,  _______,          KC_MS_DOWN,
    _______, _______, _______,
        _______, _______
),

[_RAISE] = LAYOUT_62key(
    KC_NO,   KC_NO,   KC_2,    KC_3,    KC_4,    KC_MINS,
    KC_NO,   KC_1,    KC_6,    KC_7,    KC_8,    KC_EQL,
    KC_NO,   KC_5,    KC_0,    CM_COLN, KC_NO,   KC_BSLASH,
    KC_NO,   KC_9,    KC_NO,   KC_NO,   KC_NO,
                               KC_NO,           _______, _______,
                                             _______, _______, _______,
                                                 _______, _______,

                 KC_DOWN, KC_RIGHT,KC_BSPC, KC_NO,   RESET,   CMB_TOG,
                 KC_GRV,  KC_QUOT, KC_LBRC, KC_RBRC, KC_NO,   KC_NO,
                 KC_UP,   KC_LEFT, KC_LPRN, KC_RPRN, KC_NO,   KC_NO,
                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        _______, _______,          KC_NO,
    _______, _______, _______,
        _______, _______
),
[_LOWER] = LAYOUT_62key(
    QWERTY,  COLEMAK, KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                               KC_NO,            _______, _______,
                                             _______, _______, _______,
                                                 _______, _______,

                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        _______, _______,          KC_NO,
    _______, _______, _______,
        _______, _______
),
[_FUNCTION] = LAYOUT_62key(
    _______, _______, KC_F2,   KC_F3,   KC_F4,   KC_NO,
    KC_NO,   KC_F1,   KC_F6,   KC_F7,   KC_F8,   KC_NO,
    KC_NO,   KC_F5,   KC_F10,  KC_F11,  KC_F12,  KC_NO,
    KC_NO,   KC_F9,   KC_NO,   KC_NO,   KC_NO,
                               KC_NO,            _______, _______,
                                             _______, _______, _______,
                                                 _______, _______,

                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        _______, _______,          KC_NO,
    _______, _______, _______,
        _______, _______
)
};


enum combo_events {
  NE_CTRL,
  FP_TAB,
  AT_SHIFT,
  NO_SHIFT,
};

const uint16_t PROGMEM ne_combo[] = {CM_N, CM_E, COMBO_END};
const uint16_t PROGMEM fp_combo[] = {CM_F, CM_P, COMBO_END};
const uint16_t PROGMEM at_combo[] = {CM_A, CM_T, COMBO_END};
const uint16_t PROGMEM no_combo[] = {CM_N, CM_O, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [NE_CTRL] = COMBO(ne_combo, KC_RCTRL),
  [FP_TAB] = COMBO(fp_combo, KC_TAB),
  [AT_SHIFT] = COMBO(at_combo, KC_LSFT),
  [NO_SHIFT] = COMBO(no_combo, KC_RSFT),
};

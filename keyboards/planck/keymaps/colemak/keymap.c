// Generated from keymap.c.org
// Keymap meta-code
#include QMK_KEYBOARD_H
#include "muse.h"
#include "keymap_steno.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _LOWER_COLEMAK,
  _LOWER_QWERTY,
  _FUNCTION,
  _STENO
};

#define LOWER_CO MO(_LOWER_COLEMAK)
#define LOWER_QW MO(_LOWER_QWERTY)
#define FN MO(_FUNCTION)
#define STENO TT(_STENO)
#define UNSTENO TT(_COLEMAK)
#define ESCTL LCTL_T(KC_ESC)
#define COLN LSFT(KC_P)

void matrix_init_user() {
  steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_planck_grid(
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_ENT,
    KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
    KC_LSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, FN,
    KC_LCTL, KC_NO, KC_NO, KC_LGUI, KC_SPC, LOWER_QW, KC_LSHIFT, ESCTL, KC_LALT, KC_NO, STENO, FN
  ),
  [_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_ENT,
    KC_ESC, KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, KC_QUOT,
    KC_LSHIFT, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, FN,
    KC_LCTL, KC_NO, KC_NO, KC_LGUI, KC_SPC, LOWER_CO, KC_LSHIFT, ESCTL, KC_LALT, KC_NO, STENO, FN
  ),
  [_LOWER_COLEMAK] = LAYOUT_planck_grid(
    KC_NO, KC_1, KC_2, KC_3, KC_4, KC_MINS, KC_DOWN, KC_RGHT, KC_BSPC, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_5, KC_6, KC_7, KC_8, KC_EQL, KC_GRV, KC_QUOT, KC_LBRC, KC_RBRC, KC_NO, KC_NO,
    KC_TRNS, KC_9, KC_0, KC_COLN, KC_NO, KC_BSLS, KC_UP, KC_LEFT, KC_LPRN, KC_RPRN, KC_NO, KC_TRNS,
    KC_TRNS, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO
  ),
  [_LOWER_QWERTY] = LAYOUT_planck_grid(
    KC_NO, KC_1, KC_2, KC_3, KC_4, KC_MINS, KC_DOWN, KC_RGHT, KC_BSPC, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_5, KC_6, KC_7, KC_8, KC_EQL, KC_GRV, KC_QUOT, KC_LBRC, KC_RBRC, KC_NO, KC_NO,
    KC_TRNS, KC_9, KC_0, COLN, KC_NO, KC_BSLS, KC_UP, KC_LEFT, KC_LPRN, KC_RPRN, KC_NO, KC_TRNS,
    KC_TRNS, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO
  ),
  [_FUNCTION] = LAYOUT_planck_grid(
    KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_NO, KC_VOLD, KC_MNXT, KC_MPLY, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_F5, KC_F6, KC_F7, KC_F8, KC_NO, KC_MPRV, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_VOLU, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
    KC_TRNS, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO
  ),
  [_STENO] = LAYOUT_planck_grid(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, STN_S1, STN_TL, STN_PL, STN_HL, STN_ST1, STN_ST3, STN_FR, STN_PR, STN_LR, STN_TR, STN_DR,
    KC_NO, STN_S2, STN_KL, STN_WL, STN_RL, STN_ST2, STN_ST4, STN_RR, STN_BR, STN_GR, STN_SR, STN_ZR,
    DF(_COLEMAK), DF(_QWERTY), KC_NO, KC_NO, STN_A, STN_O, STN_E, STN_U, KC_NO, KC_NO, KC_TRNS, KC_NO
  )
};

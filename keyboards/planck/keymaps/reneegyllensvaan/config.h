#pragma once

#define SOFTWARE_MOD_DH

#define KC_NP KC_NO // key is not present
#define _____ KC_NO // key is not present
#define KC_NA KC_NO // present but not available for use
#define KC_NU KC_NO // available but not used

#ifdef SOFTWARE_MOD_DH
#define _COLN DH_COLN
#define _SCLN DH_SCLN
#else
#define _COLN KC_COLN
#define _SCLN KC_SCLN
#endif


// non-KC_ keycodes
#define KC_RST RESET
#define KC_TOG RGB_TOG
#define KC_MOD RGB_MOD
#define KC_HUI RGB_HUI
#define KC_SAI RGB_SAI
#define KC_VAI RGB_VAI

/* #define COMBO_VARIABLE_LEN */
/* #define COMBO_COUNT 24 */
#define COMBO_COUNT 4
#define COMBO_TERM 200
#define COMBO_ALLOW_ACTION_KEYS

// default but important
#define TAPPING_TERM 230

// default but important
#define PERMISSIVE_HOLD

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Recommended for heavy chording.
#define QMK_KEYS_PER_SCAN 4

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64


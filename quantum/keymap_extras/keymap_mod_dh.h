#pragma once

#include "keymap.h"

// clang-format off

/*
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │ Q │ W │ F │ P │ G │ J │ L │ U │ Y │ ; │ [ │ ] │  \  │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 * │      │ A │ R │ S │ T │ D │ H │ N │ E │ I │ O │ ' │        │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
 * │        │ Z │ X │ C │ V │ B │ K │ M │ , │ . │ / │          │
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
// Row 1
#define DH_GRV  KC_GRV  // `
#define DH_1    KC_1    // 1
#define DH_2    KC_2    // 2
#define DH_3    KC_3    // 3
#define DH_4    KC_4    // 4
#define DH_5    KC_5    // 5
#define DH_6    KC_6    // 6
#define DH_7    KC_7    // 7
#define DH_8    KC_8    // 8
#define DH_9    KC_9    // 9
#define DH_0    KC_0    // 0
#define DH_MINS KC_MINS // -
#define DH_EQL  KC_EQL  // =
// Row 2
#define DH_Q    KC_Q    // Q
#define DH_W    KC_W    // W
#define DH_F    KC_E    // F
#define DH_P    KC_R    // P
#define DH_B    KC_T    // B
#define DH_J    KC_Y    // J
#define DH_L    KC_U    // L
#define DH_U    KC_I    // U
#define DH_Y    KC_O    // Y
#define DH_QUOT KC_P    // '
#define DH_LBRC KC_LBRC // [
#define DH_RBRC KC_RBRC // ]
#define DH_BSLS KC_BSLS // (backslash)
// Row 3
#define DH_A    KC_A    // A
#define DH_R    KC_S    // R
#define DH_S    KC_D    // S
#define DH_T    KC_F    // T
#define DH_G    KC_G    // G
#define DH_M    KC_H    // M
#define DH_N    KC_J    // N
#define DH_E    KC_K    // E
#define DH_I    KC_L    // I
#define DH_O    KC_SCLN // O
#define DH_SCLN KC_QUOT // ;
// Row 4
#define DH_Z    KC_Z    // Z
#define DH_X    KC_X    // X
#define DH_C    KC_C    // C
#define DH_D    KC_V    // D
#define DH_V    KC_B    // V
#define DH_K    KC_N    // K
#define DH_H    KC_M    // H
#define DH_COMM KC_COMM // ,
#define DH_DOT  KC_DOT  // .
#define DH_SLSH KC_SLSH // /

/* Shifted symbols
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │ ~ │ ! │ @ │ # │ $ │ % │ ^ │ & │ * │ ( │ ) │ _ │ + │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │   │   │   │   │   │   │   │   │   │ : │ { │ } │  |  │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 * │      │   │   │   │   │   │   │   │   │   │   │ " │        │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
 * │        │   │   │   │   │   │   │   │ < │ > │ ? │          │
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
// Row 1
#define DH_TILD S(DH_GRV)  // ~
#define DH_EXLM S(DH_1)    // !
#define DH_AT   S(DH_2)    // @
#define DH_HASH S(DH_3)    // #
#define DH_DLR  S(DH_4)    // $
#define DH_PERC S(DH_5)    // %
#define DH_CIRC S(DH_6)    // ^
#define DH_AMPR S(DH_7)    // &
#define DH_ASTR S(DH_8)    // *
#define DH_LPRN S(DH_9)    // (
#define DH_RPRN S(DH_0)    // )
#define DH_UNDS S(DH_MINS) // _
#define DH_PLUS S(DH_EQL)  // +
// Row 2
#define DH_COLN S(DH_SCLN) // :
#define DH_LCBR S(DH_LBRC) // {
#define DH_RCBR S(DH_RBRC) // }
#define DH_PIPE S(DH_BSLS) // |
// Row 3
#define DH_DQUO S(DH_QUOT) // "
// Row 4
#define DH_LABK S(DH_COMM) // <
#define DH_RABK S(DH_DOT)  // >
#define DH_QUES S(DH_SLSH) // /

// DEPRECATED
#define KC_DH_Q    DH_Q
#define KC_DH_W    DH_W
#define KC_DH_F    DH_F
#define KC_DH_P    DH_P
#define KC_DH_G    DH_G
#define KC_DH_J    DH_J
#define KC_DH_L    DH_L
#define KC_DH_U    DH_U
#define KC_DH_Y    DH_Y
#define KC_DH_SCLN DH_SCLN
#define KC_DH_A    DH_A
#define KC_DH_R    DH_R
#define KC_DH_S    DH_S
#define KC_DH_T    DH_T
#define KC_DH_D    DH_D
#define KC_DH_H    DH_H
#define KC_DH_N    DH_N
#define KC_DH_E    DH_E
#define KC_DH_I    DH_I
#define KC_DH_O    DH_O
#define KC_DH_Z    DH_Z
#define KC_DH_X    DH_X
#define KC_DH_C    DH_C
#define KC_DH_V    DH_V
#define KC_DH_B    DH_B
#define KC_DH_K    DH_K
#define KC_DH_M    DH_M
#define KC_DH_COMM DH_COMM
#define KC_DH_DOT  DH_DOT
#define KC_DH_SLSH DH_SLSH

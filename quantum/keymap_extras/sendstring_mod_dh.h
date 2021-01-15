#pragma once

#include "keymap_mod_dh.h"

// clang-format off

const uint8_t ascii_to_keycode_lut[128] PROGMEM = {
    // NUL   SOH      STX      ETX      EOT      ENQ      ACK      BEL
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    // BS    TAB      LF       VT       FF       CR       SO       SI
    KC_BSPC, KC_TAB,  KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    // DLE   DC1      DC2      DC3      DC4      NAK      SYN      ETB
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    // CAN   EM       SUB      ESC      FS       GS       RS       US
    XXXXXXX, XXXXXXX, XXXXXXX, KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

    //       !        "        #        $        %        &        '
    KC_SPC,  DH_1,    DH_QUOT, DH_3,    DH_4,    DH_5,    DH_7,    DH_QUOT,
    // (     )        *        +        ,        -        .        /
    DH_9,    DH_0,    DH_8,    DH_EQL,  DH_COMM, DH_MINS, DH_DOT,  DH_SLSH,
    // 0     1        2        3        4        5        6        7
    DH_0,    DH_1,    DH_2,    DH_3,    DH_4,    DH_5,    DH_6,    DH_7,
    // 8     9        :        ;        <        =        >        ?
    DH_8,    DH_9,    DH_SCLN, DH_SCLN, DH_COMM, DH_EQL,  DH_DOT,  DH_SLSH,
    // @     A        B        C        D        E        F        G
    DH_2,    DH_A,    DH_B,    DH_C,    DH_D,    DH_E,    DH_F,    DH_G,
    // H     I        J        K        L        M        N        O
    DH_H,    DH_I,    DH_J,    DH_K,    DH_L,    DH_M,    DH_N,    DH_O,
    // P     Q        R        S        T        U        V        W
    DH_P,    DH_Q,    DH_R,    DH_S,    DH_T,    DH_U,    DH_V,    DH_W,
    // X     Y        Z        [        \        ]        ^        _
    DH_X,    DH_Y,    DH_Z,    DH_LBRC, DH_BSLS, DH_RBRC, DH_6,    DH_MINS,
    // `     a        b        c        d        e        f        g
    DH_GRV,  DH_A,    DH_B,    DH_C,    DH_D,    DH_E,    DH_F,    DH_G,
    // h     i        j        k        l        m        n        o
    DH_H,    DH_I,    DH_J,    DH_K,    DH_L,    DH_M,    DH_N,    DH_O,
    // p     q        r        s        t        u        v        w
    DH_P,    DH_Q,    DH_R,    DH_S,    DH_T,    DH_U,    DH_V,    DH_W,
    // x     y        z        {        |        }        ~        DEL
    DH_X,    DH_Y,    DH_Z,    DH_LBRC, DH_BSLS, DH_RBRC, DH_GRV,  KC_DEL
};

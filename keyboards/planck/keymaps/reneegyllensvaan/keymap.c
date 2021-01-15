/*
Notes
=====
    - Fixed: Esc and Ret positions should be swapped, Esc is much more common
    - Fixed: Mod tap does not work when typing fast but in proper order (e.g.
      Pn -> Pt -> Rt -> Rn sends "nt" when typing too quickly)

    - Look into reducing thumb movement with tri-layers
    - Media and Mouse could fit on the same layer, freeing up RT3 for shift or
    new layer. Media can be a same-hand layer because it's very infrequent
    anyway
        - Consider making a full 4-key row of some infrequent layer a backspace row,
          for finger rolling interactive delete
        - Maybe left hand top on Nav?
    - Mouse layer is a comfortable position, could maybe put Nav there since
      that's a "parking" mode?
    - Could maybe utilize left hand in RT3 layer?
    - Combos:
    - `nt`: Esc->: or just :
    - `se`: Esc
    - `ao`: "Microsnippet" layer
    - `aoX`: Microsnippet X without waiting
    - Nav+n: left
    - Nav+o: right


*/

#include QMK_KEYBOARD_H
#ifdef SOFTWARE_MOD_DH
#include <keymap_mod_dh.h>
#include <sendstring_mod_dh.h>
#endif
#include "print.h"

#define LAYOUT_miryoku(\
    K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,\
    K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,\
    K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29,\
    N30,   N31,   K32,   K33,   K34,   K35,   K36,   K37,   N38,   N39\
    )\
LAYOUT_ortho_4x12(\
    K00,   K01,   K02,   K03,   K04,   KC_NO, KC_NO, K05,   K06,   K07,   K08,   K09,\
    K10,   K11,   K12,   K13,   K14,   KC_NO, KC_NO, K15,   K16,   K17,   K18,   K19,\
    K20,   K21,   K22,   K23,   K24,   KC_NO, KC_NO, K25,   K26,   K27,   K28,   K29,\
    KC_NO, KC_NO, K32,   K33,   K34,   K34,   K35,   K35,   K36,   K37,   KC_NO, KC_NO\
    )



enum layers {
  BASE,
  MBO,
  MEDR,
  NAVR,
  MOUR,
  NSSL,
  NSL,
  FUNL,
  MICROSNIPPET
};

enum custom_keycodes {
  SS_W  =  SAFE_RANGE,
           SS_F,    SS_P,    SS_B,    SS_J,    SS_L,    SS_U,    SS_Y,
  SS_R,    SS_S,    SS_T,    SS_G,    SS_M,    SS_N,    SS_E,    SS_O,
  SS_D,    SS_V,    SS_K,    SS_H
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    /* // Left pinky should be allowed to lift slower */
    /* case LGUI_T(KC_O): */
    /* case LGUI_T(DH_O): */
    /*   return TAPPING_TERM + 50; */
    /* // Same with right pinky */
    /* case LGUI_T(KC_A): */
    /* case LGUI_T(DH_A): */
    /*   return TAPPING_TERM + 50; */
    default:
      return TAPPING_TERM;
  }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    /* case LT(1, KC_BSPC): */
    /*     return true; */
    default:
      return false;
  }
}

/* void keyboard_post_init_user(void) { */
/*   // Customise these values to desired behaviour */
/*   debug_enable=true; */
/*   // debug_matrix=true; */
/*   debug_keyboard=true; */
/*   //debug_mouse=true; */
/* } */

/* #ifdef COMBO_ENABLE */
enum combo_events {
  /* AOW_SS_COMBO, */
  /* AOF_SS_COMBO, */
  /* AOP_SS_COMBO, */
  /* AOB_SS_COMBO, */
  /* AOJ_SS_COMBO, */
  /* AOL_SS_COMBO, */
  /* AOU_SS_COMBO, */
  /* AOY_SS_COMBO, */
  /* AOR_SS_COMBO, */
  /* AOS_SS_COMBO, */
  /* AOT_SS_COMBO, */
  /* AOG_SS_COMBO, */
  /* AOM_SS_COMBO, */
  /* AON_SS_COMBO, */
  /* AOE_SS_COMBO, */
  /* AOO_SS_COMBO, */
  /* AOD_SS_COMBO, */
  /* AOV_SS_COMBO, */
  /* AOK_SS_COMBO, */
  /* AOH_SS_COMBO, */
  CO_MICROSNIPPET,
  CO_SPAMMA,
  CO_VIMCMD,
  CO_FOO
};


bool send_microsnippet(uint16_t keycode, bool pressed) {
  switch (keycode) {
    case SS_W:
      return false;
    case SS_F:
      return false;
    case SS_P:
      return false;
    case SS_B:
      return false;
    case SS_J:
      return false;
    case SS_L:
      return false;
    case SS_U:
      return false;
    case SS_Y:
      return false;

    case SS_R:
      if (pressed) {
          SEND_STRING("{}" SS_TAP(X_LEFT));
      }
      return true;
    case SS_S:
      if (pressed) {
          SEND_STRING("[]" SS_TAP(X_LEFT));
      }
      return true;
    case SS_T:
      if (pressed) {
          SEND_STRING("()" SS_TAP(X_LEFT));
      }
      return true;
    case SS_G:
      if (pressed) {
          SEND_STRING(" => ");
      }
      return true;
    case SS_M:
      if (pressed) {
          SEND_STRING(" -> ");
      }
      return true;
    case SS_N:
      if (pressed) {
          SEND_STRING("\"\"" SS_TAP(X_LEFT));
      }
      return true;
    case SS_E:
      if (pressed) {
          SEND_STRING("''" SS_TAP(X_LEFT));
      }
      return true;
    case SS_O:
      if (pressed) {
          SEND_STRING("<>" SS_TAP(X_LEFT));
      }
      return true;

    case SS_D:
      return false;
    case SS_V:
      return false;
    case SS_K:
      return false;
    case SS_H:
      return false;
  }
  return false;
}

const int COMBO_LEN = 3;
#ifdef SOFTWARE_MOD_DH
const uint16_t microsnippet_combo[] = {LGUI_T(DH_A), LGUI_T(DH_O), COMBO_END};
const uint16_t spamma_combo[] = {DH_G, LSFT_T(DH_T), COMBO_END};
const uint16_t vimcmd_combo[] = {LSFT_T(DH_T), LSFT_T(DH_N), COMBO_END};
const uint16_t foo_combo[] = {DH_W, DH_P, COMBO_END};

/* const uint16_t PROGMEM snip_w_combo[] = {LGUI_T(DH_A), LGUI_T(DH_O), DH_W, COMBO_END}; */
/* const uint16_t PROGMEM snip_f_combo[] = {LGUI_T(DH_A), LGUI_T(DH_O), DH_F, COMBO_END}; */
/* const uint16_t PROGMEM snip_p_combo[] = {LGUI_T(DH_A), LGUI_T(DH_O), DH_P, COMBO_END}; */
/* const uint16_t PROGMEM snip_b_combo[] = {LGUI_T(DH_A), LGUI_T(DH_O), DH_B, COMBO_END}; */
/* const uint16_t PROGMEM snip_j_combo[] = {LGUI_T(DH_A), LGUI_T(DH_O), DH_J, COMBO_END}; */
/* const uint16_t PROGMEM snip_l_combo[] = {LGUI_T(DH_A), LGUI_T(DH_O), DH_L, COMBO_END}; */
/* const uint16_t PROGMEM snip_u_combo[] = {LGUI_T(DH_A), LGUI_T(DH_O), DH_U, COMBO_END}; */
/* const uint16_t PROGMEM snip_y_combo[] = {LGUI_T(DH_A), LGUI_T(DH_O), DH_Y, COMBO_END}; */
/* const uint16_t PROGMEM snip_r_combo[] = {LGUI_T(DH_A), LGUI_T(DH_O), LALT_T(DH_R), COMBO_END}; */
/* const uint16_t PROGMEM snip_s_combo[] = {LGUI_T(DH_A), LGUI_T(DH_O), LCTL_T(DH_S), COMBO_END}; */
/* const uint16_t PROGMEM snip_t_combo[] = {LGUI_T(DH_A), LGUI_T(DH_O), LSFT_T(DH_T), COMBO_END}; */
/* const uint16_t PROGMEM snip_g_combo[] = {LGUI_T(DH_A), LGUI_T(DH_O), DH_G, COMBO_END}; */
/* const uint16_t PROGMEM snip_m_combo[] = {LGUI_T(DH_A), LGUI_T(DH_O), DH_M, COMBO_END}; */
/* const uint16_t PROGMEM snip_n_combo[] = {LGUI_T(DH_A), LGUI_T(DH_O), LSFT_T(DH_N), COMBO_END}; */
/* const uint16_t PROGMEM snip_e_combo[] = {LGUI_T(DH_A), LGUI_T(DH_O), LCTL_T(DH_E), COMBO_END}; */
/* const uint16_t PROGMEM snip_i_combo[] = {LGUI_T(DH_A), LGUI_T(DH_O), LALT_T(DH_I), COMBO_END}; */
/* const uint16_t PROGMEM snip_d_combo[] = {LGUI_T(DH_A), LGUI_T(DH_O), DH_D, COMBO_END}; */
/* const uint16_t PROGMEM snip_v_combo[] = {LGUI_T(DH_A), LGUI_T(DH_O), DH_V, COMBO_END}; */
/* const uint16_t PROGMEM snip_k_combo[] = {LGUI_T(DH_A), LGUI_T(DH_O), DH_K, COMBO_END}; */
/* const uint16_t PROGMEM snip_h_combo[] = {LGUI_T(DH_A), LGUI_T(DH_O), DH_H, COMBO_END}; */
#else
// FIXME: These aren't used currently
const uint16_t PROGMEM microsnippet_combo[] = {LGUI_T(KC_A), LGUI_T(KC_O), COMBO_END};
const uint16_t PROGMEM spamma_combo[] = {LGUI_T(KC_W), LGUI_T(KC_T), COMBO_END};
const uint16_t PROGMEM snip_w_combo[] = {LGUI_T(KC_A), LGUI_T(KC_O), KC_W, COMBO_END};
const uint16_t PROGMEM snip_f_combo[] = {LGUI_T(KC_A), LGUI_T(KC_O), KC_F, COMBO_END};
const uint16_t PROGMEM snip_p_combo[] = {LGUI_T(KC_A), LGUI_T(KC_O), KC_P, COMBO_END};
const uint16_t PROGMEM snip_b_combo[] = {LGUI_T(KC_A), LGUI_T(KC_O), KC_B, COMBO_END};
const uint16_t PROGMEM snip_j_combo[] = {LGUI_T(KC_A), LGUI_T(KC_O), KC_J, COMBO_END};
const uint16_t PROGMEM snip_l_combo[] = {LGUI_T(KC_A), LGUI_T(KC_O), KC_L, COMBO_END};
const uint16_t PROGMEM snip_u_combo[] = {LGUI_T(KC_A), LGUI_T(KC_O), KC_U, COMBO_END};
const uint16_t PROGMEM snip_y_combo[] = {LGUI_T(KC_A), LGUI_T(KC_O), KC_Y, COMBO_END};
const uint16_t PROGMEM snip_r_combo[] = {LGUI_T(KC_A), LGUI_T(KC_O), KC_R, COMBO_END};
const uint16_t PROGMEM snip_s_combo[] = {LGUI_T(KC_A), LGUI_T(KC_O), KC_S, COMBO_END};
const uint16_t PROGMEM snip_t_combo[] = {LGUI_T(KC_A), LGUI_T(KC_O), KC_T, COMBO_END};
const uint16_t PROGMEM snip_g_combo[] = {LGUI_T(KC_A), LGUI_T(KC_O), KC_G, COMBO_END};
const uint16_t PROGMEM snip_m_combo[] = {LGUI_T(KC_A), LGUI_T(KC_O), KC_M, COMBO_END};
const uint16_t PROGMEM snip_n_combo[] = {LGUI_T(KC_A), LGUI_T(KC_O), KC_N, COMBO_END};
const uint16_t PROGMEM snip_e_combo[] = {LGUI_T(KC_A), LGUI_T(KC_O), KC_E, COMBO_END};
const uint16_t PROGMEM snip_i_combo[] = {LGUI_T(KC_A), LGUI_T(KC_O), KC_O, COMBO_END};
const uint16_t PROGMEM snip_d_combo[] = {LGUI_T(KC_A), LGUI_T(KC_O), KC_D, COMBO_END};
const uint16_t PROGMEM snip_v_combo[] = {LGUI_T(KC_A), LGUI_T(KC_O), KC_V, COMBO_END};
const uint16_t PROGMEM snip_k_combo[] = {LGUI_T(KC_A), LGUI_T(KC_O), KC_K, COMBO_END};
const uint16_t PROGMEM snip_h_combo[] = {LGUI_T(KC_A), LGUI_T(KC_O), KC_H, COMBO_END};
#endif

combo_t key_combos[COMBO_COUNT] = {
  /* [AOW_SS_COMBO] = COMBO_ACTION(snip_w_combo), */
  /* [AOF_SS_COMBO] = COMBO_ACTION(snip_f_combo), */
  /* [AOP_SS_COMBO] = COMBO_ACTION(snip_p_combo), */
  /* [AOB_SS_COMBO] = COMBO_ACTION(snip_b_combo), */
  /* [AOJ_SS_COMBO] = COMBO_ACTION(snip_j_combo), */
  /* [AOL_SS_COMBO] = COMBO_ACTION(snip_l_combo), */
  /* [AOU_SS_COMBO] = COMBO_ACTION(snip_u_combo), */
  /* [AOY_SS_COMBO] = COMBO_ACTION(snip_y_combo), */
  /* [AOR_SS_COMBO] = COMBO_ACTION(snip_r_combo), */
  /* [AOS_SS_COMBO] = COMBO_ACTION(snip_s_combo), */
  /* [AOT_SS_COMBO] = COMBO_ACTION(snip_t_combo), */
  /* [AOG_SS_COMBO] = COMBO_ACTION(snip_g_combo), */
  /* [AOM_SS_COMBO] = COMBO_ACTION(snip_m_combo), */
  /* [AON_SS_COMBO] = COMBO_ACTION(snip_n_combo), */
  /* [AOE_SS_COMBO] = COMBO_ACTION(snip_e_combo), */
  /* [AOO_SS_COMBO] = COMBO_ACTION(snip_i_combo), */
  /* [AOD_SS_COMBO] = COMBO_ACTION(snip_d_combo), */
  /* [AOV_SS_COMBO] = COMBO_ACTION(snip_v_combo), */
  /* [AOK_SS_COMBO] = COMBO_ACTION(snip_k_combo), */
  /* [AOH_SS_COMBO] = COMBO_ACTION(snip_h_combo), */

  [CO_MICROSNIPPET] = COMBO_ACTION(microsnippet_combo),
  [CO_SPAMMA] = COMBO_ACTION(spamma_combo),
  [CO_VIMCMD] = COMBO_ACTION(vimcmd_combo),
  [CO_FOO] = COMBO_ACTION(foo_combo)

};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        case CO_MICROSNIPPET:
            if (pressed) {
                layer_on(MICROSNIPPET);
            } else {
                layer_off(MICROSNIPPET);
            }
            break;
        case CO_SPAMMA:
            if (pressed) {
                SEND_STRING(", ");
            }
            break;

        case CO_VIMCMD:
            if (pressed) {
                SEND_STRING(SS_TAP(X_ESC) ", ");
            }
            break;

        case CO_FOO:
            if (pressed) {
                SEND_STRING("FOOOO down");
            } else {
                SEND_STRING("FOOOO up");
            }
            break;
    }

    /* if (pressed) { */
    /*     switch (keycode) { */
    /*         // "Dumb" code to map combo layout to keycodes */
    /*         // Could just do some arithmetic here, but w/e */
    /*         case AOW_SS_COMBO: */
    /*             send_microsnippet(SS_W, pressed); */
    /*             break; */
    /*         case AOF_SS_COMBO: */
    /*             send_microsnippet(SS_F, pressed); */
    /*             break; */
    /*         case AOP_SS_COMBO: */
    /*             send_microsnippet(SS_P, pressed); */
    /*             break; */
    /*         case AOB_SS_COMBO: */
    /*             send_microsnippet(SS_B, pressed); */
    /*             break; */
    /*         case AOJ_SS_COMBO: */
    /*             send_microsnippet(SS_J, pressed); */
    /*             break; */
    /*         case AOL_SS_COMBO: */
    /*             send_microsnippet(SS_L, pressed); */
    /*             break; */
    /*         case AOU_SS_COMBO: */
    /*             send_microsnippet(SS_U, pressed); */
    /*             break; */
    /*         case AOY_SS_COMBO: */
    /*             send_microsnippet(SS_Y, pressed); */
    /*             break; */
    /*         case AOR_SS_COMBO: */
    /*             send_microsnippet(SS_R, pressed); */
    /*             break; */
    /*         case AOS_SS_COMBO: */
    /*             send_microsnippet(SS_S, pressed); */
    /*             break; */
    /*         case AOT_SS_COMBO: */
    /*             send_microsnippet(SS_T, pressed); */
    /*             break; */
    /*         case AOG_SS_COMBO: */
    /*             send_microsnippet(SS_G, pressed); */
    /*             break; */
    /*         case AOM_SS_COMBO: */
    /*             send_microsnippet(SS_M, pressed); */
    /*             break; */
    /*         case AON_SS_COMBO: */
    /*             send_microsnippet(SS_N, pressed); */
    /*             break; */
    /*         case AOE_SS_COMBO: */
    /*             send_microsnippet(SS_E, pressed); */
    /*             break; */
    /*         case AOO_SS_COMBO: */
    /*             send_microsnippet(SS_O, pressed); */
    /*             break; */
    /*         case AOD_SS_COMBO: */
    /*             send_microsnippet(SS_D, pressed); */
    /*             break; */
    /*         case AOV_SS_COMBO: */
    /*             send_microsnippet(SS_V, pressed); */
    /*             break; */
    /*         case AOK_SS_COMBO: */
    /*             send_microsnippet(SS_K, pressed); */
    /*             break; */
    /*         case AOH_SS_COMBO: */
    /*             send_microsnippet(SS_H, pressed); */
    /*             break; */
    /*     } */
    /* } */
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (send_microsnippet(keycode, record->event.pressed)) {
        return false;
    }

    /* switch(keycode) { */
    /*         return false; */
    /* } */

    return true;
}
/* #endif */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#ifdef SOFTWARE_MOD_DH
  [BASE] = LAYOUT_miryoku(
      DH_Q,              DH_W,              DH_F,              DH_P,              DH_B,              DH_J,              DH_L,              DH_U,              DH_Y,              DH_QUOT,
      LGUI_T(DH_A),      LALT_T(DH_R),      LCTL_T(DH_S),      LSFT_T(DH_T),      DH_G,              DH_M,              LSFT_T(DH_N),      LCTL_T(DH_E),      LALT_T(DH_I),      LGUI_T(DH_O),
      DH_Z,              ALGR_T(DH_X),      DH_C,              DH_D,              DH_V,              DH_K,              DH_H,              DH_COMM,           ALGR_T(DH_DOT),    DH_SLSH,
      KC_NP,             KC_NP,             LT(MEDR, KC_ENT),  LT(NAVR, KC_SPC),  LT(MOUR, KC_TAB),  LT(NSSL, KC_ESC),  LT(NSL, KC_BSPC),  LT(FUNL, KC_DEL),  KC_NP,             KC_NP
      ),
#else
  [BASE] = LAYOUT_miryoku(
      KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,
      LGUI_T(KC_A),      LALT_T(KC_R),      LCTL_T(KC_S),      LSFT_T(KC_T),      KC_G,              KC_M,              LSFT_T(KC_N),      LCTL_T(KC_E),      LALT_T(KC_I),      LGUI_T(KC_O),
      KC_Z,              ALGR_T(KC_X),      KC_C,              KC_D,              KC_V,              KC_K,              KC_H,              KC_COMM,           ALGR_T(KC_DOT),    KC_SLSH,
      KC_NP,             KC_NP,             LT(MEDR, KC_ENT),  LT(NAVR, KC_SPC),  LT(MOUR, KC_TAB),  LT(NSSL, KC_ESC),  LT(NSL, KC_BSPC),  LT(FUNL, KC_DEL),  KC_NP,             KC_NP
      ),
#endif

  [NAVR] = LAYOUT_miryoku(
      KC_RST,  KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_AGIN, KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE,
      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NA,   KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
      KC_NA,   KC_ALGR, KC_NA,   KC_NA,   KC_NA,   KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,
      KC_NP,   KC_NP,   KC_NA,   KC_NA,   KC_NA,   KC_ENT,  KC_BSPC, KC_DEL,  KC_NP,   KC_NP
      ),
  [MOUR] = LAYOUT_miryoku(
      KC_RST,  KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NU,   KC_NU,   KC_NU,   KC_NU,   KC_NU,
      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NA,   KC_NU,   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
      KC_NA,   KC_ALGR, KC_NA,   KC_NA,   KC_NA,   KC_NU,   KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,
      KC_NP,   KC_NP,   KC_NA,   KC_NA,   KC_NA,   KC_BTN1, KC_BTN3, KC_BTN2, KC_NP,   KC_NP
      ),
  [MBO] = LAYOUT_miryoku(
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_NP,   KC_NP,   KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN3, KC_BTN2, KC_NP,   KC_NP
      ),
  [MEDR] = LAYOUT_miryoku(
      KC_RST,  KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_TOG,  KC_MOD,  KC_HUI,  KC_SAI,  KC_VAI,
      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NA,   KC_NU,   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
      KC_NA,   KC_ALGR, KC_NA,   KC_NA,   KC_NA,   KC_NU,   KC_NU,   KC_NU,   KC_NU,   KC_NU,
      KC_NP,   KC_NP,   KC_NA,   KC_NA,   KC_NA,   KC_MSTP, KC_MPLY, KC_MUTE, KC_NP,   KC_NP
      ),
  [FUNL] = LAYOUT_miryoku(
      KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, KC_NA,   CMB_TOG, KC_NA,   KC_NA,   KC_RST,
      KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SLCK, KC_NA,   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
      KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, KC_NA,   KC_NA,   KC_NA,   KC_ALGR, KC_NA,
      KC_NP,   KC_NP,   KC_APP,  KC_SPC,  KC_TAB,  KC_NA,   KC_NA,   KC_NA,   KC_NP,   KC_NP
      ),
  [NSL] = LAYOUT_miryoku(
      KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_RST,
        _SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,  KC_NA,   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, KC_NA,   KC_NA,   KC_NA,   KC_ALGR, KC_NA,
      KC_NP,   KC_NP,   KC_DOT,  KC_0,    KC_MINS, KC_NA,   KC_NA,   KC_NA,   KC_NP,   KC_NP
      ),
  [NSSL] = LAYOUT_miryoku(
      KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_RST,
        _COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, KC_NA,   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, KC_NA,   KC_NA,   KC_NA,   KC_ALGR, KC_NA,
      KC_NP,   KC_NP,   KC_LPRN, KC_RPRN, KC_UNDS, KC_NA,   KC_NA,   KC_NA,   KC_NP,   KC_NP
      ),

  [MICROSNIPPET] = LAYOUT_miryoku(
      KC_TRNS, SS_W,    SS_F,    SS_P,    SS_B,    SS_J,    SS_L,    SS_U,    SS_Y,    KC_TRNS,
      KC_TRNS, SS_R,    SS_S,    SS_T,    SS_G,    SS_M,    SS_N,    SS_E,    SS_O,    KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, SS_D,    SS_V,    SS_K,    SS_H,    KC_TRNS, KC_TRNS, KC_TRNS,
      _____,   _____,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, _____,   _____
      )
};

/* Copyright 2021 weteor
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
/* #include "os_detection.h" */
#include "print.h"

enum layers
{
    _ALPHA_QWERTY = 0,
    _ALPHA_COLEMAK_DH,
    _ALPHA_QWERTY_PC,
    _SYM,
    _NUM,
    _NAV,
    _CFG,
};

/* bool process_detected_host_os_user(os_variant_t detected_os) { */
/*     switch (detected_os) { */
/*         case OS_MACOS: */
/*         case OS_IOS: */
/*             print("Detected mac or ios, setting default layer to _ALPHA_QWERTY"); */
/*             tap_code16(DF(_ALPHA_QWERTY)); */
/*             break; */
/*         case OS_WINDOWS: */
/*             print("Detected windows, setting default layer to _ALPHA_QWERTY_PC"); */
/*             tap_code16(DF(_ALPHA_QWERTY_PC)); */
/*             break; */
/*         case OS_LINUX: */
/*             print("Detected linux, setting default layer to _ALPHA_QWERTY_PC"); */
/*             tap_code16(DF(_ALPHA_QWERTY_PC)); */
/*             break; */
/*         case OS_UNSURE: */
/*             print("Detected unsure, setting default layer to _ALPHA_QWERTY"); */
/*             tap_code16(DF(_ALPHA_QWERTY)); */
/*             break; */
/*     } */

/*     return true; */
/* } */

/* // Define tap dance states */
/* typedef enum { */
/*     TD_NONE, */
/*     TD_SINGLE_TAP, */
/*     TD_SINGLE_HOLD, */
/* } td_state_t; */

/* // Create a struct to track the tap dance state */
/* typedef struct { */
/*     td_state_t state; */
/*     uint16_t timer; */
/*     uint16_t keycode; */
/*     bool is_pc_mode; */
/*     bool is_ctl_sft; */
/*     bool is_alt; */
/* } td_tap_t; */

/* // Define maximum number of custom keys (adjust as needed) */
/* #define NUM_CUSTOM_KEYS 5  // Example: comma, period, semicolon, etc. */
/* #define NUM_LETTER_KEYS 26 // A-Z */
/* #define TOTAL_KEYS (NUM_LETTER_KEYS + NUM_CUSTOM_KEYS) */

/* // Initialize tap dance states */
/* static td_tap_t td_states[TOTAL_KEYS * 2];  // Times 2 for PC/Mac modes */

/* // Function to determine tap dance state */
/* /1* td_state_t get_tap_dance_state(tap_dance_state_t *state) { *1/ */
/* /1*     if (state->interrupted || state->pressed == 0) { *1/ */
/* /1*         if (state->count == 1) { *1/ */
/* /1*             return TD_SINGLE_TAP; *1/ */
/* /1*         } *1/ */
/* /1*     } else if (state->pressed) { *1/ */
/* /1*         return TD_SINGLE_HOLD; *1/ */
/* /1*     } *1/ */
/* /1*     return TD_NONE; *1/ */
/* /1* } *1/ */

/* // Fixed state detection function */
/* td_state_t get_tap_dance_state(tap_dance_state_t *state) { */
/*     // If key was tapped (not held) */
/*     if (!state->pressed) { */
/*         return TD_SINGLE_TAP; */
/*     } */

/*     // If key is still being held */
/*     if (state->pressed) { */
/*         return TD_SINGLE_HOLD; */
/*     } */

/*     return TD_NONE; */
/* } */

/* // Calculate index for state array */
/* int get_state_index(uint16_t keycode, bool is_pc_mode) { */
/*     int base_index; */
/*     if (keycode >= KC_A && keycode <= KC_Z) { */
/*         base_index = keycode - KC_A; */
/*     } else { */
/*         // Custom keys start after the letters */
/*         switch (keycode) { */
/*             case KC_COMMA:  base_index = NUM_LETTER_KEYS + 0; break; */
/*             case KC_DOT:    base_index = NUM_LETTER_KEYS + 1; break; */
/*             case KC_ENT:   base_index = NUM_LETTER_KEYS + 2; break; */
/*             case KC_SPC:   base_index = NUM_LETTER_KEYS + 3; break; */
/*             case KC_BSPC:   base_index = NUM_LETTER_KEYS + 4; break; */
/*             default:        base_index = 0; break; */
/*         } */
/*     } */
/*     return base_index + (is_pc_mode ? TOTAL_KEYS : 0); */
/* } */

/* // Generic tap dance handler for keys */
/* void key_tap_dance_finished(tap_dance_state_t *state, void *user_data) { */
/*     td_tap_t *tap_data = (td_tap_t*)user_data; */
/*     uint16_t keycode = tap_data->keycode; */
/*     int index = get_state_index(keycode, tap_data->is_pc_mode); */
/*     td_states[index].state = get_tap_dance_state(state); */

/*     switch (td_states[index].state) { */
/*         case TD_SINGLE_TAP: */
/*             register_code(keycode); */
/*             break; */
/*         case TD_SINGLE_HOLD: */
/*             if (tap_data->is_ctl_sft) { */
/*                 register_code(KC_LCTL); */
/*                 register_code(KC_LSFT); */
/*             } else if (tap_data->is_alt) { */
/*                 register_code(KC_LALT); */
/*             } else if (tap_data->is_pc_mode) { */
/*                 register_code(KC_LCTL); */
/*             } else { */
/*                 register_code(KC_LGUI); */
/*             } */
/*             register_code(keycode); */
/*             break; */
/*         default: */
/*             break; */
/*     } */
/* } */

/* void key_tap_dance_reset(tap_dance_state_t *state, void *user_data) { */
/*     td_tap_t *tap_data = (td_tap_t*)user_data; */
/*     uint16_t keycode = tap_data->keycode; */
/*     int index = get_state_index(keycode, tap_data->is_pc_mode); */

/*     switch (td_states[index].state) { */
/*         case TD_SINGLE_TAP: */
/*             unregister_code(keycode); */
/*             break; */
/*         case TD_SINGLE_HOLD: */
/*             unregister_code(keycode); */
/*             if (tap_data->is_ctl_sft) { */
/*                 unregister_code(KC_LSFT); */
/*                 unregister_code(KC_LCTL); */
/*             } else if (tap_data->is_alt) { */
/*                 unregister_code(KC_LALT); */
/*             } else if (tap_data->is_pc_mode) { */
/*                 unregister_code(KC_LCTL); */
/*             } else { */
/*                 unregister_code(KC_LGUI); */
/*             } */
/*             break; */
/*         default: */
/*             break; */
/*     } */
/*     td_states[index].state = TD_NONE; */
/* } */

/* // Static storage for tap data */
/* static td_tap_t mac_tap_data[TOTAL_KEYS];  // For Mac mode (GUI) */
/* static td_tap_t pc_tap_data[TOTAL_KEYS];   // For PC mode (Control) */

/* // Initialize tap data */
/* void init_tap_data(void) { */
/*     // Initialize letter keys */
/*     for (int i = 0; i < NUM_LETTER_KEYS; i++) { */
/*         // Mac mode */
/*         mac_tap_data[i].keycode = KC_A + i; */
/*         mac_tap_data[i].is_pc_mode = false; */
/*         mac_tap_data[i].is_ctl_sft = false; */
/*         mac_tap_data[i].is_alt = false; */

/*         // PC mode */
/*         pc_tap_data[i].keycode = KC_A + i; */
/*         pc_tap_data[i].is_pc_mode = true; */
/*         pc_tap_data[i].is_ctl_sft = false; */
/*         pc_tap_data[i].is_alt = false; */
/*     } */

/*     // Initialize custom keys */
/*     int index = NUM_LETTER_KEYS; */

/*     // Comma */
/*     mac_tap_data[index].keycode = KC_COMMA; */
/*     mac_tap_data[index].is_pc_mode = false; */
/*     mac_tap_data[index].is_ctl_sft = false; */
/*     mac_tap_data[index].is_alt = false; */
/*     pc_tap_data[index].keycode = KC_COMMA; */
/*     pc_tap_data[index].is_pc_mode = true; */
/*     pc_tap_data[index].is_ctl_sft = false; */
/*     pc_tap_data[index].is_alt = false; */
/*     index++; */

/*     // Period */
/*     mac_tap_data[index].keycode = KC_DOT; */
/*     mac_tap_data[index].is_pc_mode = false; */
/*     mac_tap_data[index].is_ctl_sft = false; */
/*     mac_tap_data[index].is_alt = false; */
/*     pc_tap_data[index].keycode = KC_DOT; */
/*     pc_tap_data[index].is_pc_mode = true; */
/*     pc_tap_data[index].is_ctl_sft = false; */
/*     pc_tap_data[index].is_alt = false; */
/*     index++; */

/*     // Enter */
/*     mac_tap_data[index].keycode = KC_ENT; */
/*     mac_tap_data[index].is_pc_mode = false; */
/*     mac_tap_data[index].is_ctl_sft = true; */
/*     mac_tap_data[index].is_alt = false; */
/*     pc_tap_data[index].keycode = KC_ENT; */
/*     pc_tap_data[index].is_pc_mode = true; */
/*     pc_tap_data[index].is_ctl_sft  = true; */
/*     pc_tap_data[index].is_alt = false; */
/*     index++; */

/*     // Space */
/*     mac_tap_data[index].keycode = KC_SPC; */
/*     mac_tap_data[index].is_pc_mode = false; */
/*     mac_tap_data[index].is_ctl_sft = false; */
/*     mac_tap_data[index].is_alt = false; */
/*     pc_tap_data[index].keycode = KC_SPC; */
/*     pc_tap_data[index].is_pc_mode = true; */
/*     pc_tap_data[index].is_ctl_sft = false; */
/*     pc_tap_data[index].is_alt = false; */
/*     index++; */

/*     // Backspace */
/*     mac_tap_data[index].keycode = KC_BSPC; */
/*     mac_tap_data[index].is_pc_mode = false; */
/*     mac_tap_data[index].is_ctl_sft = false; */
/*     mac_tap_data[index].is_alt = true; */
/*     pc_tap_data[index].keycode = KC_BSPC; */
/*     pc_tap_data[index].is_pc_mode = true; */
/*     pc_tap_data[index].is_ctl_sft = false; */
/*     pc_tap_data[index].is_alt = true; */
/*     index++; */
/* } */

/* // Define tap dance actions for letters and custom keys - fixed macro definitions */
/* #define ACTION_TAP_DANCE_KEY_MAC(kc_name, array_index) \ */
/*     [TD_MAC_##kc_name] = { \ */
/*         .fn = { \ */
/*             NULL, \ */
/*             key_tap_dance_finished, \ */
/*             key_tap_dance_reset \ */
/*         }, \ */
/*         .user_data = (void*)&mac_tap_data[array_index] \ */
/*     } */

/* #define ACTION_TAP_DANCE_KEY_PC(kc_name, array_index) \ */
/*     [TD_PC_##kc_name] = { \ */
/*         .fn = { \ */
/*             NULL, \ */
/*             key_tap_dance_finished, \ */
/*             key_tap_dance_reset \ */
/*         }, \ */
/*         .user_data = (void*)&pc_tap_data[array_index] \ */
/*     } */

/* // Define tap dance actions for letters and custom keys */
/* /1* #define ACTION_TAP_DANCE_KEY_MAC(kc_name, array_index) \ *1/ */
/* /1*     [TD_MAC_##kc_name] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, key_tap_dance_finished, key_tap_dance_reset, \ *1/ */
/* /1*         (void*)&mac_tap_data[array_index]) *1/ */

/* /1* #define ACTION_TAP_DANCE_KEY_PC(kc_name, array_index) \ *1/ */
/* /1*     [TD_PC_##kc_name] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, key_tap_dance_finished, key_tap_dance_reset, \ *1/ */
/* /1*         (void*)&pc_tap_data[array_index]) *1/ */

/* enum tap_dance_codes { */
/*     // Mac mode tap dances */
/*     TD_MAC_A, */
/*     TD_MAC_B, */
/*     TD_MAC_C, */
/*     TD_MAC_D, */
/*     TD_MAC_E, */
/*     TD_MAC_F, */
/*     TD_MAC_G, */
/*     TD_MAC_H, */
/*     TD_MAC_I, */
/*     TD_MAC_J, */
/*     TD_MAC_K, */
/*     TD_MAC_L, */
/*     TD_MAC_M, */
/*     TD_MAC_N, */
/*     TD_MAC_O, */
/*     TD_MAC_P, */
/*     TD_MAC_Q, */
/*     TD_MAC_R, */
/*     TD_MAC_S, */
/*     TD_MAC_T, */
/*     TD_MAC_U, */
/*     TD_MAC_V, */
/*     TD_MAC_W, */
/*     TD_MAC_X, */
/*     TD_MAC_Y, */
/*     TD_MAC_Z, */
/*     TD_MAC_COMMA, */
/*     TD_MAC_DOT, */
/*     TD_MAC_ENT, */
/*     TD_MAC_SPC, */
/*     TD_MAC_BSPC, */

/*     // PC mode tap dances */
/*     TD_PC_A, */
/*     TD_PC_B, */
/*     TD_PC_C, */
/*     TD_PC_D, */
/*     TD_PC_E, */
/*     TD_PC_F, */
/*     TD_PC_G, */
/*     TD_PC_H, */
/*     TD_PC_I, */
/*     TD_PC_J, */
/*     TD_PC_K, */
/*     TD_PC_L, */
/*     TD_PC_M, */
/*     TD_PC_N, */
/*     TD_PC_O, */
/*     TD_PC_P, */
/*     TD_PC_Q, */
/*     TD_PC_R, */
/*     TD_PC_S, */
/*     TD_PC_T, */
/*     TD_PC_U, */
/*     TD_PC_V, */
/*     TD_PC_W, */
/*     TD_PC_X, */
/*     TD_PC_Y, */
/*     TD_PC_Z, */
/*     TD_PC_COMMA, */
/*     TD_PC_DOT, */
/*     TD_PC_ENT, */
/*     TD_PC_SPC, */
/*     TD_PC_BSPC, */
/* }; */

/* // Add these to your tap dance actions */
/* tap_dance_action_t tap_dance_actions[] = { */
/*     // Mac mode (GUI modifier) */
/*     ACTION_TAP_DANCE_KEY_MAC(A, 0), */
/*     ACTION_TAP_DANCE_KEY_MAC(B, 1), */
/*     ACTION_TAP_DANCE_KEY_MAC(C, 2), */
/*     ACTION_TAP_DANCE_KEY_MAC(D, 3), */
/*     ACTION_TAP_DANCE_KEY_MAC(E, 4), */
/*     ACTION_TAP_DANCE_KEY_MAC(F, 5), */
/*     ACTION_TAP_DANCE_KEY_MAC(G, 6), */
/*     ACTION_TAP_DANCE_KEY_MAC(H, 7), */
/*     ACTION_TAP_DANCE_KEY_MAC(I, 8), */
/*     ACTION_TAP_DANCE_KEY_MAC(J, 9), */
/*     ACTION_TAP_DANCE_KEY_MAC(K, 10), */
/*     ACTION_TAP_DANCE_KEY_MAC(L, 11), */
/*     ACTION_TAP_DANCE_KEY_MAC(M, 12), */
/*     ACTION_TAP_DANCE_KEY_MAC(N, 13), */
/*     ACTION_TAP_DANCE_KEY_MAC(O, 14), */
/*     ACTION_TAP_DANCE_KEY_MAC(P, 15), */
/*     ACTION_TAP_DANCE_KEY_MAC(Q, 16), */
/*     ACTION_TAP_DANCE_KEY_MAC(R, 17), */
/*     ACTION_TAP_DANCE_KEY_MAC(S, 18), */
/*     ACTION_TAP_DANCE_KEY_MAC(T, 19), */
/*     ACTION_TAP_DANCE_KEY_MAC(U, 20), */
/*     ACTION_TAP_DANCE_KEY_MAC(V, 21), */
/*     ACTION_TAP_DANCE_KEY_MAC(W, 22), */
/*     ACTION_TAP_DANCE_KEY_MAC(X, 23), */
/*     ACTION_TAP_DANCE_KEY_MAC(Y, 24), */
/*     ACTION_TAP_DANCE_KEY_MAC(Z, 25), */
/*     ACTION_TAP_DANCE_KEY_MAC(COMMA, 26),  // NUM_LETTER_KEYS + 0 */
/*     ACTION_TAP_DANCE_KEY_MAC(DOT, 27),    // NUM_LETTER_KEYS + 1 */
/*     ACTION_TAP_DANCE_KEY_MAC(ENT, 28),   // NUM_LETTER_KEYS + 2 */
/*     ACTION_TAP_DANCE_KEY_MAC(SPC, 29),   // NUM_LETTER_KEYS + 3 */
/*     ACTION_TAP_DANCE_KEY_MAC(BSPC, 30),   // NUM_LETTER_KEYS + 4 */

/*     // PC mode (Control modifier) */
/*     ACTION_TAP_DANCE_KEY_PC(A, 0), */
/*     ACTION_TAP_DANCE_KEY_PC(B, 1), */
/*     ACTION_TAP_DANCE_KEY_PC(C, 2), */
/*     ACTION_TAP_DANCE_KEY_PC(D, 3), */
/*     ACTION_TAP_DANCE_KEY_PC(E, 4), */
/*     ACTION_TAP_DANCE_KEY_PC(F, 5), */
/*     ACTION_TAP_DANCE_KEY_PC(G, 6), */
/*     ACTION_TAP_DANCE_KEY_PC(H, 7), */
/*     ACTION_TAP_DANCE_KEY_PC(I, 8), */
/*     ACTION_TAP_DANCE_KEY_PC(J, 9), */
/*     ACTION_TAP_DANCE_KEY_PC(K, 10), */
/*     ACTION_TAP_DANCE_KEY_PC(L, 11), */
/*     ACTION_TAP_DANCE_KEY_PC(M, 12), */
/*     ACTION_TAP_DANCE_KEY_PC(N, 13), */
/*     ACTION_TAP_DANCE_KEY_PC(O, 14), */
/*     ACTION_TAP_DANCE_KEY_PC(P, 15), */
/*     ACTION_TAP_DANCE_KEY_PC(Q, 16), */
/*     ACTION_TAP_DANCE_KEY_PC(R, 17), */
/*     ACTION_TAP_DANCE_KEY_PC(S, 18), */
/*     ACTION_TAP_DANCE_KEY_PC(T, 19), */
/*     ACTION_TAP_DANCE_KEY_PC(U, 20), */
/*     ACTION_TAP_DANCE_KEY_PC(V, 21), */
/*     ACTION_TAP_DANCE_KEY_PC(W, 22), */
/*     ACTION_TAP_DANCE_KEY_PC(X, 23), */
/*     ACTION_TAP_DANCE_KEY_PC(Y, 24), */
/*     ACTION_TAP_DANCE_KEY_PC(Z, 25), */
/*     ACTION_TAP_DANCE_KEY_PC(COMMA, 26),   // NUM_LETTER_KEYS + 0 */
/*     ACTION_TAP_DANCE_KEY_PC(DOT, 27),     // NUM_LETTER_KEYS + 1 */
/*     ACTION_TAP_DANCE_KEY_PC(ENT, 28),   // NUM_LETTER_KEYS + 2 */
/*     ACTION_TAP_DANCE_KEY_PC(SPC, 29),   // NUM_LETTER_KEYS + 3 */
/*     ACTION_TAP_DANCE_KEY_PC(BSPC, 30),   // NUM_LETTER_KEYS + 4 */
/* }; */

/* void keyboard_init_user(void) { */
/*     init_tap_data(); */
/* } */


/* const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { */


/*     [_ALPHA_QWERTY] = LAYOUT_split_3x5_3( */
/*         TD(TD_MAC_Q),    TD(TD_MAC_W),    TD(TD_MAC_E),    TD(TD_MAC_R),    TD(TD_MAC_T),                                                TD(TD_MAC_Y),    TD(TD_MAC_U),    TD(TD_MAC_I),     TD(TD_MAC_O),    TD(TD_MAC_P), */
/*         TD(TD_MAC_A),    TD(TD_MAC_S),    TD(TD_MAC_D),    TD(TD_MAC_F),    TD(TD_MAC_G),                                                TD(TD_MAC_H),    TD(TD_MAC_J),    TD(TD_MAC_K),     TD(TD_MAC_L),    TD(TD_MAC_BSPC), */
/*         TD(TD_MAC_Z),    TD(TD_MAC_X),    TD(TD_MAC_C),    TD(TD_MAC_V),    TD(TD_MAC_B),                                                TD(TD_MAC_N),    TD(TD_MAC_M),    TD(TD_MAC_COMMA), TD(TD_MAC_DOT),  LSA_T(KC_SLASH), */

/*                                                                                     KC_LCTL, MO(_SYM), KC_LSFT,     TD(TD_MAC_SPC), MO(_NUM), KC_LALT */
/*     ), */
/*     [_ALPHA_COLEMAK_DH] = LAYOUT_split_3x5_3( */
/*         TD(TD_MAC_Q),    TD(TD_MAC_W),    TD(TD_MAC_F),    TD(TD_MAC_P),    TD(TD_MAC_B),                                                TD(TD_MAC_J),    TD(TD_MAC_L),    TD(TD_MAC_U),     TD(TD_MAC_Y),    TD(TD_MAC_BSPC), */
/*         TD(TD_MAC_A),    TD(TD_MAC_R),    TD(TD_MAC_S),    TD(TD_MAC_T),    TD(TD_MAC_G),                                                TD(TD_MAC_M),    TD(TD_MAC_N),    TD(TD_MAC_E),     TD(TD_MAC_I),    TD(TD_MAC_O), */
/*         TD(TD_MAC_Z),    TD(TD_MAC_X),    TD(TD_MAC_C),    TD(TD_MAC_D),    TD(TD_MAC_V),                                                TD(TD_MAC_K),    TD(TD_MAC_H),    TD(TD_MAC_COMMA), TD(TD_MAC_DOT),  LSA_T(KC_SLASH), */
/*                                                                                     KC_LCTL, MO(_SYM), KC_LSFT,     TD(TD_MAC_SPC), MO(_NUM), KC_LALT */
/*     ), */
/*     [_ALPHA_QWERTY_PC] = LAYOUT_split_3x5_3( */
/*         TD(TD_PC_Q),    TD(TD_PC_W),    TD(TD_PC_E),    TD(TD_PC_R),    TD(TD_PC_T),                                                TD(TD_PC_Y),    TD(TD_PC_U),    TD(TD_PC_I),     TD(TD_PC_O),    TD(TD_PC_P), */
/*         TD(TD_PC_A),    TD(TD_PC_S),    TD(TD_PC_D),    TD(TD_PC_F),    TD(TD_PC_G),                                                TD(TD_PC_H),    TD(TD_PC_J),    TD(TD_PC_K),     TD(TD_PC_L),    TD(TD_PC_BSPC), */
/*         TD(TD_PC_Z),    TD(TD_PC_X),    TD(TD_PC_C),    TD(TD_PC_V),    TD(TD_PC_B),                                                TD(TD_PC_N),    TD(TD_PC_M),    TD(TD_PC_COMMA), TD(TD_PC_DOT),  LSA_T(KC_SLASH), */
/*                                                                                     KC_LCTL, MO(_SYM), KC_LSFT,     TD(TD_PC_SPC), MO(_NUM), KC_LALT */
/*     ), */
/*     [_SYM] = LAYOUT_split_3x5_3( */
/*         RSFT(KC_1), RSFT(KC_2),   RSFT(KC_3),  RSFT(KC_4), RSFT(KC_5),                                RSFT(KC_6), RSFT(KC_7), RSFT(KC_8), KC_SCLN, RSFT(KC_SCLN), */
/*         KC_ESC, KC_LCTL, RCS_T(KC_ENT), KC_TAB,  KC_LSFT,                                KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_QUOT, */
/*         XXXXXXX, XXXXXXX, XXXXXXX, LCA(KC_DELETE), KC_LGUI,                                KC_HOME, KC_END, KC_PGDN, KC_PGUP, RSFT(KC_QUOTE), */
/*                                         XXXXXXX, XXXXXXX, KC_TRNS,     KC_RALT, MO(_NAV), KC_TRNS */
/*     ), */
/*     [_NUM] = LAYOUT_split_3x5_3( */
/*         KC_ESC,  XXXXXXX, LSFT(KC_9), LSFT(KC_0), LSFT(KC_MINUS),                                    KC_MINUS,  KC_7,  KC_8,  KC_9, KC_DOT, */
/*         KC_TAB,  LSFT(KC_BSLS),  LSFT(KC_LBRC),  LSFT(KC_RBRC),  LSFT(KC_EQUAL),           KC_EQUAL,  KC_4,  KC_5,  KC_6, KC_ENT, */
/*         KC_GRAVE,  LSFT(KC_GRAVE),  KC_LBRC,  KC_RBRC,  KC_BSLS,                           KC_0,  KC_1,  KC_2,  KC_3, KC_PAST, */
/*                                                                     KC_LALT, MO(_CFG), KC_LSFT,      XXXXXXX, XXXXXXX, KC_TRNS */
/*     ), */
/*     [_NAV] = LAYOUT_split_3x5_3( */
/*         KC_WH_L, KC_WH_R, KC_MS_U, XXXXXXX, KC_MUTE,                                KC_MRWD, KC_MPRV, KC_MNXT, KC_BRIU,  KC_VOLU, */
/*         XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_LSFT,                                KC_MFFD, KC_BTN1, KC_BTN2, KC_BRID,  KC_VOLD, */
/*         XXXXXXX, KC_MPLY, KC_WH_D, KC_WH_U, KC_LGUI,                                XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX, */
/*                                         XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX */
/*     ), */
/*     [_CFG] = LAYOUT_split_3x5_3( */
/*         QK_BOOT, QK_REBOOT, XXXXXXX, XXXXXXX, XXXXXXX,                                              XXXXXXX, KC_F9, KC_F10, KC_F11, KC_F12, */
/*         XXXXXXX, XXXXXXX, DF(_ALPHA_COLEMAK_DH), DF(_ALPHA_QWERTY), DF(_ALPHA_QWERTY_PC),           XXXXXXX, KC_F5, KC_F6, KC_F7, KC_F8, */
/*         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                                XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F4, */
/*                                                 XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX */
/*     ), */
/* }; */




enum {
    TD_Q,
    TD_W,
    TD_E,
    TD_R,
    TD_T,
    TD_Y,
    TD_U,
    TD_I,
    TD_O,
    TD_P,
    TD_A,
    TD_S,
    TD_D,
    TD_F,
    TD_G,
    TD_H,
    TD_J,
    TD_K,
    TD_L,
    TD_Z,
    TD_X,
    TD_C,
    TD_V,
    TD_B,
    TD_N,
    TD_M,
    TD_COMMA,
    TD_DOT,
    TD_ENT,
    TD_SPC,
    TD_BSPC,
    TD_Q_PC,
    TD_W_PC,
    TD_E_PC,
    TD_R_PC,
    TD_T_PC,
    TD_Y_PC,
    TD_U_PC,
    TD_I_PC,
    TD_O_PC,
    TD_P_PC,
    TD_A_PC,
    TD_S_PC,
    TD_D_PC,
    TD_F_PC,
    TD_G_PC,
    TD_H_PC,
    TD_J_PC,
    TD_K_PC,
    TD_L_PC,
    TD_Z_PC,
    TD_X_PC,
    TD_C_PC,
    TD_V_PC,
    TD_B_PC,
    TD_N_PC,
    TD_M_PC,
    TD_SPC_PC,
    TD_COMMA_PC,
    TD_DOT_PC,
};


typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }

tap_dance_action_t tap_dance_actions[] = {
    [TD_Q] = ACTION_TAP_DANCE_TAP_HOLD(KC_Q, LGUI(KC_Q)),
    [TD_W] = ACTION_TAP_DANCE_TAP_HOLD(KC_W, LGUI(KC_W)),
    [TD_E] = ACTION_TAP_DANCE_TAP_HOLD(KC_E, LGUI(KC_E)),
    [TD_R] = ACTION_TAP_DANCE_TAP_HOLD(KC_R, LGUI(KC_R)),
    [TD_T] = ACTION_TAP_DANCE_TAP_HOLD(KC_T, LGUI(KC_T)),
    [TD_Y] = ACTION_TAP_DANCE_TAP_HOLD(KC_Y, LGUI(KC_Y)),
    [TD_U] = ACTION_TAP_DANCE_TAP_HOLD(KC_U, LGUI(KC_U)),
    [TD_I] = ACTION_TAP_DANCE_TAP_HOLD(KC_I, LGUI(KC_I)),
    [TD_O] = ACTION_TAP_DANCE_TAP_HOLD(KC_O, LGUI(KC_O)),
    [TD_P] = ACTION_TAP_DANCE_TAP_HOLD(KC_P, LGUI(KC_P)),
    [TD_A] = ACTION_TAP_DANCE_TAP_HOLD(KC_A, LGUI(KC_A)),
    [TD_S] = ACTION_TAP_DANCE_TAP_HOLD(KC_S, LGUI(KC_S)),
    [TD_D] = ACTION_TAP_DANCE_TAP_HOLD(KC_D, LGUI(KC_D)),
    [TD_F] = ACTION_TAP_DANCE_TAP_HOLD(KC_F, LGUI(KC_F)),
    [TD_G] = ACTION_TAP_DANCE_TAP_HOLD(KC_G, LGUI(KC_G)),
    [TD_H] = ACTION_TAP_DANCE_TAP_HOLD(KC_H, LGUI(KC_H)),
    [TD_J] = ACTION_TAP_DANCE_TAP_HOLD(KC_J, LGUI(KC_J)),
    [TD_K] = ACTION_TAP_DANCE_TAP_HOLD(KC_K, LGUI(KC_K)),
    [TD_L] = ACTION_TAP_DANCE_TAP_HOLD(KC_L, LGUI(KC_L)),
    [TD_Z] = ACTION_TAP_DANCE_TAP_HOLD(KC_Z, LGUI(KC_Z)),
    [TD_X] = ACTION_TAP_DANCE_TAP_HOLD(KC_X, LGUI(KC_X)),
    [TD_C] = ACTION_TAP_DANCE_TAP_HOLD(KC_C, LGUI(KC_C)),
    [TD_V] = ACTION_TAP_DANCE_TAP_HOLD(KC_V, LGUI(KC_V)),
    [TD_B] = ACTION_TAP_DANCE_TAP_HOLD(KC_B, LGUI(KC_B)),
    [TD_N] = ACTION_TAP_DANCE_TAP_HOLD(KC_N, LGUI(KC_N)),
    [TD_M] = ACTION_TAP_DANCE_TAP_HOLD(KC_M, LGUI(KC_M)),
    [TD_SPC] = ACTION_TAP_DANCE_TAP_HOLD(KC_SPC, LGUI(KC_SPC)),
    [TD_ENT] = ACTION_TAP_DANCE_TAP_HOLD(KC_ENT, LCTL(LSFT(KC_ENT))),
    [TD_COMMA] = ACTION_TAP_DANCE_TAP_HOLD(KC_COMM, LGUI(KC_COMM)),
    [TD_DOT] = ACTION_TAP_DANCE_TAP_HOLD(KC_DOT, LGUI(KC_DOT)),
    [TD_BSPC] = ACTION_TAP_DANCE_TAP_HOLD(KC_BSPC, LALT(KC_BSPC)),
    [TD_Q_PC] = ACTION_TAP_DANCE_TAP_HOLD(KC_Q, LCTL(KC_Q)),
    [TD_W_PC] = ACTION_TAP_DANCE_TAP_HOLD(KC_W, LCTL(KC_W)),
    [TD_E_PC] = ACTION_TAP_DANCE_TAP_HOLD(KC_E, LCTL(KC_E)),
    [TD_R_PC] = ACTION_TAP_DANCE_TAP_HOLD(KC_R, LCTL(KC_R)),
    [TD_T_PC] = ACTION_TAP_DANCE_TAP_HOLD(KC_T, LCTL(KC_T)),
    [TD_Y_PC] = ACTION_TAP_DANCE_TAP_HOLD(KC_Y, LCTL(KC_Y)),
    [TD_U_PC] = ACTION_TAP_DANCE_TAP_HOLD(KC_U, LCTL(KC_U)),
    [TD_I_PC] = ACTION_TAP_DANCE_TAP_HOLD(KC_I, LCTL(KC_I)),
    [TD_O_PC] = ACTION_TAP_DANCE_TAP_HOLD(KC_O, LCTL(KC_O)),
    [TD_P_PC] = ACTION_TAP_DANCE_TAP_HOLD(KC_P, LCTL(KC_P)),
    [TD_A_PC] = ACTION_TAP_DANCE_TAP_HOLD(KC_A, LCTL(KC_A)),
    [TD_S_PC] = ACTION_TAP_DANCE_TAP_HOLD(KC_S, LCTL(KC_S)),
    [TD_D_PC] = ACTION_TAP_DANCE_TAP_HOLD(KC_D, LCTL(KC_D)),
    [TD_F_PC] = ACTION_TAP_DANCE_TAP_HOLD(KC_F, LCTL(KC_F)),
    [TD_G_PC] = ACTION_TAP_DANCE_TAP_HOLD(KC_G, LCTL(KC_G)),
    [TD_H_PC] = ACTION_TAP_DANCE_TAP_HOLD(KC_H, LCTL(KC_H)),
    [TD_J_PC] = ACTION_TAP_DANCE_TAP_HOLD(KC_J, LCTL(KC_J)),
    [TD_K_PC] = ACTION_TAP_DANCE_TAP_HOLD(KC_K, LCTL(KC_K)),
    [TD_L_PC] = ACTION_TAP_DANCE_TAP_HOLD(KC_L, LCTL(KC_L)),
    [TD_Z_PC] = ACTION_TAP_DANCE_TAP_HOLD(KC_Z, LCTL(KC_Z)),
    [TD_X_PC] = ACTION_TAP_DANCE_TAP_HOLD(KC_X, LCTL(KC_X)),
    [TD_C_PC] = ACTION_TAP_DANCE_TAP_HOLD(KC_C, LCTL(KC_C)),
    [TD_V_PC] = ACTION_TAP_DANCE_TAP_HOLD(KC_V, LCTL(KC_V)),
    [TD_B_PC] = ACTION_TAP_DANCE_TAP_HOLD(KC_B, LCTL(KC_B)),
    [TD_N_PC] = ACTION_TAP_DANCE_TAP_HOLD(KC_N, LCTL(KC_N)),
    [TD_M_PC] = ACTION_TAP_DANCE_TAP_HOLD(KC_M, LCTL(KC_M)),
    [TD_SPC_PC] = ACTION_TAP_DANCE_TAP_HOLD(KC_SPC, LCTL(KC_SPC)),
    [TD_COMMA_PC] = ACTION_TAP_DANCE_TAP_HOLD(KC_COMM, LCTL(KC_COMM)),
    [TD_DOT_PC] = ACTION_TAP_DANCE_TAP_HOLD(KC_DOT, LCTL(KC_DOT)),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    tap_dance_action_t *action;

    switch (keycode) {
        case TD(TD_Q):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_W):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_E):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_R):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_T):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_Y):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_U):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_I):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_O):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_P):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_A):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_S):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_D):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_F):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_G):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_H):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_J):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_K):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_L):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_Z):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_X):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_C):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_V):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_B):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_N):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_M):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_COMMA):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_DOT):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_ENT):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_BSPC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_SPC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_Q_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_W_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_E_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_R_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_T_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_Y_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_U_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_I_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_O_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_P_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_A_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_S_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_D_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_F_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_G_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_H_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_J_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_K_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_L_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_Z_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_X_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_C_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_V_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_B_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_N_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_M_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_COMMA_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_DOT_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
        case TD(TD_SPC_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
    }
    return true;
}




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    [_ALPHA_QWERTY] = LAYOUT_split_3x5_3(
        TD(TD_Q),    TD(TD_W),    TD(TD_E),    TD(TD_R),    TD(TD_T),                                                TD(TD_Y),    TD(TD_U),    TD(TD_I),     TD(TD_O),    TD(TD_P),
        TD(TD_A),    TD(TD_S),    TD(TD_D),    TD(TD_F),    TD(TD_G),                                                TD(TD_H),    TD(TD_J),    TD(TD_K),     TD(TD_L),    TD(TD_BSPC),
        TD(TD_Z),    TD(TD_X),    TD(TD_C),    TD(TD_V),    TD(TD_B),                                                TD(TD_N),    TD(TD_M),    TD(TD_COMMA), TD(TD_DOT),  LSA_T(KC_SLASH),

                                                                                    KC_LCTL, MO(_SYM), KC_LSFT,     TD(TD_SPC), MO(_NUM), KC_LALT
    ),
    [_ALPHA_COLEMAK_DH] = LAYOUT_split_3x5_3(
        TD(TD_Q),    TD(TD_W),    TD(TD_F),    TD(TD_P),    TD(TD_B),                                                TD(TD_J),    TD(TD_L),    TD(TD_U),     TD(TD_Y),    TD(TD_BSPC),
        TD(TD_A),    TD(TD_R),    TD(TD_S),    TD(TD_T),    TD(TD_G),                                                TD(TD_M),    TD(TD_N),    TD(TD_E),     TD(TD_I),    TD(TD_O),
        TD(TD_Z),    TD(TD_X),    TD(TD_C),    TD(TD_D),    TD(TD_V),                                                TD(TD_K),    TD(TD_H),    TD(TD_COMMA), TD(TD_DOT),  LSA_T(KC_SLASH),
                                                                                    KC_LCTL, MO(_SYM), KC_LSFT,     TD(TD_SPC), MO(_NUM), KC_LALT
    ),
    [_ALPHA_QWERTY_PC] = LAYOUT_split_3x5_3(
        TD(TD_Q_PC),    TD(TD_W_PC),    TD(TD_E_PC),    TD(TD_R_PC),    TD(TD_T_PC),                                                TD(TD_Y_PC),    TD(TD_U_PC),    TD(TD_I_PC),     TD(TD_O_PC),    TD(TD_P_PC),
        TD(TD_A_PC),    TD(TD_S_PC),    TD(TD_D_PC),    TD(TD_F_PC),    TD(TD_G_PC),                                                TD(TD_H_PC),    TD(TD_J_PC),    TD(TD_K_PC),     TD(TD_L_PC),    TD(TD_BSPC),
        TD(TD_Z_PC),    TD(TD_X_PC),    TD(TD_C_PC),    TD(TD_V_PC),    TD(TD_B_PC),                                                TD(TD_N_PC),    TD(TD_M_PC),    TD(TD_COMMA_PC), TD(TD_DOT_PC),  LSA_T(KC_SLASH),
                                                                                    KC_LCTL, MO(_SYM), KC_LSFT,     TD(TD_SPC), MO(_NUM), KC_LALT
    ),
    [_SYM] = LAYOUT_split_3x5_3(
        RSFT(KC_1), RSFT(KC_2),   RSFT(KC_3),  RSFT(KC_4), RSFT(KC_5),                                RSFT(KC_6), RSFT(KC_7), RSFT(KC_8), KC_SCLN, RSFT(KC_SCLN),
        KC_ESC, KC_LCTL, RCS_T(KC_ENT), KC_TAB,  KC_LSFT,                                KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_QUOT,
        XXXXXXX, XXXXXXX, XXXXXXX, LCA(KC_DELETE), KC_LGUI,                                KC_HOME, KC_END, KC_PGDN, KC_PGUP, RSFT(KC_QUOTE),
                                        XXXXXXX, XXXXXXX, KC_TRNS,     KC_RALT, MO(_NAV), KC_TRNS
    ),
    [_NUM] = LAYOUT_split_3x5_3(
        KC_ESC,  XXXXXXX, LSFT(KC_9), LSFT(KC_0), LSFT(KC_MINUS),                                    KC_MINUS,  KC_7,  KC_8,  KC_9, KC_DOT,
        KC_TAB,  LSFT(KC_BSLS),  LSFT(KC_LBRC),  LSFT(KC_RBRC),  LSFT(KC_EQUAL),           KC_EQUAL,  KC_4,  KC_5,  KC_6, KC_ENT,
        KC_GRAVE,  LSFT(KC_GRAVE),  KC_LBRC,  KC_RBRC,  KC_BSLS,                           KC_0,  KC_1,  KC_2,  KC_3, KC_PAST,
                                                                    KC_LALT, MO(_CFG), KC_LSFT,      XXXXXXX, XXXXXXX, KC_TRNS
    ),
    [_NAV] = LAYOUT_split_3x5_3(
        KC_WH_L, KC_WH_R, KC_MS_U, XXXXXXX, KC_MUTE,                                KC_MRWD, KC_MPRV, KC_MNXT, KC_BRIU,  KC_VOLU,
        XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_LSFT,                                KC_MFFD, KC_BTN1, KC_BTN2, KC_BRID,  KC_VOLD,
        XXXXXXX, KC_MPLY, KC_WH_D, KC_WH_U, KC_LGUI,                                XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX,
                                        XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_CFG] = LAYOUT_split_3x5_3(
        QK_BOOT, QK_REBOOT, XXXXXXX, XXXXXXX, XXXXXXX,                                              XXXXXXX, KC_F9, KC_F10, KC_F11, KC_F12,
        XXXXXXX, XXXXXXX, DF(_ALPHA_COLEMAK_DH), DF(_ALPHA_QWERTY), DF(_ALPHA_QWERTY_PC),           XXXXXXX, KC_F5, KC_F6, KC_F7, KC_F8,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                                XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F4,
                                                XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX
    ),
};

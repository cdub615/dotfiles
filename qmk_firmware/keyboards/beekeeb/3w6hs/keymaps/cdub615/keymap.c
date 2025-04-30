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
    _ALPHA_COLEMAK_DH = 0,
    _ALPHA_QWERTY,
    _SYM,
    _NUM,
    _NAV,
    _CFG,
};

enum {
    TD_QUOT_DBLQUOT,
};

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    tap_dance_action_t *action;

    switch (keycode) {
        case TD(TD_QUOT_DBLQUOT):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
    }
    return true;
}

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
    [TD_QUOT_DBLQUOT] = ACTION_TAP_DANCE_TAP_HOLD(KC_QUOTE, RSFT(KC_QUOTE)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_ALPHA_COLEMAK_DH] = LAYOUT_split_3x5_3(
        C_S_T(KC_Q),    LSA_T(KC_W),    LSG_T(KC_F),    KC_P,    KC_B,                     KC_J,    KC_L,    KC_U,     KC_Y,    KC_QUOTE,
        KC_A,  KC_R,  KC_S,  KC_T,  LT(_CFG, KC_G),                                 KC_M,    KC_N,    KC_E,     KC_I,    KC_O,
        LGUI_T(KC_Z),  LALT_T(KC_X),  LCTL_T(KC_C),  LSFT_T(KC_D),  KC_V,           KC_K,    RSFT_T(KC_H),    RCTL_T(KC_COMMA),     RALT_T(KC_DOT),    RGUI_T(KC_SLASH),
                                    LT(_NAV, KC_ESC), LT(_SYM, KC_TAB), KC_ENT,     KC_BSPC, LT(_NUM, KC_SPC), LT(_NAV, KC_DEL)
    ),
    [_ALPHA_QWERTY] = LAYOUT_split_3x5_3(
        C_S_T(KC_Q),    LSA_T(KC_W),    LSG_T(KC_E),    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,     KC_O,    KC_QUOTE,
        KC_A,  KC_S,  KC_D,  KC_F,  LT(_CFG, KC_G),                                 KC_H,    KC_J,     KC_K,     KC_L,    KC_P,
        LGUI_T(KC_Z),  LALT_T(KC_X),  LCTL_T(KC_C),  LSFT_T(KC_V),  KC_B,           KC_N,    RSFT_T(KC_M),    RCTL_T(KC_COMMA),     RALT_T(KC_DOT),    RGUI_T(KC_SLASH),
                                    LT(_NAV, KC_ESC), LT(_SYM, KC_TAB), KC_ENT,     KC_BSPC, LT(_NUM, KC_SPC), LT(_NAV, KC_DEL)
    ),
    [_SYM] = LAYOUT_split_3x5_3(
        RSFT(KC_1), RSFT(KC_2),   RSFT(KC_3),  RSFT(KC_4), RSFT(KC_5),                                RSFT(KC_6), RSFT(KC_7), RSFT(KC_8), KC_SCLN, RSFT(KC_SCLN),
        KC_ESC, KC_LCTL, RCS_T(KC_ENT), KC_TAB,  KC_LSFT,                                KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_QUOT,
        KC_DEL, KC_DEL, KC_DEL, LCA(KC_DELETE), KC_LGUI,                                KC_HOME, KC_END, KC_PGDN, KC_PGUP, RSFT(KC_QUOTE),
                                        XXXXXXX, XXXXXXX, KC_TRNS,     KC_RALT, MO(_NAV), KC_TRNS
    ),
    [_NUM] = LAYOUT_split_3x5_3(
        KC_ESC,  XXXXXXX, LSFT(KC_9), LSFT(KC_0), LSFT(KC_MINUS),                                    KC_MINUS,  KC_7,  KC_8,  KC_9, KC_DOT,
        KC_TAB,  LSFT(KC_BSLS),  LSFT(KC_LBRC),  LSFT(KC_RBRC),  LSFT(KC_EQUAL),           KC_EQUAL,  KC_4,  KC_5,  KC_6, KC_ENT,
        KC_GRAVE,  LSFT(KC_GRAVE),  KC_LBRC,  KC_RBRC,  KC_BSLS,                           KC_0,  KC_1,  KC_2,  KC_3, KC_PAST,
                                        KC_LALT, MO(_CFG), KC_LSFT,      XXXXXXX, XXXXXXX, KC_TRNS
    ),
    [_NAV] = LAYOUT_split_3x5_3(
        XXXXXXX, KC_WH_L, KC_MS_U, KC_WH_R, KC_MUTE,                                KC_MRWD, KC_MPRV, KC_MNXT, KC_BRIU,  KC_VOLU,
        XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_LSFT,                                KC_MFFD, KC_BTN1, KC_BTN2, KC_BRID,  KC_VOLD,
        XXXXXXX, XXXXXXX, KC_WH_D, KC_WH_U, KC_LGUI,                                KC_MPLY, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX,
                                        XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_CFG] = LAYOUT_split_3x5_3(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, KC_F9, KC_F10, KC_F11, KC_F12,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            DF(_ALPHA_COLEMAK_DH), KC_F5, KC_F6, KC_F7, KC_F8,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            DF(_ALPHA_QWERTY), KC_F1, KC_F2, KC_F3, KC_F4,
                                    QK_BOOT, QK_REBOOT, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX
    ),
};

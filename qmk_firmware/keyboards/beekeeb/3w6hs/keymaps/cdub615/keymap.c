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
#include "os_detection.h"

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


bool process_detected_host_os_user(os_variant_t detected_os) {
    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
            tap_code16(DF(_ALPHA_QWERTY));
            break;
        case OS_WINDOWS:
            tap_code16(DF(_ALPHA_QWERTY_PC));
            break;
        case OS_LINUX:
            tap_code16(DF(_ALPHA_QWERTY_PC));
            break;
        case OS_UNSURE:
            tap_code16(DF(_ALPHA_QWERTY));
            break;
    }

    return true;
}

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
        case TD(TD_W):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_E):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_R):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_T):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_Y):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_U):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_I):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_O):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_P):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_A):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_S):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_D):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_F):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_G):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_H):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_J):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_K):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_L):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_Z):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_X):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_C):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_V):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_B):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_N):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_M):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_COMMA):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_DOT):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_ENT):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_BSPC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_SPC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_Q_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_W_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_E_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_R_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_T_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_Y_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_U_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_I_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_O_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_P_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_A_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_S_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_D_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_F_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_G_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_H_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_J_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_K_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_L_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_Z_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_X_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_C_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_V_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_B_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_N_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_M_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_COMMA_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_DOT_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(TD_SPC_PC):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
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
        KC_ESC, KC_LCTL, TD(TD_ENT), KC_TAB,  KC_LSFT,                                KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_COMMA,
        XXXXXXX, XXXXXXX, XXXXXXX, LCA(KC_DELETE), KC_LGUI,                                KC_HOME, KC_END, KC_PGDN, KC_PGUP, RSFT(KC_QUOTE),
                                        XXXXXXX, XXXXXXX, KC_TRNS,     KC_RALT, MO(_NAV), KC_TRNS
    ),
    [_NUM] = LAYOUT_split_3x5_3(
        KC_ESC,  XXXXXXX, LSFT(KC_9), LSFT(KC_0), LSFT(KC_MINUS),                                    KC_MINUS,  KC_7,  KC_8,  KC_9, KC_DOT,
        KC_TAB,  LSFT(KC_BSLS),  LSFT(KC_LBRC),  LSFT(KC_RBRC),  LSFT(KC_EQUAL),           KC_EQUAL,  KC_4,  KC_5,  KC_6, KC_ENT,
        KC_GRAVE,  LSFT(KC_GRAVE),  KC_LBRC,  KC_RBRC,  KC_BSLS,                           KC_0,  KC_1,  KC_2,  KC_3, KC_PAST,
                                                                    KC_LALT, MO(_NAV), KC_LSFT,      XXXXXXX, XXXXXXX, KC_TRNS
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

/* Copyright 2019 Takuya Urakawa (dm9records.com)
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

extern keymap_config_t keymap_config;

enum plaid_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum plaid_keycodes {
  QWERTY = SAFE_RANGE,
  EXT_PLV
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define KC_SCST SGUI(KC_4)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_plaid_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_LBRC,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_SCST, KC_ESC,  KC_LALT, KC_LGUI, LOWER,   KC_SPC,  RAISE,   KC_ENT,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

[_LOWER] = LAYOUT_plaid_grid(
    _______, KC_1,    KC_2,    KC_3,     KC_4,    KC_5,    S(KC_EQL), S(KC_MINS), S(KC_QUOT), S(KC_BSLS), S(KC_GRV), _______, \
    _______, KC_6,    KC_7,    KC_8,     KC_9,    KC_0,    KC_EQL,    KC_MINS,    KC_QUOT,    KC_BSLS,    KC_GRV,    KC_RBRC, \
    _______, S(KC_1), S(KC_2), S(KC_3),  S(KC_4), S(KC_5), S(KC_6),   S(KC_7),    S(KC_8),    S(KC_9),    S(KC_0),   _______,\
    _______, _______, _______, _______,  _______, _______, _______,   _______,    KC_HOME,    KC_PGDN,    KC_PGUP,   KC_END \
),

[_RAISE] = LAYOUT_plaid_grid(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,  _______, KC_UP,   _______, _______, _______,
    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,   _______,  KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
    _______, KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, KC_NUHS,  KC_NUBS, KC_PGUP, KC_PGDN, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,  _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

[_ADJUST] = LAYOUT_plaid_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  _______, _______, _______,  _______, _______, _______,  _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)


};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

/* Copyright 2018
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

enum foobar_layers {
  QWERTY,
  LOWER,
  RAISE
};

#define LCTL_A      LCTL_T(KC_A)
#define RCTL_SPC    RCTL_T(KC_SPC)

#define LSHIFT_Z    LSFT_T(KC_Z)
#define LGUI_X      LGUI_T(KC_X)
#define LALT_C      LALT_T(KC_C)
#define LOWER_V     LT(LOWER, KC_V)

#define LGUI_X      LGUI_T(KC_X)
#define RAISE_M     LT(RAISE, KC_M)
#define RALT_COMM   RALT_T(KC_COMM)
#define RGUI_DOT    RGUI_T(KC_DOT)
#define RSHIFT_ENT  RSFT_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [QWERTY] = LAYOUT_split(
    KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,      KC_O,     KC_P,
    LCTL_A,   KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,      KC_L,     RCTL_SPC,
    LSHIFT_Z, LGUI_X,  KC_C,    LOWER_V, KC_B,    KC_N,    RAISE_M, RALT_COMM, RGUI_DOT, RSHIFT_ENT
  ),

  [LOWER] = LAYOUT_split(
    KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_MINS, KC_EQL,  KC_QUOT, KC_GRV,  KC_LBRC,
    KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_SCLN, KC_COLN, KC_RBRC, _______,
    _______,  _______, _______, _______, KC_DEL,  KC_F12,  _______, KC_SLSH, KC_BSLS, _______
  ),

  [RAISE] = LAYOUT_split(
    KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    XXXXXXX,  KC_ESC,  XXXXXXX, KC_TAB,  KC_ENT,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
    _______,  _______, _______, _______, KC_BSPC, KC_SPC,  _______, _______, _______, _______
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

/* Copyright 2019 yoshihara
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

enum Layer
{
	DF,
	LW,
	RS
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[DF] = LAYOUT(
              LGUI(KC_Z), KC_B, KC_E,       LT(LW, KC_SPC),
              SGUI(KC_Z), KC_S, LGUI(KC_D), LT(RS, KC_V)
              ),
[LW]= LAYOUT(
             KC_L,       KC_RBRC,    LGUI(KC_RBRC), _______,
             LGUI(KC_X), LGUI(KC_C), LGUI(KC_V),    _______
             ),
[RS]= LAYOUT(
             KC_C, KC_LBRC,    LGUI(KC_LBRC), _______,
             KC_X, LGUI(KC_K), KC_LALT,       _______
             )

};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}

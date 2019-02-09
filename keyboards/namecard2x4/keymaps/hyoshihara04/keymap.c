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
              LGUI(KC_Z), KC_B, LSFT(KC_RBRC), LT(LW, KC_SPC),
              SGUI(KC_Z), KC_E, LSFT(KC_LBRC), LT(RS, KC_X)
              ),
[LW]= LAYOUT(
             KC_L,       KC_S, LGUI(KC_RBRC), _______,
             LGUI(KC_D), KC_V, LGUI(KC_LBRC), _______
             ),
[RS]= LAYOUT(
             LGUI(KC_C), LGUI(KC_X), XXXXXXX, _______,
             KC_C      , LGUI(KC_V), XXXXXXX, _______
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

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
	BASE,
        EDIT,
        MENU
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  LT_REDO = SAFE_RANGE,
  LT_UNDO
};

static bool redo_pressed = false;
#define REDO_LAYER EDIT // redoを押しっぱにしたときに移動するレイヤー
static bool undo_pressed = false;
#define UNDO_LAYER MENU // undoを押しっぱにしたときに移動するレイヤー

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   /* 薬指 中指 */
   /* 小指 人差し指 */
   /* 親指 */
  [BASE] = LAYOUT( /* Base */
    KC_C,    KC_E, \
    LT_REDO, KC_B, \
    LT_UNDO \
  ),
  [MENU] = LAYOUT( /* other tool and MENU */
    KC_L,    KC_LALT, \
    _______, KC_SPC, \
    _______ \
  ),
  [EDIT] = LAYOUT( /* Edit (cut&copy&paste) */
    LGUI(KC_X),    LGUI(KC_V), \
    _______, LGUI(KC_C), \
    _______ \
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // c.f. http://okapies.hateblo.jp/entry/2019/02/02/133953
  switch (keycode) {
    case LT_REDO:
      // 他のキーが押されたらLT、単独ならredo
      if (record->event.pressed) {
        redo_pressed = true;

        layer_on(REDO_LAYER);
      } else {
        layer_off(REDO_LAYER);

        if (redo_pressed) {
          SEND_STRING(SS_LGUI(SS_LSFT("z")));
        }
        redo_pressed = false;
      }
      return false;
      break;
    case LT_UNDO:
      // 他のキーが押されたらLT、単独ならundo
      if (record->event.pressed) {
        undo_pressed = true;

        layer_on(UNDO_LAYER);
      } else {
        layer_off(UNDO_LAYER);

        if (undo_pressed) {
          SEND_STRING(SS_LGUI("z"));
        }
        undo_pressed = false;
      }
      return false;
      break;
    default:
      if (record->event.pressed) {
        // reset the flag
        redo_pressed = false;
        undo_pressed = false;
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

#include QMK_KEYBOARD_H

#define BASE 0
#define SYMB 1
#define NUMS 2

// https://docs.qmk.fm/#/feature_tap_dance
//Tap Dance Declarations
enum {
  TD_MINS_Q = 0,
  TD_COMM_DOT = 1
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for comma, twice for Caps dot
  [TD_MINS_Q]   = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_Q),
  [TD_COMM_DOT] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_DOT)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_ortho_3x10(
    TD(TD_MINS_Q),  KC_W, TD(TD_COMM_DOT), KC_SPC, KC_BSPC, LCMD_T(KC_M), KC_R,    KC_D,    KC_Y,    KC_P,
    LT(SYMB, KC_A), KC_O, KC_E,            KC_I,   KC_U,    KC_G,         KC_T,    KC_K,    KC_S,    KC_N,
    LT(NUMS, KC_Z), KC_X, KC_C,            KC_V,   KC_F,    KC_B,         KC_H,    KC_J,    KC_L,    KC_ENT
  ),

  [SYMB] = LAYOUT_ortho_3x10(
    _______, _______, _______, _______, _______, _______,    KC_LBRC, KC_SCOLON, S(KC_9), _______,
    _______, _______, _______, _______, _______, S(KC_SLSH), KC_RBRC, KC_UP,     S(KC_0), KC_LCTL,
    _______, _______, _______, KC_LSFT, _______, S(KC_1),    KC_LEFT, KC_DOWN,   KC_RGHT, _______
  ),

  [NUMS] = LAYOUT_ortho_3x10(
    _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,       KC_7,    KC_8,    KC_9,    KC_0,
    _______, _______, _______, _______, RESET,   _______,    _______, _______, _______, _______
  ),

};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

  if (usb_led & (1 << USB_LED_NUM_LOCK)) {
    DDRD |= (1 << 5); PORTD &= ~(1 << 5);
  } else {
    DDRD &= ~(1 << 5); PORTD &= ~(1 << 5);
  }

  if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
    DDRB |= (1 << 0); PORTB &= ~(1 << 0);
  } else {
    DDRB &= ~(1 << 0); PORTB &= ~(1 << 0);
  }

  if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {

  } else {

  }

  if (usb_led & (1 << USB_LED_COMPOSE)) {

  } else {

  }

  if (usb_led & (1 << USB_LED_KANA)) {

  } else {

  }

}

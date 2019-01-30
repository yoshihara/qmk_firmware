#include QMK_KEYBOARD_H

#define BASE 0
#define NUMS 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_ortho_3x10(
    KC_MINS,        KC_W,    KC_COMM, KC_SPC, KC_BSPC, KC_M,         KC_R,    KC_D,      KC_Y,    KC_P,
    KC_A,           KC_O,    KC_E,    KC_I,   KC_U,    KC_G,         KC_T,    KC_K,      KC_S,    KC_N,
    LT(NUMS, KC_Z), KC_X,    KC_C,    KC_V,   KC_F,    LCMD_T(KC_B), KC_H,    KC_J,      KC_L,    KC_ENT
  ),

  [NUMS] = LAYOUT_ortho_3x10(
    KC_Q,           KC_1,    KC_DOT,  UC(0x3000), KC_BSPC, S(KC_1),      KC_LBRC, KC_SCOLON, S(KC_9), KC_LSFT,
    RESET,          KC_2,    KC_3,    KC_4,       KC_5,    S(KC_SLSH),   KC_RBRC, KC_UP,     S(KC_0), KC_LCTL,
    _______,        KC_6,    KC_7,    KC_8,       KC_9,    KC_0,         KC_LEFT, KC_DOWN,   KC_RGHT, _______
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

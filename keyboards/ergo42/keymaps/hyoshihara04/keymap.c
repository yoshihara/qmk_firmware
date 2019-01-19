#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define BASE 0
#define META 1
#define SYMB 2
#define GAME 3

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* BASE
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |  `   | ESC  |   Q  |   W  |   E  |   R  |  T   |   |  Y   |   U  |   I  |   O  |   P  |   -  | Bksp |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | Tab  | LCtrl|   A  |   S  |   D  |   F  |  G   |   |  H   |   J  |   K  |   L  |   ;  |  [   |  '   |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | SYMB | LSft |   Z  |   X  |   C  |   V  |  B   |   |  N   |   M  |   ,  |   .  |   /  |  (   |  |   |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | SGUI4| LAlt | LGUI | LEFT | RIGHT| META |Space |   | RSft |Enter |  UP  | DOWN | RGUI | RAlt | RSft |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [BASE] = LAYOUT( \
    KC_GRV,     KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,   KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_MINS, KC_BSPC, \
    KC_TAB,     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,     KC_G,   KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_LBRC, KC_QUOT, \
    TO(SYMB),   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,   KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, S(KC_9), S(KC_BSLS), \
    SGUI(KC_4), KC_LALT, KC_LGUI, KC_LEFT, KC_RGHT, MO(META), KC_SPC, KC_RSFT, KC_ENT, KC_UP,   KC_DOWN, KC_RGUI, KC_RALT, KC_RSFT \
  ),

  /* META
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |  `   | ESC  |   1  |   2  |   3  |   4  |   5  |   |      |  !   |  +   |  *   |  ^   |  =   | Bksp |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | Tab  | LCtrl|   6  |   7  |   8  |   9  |   0  |   |      |  "   |  @   |  #   |  $   |  ]   |  %   |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | SYMB | LSft |      |      |      |      |      |   |      |  _   |  ,   |  .   |  \   |  )   |  &   |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | SGUI4| LAlt | LGUI | LEFT | RIGHT| META |Space |   | RSft |Enter |  UP  | DOWN | RGUI | RAlt | RSft |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [META] = LAYOUT( \
    _______, _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, S(KC_1),    S(KC_EQL), S(KC_8),  S(KC_6), KC_EQL,  _______, \
    _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, S(KC_QUOT), S(KC_2),   S(KC_3),  S(KC_4), KC_RBRC, S(KC_5), \
    _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, S(KC_MINS), _______,   _______,  KC_BSLS, S(KC_0), S(KC_7), \
    _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,   _______,  _______, _______, _______ \
  ),

  /* SYMB
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |   `  | Esc  |  1   |  2   |  3   |  4   |  0   |   |  F7  |  F8  |  F9  | F10  | F11  | F12  | Bksp |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | Tab  | LCtrl|  Q   |  W   |  5   |  6   |  7   |   |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | Enter|
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | BASE | LSft |  A   |  S   |  D   |  8   |  9   |   |      |      |      |  UP  |      |      | RSft |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | SGUI4| LAlt | LGUI | Space|      | META | Space|   | RSft |Enter | LEFT | DOWN | RIGHT| RGUI | RAlt |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [SYMB] = LAYOUT( \
    _______, _______,  KC_1,    KC_2,   KC_3,    KC_4,    KC_0,    KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,  _______, \
    _______, _______,  KC_Q,    KC_W,   KC_5,    KC_6,    KC_7,    KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_F6,   KC_ENT , \
    TO(BASE), _______, KC_A,    KC_S,   KC_D,    KC_8,    KC_9,    XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, KC_RSFT, \
    _______, _______,  _______, KC_SPC, XXXXXXX, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_RGUI, KC_RALT \
  )

};


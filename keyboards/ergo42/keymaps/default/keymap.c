#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define BASE 0
#define META 1
#define SYMB 2
#define GAME 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* BASE
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | ESC  | Tab  |   Q  |   W  |   E  |   R  |  T   |   |  Y   |   U  |   I  |   O  |   P  |   [  | Bksp |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | Del  | LCtrl|   A  |   S  |   D  |   F  |  G   |   |  H   |   J  |   K  |   L  |   ;  |   (  |  '   |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | SYMB | LSft |   Z  |   X  |   C  |   V  |  B   |   |  N   |   M  |   ,  |   .  |   /  |   )  | RSft |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | LAlt | LGUI | LEFT | RIGHT| SYMB | META |Space |   | RSft |Enter |   -  |  UP  | DOWN | RGUI | RAlt |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [BASE] = LAYOUT( \
    KC_ESC,   KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,     KC_T,   KC_Y,   KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC, KC_BSPC, \
    KC_DEL,   KC_RCTL, KC_A,   KC_S,    KC_D,    KC_F,     KC_G,   KC_H,   KC_J,    KC_K,    KC_L,   KC_SCLN, KC_RBRC, KC_ENT, \
    MO(SYMB), KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,     KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_UP,   KC_RSFT, \
    KC_LGUI,  KC_LCTL, KC_GRV, KC_BSLS, KC_LALT, MO(META), KC_SPC, KC_SPC, KC_QUOT, KC_MINS, KC_EQL, KC_LEFT, KC_DOWN, KC_RGHT \
  ),

  /* META
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |  6   |   |  7   |  8   |  9   |  0   |   -  |   =  | Bksp |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | Del  | LCtrl|      |      |      |      |      |   |      |      |      |      |      |  [   |  ]   |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | SYMB | LSft |      |      |      |      |      |   |      |      |      |  \   |  ;   |  '   | RSft |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | LAlt | LGUI |      |      | SYMB | META |Space |   | RSft |Enter |  ,   |  .   |  /   | RGUI | RAlt |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [META] = LAYOUT( \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  _______, \
    _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, \
    _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS, KC_SCLN, KC_QUOT, _______, \
    _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, KC_COMM, KC_DOT,  KC_SLSH, _______, _______ \
  ),

  /* SYMB
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | ESC  |  TAB |  1   |  2   |  3   |  4   |  0   |   |  F7  |  F8  |  F9  | F10  | F11  | F12  | Bksp |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | RESET| LCtrl|  Q   |  W   |  5   |  6   |  7   |   |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | Enter|
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | SYMB | LSft |  A   |  S   |  D   |  8   |  9   |   |      |      |      |  UP  |      |      | RSft |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | LAlt | LGUI | Space| Space| SYMB | META |Space |   | RSft |Enter | LEFT | DOWN | RIGHT| RGUI | RAlt |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [SYMB] = LAYOUT( \
    KC_ESC,   KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_0,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, \
    RESET,    _______, KC_Q,    KC_W,    KC_5,    KC_6,    KC_7,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_ENT, \
    TO(BASE), _______, KC_A,    KC_S,    KC_D,    KC_8,    KC_9,    XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, _______, \
    _______,  _______, KC_SPC,  KC_SPC,  _______, _______, _______, _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______ \
  )

};


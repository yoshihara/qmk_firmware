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
  [BASE] = LAYOUT( \
    KC_TAB,  KC_Q,       KC_W,    KC_E,     KC_R,     KC_T,   KC_1,    /* | */ KC_6,    KC_Y,      KC_U,       KC_I,       KC_O,       KC_P,      KC_BSPC, \
    KC_LCTL, KC_A,       KC_S,    KC_D,     KC_F,     KC_G,   KC_2,    /* | */ KC_7,    KC_H,      KC_J,       KC_K,       KC_L,       KC_SCLN,   KC_LBRC, \
    KC_LSFT, KC_Z,       KC_X,    KC_C,     KC_V,     KC_B,   KC_3,    /* | */ KC_8,    KC_N,      KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,   TO(SYMB),\
    KC_ESC,  KC_LALT,    KC_LGUI, KC_5,     MO(META), KC_SPC, KC_4,    /* | */ KC_9,    KC_ENT,    KC_RSFT,    KC_0,       KC_RGUI,    KC_LEFT,   KC_UP \
  ),

  [META] = LAYOUT( \
    _______, KC_F1,      KC_F2,   KC_F3,    KC_F4,   KC_F5,   S(KC_1), /* | */ S(KC_6), S(KC_EQL), S(KC_MINS), S(KC_QUOT), S(KC_BSLS), S(KC_GRV), _______, \
    _______, KC_F6,      KC_F7,   KC_F8,    KC_F9,   KC_F10,  S(KC_2), /* | */ S(KC_7), KC_EQL,    KC_MINS,    KC_QUOT,    KC_BSLS,    KC_GRV,    KC_RBRC, \
    _______, SGUI(KC_4), KC_F11,  KC_F12,   XXXXXXX, XXXXXXX, S(KC_3), /* | */ S(KC_8), XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,   _______, \
    _______,  _______,   _______, S(KC_5),  _______, _______, S(KC_4), /* | */ S(KC_9), _______,   _______,    S(KC_0),    _______,    KC_RGHT,   KC_DOWN \
  ),

  [SYMB] = LAYOUT( \
    _______, KC_Q,       KC_W,    KC_E,     KC_1,    KC_4,    KC_7,    /* | */ KC_F1,    KC_F2,    KC_F3,      KC_F4,      KC_F5,      KC_F6,     _______, \
    _______, KC_A,       KC_S,    KC_D,     KC_2,    KC_5,    KC_8,    /* | */ KC_F7,    KC_F8,    KC_F9,      KC_F10,     KC_F11,     KC_F12,    KC_ENT, \
    _______, KC_5,       KC_6,    KC_7,     KC_3,    KC_6,    KC_9,    /* | */ XXXXXXX,  XXXXXXX,  XXXXXXX,    KC_UP,      XXXXXXX,    XXXXXXX,   TO(BASE), \
    _______, _______,    _______, _______,  KC_SPC,  KC_TAB,  KC_0,    /* | */ XXXXXXX,  XXXXXXX,  KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_RGUI,   KC_RALT \
  )

};


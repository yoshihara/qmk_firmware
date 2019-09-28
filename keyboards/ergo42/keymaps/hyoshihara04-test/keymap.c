#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define BASE 0
#define META 1
#define SYMB 2
#define GAME 3

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define KC_SCST SGUI(KC_4)
#define KC_RIET LT(SYMB, KC_ENT)
#define KC_LWSP LT(META, KC_SPC)

enum {
  TD_RSFT_LALT = 0
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_RSFT_LALT] = ACTION_TAP_DANCE_DOUBLE(KC_RSFT, KC_LALT)
};

#define KC_SFAT TD(TD_RSFT_LALT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT( \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,    XXXXXXX, /* | */ XXXXXXX, KC_Y,    KC_U,     KC_I,    KC_O,    KC_P,    KC_BSPC, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,     KC_G,    XXXXXXX, /* | */ XXXXXXX, KC_H,    KC_J,     KC_K,    KC_L,    KC_SCLN, KC_LBRC, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,    XXXXXXX, /* | */ XXXXXXX, KC_N,    KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_SFAT, \
    KC_LCMD, XXXXXXX, XXXXXXX, XXXXXXX, MO(META), KC_SPC,  XXXXXXX, /* | */ XXXXXXX, KC_ENT,  MO(SYMB), XXXXXXX, XXXXXXX, XXXXXXX, KC_ESC \
  ),

  [META] = LAYOUT( \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, /* | */ XXXXXXX, S(KC_EQL), S(KC_MINS), S(KC_QUOT), S(KC_BSLS), S(KC_GRV), _______, \
    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, /* | */ XXXXXXX, KC_EQL,    KC_MINS,    KC_QUOT,    KC_BSLS,    KC_GRV,    KC_RBRC, \
    _______, KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /* | */ XXXXXXX, XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,   XXXXXXX, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, /* | */ XXXXXXX, _______,   _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,   XXXXXXX \
  ),

  [SYMB] = LAYOUT( \
    _______, KC_ESC,  KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /* | */ XXXXXXX, KC_F1,     KC_F2,      KC_F3,      KC_F4,      KC_F5,     KC_DEL, \
    _______, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, /* | */ XXXXXXX, KC_F6,     KC_F7,      KC_F8,      KC_F9,      KC_F10,    KC_RBRC, \
    _______, XXXXXXX, XXXXXXX, KC_SCST, XXXXXXX, XXXXXXX, XXXXXXX, /* | */ XXXXXXX, KC_F11,    KC_F12,     XXXXXXX,    XXXXXXX,    XXXXXXX,   XXXXXXX, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, /* | */ XXXXXXX, _______,   _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,   XXXXXXX \
  )

};


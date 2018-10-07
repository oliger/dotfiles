#include "planck.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _ARROWS,
  _SPECIAL,
  _SPECIAL_SFT,
  _SYMBOLS,
  _ADJUST
};

#define SPECIAL MO(_SPECIAL)
#define SPECIAL_SFT MO(_SPECIAL_SFT)
#define SYMBOLS MO(_SYMBOLS)

#define ARROWS_F LT(_ARROWS, KC_F)

#define LCTL_VOLD LCTL_T(KC__VOLDOWN)
#define LALT_VOLU LALT_T(KC__VOLUP)
#define RCMD_RWD RCMD_T(KC_MRWD)
#define RALT_PLY RALT_T(KC_MPLY)
#define RCTL_FWD RCTL_T(KC_MFFD)

#define SSHOT LCMD(LCTL(S(KC_5)))

#define AGRAVE UC(0xE0) // à
#define U_AGRAVE UC(0xC0) // À
#define ACIRCUM UC(0xE2) // â
#define U_ACIRCUM UC(0xC2) // Â
#define EACUTE UC(0xE9) // é
#define U_EACUTE UC(0xC9) // È
#define EGRAVE UC(0xE8) // è
#define U_EGRAVE UC(0xC8) // È
#define ECIRCUM UC(0xEA) // ê
#define U_ECIRCUM UC(0xCA) // Ê
#define IDIAERS UC(0xEF) // ï
#define U_IDIAERS UC(0xCF) // Ï
#define OCIRCUM UC(0xF4) // ô
#define U_OCIRCUM UC(0xD4) // Ô
#define UGRAVE UC(0xF9) // ù
#define U_UGRAVE UC(0xD9) // Ù
#define CEDILLA UC(0xE7) // ç
#define U_CEDILLA UC(0xC7) // Ç

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid(
    KC_GESC,        KC_Q,      KC_W,      KC_E,    KC_R,     KC_T,   KC_Y,   KC_U,    KC_I,     KC_O,     KC_P,     KC_BSPC,
    KC_TAB,         KC_A,      KC_S,      KC_D,    ARROWS_F, KC_G,   KC_H,   KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    LSFT_T(KC_EQL), KC_Z,      KC_X,      KC_C,    KC_V,     KC_B,   KC_N,   KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  RSFT_T(KC_ENT),
    KC_HYPR,        LCTL_VOLD, LALT_VOLU, KC_LCMD, SPECIAL,  KC_SPC, KC_SPC, SYMBOLS, RCMD_RWD, RALT_PLY, RCTL_FWD, KC_HYPR
),

[_ARROWS] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, SSHOT, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_SPECIAL] = LAYOUT_planck_grid(
    _______,     _______, ECIRCUM, EACUTE,  EGRAVE,  _______, _______, UGRAVE,  IDIAERS, OCIRCUM, _______, _______,
    _______,     AGRAVE,  ACIRCUM, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    SPECIAL_SFT, _______, _______, CEDILLA, _______, _______, _______, _______, _______, _______, _______, SPECIAL_SFT,
    _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_SPECIAL_SFT] = LAYOUT_planck_grid(
    _______, _______,  U_ECIRCUM, U_EACUTE,  U_EGRAVE, _______, _______, U_UGRAVE, U_IDIAERS, U_OCIRCUM, _______, _______,
    _______, U_AGRAVE, U_ACIRCUM, _______,   _______,  _______, _______, _______,  _______,   _______,   _______, _______,
    _______, _______,  _______,   U_CEDILLA, _______,  _______, _______, _______,  _______,   _______,   _______, _______,
    _______, _______,  _______,   _______,   _______,  _______, _______, _______,  _______,   _______,   _______, _______
),

[_SYMBOLS] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TILD,
    _______, KC_LT,   KC_LPRN, KC_LCBR, KC_LBRC, KC_MINS, KC_PLUS, KC_RBRC, KC_RCBR, KC_RPRN, KC_GT,   KC_BSLS,
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_UNDS, KC_PIPE, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _SPECIAL, _SYMBOLS, _ADJUST);
}

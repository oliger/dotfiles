#include QMK_KEYBOARD_H
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _ARROWS,
  _SPECIAL,
  _SYMBOLS,
  _ADJUST
};

#define SPECIAL MO(_SPECIAL)
#define SYMBOLS MO(_SYMBOLS)

enum les_keycodes {
  A_GRAVE = SAFE_RANGE,
  A_CIRCONFLEXE,

  E_GRAVE,
  E_CIRCONFLEXE,
  E_AIGU,
  E_TREMA,
  E_EURO,

  I_CIRCONFLEXE,
  I_TREMA,

  O_CIRCONFLEXE,

  U_GRAVE,
  U_CIRCONFLEXE,
  U_TREMA,

  C_CEDILLE,
};

#define SSHOT LCMD(S(KC_5))
#define ARROWS_F LT(_ARROWS, KC_F)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_preonic_grid(
    KC_GESC,        KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,         KC_A,    KC_S,    KC_D,    ARROWS_F, KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    LSFT_T(KC_EQL), KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
    _______,        KC_LCTL, KC_LALT, KC_LGUI, SPECIAL,  KC_SPC,  KC_SPC,  SYMBOLS, KC_LGUI, KC_LALT, KC_LCTL, KC_RGHT
  ),

  [_ARROWS] = LAYOUT_preonic_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, SSHOT,   _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_SPECIAL] = LAYOUT_preonic_grid(
    _______, _______, _______,       _______,   _______, _______, _______, _______,       _______,       _______,       _______, _______,
    _______, _______, E_CIRCONFLEXE, E_AIGU,    E_GRAVE, E_TREMA, _______, U_GRAVE,       I_TREMA,       O_CIRCONFLEXE, _______, _______,
    _______, A_GRAVE, A_CIRCONFLEXE, _______,   _______, _______, _______, U_CIRCONFLEXE, I_CIRCONFLEXE, _______,       _______, _______,
    _______, _______, _______,       C_CEDILLE, E_EURO,  _______, _______, U_TREMA,       _______,       _______,       _______, _______,
    _______, _______, _______,       _______,   _______, _______, _______, _______,       _______,       _______,       _______, _______
  ),

  [_SYMBOLS] = LAYOUT_preonic_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TILD,
    _______, KC_LT,   KC_LPRN, KC_LCBR, KC_LBRC, KC_MINS, KC_PLUS, KC_RBRC, KC_RCBR, KC_RPRN, KC_GT,   KC_BSLS,
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_UNDS, KC_PIPE, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),


  [_ADJUST] = LAYOUT_preonic_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, RESET,   DEBUG,   _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint8_t mods = get_mods();

  clear_keyboard();

  switch (keycode) {
    // à
    case A_GRAVE:
      if (record->event.pressed) {
        register_code(KC_LALT);
        tap_code(KC_GRV);
        unregister_code(KC_LALT);
        set_mods(mods);
        tap_code(KC_A);
      }
      break;
    // â
    case A_CIRCONFLEXE:
      if (record->event.pressed) {
        register_code(KC_LALT);
        tap_code(KC_I);
        unregister_code(KC_LALT);
        set_mods(mods);
        tap_code(KC_A);
      }
      break;
    // è
    case E_GRAVE:
      if (record->event.pressed) {
        register_code(KC_LALT);
        tap_code(KC_GRV);
        unregister_code(KC_LALT);
        set_mods(mods);
        tap_code(KC_E);
      }
      break;
    // ê
    case E_CIRCONFLEXE:
      if (record->event.pressed) {
        register_code(KC_LALT);
        tap_code(KC_I);
        unregister_code(KC_LALT);
        set_mods(mods);
        tap_code(KC_E);
      }
      break;
    // é
    case E_AIGU:
      if (record->event.pressed) {
        register_code(KC_LALT);
        tap_code(KC_E);
        unregister_code(KC_LALT);
        set_mods(mods);
        tap_code(KC_E);
      }
      break;
    // ë
    case E_TREMA:
      if (record->event.pressed) {
        register_code(KC_LALT);
        tap_code(KC_U);
        unregister_code(KC_LALT);
        set_mods(mods);
        tap_code(KC_E);
      }
      break;
    // €
    case E_EURO:
      if (record->event.pressed) {
        register_code(KC_LALT);
        register_code(KC_LSHIFT);
        tap_code(KC_2);
        unregister_code(KC_LALT);
        unregister_code(KC_LSHIFT);
      }
      break;
    // î
    case I_CIRCONFLEXE:
      if (record->event.pressed) {
        register_code(KC_LALT);
        tap_code(KC_I);
        unregister_code(KC_LALT);
        set_mods(mods);
        tap_code(KC_I);
      }
      break;
    // ï
    case I_TREMA:
      if (record->event.pressed) {
        register_code(KC_LALT);
        tap_code(KC_U);
        unregister_code(KC_LALT);
        set_mods(mods);
        tap_code(KC_I);
      }
      break;
    // ô
    case O_CIRCONFLEXE:
      if (record->event.pressed) {
        register_code(KC_LALT);
        tap_code(KC_I);
        unregister_code(KC_LALT);
        set_mods(mods);
        tap_code(KC_O);
      }
      break;
    // ù
    case U_GRAVE:
      if (record->event.pressed) {
        register_code(KC_LALT);
        tap_code(KC_GRV);
        unregister_code(KC_LALT);
        set_mods(mods);
        tap_code(KC_U);
      }
      break;
    // û
    case U_CIRCONFLEXE:
      if (record->event.pressed) {
        register_code(KC_LALT);
        tap_code(KC_I);
        unregister_code(KC_LALT);
        set_mods(mods);
        tap_code(KC_U);
      }
      break;
    // ü
    case U_TREMA:
      if (record->event.pressed) {
        register_code(KC_LALT);
        tap_code(KC_U);
        unregister_code(KC_LALT);
        set_mods(mods);
        tap_code(KC_U);
      }
      break;
    // ç
    case C_CEDILLE:
      set_mods(mods);
      if (record->event.pressed) {
        register_code(KC_LALT);
        tap_code(KC_C);
        unregister_code(KC_LALT);
      }
      break;
    default:
      set_mods(mods);
      return true;
  }

  set_mods(mods);
  return false;
}

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _SPECIAL, _SYMBOLS, _ADJUST);
}

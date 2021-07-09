/* PLANCK: Copyright 2015-2017 Jack Humbert
 *         Copyright 2016-2021 Steve Kuchta
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 */

#include QMK_KEYBOARD_H
//#include "muse.h" // removing music mode for space saving

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// Can use builtin enum func to assign numbers but I prefer the layer visibility

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _FNC 3
//#define _NAV 9
#define _TBALL 10


// Key aliases for legibility
#define ___x___ KC_NO
//KC_NO = XXXXXXX
//KC_TRANSPARENT = _______

/*
enum custom_keycodes {
  QWERTY = SAFE_RANGE
};
*/

// macOS shortcuts
#define KC_NDSH LALT(KC_MINS)
#define KC_MDSH S(LALT(KC_MINS))
#define INDENT RGUI(KC_RBRC)
#define OUTDENT RGUI(KC_LBRC)

// Unicode Chars
// TODO: add unicode support, below is macOS-specific workaround
#define ESEXC LOPT(KC_1)   // inverted exclamation point
#define ESQUE LSA(KC_SLSH) // inverted question mark 

// Layer Aliases 
#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)
#define FNC     MO(_FNC)
#define SPCBALL LT(_TBALL, KC_SPC)


// Mod Tap Defs                        //  Tap     Hold
// -------------------                 //  ------------------
#define HPRTAB  MT(MOD_HYPR, KC_TAB)   //  Tab     Hyper (Super+Ctrl+Alt+Shift)
#define MEHESC  MT(MOD_MEH,  KC_ESC)   //  ESC     Meh (Ctrl+Alt+Shift) // window mgmt via 
#define SFT_ENT MT(MOD_RSFT, KC_ENT)   //  Enter   Right Shift (why this and not space cadet?)

// Single Use 
#define WINCAD  C(A(KC_DEL)) // Control Alt Delete for Win Logins
#define CLNPSTE S(A(G(KC_V))) // macOS native clean paste, no style
#define CLIPHIS  S(RCTL(KC_C)) // Clipboard History - defined to Alfred


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty */
[_QWERTY] = LAYOUT_planck_grid( \
  HPRTAB,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,    KC_Y,    KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
  MEHESC,  KC_A,    KC_S,    KC_D,    KC_F,  KC_G,    KC_H,    KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,    KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT,
  FNC,     KC_LCTL, KC_LALT, KC_LGUI, LOWER, SPCBALL, SPCBALL, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),
/* Lower */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, WINCAD,
    KC_DEL,  ESEXC,   ESQUE,   KC_NDSH, KC_MDSH, ___x___, ___x___, KC_UNDS,    KC_PLUS,    KC_LBRC, KC_RBRC, KC_PIPE,
    _______, ___x___, ___x___, CLIPHIS, CLNPSTE, ___x___, ___x___, S(KC_NUHS), S(KC_NUBS), KC_LCBR, KC_RCBR, _______,
    _______, _______, _______, _______, _______, KC_DEL,  KC_DEL,  _______,    _______,    KC_LABK, KC_RABK, ___x___
),
 /* Raise */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    KC_DEL,  ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,  KC_MINS, KC_EQL,  KC_LCBR, KC_RCBR, KC_BSLS,
    _______, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,  KC_NUHS, KC_NUBS, OUTDENT, INDENT,  _______,
    _______, _______, _______, _______, _______, KC_BSPC, KC_BSPC,  _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),
/* FUNCTIONs */
[_FNC] = LAYOUT_planck_grid(
    KC_VOLU, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_MFFD,
    KC_VOLD, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  _______, KC_MRWD,
    KC_MUTE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
/* Navigation layer: move around page, desktops, windows and apps 
[_NAV] = LAYOUT_planck_grid(
    ___x___, ___x___, KC_PGUP, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,    ___x___,    ___x___,    ___x___,
    ___x___, KC_HOME, KC_PGDN, KC_END,  ___x___, ___x___, ___x___, ___x___,  ___x___,   ___x___,    ___x___,    ___x___,
    ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,    C(KC_UP),   ___x___,    ___x___,
    ___x___, _______, _______, _______, ___x___, _______, _______, _______, C(KC_LEFT), C(KC_DOWN), C(KC_RGHT), _______
),*/
/* Trackball / pointer layer: symmetric ambidex mouse buttons, esp for ploopy trackballs */
[_TBALL] = LAYOUT_planck_grid(
    ___x___, ___x___, ___x___, ___x___, KC_WH_L, KC_WH_R, KC_WH_L, KC_WH_R, ___x___, ___x___, ___x___, ___x___,
    ___x___, ___x___, KC_BTN1, KC_BTN2, KC_BTN3, KC_WH_U, KC_WH_U, KC_BTN1, KC_BTN2, KC_BTN3, ___x___, ___x___,
    ___x___, ___x___, ___x___, KC_BTN4, KC_BTN5, KC_WH_D, KC_WH_D, KC_BTN4, KC_BTN5, ___x___, ___x___, ___x___,
    ___x___, _______, _______, _______, ___x___, _______, _______, ___x___, ___x___, ___x___, ___x___, ___x___
)
};

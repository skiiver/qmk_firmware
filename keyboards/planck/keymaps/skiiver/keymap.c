/* PLANCK: Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 */

#include QMK_KEYBOARD_H
#include "muse.h"


enum planck_layers {
  _QWERTY,
  _SUPERS,
  _LOWER,
  _FN,
  _RAISE,
  _DROP,
  _LIFT,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BACKLIT
};

/* Layer Defs and Combinations */
#define LOWER  MO(_LOWER)
#define FN     MO(_FN)
#define RAISE  MO(_RAISE)
#define SUPERS MO(_SUPERS)
#define SPC_T  LT(_SUPERS, KC_SPC)
//#define METAS  MT(MOD_LSFT | MOD_LALT | MOD_LGUI, KC_ENT)

/* macOS combos for some missing standards */
#define MC_HOME LGUI(KC_LEFT)    // macOS Home (Cmd + Left Arrow)
#define MC_END  LGUI(KC_RGHT)    // macOS End (Cmd + Right Arrow)
#define MC_TOP  LGUI(KC_UP)      // macOS Top (Cmd + Up Arrow)
#define MC_BTM  LGUI(KC_DOWN)    // macOS Bottom (Cmd + Down Arrow)

/* MOD layers inc. keyboard maestro triggers: window mgmt combos */
// Shift Control Alt
#define SCA_F   MT(MOD_LSFT | MOD_LCTL | MOD_LALT, KC_F)
#define SCA_J   MT(MOD_LSFT | MOD_LCTL | MOD_LALT, KC_J)
// Hyper: Shift Control Alt GUI
#define HYP_H   MT(MOD_HYPR, KC_H)
#define HYP_G   MT(MOD_HYPR, KC_G)
// Single Use Combos
#define CALTD   LCTL(LALT(KC_DEL)) // Control Alt Delete j
#define MC_SGV  S(G(KC_V)) // macOS Paste no style: Shift GUI V
#define MC_SCC  S(RCTL(KC_C)) // macOS Alfred: Clipboard History


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty */
[_QWERTY] = LAYOUT_planck_grid( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,  KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_ESC,  KC_A,    KC_S,    KC_D,    SCA_F, HYP_G,  HYP_H, SCA_J, KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,  KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  FN,      KC_LCTL, KC_LALT, KC_LGUI, LOWER, SPC_T,  SPC_T, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),
/* SuperSys Layer: Hold SpaceBar for System Controls, WASD Left Nav Cluster */
[_SUPERS] = LAYOUT_planck_grid(
    _______, _______, KC_UP,   _______, _______, _______,    _______,    _______, _______,  _______, _______, CALTD,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, G(KC_LBRC), G(KC_RBRC), _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______,    _______,    _______, _______,  KC_PGDN, KC_PGUP, _______,
    _______, _______, _______, _______, _______, _______,    _______,    _______, KC_HOME,  MC_BTM,  MC_TOP, KC_END
),
/* Lower */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    KC_DEL,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS,
    _______,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_HASH, KC_BSLS, KC_LCBR, KC_RCBR, _______,
    _______,  _______, _______, _______, _______, KC_DEL,  KC_DEL,  _______, _______, KC_LABK, KC_RABK, _______
),
/* FN from Lower: Functions */
[_FN] = LAYOUT_planck_grid(
    G(KC_GRV), KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    MC_SGV,     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
    MC_SCC,     KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  _______,
    _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
 /* Raise */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,      KC_7,       KC_8,       KC_9,       KC_0,     KC_DEL,
    KC_DEL,  KC_4,    KC_5,    KC_6,    XXXXXXX, XXXXXXX, KC_BSPC,   KC_MINS,    KC_EQL,     KC_LCBR,    KC_RCBR,  KC_PIPE,
    _______, KC_7,    KC_8,    KC_9,    KC_0,    KC_F10,  C(KC_TAB), C(KC_RBRC), KC_BSLS,    KC_PGDN,    KC_PGUP,  _______,
    _______, _______, _______, _______, _______, KC_BSPC, KC_BSPC,   _______,    C(KC_LEFT), C(KC_DOWN), C(KC_UP), C(KC_RGHT)
),
/* DROP: LOWER_2 trilayer */
[_DROP] = LAYOUT_planck_grid(
    _______, KC_D,   KC_R,     KC_O,    KC_P,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, _______, _______, _______, _______, KC_SPC,  KC_SPC,  _______, _______, _______, _______, _______
),
/* LIFT: Raise^2 trilayer */
[_LIFT] = LAYOUT_planck_grid(
    _______, KC_L,   KC_I,     KC_F,    KC_T,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, _______, _______, _______, _______, KC_SPC,  KC_SPC,  _______, _______, _______, _______, _______
),
/* Adjust (Lower + Raise): Swap Alt-GUI for OS; TODO: swap base layer to get new WINDOWS dedicated branchs */
[_ADJUST] = LAYOUT_planck_grid(
    QWERTY,  KC_BRID, KC_BRIU, C(KC_UP), C(KC_DOWN), _______, _______, KC_MRWD, KC_MPLY, KC_MFFD, KC_MUTE, RESET,
    _______, _______, _______, _______,  _______,    AG_NORM, AG_SWAP, QWERTY,  _______, _______, _______, _______,
    _______, _______, _______, _______,  _______,    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,  _______,    KC_MUTE, KC_MUTE, _______, KC_MRWD, KC_VOLD, KC_VOLU, KC_MFFD
)
};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

/* setup for multi layer activation via state return syntax */
uint32_t layer_state_set_user(uint32_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  state = update_tri_layer_state(state, _FN,  _LOWER, _DROP);
  state = update_tri_layer_state(state, _FN,  _RAISE, _LIFT);
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          PORTE &= ~(1<<6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          PORTE |= (1<<6);
        #endif
      }
      return false;
      break;
    /*case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
    */
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        register_code(KC_MS_WH_DOWN);
        unregister_code(KC_MS_WH_DOWN);
      #else
        register_code(KC_PGDN);
        unregister_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        register_code(KC_MS_WH_UP);
        unregister_code(KC_MS_WH_UP);
      #else
        register_code(KC_PGUP);
        unregister_code(KC_PGUP);
      #endif
    }
  }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_song);
        #endif
        layer_on(_ADJUST);
      } else {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}

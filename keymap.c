/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "quantum.h"
#include <stdio.h>
#include "glcdfont.c"

// Tap Dance declarations
enum {
    TD_ENT_TAB,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ENT_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_ENT, KC_TAB),
};

// Layer names
enum layer_names {
    _Default,
    _Numbers,
    _Function,
    _Adjust
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  TD(TD_ENT_TAB),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, TT(1),  KC_SPC,       KC_SPC,   MO(2),  KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4, KC_TILD,                      KC_CIRC, KC_AMPR, KC_LCBR, KC_RCBR, KC_MINS, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_5,    KC_6,    KC_7,    KC_8, KC_PIPE,                      KC_LPRN,  KC_RPRN, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_9,    KC_0, KC_MINS, KC_EQL, KC_PERC,                      KC_UNDS, KC_PLUS, KC_ASTR, KC_PSCR, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_SPC, MO(3), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_F1,   KC_F2, KC_F3,  KC_F4, KC_EXLM,                               KC_EXLM, KC_AT, KC_HASH, KC_DLR, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_F5, KC_F6, KC_F7, KC_F8, KC_AT,                                KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_F9, KC_F10, KC_F11, KC_F12, KC_HASH,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3),  KC_ENT,     KC_SPC,  _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_ENT,     KC_SPC, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

 static const char arasaka [] PROGMEM = {
// 'Untitled', 128x32px
0x00, 0x00, 0x80, 0xc0, 0x60, 0x30, 0x18, 0x0c, 0x0c, 0x06, 0xc6, 0xe3, 0xf3, 0xfb, 0xfb, 0xfb,
0xfb, 0xf3, 0xe3, 0xc3, 0x03, 0x06, 0x06, 0x0c, 0x0c, 0x18, 0x30, 0x60, 0xc0, 0x80, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x10, 0x10, 0x20, 0x40, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x01,
0x7d, 0x45, 0x45, 0x45, 0x7d, 0x01, 0xff, 0x13, 0x6d, 0x63, 0x93, 0x69, 0xbf, 0xe1, 0x6b, 0xbb,
0x2d, 0x39, 0x79, 0x17, 0xd1, 0x5b, 0xc5, 0x1f, 0x43, 0xc5, 0xdb, 0x9b, 0xff, 0x00, 0x00, 0x00,
0x00, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0xf0, 0x10, 0xd0, 0x50, 0x50, 0x50, 0xd0, 0x10, 0xf0, 0x70,
0x50, 0x30, 0xd0, 0x30, 0xb0, 0x10, 0xf0, 0x50, 0x30, 0xd0, 0x70, 0x50, 0xf0, 0x00, 0x00, 0x00,
0xf8, 0xfe, 0x07, 0xc1, 0xe0, 0xf0, 0xf8, 0xf8, 0xf8, 0xf8, 0xf3, 0xe7, 0xcf, 0x9f, 0x9f, 0x9f,
0x9f, 0x8f, 0x9f, 0xbb, 0xf0, 0xe0, 0xc0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x81, 0x07, 0xfe, 0xf8,
0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x02, 0x02, 0x84, 0x08, 0x08, 0x08, 0x00, 0x00, 0x00, 0xe0,
0xf8, 0xf8, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xf8, 0xf8, 0xe0, 0x00, 0x00, 0x00, 0xff, 0xa3,
0x05, 0x69, 0x9f, 0xa7, 0x03, 0x55, 0x63, 0x7f, 0x45, 0xc9, 0xb7, 0xe8, 0xaa, 0x44, 0x01, 0xe8,
0xd7, 0x7c, 0xab, 0x3c, 0xe9, 0x65, 0xd5, 0xec, 0x7b, 0xe2, 0x4d, 0x05, 0xff, 0x00, 0x00, 0x00,
0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0x90, 0x37, 0x94, 0xb4, 0x54, 0xd7, 0x50, 0x9f, 0x27,
0xf6, 0x5d, 0x77, 0x55, 0xaa, 0xa3, 0x08, 0xa3, 0x77, 0xdd, 0x77, 0xd5, 0xff, 0x00, 0x00, 0x00,
0x1f, 0x7f, 0xe0, 0x83, 0x07, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0xcf, 0xe7, 0xf3, 0xf9, 0xf9, 0xf9,
0xf9, 0xf1, 0xf9, 0xdd, 0x0f, 0x07, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x81, 0xe0, 0x7f, 0x1f,
0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x40, 0x40, 0x71, 0x08, 0x08, 0x70, 0x00, 0x00, 0x00, 0x07,
0x1f, 0x1f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x1f, 0x1f, 0x07, 0x00, 0x00, 0x00, 0xff, 0x77,
0x46, 0x5f, 0x6d, 0x45, 0x54, 0x55, 0xd3, 0x39, 0xe8, 0x19, 0x80, 0x52, 0xeb, 0x22, 0x9a, 0x34,
0xb5, 0x79, 0xc5, 0x46, 0xc2, 0x47, 0x76, 0x6d, 0x41, 0x75, 0x5c, 0x58, 0xff, 0x00, 0x00, 0x00,
0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0x06, 0xf6, 0x14, 0x16, 0x17, 0xf7, 0x05, 0xfc, 0x40,
0x4f, 0xd3, 0x29, 0x25, 0xfd, 0x05, 0xf5, 0x15, 0x17, 0x15, 0xf5, 0x04, 0xff, 0x00, 0x00, 0x00,
0x00, 0x00, 0x01, 0x03, 0x06, 0x0c, 0x18, 0x30, 0x30, 0x60, 0x63, 0xc7, 0xcf, 0xdf, 0xdf, 0xdf,
0xdf, 0xcf, 0xc7, 0xc3, 0xc0, 0x60, 0x60, 0x30, 0x30, 0x18, 0x0c, 0x06, 0x03, 0x01, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x09, 0x09, 0x09, 0x09, 0x09, 0x06, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x40,
0x5f, 0x51, 0x51, 0x51, 0x5f, 0x40, 0x7f, 0x4b, 0x45, 0x70, 0x67, 0x6c, 0x46, 0x65, 0x78, 0x60,
0x6b, 0x55, 0x7e, 0x5a, 0x7f, 0x40, 0x5f, 0x51, 0x51, 0x51, 0x5f, 0x40, 0x7f, 0x00, 0x00, 0x00,
0x00, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x07, 0x04, 0x05, 0x05, 0x05, 0x05, 0x05, 0x04, 0x07, 0x04,
0x07, 0x06, 0x04, 0x04, 0x07, 0x04, 0x05, 0x05, 0x05, 0x05, 0x05, 0x04, 0x07, 0x00, 0x00, 0x00

    };
bool oled_task_user() {

    //set cursor position
    oled_set_cursor(0, 0);
    if (is_keyboard_master()) {

    // write text to oled
    oled_write("Zeitgeist117\n", false);
    // oled layer state
    switch (get_highest_layer(layer_state)) {
        case _Default :
            oled_write("Default Layer", false);
            break;
        case _Numbers :
            oled_write("Number Layer", false);
            break;
        case _Function :
            oled_write("Function Layer", false);
            break;
        case _Adjust :
            oled_write("Adjust Layer", false);
            break;
    }

    } else {


        oled_write_raw_P(arasaka, sizeof(arasaka));
        };


    return false;

}

#endif


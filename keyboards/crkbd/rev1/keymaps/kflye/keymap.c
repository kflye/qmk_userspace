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
#pragma once

#include "kflye.h"
#include <stdio.h>


#define LAYOUT_crkbd_wrapper(...) LAYOUT(__VA_ARGS__)

#define LAYOUT_crkbd_base(\
     K000, K001, K002, K003, K004, K005,                K006, K007, K008, K009, K010, K011,\
     K100, K101, K102, K103, K104, K105,                K106, K107, K108, K109, K110, K111,\
     K200, K201, K202, K203, K204, K205,                K206, K207, K208, K209, K210, K211,\
     N300, N301, N302, K303, K304, K305,                K306, K307, K308, N309, N310, K311\
) \
LAYOUT_crkbd_wrapper( \
   K000,    K001,     K002,     K003,     K004,     K005,                    K006,     K007,     K008,     K009,     K010,     K011,\
   K100,    K101,     K102,     K103,     K104,     K105,                    K106,     K107,     K108,     K109,     K110,     K111,\
   K200,    K201,     K202,     K203,     K204,     K205,                    K206,     K207,     K208,     K209,     K210,     K211,\
                                    K303,     K304,     K305,            K306,     K307,     K308\
  ) \

#define LAYOUT_base_wrapper(...) LAYOUT_crkbd_base(__VA_ARGS__)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_base_wrapper(
        _________________COLEMAK_L1_________________, _________________COLEMAK_R1_________________,
        _________________COLEMAK_L2_________________, _________________COLEMAK_R2_________________,
        _________________COLEMAK_L3_________________, _________________COLEMAK_R3_________________,
        _________________THUMB_LEFT_________________, _________________THUMB_RIGHT________________
    ),
    [_QWERTY] = LAYOUT_base_wrapper(
        _________________QWERTY_L1__________________, _________________QWERTY_R1__________________,
        _________________QWERTY_L2__________________, _________________QWERTY_R2__________________,
        _________________QWERTY_L3__________________, _________________QWERTY_R3__________________,
        _________________THUMB_LEFT_________________, _________________THUMB_RIGHT________________
    ),
    [_ALT] = LAYOUT_base_wrapper(
        _________________GALLIUM_COL_L1_____________, _________________GALLIUM_COL_R1_____________,
        _________________GALLIUM_COL_L2_____________, _________________GALLIUM_COL_R2_____________,
        _________________GALLIUM_COL_L3_____________, _________________GALLIUM_COL_R3_____________,
        _________________THUMB_LEFT_________________, _________________THUMB_RIGHT________________
    ),
    [_SYM] = LAYOUT_base_wrapper(
        ___________________SYM_L1___________________, ___________________SYM_R1___________________,
        ___________________SYM_L2___________________, ___________________SYM_R2___________________,
        ___________________SYM_L3___________________, ___________________SYM_R3___________________,
        ___________________SYM_L4___________________, ___________________SYM_R4___________________
    ),
    [_NUM] = LAYOUT_base_wrapper(
        ___________________NUM_L1___________________, ___________________NUM_R1___________________,
        ___________________NUM_L2___________________, ___________________NUM_R2___________________,
        ___________________NUM_L3___________________, ___________________NUM_R3___________________,
        ___________________NUM_L4___________________, ___________________NUM_R4___________________
    ),
    // [_NAV] = LAYOUT_base_wrapper(
    //     ___________________NAV_L1___________________, ___________________NAV_R1___________________,
    //     ___________________NAV_L2___________________, ___________________NAV_VI_R2________________,
    //     ___________________NAV_L3___________________, ___________________NAV_VI_R3________________,
    //     ___________________NAV_L4___________________, ___________________NAV_R4___________________
    // ),
    [_NAV] = LAYOUT_base_wrapper(
        ___________________NAV_L1___________________, ___________________NAV_R1___________________,
        ___________________NAV_L2___________________, ___________________NAV_R2___________________,
        ___________________NAV_L3___________________, ___________________NAV_R3___________________,
        ___________________NAV_L4___________________, ___________________NAV_R4___________________
    ),
    // [_MEDIA] = LAYOUT_base_wrapper(
    //     __________________MEDIA_L1__________________, __________________MEDIA_R1__________________,
    //     __________________MEDIA_L2__________________, __________________MEDIA_VI_R2_______________,
    //     __________________MEDIA_L3__________________, __________________MEDIA_R3__________________,
    //     __________________MEDIA_L4__________________, __________________MEDIA_R4__________________
    // ),
    [_MEDIA] = LAYOUT_base_wrapper(
        __________________MEDIA_L1__________________, __________________MEDIA_R1__________________,
        __________________MEDIA_L2__________________, __________________MEDIA_R2__________________,
        __________________MEDIA_L3__________________, __________________MEDIA_R3__________________,
        __________________MEDIA_L4__________________, __________________MEDIA_R4__________________
    ),
    [_FUN] = LAYOUT_base_wrapper(
        ___________________FUN_L1___________________, ___________________FUN_R1___________________,
        ___________________FUN_L2___________________, ___________________FUN_R2___________________,
        ___________________FUN_L3___________________, ___________________FUN_R3___________________,
        ___________________FUN_L4___________________, ___________________FUN_R4___________________
    ),
    [_MOUSE] = LAYOUT_base_wrapper(
        __________________MOUSE_L1__________________, __________________MOUSE_R1__________________,
        __________________MOUSE_L2__________________, __________________MOUSE_R2__________________,
        __________________MOUSE_L3__________________, __________________MOUSE_R3__________________,
        __________________MOUSE_L4__________________, __________________MOUSE_R4__________________
    ),
};


#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}


void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
          oled_write_ln_P(PSTR("_BASE: "), false);
          break;
        case _QWERTY:
          oled_write_ln_P(PSTR("_QWERTY: "), false);
          break;
        case _SYM:
          oled_write_ln_P(PSTR("_SYM: "), false);
          break;
        case _NUM:
          oled_write_ln_P(PSTR("_NUM: "), false);
          break;
        case _NAV:
          oled_write_ln_P(PSTR("_NAV: "), false);
          break;
        case _MEDIA:
          oled_write_ln_P(PSTR("_MEDIA: "), false);
         break;
        case _MOUSE:
          oled_write_ln_P(PSTR("_MOUSE: "), false);
          break;
        case _FUN:
          oled_write_ln_P(PSTR("_FUN: "), false);
          break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE

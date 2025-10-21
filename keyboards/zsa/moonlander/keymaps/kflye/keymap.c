/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "kflye.h"
#include "print.h"

#define ESC_CTL LCTL_T(KC_ESC)
#define TOG_WS MT(MOD_LGUI | MOD_LSFT, KC_PSCR)

#define LAYOUT_moonlander_wrapper(...) LAYOUT_moonlander(__VA_ARGS__)

#define LAYOUT_moonlander_base( \
     K000, K001, K002, K003, K004, K005,                K006, K007, K008, K009, K010, K011,\
     K100, K101, K102, K103, K104, K105,                K106, K107, K108, K109, K110, K111,\
     K200, K201, K202, K203, K204, K205,                K206, K207, K208, K209, K210, K211,\
     N300, N301, N302, K303, K304, K305,                K306, K307, K308, N309, N310, K311\
    ) \
    LAYOUT_moonlander_wrapper( \
        KC_ESC,  ________________NUMBER_LEFT_________________,     XXX,         XXX,     ________________NUMBER_RIGHT________________,      XXX,\
        K000,    K001,     K002,     K003,     K004,     K005,     XXX,         KC_AA,   K006,     K007,     K008,     K009,     K010,     K011,\
        K100,    K101,     K102,     K103,     K104,     K105,     KC_AE,       KC_OE,   K106,     K107,     K108,     K109,     K110,     K111,\
        K200,    K201,     K202,     K203,     K204,     K205,                           K206,     K207,     K208,     K209,     K210,     K211,\
        XXX,     XXX,      XXX,      K303,     K304,               XXX,         XXX,               K307,     K308,      XXX,      XXX,     XXX,\
                                                K305,    K303,     KC_LBRC,     KC_RBRC, K308,     K306\
    )


#define LAYOUT_base_wrapper(...) LAYOUT_moonlander_base(__VA_ARGS__)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_base_wrapper(
        _________________COLEMAK_L1_________________, _________________COLEMAK_R1_________________,
        _________________COLEMAK_L2_________________, _________________COLEMAK_R2_________________,
        _________________COLEMAK_L3_________________, _________________COLEMAK_R3_________________,
        _________________THUMB_LEFT_________________, _________________THUMB_RIGHT________________
    ),
    // [_GAMING] = LAYOUT_base_wrapper(
    //     ______________GAMING_QWERTY_L1______________, ______________GAMING_QWERTY_R1______________,
    //     ______________GAMING_QWERTY_L2______________, ______________GAMING_QWERTY_R2______________,
    //     ______________GAMING_QWERTY_L3______________, ______________GAMING_QWERTY_R3______________,
    //     ______________GAMING_QWERTY_L4______________, ______________GAMING_QWERTY_R4______________
    // ),
    [_GAMING] = LAYOUT_base_wrapper(
        _________________GAMING_L1__________________, _________________GAMING_R1__________________,
        _________________GAMING_L2__________________, _________________GAMING_R2__________________,
        _________________GAMING_L3__________________, _________________GAMING_R3__________________,
        _________________GAMING_L4__________________, _________________GAMING_R4__________________
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

/* Copyright 2021 @ Keychron (https://www.keychron.com)
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

// clang-format off

#define TOG_WS MT(MOD_LGUI | MOD_LSFT, KC_PSCR)

#define LAYOUT_keychron_v1_wrapper(...) LAYOUT_iso_83(__VA_ARGS__)

#define LAYOUT_keychron_v1_base(\
     K000, K001, K002, K003, K004, K005,                K006, K007, K008, K009, K010, K011,\
     K100, K101, K102, K103, K104, K105,                K106, K107, K108, K109, K110, K111,\
     K200, K201, K202, K203, K204, K205,                K206, K207, K208, K209, K210, K211,\
     N300, N301, N302, K303, K304, K305,                K306, K307, K308, N309, N310, K311\
) \
LAYOUT_keychron_v1_wrapper(\
    KC_ESC,     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  QK_BOOT,     KC_MPLY,\
    KC_GRV,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,     KC_PGUP,\
    K000,       K001,    K002,    K003,    K004,    K005,    K006,    K007,    K008,    K009,    K010,    KC_LBRC, KC_RBRC,              KC_HOME,\
    K100,       K101,    K102,    K103,    K104,    K105,    K106,    K107,    K108,    K109,    K110,    KC_NUHS, KC_RSFT, KC_ENT,      KC_END,\
    K200,       KC_NUBS, K201,    K202,    K203,    K204,    K205,    K206,    K207,    K208,    K209,    K210,    KC_RSFT,     KC_UP,          \
    KC_LCTL,    K303,    K304,                K305,                                            K306,   K307,   K308,   KC_LEFT, KC_DOWN, KC_RGHT\
)

#define LAYOUT_base_wrapper(...) LAYOUT_keychron_v1_base(__VA_ARGS__)

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
    [_GAMING] = LAYOUT_base_wrapper(
        _________________GAMING_L1__________________, _________________GAMING_R1__________________,
        _________________GAMING_L2__________________, _________________GAMING_R2__________________,
        _________________GAMING_L3__________________, _________________GAMING_R3__________________,
        _________________GAMING_L4__________________, _________________GAMING_R4__________________
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
    [_NAV] = LAYOUT_base_wrapper(
        ___________________NAV_L1___________________, ___________________NAV_R1___________________,
        ___________________NAV_L2___________________, ___________________NAV_R2___________________,
        ___________________NAV_L3___________________, ___________________NAV_R3___________________,
        ___________________NAV_L4___________________, ___________________NAV_R4___________________
    ),
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

// clang-format on
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE]    = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_QWERTY]    = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_ALT]    = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_GAMING]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_SYM]     = { ENCODER_CCW_CW(UG_HUED,UG_HUEU)},
    [_NUM]     = { ENCODER_CCW_CW(UG_VALD, UG_VALU)},
    [_NAV]     = { ENCODER_CCW_CW(UG_SATD, UG_SATU)},
    [_MEDIA]   = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
    [_FUN]     = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
    [_MOUSE]   = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS)}
};  
#endif

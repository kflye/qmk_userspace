#pragma once


#include QMK_KEYBOARD_H
/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/
#if (!defined(LAYOUT) && defined(KEYMAP))
#   define LAYOUT KEYMAP
#endif

#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)

#define ___________________BLANK___________________     _______,           _______,           _______,           _______,           _______,           _______
#define ________________CLIPBOARD_L________________     SK_UNDO,           SK_CUT,            SK_COPY,           SK_PSTE,           SK_REDO
#define ________________CLIPBOARD_R________________     SK_REDO,           SK_PSTE,           SK_COPY,           SK_CUT,            SK_UNDO

#define _________________COLEMAK_L1_________________    KC_DEL,            KC_Q,              KC_W,              KC_F,              KC_P,              KC_B
#define _________________COLEMAK_L2_________________    KC_LCTL,           KC_A,              KC_R,              KC_S,              KC_T,              KC_G
#define _________________COLEMAK_L3_________________    KC_LSFT,           KC_Z,              KC_X,              KC_C,              KC_D,              KC_V

#define _________________COLEMAK_R1_________________    KC_J,              KC_L,              KC_U,              KC_Y,              KC_SCLN,           KC_BSPC
#define _________________COLEMAK_R2_________________    KC_M,              KC_N,              KC_E,              KC_I,              KC_O,              KC_RCTL
#define _________________COLEMAK_R3_________________    KC_K,              KC_H,              KC_COMM,           KC_DOT,            KC_SLASH,          KC_RSFT

#define _________________GALLIUM_ROW_L1_____________    KC_DEL,            KC_B,              KC_L,              KC_D,              KC_C,              KC_V
#define _________________GALLIUM_ROW_L2_____________    KC_LCTL,           KC_N,              KC_R,              KC_T,              KC_S,              KC_G
#define _________________GALLIUM_ROW_L3_____________    KC_LSFT,           KC_X,              KC_Q,              KC_M,              KC_W,              KC_Z

#define _________________GALLIUM_ROW_R1_____________    KC_J,              KC_F,              KC_O,              KC_U,              KC_COMM,           KC_BSPC
#define _________________GALLIUM_ROW_R2_____________    KC_Y,              KC_H,              KC_A,              KC_E,              KC_I,              KC_RCTL
#define _________________GALLIUM_ROW_R3_____________    KC_K,              KC_P,              KC_SLASH,          KC_SCLN,           KC_DOT,            KC_RSFT

#define _________________GALLIUM_COL_L1_____________    KC_DEL,            KC_B,              KC_L,              KC_D,              KC_C,              KC_V
#define _________________GALLIUM_COL_L2_____________    KC_LCTL,           KC_N,              KC_R,              KC_T,              KC_S,              KC_G
#define _________________GALLIUM_COL_L3_____________    KC_LSFT,           KC_X,              KC_Q,              KC_M,              KC_W,              KC_Z

#define _________________GALLIUM_COL_R1_____________    KC_J,              KC_Y,              KC_O,              KC_U,              KC_COMM,           KC_BSPC
#define _________________GALLIUM_COL_R2_____________    KC_P,              KC_H,              KC_A,              KC_E,              KC_I,              KC_RCTL
#define _________________GALLIUM_COL_R3_____________    KC_K,              KC_F,              KC_SLASH,          KC_SCLN,           KC_DOT,            KC_RSFT

#define _________________GRAPHITE_L1________________    KC_DEL,            KC_B,              KC_L,              KC_D,              KC_W,              KC_V
#define _________________GRAPHITE_L2________________    KC_LCTL,           KC_N,              KC_R,              KC_T,              KC_S,              KC_G
#define _________________GRAPHITE_L3________________    KC_LSFT,           KC_Q,              KC_X,              KC_M,              KC_C,              KC_Z

#define _________________GRAPHITE_R1________________    KC_SCLN,           KC_F,              KC_O,              KC_U,              KC_J,              KC_BSPC
#define _________________GRAPHITE_R2________________    KC_Y,              KC_H,              KC_A,              KC_E,              KC_I,              KC_RCTL
#define _________________GRAPHITE_R3________________    KC_K,              KC_P,              KC_DOT,            KC_SCLN,           KC_SLASH,          KC_RSFT

#define _________________QWERTY_L1__________________    KC_DEL,            KC_Q,              KC_W,              KC_E,              KC_R,              KC_T
#define _________________QWERTY_L2__________________    KC_LCTL,           KC_A,              KC_S,              KC_D,              KC_F,              KC_G
#define _________________QWERTY_L3__________________    KC_LSFT,           KC_Z,              KC_X,              KC_C,              KC_V,              KC_B

#define _________________QWERTY_R1__________________    KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,              KC_BSPC
#define _________________QWERTY_R2__________________    KC_H,              KC_J,              KC_K,              KC_L,              KC_SCLN,           KC_RCTL
#define _________________QWERTY_R3__________________    KC_N,              KC_M,              KC_COMM,           KC_DOT,            KC_SLASH,          KC_RSFT

#define _________________DVORAK_L1__________________    KC_DEL,            KC_QUOT,           KC_COMM,           KC_DOT,            KC_P,              KC_Y
#define _________________DVORAK_L2__________________    KC_LCTL,           KC_A,              KC_O,              KC_E,              KC_U,              KC_I
#define _________________DVORAK_L3__________________    KC_LSFT,           KC_SCLN,           KC_Q,              KC_J,              KC_K,              KC_X

#define _________________DVORAK_R1__________________    KC_F,              KC_G,              KC_C,              KC_R,              KC_L,              KC_BSPC
#define _________________DVORAK_R2__________________    KC_D,              KC_H,              KC_T,              KC_N,              KC_S,              KC_RCTL
#define _________________DVORAK_R3__________________    KC_B,              KC_M,              KC_W,              KC_V,              KC_Z,              KC_RSFT

#define _________________GAMING_L1__________________    KC_TAB,            KC_Q,              KC_W,              KC_F,              KC_P,              KC_B
#define _________________GAMING_L2__________________    KC_LCTL,           KC_A,              KC_R,              KC_S,              KC_T,              KC_G
#define _________________GAMING_L3__________________    KC_LSFT,           KC_Z,              KC_X,              KC_C,              KC_D,              KC_V
#define _________________GAMING_L4__________________    _______,           _______,           _______,           GAM_WIN,           KC_LALT,           KC_SPC

#define _________________GAMING_R1__________________    KC_J,              KC_L,              KC_U,              KC_Y,              KC_SCLN,           KC_BSPC
#define _________________GAMING_R2__________________    KC_M,              KC_N,              KC_E,              KC_I,              KC_O,              KC_RCTL
#define _________________GAMING_R3__________________    KC_K,              KC_H,              KC_COMM,           KC_DOT,            KC_SLASH,          KC_RSFT
#define _________________GAMING_R4__________________    _________________THUMB_RIGHT________________

#define ______________GAMING_QWERTY_L1______________    KC_TAB,            KC_Q,              KC_W,              KC_E,              KC_R,              KC_T
#define ______________GAMING_QWERTY_L2______________    KC_LCTL,           KC_A,              KC_S,              KC_D,              KC_F,              KC_G
#define ______________GAMING_QWERTY_L3______________    KC_LSFT,           KC_Z,              KC_X,              KC_C,              KC_V,              KC_B
#define ______________GAMING_QWERTY_L4______________    _______,           _______,           _______,           GAM_WIN,           KC_LALT,           KC_SPC

#define ______________GAMING_QWERTY_R1______________    KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,              KC_BSPC
#define ______________GAMING_QWERTY_R2______________    KC_H,              KC_J,              KC_K,              KC_L,              KC_SCLN,           KC_RCTL
#define ______________GAMING_QWERTY_R3______________    KC_N,              KC_M,              KC_COMM,           KC_DOT,            KC_SLASH,          KC_RSFT
#define ______________GAMING_QWERTY_R4______________    _________________THUMB_RIGHT________________

#define ___________________SYM_L1___________________    _______,           KC_QUOT,           KC_LABK,           KC_RABK,           KC_DQUO,           KC_GRV
#define ___________________SYM_L2___________________    _______,           KC_EXLM,           KC_MINS,           KC_PLUS,           KC_EQL,            KC_HASH
#define ___________________SYM_L3___________________    _______,           KC_CIRC,           KC_SLSH,           KC_ASTR,           KC_BSLS,           _______
#define ___________________SYM_L4___________________    _______,           _______,           _______,           _______,           _______,           _______

#define ___________________SYM_R1___________________    KC_AMPR,           KC_LBRC,           KC_RBRC,           KC_PERC,           KC_AT,             _______
#define ___________________SYM_R2___________________    KC_PIPE,           KC_LPRN,           KC_RPRN,           KC_UNDS,           KC_COLN,           _______
#define ___________________SYM_R3___________________    KC_TILD,           KC_LCBR,           KC_RCBR,           KC_QUES,           KC_DLR,            _______
#define ___________________SYM_R4___________________    _______,           _______,           _______,           _______,           _______,           _______

#define ___________________SYM_LM2__________________    KC_EXLM,           KC_MINS,           KC_PLUS,           KC_EQL,            KC_HASH
#define ___________________SYM_RM2__________________    KC_PIPE,           KC_LPRN,           KC_RPRN,           KC_UNDS,           KC_QUES

#define ___________________NUM_L1___________________    _______,           KC_SLSH,           KC_7,              KC_8,              KC_9,              KC_ASTR
#define ___________________NUM_L2___________________    _______,           KC_SCLN,           KC_4,              KC_5,              KC_6,              KC_MINS
#define ___________________NUM_L3___________________    _______,           KC_0,              KC_1,              KC_2,              KC_3,              KC_PLUS
#define ___________________NUM_L4___________________    _______,           _______,           _______,           _______,           _______,           _______

#define ___________________NUM_R1___________________    TD(TD_QWERTY),     _______,           _______,           _______,           _______,           _______
#define ___________________NUM_R2___________________    TD(TD_RBT),        KC_AE,             KC_OE,             KC_AA,             _______,           _______
#define ___________________NUM_R3___________________    TD(TD_BASE),       TD(TD_GAMING),     TD(TD_ALT),        TD(TD_EECLEAR),    TD(TD_BOOT),       _______
#define ___________________NUM_R4___________________    _______,           _______,           _______,           _______,           _______,           _______

#define ___________________FUN_L1___________________    _______,           KC_F12,            KC_F7,             KC_F8,             KC_F9,             KC_PSCR
#define ___________________FUN_L2___________________    _______,           KC_F11,            KC_F4,             KC_F5,             KC_F6,             KC_SCRL
#define ___________________FUN_L3___________________    _______,           KC_F10,            KC_F1,             KC_F2,             KC_F3,             KC_PAUS
#define ___________________FUN_L4___________________    _______,           _______,           _______,           _______,           _______,           _______
// TODO: kc_app

#define ___________________FUN_R1___________________    SK_Win,            SK_Mac,            _______,           UC_PREV,           UC_NEXT,           _______
#define ___________________FUN_R2___________________    SHRUG,             _______,           _______,           _______,           SK_SCAP,           _______
#define ___________________FUN_R3___________________    VRSN,              _______,           _______,           _______,           SK_SCLP,           _______
#define ___________________FUN_R4___________________    _______,           _______,           _______,           _______,           _______,           _______

#define __________________MEDIA_L1__________________    _______,           _______,           _______,           _______,           _______,           _______
#define __________________MEDIA_L2__________________    _______,           _______,           _______,           _______,           _______,           _______
#define __________________MEDIA_L3__________________    _______,           _______,           _______,           _______,           _______,           _______
#define __________________MEDIA_L4__________________    _______,           _______,           _______,           _______,           _______,           _______

#define __________________MEDIA_R1__________________    UG_TOGG,           UG_NEXT,           UG_VALD,           UG_VALU,           UG_HUEU ,           _______
#define __________________MEDIA_R2__________________    KC_NO,              KC_MPRV,           KC_VOLD,           KC_VOLU,           KC_MNXT ,           _______
#define __________________MEDIA_R3__________________    OU_AUTO,           KC_MPLY,           KC_MSTP,           KC_MUTE,           KC_NO    ,           _______
#define __________________MEDIA_R4__________________    _______,           _______,           _______,           _______,           _______ ,           _______


#define ___________________NAV_L1___________________    SK_DELWDR,         SK_QUIT,           SK_CLOZ,           SK_FIND,           KC_MCTL,           KC_LPAD
#define ___________________NAV_L2___________________    _______,           SK_SALL,           SK_RELD,           SK_SRCH,           SK_NEWTAB,         _______
#define ___________________NAV_L3___________________    _______,           ________________CLIPBOARD_L________________
#define ___________________NAV_L4___________________    _______,           _______,           _______,           _______,           _______,           _______

#define ___________________NAV_R1___________________    _______,           SK_WORDPRV,        _______,           _______,           SK_WORDNXT,        SK_DELWDL
#define ___________________NAV_R2___________________    CW_TOGG,           KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,           _______
#define ___________________NAV_R3___________________    KC_INS,            KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END ,           _______
#define ___________________NAV_R4___________________    _______,           _______,           _______,           _______,           _______,           _______


#define __________________MOUSE_L1__________________    _______,           _______,           _______,           _______,           _______,           _______
#define __________________MOUSE_L2__________________    _______,           _______,           _______,           _______,           _______,           _______
#define __________________MOUSE_L3__________________    _______,           _______,           _______,           _______,           _______,           _______
#define __________________MOUSE_L4__________________    _______,           _______,           _______,           _______,           _______,           _______

#define __________________MOUSE_R1__________________    _______,           _______,           _______,           _______,           _______,           _______
#define __________________MOUSE_R2__________________    MS_BTN2,           MS_LEFT,           MS_DOWN,           MS_UP,             MS_RGHT,           _______
#define __________________MOUSE_R3__________________    MS_BTN1,           MS_WHLL,           MS_WHLD,           MS_WHLU,           MS_WHLR,           _______
#define __________________MOUSE_R4__________________    _______,           _______,           MS_BTN3,           KC_NO,             KC_NO,             _______

#define ________________NUMBER_LEFT_________________    KC_1,              KC_2,              KC_3,              KC_4,              KC_5
#define ________________NUMBER_RIGHT________________    KC_6,              KC_7,              KC_8,              KC_9,              KC_0

#define _________________THUMB_LEFT_________________    KC_NO,             KC_NO,             KC_NO,             KC_LGUI,           LALT_T(KC_ESC),    LT(_NAV,KC_SPC)
#define _________________THUMB_RIGHT________________    LT(_SYM,KC_ENT),   LT(_NUM,KC_TAB),   LT(_FUN, KC_RGUI), KC_NO,             KC_NO,             KC_NO


// VI Versions

#define ___________________NAV_VI_R2________________    KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,           CW_TOGG,           _______
#define ___________________NAV_VI_R3________________    KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END,            KC_INS,            _______

#define __________________MEDIA_VI_R2_______________    KC_MPRV,           KC_VOLD,           KC_VOLU,           KC_MNXT,           KC_NO,              _______

// #define __________________MOUSE_VI_R2_______________    KC_MS_L,           KC_MS_D,           KC_MS_U,           KC_MS_R,           KC_BTN2,           _______
// #define __________________MOUSE_VI_R3_______________    KC_WH_L,           KC_WH_D,           KC_WH_U,           KC_WH_R,           KC_BTN1,           _______

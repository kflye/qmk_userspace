#pragma once

#include QMK_KEYBOARD_H

enum OS_Platform { // Used for platform support via SemKeys
    OS_Mac,     // Mac with ANSI_US_EXTENDED layout
    OS_Win,     // Win with default English/ANSI layout?
#ifdef INCLUDE_SK_Lux
    OS_Lux,     // Linux (Gnome?/KDE?/Boox Android?)
#endif
    OS_count
};

bool process_semkey(uint16_t keycode, const keyrecord_t *record);

#define SK_beg SK_KILL
#define SK_count (SK_end - SK_beg)
#define SK_ndx(sk) (sk - SK_beg)

#define is_SemKey(sk) ((sk >= (uint16_t)(SK_beg)) && (sk < (uint16_t)SK_end))

#define linger_SemKey(sk) {register_SemKey(sk);linger_key = sk;linger_timer = state_reset_timer = timer_read();}
#define unlinger_SemKey(sk) {unregister_SemKey(linger_key);linger_key = 0;}

#pragma once

#include QMK_KEYBOARD_H

enum {
    TD_BOOT,
    TD_EECLEAR,
    TD_BASE,
    TD_ALT,
    TD_QWERTY,
    TD_GAMING,
    TD_RBT,
    TAP_DANCE_ACTION_COUNT
};

extern tap_dance_action_t tap_dance_actions[TAP_DANCE_ACTION_COUNT];
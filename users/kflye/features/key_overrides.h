#pragma once
#include QMK_KEYBOARD_H

// Declares the key override table for the Danish layout.
// Registered in key_overrides[] which QMK picks up automatically.
extern const key_override_t grv_override;
extern const key_override_t circ_override;
extern const key_override_t tild_override;

extern const key_override_t *const key_overrides[];

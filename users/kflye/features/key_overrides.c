#include "key_overrides.h"
#include "keymap_extras/keymap_danish.h"

// ---------------------------------------------------------------------------
// Dead key helpers: send dead key + space to produce the literal character.
//   DK_GRV  -> ` (dead grave   + space)
//   DK_CIRC -> ^ (dead circ    + space)
//   DK_TILD -> ~ (dead tilde   + space)
// ---------------------------------------------------------------------------
static bool send_dead_literal(const key_override_t *override, uint8_t *keycode, uint8_t *mods) {
    uint16_t dead = (uint16_t)(uintptr_t)override->custom_action;
    tap_code16(dead);
    tap_code(KC_SPC);
    return false; // suppress default processing
}

// We abuse the custom_action field as a thin way to pass the dead keycode.
// Each override uses a different action pointer that encodes the keycode.
static bool send_grv(const key_override_t *override, uint8_t *keycode, uint8_t *mods) {
    tap_code16(DK_GRV);
    tap_code(KC_SPC);
    return false;
}

static bool send_circ(const key_override_t *override, uint8_t *keycode, uint8_t *mods) {
    tap_code16(DK_CIRC);
    tap_code(KC_SPC);
    return false;
}

static bool send_tild(const key_override_t *override, uint8_t *keycode, uint8_t *mods) {
    tap_code16(DK_TILD);
    tap_code(KC_SPC);
    return false;
}

// The overrides intercept the DK_ dead keycodes on the _SYM layer only
// (layer mask bit 4 = _SYM = layer index 4).
#define SYM_LAYER_MASK (1 << 4)

const key_override_t grv_override  = {
    .trigger_mods          = 0,
    .layers                = SYM_LAYER_MASK,
    .suppressed_mods       = 0,
    .options               = ko_options_default,
    .negative_mod_mask     = 0,
    .custom_action         = send_grv,
    .context               = NULL,
    .trigger               = DK_GRV,
    .replacement           = KC_NO,
    .enabled               = NULL,
};

const key_override_t circ_override = {
    .trigger_mods          = 0,
    .layers                = SYM_LAYER_MASK,
    .suppressed_mods       = 0,
    .options               = ko_options_default,
    .negative_mod_mask     = 0,
    .custom_action         = send_circ,
    .context               = NULL,
    .trigger               = DK_CIRC,
    .replacement           = KC_NO,
    .enabled               = NULL,
};

const key_override_t tild_override = {
    .trigger_mods          = 0,
    .layers                = SYM_LAYER_MASK,
    .suppressed_mods       = 0,
    .options               = ko_options_default,
    .negative_mod_mask     = 0,
    .custom_action         = send_tild,
    .context               = NULL,
    .trigger               = DK_TILD,
    .replacement           = KC_NO,
    .enabled               = NULL,
};

// QMK looks for this symbol at link time when KEY_OVERRIDE_ENABLE = yes.
const key_override_t *const key_overrides[] = {
    &grv_override,
    &circ_override,
    &tild_override,
    NULL,
};

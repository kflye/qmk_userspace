#include "tap_dance.h"
#include "../definitions/layers.h"
#include "user_config.h"
#include "semantickeys.h"


void fn_boot(tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    reset_keyboard();
  }
}

void fn_reboot(tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    soft_reset_keyboard();
  }
}

void fn_eeclear(tap_dance_state_t *state, void *user_data) {
  if (state->count == 4) {
    eeconfig_init();
  }
}

void fn_base(tap_dance_state_t *state, void *user_data){
    if (state ->count == 2){
        default_layer_set((layer_state_t)1 << _BASE);
    }
}

void fn_alt(tap_dance_state_t *state, void *user_data){
    if (state ->count == 2){
        default_layer_set((layer_state_t)1 << _ALT);
    }
}

void fn_qwerty(tap_dance_state_t *state, void *user_data){
    if (state ->count == 2){
        default_layer_set((layer_state_t)1 << _QWERTY);
    }
}

void fn_gaming(tap_dance_state_t *state, void *user_data){
    if (state ->count == 2){
        default_layer_set((layer_state_t)1 << _GAMING);
    }
}

void fn_mac(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        user_config.OSIndex = OS_Mac;
        set_unicode_input_mode(UNICODE_MODE_MACOS);
        eeconfig_update_user(user_config.raw);
    }
}

void fn_win(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        user_config.OSIndex = OS_Win;
        set_unicode_input_mode(UNICODE_MODE_WINCOMPOSE);
        eeconfig_update_user(user_config.raw);
    }
}

void fn_lux(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        user_config.OSIndex = OS_Lux;
        set_unicode_input_mode(UNICODE_MODE_LINUX);
        eeconfig_update_user(user_config.raw);
    }
}

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_BOOT] = ACTION_TAP_DANCE_FN(fn_boot),
    [TD_BASE] = ACTION_TAP_DANCE_FN(fn_base),
    [TD_ALT] = ACTION_TAP_DANCE_FN(fn_alt),
    [TD_QWERTY] = ACTION_TAP_DANCE_FN(fn_qwerty),
    [TD_GAMING] = ACTION_TAP_DANCE_FN(fn_gaming),
    [TD_EECLEAR] = ACTION_TAP_DANCE_FN(fn_eeclear),
    [TD_RBT] = ACTION_TAP_DANCE_FN(fn_reboot),
    [TD_MAC] = ACTION_TAP_DANCE_FN(fn_mac),
    [TD_WIN] = ACTION_TAP_DANCE_FN(fn_win),
    [TD_LUX] = ACTION_TAP_DANCE_FN(fn_lux),
};

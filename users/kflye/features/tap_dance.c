#include "tap_dance.h"
#include  "../definitions/layers.h"


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

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_BOOT] = ACTION_TAP_DANCE_FN(fn_boot),
    [TD_BASE] = ACTION_TAP_DANCE_FN(fn_base),
    [TD_ALT] = ACTION_TAP_DANCE_FN(fn_alt),
    [TD_QWERTY] = ACTION_TAP_DANCE_FN(fn_qwerty),
    [TD_GAMING] = ACTION_TAP_DANCE_FN(fn_gaming),
    [TD_EECLEAR] = ACTION_TAP_DANCE_FN(fn_eeclear),
    [TD_RBT] = ACTION_TAP_DANCE_FN(fn_reboot),
};

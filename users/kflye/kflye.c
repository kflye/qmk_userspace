#include "config.h"
#include "version.h"
#include <stdio.h>
#include "print.h"

#include "kflye.h"

void keyboard_post_init_user(void) {
   debug_enable=true;
   debug_matrix=true;
   debug_keyboard=true;

   // Read the user config from EEPROM to facilitate
    // appropriate platform support

//    user_config.raw = 0; // reset
//    eeconfig_update_user(user_config.raw); // write the setings to EEPROM
    /*
    user_config.OSIndex use 0 for Mac; 1 for Win
     */
    user_config.raw = eeconfig_read_user();
    eeconfig_read_default_layer(); // get the default layer from eeprom.
}

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

__attribute__((weak)) void matrix_scan_keymap(void) {}

__attribute__ ((weak))
layer_state_t layer_state_set_keymap (layer_state_t state) {
  return state;
}

layer_state_t layer_state_set_user (layer_state_t state) {
  state = update_tri_layer_state(state, _NAV, _SYM, _MEDIA);
  state = update_tri_layer_state(state, _NAV, _NUM, _FUN);
  return layer_state_set_keymap (state);
}

#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        // colemak - shift
        case HOME_COL_P:
        case HOME_COL_L:
          return TAPPING_TERM - 80;

        // colemak - wln
        case HOME_COL_Q:
        case HOME_COL_SCLN:
          return TAPPING_TERM + 180;

        default:
          return TAPPING_TERM;
    }
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  #ifdef CONSOLE_ENABLE
    char A[32];
    switch (get_highest_layer(layer_state)) {
        case _BASE:
          strcpy(A, "_BASE" );
          break;
        case _ALT:
          strcpy(A, "_ALT" );
          break;
        case _GAMING:
          strcpy(A, "_GAMING" );
          break;
        case _QWERTY:
          strcpy(A, "_QWERTY" );
          break;
        case _SYM:
          strcpy(A, "_SYM" );
          break;
        case _NUM:
          strcpy(A, "_NUM" );
          break;
        case _NAV:
          strcpy(A, "_NAV" );
          break;
        case _MEDIA:
          strcpy(A, "_MEDIA" );
         break;
        case _MOUSE:
          strcpy(A, "_MOUSE" );
          break;
        case _FUN:
          strcpy(A, "_FUN" );
          break;
    }

    uprintf("KL: layer(%s) kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", A, keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
  #endif

  switch (keycode) {
    case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
    case U_BASE:
        default_layer_set((layer_state_t)1 << _BASE);
        return false;
    case U_ALT:
        default_layer_set((layer_state_t)1 << _ALT);
        return false;
    case U_GAMING:
        default_layer_set((layer_state_t)1 << _GAMING);
        return false;
    case SHRUG:
        if (record->event.pressed) {
            send_unicode_string("¯\\_(ツ)_/¯");
        }
        return false;
  }
 // Do we handle a semantic key? Combos or adaptives could have sent one.
  if (!process_semkey(keycode, record)) {
      return false; // took care of that key
  }

    bool return_state = true;
 if (record->event.pressed) {
        switch (keycode) {
            case SK_Win: // SINCE MAC IS MY LAYOUT DEFAULT switch to windows
                user_config.OSIndex = OS_Win; // for Windows Semkeys
                // process_magic(QK_MAGIC_SWAP_CTL_GUI); // tell QMK to swap ctrl/gui
                // keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = false;
                return_state = false; // stop processing this record.
                set_unicode_input_mode(UNICODE_MODE_WINCOMPOSE);
                goto storeSettings;
            case SK_Mac: // Back to default
                user_config.OSIndex = OS_Mac; // for Mac Semkeys
                // process_magic(QK_MAGIC_UNSWAP_CTL_GUI); // tell QMK to restore ctrl/gui
                // keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = true;
                return_state = false; // stop processing this record.
                set_unicode_input_mode(UNICODE_MODE_MACOS);
                goto storeSettings;


storeSettings:
                eeconfig_update_user(user_config.raw); // Remember platform variables after powerdown
                if (return_state == false) {
                  return return_state;
                }
                break;
        }


  }

  return process_record_keymap(keycode, record);
}

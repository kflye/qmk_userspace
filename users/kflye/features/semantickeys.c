#include <stdio.h>
#include "semantickeys.h"
#include "../definitions/keycodes.h"
#include "../features/user_config.h"

#define SEM_ALT_CODE(sk) (((sk) & 0x8000) || ((sk) & 0x4000))
#define SEM_LINUX_UC_FLAG 0x8000
#define LINUX_UC(cp) (SEM_LINUX_UC_FLAG | (cp))
#define IS_LINUX_UC(sk) (user_config.OSIndex == OS_Lux && ((sk) & SEM_LINUX_UC_FLAG))
#define LINUX_UC_CODE(sk) ((sk) & 0x7FFF)

const uint16_t SemKeys_t[SK_count][OS_count] = {
// Mac, Win, Linux
// System-wide controls

    [SK_ndx(SK_KILL)] = {LAG(KC_ESC),LCA(KC_DEL),LCA(KC_ESC)},        // Force quit / ctrl-alt-del
    [SK_ndx(SK_DKT8)] = {C(S(KC_3)),G(KC_H),KC_NO},             // Dictate speech to text
    [SK_ndx(SK_AIVC)] = {C(S(KC_4)),G(KC_C),KC_NO},             // AI voice control (mac Siri/Win Cortana)
        // extended characters/ editing commands
    [SK_ndx(SK_HENT)] = {G(KC_ENT),C(KC_ENT),C(KC_ENT)},            // Hard ENTER
    [SK_ndx(SK_UNDO)] = {G(KC_Z),C(KC_Z),C(KC_Z)},                // undo
    [SK_ndx(SK_REDO)] = {G(KC_Y),C(KC_Y),C(KC_Y)},                // Redo
    // [SK_ndx(SK_REDO)] = {G(S(KC_Z)),C(S(KC_Z))},       // Redo
    [SK_ndx(SK_CUT )] = {G(KC_X),C(KC_X),C(KC_X)},                // cut
    [SK_ndx(SK_COPY)] = {G(KC_C),C(KC_C),C(KC_C)},                // copy
    [SK_ndx(SK_PSTE)] = {G(KC_V),C(KC_V),C(KC_V)},                // paste
    [SK_ndx(SK_PSTM)] = {G(S(A(KC_V))),C(S(A(KC_V))),C(S(KC_V))},    // paste_match
    [SK_ndx(SK_SALL)] = {G(KC_A),C(KC_A),C(KC_A)},                // select all
    [SK_ndx(SK_CLOZ)] = {G(KC_W),C(KC_W),C(KC_W)},                // close
    [SK_ndx(SK_RELD)] = {G(KC_R),C(KC_R),C(KC_R)},                // reload
    [SK_ndx(SK_QUIT)] = {G(KC_Q),C(KC_Q),C(KC_Q)},                // quit
    [SK_ndx(SK_NEW)]  = {G(KC_N),C(KC_N),C(KC_N)},                // new
    [SK_ndx(SK_NEWTAB)]  = {G(KC_T),C(KC_T),C(KC_T)},             // new
    [SK_ndx(SK_OPEN)] = {G(KC_O),C(KC_O),C(KC_O)},                // open
    [SK_ndx(SK_FIND)] = {G(KC_F),C(KC_F),C(KC_F)},                // find
    [SK_ndx(SK_FAGN)] = {G(KC_G),C(KC_G),C(KC_G)},                // find again
    [SK_ndx(SK_SCAP)] = {LCSG(KC_3),KC_PSCR,KC_PSCR},              // Screen Capture
    [SK_ndx(SK_SCLP)] = {LCSG(KC_4),A(KC_PSCR),S(KC_PSCR)},       // Selection Capture
    // [SK_ndx(SK_SRCH)] = {G(KC_SPC),G(KC_S)},           // platform search (siri/cortana, etc.)
    [SK_ndx(SK_SRCH)] = {G(KC_SPC),A(KC_SPC),KC_LGUI},            // platform search (powertoysrun, spotlight.)
    [SK_ndx(SK_DELWDL)] = {A(KC_BSPC),C(KC_BSPC),C(KC_BSPC)},        // DELETE WORD LEFT
    [SK_ndx(SK_DELWDR)] = {A(KC_DEL),C(KC_DEL),C(KC_DEL)},          // DELETE WORD RIGHT
    [SK_ndx(SK_DELLNL)] = {G(KC_BSPC),C(KC_BSPC),C(KC_BSPC)},        // Delete line left of cursor
    [SK_ndx(SK_DELLNR)] = {G(KC_DEL),C(KC_DEL),C(KC_DEL)},          // Delete line right of cursor
        // extended navigation
    [SK_ndx(SK_WORDPRV)] = {A(KC_LEFT),C(KC_LEFT),C(KC_LEFT)},       // WORD LEFT
    [SK_ndx(SK_WORDNXT)] = {A(KC_RIGHT),C(KC_RIGHT),C(KC_RIGHT)},     // WORD RIGHT
    [SK_ndx(SK_DOCBEG)] = {G(KC_UP),C(KC_HOME),C(KC_HOME)},          // Go to start of document
    [SK_ndx(SK_DOCEND)] = {G(KC_DOWN),C(KC_END),C(KC_END)},         // Go to end of document
    [SK_ndx(SK_LINEBEG)] = {G(KC_DOWN),C(KC_END),KC_HOME},        // Go to beg of line
    [SK_ndx(SK_LINEEND)] = {G(KC_DOWN),C(KC_END),KC_END},        // Go to end of line
    [SK_ndx(SK_PARAPRV)] = {A(KC_UP),C(KC_UP),C(KC_UP)},           // Go to previous paragraph
    [SK_ndx(SK_PARANXT)] = {A(KC_DOWN),C(KC_DOWN),C(KC_DOWN)},       // Go to next paragraph
    [SK_ndx(SK_HISTPRV)] = {G(KC_LBRC),A(KC_LEFT),A(KC_LEFT)},       // BROWSER BACK
    [SK_ndx(SK_HISTNXT)] = {G(KC_RBRC),A(KC_RIGHT),A(KC_RIGHT)},      // BROWSER FWD
    [SK_ndx(SK_ZOOMIN)] = {G(KC_EQL),C(KC_EQL),C(KC_EQL)},          // ZOOM IN
    [SK_ndx(SK_ZOOMOUT)] = {G(KC_MINS),C(KC_MINS),C(KC_MINS)},       // ZOOM OUT
    [SK_ndx(SK_ZOOMRST)] = {G(KC_0),C(KC_0),C(KC_0)},             // ZOOM RESET
    [SK_ndx(SK_APPNXT)] = {G(KC_TAB),A(KC_TAB),A(KC_TAB)},          // APP switcher Next (last used)
    [SK_ndx(SK_APPPRV)] = {RSG(KC_TAB),LSA(KC_TAB),LSA(KC_TAB)},      // APP switcher Prev (least recently used)
    [SK_ndx(SK_WINNXT)] = {C(KC_TAB),C(KC_TAB),C(KC_TAB)},          // Window/tab switcher Next
    [SK_ndx(SK_WINPRV)] = {C(S(KC_TAB)),C(S(KC_TAB)),C(S(KC_TAB))},    // Window/tab switcher Prev
        // Window management
    [SK_ndx(SK_WINNXTDIS)] = {LCAG(KC_RIGHT),LSG(KC_RIGHT),LSG(KC_RIGHT)},  // Window next display
    [SK_ndx(SK_WINPREVDIS)] = {LCAG(KC_LEFT),LSG(KC_LEFT),LSG(KC_LEFT)},   // Window previous display
    [SK_ndx(SK_WINLEFT)] = {LCA(KC_LEFT),G(KC_LEFT),G(KC_LEFT)},         // Window left
    [SK_ndx(SK_WINRIGHT)] = {LCA(KC_RIGHT),G(KC_RIGHT),G(KC_RIGHT)},      // Window right
    [SK_ndx(SK_WINTOP)] = {LCA(KC_UP),G(KC_UP),G(KC_UP)},              // Window top
    [SK_ndx(SK_WINBOT)] = {LCA(KC_DOWN),G(KC_DOWN),G(KC_DOWN)},          // Window bottom
    [SK_ndx(SK_WINRESTORE)] = {LCA(KC_BSPC),G(KC_DOWN),G(KC_DOWN)},      // Window restore
    [SK_ndx(SK_WINCENTER)] = {LCA(KC_C),G(KC_DOWN),KC_NO},          // Window center
    [SK_ndx(SK_WINMAX)] = {LCA(KC_ENT),G(KC_UP),A(KC_F10)},             // Window maximize
        // Punctuation & typography
    [SK_ndx(SK_NDSH)] = {A(KC_MINS),0x8150,LINUX_UC(0x2013)},              // – N-Dash
    [SK_ndx(SK_MDSH)] = {LSA(KC_MINS),0x8151,LINUX_UC(0x2014)},            // — M-Dash
    [SK_ndx(SK_ELPS)] = {A(KC_SCLN),0x8133,LINUX_UC(0x2026)},              // …
    [SK_ndx(SK_SCRS)] = {LSA(KC_5),0x8134,LINUX_UC(0x2020)},               // † Single Cross
    [SK_ndx(SK_DCRS)] = {LSA(KC_7),0x8135,LINUX_UC(0x2021)},               // ‡ Double Cross
    [SK_ndx(SK_BBLT)] = {A(KC_8),0x8149,LINUX_UC(0x2022)},                 // • Bold Bullet
    [SK_ndx(SK_SBLT)] = {LSA(KC_9),0x8183,LINUX_UC(0x00B7)},               // · Small Bullet
    [SK_ndx(SK_PARA)] = {A(KC_7),0x8182,LINUX_UC(0x00B6)},                 // ¶
    [SK_ndx(SK_SECT)] = {A(KC_5),0x8167,LINUX_UC(0x00A7)},                 // §
        // Number & Math symbols
    [SK_ndx(SK_PERM)] = {LSA(KC_R),0x8137,LINUX_UC(0x2030)},               // ‰ Per Mille
    [SK_ndx(SK_DEGR)] = {LSA(KC_8),0x8176,LINUX_UC(0x00B0)},               // ° DEGREE
    [SK_ndx(SK_GTEQ)] = {A(KC_DOT),0x4242,LINUX_UC(0x2265)},               // ≥ Greater Than or Equal to
    [SK_ndx(SK_LTEQ)] = {A(KC_COMM),0x4243,LINUX_UC(0x2264)},              // ≤ Less Than or Equal to
    [SK_ndx(SK_PLMN)] = {LSA(KC_EQL),0x8177,LINUX_UC(0x00B1)},             // ± Plus/Minus
    [SK_ndx(SK_DIV) ] = {A(KC_SLSH),0x4246,LINUX_UC(0x00F7)},              // ÷ Divide
    [SK_ndx(SK_FRAC)] = {LSA(KC_1),0x4246,LINUX_UC(0x2044)},               // ⁄ Fraction "Solidus" symbol
    [SK_ndx(SK_NOTEQ)] = {A(KC_EQL),ALGR(KC_EQL),LINUX_UC(0x2260)},        // ≠ NOT Equal to
    [SK_ndx(SK_APXEQ)] = {A(KC_X),0x4247,LINUX_UC(0x2248)},                // ≈ APPROX Equal to
    [SK_ndx(SK_OMEGA)] = {A(KC_Z),0x4234,LINUX_UC(0x03A9)},                // Ω OMEGA
        // Currency
    [SK_ndx(SK_EURO)] = {LSA(KC_2),0x8128,LINUX_UC(0x20AC)},               // €
    [SK_ndx(SK_CENT)] = {A(KC_4),0x8162,LINUX_UC(0x00A2)},                 // ¢
    [SK_ndx(SK_BPND)] = {A(KC_3),0x8163,LINUX_UC(0x00A3)},                 // £
    [SK_ndx(SK_JPY )] = {A(KC_Y),0x8165,LINUX_UC(0x00A5)},                 // ¥
    [SK_ndx(SK_No  )] = {LSA(KC_SCLN),0x8470,LINUX_UC(0x2116)},            // № ordinal number symbol *wrong alt code*
        // Quotations
    [SK_ndx(SK_SQUL)] = {A(KC_RBRC),0x8145,LINUX_UC(0x2018)},              // ’ ** Left single quote
    [SK_ndx(SK_SQUR)] = {LSA(KC_RBRC),0x8146,LINUX_UC(0x2019)},            // ’ ** Right single quote
    [SK_ndx(SK_SDQL)] = {A(KC_LBRC),0x8147,LINUX_UC(0x201C)},              // “ ** Left double quote
    [SK_ndx(SK_SDQR)] = {LSA(KC_LBRC),0x8148,LINUX_UC(0x201D)},            // ” ** Right double quote
    [SK_ndx(SK_FDQL)] = {A(KC_BSLS),0x8171,LINUX_UC(0x00AB)},              // « Left double French quote
    [SK_ndx(SK_FDQR)] = {LSA(KC_BSLS),0x8187,LINUX_UC(0x00BB)},            // » Right double French quote
    [SK_ndx(SK_FSQL)] = {LSA(KC_3),0x8139,LINUX_UC(0x2039)},               // ‹ Left single French quote
    [SK_ndx(SK_FSQR)] = {LSA(KC_4),0x8155,LINUX_UC(0x203A)},               // › Right single French quote
    [SK_ndx(SK_IQUE)] = {LSA(KC_SLASH),0x8191,LINUX_UC(0x00BF)},           // ¿ Spanish inverted Question Mark
    [SK_ndx(SK_IEXC)] = {A(KC_1),0x8161,LINUX_UC(0x00A1)},                 // ¡ Spanish inverted Exclamation Mark
        // Composed letters with diacritics
    [SK_ndx(SK_ENYE)] = {A(KC_N),ALGR(KC_N),LINUX_UC(0x00F1)}             // ñ/Ñ

};

#define get_SemKeyCode(sk) (SemKeys_t[SK_ndx(sk)][user_config.OSIndex])
void send_alt_code(uint16_t sk) {

    if (sk & 0x8000) {
    // Always start with numpad 0 if semkeycode starts with 0x8
    tap_code(KC_P0);
    }

    // Extract & send digits using keypad keys
    tap_code((sk >> 8) & 0x0F ? KC_P0 - ((10 - (sk >> 8)) & 0x0F) : KC_P0);
    tap_code((sk >> 4) & 0x0F ? KC_P0 - ((10 - (sk >> 4)) & 0x0F) : KC_P0);
    tap_code((sk >> 0) & 0x0F ? KC_P0 - ((10 - (sk >> 0)) & 0x0F) : KC_P0);

};

void tap_SemKey(uint16_t sk) {
    uint16_t semkeycode = get_SemKeyCode(sk);

    if (IS_LINUX_UC(semkeycode)) {
        register_unicode(LINUX_UC_CODE(semkeycode));
    } else if (SEM_ALT_CODE(semkeycode)) {
        clear_keyboard();           // must have clean buffer.
        register_code(KC_LALT);     // hold Left Alt

        send_alt_code(semkeycode); // send 3 or 4-digit alt code

        unregister_code(KC_LALT);    // release Left Alt

    } else {
        tap_code16(semkeycode);      // regular keycode
    }
};

void register_SemKey(uint16_t sk) {
    uint16_t semkeycode = get_SemKeyCode(sk);

    if (IS_LINUX_UC(semkeycode)) {
        register_unicode(LINUX_UC_CODE(semkeycode));
    } else if (SEM_ALT_CODE(semkeycode)) {
        clear_keyboard();           // must have clean buffer.
        register_code(KC_LALT);     // hold Left Alt

        send_alt_code(semkeycode); // send 3 or 4-digit alt code

        // Alt must stay held here

    } else {
        register_code16(semkeycode);
    }
};

void unregister_SemKey(uint16_t sk) {
    uint16_t semkeycode = get_SemKeyCode(sk);

    if (IS_LINUX_UC(semkeycode)) {
        return;
    } else if (SEM_ALT_CODE(semkeycode)) {
        // Release Alt to finish Unicode input
        unregister_code(KC_LALT);
    } else {
        unregister_code16(semkeycode);
    }
};

bool process_semkey(uint16_t keycode, const keyrecord_t *record) {
    // custom processing could hapen here
    if (!(is_SemKey(keycode)))
        return true; // nothing to do. continue processing this record

    if (record->event.pressed) {
        switch (keycode) {
// handle multi-keystroke semkeys here
            case SK_SWRD: // Select current word
                tap_SemKey(SK_WORDPRV);
                register_code(KC_LSFT); // shift for select is close to universal?
                tap_SemKey(SK_WORDNXT); // of course, not for VIM and the like,
                unregister_code(KC_LSFT); // but we're talking OS platforms?
                break;
            default: // default keydown event (from the semkey table)
                register_SemKey(keycode);
/* Add the BCD decode for Win compose key stuff here

*/
                break;
        }
    } else { // The keyup event
        switch (keycode) {
            default:
                unregister_SemKey(keycode);
                break;
        }

    }
    return false; // don't do more with this record.
};

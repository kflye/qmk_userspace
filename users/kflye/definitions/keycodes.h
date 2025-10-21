
enum custom_keycodes {
    VRSN = SAFE_RANGE,
    U_BASE,
    U_ALT,
    U_GAMING,
     // ascii emojies
    SHRUG,
    NEW_SAFE_RANGE  //use "NEW_SAFE_RANGE" for keymap specific codes
};

enum sematic_keycodes {
    SK_sf = NEW_SAFE_RANGE,

    SK_Mac,     //  mac (using ABC-Extended keyboard)
    SK_Win,     //  windows (using US-Intl keyboard)
    SK_Lux,     //  linux
        // the rest of these semantic keys do need to be translated.
        // everything from SK_KILL on has SemKeys_t table entry.
        // System-wide controls
    SK_KILL,    // SK_KILL must be the first of contiguous block of SKs
    SK_DKT8,    // speech to text
    SK_AIVC,    // AI voice control (mac Siri/Win cortana)
        // extended characters/ editing commands
    SK_HENT,    // Hard-Enter
    SK_UNDO,    // undo
    SK_REDO,    // redo
    SK_CUT,     // cut
    SK_COPY,    // copy
    SK_PSTE,    // paste
    SK_PSTM,    // paste_match
    SK_SALL,    // select all
    SK_SWRD,    // select current word
    SK_CLOZ,    // close
    SK_RELD,    // reload
    SK_QUIT,    // quit
    SK_NEW,     // new
    SK_NEWTAB,  // new
    SK_OPEN,    // open
    SK_FIND,    // find
    SK_FAGN,    // find again
    SK_SCAP,    // screen capture to clipboard
    SK_SCLP,    // selection capture to clipboard
    SK_SRCH,    // platform search (siri/cortana, etc.)
    SK_DELWDL,  // Delete word left of cursor
    SK_DELWDR,  // Delete word right of cursor
    SK_DELLNL,  // Delete line left of cursor
    SK_DELLNR,  // Delete line right of cursor


        // extended navigation
    SK_WORDPRV, // WORD LEFT
    SK_WORDNXT, // WORD RIGHT
    SK_DOCBEG,  // Go to start of document
    SK_DOCEND,  // Go to end of document
    SK_LINEBEG, // Go to beg of line
    SK_LINEEND, // Go to end of line
    SK_PARAPRV, // Go to previous paragraph
    SK_PARANXT, // Go to next paragraph
    SK_HISTPRV, // BROWSER BACK
    SK_HISTNXT, // BROWSER FWD
    SK_ZOOMIN,  // ZOOM IN
    SK_ZOOMOUT, // ZOOM OUT
    SK_ZOOMRST, // ZOOM RESET
    SK_APPNXT,  // APP switcher Next (last used)
    SK_APPPRV,  // APP switcher Prev (least recently used)
    SK_WINNXT,  // Window/tab switcher Next
    SK_WINPRV,  // Window/tab switcher Prev
        // Punctuation & typography
    SK_NDSH,    // — N-Dash
    SK_MDSH,    // — M-Dash
    SK_ELPS,    // … Elipsis
    SK_SCRS,    // † Single Cross
    SK_DCRS,    // ‡ Double Cross
    SK_BBLT,    // • Bold Bullet
    SK_SBLT,    // · Small Bullet
    SK_PARA,    // ¶ Paragraph symbol
    SK_SECT,    // § Section symbol
        // Number & Math symbols
    SK_PERM,    // ‰ Per Mille
    SK_DEGR,    // ° DEGREE
    SK_GTEQ,    // ≥ Greater Than or Equal to
    SK_LTEQ,    // ≤ Less Than or Equal to
    SK_PLMN,    // ± Plus/Minus
    SK_DIV,     // ÷ Divide symbol
    SK_FRAC,    // ⁄ Fraction "Solidus" symbol
    SK_NOTEQ,   // ≠ NOT Equal to
    SK_APXEQ,   // ≈ APPROX Equal to
    SK_OMEGA,   // Ω OMEGA
        // Currency
    SK_EURO,    // €
    SK_CENT,    // ¢
    SK_BPND,    // £
    SK_JPY,     // ¥
    SK_No,      // № ordinal number symbol
        // Quotations
    SK_SQUL,    // ’ Left single quote (linger for paired)
    SK_SQUR,    // ’ Right single quote
    SK_SDQL,    // “ Left double quote (linger for paired)
    SK_SDQR,    // ” Right double quote
    SK_FDQL,    // « Left double French quote (linger for paired)
    SK_FDQR,    // » Right double French quote
    SK_FSQL,    // ‹ Left single French quote (linger for paired)
    SK_FSQR,    // › Right single French quote
    SK_IQUE,    // ¿ Spanish inverted Question Mark
    SK_IEXC,    // ¡ Spanish inverted Exclamation Mark
        // Composed letters with diacritics
    SK_ENYE,    // ñ/Ñ ENYE



    SK_end, // end of SemKeys
            //

    NEW_NEW_SAFE_RANGE  //use "NEW_NEW_SAFE_RANGE" for keymap specific codes
};

#define KC_AE UP(AE_L,AE_U)
#define KC_OE UP(OE_L,OE_U)
#define KC_AA UP(AA_L,AA_U)

//// Colemak

// Left-hand home row mods (row 1)
#define HOME_COL_Q LGUI_T(KC_Q)
#define HOME_COL_W LCTL_T(KC_W)
#define HOME_COL_F LALT_T(KC_F)
#define HOME_COL_P LSFT_T(KC_P)

// Left-hand home row mods (row 2)
#define HOME_COL_A LGUI_T(KC_A)
#define HOME_COL_R LCTL_T(KC_R)
#define HOME_COL_S LALT_T(KC_S)
#define HOME_COL_T LSFT_T(KC_T)

// Left-hand home row mods (row 3)
#define HOME_COL_Z LGUI_T(KC_Z)
#define HOME_COL_X LCTL_T(KC_X)
#define HOME_COL_C LALT_T(KC_C)
#define HOME_COL_D LSFT_T(KC_D)

// Right-hand home row mods (row 1)
#define HOME_COL_L RSFT_T(KC_L)
#define HOME_COL_U LALT_T(KC_U)
#define HOME_COL_Y RCTL_T(KC_Y)
#define HOME_COL_SCLN RGUI_T(KC_SCLN)

// Right-hand home row mods (row 2)
#define HOME_COL_N RSFT_T(KC_N)
#define HOME_COL_E LALT_T(KC_E)
#define HOME_COL_I RCTL_T(KC_I)
#define HOME_COL_O RGUI_T(KC_O)

// Right-hand home row mods (row 3)
#define HOME_COL_H RSFT_T(KC_H)
#define HOME_COL_COMM LALT_T(KC_COMM)
#define HOME_COL_DOT RCTL_T(KC_DOT)
#define HOME_COL_SLASH RGUI_T(KC_SLASH)

//// QWERTY

// Left-hand home row mods (row 1)
#define HOME_QWE_Q LGUI_T(KC_Q)
#define HOME_QWE_W LCTL_T(KC_W)
#define HOME_QWE_E LALT_T(KC_E)
#define HOME_QWE_R LSFT_T(KC_R)

// Left-hand home row mods (row 2)
#define HOME_QWE_A LGUI_T(KC_A)
#define HOME_QWE_S LCTL_T(KC_S)
#define HOME_QWE_D LALT_T(KC_D)
#define HOME_QWE_F LSFT_T(KC_F)

// Left-hand home row mods (row 3)
#define HOME_QWE_Z LGUI_T(KC_Z)
#define HOME_QWE_X LCTL_T(KC_X)
#define HOME_QWE_C LALT_T(KC_C)
#define HOME_QWE_V LSFT_T(KC_V)

// Right-hand home row mods (row 1)
#define HOME_QWE_U RSFT_T(KC_U)
#define HOME_QWE_I LALT_T(KC_I)
#define HOME_QWE_O RCTL_T(KC_O)
#define HOME_QWE_P RGUI_T(KC_P)

// Right-hand home row mods (row 2)
#define HOME_QWE_J RSFT_T(KC_J)
#define HOME_QWE_K LALT_T(KC_K)
#define HOME_QWE_L RCTL_T(KC_L)
#define HOME_QWE_SCLN RGUI_T(KC_SCLN)

// Right-hand home row mods (row 3)
#define HOME_QWE_M RSFT_T(KC_M)
#define HOME_QWE_COMM LALT_T(KC_COMM)
#define HOME_QWE_DOT RCTL_T(KC_DOT)
#define HOME_QWE_SLASH RGUI_T(KC_SLASH)


#define U_RDO C(KC_Y)
#define U_PST C(KC_V)
#define U_CPY C(KC_C)
#define U_CUT C(KC_X)
#define U_UND C(KC_Z)

#define U_OSX_RDO LGUI(KC_Y)
#define U_OSX_PST LGUI(KC_V)
#define U_OSX_CPY LGUI(KC_C)
#define U_OSX_CUT LGUI(KC_X)
#define U_OSX_UND LGUI(KC_Z)

#define GAM_WIN LT(_FUN, KC_LGUI)
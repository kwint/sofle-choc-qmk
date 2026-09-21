// Copyright 2026 Quint van Dijk
// SPDX-License-Identifier: GPL-2.0-or-later
//
// Sofle Choc keymap: the layers from the official build guide's default layout
// (QWERTY / COLEMAK / LOWER / RAISE / ADJUST) with a live layer readout on the
// OLEDs and per-layer encoder actions.
//
// Derived from keyboards/sofle/keymaps/default (QMK) with the OLED and RGB
// status screen adapted from brianlow's `choc3` branch.

#include QMK_KEYBOARD_H

enum sofle_layers {
    _QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_PRVWD = QK_USER,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
};

#define KC_QWERTY PDF(_QWERTY)
#define KC_COLEMAK PDF(_COLEMAK)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  Mute |    | Play  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |CapsWd|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTL |LOWER | /Space  /       \Enter \  |RAISE | RCTL | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_QWERTY] = LAYOUT(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,   KC_MPLY, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, CW_TOGG,
                    KC_LGUI, KC_LALT, KC_LCTL, TL_LOWR, KC_SPC,    KC_ENT,  TL_UPPR, KC_RCTL, KC_RALT, KC_RGUI
),

/*
 * COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  Mute |    | Play  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |CapsWd|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTL |LOWER | /Space  /       \Enter \  |RAISE | RCTL | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_COLEMAK] = LAYOUT(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
  KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                        KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,   KC_MPLY, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, CW_TOGG,
                    KC_LGUI, KC_LALT, KC_LCTL, TL_LOWR, KC_SPC,    KC_ENT,  TL_UPPR, KC_RCTL, KC_RALT, KC_RGUI
),

/*
 * LOWER  (numbers, function keys, symbols)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   =  |   -  |   +  |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTL |LOWER | /Space  /       \Enter \  |RAISE | RCTL | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  _______, KC_EQL,  KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,   _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
                    _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______
),

/*
 * RAISE  (navigation and editing)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Ins  | Pscr | Menu |      |      |                    | PgUp | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | LAlt | LCtl |LShift|      | Caps |-------.    ,-------| PgDn | Left | Down | Right|  Del | Bspc |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | Home |      |  End |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTL |LOWER | /Space  /       \Enter \  |RAISE | RCTL | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______,    _______,    _______,
  _______, KC_INS,  KC_PSCR, KC_APP,  XXXXXXX, XXXXXXX,                     KC_PGUP, KC_PRVWD, KC_UP,  KC_NXTWD,   C(KC_BSPC), KC_BSPC,
  _______, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_CAPS,                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT,    KC_DEL,     KC_BSPC,
  _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX, _______,   _______, XXXXXXX, KC_LSTRT, XXXXXXX, KC_LEND,   XXXXXXX,    _______,
                    _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______
),

/*
 * ADJUST  (LOWER + RAISE together): lighting, layout and media
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |Qwerty|Colmak|      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | BOOT |RGB on|RGBmd+|RGBmd-|      |EEclr |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |MacWin| Hue+ | Sat+ | Val+ | Spd+ |      |-------.    ,-------|      | Vol- | Mute | Vol+ |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      | Hue- | Sat- | Val- | Spd- |      |-------|    |-------|      | Prev | Play | Next |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTL |LOWER | /Space  /       \Enter \  |RAISE | RCTL | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_ADJUST] = LAYOUT(
  XXXXXXX, KC_QWERTY, KC_COLEMAK, XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  QK_BOOT, RM_TOGG,   RM_NEXT,    RM_PREV, XXXXXXX, EE_CLR,                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  CG_TOGG, RM_HUEU,   RM_SATU,    RM_VALU, RM_SPDU, XXXXXXX,               XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
  XXXXXXX, RM_HUED,   RM_SATD,    RM_VALD, RM_SPDD, XXXXXXX, _______,   _______, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                      _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______
)
};

#ifdef ENCODER_MAP_ENABLE
// Left encoder                          Right encoder
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [_COLEMAK] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [_LOWER]   = { ENCODER_CCW_CW(RM_HUED, RM_HUEU), ENCODER_CCW_CW(RM_SATD, RM_SATU) },
    [_RAISE]   = { ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(RM_SPDD, RM_SPDU) },
    [_ADJUST]  = { ENCODER_CCW_CW(RM_PREV, RM_NEXT), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
};
#endif

#ifdef RGB_MATRIX_ENABLE

// Light only the keys that actually do something on the layer you are holding,
// so blank keycaps get a legend. Keys left transparent (they fall through to
// the base layer) and unused keys stay dark. The base layers are untouched, so
// you keep whatever animation you picked.
//
// QMK only calls this while the matrix is on, so RM_TOGG kills the legend too.
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state);
    uint8_t r, g, b;

    switch (layer) {
        case _LOWER:  r =   0; g =  90; b = 110; break;  // cyan
        case _RAISE:  r = 110; g =   0; b =  90; break;  // magenta
        case _ADJUST: r = 120; g =  60; b =   0; break;  // amber
        default: return false;                           // base layer: hands off
    }

    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            uint8_t index = g_led_config.matrix_co[row][col];
            if (index == NO_LED || index < led_min || index >= led_max) {
                continue;
            }
            if (keymap_key_to_keycode(layer, (keypos_t){col, row}) > KC_TRNS) {
                rgb_matrix_set_color(index, r, g, b);
            } else {
                rgb_matrix_set_color(index, 0, 0, 0);
            }
        }
    }
    return false;
}

#endif

#ifdef OLED_ENABLE

// The OLEDs are mounted with their long axis pointing away from you, so the
// display is rotated: 5 characters wide, 16 lines tall. Every write below is
// exactly one of those 16 lines -- keep it that way when editing.
//
// If the right-hand screen reads upside down, change OLED_ROTATION_270 to
// OLED_ROTATION_90 in the non-master branch of oled_init_user() below.

#    ifdef RGB_MATRIX_ENABLE
static void write_int_ln(const char *prefix, uint8_t value) {
    oled_write_P(prefix, false);
    oled_write(get_u8_str(value, ' '), false);  // 2 + 3 chars = one full line
}
#    endif

static void render_status(bool full) {
    oled_write_ln_P(PSTR("Sofle"), false);                              //  1
    oled_write_ln_P(PSTR(""), false);                                   //  2

    switch (get_highest_layer(default_layer_state)) {                   //  3
        case _QWERTY:  oled_write_ln_P(PSTR("Qwrty"), false); break;
        case _COLEMAK: oled_write_ln_P(PSTR("Clmak"), false); break;
        default:       oled_write_ln_P(PSTR("?????"), false); break;
    }
    oled_write_ln_P(PSTR(""), false);                                   //  4

    oled_write_ln_P(PSTR("LAYER"), false);                              //  5
    switch (get_highest_layer(layer_state)) {                           //  6
        case _QWERTY:
        case _COLEMAK: oled_write_ln_P(PSTR("Base "), false); break;
        case _LOWER:   oled_write_ln_P(PSTR("Lower"), false); break;
        case _RAISE:   oled_write_ln_P(PSTR("Raise"), false); break;
        case _ADJUST:  oled_write_ln_P(PSTR("Adjst"), false); break;
        default:       oled_write_ln_P(PSTR("?????"), false); break;
    }
    oled_write_ln_P(PSTR(""), false);                                   //  7

#    ifdef RGB_MATRIX_ENABLE
    // Lighting readout, but only while you are on the layer that changes it.
    if (full && get_highest_layer(layer_state) == _ADJUST) {
        HSV hsv = rgb_matrix_get_hsv();
        oled_write_ln_P(PSTR("RGB"), false);                            //  8
        write_int_ln(PSTR("Mo"), rgb_matrix_get_mode());                //  9
        write_int_ln(PSTR("H "), hsv.h);                                // 10
        write_int_ln(PSTR("S "), hsv.s);                                // 11
        write_int_ln(PSTR("V "), hsv.v);                                // 12
        write_int_ln(PSTR("Sp"), rgb_matrix_get_speed());               // 13
    } else
#    endif
    {
        oled_write_P(PSTR("\n\n\n\n\n\n"), false);                      //  8-13
    }
    oled_write_ln_P(PSTR(""), false);                                   // 14

    // Caps Word state lives on the master only, so the slave shows caps lock.
    bool caps_word = full && is_caps_word_on();                         // 15
    bool caps_lock = host_keyboard_led_state().caps_lock;
    if (caps_word) {
        oled_write_ln_P(PSTR("WORD "), true);
    } else {
        oled_write_ln_P(caps_lock ? PSTR(" CAP ") : PSTR("     "), caps_lock);
    }

    if (full) {                                                         // 16
        oled_write_ln_P(keymap_config.swap_lctl_lgui ? PSTR("MAC  ") : PSTR("WIN  "), false);
    } else {
        oled_write_ln_P(PSTR(""), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    // Both halves show the layer; only the master knows the Mac/Win and
    // lighting state, so the slave gets the short version.
    render_status(is_keyboard_master());
    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
    }
    return true;
}

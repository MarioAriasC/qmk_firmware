#include "ergodox.h"
#include "keymap_spanish.h"

enum {
    BASE = 0,
    QWERTY,
    FN,
    NUM,
    MOUSE,
    IDEA
};

#define _______   KC_TRNS

#define MACRO_COLUMN_MODE 0
#define MACRO_TERMINAL 1

#define M_COLUMN  M(MACRO_COLUMN_MODE)
#define M_TERM    M(MACRO_TERMINAL)

#define BEL       UC(0x07)

// Column mode
#define I_COLUMN  ALGR(LCTL(LGUI(ES_MINS)))
// Terminal
#define I_TERM    ALGR(KC_F12)
// Line comment
#define I_LN_COM  LCTL(LGUI(KC_7))
// Block comment
#define I_BK_COM  LCTL(LGUI(KC_8))
// Reformat code
#define I_REFORM  LALT(LGUI(KC_L))
// Rename
#define I_RENAME  LSFT(KC_F6)
// Find usages
#define I_FUSAGE  LALT(KC_F7)
// Code for Packt
#define P_CODE    LCTL(ALGR(KC_X))

// Tmux prefix
#define T_PREFIX  LCTL(KC_B)

// Special paste

#define S_PASTE   LSFT(LGUI(KC_V))


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Colemak Spanish layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   Esc  |  1 ! | 2 "  | 3 ·  | 4 $  | 5 %  |  º \ |           | ¡ ¿  |  6 & | 7 /  |  8 ( | 9 )  | 0 =  | Backsp |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   TAB  |   Q  |   W  |   F  |   P  |   G  | Home |           | End  |   J  |   L  |   U  |   Y  |  Ñ   |  ' ?   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  CAPS  |   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |  O   |  ENT   |
 * |--------+------+------+------+------+------|  <>  |           |  -_  |------+------+------+------+------+--------|
 * | Shift  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |  , ; |  . : |  UP  | Shift  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Del  | PgUp |Ctl/PD|Alt/[ |Cmd/] |                                       |Cmd/{ |Alt/} | LEFT | DOWN | RIGHT|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,--------------.        ,--------------.
 *                                        | Num  | Mouse |        | Qwer | Ctrl  |
 *                                 ,------|------|-------|        |------+-------+------.
 *                                 |      |      | FN    |        |SPaste|       |      |
 *                                 |LShift|Backsp|-------|        |------|  ENT  |Space |
 *                                 |      |      | IDEA  |        | T-pre|       |      |
 *                                 `---------------------'        `---------------------'
 */
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,        KC_5,        KC_NUBS,
        KC_TAB,     KC_Q,       KC_W,       KC_F,       KC_P,        KC_G,        KC_HOME,
        KC_CAPS,    KC_A,       KC_R,       KC_S,       KC_T,        KC_D,
        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,        KC_B,        KC_GRV,
        KC_DEL,     KC_PGUP,CTL_T(KC_PGDN),ALT_T(ES_GRV),GUI_T(ES_PLUS),

                    DF(NUM),    DF(MOUSE),
                                DF(FN),
        KC_LSFT,    KC_BSPC,    MO(IDEA),

        // right hand
        ES_IEXL,       KC_6,       KC_7,       KC_8,       KC_9,        KC_0,        KC_BSPC,
        KC_END,       KC_J,       KC_L,       KC_U,       KC_Y,        ES_NTIL,     ES_APOS,
                      KC_H,       KC_N,       KC_E,       KC_I,        KC_O,        KC_ENT,
        ES_MINS,      KC_K,       KC_M,       KC_COMM,    KC_DOT,      KC_UP,       KC_RSFT,
                                  GUI_T(ES_ACUT),ALT_T(KC_BSLS), KC_LEFT, KC_DOWN,  KC_RIGHT,

        DF(QWERTY),     KC_RCTL,
        S_PASTE,
        T_PREFIX,    KC_ENT,     KC_SPC
    ),

/* Keymap 1: Spanish QWERTY layer (games)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   Ñ  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       | Base |      |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[QWERTY] = KEYMAP(  // layer 1: QWERTY layer (games)
       _______,        _______,    _______,    _______,    _______,    _______,    _______,
       _______,        KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       _______,
       _______,        KC_A,       KC_S,       KC_D,       KC_F,       KC_G,
       _______,        KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       _______,
       _______,        _______,    _______,    _______,    _______,

                       _______,    _______,
                                   _______,
       _______,        _______,    _______,

    // right hand
       _______,        _______,    _______,    _______,    _______,    _______,    _______,
       _______,        KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       _______,
                       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    _______,
       _______,        KC_N,       KC_M,       _______,    _______,    _______,    _______,
                                   _______,    _______,    _______,    _______,    _______,
       DF(BASE),        _______,
       _______,
       _______,        _______,    _______
    ),

/* Keymap 2: Function Layer
*
* ,--------------------------------------------------.           ,--------------------------------------------------.
* |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  | F10  | F11  | F12  |        |
* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
* |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
* |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
* |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
*   |      |      |      |      |      |                                       |      |      |      |      |      |
*   `----------------------------------'                                       `----------------------------------'
*                                        ,-------------.       ,-------------.
*                                        |      |      |       |      |      |
*                                 ,------|------|------|       |------+------+------.
*                                 |      |      | Base |       |      |      |      |
*                                 |      |      |------|       |------|      |      |
*                                 |      |      |      |       |      |      |      |
*                                 `--------------------'       `--------------------'
*/
// FN
[FN] = KEYMAP(
       // left hand
       _______,        KC_F1,        KC_F2,       KC_F3,      KC_F4,       KC_F5,      KC_F6,
       _______,        _______,      _______,     _______,    _______,     _______,    _______,
       _______,        _______,      _______,     _______,    _______,     _______,
       _______,        _______,      _______,     _______,    _______,     _______,    _______,
       _______,        _______,      _______,     _______,    _______,

                       _______,      _______,
                                     DF(BASE),
       _______,        _______,      _______,

       // right hand
       KC_F7,          KC_F8,        KC_F9,        KC_F10,     KC_F11,      KC_F12,     _______,
       _______,        _______,      _______,      _______,    _______,     _______,    _______,
                       _______,      _______,      _______,    _______,     _______,    _______,
       _______,        _______,      _______,      _______,    _______,     _______,    _______,
                                     _______,      _______,    _______,     _______,    _______,

       _______,        _______,
       _______,
       _______,        _______,      _______
),

/* Mouse
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      | Play |           | Vol+ |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      | WhUp |      |      |        |
 * |--------+------+------+------+------+------| Rwd  |           | Vol- |------+------+------+------+------+--------|
 * |        |      | MsLf | MsDn | MsRh |      |------|           |------|      | WhLf | WhDn | WhRh |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | Acc0 | Acc1 | Acc2 |      | Fwd  |           | Mute |      | Btn1 | Btn2 |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      | Base |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------        |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MOUSE] = KEYMAP(
       _______,        _______,    _______,    _______,    _______,    _______,    KC_MPLY,
       _______,        _______,    _______,    KC_MS_UP,   _______,    _______,    KC_MRWD,
       _______,        _______,    KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT,_______,
       _______,        _______, KC_MS_ACCEL0,KC_MS_ACCEL1,KC_MS_ACCEL2,_______,    KC_MFFD,
       _______,        _______,    _______,    _______,    _______,

                       _______,    DF(BASE),
                                   _______,
       _______,        _______,    _______,

       // right hand
       KC_VOLU,        _______,    _______,    _______,    _______,    _______,    _______,
       KC_VOLD,        _______,    _______,    KC_MS_WH_UP,_______,    _______,    _______,
                       _______,    KC_MS_WH_LEFT,KC_MS_WH_DOWN,KC_MS_WH_RIGHT,_______,    _______,
       KC_MUTE,        _______,    KC_MS_BTN1, KC_MS_BTN2, _______,    _______,    _______,
                                   _______,    _______,    _______,    _______,    _______,

       _______,        _______,
       _______,
       _______,        _______,    _______
),

/* IDEA
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      | Renm |           | Usag |      | LnCm | BkCm |      | Term |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      | Refm | WhUp |      |      |        |
 * |--------+------+------+------+------+------| Rwd  |           | Col  |------+------+------+------+------+--------|
 * |        |      | MsLf | MsDn | MsRh |      |------|           |------|      | WhLf | WhDn | WhRh |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | Code | Acc1 | Acc2 |      | Fwd  |           | Mute |      | Btn1 | Btn2 |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      | Base |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------        |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[IDEA] = KEYMAP(
       _______,        _______,    _______,    _______,    _______,    _______,    I_RENAME,
       _______,        _______,    _______,    KC_MS_UP,   _______,    _______,    KC_MRWD,
       _______,        _______,    KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT,_______,
       _______,        _______,    P_CODE,    KC_MS_ACCEL1,KC_MS_ACCEL2,_______,    KC_MFFD,
       _______,        _______,    _______,    _______,    _______,

                       _______,    DF(BASE),
                                   _______,
       _______,        _______,    _______,

       // right hand
       I_FUSAGE,       _______,    I_LN_COM,    I_BK_COM,    _______,    I_TERM,    _______,
       I_COLUMN,       _______,   I_REFORM,    KC_MS_WH_UP,_______,    _______,    _______,
                       _______,    KC_MS_WH_LEFT,KC_MS_WH_DOWN,KC_MS_WH_RIGHT,_______,    _______,
       KC_MUTE,        _______,    KC_MS_BTN1, KC_MS_BTN2, _______,    _______,    _______,
                                   _______,    _______,    _______,    _______,    _______,

       _______,        _______,
       _______,
       _______,        _______,    _______
),
/* Numlock and RTS
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  |   6  |           | Vol+ |  (   |  )   |  =   |  /   |  *   |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |  Up  |      |      |      |      |           |      |      |  7   |  8   |  9   |  -   |        |
 * |--------+------+------+------+------+------|  7   |           | Vol- |------+------+------+------+------+--------|
 * |        | Left | Down |Right |      |      |------|           |------|      |  4   |  5   |  6   |  +   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |  8   |           | Mute |      |  1   |  2   |  3   |Enter |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      | Ctrl |                                       |  0   |  0   |  ,   |Enter |  .   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Base |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------        |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NUM] = KEYMAP(
       _______,        KC_1,       KC_2,       KC_3,         KC_4,       KC_5   ,    KC_6,
       _______,        _______,    KC_UP,      _______,      _______,    _______,    KC_7,
       _______,        KC_LEFT,    KC_DOWN,    KC_RIGHT,   _______,    _______,
       _______,        _______,    _______,    _______,    _______,    _______,    KC_8,
       _______,        _______,    _______,    _______,    KC_RCTL,

                       DF(BASE),   _______,
                                   _______,
       _______,        _______,    _______,

       // right hand
       KC_VOLU,        LSFT(KC_8), LSFT(KC_9), KC_PEQL,    KC_PSLS,    KC_PAST,    _______,
       KC_VOLD,        _______,    KC_P7,      KC_P8,      KC_P9,      KC_PMNS,    _______,
                       _______,    KC_P4,      KC_P5,      KC_P6,      KC_PPLS,    _______,
       KC_MUTE,        _______,    KC_P1,      KC_P2,      KC_P3,      KC_PENT,    _______,
                                   KC_P0,      KC_P0,      KC_PDOT,    KC_PENT,    KC_DOT,

       _______,        _______,
       _______,
       _______,        _______,    _______
),

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt){
    if (record->event.pressed) {
      switch (id) {
        case MACRO_COLUMN_MODE:
          return MACRO(D(LCTL), D(LALT), D(LGUI), T(SLSH), U(LCTL), U(LALT), U(LGUI), END);
        case MACRO_TERMINAL:
          return MACRO(D(LALT), T(F12), U(LALT), END);
      }
    }
    return MACRO_NONE;
};

void matrix_init_user(void) {
  set_unicode_input_mode(UC_OSX);
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    static uint8_t state;

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    //reduce LED on time to 1/6th because LEDs are too strong
    if (++state < 6) return;
    state = 0;

    //bit 1: default layer 1 - QWERTY
    if (default_layer_state & (1UL << QWERTY)) ergodox_right_led_3_on();

    if (default_layer_state & (1UL << FN)) ergodox_right_led_2_on();

    if (default_layer_state & (1UL << NUM)) {
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
    }

    if (default_layer_state & (1UL << MOUSE)) ergodox_right_led_1_on();

    if (default_layer_state & (1UL << IDEA)) {
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
    }

    //uint8_t layer = biton32(layer_state);

    //layer 2 : Symbols (& Fs)
    //if (layer == 2) ergodox_right_led_2_on();

    //layer 3 : F-lock
    //if (layer == 3) ergodox_right_led_2_on();

    //layer 4 : Num-lock
    //if (layer == 4) ergodox_right_led_3_on();
};

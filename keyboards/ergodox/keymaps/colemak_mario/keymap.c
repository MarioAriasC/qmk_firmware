#include "ergodox.h"

enum {
    BASE = 0,
    QWERTY,
    FN,
    IDEA,
    MOUSE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 * MEH:   Alt+Control+Shift
 * HYPER: Alt+Control+Shift+Gui
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   Esc  |  1 ! | 2 "  | 3 ·  | 4 $  | 5 %  |  º \ |           | ' ?  |  6 & | 7 /  |  8 ( | 9 )  | 0 =  | Backsp |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   TAB  |   Q  |   W  |   F  |   P  |   G  |  [   |           |  ]   |   J  |   L  |   U  |   Y  |  Ñ   |  ¡ ¿   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  CAPS  |   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |   O  |  ENT   |
 * |--------+------+------+------+------+------|  {   |           |  }   |------+------+------+------+------+--------|
 * | Shift  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |  , ; |  . : |  UP  | Shift  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  <>  |  -_  | LCTL | LALT | LGUI |                                       | RGUI | RALT | LEFT | DOWN | RIGHT|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,--------------.        ,--------------.
 *                                        | Play | Fwd   |        | Vdwn | Vup   |
 *                                 ,------|------|-------|        |------+-------+------.
 *                                 |      |      | Rwd   |        | Mute |       |      |
 *                                 |Backsp|LShift|-------|        |------|  ENT  |Space |
 *                                 |      |      | Fn    |        | Qwer |       |      |
 *                                 `---------------------'        `---------------------'
 */
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,        KC_5,        KC_NUBS,
        KC_TAB,     KC_Q,       KC_W,       KC_F,       KC_P,        KC_G,        KC_LBRC,
        KC_CAPS,    KC_A,       KC_R,       KC_S,       KC_T,        KC_D,
        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,        KC_B,        KC_QUOT,
        KC_GRV,     KC_SLSH,    KC_LCTL,    KC_LALT,    KC_LGUI,

                    KC_MPLY,    KC_MFFD,
                                KC_MRWD,
        KC_BSPC,    KC_LSFT,    DF(FN),

        // right hand
        KC_MINS,      KC_6,       KC_7,       KC_8,       KC_9,        KC_0,        KC_BSPC,
        KC_RBRC,      KC_J,       KC_L,       KC_U,       KC_Y,        KC_SCLN,     KC_EQL,
                      KC_H,       KC_N,       KC_E,       KC_I,        KC_O,        KC_ENT,
        KC_BSLS,      KC_K,       KC_M,       KC_COMM,    KC_DOT,      KC_UP,       KC_RSFT,
                                  KC_RGUI,    KC_RALT,    KC_LEFT,     KC_DOWN,     KC_RIGHT,

        KC__VOLDOWN,     KC__VOLUP,
        KC__MUTE,
        DF(QWERTY),    KC_ENT,     KC_SPC
    ),

/* Keymap 1: QWERTY layer (games)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       | Base |        |      |
 *                                 `--------------------'       `----------------------'
 */
[QWERTY] = KEYMAP(  // layer 1: QWERTY layer (games)
       KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
       KC_TRNS,        KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_TRNS,
       KC_TRNS,        KC_A,       KC_S,       KC_D,       KC_F,       KC_G,
       KC_TRNS,        KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_TRNS,
       KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,

                       KC_TRNS,    KC_TRNS,
                                   KC_TRNS,
       KC_TRNS,        KC_TRNS,    KC_TRNS,
       
    // right hand
       KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
       KC_TRNS,        KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_TRNS,
                       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_TRNS,
       KC_TRNS,        KC_N,       KC_M,       KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
       KC_TRNS,        KC_TRNS,
       KC_TRNS,
       DF(BASE),        KC_TRNS,    KC_TRNS
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
*                                 |      |      |      |       |      |      |      |
*                                 |      |      |------|       |------|      |      |
*                                 |      |      | Base |       |      |      |      |
*                                 `--------------------'       `--------------------'
*/
// FN
[FN] = KEYMAP(
       // left hand
       KC_TRNS,        KC_F1,        KC_F2,       KC_F3,      KC_F4,       KC_F5,      KC_F6,
       KC_TRNS,        KC_TRNS,      KC_TRNS,     KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,
       KC_TRNS,        KC_TRNS,      KC_TRNS,     KC_TRNS,    KC_TRNS,     KC_TRNS,
       KC_TRNS,        KC_TRNS,      KC_TRNS,     KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,
       KC_TRNS,        KC_TRNS,      KC_TRNS,     KC_TRNS,    KC_TRNS,

                       KC_TRNS,      KC_TRNS,
                                     KC_TRNS,
       KC_TRNS,        KC_TRNS,      DF(BASE),

       // right hand
       KC_F7,          KC_F8,        KC_F9,        KC_F10,     KC_F11,      KC_F12,     KC_TRNS,
       KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,
                       KC_TRNS,      KC_TRNS,      KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,
       KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,
                                     KC_TRNS,      KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,

       KC_TRNS,        KC_TRNS,
       KC_TRNS,
       KC_TRNS,        KC_TRNS,      KC_TRNS
),

/* Keymap 3:
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      | HYPR |           | HYPR |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------        |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// F-keys
[3] = KEYMAP(
       KC_TRNS,        KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,
       KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
       KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
       KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_HYPR,
       KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,

                       KC_TRNS,    KC_TRNS,
                                   KC_TRNS,
       KC_TRNS,        KC_TRNS,    KC_TRNS,

       // right hand
       KC_F7,          KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_TRNS,
       KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                       KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
       KC_HYPR,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,

       KC_TRNS,        KC_TRNS,
       KC_TRNS,
       KC_TRNS,        KC_TRNS,    KC_TRNS
),
/* Keymap 4: Numlock
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | RESET  |      |      |      |P-SCRE|S-LOCK|PAUSE |           |NLOCK | CALC |  =   |  /   |  *   |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      | Vol+ |  7   |  8   |  9   |  -   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| Vol- |  4   |  5   |  6   |  +   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      | HYPR |           | HYPR | Mute |  1   |  2   |  3   |Enter |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |  0   |  .   | RCTL | RCTL |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------        |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[4] = KEYMAP(
       RESET,          KC_LSFT,    KC_LSFT,    KC_SYSREQ,  KC_PSCR,    KC_SLCK,    KC_PAUSE,
       KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
       KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
       KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_HYPR,
       KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,

                       KC_TRNS,    KC_TRNS,
                                   KC_TRNS,
       KC_TRNS,        KC_TRNS,    KC_TRNS,

       // right hand
       KC_NLCK,        KC_CALC,    KC_PEQL,    KC_PSLS,    KC_PAST,    KC_LSFT,    KC_TRNS,
       KC_TRNS,        KC_VOLU,    KC_P7,      KC_P8,      KC_P9,      KC_PMNS,    KC_TRNS,
                       KC_VOLD,    KC_P4,      KC_P5,      KC_P6,      KC_PPLS,    KC_TRNS,
       KC_HYPR,        KC_MUTE,    KC_P1,      KC_P2,      KC_P3,      KC_PENT,    KC_TRNS,
                                   KC_TRNS,    KC_P0,      KC_PDOT,    KC_RCTL,    KC_RCTL,

       KC_TRNS,        KC_TRNS,
       KC_TRNS,
       KC_TRNS,        KC_TRNS,    KC_TRNS
),

};


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

    uint8_t layer = biton32(layer_state);

    //layer 2 : Symbols (& Fs)
    //if (layer == 2) ergodox_right_led_2_on();

    //layer 3 : F-lock
    if (layer == 3) ergodox_right_led_2_on();

    //layer 4 : Num-lock
    if (layer == 4) ergodox_right_led_3_on();
};

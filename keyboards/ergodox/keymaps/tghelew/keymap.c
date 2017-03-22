#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

#define _______ KC_TRNS

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  | LEFT |           |RIGHT |   6  |   7  |   8  |   9  |   0  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |BackS |           |BackS |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | _/LALT |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | _/LALT |
 * |--------+------+------+------+------+------| L1   |           | L2   |------+------+------+------+------+--------|
 * |M-LShift|   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |M-RShift|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |C-Alt |  `  |  '   |Lft/L2|Rht/L1|                                       |Up/L1 |Down/L2| [   |   ]   | C-Alt  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Del  | Home |       | PgUp  |SysRq|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |Backsp| End  |       | PgDn |        |      |
 *                                 | Space|ace   |------|       |------|  Enter |Space |
 *                                 | Ctrl |Alt   | Win  |       | AltGr|  Alt   |Ctrl  |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,        KC_1,         KC_2,       KC_3,  KC_4,   KC_5,   KC_LEFT,
        KC_TAB,        KC_Q,         KC_W,       KC_E,  KC_R,   KC_T,   KC_BSPC,
        ALT_T(KC_UNDS),KC_A,         KC_S,       KC_D,  KC_F,   KC_G,
        LALT(KC_LSFT), KC_Z,         KC_X,       KC_C,  KC_V,   KC_B,   TG(SYMB),
        LCTL(KC_LALT), KC_GRAVE,     KC_QUOTE,   LT(MDIA,KC_LEFT), LT(SYMB,KC_RIGHT),
                                                 KC_DEL,  KC_HOME,
                                                          KC_END,
                                                 CTL_T(KC_SPC),SFT_T(KC_BSPC),KC_LGUI,
        // right hand
             KC_RGHT,     KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_EQUAL,
             KC_BSPC,     KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,             KC_BSLASH,
             KC_H,        KC_J,   KC_K,  KC_L,   KC_SCLN,                  ALT_T(KC_UNDS),
             TG(MDIA),    KC_N,   KC_M,  KC_COMM,KC_DOT, KC_SLSH,          RALT(KC_RSFT),
             LT(SYMB,KC_UP), LT(MDIA,KC_DOWN),   KC_LBRC,KC_RBRC,          RCTL(KC_LALT),
             KC_PGUP,        KC_PSCREEN,
             KC_PGDN,
             KC_RALT,SFT_T(KC_ENTER), CTL_T(KC_SPC)
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   ~  |   +  |   :  |   [  |   ]  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   _  |   =  |   "  |   (  |   )  |------|           |------| Down |   4  |   5  |   6  |   +  |    -   |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   -  |   `  |   '  |   { |   }   |      |           |      |   &  |   1  |   2  |   3  |   /  |  BackS |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |   0  |   .  |   =    |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       VRSN,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  _______,
       _______,KC_TILD,KC_PLUS,  KC_SCLN,KC_LCBR,KC_RBRC,_______,
       _______,KC_UNDS,KC_EQUAL, KC_DQUO,KC_LPRN,KC_RPRN,
       _______,KC_MINS,KC_GRAVE,KC_QUOT,KC_LBRC,KC_RCBR,_______,
       _______,_______,_______,_______,_______,
                                       _______,_______,
                                               _______,
                               _______,_______,_______,
       // right hand
       _______, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       _______, KC_UP,   KC_7,   KC_8,    KC_9,    KC_PAST, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PPLS, KC_PMNS,
       _______, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_PSLS, KC_BSPC,
                          _______,_______,KC_0,    KC_PDOT, KC_PEQL,
       _______, _______,
       _______,
       _______, _______, _______
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  RESET |      |WhRgt| Whup | WhLft|      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | Rclk | MsUp | Lclk |      |      |           |      |      |VolDn | Play |VolUp |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      | Prev | Mute | Next |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |WhRgt | WhDn |WhLft |      |      |           |      |      |      | Stop |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       RESET  , _______, KC_WH_R, KC_WH_U, KC_WH_L, _______, _______,
       _______, _______, KC_BTN2, KC_MS_U, KC_BTN1, _______, _______,
       _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,
       _______, _______, KC_WH_R, KC_WH_D, KC_WH_L, _______, _______,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______,  _______, _______, _______, _______, _______, _______,
       _______,  _______, _______, _______, _______, _______, _______,
                 _______, KC__VOLDOWN, KC__MUTE, KC__VOLUP, _______, _______,
       _______,  _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),
};

const uint16_t PROGMEM fn_actions[] = {
  //    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};

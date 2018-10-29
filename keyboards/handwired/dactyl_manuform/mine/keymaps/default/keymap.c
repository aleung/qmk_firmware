#include "../../4x5.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

#define _BASE 0
#define _FN   1
#define _NUM  2

// Fillers to make layering more clear
#define ____ KC_TRNS

// Mod-Tap
#define SFT_BSPC LSFT_T(KC_BSPC)
#define CMD_DEL  LCMD_T(KC_DEL)
#define CMD_SPC  RCMD_T(KC_SPC)
#define ALT_CAPS ALT_T(KC_CAPS)
#define SFT_ENT  RSFT_T(KC_ENT)
#define CTL_TAB  CTL_T(KC_TAB)

// compose keys
#define CMD_TAB  LCMD(KC_TAB)
#define CMD_RTAB LCMD(KC_GRAVE)
#define CTL_LEFT LCTL(KC_LEFT)
#define CTL_RGHT LCTL(KC_RIGHT)

// mouse keys
#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN1

// toggling layers
#define LY_FN  TT(_FN)
#define LY_NUM TT(_NUM)

// detect mod status
#define MODS_SHIFT_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base (qwerty)
 * ,----------------------------------,                             ,----------------------------------,
 * |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |      |      |      |      |      |                             |      |      |   (  |   )  |   "  |
 * |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   '  |
 * '------+------+------+-------------'                             '-------------+------+------+------'
 *        |  {   |   }  |                                                         |  __  |   +  |
 *        |  [   |   ]  |                                                         |   -  |   =  |
 *        '------+------'-------------.                             .-------------'------+------'
 *                      | BS   | DEL  |                             | SPACE|ENTER |
 *                      | SHIFT| CMD  |                             | CMD  |SHIFT |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    | NUM  | Tab  | | CAP  | NUM  |
 *                                    |      | CTRL | | ALT  |      |
 *                                    '------+------' '------+------'
 *                                    | FN   | ESC  | |      | FN   |
 *                                    '------+------' '------+------'
 */

[_BASE] = LAYOUT( \
  KC_Q, KC_W,    KC_E,  KC_R,    KC_T,                               KC_Y,    KC_U,  KC_I,    KC_O,   KC_P,    \
  KC_A, KC_S,    KC_D,  KC_F,    KC_G,                               KC_H,    KC_J,  KC_K,    KC_L,   KC_SCLN, \
  KC_Z, KC_X,    KC_C,  KC_V,    KC_B,                               KC_N,    KC_M,  KC_COMM, KC_DOT, KC_QUOT, \
        KC_LBRC, KC_RBRC,                                                            KC_MINS, KC_EQL,          \
                        SFT_BSPC,CMD_DEL,                            CMD_SPC, SFT_ENT,                         \
                                     LY_NUM, CTL_TAB, ALT_CAPS, LY_NUM,                                        \
                                     LY_FN,  KC_GESC, ____,     LY_FN                                          \
),

/* Layer: function + navigation
 * ,----------------------------------,                             ,----------------------------------,
 * |  F1  | F2   |  F3  |  F4  |  F5  |                             | del  |      |   ^  |      | VOL+ |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |  F6  | F7   |  F8  |  F9  |  F10 |                             |      |  <-  |   v  |  ->  | MUTE |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |  F11 | F12  |      |      |      |                             | home | end  | PgUp | PgDn | VOL- |
 * '------+------+------+-------------'                             '-------------+------+------+------'
 *        |      |      |                                                         | <-desktop-> |
 *        '------+------'-------------.                             .-------------'------+------'
 *                      | BS   | DEL  |                             | SPACE|ENTER |
 *                      | SHIFT| CMD  |                             | CMD  |SHIFT |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    |      | CTRL | | ALT  |      |
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 */

[_FN] = LAYOUT( \
  KC_F1,  KC_F2,  KC_F3, KC_F4, KC_F5,                        KC_DEL,  KC_HOME, KC_UP,   KC_PGUP,   KC_VOLU,  \
  KC_F6,  KC_F7,  KC_F8, KC_F9, KC_F10,                       ____,    KC_LEFT, KC_DOWN, KC_RIGHT,  KC_MUTE,  \
  KC_F11, KC_F12, ____,  ____,  ____,                         KC_HOME, KC_END,  KC_PGUP, KC_PGDOWN, KC_VOLD,  \
          ____,   ____,                                                         CTL_LEFT,CTL_RGHT,            \
                         SFT_BSPC,CMD_DEL,                    CMD_SPC, SFT_ENT,                               \
                                     ____, KC_LCTL, KC_LALT, ____,                                         \
                                     ____, ____,    ____,    ____                                          \
),

/* Layer: number + symbol
 * ,----------------------------------,                             ,----------------------------------,
 * |  !   |  @   |  #   |  $   |  %   |                             |  \   |  7   |  8   |  9   |  -   |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |  ^   |  &   |  *   |  <   |  >   |                             |  *   |  4   |  5   |  6   |  +   |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |  `   |      |  ?   |  ~   |  |   |                             |  /   |  1   |  2   |  3   |  =   |
 * '------+------+------+-------------'                             '-------------+------+------+------'
 *        |      |      |                                                         |  0   |  .   |
 *        '------+------'-------------.                             .-------------'------+------'
 *                      | BS   | DEL  |                             | SPACE|ENTER |
 *                      | SHIFT| CMD  |                             | CMD  |SHIFT |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    |      | CTRL | | ALT  |      |
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 */

[_NUM] = LAYOUT( \
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                       KC_BSLS, KC_7,  KC_8,   KC_9,   KC_MINS,   \
  KC_CIRC, KC_AMPR, KC_ASTR, KC_LT,   KC_GT,                         KC_ASTR, KC_4,  KC_5,   KC_6,   KC_PLUS,   \
  KC_GRV,  ____,    KC_QUES, KC_TILD, KC_PIPE,                       KC_SLSH, KC_1,  KC_2,   KC_3,   KC_EQL,    \
           ____,    ____,                                                            KC_0,   KC_DOT,             \
                             SFT_BSPC,CMD_DEL,                       CMD_SPC, SFT_ENT,                           \
                                           ____, KC_LCTL, KC_LALT, ____,                                         \
                                           ____, ____,    ____,    ____                                          \
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (get_mods() & MODS_SHIFT_MASK) {
    // modify keycode on shift pressed
    switch (keycode) {
      case KC_COMM:                         // SHIFT + , => (
        if (record->event.pressed) {
          register_code(KC_9);
        } else {
          unregister_code(KC_9);
        }
        return false;
      case KC_DOT:                          // SHIFT + . => )
        if (record->event.pressed) {
          register_code(KC_0);
        } else {
          unregister_code(KC_0);
        }
        return false;
    }
  }
  return true;
}

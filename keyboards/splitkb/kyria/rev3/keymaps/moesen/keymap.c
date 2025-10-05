#include <stdint.h>
#include <string.h>
#include "action_layer.h"
#include "color.h"
#include "info_config.h"
#include "keyboard.h"
#include "keycodes.h"
#include "keymap_common.h"
#include "oled_driver.h"
#include "quantum.h"
#include "rgb_matrix.h"
#include "rgb_matrix_types.h"
#include QMK_KEYBOARD_H
#include "gpio.h"

void keyboard_pre_init_user(void) {
    gpio_set_pin_output(24);
    gpio_write_pin_high(24);
}

static void render_my_logo(void) {
    static const char PROGMEM my_logo[] = {// 'kyria_logo2', 128x64px
                                           0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xa4, 0xfc, 0xf4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x00, 0x20, 0x20, 0x20, 0x20, 0xfc, 0xfc, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00,
                                           0x00, 0x00, 0x04, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x60, 0x70, 0x10, 0x10, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x1f, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x02, 0x03, 0x03, 0x0f, 0x1f, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x00, 0x00, 0x60, 0x02, 0x02, 0x01, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0xfc, 0xfc, 0x20, 0x20, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc1, 0xe1, 0x61, 0x31, 0x31, 0x61, 0xe1, 0xc1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x0c, 0x80, 0x00, 0x00, 0x00, 0x00, 0x23, 0x23, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0xf8, 0xfc, 0xfc, 0xfe, 0xfe, 0xfe, 0xfe, 0x3e, 0x3e, 0x3e, 0xfe, 0xfe, 0xff, 0xff, 0x3c, 0x3c, 0x30,
                                           0x30, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x01, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x83, 0x83, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x80, 0x80, 0x00, 0x04, 0x04, 0x00, 0x00, 0x20, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x1c, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x87, 0x86, 0x86, 0x8e, 0x86, 0x87, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x00, 0x80, 0x80, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x1e, 0x3f, 0x18, 0xd8, 0xc0, 0xc0, 0xd8, 0xdf, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xf8, 0xf8, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xf8, 0xf8, 0xf8, 0xfe, 0xfe, 0xfe, 0xfe,
                                           0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xe0, 0xe0, 0xe0, 0xe0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x0f, 0x0f, 0x06, 0x06, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x02, 0x02, 0x00, 0x00, 0x80, 0x82, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x3f, 0x01, 0x3f, 0x3f, 0x31, 0x1f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x00, 0x07, 0x07, 0x01, 0x41, 0x40, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x0c, 0x1c, 0x7c, 0x7c, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x0f, 0x7e,
                                           0x7e, 0xfc, 0xfc, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xfc, 0x7c, 0x7e, 0x1e, 0x1e, 0x0f, 0x0f, 0x01, 0x81, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0xfc, 0xc0, 0xf0, 0x3c, 0x0c, 0xfc, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0xf0, 0xf2, 0xf2, 0x30, 0x30, 0xf0, 0xe0, 0xe0, 0x38, 0x38, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x78, 0x19, 0x19, 0x01, 0x01, 0x03, 0x01, 0xfc, 0xfc, 0x7f, 0x7f, 0x1f, 0x1f, 0x0b, 0x07, 0x07, 0x00, 0x00, 0x07, 0x07, 0x07, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x03, 0xc0, 0xc0, 0xc3, 0xc3, 0x03, 0x0f, 0x0f, 0x1f, 0x1f, 0x7e, 0x7e, 0x7c, 0x7c, 0x00, 0x03, 0x07, 0x07, 0x0f, 0x0f, 0x0f, 0x07, 0x07, 0x07, 0x03, 0x03, 0x03, 0x01, 0x01, 0x30, 0x30, 0x30,
                                           0x30, 0x30, 0x30, 0x30, 0x31, 0x30, 0x38, 0x30, 0x30, 0x38, 0x38, 0x32, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x00, 0x00, 0xc0, 0xf0, 0x30, 0xf0, 0xf0, 0x30, 0xf0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd9, 0xd9, 0xdf, 0xdf, 0xcf, 0xcf, 0xc9, 0xf9, 0xf9, 0xf9, 0xf9, 0xd9, 0xd9, 0xd9, 0xd9, 0xf9, 0xf9, 0xf9, 0xf9, 0xff, 0xff, 0xff, 0xf9, 0xf9, 0xd9, 0xd9, 0xd8, 0xd8, 0xf8, 0xf8, 0xf8, 0xd8, 0xd8, 0xc8, 0xc8, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc8, 0xc8, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc8, 0xc0, 0xc0, 0xc0, 0xc0, 0xc8, 0xd8, 0xd8, 0xd8, 0xd8, 0xd8, 0xd8, 0xd8, 0xd8, 0xc8, 0xc8, 0xd8, 0xd8, 0xd9, 0xd9, 0xdf, 0xdf, 0xcf, 0xcf, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xd9, 0x59, 0xd9, 0xf9, 0xf9, 0xf9, 0xf9, 0xd9, 0xd9, 0xd9, 0xff, 0xff, 0xf9, 0xf9, 0x00,
                                           0x00, 0x87, 0x87, 0x80, 0x87, 0x87, 0x86, 0x83, 0x81, 0x00, 0x00, 0x00, 0x00, 0x00, 0x26, 0x26, 0x3e, 0x3f, 0x27, 0x27, 0x26, 0x26, 0x26, 0x26, 0x26, 0x26, 0x26, 0x27, 0x27, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x26, 0x26, 0xe7, 0xe7, 0xe7, 0xe7, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0xe6, 0xe6, 0xe6, 0xfe, 0x3e, 0x3e, 0x26, 0x26, 0x26, 0x26, 0x3e, 0x3e, 0x3e, 0x3e, 0x26, 0x26, 0x26, 0x26, 0x26, 0x26, 0x26, 0x26, 0xe6, 0xe6, 0xe6, 0x26, 0x26, 0x3e, 0x3e, 0x3e, 0x3e, 0xe6, 0xe6, 0xe6, 0x26, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0xe6, 0xe6, 0xe7, 0xe7, 0x27, 0x27, 0x26, 0x26, 0x3e, 0x3f, 0x3f, 0x27, 0x27, 0xe7, 0xe7, 0xfe, 0x3e, 0x3e, 0x2e, 0x26, 0x26, 0x26, 0x26, 0x26, 0x27, 0x27, 0x27, 0x27, 0x26, 0x26, 0x27, 0x27, 0x27, 0x27, 0x27, 0x26, 0x26, 0x26, 0x3e, 0x3e, 0x26, 0x26, 0x00, 0x00, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x1f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00};
    oled_write_raw_P(my_logo, sizeof(my_logo));
}

enum layers {
    _QWERTY = 0,
    _NAV,
    _SYM,
    _CODE,
    _FUNCTION,
    _ADJUST,
};

// Aliases for readability
#define QWERTY DF(_QWERTY)

#define SYM MO(_SYM)
#define NAV MO(_NAV)
#define CODE MO(_CODE)
#define FKEYS MO(_FUNCTION)
#define ADJUST MO(_ADJUST)

#define SFT_ESC MT(MOD_LSFT, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT MT(MOD_LALT, KC_ENT)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | [ {  |CapsLk|  |F-keys|  ] } |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
 *                        |      |      | Enter|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
     KC_TAB  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                        KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_BSPC,
     SFT_ESC , KC_A ,  KC_S   ,  KC_D  ,   KC_F ,   KC_G ,                                        KC_H,   KC_J ,  KC_K ,   KC_L ,KC_SCLN,KC_QUOT,
     KC_LCTL , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , KC_LBRC,KC_CAPS,     FKEYS  , KC_RBRC, KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
                                ADJUST , KC_LGUI, CODE, ALT_ENT , NAV   ,     SYM    , KC_SPC ,KC_RALT, KC_RGUI, KC_APP
    ),

/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              | PgUp | Home |   ↑  | End  | VolUp| Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  GUI |  Alt | Ctrl | Shift|      |                              | PgDn |  ←   |   ↓  |   →  | VolDn| Insert |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |ScLck |  |      |      | Pause|M Prev|M Play|M Next|VolMut| PrtSc  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_VOLU, KC_DEL,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                     KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_VOLD, KC_INS,
      _______, _______, _______, _______, _______, _______, _______, KC_SCRL, _______, _______,KC_PAUSE, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_PSCR,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    `   |  1   |  2   |  3   |  4   |  5   |                              |   6  |  7   |  8   |  9   |  0   |   =    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |    ~   |  !   |  @   |  #   |  $   |  %   |                              |   ^  |  &   |  *   |  (   |  )   |   +    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |    |   |   \  |  :   |  ;   |  -   |  [   |  {   |      |  |      |   }  |   ]  |  _   |  ,   |  .   |  /   |   ?    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
      KC_GRV ,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 ,                                       KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0 , KC_EQL ,
     KC_TILD , KC_EXLM,  KC_AT , KC_HASH,  KC_DLR, KC_PERC,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
     KC_PIPE , KC_BSLS, KC_COLN, KC_SCLN, KC_MINS, KC_LBRC, KC_LCBR, _______, _______, KC_RCBR, KC_RBRC, KC_UNDS, KC_COMM,  KC_DOT, KC_SLSH, KC_QUES,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Code Layer: Symbols and macros for coding
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |  [   |  ]   |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |  (   |  )   |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |  {   |  }   |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */

    [_CODE] = LAYOUT(
    _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                    _______ , KC_LBRC, KC_RBRC,_______, _______,_______,
    _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                    _______ , KC_LPRN, KC_RPRN,_______,_______,_______,
    _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______, _______, _______ ,_______ ,_______ , KC_LCBR, KC_RCBR,_______,_______,_______,
                               _______ ,_______ ,_______ ,_______, _______, _______ ,_______ ,_______ ,_______ , _______
    ),

/*
 * Function Layer: Function keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  F9  | F10  | F11  | F12  |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F5  |  F6  |  F7  |  F8  |      |                              |      | Shift| Ctrl |  Alt |  GUI |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUNCTION] = LAYOUT(
      _______,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, _______,                                     _______, _______, _______, _______, _______, _______,
      _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______,                                     _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______,
      _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Adjust Layer: Default layer settings, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |QWERTY|      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |Dvorak|      |      |                              | TOG  | SAI  | HUI  | VAI  | MOD  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |Colmak|      |      |      |      |  |      |      |      | SAD  | HUD  | VAD  | RMOD |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      _______, _______, _______, QWERTY , _______, _______,                                    _______, _______, _______, _______,  _______, _______,
      _______, _______, _______, _______, _______, RM_TOGG,                                    RM_SPDU, RM_SATU, RM_HUEU, RM_VALU, RM_NEXT,  _______,
      _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, RM_SPDD, RM_SATD, RM_HUED, RM_VALD, RM_PREV,  _______,
                                 _______, _______, _______,_______, _______, _______, _______, _______, _______, _______
    ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */


#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }
bool oled_task_user(void) {
    oled_clear();
    if (is_keyboard_master()) {
        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state | default_layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("QWERTY\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Nav\n"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("Sym\n"), false);
                break;
            case _CODE:
                oled_write_P(PSTR("Code\n"), false);
                break;
            case _FUNCTION:
                oled_write_P(PSTR("Function\n"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("Adjust\n"), false);
#    ifdef RGB_MATRIX_ENABLE
                // Mode
                oled_write_P("RGB Mode: ", false);
                oled_write_ln_P(get_u8_str(rgb_matrix_get_mode(), ' '), false);
                // Hue
                oled_write_P("Hue: ", false);
                oled_write_ln_P(get_u8_str(rgb_matrix_get_hue(), ' '), false);
                // Saturation
                oled_write_P("Sat: ", false);
                oled_write_ln_P(get_u8_str(rgb_matrix_get_sat(), ' '), false);
                // Brightnesss
                oled_write_P("Val: ", false);
                oled_write_ln_P(get_u8_str(rgb_matrix_get_val(), ' '), false);
                // Speed
                oled_write_P("Speed: ", false);
                oled_write_ln_P(get_u8_str(rgb_matrix_get_speed(), ' '), false);
#    endif
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
        render_my_logo();
    }
    return false;
}
#endif

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (get_highest_layer(layer_state) > 0) {
        uint8_t layer      = get_highest_layer(layer_state);
        // uint8_t brightness = 64; // 0-255 (64=25%)
        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];
                if (index >= led_min && index < led_max && index != NO_LED) {
                    if (keymap_key_to_keycode(layer, (keypos_t){col, row}) > KC_TRNS) {
                        // rgb_matrix_set_color(index, (139 * brightness) / 255, (164 * brightness) / 255, (176 * brightness) / 255);
                    } else {
                        rgb_matrix_set_color(index, RGB_BLACK);
                    }
                }
            }
        }
    }
    return false;
}

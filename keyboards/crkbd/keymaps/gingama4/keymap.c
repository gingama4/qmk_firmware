#include QMK_KEYBOARD_H

enum layer {
    LAYER_DEFAULT,
    LAYER_LOWER,
    LAYER_RAISE,
    LAYER_ADJUST,
};

enum user_macro {
    UM_F13,
    UM_F14,
};

#define LY_LWR MO(LAYER_LOWER)
#define LY_RSE MO(LAYER_RAISE)

#define KY_CTAB LCTL_T(KC_TAB)

#define M_F13 MACROTAP(UM_F13)
#define M_F14 MACROTAP(UM_F14)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_DEFAULT] = LAYOUT(
        KC_ESC,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                         KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_MINS,
        KY_CTAB,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                         KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                         KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RGUI,
                                                KC_LALT,  M_F13,   KC_SPC,   KC_ENT,    M_F14,   KC_BSPC
    ),

    [LAYER_LOWER] = LAYOUT(
        _______,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,                      KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_UNDS,
        _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LBRC,                      KC_RBRC,  KC_PLUS,  KC_EQL,   XXXXXXX,  KC_COLN,  KC_DQUO,
        _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LCBR,                      KC_RCBR,  KC_PIPE,  KC_GRV,   KC_TILD,  KC_QUES,  KC_BSLS,
                                                _______,  _______,  _______,  _______,  _______,  _______
    ),

    [LAYER_RAISE] = LAYOUT(
        _______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                         KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                        KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_F11,   KC_DEL,
        _______,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,                       KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_F12,   KC_INS,
                                                _______,  _______,  _______,  _______,  _______,  _______
    ),

    [LAYER_ADJUST] = LAYOUT(
        _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,                      RGB_RMOD, KC_VOLD,  KC_VOLU,  _______,  _______,  _______,
        _______,  _______,  KC_CUT,   KC_COPY,  KC_PSTE,  _______,                      _______,  KC_MUTE,  _______,  _______,  _______,  _______,
                                                _______,  _______,  _______,  _______,  _______,  _______
    ),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch(id) {

        case UM_F13: {
            return MACRO_TAP_HOLD_LAYER( record, MACRO(TYPE(KC_F13), END), LAYER_LOWER);
        } break;

        case UM_F14: {
            return MACRO_TAP_HOLD_LAYER( record, MACRO(TYPE(KC_F14), END), LAYER_RAISE);
        } break;
    }
    return MACRO_NONE;
};

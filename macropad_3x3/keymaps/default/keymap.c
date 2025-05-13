// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌────────────┬────────────┬────────────┐
     * │ Prev Track │ Play/Pause │ Next Track │
     * ├────────────┼────────────┼────────────┤
     * │     4      │     5      │      6     │
     * ├────────────┼────────────┼────────────┤
     * │     1      │     2      │      3     │
     * └────────────┴────────────┴────────────┘
     */
     [0] = LAYOUT(
      KC_MPRV,   KC_MPLY, KC_MNXT,
      _______,   KC_MUTE, _______,
      _______,   _______, _______
  )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)}
};
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

bool oled_task_user(void) {
    oled_set_cursor(0, 1);

    oled_write("NETDECK Mk II", false);
    return false;
}
#endif

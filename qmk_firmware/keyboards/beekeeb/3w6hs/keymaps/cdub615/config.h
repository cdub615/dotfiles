// Copyright 2023 beekeeb
// Copyright 2021 weteor
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 10

#define MATRIX_ROWS_PER_SIDE (MATRIX_ROWS / 2)
#define MATRIX_COLS_PER_SIDE (MATRIX_COLS / 2)

#define MATRIX_ROW_PINS_L { GP7, GP8, GP9, GP10}
#define MATRIX_COL_PINS_L { GP11, GP12, GP13, GP14, GP15 }

#define MATRIX_ROW_PINS_R { P10, P11, P12, P05 }
#define MATRIX_COL_PINS_R { P06, P13, P14, P01, P00 }

#define I2C_DRIVER I2CD0
#define I2C1_SDA_PIN GP0
#define I2C1_SCL_PIN GP1

#define PERMISSIVE_HOLD

#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY
/* #define OS_DETECTION_DEBOUNCE 1000 */
/* #define OS_DETECTION_KEYBOARD_RESET */
/* #define OS_DETECTION_DEBUG_ENABLE */

/* #define VIAL_KEYBOARD_UID {0x75, 0x21, 0x0B, 0x9E, 0x98, 0x5B, 0x0B, 0x17} */
/* #define DYNAMIC_KEYMAP_LAYER_COUNT 10 */
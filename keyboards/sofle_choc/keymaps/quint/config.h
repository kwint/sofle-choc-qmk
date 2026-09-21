// Copyright 2026 Quint van Dijk
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

// ---------------------------------------------------------------------------
// Layers
// ---------------------------------------------------------------------------
// LOWER + RAISE held together activates ADJUST (QMK's tri-layer feature).
#define TRI_LAYER_LOWER_LAYER 2
#define TRI_LAYER_UPPER_LAYER 3
#define TRI_LAYER_ADJUST_LAYER 4

// ---------------------------------------------------------------------------
// Split
// ---------------------------------------------------------------------------
#define MASTER_LEFT       // plug USB into the left half
#define SPLIT_USB_DETECT  // ...but survive it being plugged into the right

// Push layer and caps-lock state across the TRRS cable so the second OLED can
// display them too. Each costs a little flash; drop them if you need room.
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE

// ---------------------------------------------------------------------------
// Per-key RGB
// ---------------------------------------------------------------------------
#define RGB_MATRIX_SLEEP                   // lights off when the host suspends
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 100  // higher can brown out a Pro Micro
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT

// The ATmega32U4 only has 28 KB of flash and the board enables all 29 matrix
// animations by default, which leaves no room for a real keymap. Five are kept
// (breathing, cycle left/right, rainbow chevron, cycle out-in dual, plus the
// always-present solid colour). Delete an #undef below to get one back, then
// rebuild and watch the reported firmware size.
#undef ENABLE_RGB_MATRIX_ALPHAS_MODS
#undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#undef ENABLE_RGB_MATRIX_BAND_SAT
#undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#undef ENABLE_RGB_MATRIX_BAND_VAL
#undef ENABLE_RGB_MATRIX_CYCLE_ALL
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#undef ENABLE_RGB_MATRIX_DUAL_BEACON
#undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#undef ENABLE_RGB_MATRIX_HUE_BREATHING
#undef ENABLE_RGB_MATRIX_HUE_PENDULUM
#undef ENABLE_RGB_MATRIX_HUE_WAVE
#undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#undef ENABLE_RGB_MATRIX_PIXEL_FLOW
#undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#undef ENABLE_RGB_MATRIX_PIXEL_RAIN
#undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
#undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#undef ENABLE_RGB_MATRIX_RAINDROPS

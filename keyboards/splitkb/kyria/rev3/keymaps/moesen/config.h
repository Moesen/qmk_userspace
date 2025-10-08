/* Copyright 2022 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 *f along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_EFFECT_BREATHING
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    define RGBLIGHT_EFFECT_SNAKE
#    define RGBLIGHT_EFFECT_KNIGHT
#    define RGBLIGHT_EFFECT_CHRISTMAS
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
#    define RGBLIGHT_EFFECT_RGB_TEST
#    define RGBLIGHT_EFFECT_ALTERNATING
#    define RGBLIGHT_EFFECT_TWINKLE
#    define RGBLIGHT_HUE_STEP 8
#    define RGBLIGHT_SAT_STEP 8
#    define RGBLIGHT_VAL_STEP 8
#    ifndef RGBLIGHT_LIMIT_VAL
#    	define RGBLIGHT_LIMIT_VAL 150
#    endif
#    define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT
#    define RGBLIGHT_DEFAULT_HUE 0
#    define RGBLIGHT_DEFAULT_SAT 0
#    define RGBLIGHT_DEFAULT_VAL 150
#endif

#ifdef RGB_MATRIX_ENABLE
// Per-key defaults to white
#    define RGB_MATRIX_DEFAULT_HUE 0
#    define RGB_MATRIX_DEFAULT_SAT 100
#    define RGB_MATRIX_DEFAULT_VAL 200
#    define RGB_MATRIX_TIMEOUT 0
#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
#    define RGB_MATRIX_MODE_NAME_ENABLE
#    define RGB_MATRIX_KEYPRESSES
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#    define ENABLE_RGB_MATRIX_SPLASH
#    define ENABLE_RGB_MATRIX_MULTISPLASH
#    define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#    define RGB_MATRIX_TYPING_HEATMAP_SPREAD 40
#    define RGB_MATRIX_TYPING_HEATMAP_AREA_LIMIT 16
#endif

#define TAPPING_TERM 125
#define PERMISSIVE_HOLD
#define SPLIT_LAYER_STATE_ENABLE

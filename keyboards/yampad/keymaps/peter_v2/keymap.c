/* MIT License

Copyright (c) 2019 Mattia Dal Ben

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers {
    _BL, // BaseLayer, standard numpad
    _VOC, // TeamSpeak Binds, CSGO Chat Macros
    _FN, // RGB Functions
    _RPL, // CSGO Replays
    _SKBX, // Skybox.gg
    _MED, // Media Keys
    _YT // Youtube
};

enum custom_keycodes {
    KC_DBL0 = SAFE_RANGE,
    KC_TRL0,
    KC_RAGEQUIT,
    KC_THROW_en,
    KC_DONTTHROW_en,
    KC_ZZZ,
    KC_NOCOMMENT_de,
    KC_HOBBY_de,
    KC_DONTFACE_de,
    KC_SOLD_de,
    KC_TIME_de 
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BL] = LAYOUT(
    TO(_VOC),  TG(_FN),  TG(_RPL),   TG(_MED),
    KC_P7,    KC_P8,    KC_P9,
    KC_P4,    KC_P5,    KC_P6,     KC_PPLS,
    KC_P1,    KC_P2,    KC_P3,
    KC_P0,    KC_TRL0,  KC_PDOT,   KC_PENT
  ),


  [_VOC] = LAYOUT(
    TO(_FN),  TG(_FN),  TG(_RPL),   TG(_MED),
    KC_THROW_en,   KC_DONTTHROW_en ,   KC_ZZZ,
    KC_NOCOMMENT_de,  KC_HOBBY_de,  KC_DONTFACE_de,   KC_F24,
    KC_SOLD_de,  KC_TIME_de,    KC_RAGEQUIT,
    KC_F13,  KC_F14,  KC_F15,   KC_F23
  ),


  [_FN] = LAYOUT(
    TO(_RPL),  TG(_FN),  TG(_RPL),   TG(_MED),
    RGB_HUD,  RGB_HUI,  XXXXXXX,
    RGB_SAD,  RGB_SAI,  XXXXXXX,   XXXXXXX,
    RGB_VAD,  RGB_VAI,  XXXXXXX,
    QK_BOOT,    XXXXXXX,  XXXXXXX,   XXXXXXX
  ),

  [_RPL] = LAYOUT(
    TO(_SKBX),  TG(_FN),  TG(_RPL),   TG(_MED),
    XXXXXXX,  RGB_HUI,  XXXXXXX,
    KC_RAGEQUIT,  RGB_SAI,  XXXXXXX,   XXXXXXX,
    RGB_VAD,  RGB_VAI,  XXXXXXX,
    QK_BOOT,    XXXXXXX,  XXXXXXX,   XXXXXXX
  ),

  [_SKBX] = LAYOUT(
    TO(_MED),  TG(_FN),  TG(_RPL),   TG(_MED),
    KC_X,  KC_G,  KC_PGUP,
    LCTL(KC_B),  KC_SPC,  LCTL(KC_N),   LCTL(KC_O),
    LCTL(KC_1),  LCTL(KC_2),  KC_PGDN,
    LCTL(KC_3),    LCTL(KC_4),  LCTL(KC_5),   LCTL(KC_F)
  ),

  [_MED] = LAYOUT(
    TO(_YT),  TG(_FN),  TG(_RPL),   TG(_MED),
    XXXXXXX,  KC_VOLU,  XXXXXXX,
    KC_MPRV,  KC_MPLY,  KC_MNXT,   XXXXXXX,
    XXXXXXX,  KC_VOLD,  XXXXXXX,
    XXXXXXX,    XXXXXXX,  XXXXXXX,   XXXXXXX
  ),
  [_YT] = LAYOUT(
    TO(_BL),  TG(_FN),  TG(_RPL),   TG(_MED),
    LSFT(KC_COMM),  KC_UP,  LSFT(KC_DOT),
    KC_LEFT,  KC_SPC,  KC_RIGHT,   KC_TRANSPARENT,
    KC_COMM,  KC_DOWN,  KC_DOT,
    KC_C,    XXXXXXX,  XXXXXXX,   KC_TRANSPARENT
  ),


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_DBL0:
      if (record->event.pressed) {
        SEND_STRING("00");
      } else {
        // when keycode KC_DBL0 is released
      }
      break;
    case KC_TRL0:
      if (record->event.pressed) {
          SEND_STRING("000");
        } else {
          // when keycode KC_DBL0 is released
        }
        break;
    case KC_RAGEQUIT:
        if (record->event.pressed) {
            register_code(KC_F10);
            unregister_code(KC_F10);
            SEND_STRING(SS_DELAY(50));
            register_code(KC_ENT);
            unregister_code(KC_ENT);
        } else {
            // when keycode KC_DBL0 is released
        }
        break;
    case KC_THROW_en:
        if (record->event.pressed) {
            SEND_STRING("u" SS_DELAY(50) "Come on guzs, we are throwing this round so hard! \n");
        } else {
            // when keycode KC_DBL0 is released
        }
        break;
      case KC_DONTTHROW_en:
        if (record->event.pressed) {
            SEND_STRING("u" SS_DELAY(50) "We have the advantage, pls plaz it out safelz and dont throw! \n");
        } else {
            // when keycode KC_DBL0 is released
        }
        break;
      case KC_ZZZ:
        if (record->event.pressed) {
            SEND_STRING("u" SS_DELAY(50) "yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyYYYYYYYYYYYYYYYYYYYYYYYYYYYYYyyyyyyyyyyyyyyyyyyyyyyyyyyy\n");
        } else {
            // when keycode KC_DBL0 is released
        }
        break;
      case KC_NOCOMMENT_de:
        if (record->event.pressed) {
            SEND_STRING("u" SS_DELAY(50) "... Ich sag gar nix\n");
        } else {
            // when keycode KC_DBL0 is released
        }
        break;
      case KC_HOBBY_de:
        if (record->event.pressed) {
            SEND_STRING("u" SS_DELAY(50) "Ich mach Hobbzmove\n");
        } else {
            // when keycode KC_DBL0 is released
        }
        break;
      case KC_DONTFACE_de:
        if (record->event.pressed) {
            SEND_STRING("u" SS_DELAY(50) "Jetyt B I T T E     N I C H T   dumm reinfacen!\n");
        } else {
            // when keycode KC_DBL0 is released
        }
        break;
      case KC_SOLD_de:
        if (record->event.pressed) {
            SEND_STRING("u" SS_DELAY(50) "Verkauft\n");
        } else {
            // when keycode KC_DBL0 is released
        }
        break;
      case KC_TIME_de:
        if (record->event.pressed) {
            SEND_STRING("u" SS_DELAY(50) "Das dauert schon wieder alles viel zu lange\n");
        } else {
            // when keycode KC_DBL0 is released
        }
        break;
  }
  
  return true;
};


// //rgbzeug

const rgblight_segment_t PROGMEM base_light[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 9, HSV_BLUE}
);
const rgblight_segment_t PROGMEM rgb_light[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 3, HSV_RED},
{3, 3, HSV_GREEN},
{6, 3, HSV_BLUE}
);

const rgblight_segment_t PROGMEM voc_light[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 9, HSV_GREEN}
);
const rgblight_segment_t PROGMEM med_light[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 9, HSV_CYAN}
);
const rgblight_segment_t PROGMEM yt_light[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 9, HSV_RED}
);
const rgblight_segment_t PROGMEM skbx_light[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 9, HSV_PURPLE}
);

const rgblight_segment_t* const PROGMEM rgb_layer[] = RGBLIGHT_LAYERS_LIST(
  base_light,
  voc_light,
  med_light,
  yt_light,
  skbx_light,
  rgb_light
);


void keyboard_post_init_user(void) {
  rgblight_layers = rgb_layer;

}


layer_state_t default_layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(0, layer_state_cmp(state, _BL));
  return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(1, layer_state_cmp(state, _VOC));
  rgblight_set_layer_state(2, layer_state_cmp(state, _MED));
  rgblight_set_layer_state(3, layer_state_cmp(state, _YT));
  rgblight_set_layer_state(4, layer_state_cmp(state, _SKBX));
  rgblight_set_layer_state(5, layer_state_cmp(state, _FN));
  return state;
}

                                                                                                                  
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;  // flips the display 270 degrees
}

bool oled_task_user(void) {
  // Host Keyboard Layer Status
  oled_write_P(PSTR("Layer"), false);
  switch (get_highest_layer(layer_state)) {
    case _BL:
      oled_write_ln_P(PSTR(" BAS"), false);
      break;
    case _VOC:
      oled_write_ln_P(PSTR(" VOC"), false);
      break;
    case _RPL:
      oled_write_ln_P(PSTR(" RPL"), false);
      break;
    case _SKBX:
      oled_write_ln_P(PSTR("SKBX"), false);
      break;
    case _MED:
      oled_write_ln_P(PSTR(" MED"), false);
      break;
    case _FN:
      oled_write_ln_P(PSTR(" RGB"), false);
      break;
    case _YT:
      oled_write_ln_P(PSTR("  YT"), false);
      break;
    default:
      // Or use the write_ln shortcut over adding '\n' to the end of your string
      oled_write_ln_P(PSTR(" UND"), false);
  }

  // Host Keyboard LED Status
  led_t led_state = host_keyboard_led_state();
  oled_write_P(PSTR("-----"), false);
  oled_write_P(PSTR("Stats"), false);
  oled_write_P(led_state.num_lock ? PSTR("num:*") : PSTR("num:."), false);
  oled_write_P(led_state.caps_lock ? PSTR("cap:*") : PSTR("cap:."), false);
  oled_write_P(led_state.scroll_lock ? PSTR("scr:*") : PSTR("scr:."), false);

  // Host Keyboard RGB backlight status
  oled_write_P(PSTR("-----"), false);
  oled_write_P(PSTR("Light"), false);

  static char led_buf[30];
  snprintf(led_buf, sizeof(led_buf) - 1, "RGB:%cM: %2d\nh: %2ds: %2dv: %2d\n",
      rgblight_is_enabled() ? '*' : '.', (uint8_t)rgblight_get_mode(),
      (uint8_t)(rgblight_get_hue() / RGBLIGHT_HUE_STEP),
      (uint8_t)(rgblight_get_sat() / RGBLIGHT_SAT_STEP),
      (uint8_t)(rgblight_get_val() / RGBLIGHT_VAL_STEP));
  oled_write(led_buf, false);

    return false;
}
#endif

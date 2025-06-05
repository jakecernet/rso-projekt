#include <string.h>

#include "actions.h"
#include "fonts.h"
#include "images.h"
#include "screens.h"
#include "styles.h"
#include "ui.h"
#include "vars.h"

#include "esp_log.h"
#include "esp_netif.h"
#include "esp_wifi.h"
#include "lwip/ip_addr.h"
#include "lwip/netif.h"

static void switch_to_wifi_cb(lv_event_t *e) {
    lv_scr_load(objects.nastavitve);
}

static void slider_event_cb(lv_event_t *e);

objects_t objects;
lv_obj_t *tick_value_change_obj;
uint32_t active_theme_index = 0;

int stevilo_mest = 60;

lv_obj_t *physical_slider_obj = NULL;

void increment_stevilo_mest_cb(lv_event_t *e) {
    stevilo_mest++;
    char stevilo_mest_str[10];
    snprintf(stevilo_mest_str, sizeof(stevilo_mest_str), "%d", stevilo_mest);
    lv_label_set_text(objects.st_mest, stevilo_mest_str);
}

void decrement_stevilo_mest_cb(lv_event_t *e) {
    if (stevilo_mest > 0) {
        stevilo_mest--;
        char stevilo_mest_str[10];
        snprintf(stevilo_mest_str, sizeof(stevilo_mest_str), "%d", stevilo_mest);
        lv_label_set_text(objects.st_mest, stevilo_mest_str);
    }
}

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // text
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.text = obj;
            lv_obj_set_pos(obj, 70, 15);
            lv_obj_set_size(obj, 180, 78);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // text_iz_weba
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.text_iz_weba = obj;
                    lv_obj_set_pos(obj, 74, 31);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Text");
                }
            }
        }
        {
            // gumba
            lv_obj_t *obj = lv_spangroup_create(parent_obj);
            objects.gumba = obj;
            lv_obj_set_pos(obj, 37, 78);
            lv_obj_set_size(obj, 246, 100);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // vn_gumb
                    lv_obj_t *obj = lv_button_create(parent_obj);
                    objects.vn_gumb = obj;
                    lv_obj_set_pos(obj, 33, 25);
                    lv_obj_set_size(obj, 50, 50);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff21f337), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff95d39b), LV_PART_MAIN | LV_STATE_PRESSED);
                    lv_obj_add_event_cb(obj, increment_stevilo_mest_cb, LV_EVENT_CLICKED, NULL);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_image_create(parent_obj);
                            lv_obj_set_pos(obj, -11, -6);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_image_set_src(obj, &img_gre_vn);
                        }
                    }
                }
                {
                    // not_gumb
                    lv_obj_t *obj = lv_button_create(parent_obj);
                    objects.not_gumb = obj;
                    lv_obj_set_pos(obj, 163, 25);
                    lv_obj_set_size(obj, 50, 50);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff32121), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffdf4a4a), LV_PART_MAIN | LV_STATE_PRESSED);
                    lv_obj_add_event_cb(obj, decrement_stevilo_mest_cb, LV_EVENT_CLICKED, NULL);

                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_image_create(parent_obj);
                            lv_obj_set_pos(obj, -11, -6);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_image_set_src(obj, &img_gre_not);
                        }
                    }
                }
                {
                    // st_mest
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.st_mest = obj;
                    lv_obj_set_pos(obj, 111, 39);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "60");
                }
            }
        }
        {
            // slider
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.slider = obj;
            lv_obj_set_pos(obj, 10, 178);
            lv_obj_set_size(obj, 300, 58);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Create the physical slider
                    lv_obj_t *slider = lv_slider_create(parent_obj);
                    physical_slider_obj = slider; // so main.cpp can reference it
                    lv_obj_set_pos(slider, 5, 17);
                    lv_obj_set_size(slider, 235, 24);
                    lv_slider_set_value(slider, 25, LV_ANIM_OFF);
                    lv_obj_add_event_cb(slider, slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
                }
                {
                    // slider_num
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.slider_num = obj;
                    lv_obj_set_pos(obj, 260, 17);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "25");
                }
            }
        }
        {
            // switch_to_wifi
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.switch_to_wifi = obj;
            lv_obj_set_pos(obj, 250, 0);
            lv_obj_set_size(obj, 70, 46);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Wi-Fi");
                }
            }
        }
    }

    tick_screen_main();
}

void tick_screen_main() {
}

void create_screen_nastavitve() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.nastavitve = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // ssid_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.ssid_label = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "SSID");
        }
        {
            // ssid_pass_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.ssid_pass_label = obj;
            lv_obj_set_pos(obj, 0, 65);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "PASSWORD");
        }
        {
            // kbd
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.kbd = obj;
            lv_obj_set_pos(obj, 0, 120);
            lv_obj_set_size(obj, 320, 120);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // b_connect
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.b_connect = obj;
            lv_obj_set_pos(obj, 257, 81);
            lv_obj_set_size(obj, 63, 35);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Connect");
                }
            }
        }
        {
            // b_back
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.b_back = obj;
            lv_obj_set_pos(obj, 258, 17);
            lv_obj_set_size(obj, 63, 35);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Back");
                }
            }
        }
        {
            // tb_ssid_pass
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.tb_ssid_pass = obj;
            lv_obj_set_pos(obj, 0, 81);
            lv_obj_set_size(obj, 235, 35);
            lv_textarea_set_max_length(obj, 32);
            lv_textarea_set_placeholder_text(obj, "SSID password");
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, true);
        }
        {
            // tb_ssid_text
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.tb_ssid_text = obj;
            lv_obj_set_pos(obj, 1, 17);
            lv_obj_set_size(obj, 235, 36);
            lv_textarea_set_max_length(obj, 32);
            lv_textarea_set_placeholder_text(obj, "SSID");
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
        }
    }

    tick_screen_nastavitve();
}

void tick_screen_nastavitve() {
}

// Add the slider event callback function
static void slider_event_cb(lv_event_t *e) {
    lv_obj_t *slider = lv_event_get_target(e);
    int value = lv_slider_get_value(slider);
    char buf[10];
    snprintf(buf, sizeof(buf), "%d", value);
    lv_label_set_text(objects.slider_num, buf);
}

typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_nastavitve,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);

    create_screen_main();
    create_screen_nastavitve();
}

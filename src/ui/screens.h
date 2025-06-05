#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *nastavitve;
    lv_obj_t *garaza;
    lv_obj_t *img_h_hand;
    lv_obj_t *img_m_hand;
    lv_obj_t *img_s_hand;
    lv_obj_t *b1;
    lv_obj_t *b1_label;
    lv_obj_t *wi_fi_bli;
    lv_obj_t *ssid_label;
    lv_obj_t *ssid_pass_label;
    lv_obj_t *kbd;
    lv_obj_t *b_connect;
    lv_obj_t *b_back;
    lv_obj_t *tb_ssid_pass;
    lv_obj_t *tb_ssid_text;
    lv_obj_t *mesta_text;
    lv_obj_t *st_mest;
    lv_obj_t *gumba;
    lv_obj_t *vn_gumb;
    lv_obj_t *not_gumb;
    lv_obj_t *text_iz_weba;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 3,
    SCREEN_ID_NASTAVITVE = 2,
    SCREEN_ID_GARAZA = 1,
};

void create_screen_main();
void tick_screen_main();

void create_screen_nastavitve();
void tick_screen_nastavitve();

void create_screen_garaza();
void tick_screen_garaza();

void increment_stevilo_mest_cb(lv_event_t *e);
void decrement_stevilo_mest_cb(lv_event_t *e);

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/
#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#elif defined(LV_BUILD_TEST)
#include "../lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_GRE_NOT
#define LV_ATTRIBUTE_IMG_GRE_NOT
#endif

static const
LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_GRE_NOT
uint8_t img_gre_not_map[] = {

    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x07,0x80,0x00,0x00,
    0x00,0x00,0x0f,0xc0,0x00,0x00,
    0x00,0x00,0x1f,0xe0,0x00,0x00,
    0x00,0x00,0x7f,0xf8,0x00,0x00,
    0x00,0x00,0xff,0xfc,0x00,0x00,
    0x00,0x01,0xff,0xfe,0x00,0x00,
    0x00,0x07,0xff,0xff,0x80,0x00,
    0x00,0x0f,0xff,0xff,0xc0,0x00,
    0x00,0x0f,0xff,0xff,0xc0,0x00,
    0x00,0x0f,0xff,0xff,0xc0,0x00,
    0x00,0x07,0x00,0x03,0x80,0x00,
    0x00,0x01,0x3f,0xfa,0x00,0x00,
    0x00,0x01,0x3c,0xfa,0x00,0x00,
    0x00,0x01,0x38,0x7a,0x00,0x00,
    0x00,0x01,0x03,0x02,0x00,0x00,
    0x00,0x01,0x27,0x9a,0x00,0x00,
    0x00,0x01,0x2f,0xda,0x00,0x00,
    0x00,0x01,0x07,0x82,0x00,0x00,
    0x00,0x01,0x27,0x9a,0x00,0x00,
    0x00,0x01,0x37,0xba,0x00,0x00,
    0x00,0x01,0x37,0xba,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,

};

const lv_image_dsc_t img_gre_not = {
  .header.magic = LV_IMAGE_HEADER_MAGIC,
  .header.cf = LV_COLOR_FORMAT_A1,
  .header.flags = 0,
  .header.w = 46,
  .header.h = 46,
  .header.stride = 6,
  .data_size = sizeof(img_gre_not_map),
  .data = img_gre_not_map,
};


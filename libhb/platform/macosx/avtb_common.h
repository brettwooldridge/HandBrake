/**********************************************************************************
 * Copyright (c) 2015, 2016 Brett Wooldridge
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and/or associated documentation files (the
 * "Materials"), to deal in the Materials without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Materials, and to
 * permit persons to whom the Materials are furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Materials.
 *
 * THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
 **********************************************************************************/

 #ifndef HB_AVTB_COMMON_H
 #define HB_AVTB_COMMON_H

 /* Apple VideoToolbox utilities */
 int            hb_avtb_available();
 int            hb_avtb_video_encoder_is_enabled(int encoder);

 static const char* const hb_avtb_preset_names1[] = { "speed", "balanced", "quality", NULL, };
 const char* const* hb_avtb_preset_get_names();
 const char* const* hb_avtb_profile_get_names(int encoder);

 const char* hb_avtb_video_quality_get_name(uint32_t codec);
 void hb_avtb_video_quality_get_limits(uint32_t codec, float *low, float *high, float *granularity, int *direction);

 const char* hb_avtb_codec_name    (uint32_t codec_id);
 const char* hb_avtb_profile_name  (uint32_t codec_id, uint16_t profile_id);
 const char* hb_avtb_level_name    (uint32_t codec_id, uint16_t level_id);

 #endif

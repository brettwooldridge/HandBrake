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

#ifdef USE_AVTB

#include "hb.h"
#include "common.h"
#include "avtb_common.h"
#include "h264_common.h"

int hb_avtb_available()
{
    // return ((hb_qsv_video_encoder_is_enabled(HB_VCODEC_QSV_H264) ? HB_VCODEC_QSV_H264 : 0) |
    //        (hb_qsv_video_encoder_is_enabled(HB_VCODEC_QSV_H265) ? HB_VCODEC_QSV_H265 : 0));
    return HB_VCODEC_AVTB_H264;
}

int hb_avtb_video_encoder_is_enabled(int encoder)
{
    switch (encoder)
    {
        case HB_VCODEC_AVTB_H264:
            return 1; // hb_qsv_info_avc != NULL && hb_qsv_info_avc->available;
        default:
            return 0;
    }
}

const char* const* hb_avtb_preset_get_names()
{
    return hb_avtb_preset_names;
}

const char* const* hb_avtb_profile_get_names(int encoder)
{
    switch (encoder)
    {
        case HB_VCODEC_AVTB_H264:
            return hb_h264_profile_names_8bit;
        default:
            return NULL;
    }
}

const char* const* hb_avtb_level_get_names(int encoder)
{
    switch (encoder)
    {
        case HB_VCODEC_AVTB_H264:
            return hb_h264_level_names;
        default:
            return NULL;
    }
}

const char* hb_avtb_video_quality_get_name(uint32_t codec)
{
    uint64_t caps = 0;
    switch (codec)
    {
        case HB_VCODEC_AVTB_H264:
            // if (hb_qsv_info_avc != NULL) caps = hb_qsv_info_avc->capabilities;
            break;
        default:
            break;
    }
    return (caps & HB_QSV_CAP_RATECONTROL_ICQ) ? "ICQ" : "QP";
}

void hb_avtb_video_quality_get_limits(uint32_t codec, float *low, float *high,
                                     float *granularity, int *direction)
{
    *direction   = 1;
    *granularity = 1.;
    *low         = 1.;
    *high        = 51.;
}

#endif

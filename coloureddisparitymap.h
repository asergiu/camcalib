/*

  dupa MARTIN PERIS
  Copyright (c) 2011 Martin Peris (http://www.martinperis.com).
  All right reserved.

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

*/
#ifndef COLOUREDDISPARITYMAP_H
#define COLOUREDDISPARITYMAP_H

#include"opencv_headers.h"


class ColouredDisparityMap
{

public:

    //Define the RGB channels following OpenCV's BGR distribution

    const int G2CD_BLUE_CHANNEL;
    const int G2CD_GREEN_CHANNEL;
    const int G2CD_RED_CHANNEL;

    typedef struct
    {
        unsigned char lookup_table[3][255]; //All posible values with IPL_DEPTH_8 and 3 channels
    }g2cd_data_t;

    typedef struct
    {
        float period[3];// 3 period values: Red, Green and blue
        float frequency[3];// 3 frequency values: Red, Green and blue

        unsigned char lookup_table[3][255]; //All posible values with IPL_DEPTH_8 and 3 channels
    }g2pc_data_t;

    ColouredDisparityMap();

    int g2pc_calculate_look_up_table ( g2pc_data_t *data);
    int g2pc_gray_to_pseudocolor ( IplImage *gray, IplImage *pseudocolor, g2pc_data_t *data);

    void g2cd_gray_to_rgb ( float gray, float *red, float *green, float *blue);
    int g2cd_calculate_look_up_table ( g2cd_data_t *data);
    int g2cd_gray_to_chromadepth ( IplImage *gray, IplImage *chromadepth, g2cd_data_t *data);

};

#endif // COLOUREDDISPARITYMAP_H

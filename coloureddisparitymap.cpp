
#include "coloureddisparitymap.h"
#include <stdio.h>



ColouredDisparityMap::ColouredDisparityMap(): G2CD_BLUE_CHANNEL(0), G2CD_GREEN_CHANNEL(1), G2CD_RED_CHANNEL(2)
{

}

/*
        This function receives a gray value (between 0 and 1) and returns
        the corresponding chroma depth rgb values (between 0 and 1)

*/
void ColouredDisparityMap::g2cd_gray_to_rgb ( float gray, float *red, float *green, float *blue)
{
    float gr = 1.0 - gray;
    float r = 1.0;
    float g = 0.0;
    float b = 1.0 - 6.0 * ( gr - (5.0/6.0) );

    if ( gr <= (5.0/6.0) )
    {
        r = 6.0 * ( gr - (4.0/6.0) );
        g = 0.0;
        b = 1.0;
    }

    if ( gr <= (4.0/6.0) )
    {
        r = 0.0;
        g = 1.0 - 6.0 * ( gr - (3.0/6.0) );
        b = 1.0;
    }

    if ( gr <= (3.0/6.0) )
    {
        r = 0.0;
        g = 1.0;
        b = 6.0 * ( gr - (2.0/6.0) );
    }

    if ( gr <= (2.0/6.0) )
    {
        r = 1.0 - 6.0 * ( gr - (1.0/6.0) );
        g = 1.0;
        b = 0.0;
    }

    if ( gr <= (1.0/6.0) )
    {
        r = 1.0;
        g = 6.0 * gr;

    }

    *red   = r;
    *green = g;
    *blue  = b;

}


/*
        This function precalculates all the possible values for R,G,B.
*/
int ColouredDisparityMap::g2cd_calculate_look_up_table ( g2cd_data_t *data)
{
    int i;
    float value;
    //For safety check the pointer
    if ( data == NULL) return 0;
    float r, g, b;


    //Pre-calculate all the possible values for R,G,B given the current frequency and period
    //Asume IPL_DEPTH_8U and 3 channels
    for ( i = 0; i < 255; i++)
    {

        value = (float)i/255.0;
        g2cd_gray_to_rgb ( value, &r, &g, &b );
        data->lookup_table[G2CD_RED_CHANNEL][i] = (unsigned char)(255.0 * r );
        data->lookup_table[G2CD_GREEN_CHANNEL][i] = (unsigned char)(255.0 * g );
        data->lookup_table[G2CD_BLUE_CHANNEL][i] = (unsigned char)(255.0 * b );
    }


    return 1;
}


/*
        This function returns a pseudo-color image given a gray image and the precalculated lookup table.
*/
int ColouredDisparityMap::g2cd_gray_to_chromadepth ( IplImage *gray, IplImage *chromadepth, g2cd_data_t *data)
{
    int x,y, x3;
    uchar *gray_ptr;
    uchar *chromadepth_ptr;
    int value;

    //Check all the pointers for safety
    if (gray == NULL)
    {
        fprintf(stderr, "ERROR: g2cd_gray_to_chromadepth: gray image is null\n");
        return 0;
    }
    if (chromadepth == NULL)
    {
        fprintf(stderr, "ERROR: g2cd_gray_to_chromadepth: chromadepth image is null\n");
        return 0;
    }
    if (data == NULL)
    {
        fprintf(stderr, "ERROR: g2cd_gray_to_chromadepth: lookup table data is null\n");
        return 0;
    }

    //Check that the gray image is IPL_DEPTH_8U and 1 channel
    if (gray->depth != IPL_DEPTH_8U || gray->nChannels != 1)
    {
        fprintf(stderr, "ERROR: g2cd_gray_to_chromadepth: gray image should be IPL_DEPTH_8U and 1 channel\n");
        return 0;
    }

    //Check that the chromadepth image is IPL_DEPTH_8U and 2 channel
    if (chromadepth->depth != IPL_DEPTH_8U || chromadepth->nChannels != 3)
    {
        fprintf(stderr, "ERROR: g2cd_gray_to_chromadepth: chromadepth image should be IPL_DEPTH_8U and 3 channel\n");
        return 0;
    }

    //Check that gray and chromadepth images have same dimensions
    if (gray->width != chromadepth->width || gray->height != chromadepth->height)
    {
        fprintf(stderr, "ERROR: g2cd_gray_to_chromadepth: gray and chromadepth images should have the same dimensions\n");
        return 0;
    }

    for ( y = 0; y < gray->height; y++)
    {
        gray_ptr = (uchar *)(gray->imageData + y*gray->widthStep);
        chromadepth_ptr = (uchar *)(chromadepth->imageData + y*chromadepth->widthStep);
        for ( x = 0; x < gray->width; x++)
        {
            x3 = 3*x; //lets save 2 multiplications on each loop
            value = (int)gray_ptr[x];//Gray value

            /*Blue channel*/
            chromadepth_ptr[x3] = data->lookup_table[G2CD_BLUE_CHANNEL][value];
            /*Green channel*/
            chromadepth_ptr[x3 + 1] = data->lookup_table[G2CD_GREEN_CHANNEL][value];
            /*Red channel*/
            chromadepth_ptr[x3 + 2] = data->lookup_table[G2CD_RED_CHANNEL][value];
        }
    }

    return 1;
}




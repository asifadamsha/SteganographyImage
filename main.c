#include "qdbmp.h"
#include <stdio.h>
#include <stdlib.h>

void writeStingOnBitmap(BMP *bitmapImage, UINT width, UINT height, const char *msgToWrite) {

    UCHAR r, g, b;

    for (UINT x = 0; x < width; ++x) {
        for (UINT y = 0; y < height; ++y) {

            BMP_GetPixelRGB(bitmapImage, x, y, &r, &g, &b);

            printf("R: %d, G: %d, B: %d \n", r, g, b);

            //BMP_SetPixelRGB(bitmapImage, x, y, 255 - r, 255 - g, 255 - b);
        }
    }

}


int main() {

    char bmpOrginalImageFilePath[] = "..\\img\\tiger.bmp";
    char bmpEditedImageFilePath[] = "..\\img\\tiger_edited.bmp";
    BMP *bitmapImage;

    bitmapImage = BMP_ReadFile(bmpOrginalImageFilePath);
    BMP_CHECK_ERROR(stderr, -1);

    UINT width = BMP_GetWidth(bitmapImage);
    UINT height = BMP_GetHeight(bitmapImage);

    printf("Image - Dimension : %lu * %lu", width, height);

    //writeStingOnBitmap(bitmapImage, width, height, "");


    /*BMP_WriteFile(bitmapImage, bmpEditedImageFilePath);
    BMP_CHECK_ERROR(stderr, -2);*/

    /* Free all memory allocated for the image */
    BMP_Free(bitmapImage);

    return 0;
}


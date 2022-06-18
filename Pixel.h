//
// Created by Grace Erickson on 12/6/21.
//

#ifndef STENOAGRAPHYFINALBITMAP_PIXEL_H
#define STENOAGRAPHYFINALBITMAP_PIXEL_H
#include "bitmap_defs.h"


class Pixel {
public:
    Pixel(BYTE red = 0, BYTE green = 0, BYTE blue = 0);

    BYTE getRed();
    BYTE getGreen();
    BYTE getBlue();

    void setRed(BYTE value);
    void setGreen(BYTE value);
    void setBlue(BYTE value);

private:
    BYTE red;
    BYTE green;
    BYTE blue;
};



#endif //STENOAGRAPHYFINALBITMAP_PIXEL_H

//
// Created by Grace Erickson on 12/6/21.
//

#ifndef STENOAGRAPHYFINALBITMAP_PIXELARRAY_H
#define STENOAGRAPHYFINALBITMAP_PIXELARRAY_H
#include <string>       // for file type property
#include "BMReader.h"   // bitmap file reader
#include "BMWriter.h"   // bitmap file writer
#include "Pixel.h"      // Pixel class


class PixelArray {
public:
    // constructors
    // ----------------------------------------------------
    PixelArray(int width=0, int height=0, int depth=0);
    ~PixelArray();


    // accessors/mutators (getters/setters)
    // ----------------------------------------------------
    int getWidth();
    int getHeight();
    int getDepth();

    void setWidth(int value);
    void setHeight(int value);
    void setDepth(int value);

    Pixel** getPixels();

    // member methods
    // ----------------------------------------------------
    int load(BMReader* reader);
    int store(BMWriter* writer);

    std::string toString();


protected:
    int width;      // width of image in pixels
    int height;     // number of rows of pixels
    int depth;      // bit-depth (bytes per pixel)

    Pixel **pixels;

    int calcPadding();  // calculate number of padding bytes per row
};



#endif //STENOAGRAPHYFINALBITMAP_PIXELARRAY_H

//
// Created by Grace Erickson on 12/6/21.
//

#ifndef STENOAGRAPHYFINALBITMAP_BMINFOHEADER_H
#define STENOAGRAPHYFINALBITMAP_BMINFOHEADER_H
#include "BMCoreHeader.h"


class BMInfoHeader : public BMCoreHeader {
    public:
        // constructors
        // ----------------------------------------------------
        BMInfoHeader();

        // accessors/mutators (getters/setters)
        // properties are readonly and can only be modified
        // through the load method
        // ----------------------------------------------------
        int getCompression();
        int getImageSize();
        int getHorizontal();
        int getVertical();
        int getColorPalette();
        int getImportantColors();

        // member methods
        // ----------------------------------------------------
        int load(BMReader* reader);
        int store(BMWriter* writer);

        std::string toString();

    private:
        DWORD compression;      // compression method (i.e. BI_RGB=0)
        DWORD imageSize;        // size of raw bitmap
        DWORD horizontal;       // resolution pixel per metre
        DWORD vertical;         // resolution pixel per metre
        DWORD colorPalette;     // number of colors in palette
        DWORD importantColors;  // number of important colors
    };







#endif //STENOAGRAPHYFINALBITMAP_BMINFOHEADER_H

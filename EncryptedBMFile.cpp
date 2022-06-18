//
// Created by Grace Erickson on 12/7/21.
//

#include "EncryptedBMFile.h"
EncryptedBMFile::EncryptedBMFile(std::ifstream* reader, std::ofstream* writer){
    this->reader = BMReader(reader);
    this->writer = BMWriter(writer);
}


//a method that sets my attribute equals to daddy class
void EncryptedBMFile :: sendToDad(BMFile Daddy){
    this->fileHeader=Daddy.getFileHeader();
    this->infoHeader=Daddy.getInfoHeader();
    this->pixels=Daddy.getPixelArray();
}


int EncryptedBMFile::encrypt(std::string message) {
    int bytes;

    int row = 0, column = 0;
    for (int next = 0; next < message.length(); next++) {
        char nextChar = message[next];

        for (int bit = 0; bit < 8; bit++) {
            char mask = 1;
            mask=mask<<bit;
            Pixel pixel = pixels.getPixels()[row][column];

            BYTE blue = pixel.getBlue();

            if (mask & nextChar) {
                blue |= 1;
            } else {
                blue &= 0xFE;
            }

            pixel.setBlue(blue);
        }

        column++;
        if (column == infoHeader.getWidth()) {
            row++;
            column = 0;
        }
        bytes++;
    }

    return bytes;

}

std::string EncryptedBMFile::decrypt(BMFile name){
    int row = 0, column = 0;
    char nextChar;

// until we hit the null terminator
    do {
        nextChar=0;
        for (int i = 7; i > -1; i--) {
            Pixel pixel = pixels.getPixels()[row][column];

            //or the result of {Blue & 1 (isolate bit-0) shifted i times to the left}
            BYTE blue = pixel.getBlue();
            nextChar |= ((blue & 1) << i);

            // get next pixel
            column++;
            //if we have reached the end of the row, go to the next row
            if (column == infoHeader.getWidth()) {
                column = 0;
                row++;
            }

        }

        secretMessage += nextChar;

    } while (nextChar!='null');

}

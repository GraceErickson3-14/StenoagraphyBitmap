//
// Created by Grace Erickson on 12/6/21.
//

#ifndef STENOAGRAPHYFINALBITMAP_BMREADER_H
#define STENOAGRAPHYFINALBITMAP_BMREADER_H

#include "bitmap_defs.h"
#include <iostream>
class BMReader {
public:
    // default parameter to null so this can be a default constructor as well
    BMReader(std::ifstream* reader = nullptr);

    // not creating a dynamic ifstream so no need for a destructor

    // no need for accessors as users of this class should call the member methods below to read data

    // mutator so we can late-bind the filestream if not available at creation time
    void setReader(std::ifstream* reader);

    // member methods
    // ----------------------------------------------------
    int readByte(BYTE &field);
    int readWord(WORD &field);
    int readDWord(DWORD &field);

    // provide status of reader (calls internal ifstream.is_open)
    bool isOpen();

private:
    std::ifstream* reader;

    // private method used by the read member methods
    int readBytes(char* field, int size);
};




#endif //STENOAGRAPHYFINALBITMAP_BMREADER_H

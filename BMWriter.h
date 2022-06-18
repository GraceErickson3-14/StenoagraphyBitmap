//
// Created by Grace Erickson on 12/6/21.
//

#ifndef STENOAGRAPHYFINALBITMAP_BMWRITER_H
#define STENOAGRAPHYFINALBITMAP_BMWRITER_H

#include <fstream>          // file input/output streams
#include "bitmap_defs.h"    // application defines

class BMWriter {
public:
    // default parameter to null so this can be a default constructor as well
    BMWriter(std::ofstream* writer = nullptr);

    // not creating a dynamic ifstream so no need for a destructor

    // no need for accessors as users of this class should call the member methods below to write data

    // mutator so we can late-bind the filestream if not available at creation time
    void setWriter(std::ofstream* writer);

    // member methods
    // ----------------------------------------------------
    int writeByte(BYTE &field);
    int writeWord(WORD &field);
    int writeDWord(DWORD &field);

    // provide status of writer (calls internal ifstream.is_open)
    bool isOpen();

    // save the file after writing to it
    void save();

private:
    std::ofstream* writer;

    // private method used by the writer member methods
    int writeBytes(char* field, int size);
};



#endif //STENOAGRAPHYFINALBITMAP_BMWRITER_H

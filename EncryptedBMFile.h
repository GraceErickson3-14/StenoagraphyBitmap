//
// Created by Grace Erickson on 12/7/21.
//

#ifndef STENOAGRAPHYFINALBITMAP_ENCRYPTEDBMFILE_H
#define STENOAGRAPHYFINALBITMAP_ENCRYPTEDBMFILE_H
#include "BMFile.h"
#include <string>
#include "PixelArray.h"
class EncryptedBMFile : public BMFile {

public:
    EncryptedBMFile(std::ifstream* reader = nullptr, std::ofstream* writer = nullptr);


    int encrypt(std::string message);

    void sendToDad(BMFile Daddy);

    std::string decrypt(BMFile name);

private:
    std::string secretMessage;

};


#endif //STENOAGRAPHYFINALBITMAP_ENCRYPTEDBMFILE_H

// --------------------------------------------------------
//    File: bitmap.cpp
//  Author: COP 3003 Programming II
// Purpose: main application file for bitmap program that
//  currently opens a bitmap and copies it to an output file
// --------------------------------------------------------
#include <iostream>
#include "EncryptedBMFile.h"
#include "BMFile.h"     // bitmap file class

int main() {
    int answer;
    std::cout << "\n Type 1 to encrypt a message; Type 2 to decrypt";
    std::cin >> answer;

    if (answer == 1) {
        std::string inFileName, outFileName;

        std::cout << "\nEnter bitmap file name to read: ";
        std::cin >> inFileName;  //file to encrypt or decrypt

        std::cout << "\nEnter bitmap file name to write: ";
        std::cin >> outFileName; //file to write encryption to

        std::string msg;
        std::cout << "Enter string to encrypt: ";
        std::cin >> msg;
        std::getline(std::cin, msg);


        // make sure the file names were entered
        if (inFileName.length() && outFileName.length()) {

            std::ifstream inFile;
            inFile.open(inFileName, std::ios::binary);

            std::ofstream outFile;
            outFile.open(outFileName, std::ios::out | std::ios::trunc | std::ios::binary);

            //encrypt
            if (inFile.is_open() && outFile.is_open()) {
                BMFile bmFile = BMFile(&inFile, &outFile);
                EncryptedBMFile encryptedbmFile = EncryptedBMFile(&inFile, &outFile);

                int bytes = bmFile.load();

                encryptedbmFile.sendToDad(bmFile);

                bytes +=encryptedbmFile.encrypt(msg);


                std::cout << "Loaded Bitmap \"" << inFileName << "\" (" << std::to_string(bytes) << " bytes)\n";
                std::cout << bmFile.toString();
                bytes = encryptedbmFile.store();

                std::cout << "\n\nStored to Bitmap \"" << outFileName << "\" (" << std::to_string(bytes) << " bytes)\n";

            } else {
                std::cout << "Could not open input file: " << inFileName << std::endl;
            }


        } // filename lengths > 0
        else {
            std::cout << "File names must be > 0 length!\n";
        }

        return 0;
    }else{
        std::string inFileName;

        std::cout << "\nEnter bitmap file name to read: ";
        std::cin >> inFileName;  //file to decrypt

        // make sure the file name was entered
        if (inFileName.length()) {

            std::ifstream inFile;
            inFile.open(inFileName, std::ios::binary);

            //encrypt
            if (inFile.is_open()) {
                BMFile bmFile = BMFile(&inFile);
                EncryptedBMFile encryptedbmFile = EncryptedBMFile(&inFile);

                int bytes = bmFile.load();

                encryptedbmFile.sendToDad(bmFile);


                encryptedbmFile.decrypt(bmFile);

                std::cout << "Loaded Bitmap \"" << inFileName << "\" (" << std::to_string(bytes) << " bytes)\n";


            }
            else {
                std::cout << "Could not open input file: " << inFileName << std::endl;
            }


        } // filename lengths > 0
        else {
            std::cout << "File names must be > 0 length!\n";
        }

        return 0;
    }

    }


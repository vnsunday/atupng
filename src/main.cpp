#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int i, j;

    if (argc < 2) {
        printf("Usage: main pngfile\r\n");
        return 0;
    }


    size_t nLength;
    const char* szFile = argv[1];
    const int N_SIGNATURE = 8;
    unsigned char szBuffer[1000];
    unsigned char azPNGSIGN[N_SIGNATURE] {  0x89,  0x50,  0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a };

    std::ifstream f1;

    f1.open(szFile, std::ios::in | std::ios::binary);

    

    if (!f1.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    } 
    else {
        printf("Reading Success\r\n");
    }
    
    if (f1.read(reinterpret_cast<char*>(szBuffer), N_SIGNATURE)) {
        printf("Success Read \r\n");

        for (int i=0; i<N_SIGNATURE; ++i) {
            if (szBuffer[i] != azPNGSIGN[i]) {
                printf("SIgnature Mismatch: %#x != %#x (Expected)\r\n", szBuffer[i], azPNGSIGN[i]);
            } 
            else {
                printf("Signature[%d] Matched: %#x = %#x (Expected)\r\n", i, szBuffer[i], azPNGSIGN[i]);
            }
        }
    } else {
        printf("Failed Reading\r\n");
    }

    f1.close();
    return 0;
}
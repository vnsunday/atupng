#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

#define PALETTE_ENTRY 255
// Global Variables 
short alpha; /* degree of opacity */
short alpha_compaction;
unsigned char alpha_separation;
unsigned char alpha_table[PALETTE_ENTRY];
/* */
unsigned char bit_depth; /* 32 */
unsigned char channel[5];
/* */


int read_next_chunk(std::ifstream& file) {
    /*============================================================
     * Chunk Fields
     *      [Length(size=4)]
     *      [ChunkType(size=4)]
     *      [ChunkData()]
     *      [CRC(size=4)]
     *============================================================*/
    unsigned int unLength;
    unsigned char chType[4];
    unsigned char* pData;
    unsigned char CRC[4];

    file.read(reinterpret_cast<char*>(&unLength), 4);
    file.read(reinterpret_cast<char*>(chType), 4);

    if (unLength > 0) {
        pData = (unsigned char*)malloc(unLength);

        if (pData) {
            file.read(reinterpret_cast<char*>(pData), unLength);
        }
    }

    file.read(reinterpret_cast<char*>(CRC), 4);
    return 0;
}

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
    unsigned char azPNGSIGN[N_SIGNATURE] { 0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a };

    bool bSignature = false;
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
                bSignature = true;
            }
        }
    } else {
        printf("Failed Reading\r\n");
    }

    if (bSignature) {
        // Process Chunks here
    }

    f1.close();

    return 0;
}
#ifndef ATUPGN_GLOBALS_H_
#define ATUPGN_GLOBALS_H_

#include <string>


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
unsigned char CIE_x;
unsigned char CIE_x; 

unsigned char colour_type; /* 0, 2, 3, 4, 6 */

unsigned char filter;
unsigned char frame_buffer;

unsigned char alpha_table;

/* Actions */
std::string azAction[] {
	"composite",
	"indexing", /* for color */
	"extraction", 
	"pass",
	"compress",
	"deflate",
	"encoding",
	"decoding", 
	"merging"
};

/* Actions */
unsigned char deflate;
unsigned char transformation; /* filter */
unsigned char gamma; /* */

unsigned char greyscale;
unsigned char palette;
unsigned char luminance;

/* */
unsigned char byte_order; /* MSB - LSB */
unsigned char channels; /* MSB - LSB */
unsigned char data_stream; 

unsigned char editor; 
unsigned char encoder;
unsigned char decoder;

unsigned char reference_image; /**/
unsigned char white_point;

/*=====  =====*/



#endif
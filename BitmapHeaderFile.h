#pragma once

// Lets the program include the header only once

#ifndef BitmapHeaderFile_H_
#define BitmapHeaderFile_H_

#pragma pack(2)
// Stores the structure as it is without any padding

struct BitmapHeaderFile {
	char bfType[2]{ 'B','M' };
	int32_t bfSize;
	int32_t bfReserved{0};
	int32_t bfOffset;

};




#endif

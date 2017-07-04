#pragma once
#ifndef BitmapHeaderInfoFile_H_
#define BitmapHeaderInfoFile_H_

# include <cstdint>
struct BitmapHeaderInfoFile {
	int32_t biSize = 40 ;		  //Header Size
	int32_t biWidth;			 //Image width
	int32_t biHeight;			 //Image height
	int16_t biplanes = 1 ;			 // Image planes in bitmap its one
	int16_t biBitCount= 24;		     // bits per pixel 
	int32_t biCompression= 0 ;  
	int32_t biSizeImage= 0 ;
	int32_t biXPelMeter= 2400;
	int32_t biYPelMeter= 2400;
	int32_t biClrUsed=0;
	int32_t biClrImportant=0;



};






#endif
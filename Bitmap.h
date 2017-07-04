#pragma once

 # include <cstdint>
# include "BitmapHeaderFile.h"
# include "BitmapHeaderInfoFile.h"
# include <string>
# include <memory>
# include <fstream>

using namespace std;


class Bitmap
{
private:
	int width;
	int height;
	unique_ptr<uint8_t[]> mPixels {nullptr};
	uint8_t* ptr =NULL;





public:

	Bitmap(int w, int h) :width(w), height(h), mPixels(new uint8_t[width * height * 3]{ }) { }

	bool writeBitmapfile(string filename)
	{
		BitmapHeaderFile file;
		BitmapHeaderInfoFile fileheader;

		fileheader.biWidth = width;
		fileheader.biHeight = height;
		file.bfOffset = sizeof(BitmapHeaderFile) + sizeof(BitmapHeaderInfoFile);
		file.bfSize = (width *height*3 )+ sizeof(BitmapHeaderFile) +sizeof(BitmapHeaderInfoFile);

		ofstream outputFile;
		outputFile.open(filename,ios::out,ios::binary);
		if (!outputFile) 
		{
			return false;
		}

		outputFile.write((char *)&file, sizeof(BitmapHeaderFile));
		outputFile.write((char *)&fileheader, sizeof(BitmapHeaderInfoFile));
		outputFile.write((char *)mPixels.get(), width*height*3);

		outputFile.close();

		if (!outputFile)
		{
			return false;
		}
		return true;
	}

	void SetPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
	{
		uint8_t *ptr = mPixels.get();
		ptr += (y * 3 * width) + x*3;
		ptr[0] = blue;
		ptr[1] = green;
		ptr[2] = red;

			
	}

	virtual ~Bitmap()
	{
	}
};


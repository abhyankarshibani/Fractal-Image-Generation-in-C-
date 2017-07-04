/*This codes generates fractal Images using c++
Author: Shibani Abhyankar
Date: 4/7/2017
*/

# include <iostream>
# include "BitmapHeaderFile.h"
# include "BitmapHeaderInfoFile.h"
# include "Bitmap.h";
using namespace std;


int main()
{
	Bitmap Bitimage(300, 300);
	Bitimage.writeBitmapfile("Image.bmp");
	cout << "Hello World";
	int pause = 0;
	cin >> pause;
	return 0;
}
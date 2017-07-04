/*This codes generates fractal Images using c++
Author: Shibani Abhyankar
Date: 4/7/2017
*/

# include <iostream>
# include "BitmapHeaderFile.h"
# include "BitmapHeaderInfoFile.h"
# include "Bitmap.h"

using namespace std;


int main()

{
	int W, H;
	W = 100;
	H = 100;
	double minlimit = 9999999;
	double maxlimit = -9999999;
	Bitmap Bitimage(W, H);


	for(int k=0;k<W;k++)
	{
		for (int k1 = 0; k1 < H; k1++)
		{
			double xfractal = (k/(W/2.0))-1;
			double yfractal = (k1 /(H/2.0) ) - 1;
			if (xfractal < minlimit)
			{
				minlimit = xfractal;

			}
			if (xfractal > maxlimit)
			{
				maxlimit= xfractal;

			}

			//Bitimage.SetPixel(k, k1, 255, 255, 255);
		}
	}
	//Bitimage.SetPixel(50, 50, 255, 255, 255);
	cout << minlimit << endl << maxlimit;
	
	Bitimage.writeBitmapfile("ImageTest.bmp");
	cout << "Finished";
	int pause;
	cin >> pause;
	return 0;
}
/*This codes generates fractal Images using c++
Author: Shibani Abhyankar
Date: 4/7/2017
*/

# include <iostream>
# include <cstdint>
# include <math.h>
# include "BitmapHeaderFile.h"
# include "BitmapHeaderInfoFile.h"
# include "Bitmap.h"
# include "Mandelbrot.h"

using namespace std;


int main()

{
	int W, H;
	W = 500;
	H = 500;
	double minlimit = 9999999;
	double maxlimit = -9999999;
	Bitmap Bitimage(W, H);
	Mandelbrot M1;
	unique_ptr<int[]> color_histogram(new int[M1.maximum_iterations]{0});
	unique_ptr<int[]>fractalimage(new int[W*H]{ 0 });

	for (int k = 0; k < W; k++)
	{
		for (int k1 = 0; k1 < H; k1++)
		{
			double xfractal = (k / (W / 2.0)) - 1;
			double yfractal = (k1 / (H / 2.0)) - 1;
			int iterate = M1.Iterationsget(xfractal, yfractal);
			//uint8_t color =(uint8_t)(256* double(iterate) / M1.maximum_iterations);
			//color = color*color*color*15;
			if (iterate != M1.maximum_iterations)
			{
				color_histogram[iterate]++;
			}
			fractalimage[k1*W + k] = iterate;

		}
	}
	int total_iterations_image=0;
	for (int idx = 0; idx < M1.maximum_iterations; idx++)
	{
		total_iterations_image = total_iterations_image + color_histogram[idx];
		
		}
			
			for (int kk = 0; kk < W; kk++)
			{
				for (int kk1 = 0; kk1 < H; kk1++)
				{
					//uint8_t color = (uint8_t)(256 * double(fractalimage[kk1*W + kk]) / M1.maximum_iterations);
					//color = color * 3 * color*color;
					uint8_t red = 0;
					uint8_t green = 0;
					uint8_t blue = 0;
					//cout << fractalimage[kk1*W + kk]<<endl;
					if (fractalimage[kk1*W + kk] != M1.maximum_iterations)
					{
					
					double hue = 0.0;
					for (int ii = 0; ii < fractalimage[kk1*W + kk]; ii++)
					{
						hue = hue + ((double)color_histogram[ii]) / total_iterations_image;
					}
					 red = 0;
					 green = pow(255, hue);
					 blue = 0;
				   }
		/*	if (color < minlimit)
			{
				minlimit = color;

			}
			if (color > maxlimit)
			{
				maxlimit = color;

			}*/

			Bitimage.SetPixel(kk, kk1, red,green,blue);
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

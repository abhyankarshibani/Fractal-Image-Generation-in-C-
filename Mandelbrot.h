#pragma once
# include<iostream>
# include<complex>
using namespace std;
class Mandelbrot
{
public:
	static const int maximum_iterations = 1000;

public:

	Mandelbrot()
	{
		

	}
	int Iterationsget(double x, double y)
	{
		int iterate = 0;
		complex<double>z = 0;
		complex<double>c(x, y);
		while (iterate < maximum_iterations)
		{
			z = z*z + c;
			if (abs(z) > 2)
			{
				break;
			}
			iterate++;
		}
		return iterate++;
	}

	~Mandelbrot()
	{
	}
};


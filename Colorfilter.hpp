#ifndef COLORFILTER_HPP
#define COLORFILTER_HPP

// Libraries
#include "Matrix.hpp"
#include "Pixel.hpp"
#include "Geometry.hpp"


// Creating class ColorFilter
class Colorfilter
{
    public:
	ColorUtilize colorUtilize;
	
	void Filter(Matrix& matrix, Matrix& matrix1,Pixel pixel, int range)
	{
	    for (int i = 0; i < CAMERAHEIGHT; ++i)
	    {
		for (int j = 0; j < CAMERAWIDTH; ++j)
		{
		    if (colorUtilize.GetColorDistance(matrix.Data[i][j],pixel) <= range)
		    {
			matrix1.Data[i][j].R = 255;
			matrix1.Data[i][j].G = 255;
			matrix1.Data[i][j].B = 255;
		    }
		    else
		    {
			matrix1.Data[i][j].R = 0;
			matrix1.Data[i][j].G = 0;
			matrix1.Data[i][j].B = 0;
		    }
		}
	    }
	}
};

#endif //Colorfilter.hpp

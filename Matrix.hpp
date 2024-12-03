#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "Constants.hpp"
#include "Pixel.hpp"

// Creating class matrix
class Matrix 
{
    public:
	int Height = 0;
	int Width = 0;

	Pixel Data[CAMERAHEIGHT][CAMERAWIDTH];

	Matrix()
	:Height(CAMERAHEIGHT)
	,Width(CAMERAWIDTH)
	{
	}

};
#endif // Matrix.hpp

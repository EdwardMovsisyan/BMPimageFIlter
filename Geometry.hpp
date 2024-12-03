
#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

// Libraries
#include <math.h>
#include "Pixel.hpp"



// Creating class ColorUtilize
class ColorUtilize
{
    public:
	
	double GetColorDistance(const Pixel& p1, const Pixel& p2)
	{
	    double distance = sqrt((p1.R - p2.R)*(p1.R - p2.R) +
				   (p1.G - p2.G)*(p1.G - p2.G) +
				   (p1.B - p2.B)*(p1.B - p2.B));
	    return distance;
	}
};
#endif //Geometry.hpp

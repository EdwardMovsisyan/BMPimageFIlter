
// Standart libraries
#include <iostream>

// Project libraries
#include "BMPImporter.hpp"
#include "BMPExporter.hpp"
#include "Matrix.hpp"
#include "Constants.hpp"
#include "Pixel.hpp"
#include "Colorfilter.hpp"
#include "Webcam.hpp"

int main()
{
    // Creating Webcam object 
    Webcam webcam("/dev/video0", CAMERAWIDTH, CAMERAHEIGHT);

    // Creating BMPImporter object 
    BMPImporter importer;

    // Creating BMPExporter object 
    BMPExporter exporter;

    // Creating Matrix object 
    Matrix matrix = webcam.Frame(1000000);
    Matrix matrix1; 

    // Creating Pixel object 
    Pixel pixel;

    // Creating ColorFilter object
    Colorfilter colorfilter;
    colorfilter.Filter(matrix,matrix1,pixel,Range);

    // Export
    exporter.Export(matrix,"Output/heee.bmp");
    exporter.Export(matrix1,"Output/tmp.bmp");

    return 0;
}


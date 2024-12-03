
#ifndef TOUROUBERAN_BMPIMPORTER
#define TOUROUBERAN_BMPIMPORTER

// Project libraries
#include "Pixel.hpp"
#include "Matrix.hpp"

// Standard libraries
#include <string>
#include <iostream>

class BMPImporter
{
private:

    // Init
    int X = 0;
    int Y = 0;

    // This function should put the values of RGB pixel into the matrix
    int bitmapin(FILE* fp, Matrix& matrix)
    {

	long n;
	int t = 0;

	for (int i = 0; i < 20; ++i)
	{
	    int k = 0;
	    fread(&k, 1, 1, fp);    // Full file size
	}

	fseek(fp, 2, SEEK_SET); // BM

	int t1 = 0;
	int t2 = 0;
	int t3 = 0;
	int t4 = 0;
	fread(&t1, 1, 1, fp);    // Full file size
	fread(&t2, 1, 1, fp);    // Full file size
	fread(&t3, 1, 1, fp);    // Full file size
	fread(&t4, 1, 1, fp);    // Full file size

	int size = (t4 << 24) + (t3 << 16) + (t2 << 8) + t1;

	fseek(fp, 10, SEEK_SET); // Header

	fread(&t, 1, 4, fp); // reads the offset and puts it in t - go and read the documentation, ok you are right

	// Don't touch this!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//t = 14;
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	fseek(fp, t, SEEK_SET);

	int e = ((4 - (X * 3)) % 4);

	for (int i=Y-1; i>=0; --i)
	{
	    for (int p=0; p<X; p++)
	    {
		int tmp = 0;

		n=fread(&tmp, 1, 1, fp);
		matrix.Data[i][p].B = tmp;
		if (n!=1)
		{
		    return 29;
		}

		n=fread(&tmp, 1, 1, fp);
		matrix.Data[i][p].G = tmp;
		if (n!=1)
		{
		    return 30;
		}

		n=fread(&tmp, 1, 1, fp);
		matrix.Data[i][p].R = tmp;
		if (n!=1)
		{
		    return 31;
		}
	    }

	    fseek(fp, e, SEEK_CUR);
	}

	return 0;
    }

public:

    // Import BMP into Matrix	
    void Import(const std::string& file, Matrix& matrix)
    {
	    // Set
	    X = matrix.Width;
	    Y = matrix.Height;

	    FILE* fp = fopen(file.c_str(), "r");
	    //FILE* fp = fopen("Output/h.bmp", "r");

	    if (fp == NULL) 
	    {
		    return;
	    }

	    bitmapin(fp, matrix); 
	    std::cout << "GOOD End == Happy End" << std::endl;
    }

};

#endif // TOUROUBERAN_BMPIMPORTER

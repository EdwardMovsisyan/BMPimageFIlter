main:
	g++ -std=c++11 \
	BMPImporter.hpp \
	BMPExporter.hpp \
	Matrix.hpp \
	Pixel.hpp \
	Point.hpp \
	Constants.hpp \
	Colorfilter.hpp \
	Geometry.hpp \
	Webcam.cpp \
	Main.cpp \
	-o test


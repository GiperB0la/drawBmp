#include "../include/drawBmp.h"


int main(int argc, char* argv[])
{
	std::string path = "..\\dev\\1.bmp";
	//std::string path = "..\\dev\\2.bmp";
	if (argc > 1)
		path = argv[1];

	drawBmp drawBmp;
	drawBmp.openBMP(path);
	drawBmp.displayBMP();

	return 0;
}
#include "../include/drawBmp.h"


drawBmp::~drawBmp()
{
	closeBMP();
}

void drawBmp::openBMP(const std::string& fileName)
{
	file.open(fileName, std::ios::binary);
	if (file.is_open()) {
		file.read(reinterpret_cast<char*>(&fileHeader), sizeof(fileHeader));
		file.read(reinterpret_cast<char*>(&imageHeader), sizeof(imageHeader));

		if (fileHeader.bfType == 0x4D42) {
			if (imageHeader.biBitCount == 24 || imageHeader.biBitCount == 32) {
				file.seekg(fileHeader.bfOffBits, std::ios::beg);
				size_t pixelArraySize = imageHeader.biWidth * imageHeader.biHeight * (imageHeader.biBitCount / 8);
				pixels.resize(pixelArraySize);
				file.read(reinterpret_cast<char*>(pixels.data()), pixelArraySize);
			}

			else {
				std::cerr << "File size error." << std::endl;
			}
		}

		else {
			std::cerr << "File format error." << std::endl;
		}
	}

	else {
		std::cerr << "File opening error." << std::endl;
	}
}

void drawBmp::displayBMP()
{
	int bytesPerPixel = imageHeader.biBitCount / 8;
	for (int y = imageHeader.biHeight - 1; y >= 0; --y) {
		for (int x = 0; x < imageHeader.biWidth; ++x) {
			int pixelIndex = (y * imageHeader.biWidth + x) * bytesPerPixel;
			uint8_t blue = pixels[pixelIndex];
			uint8_t green = pixels[pixelIndex + 1];
			uint8_t red = pixels[pixelIndex + 2];

			if (red == 0 && green == 0 && blue == 0) {
				std::cout << "#";
			}

			else if (red == 255 && green == 255 && blue == 255) {
				std::cout << " ";
			}

			else {
				std::cout << "RGB color error.";
			}
		}
		std::cout << std::endl;
	}
}

void drawBmp::closeBMP()
{
	file.close();
	pixels.clear();
}
#pragma once
#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <string>


class drawBmp
{
public:
	drawBmp() = default;
	~drawBmp();

private:
	BITMAPFILEHEADER fileHeader;
	BITMAPINFOHEADER imageHeader;
	std::vector<uint8_t> pixels;
	std::ifstream file;

public:
	void openBMP(const std::string& fileName);
	void displayBMP();

private:
	void closeBMP();
};
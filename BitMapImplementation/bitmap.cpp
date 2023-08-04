#include "bitmap.h"

#include <stdexcept>

Bitmap::Bitmap() = default;

Bitmap::Bitmap(int w, int h) : width{w}, height{h} 
{
	pixels.resize(width * height, Pixel(0,0,0));
}

int Bitmap::getWidth() const {
	return width;
}

void Bitmap::setWidth(int w) {
	width = w;
}

int Bitmap::getHeight() const {
	return height;
}

void Bitmap::setHeight(int h) {
	height = h;
}

Pixel Bitmap::getPixel(int x, int y) const {
	if (x < 0 || x >= width || y < 0 || y >= height) {
		throw std::out_of_range{"Indexes out of range"};
	}
	return pixels[width * y + x];
}

void Bitmap::setPixel(int x, int y, const Pixel& p) {
	if (x < 0 || x >= width || y < 0 || y >= height) {
		throw std::out_of_range{"Indexes out of range"};
	}
	pixels[width * y + x] = p;
}
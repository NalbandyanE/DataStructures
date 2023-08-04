#include "pixel.h"

Pixel::Pixel() = default;

Pixel::Pixel(int r, int g, int b) : red{r}, green{g}, blue{b}
{
}

void Pixel::setRed(int r) {
	red = r;
}

int Pixel::getRed() const {
	return red;
}

void Pixel::setGreen(int g) {
	green = g;
}

int Pixel::getGreen() const {
	return green;
}

void Pixel::setBlue(int b) {
	blue = b;
}

int Pixel::getBlue() const {
	return blue;
}
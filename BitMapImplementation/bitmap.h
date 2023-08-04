#ifndef BITMAP_H
#define BITMAP_H

#include "pixel.h"

#include <vector>

class Bitmap {
public:
	Bitmap();
	Bitmap(int, int);
	int getWidth() const;
	void setWidth(int);
	int getHeight() const;
	void setHeight(int);
	Pixel getPixel(int, int) const;
	void setPixel(int, int, const Pixel&);
private:
	int width;
	int height;
	std::vector<Pixel> pixels;
};

#endif // BITMAP_H
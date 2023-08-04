#ifndef PIXEL_H
#define PIXEL_H

class Pixel {
public:
	Pixel();
	Pixel(int, int, int);
	void setRed(int);
	int getRed() const;
	void setGreen(int);
	int getGreen() const;
	void setBlue(int);
	int getBlue() const;
private:
	int red;
	int green;
	int blue;
};

#endif // PIXEL_H
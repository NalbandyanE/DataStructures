#include <iostream>
#include "bitmap.h"

int main() {
    Bitmap bitmap(800, 600);
    Pixel redPixel(255, 0, 0);
    bitmap.setPixel(100, 200, redPixel);
    Pixel retrievedPixel = bitmap.getPixel(100, 200);
    std::cout << "Red: " << retrievedPixel.getRed() << std::endl;
    std::cout << "Green: " << retrievedPixel.getGreen() << std::endl;
    std::cout << "Blue: " << retrievedPixel.getBlue() << std::endl;

    return 0;
}

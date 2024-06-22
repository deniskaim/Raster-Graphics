#include "Pixel.h"

Pixel::Pixel() : Pixel(0, 0, 0)
{}
Pixel::Pixel(uint8_t red, uint8_t green, uint8_t blue)
	: red(red), green(green), blue(blue)
{}
uint8_t Pixel::getRed() const
{
	return red;
}
void Pixel::setRed(uint8_t newRed)
{
	red = newRed;
}

uint8_t Pixel::getGreen() const
{
	return green;
}
void Pixel::setGreen(uint8_t newGreen)
{
	green = newGreen;
}

uint8_t Pixel::getBlue() const
{
	return blue;
}
void Pixel::setBlue(uint8_t newBlue)
{
	blue = newBlue;
}

bool Pixel::operator==(const Pixel& other) const
{
	return red == other.red && green == other.green && blue == other.blue;
}
bool Pixel::operator!=(const Pixel& other) const
{
	return !(operator==(other));
}

std::ostream& operator<<(std::ostream& os, const Pixel& pixel)
{
	os << pixel.red << " " << pixel.green << " " << pixel.blue;
	return os;
}
std::istream& operator>>(std::istream& is, Pixel& pixel)
{
	is >> pixel.red >> pixel.green >> pixel.blue;
	return is;
}

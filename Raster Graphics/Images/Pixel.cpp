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
	os << static_cast<int32_t>(pixel.red) << " " << static_cast<int32_t>(pixel.green) << " " << static_cast<int32_t>(pixel.blue);
	return os;
}
std::istream& operator>>(std::istream& is, Pixel& pixel)
{

	int32_t red, green, blue;
	is >> red >> green >> blue;
	pixel.setRed(static_cast<int8_t>(red));
	pixel.setGreen(static_cast<int8_t>(green));
	pixel.setBlue(static_cast<int8_t>(blue));
	return is;
}

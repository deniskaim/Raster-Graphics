#pragma once
#include <iostream>
class Pixel
{
public:
	Pixel();
	Pixel(uint8_t red, uint8_t green, uint8_t blue);

	uint8_t getRed() const;
	void setRed(uint8_t newRed);

	uint8_t getGreen() const;
	void setGreen(uint8_t newGreen);

	uint8_t getBlue() const;
	void setBlue(uint8_t newBlue);
	
	bool operator==(const Pixel& other) const;
	bool operator!=(const Pixel& other) const;
	friend std::ostream& operator<<(std::ostream& os, const Pixel& pixel);
	friend std::istream& operator>>(std::istream& is, Pixel& pixel);

private:
	uint8_t red;
	uint8_t green;
	uint8_t blue;
};
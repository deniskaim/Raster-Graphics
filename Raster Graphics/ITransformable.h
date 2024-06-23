#pragma once

class ITransformable
{
public:
	virtual void applyGrayscale() = 0;
	virtual void applyMonochrome() = 0;
	virtual void applyNegative() = 0;
	virtual void rotateLeft() = 0;
	virtual void rotateRight() = 0;
	
	virtual ~ITransformable() = default;

protected:
	bool isGrayscale = false;
	bool isMonochrome = false;
};
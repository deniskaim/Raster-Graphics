#pragma once
#include "MyVector.hpp"
#include "Polymorphic_ptr.hpp"
#include "TransformableImage.h"

class ImageCollection : public MyVector<Polymorphic_ptr<TransformableImage>>
{
	
};
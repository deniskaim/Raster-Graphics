#pragma once
#include "MyVector.hpp"
#include "Polymorphic_ptr.h"
#include "TransformableImage.h"

class ImageCollection : public MyVector<Polymorphic_ptr<TransformableImage>>
{
	
};
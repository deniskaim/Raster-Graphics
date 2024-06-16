#pragma once
#include "MyVector.hpp"
#include "Polymorphic_ptr.h"
#include "TransformableImage.h"

class ImagesCollection : public MyVector<Polymorphic_ptr<TransformableImage>>
{
};
#pragma once
#include "MyVector.hpp"
#include "Polymorphic_ptr.h"
#include "Image.h"

class ImagesCollection : public MyVector<Polymorphic_ptr<Image>>
{
};
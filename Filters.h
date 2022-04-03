#pragma once

#include "image_processor.h"

class Filters {
public:
    virtual void Do(Image &my_image) = 0;
    virtual ~Filters() = default;
};
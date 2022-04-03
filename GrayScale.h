#pragma once

#include "Filters.h"

class GrayScale : public Filters {
public:
    void Do(Image &my_image) override;
};
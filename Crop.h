#pragma once

#include "Filters.h"

class Crop : public Filters {
private:
    size_t new_width;
    size_t new_height;
public:
    Crop(size_t width, size_t height);
    void Do(Image& my_image) override;
};
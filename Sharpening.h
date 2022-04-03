#pragma once

#include "Filters.h"

class Sharpening : public Filters{
public:
    void Do(Image &my_image) override;
};
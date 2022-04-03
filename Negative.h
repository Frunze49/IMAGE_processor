#pragma once

#include "Filters.h"

class Negative : public Filters {
public:
    void Do(Image &my_image) override;
};
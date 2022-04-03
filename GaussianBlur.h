#pragma once

#include "Filters.h"

class GaussianBlur : public Filters {
private:
    double sigma_;

public:
    GaussianBlur(double sigma);
    void Do(Image &my_image) override;
    void Cycle(Image &my_imag, std::vector<std::vector<Pixel>>& new_field, bool first, bool second, double coef);
};
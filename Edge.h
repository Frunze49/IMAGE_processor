#pragma once

#include "GrayScale.h"

class Edge : public GrayScale {
private:
    double threshold_;

public:
    Edge(double new_threshold);
    void Do(Image &my_image) override;
};
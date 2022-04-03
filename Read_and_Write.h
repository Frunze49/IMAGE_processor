#pragma once

#include "image_processor.h"
#include "Pixel.h"

class ReadAndWrite {
public:
    void Read(Image& image, std::ifstream &in_str);
    void Write(Image& image, std::ofstream &out_str);
};
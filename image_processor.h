#pragma once

#include <cstdint>
#include <iostream>
#include <fstream>
#include <bit>
#include <vector>
#include <exception>

#include "Pixel.h"

const int BGR = 3;
const int header_size = 54;

struct Image {
    char header_first[2];
    char header_second[12];
    char header_third[8];
    char header_forth[16];
    std::vector<std::vector<Pixel>> field;

    uint32_t width;
    uint32_t height;
    uint32_t size;
    uint32_t size_bm;
};
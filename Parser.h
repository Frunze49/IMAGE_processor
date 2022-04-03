#pragma once

#include "image_processor.h"
#include "Filters.h"
#include "Crop.h"
#include "GrayScale.h"
#include "Edge.h"
#include "Negative.h"
#include "Sharpening.h"
#include "GaussianBlur.h"
#include "Pointillize.h"
#include "Read_and_Write.h"

struct Parser{
    Image image;
    std::ifstream input_stream;
    std::ofstream output_stream;
    ReadAndWrite read_write;
    void MainProcess(int argc, char *argv[]);
};
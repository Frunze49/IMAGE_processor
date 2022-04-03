cmake_minimum_required(VERSION 3.21)
project(project)

set(CMAKE_CXX_STANDARD 17)
add_executable(
        project image_processor.cpp
        Filters.h Pixel.h
        Sharpening.h Sharpening.cpp
        Negative.h Negative.cpp
        Crop.h Crop.cpp
        GrayScale.cpp GrayScale.h
        Edge.h Edge.cpp
        GaussianBlur.h GaussianBlur.cpp
        Parser.h Parser.cpp
        Read_and_Write.cpp Read_and_Write.h Pointillize.cpp Pointillize.h)

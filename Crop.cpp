#include "Crop.h"

Crop::Crop(size_t width, size_t height) {
    new_width = width;
    new_height = height;
}

void Crop::Do(Image &my_image) {
    std::vector<std::vector<Pixel>> new_field;
    new_field.assign(new_height, std::vector<Pixel>(new_width));

    size_t new_padding = (4 - (BGR * new_width % 4)) % 4;

    for (size_t i = 0; i < new_height; ++i) {
        for (size_t j = 0; j < new_width; ++j) {
            new_field[i][j] = my_image.field[i][j];
        }
    }

    my_image.field = new_field;
    my_image.size_bm = (BGR * new_width + new_padding) * new_height;
    my_image.size = header_size + my_image.size_bm;
    my_image.width = new_width;
    my_image.height = new_height;
}
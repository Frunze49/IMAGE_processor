#include "GrayScale.h"

void GrayScale::Do(Image &my_image) {
    for (size_t i = 0; i < my_image.field.size(); ++i) {
        for (size_t j = 0; j < my_image.field[0].size(); ++j) {
            my_image.field[i][j].blue =
                static_cast<uint8_t>(0.114 * my_image.field[i][j].blue + 0.587 * my_image.field[i][j].green +
                                     0.299 * my_image.field[i][j].red);
            my_image.field[i][j].green = my_image.field[i][j].blue;
            my_image.field[i][j].red = my_image.field[i][j].blue;
        }
    }
}
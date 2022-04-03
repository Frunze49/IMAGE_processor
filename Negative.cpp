#include "Negative.h"

void Negative::Do(Image &my_image) {
    for (size_t i = 0; i < my_image.field.size(); ++i) {
        for (size_t j = 0; j < my_image.field[0].size(); ++j) {
            my_image.field[i][j].blue = 255 - my_image.field[i][j].blue;
            my_image.field[i][j].green = 255 - my_image.field[i][j].green;
            my_image.field[i][j].red = 255 - my_image.field[i][j].red;
        }
    }
}

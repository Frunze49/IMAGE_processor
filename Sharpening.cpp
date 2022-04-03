#include "Sharpening.h"

void Sharpening::Do(Image &my_image) {

    std::vector<std::vector<Pixel>> new_field = my_image.field;

    for (size_t i = 0; i < my_image.field.size(); ++i) {
        for (size_t j = 0; j < my_image.field[0].size(); ++j) {

            int now_blue = 5 * my_image.field[i][j].blue;
            int now_green = 5 * my_image.field[i][j].green;
            int now_red = 5 * my_image.field[i][j].red;

            if (i > 0) {
                now_blue -= 1 * my_image.field[i - 1][j].blue;
                now_green -= 1 * my_image.field[i - 1][j].green;
                now_red -= 1 * my_image.field[i - 1][j].red;
            }
            if (i + 1 < my_image.field.size()) {
                now_blue -= 1 * my_image.field[i + 1][j].blue;
                now_green -= 1 * my_image.field[i + 1][j].green;
                now_red -= 1 * my_image.field[i + 1][j].red;
            }
            if (j > 0) {
                now_blue -= 1 * my_image.field[i][j - 1].blue;
                now_green -= 1 * my_image.field[i][j - 1].green;
                now_red -= 1 * my_image.field[i][j - 1].red;
            }
            if (j + 1 < my_image.field[0].size()) {
                now_blue -= 1 * my_image.field[i][j + 1].blue;
                now_green -= 1 * my_image.field[i][j + 1].green;
                now_red -= 1 * my_image.field[i][j + 1].red;
            }
            new_field[i][j].blue = std::min(255, std::max(0, static_cast<int>(now_blue)));
            new_field[i][j].blue = std::min(255, std::max(0, static_cast<int>(now_green)));
            new_field[i][j].blue = std::min(255, std::max(0, static_cast<int>(now_red)));
        }
    }
    my_image.field = new_field;
}
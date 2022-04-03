#include "Edge.h"
#include <cmath>

Edge::Edge(double new_threshold) {
    threshold_ = new_threshold;
}

void Edge::Do(Image &my_image) {
    GrayScale::Do(my_image);
    std::vector<std::vector<Pixel>> new_field = my_image.field;
    for (size_t i = 0; i < my_image.field.size(); ++i) {
        for (size_t j = 0; j < my_image.field[0].size(); ++j) {

            int now_blue = 4 * static_cast<int>(my_image.field[i][j].blue);

            if (i > 0) {
                now_blue -= static_cast<int>(my_image.field[i - 1][j].blue);
            } else {
                now_blue -= static_cast<int>(my_image.field[i][j].blue);
            }

            if (i + 1 < my_image.field.size()) {
                now_blue -= static_cast<int>(my_image.field[i + 1][j].blue);
            } else {
                now_blue -= static_cast<int>(my_image.field[i][j].blue);
            }

            if (j > 0) {
                now_blue -= static_cast<int>(my_image.field[i][j - 1].blue);
            } else {
                now_blue -= static_cast<int>(my_image.field[i][j].blue);
            }

            if (j + 1 < my_image.field[0].size()) {
                now_blue -= static_cast<int>(my_image.field[i][j + 1].blue);
            } else {
                now_blue -= static_cast<int>(my_image.field[i][j].blue);
            }

            if (now_blue > std::max(0, (std::min(255, static_cast<int>(ceil(255. * threshold_)))))) {
                now_blue = 255;
            } else {
                now_blue = 0;
            }

            new_field[i][j].blue = now_blue;
            new_field[i][j].green = now_blue;
            new_field[i][j].red = now_blue;
        }
    }
    my_image.field = new_field;
}

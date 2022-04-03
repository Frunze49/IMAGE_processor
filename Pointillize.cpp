#include "Pointillize.h"
#include <cmath>
#include <random>

Pointillize::Pointillize(double new_lambda, int64_t new_radius) {
    lambda_ = new_lambda;
    radius_ = new_radius;
}

void Pointillize::Do(Image &my_image) {

    std::vector<std::vector<Pixel>> new_field(my_image.height, std::vector<Pixel>(my_image.width, {255, 255, 255}));
    size_t amount_circle = ceil(lambda_ * (my_image.height * my_image.width) / (M_PI * radius_ * radius_));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib_width(0, my_image.width - 1);
    std::uniform_int_distribution<> distrib_height(0, my_image.height - 1);

    for (size_t i = 0; i < amount_circle; ++i) {
        int y = distrib_height(gen);
        int x = distrib_width(gen);
        for (int it_y = -radius_; it_y <= radius_; ++it_y) {
            for (int it_x = -radius_; it_x <= radius_; ++it_x) {
                if (it_x * it_x + it_y * it_y <= radius_ * radius_ && 0 <= x + it_x && x + it_x < static_cast<int>(my_image.width) && 0 <= y + it_y &&
                    y + it_y < static_cast<int>(my_image.height)) {
                    new_field[y + it_y][x + it_x] = my_image.field[y][x];
                }
            }
        }
    }
    my_image.field = new_field;
}
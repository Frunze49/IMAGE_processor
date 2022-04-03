#include "GaussianBlur.h"
#include "math.h"

GaussianBlur::GaussianBlur(double new_sigma) {
    sigma_ = new_sigma;
}

void GaussianBlur::Cycle(Image &my_image, std::vector<std::vector<Pixel>> &new_field, bool first, bool second,
                         double coef) {
    for (size_t i = 0; i < my_image.height; ++i) {
        for (size_t j = 0; j < my_image.width; ++j) {
            double gs_blue = 0;
            double gs_green = 0;
            double gs_red = 0;
            for (int iter = static_cast<int>(-ceil(3 * sigma_)); iter <= static_cast<int>(ceil(3 * sigma_)); ++iter) {
                if ((iter + j >= 0 && iter + i < my_image.width && second) ||
                    (iter + i >= 0 && iter + i < my_image.height && first)) {
                    gs_blue += coef * my_image.field[i + iter * first][j + iter * second].blue *
                               exp(-(iter * iter) / (2 * sigma_ * sigma_));
                    gs_green += coef * my_image.field[i + iter * first][j + iter * second].green *
                                exp(-(iter * iter) / (2 * sigma_ * sigma_));
                    gs_red += coef * my_image.field[i + iter * first][j + iter * second].red *
                              exp(-(iter * iter) / (2 * sigma_ * sigma_));
                } else if ((iter + j < 0 && second) || (iter + i < 0 && first)) {
                    gs_blue +=
                        coef * my_image.field[i * second][j * first].blue * exp(-(iter * iter) / (2 * sigma_ * sigma_));
                    gs_green += coef * my_image.field[i * second][j * first].green *
                                exp(-(iter * iter) / (2 * sigma_ * sigma_));
                    gs_red +=
                        coef * my_image.field[i * second][j * first].red * exp(-(iter * iter) / (2 * sigma_ * sigma_));
                } else {
                    gs_blue += coef *
                               my_image
                                   .field[i * second + (my_image.height - 1) * first]
                                         [j * first + (my_image.width - 1) * second]
                                   .blue *
                               exp(-(iter * iter) / (2 * sigma_ * sigma_));
                    gs_green += coef *
                                my_image
                                    .field[i * second + (my_image.height - 1) * first]
                                          [j * first + (my_image.width - 1) * second]
                                    .green *
                                exp(-(iter * iter) / (2 * sigma_ * sigma_));
                    gs_red += coef *
                              my_image
                                  .field[i * second + (my_image.height - 1) * first]
                                        [j * first + (my_image.width - 1) * second]
                                  .red *
                              exp(-(iter * iter) / (2 * sigma_ * sigma_));
                }
            }
            new_field[i][j].blue = std::min(255, std::max(0, static_cast<int>(gs_blue)));
            new_field[i][j].green = std::min(255, std::max(0, static_cast<int>(gs_green)));
            new_field[i][j].red = std::min(255, std::max(0, static_cast<int>(gs_red)));
        }
    }
    my_image.field = new_field;
}

void GaussianBlur::Do(Image &my_image) {
    std::vector<std::vector<Pixel>> new_field = my_image.field;
    double coef = 1. / (sigma_ * sqrt(2 * M_PI));
    Cycle(my_image, new_field, 0, 1, coef);
    std::vector<std::vector<Pixel>> new_new_field = new_field;
    Cycle(my_image, new_new_field, 1, 0, coef);
}

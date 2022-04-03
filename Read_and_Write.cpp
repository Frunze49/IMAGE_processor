#include "Read_and_Write.h"

size_t Padding(const Image &image) {
    return (4 - (BGR * image.width % 4)) % 4;
}

void ReadAndWrite::Read(Image& image, std::ifstream &in_stream) {

    in_stream.read(reinterpret_cast<char *>(&image.header_first), sizeof(image.header_first));

    in_stream.read(reinterpret_cast<char *>(&image.size), sizeof(image.size));

    in_stream.read(reinterpret_cast<char *>(&image.header_second), sizeof(image.header_second));

    in_stream.read(reinterpret_cast<char *>(&image.width), sizeof(image.width));
    in_stream.read(reinterpret_cast<char *>(&image.height), sizeof(image.height));

    in_stream.read(reinterpret_cast<char *>(&image.header_third), sizeof(image.header_third));

    in_stream.read(reinterpret_cast<char *>(&image.size_bm), sizeof(image.size_bm));

    in_stream.read(reinterpret_cast<char *>(&image.header_forth), sizeof(image.header_forth));

    image.field.assign(image.height, std::vector<Pixel>(image.width));

    in_stream.seekg(0x36);
    uint8_t trash;
    size_t padding = Padding(image);

    for (size_t i = 0; i < image.height; ++i) {
        for (size_t j = 0; j < image.width + padding; ++j) {
            if (j >= image.width) {
                in_stream.read(reinterpret_cast<char *>(&trash), sizeof(trash));
            } else {
                Pixel pixel;
                in_stream.read(reinterpret_cast<char *>(&pixel.blue), sizeof(pixel.blue));
                in_stream.read(reinterpret_cast<char *>(&pixel.green), sizeof(pixel.green));
                in_stream.read(reinterpret_cast<char *>(&pixel.red), sizeof(pixel.red));
                image.field[image.height - 1 - i][j] = pixel;
            };
        }
    }
}

void ReadAndWrite::Write(Image& image, std::ofstream &out_str) {
    out_str.write(reinterpret_cast<char *>(&image.header_first), sizeof(image.header_first));

    out_str.write(reinterpret_cast<char *>(&image.size), sizeof(image.size));

    out_str.write(reinterpret_cast<char *>(&image.header_second), sizeof(image.header_second));

    out_str.write(reinterpret_cast<char *>(&image.width), sizeof(image.width));
    out_str.write(reinterpret_cast<char *>(&image.height), sizeof(image.height));

    out_str.write(reinterpret_cast<char *>(&image.header_third), sizeof(image.header_third));

    out_str.write(reinterpret_cast<char *>(&image.size_bm), sizeof(image.size_bm));

    out_str.write(reinterpret_cast<char *>(&image.header_forth), sizeof(image.header_forth));

    size_t padding = Padding(image);
    uint8_t trash = 0;

    for (size_t i = 0; i < image.height; ++i) {
        for (size_t j = 0; j < image.width + padding; ++j) {
            if (j >= image.width) {
                out_str.write(reinterpret_cast<char *>(&trash), sizeof(trash));
            } else {
                Pixel pixel = image.field[image.height - 1 - i][j];
                out_str.write(reinterpret_cast<char *>(&pixel.blue), sizeof(pixel.blue));
                out_str.write(reinterpret_cast<char *>(&pixel.green), sizeof(pixel.green));
                out_str.write(reinterpret_cast<char *>(&pixel.red), sizeof(pixel.red));
            };
        }
    }
}

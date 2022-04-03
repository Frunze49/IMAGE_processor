#include "Parser.h"

void Parser::MainProcess(int argc, char* argv[]) {

    try {
        if (argc < 3) {
            throw std::invalid_argument("Try to input more than 2 arguments");
        }
        for (int i = 0; i < argc; ++i) {
            if (i == 1) {
                input_stream = std::ifstream(argv[i], std::ios::binary);
                read_write.Read(image, input_stream);
            } else if (i == 2) {
                output_stream = std::ofstream(argv[i], std::ios::binary);
            } else {
                if (argv[i] == std::string("-gs")) {
                    GrayScale gs;
                    gs.Do(image);
                } else if (argv[i] == std::string("-neg")) {
                    Negative neg;
                    neg.Do(image);
                } else if (argv[i] == std::string("-sharp")) {
                    Sharpening sh;
                    sh.Do(image);
                } else if (argv[i] == std::string("-blur")) {

                    if (i + 1 < argc) {
                        try {
                            GaussianBlur gb(std::stod(argv[i + 1]));
                            gb.Do(image);
                        } catch (std::invalid_argument& error) {
                            std::cout << "Try to input double with the blur";
                        }
                    } else {
                        throw std::invalid_argument("Try to input double with the blur");
                    }
                }

                else if (argv[i] == std::string("-crop")) {

                    if (i + 2 < argc) {
                        try {
                            Crop c(std::stoi(argv[i + 1]), std::stoi(argv[i + 2]));
                            c.Do(image);
                        } catch (std::invalid_argument& error) {
                            std::cout << "Try to input two integers with the crop";
                        }
                    } else {
                        throw std::invalid_argument("Try to input two integers with the crop");
                    }
                } else if (argv[i] == std::string("-edge")) {

                    if (i + 1 < argc) {
                        try {
                            Edge e(std::stod(argv[i + 1]));
                            e.Do(image);
                        } catch (std::invalid_argument& error) {
                            std::cout << "Try to input double with the edge";
                        }
                    } else {
                        throw std::invalid_argument("Try to input double with the edge");
                    }
                } else if (argv[i] == std::string("-point")) {

                    if (i + 2 < argc) {
                        try {
                            Pointillize pointillize(std::stod(argv[i + 1]), std::stoi(argv[i + 2]));
                            pointillize.Do(image);
                        } catch (std::invalid_argument& error) {
                            std::cout << "Try to input double and integer with the pointillize";
                        }
                    } else {
                        throw std::invalid_argument("Try to input double and integer with the pointillize");
                    }
                }
            }
        }
        read_write.Write(image, output_stream);
        output_stream = 0;
    } catch (std::invalid_argument& error) {
        std::cerr << error.what() << std::endl;
    }
}
#include "image_processor.h"
#include "Filters.h"
#include "Crop.h"
#include "GrayScale.h"
#include "Edge.h"
#include "Negative.h"
#include "Sharpening.h"
#include "GaussianBlur.h"
#include "Read_and_Write.h"
#include "Parser.h"

int main(int argc, char *argv[]) {
    Parser parser;
    parser.MainProcess(argc, argv);
    return 0;
}

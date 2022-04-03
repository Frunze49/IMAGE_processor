#include "Filters.h"

class Pointillize : public Filters {
private:
    double lambda_;
    int radius_;
public:
    Pointillize(double new_lambda, int64_t new_radius);
    void Do(Image& image) override;
};
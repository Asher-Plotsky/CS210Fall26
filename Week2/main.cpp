#include <iostream>
#include "shape_utility.h"
#define GREETING "Welcome to CS210"

int main() {
    double area1 = circle_area(4);
    double area2 = rectangle_area(4,4);
    std::cout << "area 1 Circle Area " << area1 << std::endl;
    std::cout << "area 2 Rectangle Area " << area2 << std::endl;
    return 0;
}
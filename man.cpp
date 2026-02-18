#include <iostream>
#include "TrigMath.hpp"

int main() {
    double angle = 90.0;
    std::cout << "Sin of " << angle << " degrees: " << Trig::sin(angle, true) << std::endl;
    std::cout << "Cosec of 0.5 rad: " << Trig::cosec(0.5) << std::endl;
    return 0;
}
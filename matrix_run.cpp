#include "include/linalg/LinLib.hpp"
#include <iostream>

int main() {
    // 1. Create a 3x3 Positive Definite Matrix
    LinLib::Matrix<double> myMat = {
        {4, 1, 1},
        {1, 3, 1},
        {1, 1, 2}
    };

    std::cout << "--- Matrix Analysis ---" << std::endl;
    
    // Test Rank
    std::cout << "Rank: " << LinLib::Rank(myMat) << std::endl;

    // Test Determinant
    std::cout << "Determinant: " << LinLib::Det(myMat) << std::endl;

    // Test Transpose
    auto T = LinLib::Transpose(myMat);
    std::cout << "Transpose [0][1]: " << T[0][1] << " (Original [1][0] was: " << myMat[1][0] << ")" << std::endl;

    // Test PD / ND
    std::cout << "Is Positive Definite (PD)? " << (LinLib::isPD(myMat) ? "Yes" : "No") << std::endl;
    std::cout << "Is Negative Definite (ND)? " << (LinLib::isND(myMat) ? "Yes" : "No") << std::endl;

    return 0;
}
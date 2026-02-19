#include <iostream>
#include <iomanip>
#include "VecLib.hpp"

int main() {
    using namespace VecLib;
    std::cout << std::fixed << std::setprecision(4);

    // 1. Vector Properties
    Vector3 A(1.0, 2.0, 3.0);
    Vector3 B(4.0, 5.0, 6.0);
    
    std::cout << "--- Vector Properties ---" << std::endl;
    std::cout << "Norm of A: " << Norm(A) << std::endl;
    std::cout << "Unit Vector A: " << unit_vector(A).transpose() << "\n\n";

    // 2. Eigenvalue Solver
    std::cout << "--- Eigen Solver ---" << std::endl;
    MatrixX M(2, 2);
    M << 2, 1, 
         1, 2;
    SolveEigen(M);

    // 3. Vector Calculus (Divergence)
    std::cout << "\n--- Vector Calculus ---" << std::endl;
    auto myField = [](VectorX p) -> VectorX {
        VectorX res(3);
        res << p(0)*p(0), p(1)*p(1), p(2)*p(2); // F = (x^2, y^2, z^2)
        return res;
    };

    VectorX point(3);
    point << 1.0, 1.0, 1.0;
    std::cout << "Div at (1,1,1): " << Divergence(myField, point) << std::endl;

    return 0;
}
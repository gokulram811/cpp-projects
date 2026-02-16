#include <iostream>
#include <vector>
#include <iomanip>
#include <functional>

// Modular Header Includes
#include "calc/CalcLib.hpp"
#include "vectors/VecLib.hpp"
#include "constants/UniCon.hpp"

void clear_input() {
    std::cin.clear();
    std::cin.ignore(1000, '\n');
}

// --- Menu Handlers ---

void runCalculusMenu() {
    int choice;
    std::cout << "\n--- CALCULUS OPERATIONS ---\n";
    std::cout << "1. Numerical Derivative (Ddt) of x^2\n";
    std::cout << "2. Taylor Series Approximation (sin(x))\n";
    std::cout << "3. Continuity Check\nChoice: ";
    std::cin >> choice;

    if (choice == 1) {
        auto f = [](double x) { return x * x; };
        double point = 3.0;
        std::cout << "Derivative of x^2 at x=" << point << " is: " << CalcLib::Ddt(f, point) << "\n";
    } else if (choice == 2) {
        auto f = [](double x) { return std::sin(x); };
        // Approximating sin(0.5) near 0 with 2 terms
        std::cout << "Taylor Approx of sin(0.5): " << CalcLib::Taylor_series(f, 0.5, 0.0, 2) << "\n";
    } else if (choice == 3) {
        auto f = [](double x) { return 1.0 / x; };
        std::cout << "Is 1/x continuous at 0? " << (CalcLib::Continuity(f, 0.0) ? "Yes" : "No") << "\n";
    }
}



void runVectorMenu() {
    int choice;
    std::cout << "\n--- VECTOR OPERATIONS ---\n";
    std::cout << "1. Norm & Unit Vector\n";
    std::cout << "2. Vector Triple Product (A x (B x C))\n";
    std::cout << "3. Orthogonality Check\nChoice: ";
    std::cin >> choice;

    VecLib::Vector A = {1.0, 0.0, 0.0};
    VecLib::Vector B = {0.0, 1.0, 0.0};
    VecLib::Vector C = {0.0, 0.0, 1.0};

    if (choice == 1) {
        std::cout << "Norm of A [1,0,0]: " << VecLib::Norm(A) << "\n";
    } else if (choice == 2) {
        auto res = VecLib::Vector_TP(A, B, C);
        std::cout << "Triple Product Result: [" << res[0] << "," << res[1] << "," << res[2] << "]\n";
    } else if (choice == 3) {
        std::cout << "Are A and B orthogonal? " << (VecLib::Orthogonal(A, B) ? "Yes" : "No") << "\n";
    }
}



void runConstantsMenu() {
    std::cout << "\n--- UNIVERSAL CONSTANTS ---\n";
    std::cout << "Math PI: " << UniCon::Maths::pi << "\n";
    std::cout << "Physics g: " << UniCon::Physics::g << " m/s^2\n";
    std::cout << "Gas Constant (R): " << UniCon::Chemistry::R << " J/(mol*K)\n";
    std::cout << "Electron Mass: " << UniCon::Particle::me << " kg\n";
}

// --- Main CLI Engine ---

int main() {
    // Set global precision for scientific output
    std::cout << std::fixed << std::setprecision(6);

    int mainChoice;
    while (true) {
        std::cout << "\n========================================\n";
        std::cout << "     LLVM MATH MASTER TOOLKIT (UPI)     \n";
        std::cout << "========================================\n";
        std::cout << "1. Calculus Operations\n";
        std::cout << "2. Vector Operations\n";
        std::cout << "3. Universal Constants\n";
        std::cout << "0. Exit\n";
        std::cout << "Selection: ";

        if (!(std::cin >> mainChoice)) {
            clear_input();
            continue;
        }

        if (mainChoice == 0) break;

        switch (mainChoice) {
            case 1: runCalculusMenu(); break;
            case 2: runVectorMenu(); break;
            case 3: runConstantsMenu(); break;
            default: std::cout << "Invalid Selection.\n";
        }
    }

    std::cout << "Toolkit shutting down. Goodbye.\n";
    return 0;
}
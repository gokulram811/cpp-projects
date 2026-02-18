#define _USE_MATH_DEFINES 
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include "CalcLib.hpp"

using namespace std;
using namespace CalculusLib;

void print_test(string name, double result, double expected) {
    cout << left << setw(30) << name 
         << " | Result: " << setw(10) << result 
         << " | Error: " << abs(result - expected) << endl;
}

int main() {
    cout << "=== CALCULUS ENGINE COMPREHENSIVE TEST ===\n" << endl;
    cout << fixed << setprecision(6);

    // 1. BASIC CALCULUS & TRIG
    // Test: d/dx of sin(x) at PI/4 is cos(PI/4) approx 0.707107
    auto f_sin = [](double x) { return sin(x); };
    print_test("Ddt: sin(x) at PI/4", Ddt(f_sin, M_PI_4), cos(M_PI_4));

    // Test: d/dx of (x^2 + 3x) at x=2 is 7
    auto f_poly = [](double x) { return pow(x, 2) + 3 * x; };
    print_test("Ddt: x^2 + 3x at x=2", Ddt(f_poly, 2.0), 7.0);

    // Test: Integral of sin(x) from 0 to PI is 2
    print_test("Integral: sin(x) [0, PI]", Integral(f_sin, 0, M_PI), 2.0);

    // 2. VECTOR CALCULUS
    // Scalar Field: f = x^2 + y^2. Grad = [2x, 2y]. At (1,2) = [2, 4]
    auto f_scalar = [](const Vector& v) { return v[0]*v[0] + v[1]*v[1]; };
    Vector g = Grad(f_scalar, {1.0, 2.0});
    cout << left << setw(30) << "Grad: x^2 + y^2 at (1,2)" 
         << " | Result: [" << g[0] << ", " << g[1] << "]" << " | Expected: [2.0, 4.0]" << endl;

    // Laplacian: f = x^2 + y^2. Laplace = 2 + 2 = 4
    print_test("Laplace: x^2 + y^2", Laplace(f_scalar, {1.0, 2.0}), 4.0);

    // Curl: F = {-y, x, 0}. Curl = [0, 0, 2]
    auto f_vortex = [](const Vector& v) -> Vector { return {-v[1], v[0], 0.0}; };
    Vector c = Curl(f_vortex, {0, 0, 0});
    cout << left << setw(30) << "Curl: {-y, x, 0}" 
         << " | Result: [" << c[0] << ", " << c[1] << ", " << c[2] << "]" << " | Expected: [0, 0, 2]" << endl;

    // 3. THEOREMS
    // Green's Theorem: Integral over unit square for P=-y, Q=x. Result = 2.0
    double green = Green_Integral([](double x, double y){return -y;}, [](double x, double y){return x;}, 0, 1, 0, 1);
    print_test("Green's Theorem (Square)", green, 2.0);

    // Stokes' Theorem: Surface integral of curl over unit square. Result = 2.0
    double stokes = Stokes_integral(f_vortex, 0, 1, 0, 1);
    print_test("Stokes' Theorem (Square)", stokes, 2.0);

    // 4. SERIES & LIMITS
    // Taylor: e^x at x=1, centered a=0, order 3. e^1 approx 2.718
    // Note: Taylor uses 1st order derivative in your current header logic
    auto f_exp = [](double x) { return exp(x); };
    cout << left << setw(30) << "Taylor: e^x at x=1 (n=3)" 
         << " | Result: " << Taylor_series(f_exp, 1.0, 0.0, 3) << " | Exact e^1: " << M_E << endl;

    // Continuity: 1/x is NOT continuous at 0 (or very near 0)
    bool cont = Continuity([](double x){ return 1.0/x; }, 0.00001);
    cout << left << setw(30) << "Continuity: 1/x near 0" 
         << " | Result: " << (cont ? "Continuous" : "Discontinuous") << " | Expected: Discontinuous" << endl;

    cout << "\n=== TEST COMPLETE ===" << endl;
    return 0;
}
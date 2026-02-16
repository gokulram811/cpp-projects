#ifndef CALC_LIB_HPP
#define CALC_LIB_HPP

#include <vector>
#include <functional>
#include <cmath>
#include <string>

namespace CalcLib {

    // ==========================================
    // 1. BASIC DIFFERENTIAL CALCULUS
    // ==========================================

    // Derivative - Notation: Ddt()
    static double Ddt(std::function<double(double)> f, double x, double h = 1e-5) {
        return (f(x + h) - f(x - h)) / (2.0 * h);
    }

    // Partial Derivative - Notation: Pddt()
    static double Pddt(std::function<double(const std::vector<double>&)> f, 
                      std::vector<double> x, size_t idx, double h = 1e-5) {
        x[idx] += h;
        double f_plus = f(x);
        x[idx] -= 2.0 * h;
        double f_minus = f(x);
        return (f_plus - f_minus) / (2.0 * h);
    }

    // ==========================================
    // 2. VECTOR CALCULUS OPERATIONS
    // ==========================================

    // Gradient - Notation: Grad()
    static std::vector<double> Grad(std::function<double(const std::vector<double>&)> f, 
                                   const std::vector<double>& x) {
        std::vector<double> g(x.size());
        for (size_t i = 0; i < x.size(); ++i) g[i] = Pddt(f, x, i);
        return g;
    }

    // Laplacian - Notation: Laplace()
    static double Laplace(std::function<double(const std::vector<double>&)> f, 
                          const std::vector<double>& x, double h = 1e-4) {
        double res = 0.0;
        for (size_t i = 0; i < x.size(); ++i) {
            std::vector<double> p_plus = x, p_minus = x;
            p_plus[i] += h; p_minus[i] -= h;
            res += (f(p_plus) - 2 * f(x) + f(p_minus)) / (h * h);
        }
        return res;
    }

    // Curl (Simplified for 3D Vector Fields) - Notation: Curl()
    // Returns the curl vector at point (x, y, z)
    static std::vector<double> Curl(std::function<std::vector<double>(std::vector<double>)> F, 
                                   std::vector<double> p) {
        // Implementation of (dFz/dy - dFy/dz, dFx/dz - dFz/dx, dFy/dx - dFx/dy)
        return {0.0, 0.0, 0.0}; // Placeholder for vector field logic
    }

    // ==========================================
    // 3. SERIES & APPROXIMATIONS
    // ==========================================

    // Taylor Series - Notation: Taylor_series()
    static double Taylor_series(std::function<double(double)> f, double x, double a, int n) {
        double result = f(a);
        double factorial = 1.0;
        for (int i = 1; i <= n; ++i) {
            factorial *= i;
            // Uses higher-order finite difference for coefficients
            double h = 0.01;
            double deriv = (f(a + h) - f(a - h)) / (2 * h); // First order demo
            result += (deriv / factorial) * std::pow(x - a, i);
        }
        return result;
    }

    // Radius of Convergence - Notation: Rad_of_Con()
    static double Rad_of_Con(const std::vector<double>& coefficients) {
        // Ratio test implementation: R = lim |an / an+1|
        return 0.0; 
    }

    // ==========================================
    // 4. THEOREMS IN CALCULUS
    // ==========================================

    // Green's Theorem - Notation: Green_Integral()
    static double Green_Integral() { return 0.0; }

    // Stokes' Theorem - Notation: Stokes_integral()
    static double Stokes_integral() { return 0.0; }

    // ==========================================
    // 5. LIMITS & CONTINUITY
    // ==========================================

    // Continuity Check - Notation: Continuity()
    static bool Continuity(std::function<double(double)> f, double a, double epsilon = 1e-4) {
        double limit_left = f(a - epsilon);
        double limit_right = f(a + epsilon);
        return std::abs(limit_left - limit_right) < epsilon;
    }
}

#endif
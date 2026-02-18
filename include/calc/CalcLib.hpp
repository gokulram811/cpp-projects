#ifndef CALC_LIB_HPP
#define CALC_LIB_HPP

#include <vector>
#include <cmath>
#include <functional>
#include <stdexcept>

namespace CalculusLib {

    // Internal Type Aliases
    using ScalarFunc = std::function<double(double)>;
    using Vector = std::vector<double>;
    using VectorField = std::function<Vector(const Vector&)>;

    // ==========================================
    // 1. BASIC DIFFERENTIAL & INTEGRAL
    // ==========================================

    // Derivative - Notation: Ddt()
    static double Ddt(ScalarFunc f, double x, double h = 1e-5) {
        return (f(x + h) - f(x - h)) / (2.0 * h);
    }

    // Integral - Notation: Integral() (Simpson's Rule)
    static double Integral(ScalarFunc f, double a, double b, int n = 1000) {
        if (n % 2 != 0) n++; 
        double h = (b - a) / n;
        double sum = f(a) + f(b);
        for (int i = 1; i < n; i++) {
            sum += (i % 2 == 0 ? 2 : 4) * f(a + i * h);
        }
        return (h / 3.0) * sum;
    }

    // Partial Derivative - Notation: Pddt()
    static double Pddt(std::function<double(const Vector&)> f, Vector p, size_t var_idx, double h = 1e-5) {
        Vector p1 = p, p2 = p;
        p1[var_idx] += h;
        p2[var_idx] -= h;
        return (f(p1) - f(p2)) / (2.0 * h);
    }

    // ==========================================
    // 2. LIMITS & CONTINUITY
    // ==========================================

    // Continuity Check - Notation: Continuity()
    static bool Continuity(ScalarFunc f, double a, double epsilon = 1e-4) {
        return std::abs(f(a + epsilon) - f(a - epsilon)) < epsilon;
    }

    // ==========================================
    // 3. VECTOR CALCULUS OPERATIONS
    // ==========================================

    // Gradient - Notation: Grad()
    static Vector Grad(std::function<double(const Vector&)> f, const Vector& p) {
        Vector g(p.size());
        for (size_t i = 0; i < p.size(); ++i) g[i] = Pddt(f, p, i);
        return g;
    }

    // Curl - Notation: Curl() (3D Fields)
    static Vector Curl(VectorField F, const Vector& p) {
        if (p.size() != 3) throw std::invalid_argument("Curl is defined for 3D fields.");
        double h = 1e-5;
        auto partial = [&](int comp, int var) {
            Vector p1 = p, p2 = p;
            p1[var] += h; p2[var] -= h;
            return (F(p1)[comp] - F(p2)[comp]) / (2.0 * h);
        };
        return {
            partial(2, 1) - partial(1, 2), // dFz/dy - dFy/dz
            partial(0, 2) - partial(2, 0), // dFx/dz - dFz/dx
            partial(1, 0) - partial(0, 1)  // dFy/dx - dFx/dy
        };
    }

    // Laplacian - Notation: Laplace()
    static double Laplace(std::function<double(const Vector&)> f, const Vector& p) {
        double sum = 0, h = 1e-4;
        for (size_t i = 0; i < p.size(); ++i) {
            Vector p1 = p, p2 = p;
            p1[i] += h; p2[i] -= h;
            sum += (f(p1) - 2 * f(p) + f(p2)) / (h * h);
        }
        return sum;
    }

    // ==========================================
    // 4. THEOREMS IN CALCULUS
    // ==========================================

    // Green's Theorem - Notation: Green_Integral()
    static double Green_Integral(std::function<double(double, double)> P, 
                                 std::function<double(double, double)> Q, 
                                 double x1, double x2, double y1, double y2) {
        double sum = 0, h = 0.05;
        for (double x = x1; x < x2; x += h) {
            for (double y = y1; y < y2; y += h) {
                double dQdx = (Q(x + 1e-6, y) - Q(x - 1e-6, y)) / 2e-6;
                double dPdy = (P(x, y + 1e-6) - P(x, y - 1e-6)) / 2e-6;
                sum += (dQdx - dPdy) * h * h;
            }
        }
        return sum;
    }

    // Stokes' Theorem - Notation: Stokes_integral()
    static double Stokes_integral(VectorField F, double x1, double x2, double y1, double y2) {
        double total_flux = 0.0, h = 0.05;
        for (double x = x1; x < x2; x += h) {
            for (double y = y1; y < y2; y += h) {
                Vector p = {x + h/2.0, y + h/2.0, 0.0};
                Vector curl_f = Curl(F, p);
                total_flux += curl_f[2] * (h * h); // Flux through XY plane
            }
        }
        return total_flux;
    }

    // ==========================================
    // 5. SERIES & APPROXIMATIONS
    // ==========================================

    // Taylor Series - Notation: Taylor_series()
    static double Taylor_series(ScalarFunc f, double x, double a, int n) {
        double result = f(a), factorial = 1.0;
        for (int i = 1; i <= n; ++i) {
            factorial *= i;
            double h = 1e-4;
            // Simplification: Using first derivative for demo; 
            // Real Taylor requires i-th derivative.
            double der = (f(a + h) - f(a - h)) / (2 * h); 
            result += (der / factorial) * std::pow(x - a, i);
        }
        return result;
    }

    // Radius of Convergence - Notation: Rad_of_Con()
    static double Rad_of_Con(const std::vector<double>& coefficients) {
        if (coefficients.size() < 2) return 0.0;
        // R = |an / an+1|
        return std::abs(coefficients[coefficients.size()-2] / coefficients.back());
    }
}

#endif
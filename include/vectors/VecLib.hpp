#ifndef VEC_LIB_HPP
#define VEC_LIB_HPP

#include <vector>
#include <cmath>
#include <numeric>
#include <functional>
#include <stdexcept>

namespace VecLib {
    using Vector = std::vector<double>;

    // Notation: Norm - L2 Magnitude
    static double Norm(const Vector& V) {
        double sum = 0;
        for (double x : V) sum += x * x;
        return std::sqrt(sum);
    }

    // Notation: unit_vector()
    static Vector unit_vector(const Vector& V) {
        double n = Norm(V);
        if (n < 1e-12) return V; 
        Vector res = V;
        for (double& x : res) x /= n;
        return res;
    }

    // Notation: Dircos - Direction Cosines
    static Vector Dircos(const Vector& V) {
        return unit_vector(V); 
    }

    // Dot Product helper
    static double Dot(const Vector& A, const Vector& B) {
        return std::inner_product(A.begin(), A.end(), B.begin(), 0.0);
    }

    // Notation: Cross Product (3D only)
    static Vector Cross(const Vector& A, const Vector& B) {
        if (A.size() != 3 || B.size() != 3) 
            throw std::invalid_argument("Cross product is defined for 3D vectors.");
        return {
            A[1] * B[2] - A[2] * B[1],
            A[2] * B[0] - A[0] * B[2],
            A[0] * B[1] - A[1] * B[0]
        };
    }

    

    // Notation: Vector_TP - Vector Triple Product A x (B x C)
    static Vector Vector_TP(const Vector& A, const Vector& B, const Vector& C) {
        return Cross(A, Cross(B, C));
    }

    // Notation: Proj(A,B) - Scalar Projection
    static double Proj(const Vector& A, const Vector& B) {
        return Dot(A, B) / Norm(B);
    }

    // Notation: Proj_Vec() - Vector Projection
    static Vector Proj_Vec(const Vector& A, const Vector& B) {
        double scalar = Dot(A, B) / (Dot(B, B));
        Vector res = B;
        for (double& x : res) x *= scalar;
        return res;
    }

    // Notation: Orthogonal()
    static bool Orthogonal(const Vector& A, const Vector& B) {
        return std::abs(Dot(A, B)) < 1e-9;
    }

    // Notation: Orthonormal() - Orthogonal and both are unit vectors
    static bool Orthonormal(const Vector& A, const Vector& B) {
        return Orthogonal(A, B) && std::abs(Norm(A) - 1.0) < 1e-7 && std::abs(Norm(B) - 1.0) < 1e-7;
    }

    // Notation: Divergence() for vector fields
    static double Divergence(std::function<Vector(Vector)> F, Vector p) {
        double div = 0;
        double h = 1e-5;
        for (size_t i = 0; i < p.size(); ++i) {
            Vector p_p = p, p_m = p;
            p_p[i] += h; p_m[i] -= h;
            div += (F(p_p)[i] - F(p_m)[i]) / (2.0 * h);
        }
        return div;
    }

    // Notation: Curl() (3D Vector Fields)
    static Vector Curl(std::function<Vector(Vector)> F, Vector p) {
        if (p.size() != 3) throw std::invalid_argument("Curl is defined for 3D fields.");
        double h = 1e-5;
        auto partial = [&](int field_comp, int var_idx) {
            Vector p_p = p, p_m = p;
            p_p[var_idx] += h; p_m[var_idx] -= h;
            return (F(p_p)[field_comp] - F(p_m)[field_comp]) / (2.0 * h);
        };

        return {
            partial(2, 1) - partial(1, 2), // dFz/dy - dFy/dz
            partial(0, 2) - partial(2, 0), // dFx/dz - dFz/dx
            partial(1, 0) - partial(0, 1)  // dFy/dx - dFx/dy
        };
    }

    
}
#endif
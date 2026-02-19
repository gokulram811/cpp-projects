#ifndef VECLIB_HPP
#define VECLIB_HPP

#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <vector>
#include <functional>
#include <cmath>
#include <iostream>

namespace VecLib {

    // --- Type Definitions ---
    using Vector3 = Eigen::Vector3d;
    using VectorX = Eigen::VectorXd;
    using MatrixX = Eigen::MatrixXd;
    using ScalarFunc = std::function<double(double)>;
    using FieldFunc = std::function<VectorX(VectorX)>;

    // --- Vector Algebra ---
    static double Norm(const VectorX& V) { return V.norm(); }
    
    static VectorX unit_vector(const VectorX& V) { return V.normalized(); }
    
    static VectorX Dircos(const VectorX& V) { return V.normalized(); }

    static Vector3 Vector_TP(const Vector3& A, const Vector3& B, const Vector3& C) {
        return A.cross(B.cross(C));
    }

    static double Proj(const VectorX& A, const VectorX& B) {
        return A.dot(B.normalized());
    }

    static VectorX Proj_Vec(const VectorX& A, const VectorX& B) {
        return (A.dot(B) / B.squaredNorm()) * B;
    }

    static bool Orthogonal(const VectorX& A, const VectorX& B) {
        return std::abs(A.dot(B)) < 1e-9;
    }

    static bool Orthonormal(const VectorX& A, const VectorX& B) {
        return Orthogonal(A, B) && std::abs(A.norm() - 1.0) < 1e-7;
    }

    // --- Matrix Operations ---
    static void SolveEigen(const MatrixX& M) {
        Eigen::EigenSolver<MatrixX> solver(M);
        std::cout << "Eigenvalues:\n" << solver.eigenvalues() << "\n";
        std::cout << "Eigenvectors:\n" << solver.eigenvectors() << "\n";
    }

    // --- Vector Calculus ---
    static double Divergence(FieldFunc F, VectorX p, double h = 1e-5) {
        double div = 0;
        for (int i = 0; i < p.size(); ++i) {
            VectorX p_p = p, p_m = p;
            p_p(i) += h; p_m(i) -= h;
            div += (F(p_p)(i) - F(p_m)(i)) / (2.0 * h);
        }
        return div;
    }

    static Vector3 Curl(std::function<Vector3(Vector3)> F, Vector3 p, double h = 1e-5) {
        auto partial = [&](int field_comp, int var_idx) {
            Vector3 p_p = p, p_m = p;
            p_p(var_idx) += h; p_m(var_idx) -= h;
            return (F(p_p)(field_comp) - F(p_m)(field_comp)) / (2.0 * h);
        };
        return Vector3(
            partial(2, 1) - partial(1, 2),
            partial(0, 2) - partial(2, 0),
            partial(1, 0) - partial(0, 1)
        );
    }
} // End of Namespace VecLib

#endif
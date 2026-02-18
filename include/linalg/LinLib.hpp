#ifndef LIN_LIB_HPP
#define LIN_LIB_HPP

#include <vector>
#include <iostream>
#include <Eigen/Dense>

namespace LinLib {
    template <typename T>
    using Matrix = std::vector<std::vector<T>>;

    // Helper: Convert std::vector to Eigen Matrix
    template <typename T>
    Eigen::MatrixXd toEigen(const Matrix<T>& A) {
        int r = A.size();
        int c = A[0].size();
        Eigen::MatrixXd res(r, c);
        for(int i=0; i<r; ++i)
            for(int j=0; j<c; ++j) res(i,j) = static_cast<double>(A[i][j]);
        return res;
    }

    // --- YOUR CODE (Structural) ---
    template <typename T>
    static Matrix<T> Transpose(const Matrix<T>& A) {
        Matrix<T> AT(A[0].size(), std::vector<T>(A.size()));
        for (size_t i = 0; i < A.size(); ++i)
            for (size_t j = 0; j < A[0].size(); ++j) AT[j][i] = A[i][j];
        return AT;
    }

    // --- EIGEN CODE (Mathematical) ---
    template <typename T>
    static int Rank(const Matrix<T>& A) {
        return toEigen(A).fullPivLu().rank();
    }

    template <typename T>
    static double Det(const Matrix<T>& A) {
        return toEigen(A).determinant();
    }

    // --- PROPERTY CHECKS (PD / ND) ---
    template <typename T>
    static bool isPD(const Matrix<T>& A) {
        Eigen::MatrixXd eA = toEigen(A);
        if (!eA.isApprox(eA.transpose())) return false;
        Eigen::LLT<Eigen::MatrixXd> llt(eA);
        return (llt.info() == Eigen::Success);
    }

    template <typename T>
    static bool isND(const Matrix<T>& A) {
        Matrix<T> negA = A;
        for(auto& row : negA) for(auto& val : row) val = -val;
        return isPD(negA);
    }
}
#endif
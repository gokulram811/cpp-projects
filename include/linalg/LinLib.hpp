#ifndef LIN_LIB_HPP
#define LIN_LIB_HPP

#include <vector>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <iostream>

namespace LinLib {
    template <typename T>
    using Matrix = std::vector<std::vector<T>>;

    // --- Helpers ---
    template <typename T>
    inline bool isSquare(const Matrix<T>& A) {
        return !A.empty() && A.size() == A[0].size();
    }

    // 1. MATRIX TYPES (Generators)
    template <typename T = double>
    static Matrix<T> Unit_matrix(int n) {
        Matrix<T> I(n, std::vector<T>(n, 0));
        for (int i = 0; i < n; ++i) I[i][i] = 1;
        return I;
    }

    

    template <typename T = double>
    static Matrix<T> Zero_Matrix(int r, int c) {
        return Matrix<T>(r, std::vector<T>(c, 0));
    }

    template <typename T = double>
    static Matrix<T> Diag(const std::vector<T>& d) {
        Matrix<T> res = Zero_Matrix<T>(d.size(), d.size());
        for (size_t i = 0; i < d.size(); ++i) res[i][i] = d[i];
        return res;
    }

    // 2. MATRIX OPERATIONS
    template <typename T>
    static Matrix<T> Transpose(const Matrix<T>& A) {
        if (A.empty()) return {};
        Matrix<T> AT(A[0].size(), std::vector<T>(A.size()));
        for (size_t i = 0; i < A.size(); ++i)
            for (size_t j = 0; j < A[0].size(); ++j) AT[j][i] = A[i][j];
        return AT;
    }

    

    template <typename T>
    static T Det(const Matrix<T>& A) {
        if (!isSquare(A)) throw std::domain_error("Must be square.");
        int n = A.size();
        if (n == 1) return A[0][0];
        Matrix<double> temp;
        for(const auto& r : A) temp.push_back(std::vector<double>(r.begin(), r.end()));
        double d = 1.0;
        for (int i = 0; i < n; ++i) {
            int p = i;
            for (int j = i + 1; j < n; ++j)
                if (std::abs(temp[j][i]) > std::abs(temp[p][i])) p = j;
            std::swap(temp[i], temp[p]);
            if (p != i) d *= -1;
            if (std::abs(temp[i][i]) < 1e-9) return 0;
            d *= temp[i][i];
            for (int j = i + 1; j < n; ++j) {
                double f = temp[j][i] / temp[i][i];
                for (int k = i + 1; k < n; ++k) temp[j][k] -= f * temp[i][k];
            }
        }
        return static_cast<T>(d);
    }

    template <typename T>
    static Matrix<T> Had_Prod(const Matrix<T>& A, const Matrix<T>& B) {
        Matrix<T> res = A;
        for (size_t i = 0; i < A.size(); ++i)
            for (size_t j = 0; j < A[0].size(); ++j) res[i][j] *= B[i][j];
        return res;
    }

    

    // 3. PROPERTY CHECKS
    template <typename T>
    static T Trace(const Matrix<T>& A) {
        T s = 0;
        for (size_t i = 0; i < A.size(); ++i) s += A[i][i];
        return s;
    }

    template <typename T>
    static double Norm(const Matrix<T>& A) {
        double s = 0;
        for (const auto& r : A) for (T v : r) s += v * v;
        return std::sqrt(s);
    }

    

    template <typename T>
    static int Rank(const Matrix<T>& A) {
        if (A.empty()) return 0;
        Matrix<double> t;
        for(const auto& r : A) t.push_back(std::vector<double>(r.begin(), r.end()));
        int r = t[0].size(), rows = t.size();
        for (int i = 0; i < r; i++) {
            if (t[i][i] != 0) {
                for (int j = 0; j < rows; j++) 
                    if (j != i) {
                        double f = t[j][i] / t[i][i];
                        for (int k = 0; k < r; k++) t[j][k] -= f * t[i][k];
                    }
            } else {
                bool red = true;
                for (int j = i + 1; j < rows; j++)
                    if (t[j][i] != 0) { std::swap(t[i], t[j]); red = false; break; }
                if (red) { r--; for (int j = 0; j < rows; j++) t[j][i] = t[j][r]; }
                i--;
            }
        }
        return r;
    }

    
}
#endif
#include "stat/StatLib.hpp" 
#include <algorithm>
#include <numeric>  
#include <cmath>

static constexpr auto factorial(int n) -> unsigned long long {
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}


// Arithmetic Mean
auto StatLib::Mean(const std::vector<double>& A) -> double {
    if (A.empty()) return 0.0;
    return std::accumulate(A.begin(), A.end(), 0.0) / A.size();
}

// Median using Quickselect logic (O(n))
auto StatLib::Median(std::vector<double> A) -> double {
    if (A.empty()) return 0.0;
    size_t n = A.size();
    size_t mid = n / 2;

    // Rearranges elements so the element at 'mid' is what it would be in a sorted list
    std::nth_element(A.begin(), A.begin() + mid, A.end());
    double midVal = A[mid];

    if (n % 2 != 0) return midVal;

    // For even sets, find the largest element in the unsorted left half
    double prevVal = *std::max_element(A.begin(), A.begin() + mid);
    return (midVal + prevVal) / 2.0;
}

// Sample Variance (Bessel's correction applied: n-1)
auto StatLib::Variance(const std::vector<double>& A) -> double {
    if (A.size() < 2) return 0.0;
    double avg = Mean(A);
    double sq_sum = std::accumulate(A.begin(), A.end(), 0.0, [avg](double acc, double x) {
        return acc + (x - avg) * (x - avg);
    });
    return sq_sum / (A.size() - 1);
}

// Standard Deviation
auto StatLib::StandardDeviation(const std::vector<double>& A) -> double {
    return std::sqrt(Variance(A));
}

// Skewness
auto StatLib::Skewness(const std::vector<double>& A) -> double {
    size_t n = A.size();
    if (n < 3) return 0.0;
    
    double avg = Mean(A);
    double sd = StandardDeviation(A);
    if (sd == 0) return 0.0;

    double sum_cubed = 0.0;
    for (auto x : A) {
        sum_cubed += std::pow((x - avg) / sd, 3);
    }
    
    // Adjusted Fisher-Pearson standardized moment coefficient
    return (n / (double)((n - 1) * (n - 2))) * sum_cubed;
}

// Min-Max Normalization
auto StatLib::Normalize(const std::vector<double>& A) -> std::vector<double> {
    if (A.empty()) return {};
    
    auto [min_it, max_it] = std::minmax_element(A.begin(), A.end());
    double min_val = *min_it;
    double range = *max_it - min_val;

    std::vector<double> result;
    result.reserve(A.size()); // Pre-allocate memory for performance
    for (auto x : A) {
        result.push_back(range == 0 ? 0 : (x - min_val) / range);
    }
    return result;
}
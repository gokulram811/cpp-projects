#ifndef STATLIB_HPP
#define STATLIB_HPP

#include <vector>

/**
 * @class StatLib
 * @brief A collection of static methods for common statistical operations.
 */
class StatLib {
public:
    // Prevent instantiation since this is a utility library
    StatLib() = delete;

    /**
     * Calculates the arithmetic mean.
     * @param A Vector of data points.
     */
    static auto Mean(const std::vector<double>& A) -> double;

    /**
     * Calculates the median. Uses O(n) partial selection.
     * @param A Passed by value to allow internal reordering/sorting.
     */
    static auto Median(std::vector<double> A) -> double;

    /**
     * Calculates the sample variance (N-1).
     * @param A Vector of data points.
     */
    static auto Variance(const std::vector<double>& A) -> double;

    /**
     * Calculates the standard deviation (sqrt of variance).
     * @param A Vector of data points.
     */
    static auto StandardDeviation(const std::vector<double>& A) -> double;

    /**
     * Calculates Adjusted Fisher-Pearson Skewness.
     * @param A Vector of data points.
     */
    static auto Skewness(const std::vector<double>& A) -> double;

    /**
     * Performs Min-Max Normalization (scales data to [0, 1]).
     * @param A Vector of data points.
     * @return A new vector containing the normalized values.
     */
    static auto Normalize(const std::vector<double>& A) -> std::vector<double>;
};

#endif // STATLIB_HPP
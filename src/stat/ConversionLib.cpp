#include "stat/ConversionLib.hpp"
#include <numeric>
#include <cmath>
#include <sstream>

// Decimal to Fraction logic
auto ConversionLib::deci2frac(double decimal) -> std::string {
    const long precision = 1000000; 
    long numerator = std::round(decimal * precision);
    long denominator = precision;

    long common_divisor = std::gcd(numerator, denominator);

    numerator /= common_divisor;
    denominator /= common_divisor;

    return std::to_string(numerator) + "/" + std::to_string(denominator);
}

// Fraction to Decimal logic
auto ConversionLib::frac2deci(std::string_view fraction) -> std::optional<double> {
    std::string s(fraction);
    size_t slash_pos = s.find('/');
    
    if (slash_pos == std::string::npos) return std::nullopt;

    try {
        double num = std::stod(s.substr(0, slash_pos));
        double den = std::stod(s.substr(slash_pos + 1));

        if (den == 0) return std::nullopt; // Prevent division by zero
        return num / den;
    } catch (...) {
        return std::nullopt; // Handle non-numeric input
    }
}
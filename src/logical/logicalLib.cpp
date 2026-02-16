#include "logical/LogicalLib.hpp"

namespace Logical {

    auto NOT(bool condition) -> bool { 
        return !condition; 
    }

    auto colon_operator(double start, double interval, double end) -> std::vector<double> {
        std::vector<double> result;
        // Optimization: prevent infinite loops if interval is 0 or negative
        if (interval <= 0) return result; 

        for (double i = start; i <= end; i += interval) {
            result.push_back(i);
        }
        return result;
    }

    auto is_nan(double value) -> bool {
        return std::isnan(value);
    }
}
#pragma once
#include <vector>
#include <algorithm>
#include <cmath>

namespace Logical {
    // 1. Boolean NOT logic
    auto NOT(bool condition) -> bool;

    // 2. Membership: Templates must stay in header for instantiation
    template <typename T>
    bool in(const T& element, const std::vector<T>& container) {
        return std::find(container.begin(), container.end(), element) != container.end();
    }

    // 3. Exclusion
    template <typename T>
    bool not_in(const T& element, const std::vector<T>& container) {
        return std::find(container.begin(), container.end(), element) == container.end();
    }

    // 4. Sequence Generation (Colon Operator)
    auto colon_operator(double start, double interval, double end) -> std::vector<double>;

    // 5. Status Checks
    template <typename T>
    bool is_empty(const std::vector<T>& container) {
        return container.empty();
    }

    auto is_nan(double value) -> bool;
}
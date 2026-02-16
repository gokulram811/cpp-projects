#include "trig/TrigLib.hpp"

namespace Trig {


    auto to_radians(double degrees) -> double {
        return degrees * DEG_TO_RAD;
    }

    auto sin(double x, bool is_degrees) -> double {
        if (is_degrees) x = to_radians(x);
        return std::sin(x);
    }

    auto cos(double x, bool is_degrees) -> double {
        if (is_degrees) x = to_radians(x);
        return std::cos(x);
    }

    auto tan(double x, bool is_degrees) -> double {
        if (is_degrees) x = to_radians(x);
        return std::tan(x);
    }
    // Wrappers
    auto sin(double x) -> double { return std::sin(x); }
    auto cos(double x) -> double { return std::cos(x); }
    auto tan(double x) -> double { return std::tan(x); }

    // Reciprocals (with basic safety)
    auto cosec(double x) -> double { return 1.0 / std::sin(x); }
    auto sec(double x) -> double { return 1.0 / std::cos(x); }
    auto cot(double x) -> double { return 1.0 / std::tan(x); }

    // Inverses
    auto inv_sin(double x) -> double { return std::asin(x); }
    auto inv_cos(double x) -> double { return std::acos(x); }
    auto inv_tan(double x) -> double { return std::atan(x); }
    auto inv_cosec(double x) -> double { return std::asin(1.0 / x); }
    auto inv_sec(double x) -> double { return std::acos(1.0 / x); }
    auto inv_cot(double x) -> double { return std::atan(1.0 / x); }

    // Hyperbolics
    auto sinh(double x) -> double { return std::sinh(x); }
    auto cosh(double x) -> double { return std::cosh(x); }
    auto tanh(double x) -> double { return std::tanh(x); }
    auto cosech(double x) -> double { return 1.0 / std::sinh(x); }
    auto sech(double x) -> double { return 1.0 / std::cosh(x); }
    auto coth(double x) -> double { return 1.0 / std::tanh(x); }
}
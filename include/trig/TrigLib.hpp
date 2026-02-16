#pragma once
#include <cmath>
#include <numbers> // C++20 for high-precision PI

namespace Trig {
    // Conversion Factor: pi / 180
    static constexpr double DEG_TO_RAD = std::numbers::pi / 180.0;

    // Conversion Utility
    auto to_radians(double degrees) -> double;

    // Basic Functions
    auto sin(double x, bool is_degrees = false) -> double;
    auto cos(double x, bool is_degrees = false) -> double;
    auto tan(double x, bool is_degrees = false) -> double;

    auto sin(double x) -> double;
    auto cos(double x) -> double;
    auto tan(double x) -> double;

    // Reciprocal Functions
    auto cosec(double x) -> double;
    auto sec(double x) -> double;
    auto cot(double x) -> double;

    // Inverse Functions
    auto inv_sin(double x) -> double;
    auto inv_cos(double x) -> double;
    auto inv_tan(double x) -> double;
    auto inv_cosec(double x) -> double;
    auto inv_sec(double x) -> double;
    auto inv_cot(double x) -> double;

    // Hyperbolic Functions
    auto sinh(double x) -> double;
    auto cosh(double x) -> double;
    auto tanh(double x) -> double;
    auto cosech(double x) -> double;
    auto sech(double x) -> double;
    auto coth(double x) -> double;

   
}
#pragma once
#include <string>
#include <string_view>
#include <optional>

class ConversionLib {
public:
    ConversionLib() = delete; // Utility class pattern

    // Converts 0.75 -> "3/4"
    static auto deci2frac(double decimal) -> std::string;

    // Converts "3/4" -> 0.75
    static auto frac2deci(std::string_view fraction) -> std::optional<double>;
};
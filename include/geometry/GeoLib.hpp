#pragma once
#include <numbers>
#include <cmath>

// Define selectable output types
enum class Measure { Area, Perimeter, Volume, SurfaceArea };

class Geometry {
public:
    static constexpr double PI = std::numbers::pi;
    
    // 2D Functions now take a Measure parameter
    static auto Char_Circle(double r, Measure m) -> double;
    static auto Char_Square(double a, Measure m) -> double;
    static auto Char_Rectangle(double b, double h, Measure m) -> double;
    static auto Char_Triangle(double a, Measure m) -> double;
    static auto Char_Trapezoid(double a, double b, double h, Measure m) -> double;
    static auto Char_Polygon(double a, int n, Measure m) -> double;

    // 3D Functions
    static auto Char_Sphere(double r, Measure m) -> double;
    static auto Char_Cylinder(double r, double h, Measure m) -> double;
    static auto Char_Cube(double a, Measure m) -> double;

private:
    static auto to_rad(double deg) -> double { return deg * (PI / 180.0); }
};
#include "geometry/GeoLib.hpp"

// --- 2D SHAPES ---

auto Geometry::Char_Circle(double r, Measure m) -> double {
    if (m == Measure::Area) return PI * r * r;
    if (m == Measure::Perimeter) return 2 * PI * r;
    return 0.0;
}

auto Geometry::Char_Square(double a, Measure m) -> double {
    return (m == Measure::Area) ? (a * a) : (4 * a);
}

auto Geometry::Char_Rectangle(double b, double h, Measure m) -> double {
    return (m == Measure::Area) ? (b * h) : (2 * (b + h));
}

auto Geometry::Char_Triangle(double a, Measure m) -> double {
    return (m == Measure::Area) ? ((std::sqrt(3) / 4) * a * a) : (3 * a);
}

auto Geometry::Char_Trapezoid(double a, double b, double h, Measure m) -> double {
    if (m == Measure::Area) return ((a + b) / 2.0) * h;
    double leg = std::sqrt(h * h + std::pow((std::abs(b - a) / 2.0), 2));
    return a + b + (2 * leg);
}

auto Geometry::Char_Polygon(double a, int n, Measure m) -> double {
    if (n < 3) return 0.0;
    if (m == Measure::Area) return (n * a * a) / (4 * std::tan(PI / n));
    return static_cast<double>(n) * a;
}

// --- 3D SHAPES ---

auto Geometry::Char_Sphere(double r, Measure m) -> double {
    if (m == Measure::Volume) return (4.0/3.0) * PI * std::pow(r, 3);
    if (m == Measure::SurfaceArea) return 4 * PI * r * r;
    return 0.0;
}

auto Geometry::Char_Cylinder(double r, double h, Measure m) -> double {
    if (m == Measure::Volume) return PI * r * r * h;
    if (m == Measure::SurfaceArea) return 2 * PI * r * (r + h);
    return 0.0;
}

auto Geometry::Char_Cube(double a, Measure m) -> double {
    return (m == Measure::Volume) ? std::pow(a, 3) : (6 * a * a);
}
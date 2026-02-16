#ifndef UNICON_HPP
#define UNICON_HPP

namespace UniCon {
    namespace Maths {
        constexpr double pi = 3.141592653589793;
    }

    namespace Physics {
        constexpr double g = 9.80665;               // Gravity
        constexpr double G = 6.67430e-11;           // Gravitational Constant
        constexpr double h = 6.62607e-34;           // Planck's Constant
        constexpr double c = 299792458.0;           // Light speed
        constexpr double sigma = 5.67037e-8;        // Stefan-Boltzmann
        constexpr double ke = 8.98755e9;            // Coulomb Constant
    }

    namespace Chemistry {
        constexpr double R = 8.31446;               // Gas Constant
        constexpr double Na = 6.02214e23;           // Avogadro's Number
    }

    namespace Particle {
        constexpr double me = 9.10938e-31;          // Electron Mass
        constexpr double mp = 1.67262e-27;          // Proton Mass
        constexpr double e = 1.60217e-19;           // Elementary Charge
    }
}

#endif
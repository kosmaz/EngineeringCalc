//math header file for all math class operations
#ifndef MATH_H
#define MATH_H

//required header files for all math class
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>

//global functions for all class
inline void pausescreen(){system("pause");}
inline void clearscreen(){system("cls");}

//math/engineering constants
const float pi=3.1415926535; //no unit 'π'
const float gravitational_acc=9.807; //m/s^2 'g'
const float avogadros_no=6.024e23; //molecules/mol 'N'
const float planks_constant=6.625e-34; //J·s/molecule 'h'
const float boltzmans_constant=1.380e-23; //J/K·molecule 'k'
const float speed_of_light=2.998e8; //m/s 'c'
const float atmospheric_pressure=101325; //N/m2 'p'
const float charge_density=1.081202317e12; //C/m^3 
const float conductance_quantum=7.748091733e-5; //s 'G0'
const float current=6.62361782e-3; //Ω
const float electron_charge_mass_ratio=1.75882012e11; //c/kg 'e/Me'
const float electric_dipole_moment=8.47835309e-30; //C.m
const float electric_field=5.14220642e11; //V/m
const float electric_field_gradient=9.71736182e21; //V/m^2
const float electric_potential=27.2113845; //V
const float electric_volt=1.60217653e-19; //J 'eV'
const float electric_charge=1.60217653e-19; //C 'e'
const float freespace_impedance=376.730313461; //Ω 'Z0' (120π)
const float magnetic_flux_quantum=2.06783372e-15; //Wb 'Φ0'
const float magnetic_flux_density=4.48655124e-40; //C.m^2
const float magnetic_flux_dipole_moment=1.85480190e-23; //J/T
const float permebility_of_freespace=1.2566370614e-6; //H/m 'μ0'
const float permitivity_of_freespace=8.854187817e-12; //F/m 'ε0'

#endif //MATH_H

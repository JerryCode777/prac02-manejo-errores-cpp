#ifndef ALUMNO_H
#define ALUMNO_H

#include <string>

// Datos de un alumno del registro.
struct Alumno {
    std::string codigo;  // CUI de 8 dígitos
    std::string nombre;  // solo letras y espacios
    int edad = 0;        // 15 a 99
    double nota = 0.0;   // 0 a 20
};

#endif

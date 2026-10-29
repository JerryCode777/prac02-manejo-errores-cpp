#ifndef ENTRADA_H
#define ENTRADA_H

#include <string>

// Responsable: Fernando
// Lectura y validación de los datos que ingresa el usuario.
// Todas las funciones lanzan EntradaInvalidaException si el dato no es válido.

// Muestra `mensaje` y lee una línea completa de la entrada estándar.
// Lanza EntradaInvalidaException si la entrada se cerró (EOF).
std::string leerLinea(const std::string& mensaje);

// Convierte `texto` a un entero dentro de [min, max].
int convertirEntero(const std::string& texto, const std::string& campo, int min, int max);

// Convierte `texto` a una nota entre 0 y 20.
double convertirNota(const std::string& texto);

// Verifica que el código tenga exactamente 8 dígitos.
std::string validarCodigo(const std::string& texto);

// Verifica que el nombre no esté vacío y contenga solo letras y espacios.
std::string validarNombre(const std::string& texto);

#endif

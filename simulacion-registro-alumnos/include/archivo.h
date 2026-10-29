#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <string>
#include <vector>

#include "alumno.h"

// Responsable: Diego
// Persistencia del registro en un archivo de texto.
// Formato: una línea por alumno -> codigo;nombre;edad;nota
// Las líneas vacías y las que empiezan con # se ignoran.

// Lanza ArchivoNoEncontradoException si el archivo no se puede abrir.
// Lanza ArchivoCorruptoException si una línea no tiene 4 campos o sus datos son inválidos.
std::vector<Alumno> cargarAlumnos(const std::string& ruta);

// Lanza RegistroException si el archivo no se puede escribir.
void guardarAlumnos(const std::string& ruta, const std::vector<Alumno>& alumnos);

#endif

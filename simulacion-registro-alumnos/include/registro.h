#ifndef REGISTRO_H
#define REGISTRO_H

#include <string>
#include <vector>

#include "alumno.h"

// Responsable: Gabriel
// Registro de alumnos en memoria.
class RegistroAlumnos {
public:
    // Lanza AlumnoDuplicadoException si el código ya existe.
    void agregar(const Alumno& alumno);

    // Lanza AlumnoNoEncontradoException si el código no existe.
    const Alumno& buscar(const std::string& codigo) const;

    // Lanza AlumnoNoEncontradoException si el código no existe.
    void eliminar(const std::string& codigo);

    const std::vector<Alumno>& listar() const;

    // Sustituye todo el registro, por ejemplo al cargar desde archivo.
    void reemplazar(const std::vector<Alumno>& alumnos);

private:
    std::vector<Alumno> alumnos_;
};

#endif

#include "registro.h"

#include <algorithm>

#include "excepciones.h"

// Responsable: Gabriel
void RegistroAlumnos::agregar(const Alumno& alumno) {
    const auto encontrado = std::find_if(alumnos_.begin(), alumnos_.end(),
        [&](const Alumno& a) { return a.codigo == alumno.codigo; });
    if (encontrado != alumnos_.end()) {
        throw AlumnoDuplicadoException(alumno.codigo);
    }
    alumnos_.push_back(alumno);
}

const Alumno& RegistroAlumnos::buscar(const std::string& codigo) const {
    const auto encontrado = std::find_if(alumnos_.begin(), alumnos_.end(),
        [&](const Alumno& a) { return a.codigo == codigo; });
    if (encontrado == alumnos_.end()) {
        throw AlumnoNoEncontradoException(codigo);
    }
    return *encontrado;
}

void RegistroAlumnos::eliminar(const std::string& codigo) {
    const auto encontrado = std::find_if(alumnos_.begin(), alumnos_.end(),
        [&](const Alumno& a) { return a.codigo == codigo; });
    if (encontrado == alumnos_.end()) {
        throw AlumnoNoEncontradoException(codigo);
    }
    alumnos_.erase(encontrado);
}

const std::vector<Alumno>& RegistroAlumnos::listar() const { return alumnos_; }

void RegistroAlumnos::reemplazar(const std::vector<Alumno>& alumnos) { alumnos_ = alumnos; }

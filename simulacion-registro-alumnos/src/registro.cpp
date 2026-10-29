#include "registro.h"

#include <stdexcept>

#include "excepciones.h"

// Responsable: Gabriel
// TODO: implementar agregar, buscar y eliminar.
//   - agregar: si ya existe un alumno con el mismo código -> throw AlumnoDuplicadoException(codigo)
//   - buscar / eliminar: si no existe -> throw AlumnoNoEncontradoException(codigo)
// Sugerencia: usar std::find_if de <algorithm> para buscar por código.

void RegistroAlumnos::agregar([[maybe_unused]] const Alumno& alumno) {
    throw std::logic_error("Pendiente de implementar: RegistroAlumnos::agregar");
}

const Alumno& RegistroAlumnos::buscar([[maybe_unused]] const std::string& codigo) const {
    throw std::logic_error("Pendiente de implementar: RegistroAlumnos::buscar");
}

void RegistroAlumnos::eliminar([[maybe_unused]] const std::string& codigo) {
    throw std::logic_error("Pendiente de implementar: RegistroAlumnos::eliminar");
}

const std::vector<Alumno>& RegistroAlumnos::listar() const { return alumnos_; }

void RegistroAlumnos::reemplazar(const std::vector<Alumno>& alumnos) { alumnos_ = alumnos; }

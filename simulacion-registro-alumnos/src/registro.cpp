// Operaciones del registro de alumnos en memoria.
// Cuando una operación no se puede completar, se informa lanzando una excepción
// personalizada en lugar de devolver un código de error.
#include "registro.h"

#include <algorithm>

#include "excepciones.h"

// Responsable: Gabriel
// Agrega un alumno nuevo. Si el código ya existe, lanza AlumnoDuplicadoException
// y el registro no cambia.
void RegistroAlumnos::agregar(const Alumno& alumno) {
    // std::find_if recorre el vector y devuelve el primer alumno que cumple la condición
    // de la lambda; si no encuentra ninguno, devuelve alumnos_.end().
    const auto encontrado = std::find_if(alumnos_.begin(), alumnos_.end(),
        [&](const Alumno& a) { return a.codigo == alumno.codigo; });
    if (encontrado != alumnos_.end()) {
        throw AlumnoDuplicadoException(alumno.codigo);
    }
    alumnos_.push_back(alumno);
}

// Devuelve una referencia constante: el alumno se puede leer, pero no modificar.
// Si el código no existe, lanza AlumnoNoEncontradoException.
const Alumno& RegistroAlumnos::buscar(const std::string& codigo) const {
    const auto encontrado = std::find_if(alumnos_.begin(), alumnos_.end(),
        [&](const Alumno& a) { return a.codigo == codigo; });
    if (encontrado == alumnos_.end()) {
        throw AlumnoNoEncontradoException(codigo);
    }
    return *encontrado;
}

// Elimina el alumno con el código indicado o lanza AlumnoNoEncontradoException.
void RegistroAlumnos::eliminar(const std::string& codigo) {
    const auto encontrado = std::find_if(alumnos_.begin(), alumnos_.end(),
        [&](const Alumno& a) { return a.codigo == codigo; });
    if (encontrado == alumnos_.end()) {
        throw AlumnoNoEncontradoException(codigo);
    }
    alumnos_.erase(encontrado);
}

// Devuelve todos los alumnos sin copiarlos (referencia constante).
const std::vector<Alumno>& RegistroAlumnos::listar() const { return alumnos_; }

// Sustituye todo el contenido, por ejemplo después de cargar el archivo.
void RegistroAlumnos::reemplazar(const std::vector<Alumno>& alumnos) { alumnos_ = alumnos; }

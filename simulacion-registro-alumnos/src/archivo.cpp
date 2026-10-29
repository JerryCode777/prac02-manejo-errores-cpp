#include "archivo.h"

#include <fstream>
#include <stdexcept>

#include "entrada.h"
#include "excepciones.h"

// Responsable: Diego
// TODO: implementar la carga y el guardado.
//   - cargarAlumnos:
//       * si std::ifstream no abre el archivo -> throw ArchivoNoEncontradoException(ruta)
//       * leer línea por línea llevando el número de línea; ignorar vacías y las que empiezan con #
//       * separar por ';' (std::getline sobre un std::stringstream); si no hay 4 campos
//         -> throw ArchivoCorruptoException(ruta, linea, "se esperaban 4 campos")
//       * validar cada campo con las funciones de entrada.h; si alguna lanza
//         EntradaInvalidaException, capturarla y relanzar ArchivoCorruptoException(ruta, linea, e.what())
//   - guardarAlumnos:
//       * si std::ofstream no abre el archivo -> throw RegistroException("No se pudo escribir " + ruta)
//       * escribir una línea por alumno con el formato codigo;nombre;edad;nota

std::vector<Alumno> cargarAlumnos([[maybe_unused]] const std::string& ruta) {
    throw std::logic_error("Pendiente de implementar: cargarAlumnos");
}

void guardarAlumnos([[maybe_unused]] const std::string& ruta, [[maybe_unused]] const std::vector<Alumno>& alumnos) {
    throw std::logic_error("Pendiente de implementar: guardarAlumnos");
}

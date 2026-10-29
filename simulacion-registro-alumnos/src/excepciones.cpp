#include "excepciones.h"

// Responsable: Gabriel
// TODO: cada constructor debe armar un mensaje claro para el usuario, por ejemplo:
//   EntradaInvalidaException("edad", "debe ser un número entero")
//       -> "edad: debe ser un número entero"
//   ArchivoNoEncontradoException("data/alumnos.csv")
//       -> "No se encontró el archivo data/alumnos.csv"
//   ArchivoCorruptoException("data/alumnos.csv", 3, "faltan campos")
//       -> "El archivo data/alumnos.csv está dañado en la línea 3: faltan campos"
//   AlumnoNoEncontradoException("20231234")
//       -> "No existe un alumno con el código 20231234"
//   AlumnoDuplicadoException("20231234")
//       -> "Ya existe un alumno con el código 20231234"
// Reemplazar los textos "TODO" por esos mensajes.

RegistroException::RegistroException(const std::string& mensaje)
    : std::runtime_error(mensaje) {}

EntradaInvalidaException::EntradaInvalidaException(const std::string& campo,
                                                   [[maybe_unused]] const std::string& detalle)
    : RegistroException("TODO"), campo_(campo) {}

const std::string& EntradaInvalidaException::campo() const { return campo_; }

ArchivoNoEncontradoException::ArchivoNoEncontradoException([[maybe_unused]] const std::string& ruta)
    : RegistroException("TODO") {}

ArchivoCorruptoException::ArchivoCorruptoException([[maybe_unused]] const std::string& ruta, int linea,
                                                   [[maybe_unused]] const std::string& detalle)
    : RegistroException("TODO"), linea_(linea) {}

int ArchivoCorruptoException::linea() const { return linea_; }

AlumnoNoEncontradoException::AlumnoNoEncontradoException([[maybe_unused]] const std::string& codigo)
    : RegistroException("TODO") {}

AlumnoDuplicadoException::AlumnoDuplicadoException([[maybe_unused]] const std::string& codigo)
    : RegistroException("TODO") {}

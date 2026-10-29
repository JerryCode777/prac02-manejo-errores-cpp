#include "excepciones.h"

// Responsable: Gabriel
// Cada excepción conserva un mensaje descriptivo, disponible mediante what().
RegistroException::RegistroException(const std::string& mensaje)
    : std::runtime_error(mensaje) {}

EntradaInvalidaException::EntradaInvalidaException(const std::string& campo,
                                                 const std::string& detalle)
    : RegistroException(campo + ": " + detalle), campo_(campo) {}

const std::string& EntradaInvalidaException::campo() const { return campo_; }

ArchivoNoEncontradoException::ArchivoNoEncontradoException(const std::string& ruta)
    : RegistroException("No se encontró el archivo " + ruta) {}

ArchivoCorruptoException::ArchivoCorruptoException(const std::string& ruta, int linea,
                                                 const std::string& detalle)
    : RegistroException("El archivo " + ruta + " está dañado en la línea "
                        + std::to_string(linea) + ": " + detalle), linea_(linea) {}

int ArchivoCorruptoException::linea() const { return linea_; }

AlumnoNoEncontradoException::AlumnoNoEncontradoException(const std::string& codigo)
    : RegistroException("No existe un alumno con el código " + codigo) {}

AlumnoDuplicadoException::AlumnoDuplicadoException(const std::string& codigo)
    : RegistroException("Ya existe un alumno con el código " + codigo) {}

#include "excepciones.h"

// Responsable: Gabriel
// Cada excepción conserva un mensaje descriptivo, disponible mediante what().
// Clase base: hereda de std::runtime_error, que guarda el mensaje y lo devuelve con what().
RegistroException::RegistroException(const std::string& mensaje)
    : std::runtime_error(mensaje) {}

// El mensaje combina el campo y el motivo, por ejemplo "edad: El valor ingresado no es...".
// Además se guarda el campo por si quien captura necesita saber qué dato falló.
EntradaInvalidaException::EntradaInvalidaException(const std::string& campo,
                                                 const std::string& detalle)
    : RegistroException(campo + ": " + detalle), campo_(campo) {}

const std::string& EntradaInvalidaException::campo() const { return campo_; }

// Se lanza cuando el archivo de datos no existe o no se puede abrir.
ArchivoNoEncontradoException::ArchivoNoEncontradoException(const std::string& ruta)
    : RegistroException("No se encontró el archivo " + ruta) {}

// Incluye el número de línea para que el usuario sepa dónde está el dato dañado.
ArchivoCorruptoException::ArchivoCorruptoException(const std::string& ruta, int linea,
                                                 const std::string& detalle)
    : RegistroException("El archivo " + ruta + " está dañado en la línea "
                        + std::to_string(linea) + ": " + detalle), linea_(linea) {}

int ArchivoCorruptoException::linea() const { return linea_; }

// Excepción del dominio: se lanza al buscar o eliminar un código que no está registrado.
AlumnoNoEncontradoException::AlumnoNoEncontradoException(const std::string& codigo)
    : RegistroException("No existe un alumno con el código " + codigo) {}

// Se lanza al registrar un código que ya existe, para no tener dos alumnos con el mismo CUI.
AlumnoDuplicadoException::AlumnoDuplicadoException(const std::string& codigo)
    : RegistroException("Ya existe un alumno con el código " + codigo) {}

#ifndef EXCEPCIONES_H
#define EXCEPCIONES_H

#include <stdexcept>
#include <string>

// Responsable: Gabriel
// Excepciones personalizadas del sistema. Todas heredan de RegistroException
// para poder capturarlas juntas cuando convenga.

class RegistroException : public std::runtime_error {
public:
    explicit RegistroException(const std::string& mensaje);
};

// Dato ingresado con formato o rango inválido.
class EntradaInvalidaException : public RegistroException {
public:
    EntradaInvalidaException(const std::string& campo, const std::string& detalle);
    const std::string& campo() const;

private:
    std::string campo_;
};

// El archivo de datos no existe o no se puede abrir.
class ArchivoNoEncontradoException : public RegistroException {
public:
    explicit ArchivoNoEncontradoException(const std::string& ruta);
};

// Una línea del archivo de datos no tiene el formato esperado.
class ArchivoCorruptoException : public RegistroException {
public:
    ArchivoCorruptoException(const std::string& ruta, int linea, const std::string& detalle);
    int linea() const;

private:
    int linea_;
};

// No existe un alumno con el código buscado.
class AlumnoNoEncontradoException : public RegistroException {
public:
    explicit AlumnoNoEncontradoException(const std::string& codigo);
};

// Ya existe un alumno con ese código.
class AlumnoDuplicadoException : public RegistroException {
public:
    explicit AlumnoDuplicadoException(const std::string& codigo);
};

#endif

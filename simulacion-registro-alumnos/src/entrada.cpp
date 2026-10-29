#include "entrada.h"

#include <iostream>
#include <stdexcept>

#include "excepciones.h"

// Responsable: Fernando
// TODO: implementar las validaciones. Todas lanzan EntradaInvalidaException(campo, detalle).
//   - leerLinea: si std::getline falla (EOF) -> lanzar la excepción.
//   - convertirEntero: usar std::stoi(texto, &pos) dentro de try y capturar
//       std::invalid_argument (no es número) y std::out_of_range (número demasiado grande).
//       Verificar también que pos == texto.size() ("12abc" no es válido) y el rango [min, max].
//   - convertirNota: igual con std::stod, rango 0 a 20.
//   - validarCodigo: exactamente 8 dígitos (std::isdigit).
//   - validarNombre: no vacío; solo letras y espacios (permitir tildes y ñ).

std::string leerLinea(const std::string& mensaje) {
    std::cout << mensaje;
    std::string linea;
    std::getline(std::cin, linea);  // TODO: lanzar EntradaInvalidaException si falla
    return linea;
}

int convertirEntero([[maybe_unused]] const std::string& texto, [[maybe_unused]] const std::string& campo,
                    [[maybe_unused]] int min, [[maybe_unused]] int max) {
    throw std::logic_error("Pendiente de implementar: convertirEntero");
}

double convertirNota([[maybe_unused]] const std::string& texto) {
    throw std::logic_error("Pendiente de implementar: convertirNota");
}

std::string validarCodigo([[maybe_unused]] const std::string& texto) {
    throw std::logic_error("Pendiente de implementar: validarCodigo");
}

std::string validarNombre([[maybe_unused]] const std::string& texto) {
    throw std::logic_error("Pendiente de implementar: validarNombre");
}

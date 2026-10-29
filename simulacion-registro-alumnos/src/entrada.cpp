#include "entrada.h"

#include <cctype>
#include <iostream>
#include <stdexcept>

#include "excepciones.h"

// Responsable: Fernando

std::string leerLinea(const std::string& mensaje) {
    std::cout << mensaje;
    std::string linea;
    if (!std::getline(std::cin, linea)) {
        throw EntradaInvalidaException("lectura", "Error al leer entrada (se alcanzo EOF o fallo la lectura)");
    }
    return linea;
}

int convertirEntero(const std::string& texto, const std::string& campo, int min, int max) {
    std::size_t pos = 0;
    int valor = 0;

    try {
        valor = std::stoi(texto, &pos);
    } catch (const std::invalid_argument&) {
        throw EntradaInvalidaException(campo, "El valor ingresado no es un numero entero valido");
    } catch (const std::out_of_range&) {
        throw EntradaInvalidaException(campo, "El numero ingresado esta fuera del rango soportado");
    }

    if (pos != texto.size()) {
        throw EntradaInvalidaException(campo, "El texto contiene caracteres no validos");
    }

    if (valor < min || valor > max) {
        throw EntradaInvalidaException(campo, "El valor debe estar entre " + std::to_string(min) + " y " + std::to_string(max));
    }

    return valor;
}

double convertirNota(const std::string& texto) {
    std::size_t pos = 0;
    double valor = 0.0;

    try {
        valor = std::stod(texto, &pos);
    } catch (const std::invalid_argument&) {
        throw EntradaInvalidaException("nota", "El valor ingresado no es un numero decimal valido");
    } catch (const std::out_of_range&) {
        throw EntradaInvalidaException("nota", "La nota ingresada esta fuera de rango");
    }

    if (pos != texto.size()) {
        throw EntradaInvalidaException("nota", "La nota contiene caracteres no validos");
    }

    if (valor < 0.0 || valor > 20.0) {
        throw EntradaInvalidaException("nota", "La nota debe estar en el rango de 0 a 20");
    }

    return valor;
}

std::string validarCodigo(const std::string& texto) {
    if (texto.size() != 8) {
        throw EntradaInvalidaException("codigo", "El codigo debe tener exactamente 8 digitos");
    }

    for (char c : texto) {
        if (!std::isdigit(static_cast<unsigned char>(c))) {
            throw EntradaInvalidaException("codigo", "El codigo debe contener únicamente digitos numericos");
        }
    }

    return texto;
}

std::string validarNombre(const std::string& texto) {
    if (texto.empty()) {
        throw EntradaInvalidaException("nombre", "El nombre no puede estar vacio");
    }

    for (char c : texto) {
        unsigned char uc = static_cast<unsigned char>(c);
        // Se permiten letras ASCII, espacios y bytes multibyte (>= 128) para soportar UTF-8 (tildes, ñ, Ñ)
        if (!std::isalpha(uc) && !std::isspace(uc) && uc < 128) {
            throw EntradaInvalidaException("nombre", "El nombre solo puede contener letras y espacios");
        }
    }

    return texto;
}

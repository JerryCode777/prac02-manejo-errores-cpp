#include "archivo.h"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>

#include "entrada.h"
#include "excepciones.h"

std::vector<Alumno> cargarAlumnos(const std::string& ruta) {
    std::ifstream archivo(ruta);
    if (!archivo.is_open()) {
        throw ArchivoNoEncontradoException(ruta);
    }

    std::vector<Alumno> alumnos;
    std::string linea;
    int numeroLinea = 0;

    while (std::getline(archivo, linea)) {
        numeroLinea++;

        // Ignorar líneas vacías o comentarios que empiezan con '#' 
        // (omitiendo espacios en blanco iniciales si los hubiera)
        size_t inicio = linea.find_first_not_of(" \t\r\n");
        if (inicio == std::string::npos || linea[inicio] == '#') {
            continue;
        }

        std::stringstream ss(linea);
        std::string campo;
        std::vector<std::string> campos;

        while (std::getline(ss, campo, ';')) {
            campos.push_back(campo);
        }

        if (campos.size() != 4) {
            throw ArchivoCorruptoException(ruta, numeroLinea, "se esperaban 4 campos");
        }

        try {
            // Validar cada campo usando las funciones de entrada.h.
            Alumno alumno;
            alumno.codigo = validarCodigo(campos[0]);
            alumno.nombre = validarNombre(campos[1]);
            alumno.edad = convertirEntero(campos[2], "edad", 15, 99);
            alumno.nota = convertirNota(campos[3]);

            alumnos.push_back(alumno);

        } catch (const EntradaInvalidaException& e) {
            throw ArchivoCorruptoException(ruta, numeroLinea, e.what());
        }
    }

    return alumnos;
}

void guardarAlumnos(const std::string& ruta, const std::vector<Alumno>& alumnos) {
    std::ofstream archivo(ruta);
    if (!archivo.is_open()) {
        throw RegistroException("No se pudo escribir " + ruta);
    }

    for (const auto& alumno : alumnos) {
        // Escribe en formato: codigo;nombre;edad;nota
        archivo << alumno.codigo << ";"
                << alumno.nombre << ";"
                << alumno.edad << ";"
                << alumno.nota << "\n";
    }
}

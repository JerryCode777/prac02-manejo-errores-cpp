// Persistencia del registro en un archivo de texto con el formato codigo;nombre;edad;nota.
// Los problemas con el archivo se informan con excepciones personalizadas:
//   - ArchivoNoEncontradoException si no se puede abrir.
//   - ArchivoCorruptoException si una línea no tiene el formato esperado.
#include "archivo.h"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>

#include "entrada.h"
#include "excepciones.h"

// Lee todos los alumnos del archivo. Si una sola línea está dañada se lanza la
// excepción y no se carga nada, para no trabajar con datos incompletos.
std::vector<Alumno> cargarAlumnos(const std::string& ruta) {
    std::ifstream archivo(ruta);
    if (!archivo.is_open()) {
        throw ArchivoNoEncontradoException(ruta);
    }

    std::vector<Alumno> alumnos;
    std::string linea;
    // Se cuenta el número de línea para indicarlo en el mensaje de error.
    int numeroLinea = 0;

    while (std::getline(archivo, linea)) {
        numeroLinea++;

        // Ignorar líneas vacías o comentarios que empiezan con '#' 
        // (omitiendo espacios en blanco iniciales si los hubiera)
        size_t inicio = linea.find_first_not_of(" \t\r\n");
        if (inicio == std::string::npos || linea[inicio] == '#') {
            continue;
        }

        // Separa la línea en campos usando ';' como delimitador.
        std::stringstream ss(linea);
        std::string campo;
        std::vector<std::string> campos;

        while (std::getline(ss, campo, ';')) {
            campos.push_back(campo);
        }

        // Cada línea debe tener exactamente código, nombre, edad y nota.
        if (campos.size() != 4) {
            throw ArchivoCorruptoException(ruta, numeroLinea, "se esperaban 4 campos");
        }

        // Si alguna validación falla, el catch transforma la EntradaInvalidaException en
        // ArchivoCorruptoException y le agrega la línea donde ocurrió.
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

// Sobrescribe el archivo con el contenido actual del registro.
void guardarAlumnos(const std::string& ruta, const std::vector<Alumno>& alumnos) {
    std::ofstream archivo(ruta);
    // Puede fallar si la carpeta no existe o no hay permisos de escritura.
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

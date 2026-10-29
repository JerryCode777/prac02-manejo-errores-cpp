// Sistema de registro de alumnos con manejo de errores.
// Responsable: Jerry (integración del menú y registro de errores)

#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "archivo.h"
#include "entrada.h"
#include "excepciones.h"
#include "registro.h"

namespace {

const std::string kRutaLog = "errores.log";

// Guarda los errores críticos en errores.log con fecha y hora.
void registrarError(const std::string& mensaje) {
    std::ofstream log(kRutaLog, std::ios::app);
    if (!log) {
        return;  // si no se puede escribir el log, el sistema sigue funcionando
    }
    std::time_t ahora = std::time(nullptr);
    log << std::put_time(std::localtime(&ahora), "%Y-%m-%d %H:%M:%S") << " | " << mensaje << '\n';
}

void mostrarEncabezado() {
    std::cout << std::left << std::setw(10) << "CODIGO" << std::setw(30) << "NOMBRE"
              << std::setw(6) << "EDAD" << "NOTA\n";
}

void mostrarAlumno(const Alumno& alumno) {
    std::cout << std::left << std::setw(10) << alumno.codigo << std::setw(30) << alumno.nombre
              << std::setw(6) << alumno.edad << std::fixed << std::setprecision(1) << alumno.nota << '\n';
}

void registrar(RegistroAlumnos& registro) {
    Alumno alumno;
    alumno.codigo = validarCodigo(leerLinea("Código (8 dígitos): "));
    alumno.nombre = validarNombre(leerLinea("Nombre: "));
    alumno.edad = convertirEntero(leerLinea("Edad: "), "edad", 15, 99);
    alumno.nota = convertirNota(leerLinea("Nota (0-20): "));
    registro.agregar(alumno);
    std::cout << "Alumno registrado.\n";
}

void buscar(const RegistroAlumnos& registro) {
    const Alumno& alumno = registro.buscar(validarCodigo(leerLinea("Código a buscar: ")));
    mostrarEncabezado();
    mostrarAlumno(alumno);
}

void listar(const RegistroAlumnos& registro) {
    if (registro.listar().empty()) {
        std::cout << "No hay alumnos registrados.\n";
        return;
    }
    mostrarEncabezado();
    for (const Alumno& alumno : registro.listar()) {
        mostrarAlumno(alumno);
    }
}

void eliminar(RegistroAlumnos& registro) {
    registro.eliminar(validarCodigo(leerLinea("Código a eliminar: ")));
    std::cout << "Alumno eliminado.\n";
}

void guardar(const RegistroAlumnos& registro, const std::string& ruta) {
    guardarAlumnos(ruta, registro.listar());
    std::cout << "Datos guardados en " << ruta << ".\n";
}

void cargar(RegistroAlumnos& registro, const std::string& ruta) {
    registro.reemplazar(cargarAlumnos(ruta));
    std::cout << "Se cargaron " << registro.listar().size() << " alumnos desde " << ruta << ".\n";
}

// Si el archivo no existe o está dañado, el sistema inicia con un registro vacío.
void cargaInicial(RegistroAlumnos& registro, const std::string& ruta) {
    try {
        cargar(registro, ruta);
    } catch (const ArchivoNoEncontradoException& e) {
        std::cout << "Aviso: " << e.what() << ". Se inicia con un registro vacío.\n";
    } catch (const ArchivoCorruptoException& e) {
        std::cout << "Error: " << e.what() << ". Se inicia con un registro vacío.\n";
        registrarError(e.what());
    } catch (const std::exception& e) {
        std::cout << "Error al cargar los datos: " << e.what() << ". Se inicia con un registro vacío.\n";
        registrarError(e.what());
    }
}

void mostrarMenu() {
    std::cout << "\n===== REGISTRO DE ALUMNOS =====\n"
              << "1. Registrar alumno\n"
              << "2. Buscar alumno\n"
              << "3. Listar alumnos\n"
              << "4. Eliminar alumno\n"
              << "5. Guardar en archivo\n"
              << "6. Cargar desde archivo\n"
              << "0. Salir\n"
              << "Opción: ";
}

}  // namespace

// Uso: registro_alumnos [ruta_del_archivo]   (por defecto data/alumnos.csv)
int main(int argc, char* argv[]) {
    const std::string ruta = argc > 1 ? argv[1] : "data/alumnos.csv";
    RegistroAlumnos registro;
    cargaInicial(registro, ruta);

    std::string opcion;
    while (true) {
        mostrarMenu();
        if (!std::getline(std::cin, opcion) || opcion == "0") {
            break;
        }
        try {
            if (opcion == "1") {
                registrar(registro);
            } else if (opcion == "2") {
                buscar(registro);
            } else if (opcion == "3") {
                listar(registro);
            } else if (opcion == "4") {
                eliminar(registro);
            } else if (opcion == "5") {
                guardar(registro, ruta);
            } else if (opcion == "6") {
                cargar(registro, ruta);
            } else {
                // Una opción equivocada es parte del flujo normal: se valida, no se lanza excepción.
                std::cout << "Opción no válida. Elija un número del 0 al 6.\n";
            }
        } catch (const EntradaInvalidaException& e) {
            std::cout << "Dato inválido -> " << e.what() << ". Operación cancelada.\n";
        } catch (const AlumnoNoEncontradoException& e) {
            std::cout << "Aviso: " << e.what() << ".\n";
        } catch (const AlumnoDuplicadoException& e) {
            std::cout << "Aviso: " << e.what() << ".\n";
        } catch (const RegistroException& e) {
            std::cout << "Error: " << e.what() << ".\n";
            registrarError(e.what());
        } catch (const std::exception& e) {
            std::cout << "Error inesperado: " << e.what() << ".\n";
            registrarError(std::string("Inesperado: ") + e.what());
        }
    }

    std::cout << "Sistema finalizado.\n";
    return 0;
}

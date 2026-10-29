// Práctica 1: División segura
// Responsable: Elkin
//
// Objetivo: evitar que el programa se detenga por división por cero.
// Indicaciones:
//   1. Pedir dos números al usuario.
//   2. Manejar el error de división por cero mostrando un mensaje adecuado.
//   3. Mostrar un mensaje de cierre equivalente a finally.
//
// Notas sobre C++:
//   - Dividir entre cero NO lanza una excepción en C++ (con enteros es comportamiento
//     indefinido y con double da inf). Hay que comprobar el divisor y lanzar la
//     excepción con throw, por ejemplo std::domain_error.
//   - C++ no tiene finally. Se simula con un objeto cuyo destructor muestra el mensaje
//     de cierre (RAII): el destructor se ejecuta siempre al salir del bloque, haya o no
//     excepción.
//   - Extra opcional: validar que lo ingresado sea un número (std::cin.fail()).

#include <iostream>
#include <stdexcept>

// TODO: función dividir(a, b) que lance std::domain_error si b == 0.

// TODO: struct MensajeCierre cuyo destructor imprima "Operación finalizada."

int main() {
    // TODO: pedir los dos números, llamar a dividir() dentro de try/catch
    //       y mostrar el resultado o el mensaje de error.
    std::cout << "Práctica 1: pendiente de implementar\n";
    return 0;
}

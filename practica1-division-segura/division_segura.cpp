// Práctica 1: División segura
#include <iostream>
#include <stdexcept>
#include <string>

// Su destructor se ejecuta siempre al salir del bloque: cumple el papel de finally (RAII).
struct MensajeCierre {
    ~MensajeCierre() { std::cout << "Operación finalizada.\n"; }
};

// En C++ dividir entre cero no lanza una excepción por sí solo (con double da inf y con
// enteros es comportamiento indefinido). Por eso se comprueba el divisor y se lanza
// std::domain_error con throw.
double dividir(double dividendo, double divisor) {
    if (divisor == 0) {
        throw std::domain_error("no se puede dividir entre cero");
    }
    return dividendo / divisor;
}

// Lee un número; si el usuario escribe texto, cin falla y se lanza std::invalid_argument.
double leerNumero(const std::string& mensaje) {
    std::cout << mensaje;
    double valor;
    if (!(std::cin >> valor)) {
        throw std::invalid_argument("debe ingresar un número válido");
    }
    return valor;
}

int main() {
    std::cout << "===== DIVISIÓN SEGURA =====\n";
    {
        // Se declara fuera del try: su destructor se ejecuta al cerrar este bloque, después
        // del try y del catch, igual que un bloque finally.
        MensajeCierre cierre;
        // Si dividir() o leerNumero() lanzan una excepción, el resto del try se salta y el
        // control pasa al catch cuyo tipo coincide.
        try {
            double dividendo = leerNumero("Ingrese el dividendo: ");
            double divisor = leerNumero("Ingrese el divisor: ");
            double resultado = dividir(dividendo, divisor);
            std::cout << "Resultado: " << resultado << '\n';
        } catch (const std::domain_error& e) {
            std::cout << "Error: " << e.what() << ".\n";
        } catch (const std::invalid_argument& e) {
            std::cout << "Error: " << e.what() << ".\n";
        }
    }  // aquí se destruye `cierre` y se muestra el mensaje de cierre
    return 0;
}

#include <iostream>
#include <string>
#include <stack>

std::string eliminarDuplicados(const std::string& input) {
    std::stack<char> pila;

    for (char c : input) {
        if (!pila.empty() && pila.top() == c) {
            pila.pop();
        }
        else {
            pila.push(c);
        }
    }

    std::string resultado;
    while (!pila.empty()) {
        resultado = pila.top() + resultado;
        pila.pop();
    }

    return resultado;
}

int main() {
    std::string cadena;
    std::cout << "Ingrese la cadena: ";
    std::cin >> cadena;

    std::string resultado = eliminarDuplicados(cadena);
    std::cout << "Cadena procesada: " << resultado << std::endl;

    return 0;
}

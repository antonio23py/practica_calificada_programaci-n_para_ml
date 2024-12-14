#include <iostream>
#include <vector>

using Matriz = std::vector<std::vector<int>>;

bool esMosaico(const Matriz& original, const Matriz& subImagen, int filas, int columnas) {
    int subFilas = subImagen.size();
    int subColumnas = subImagen[0].size();

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (original[i][j] != subImagen[i % subFilas][j % subColumnas]) {
                return false;
            }
        }
    }
    return true;
}

Matriz encontrarSubImagen(const Matriz& imagen) {
    int filas = imagen.size();
    int columnas = imagen[0].size();

    for (int subFilas = 1; subFilas <= filas; subFilas++) {
        if (filas % subFilas != 0) continue;
        for (int subColumnas = 1; subColumnas <= columnas; subColumnas++) {
            if (columnas % subColumnas != 0) continue;

            Matriz subImagen(subFilas, std::vector<int>(subColumnas));
            for (int i = 0; i < subFilas; i++) {
                for (int j = 0; j < subColumnas; j++) {
                    subImagen[i][j] = imagen[i][j];
                }
            }

            if (esMosaico(imagen, subImagen, filas, columnas)) {
                return subImagen;
            }
        }
    }
    return imagen;
}

int main() {
    int filas, columnas;
    std::cout << "Ingrese las dimensiones de la imagen (filas y columnas): ";
    std::cin >> filas >> columnas;

    Matriz imagen(filas, std::vector<int>(columnas));
    std::cout << "Ingrese los valores de la imagen:" << std::endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            std::cin >> imagen[i][j];
        }
    }

    Matriz subImagen = encontrarSubImagen(imagen);

    std::cout << "La subimagen más pequeña es:" << std::endl;
    for (const auto& fila : subImagen) {
        for (int val : fila) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

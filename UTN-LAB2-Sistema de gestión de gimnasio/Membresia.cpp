#include "Membresia.h"

Membresia::Membresia(const char* n, int cc, float v, int i) {
    strcpy(nombre, n);
    cantidadClases = cc;
    valor = v;
    id = i;
}

void Membresia::MostrarMembresia() {
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Cantidad de clases: " << cantidadClases << std::endl;
    std::cout << "Valor: " << valor << std::endl;
    std::cout << "ID: " << id << std::endl;
}


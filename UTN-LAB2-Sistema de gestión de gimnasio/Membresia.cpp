#include "Membresia.h"
#include "fecha.h"

Membresia::Membresia(std::string  n, int cc, float v, int i) {
    strcpy(nombre, n.c_str());
    cantidadClases = cc;
    valor = v;
    id = i;
    estado = true;
}

void Membresia::MostrarMembresia() {
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Cantidad de clases: " << cantidadClases << std::endl;
    std::cout << "Valor: " << valor << std::endl;
    std::cout << "ID: " << id << std::endl;
}


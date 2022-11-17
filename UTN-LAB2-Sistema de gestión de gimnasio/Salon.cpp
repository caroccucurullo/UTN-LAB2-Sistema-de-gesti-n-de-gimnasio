#include "Salon.h"

Salon::Salon(int i, int c, std::string n) {
    id = i;
    cupo = c;
    strcpy(nombre, n.c_str());
    estado = true;
}

void Salon::MostrarSalon() {
    std::cout << "ID: " << id << std::endl;
    std::cout << "Cupo: " << cupo << std::endl;
    std::cout << "Nombre: " << nombre << std::endl;
}

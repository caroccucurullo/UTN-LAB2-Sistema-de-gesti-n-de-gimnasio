
#include "Rol.h"


Rol::Rol(int i, const char* c, float s, const char* fi) {
    id = i;
    strcpy(cargo, c);
    sueldo = s;
    strcpy(fechaIngreso, fi);
}

void Rol::MostrarRol() {
    std::cout << "ID: " << id << std::endl;
    std::cout << "Cargo: " << cargo << std::endl;
    std::cout << "Sueldo: " << sueldo << std::endl;
    std::cout << "Fecha de ingreso: " << fechaIngreso << std::endl;
}


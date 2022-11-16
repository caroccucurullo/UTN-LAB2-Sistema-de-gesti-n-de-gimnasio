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

std::string Salon::MostrarSalonesDatos() {

    std::string cadena;
    cadena = std::to_string(getId()) + "," + getNombre() + "," + std::to_string(getCupo());
    return cadena;
}

void Salon::CargarSalon()
{
    std::string cadena;
    std::cout << "ID: ";
    std::cin >> id;
    std::cout << "Cupo: ";
    std::cin >> cupo;
    std::cin.ignore();
    std::cout << "Nombre: ";
    std::getline(std::cin, cadena);
    setNombre(cadena);
}
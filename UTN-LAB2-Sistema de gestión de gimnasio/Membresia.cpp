#include "Membresia.h"

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

std::string Membresia::MostrarMembresiasDatos()
{
    std::string cadena;
    cadena = getNombre() + "," + std::to_string(getCantidadClases()) + ","
		+ std::to_string(getValor()) + "," + std::to_string(getId())  ;
    return cadena;
}

void Membresia::CargarMembresia()
{
    std::string cadena;
    std::cout << "Nombre: ";
    std::getline(std::cin, cadena);
    setNombre(cadena);
    std::cout << "Cantidad de clases: ";
    std::cin >> cantidadClases;
    std::cin.ignore();
    std::cout << "Valor: ";
    std::cin >> valor;
    std::cin.ignore();
	std::cout << "ID: ";
	std::cin >> id;
	std::cin.ignore();
}
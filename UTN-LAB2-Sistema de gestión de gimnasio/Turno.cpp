# include "turno.h"

void Turno::CargarTurno()
{
    std::string cadena;
    std::cout << "Ingrese el nombre del turno: ";
    std::getline(std::cin, cadena);
    setNombre(cadena);
    std::cin.ignore();
    std::cout << "Ingrese el ID del turno: ";
    std::cin >> _idTurno;
}

void Turno::MostrarTurno()
{
    std::cout << "ID: " << _idTurno << std::endl;
    std::cout << "Nombre: " << _nombre << std::endl;
}

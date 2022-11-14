#include "Rol.h"


Rol::Rol(int id, std::string cargo, float sueldo, std::string turno, Fecha fechaIngreso) {
	_id = id;
	setCargo(cargo);
	_sueldo = sueldo;
	setTurno(turno);
	_fechaIngreso = fechaIngreso;
}

void Rol::MostrarRol() {
    std::cout << "ID: " << _id << std::endl;
    std::cout << "Cargo: " << _cargo << std::endl;
	Persona::MostrarPersona();
    std::cout << "Sueldo: " << _sueldo << std::endl;
	std::cout << "Turno: " << _turno << std::endl;
    std::cout << "Fecha de ingreso: " << getFechaIngreso().toString() << std::endl;
	if (!_estado) std::cout << "Fecha de Egreso: " << getFechaEgreso().toString() << std::endl;
}

void Rol::CargarRol()
{
	std::string cadena;
	std::cout << "ID: ";
	std::cin >> _id;
	std::cin.ignore();
	std::cout << "Cargo: ";
	std::getline(std::cin, cadena);
	setCargo(cadena);
	Persona::CargarPersona();
	std::cout << "Sueldo: ";
	std::cin >> _sueldo;
	std::cin.ignore();
	std::cout << "Turno: ";
	std::getline(std::cin, cadena);
	setTurno(cadena);
}


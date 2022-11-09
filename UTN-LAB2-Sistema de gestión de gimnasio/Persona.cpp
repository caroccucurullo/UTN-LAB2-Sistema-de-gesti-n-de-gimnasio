#include "Persona.h"

Persona::Persona(const char* n, const char* a, const char* fn, int e, const char* g, const char* t, const char* d) {
	strcpy(nombre, n);
	strcpy(apellido, a);
	strcpy(fechaNacimiento, fn);
	edad = e;
	strcpy(genero, g);
	strcpy(telefono, t);
	strcpy(dni, d);
	strcpy(direccion, d);
}

void Persona::MostrarPersona() {
	std::cout << "Nombre: " << nombre << std::endl;
	std::cout << "Apellido: " << apellido << std::endl;
	std::cout << "Fecha de nacimiento: " << fechaNacimiento << std::endl;
	std::cout << "Edad: " << edad << std::endl;
	std::cout << "Genero: " << genero << std::endl;
	std::cout << "Telefono: " << telefono << std::endl;
	std::cout << "DNI: " << dni << std::endl;
	std::cout << "Direccion: " << direccion << std::endl;
}


void Persona::personaCargar() {
	std::cout << "Ingrese nombre: ";
	std::cin >> nombre;
	std::cout << "Ingrese apellido: ";
	std::cin >> apellido;
	std::cout << "Ingrese fecha de nacimiento: ";
	std::cin >> fechaNacimiento;
	std::cout << "Ingrese edad: ";
	std::cin >> edad;
	std::cout << "Ingrese genero: ";
	std::cin >> genero;
	std::cout << "Ingrese telefono: ";
	std::cin >> telefono;
	std::cout << "Ingrese DNI: ";
	std::cin >> dni;
	std::cout << "Ingrese direccion: ";
	std::cin >> direccion;
}

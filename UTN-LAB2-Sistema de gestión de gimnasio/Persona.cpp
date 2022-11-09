#include "Persona.h"

Persona::Persona(const char* n, const char* a, Fecha nac, int e, const char* g, const char* t,const char* d, Direccion dir) {
	strcpy(nombre, n);
	strcpy(apellido, a);
	_fnac = nac;
	edad = e;
	strcpy(genero, g);
	strcpy(telefono, t);
	strcpy(dni, d);
	_dir = dir;
}

std::string Persona::MostrarPersona() {
	/*std::cout << "Nombre: " << nombre << std::endl;
	std::cout << "Apellido: " << apellido << std::endl;
	std::cout << "Fecha de nacimiento: " << getFechaNac().toString() << std::endl;
	std::cout << "Edad: " << edad << std::endl;
	std::cout << "Genero: " << genero << std::endl;
	std::cout << "Telefono: " << telefono << std::endl;
	std::cout << "DNI: " << dni << std::endl;
	std::cout << "Direccion: " << getDireccion().mostrar() << std::endl;*/
	std::string cadena;
	cadena = getNombre() + "," + getApellido() + "," + getFechaNac().toString() + "," + std::to_string(getEdad()) + "," + getGenero() + "," + getTelefono() + "," + getDni() + "," + getDireccion().mostrar();
	return cadena;
}


void Persona::personaCargar() {
	std::string cadena;
	std::cout << "Nombre: ";
	std::getline(std::cin, cadena);
	setNombre(cadena);
	std::cout << "Apellido: ";
	std::getline(std::cin, cadena);
	setApellido(cadena);
	std::cout << "Fecha de nacimiento: "<<std::endl;
	_fnac.Cargar();
	std::cout << "Edad: ";
	std::cin >> edad;
	std::cin.ignore();
	std::cout << "Genero: ";
	std::getline(std::cin, cadena);
	setGenero(cadena);
	std::cout << "Telefono: ";
	std::getline(std::cin, cadena);
	setTelefono(cadena);
	std::cout << "DNI: ";
	std::getline(std::cin, cadena);
	setDni(cadena);
	std::cout << "Direccion: "<<std::endl;
	_dir.cargar();
}

#include "Profesor.h"

Profesor::Profesor(int i, const char* d, int he, int hs, const char* fi, float s) {
	id = i;
	strcpy(disciplina, d);
	horarioEntrada = he;
	horarioSalida = hs;
	strcpy(fechaIngreso, fi);
	sueldo = s;
}

void Profesor::MostrarProfesor() {
	Persona::MostrarPersona();
	std::cout << "ID: " << id << std::endl;
	std::cout << "Disciplina: " << disciplina << std::endl;
	std::cout << "Horario de entrada: " << horarioEntrada << std::endl;
	std::cout << "Horario de salida: " << horarioSalida << std::endl;
	std::cout << "Fecha de ingreso: " << fechaIngreso << std::endl;
	std::cout << "Sueldo: " << sueldo << std::endl;
}

void Profesor::cargarProfesor() {
	Persona::personaCargar();
	
	std::cout << "Ingrese el ID: ";
	std::cin >> id;
	std::cout << "Ingrese la disciplina: ";
	std::cin >> disciplina;
	std::cout << "Ingrese el horario de entrada: ";
	std::cin >> horarioEntrada;
	std::cout << "Ingrese el horario de salida: ";
	std::cin >> horarioSalida;
	std::cout << "Ingrese la fecha de ingreso: ";
	std::cin >> fechaIngreso;
	std::cout << "Ingrese el sueldo: ";
	std::cin >> sueldo;
}

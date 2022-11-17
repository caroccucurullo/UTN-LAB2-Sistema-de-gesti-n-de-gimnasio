#include "Profesor.h"
#include "ArchivoProfesor.h"
#include "ArchivoDisciplina.h"

Profesor::Profesor(int id, int idDis, int turno, Fecha fIn, float s) {
	_id = id;
	_idDisciplina = idDis;
	_turnoId = turno;
	_fIngreso = fIn;
	_sueldo = s;
}

void Profesor::MostrarProfesor() {
	std::cout << "ID: " << _id << std::endl;
	Persona::MostrarPersona();
	std::cout << "ID Disciplina: " << _idDisciplina << std::endl;
	std::cout << "ID Turno: " << _turnoId << std::endl;
	std::cout << "Fecha de ingreso: " << getFechaIngreso().toString() << std::endl;
	if (!_estado) std::cout << "Fecha de Egreso: " << getFechaEgreso().toString() << std::endl;
	std::cout << "Sueldo: " << _sueldo << std::endl;
}

void Profesor::cargarProfesor() {
	std::string cadena;
	std::cout << "ID: ";
	std::cin >> _id;
	std::cin.ignore();
	Persona::CargarPersona();
	std::cout << "Id Disciplina: ";
	std::cin >> _idDisciplina;
	std::cin.ignore();
	std::cout << "ID Turno: ";
	std::cin >> _turnoId;
	std::cout << "Ingrese el sueldo: ";
	std::cin >> _sueldo;
}




//Funciones auxiliares de la clase


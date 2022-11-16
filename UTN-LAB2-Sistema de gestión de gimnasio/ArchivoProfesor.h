#pragma once
#include "Profesor.h"
#include "ArchivoDisciplina.h"
class ArchivoProfesor
{
public:
	bool guardarProfesor(Profesor& profesor);
	Profesor leerProfesor(int nRegistro);
	bool leerTodos(Profesor* profesor, int cantidad);
	bool modificarProfesor(Profesor& profesor, int nRegistro);
	int getCantidad();
	//Consulta Por DNI
	int buscarRegPorDni(std::string dni);
	//CONSULTA POR DISCIPLINA
	int getCantidadProfePorDis(std::string nombre);
	void ProfePorDis();
	void copiarProfeDis(Profesor* vProfe, std::string nombre);
	void mostrarProfe(Profesor* vProfe, int cant);
	//CONSULTA POR TURNO
	int getCantidadProfePorTurno(std::string turno);
	void ProfePorTurno();
	void copiarProfeTurno(Profesor* vProfe, std::string turno);

	bool bajaLogica(int nRegistro);
	bool altaLogica(int nRegistro);
};


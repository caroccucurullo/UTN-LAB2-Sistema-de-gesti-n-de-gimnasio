#pragma once
#include "Profesor.h"
class ArchivoProfesor
{
public:
	bool guardarProfesor(Profesor& profesor);
	Profesor leerProfesor(int nRegistro);
	bool leerTodos(Profesor* profesor, int cantidad);
	bool modificarProfesor(Profesor& profesor, int nRegistro);
	int getCantidad();
	int buscarRegPorDni(std::string dni);
	bool bajaLogica(int nRegistro);
	bool altaLogica(int nRegistro);

	//INFORMES
	void profesorAltasAnuales();
	void profesorBajasAnuales();
	void profesorSueldoAnual();
};


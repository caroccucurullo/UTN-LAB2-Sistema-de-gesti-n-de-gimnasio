#pragma once
#include "ClaseAsignada.h"
class ArchivoClaseAsignada
{
public:
	bool guardarClaseAsignada(ClaseAsignada& claseAsignada);
	ClaseAsignada leerClaseAsignada(int nRegistro);
	bool leerTodos(ClaseAsignada* claseAsignada, int cantidad);
	bool modificarClaseAsignada(ClaseAsignada& claseAsignada, int nRegistro);
	int getCantidad();

	void mostrarPorDisciplina();
};


#pragma once
#include "ClaseAsignada.h"
#include "ArchivoDisciplina.h"
#include "ArchivoSocios.h"
#include "ArchivoProfesor.h"

class ArchivoClaseAsignada
{
public:
	bool cargarClaseAsignada();

	bool guardarClaseAsignada(ClaseAsignada& claseAsignada);
	void guardarClaseAsignada();
	ClaseAsignada leerClaseAsignada(int nRegistro);
	bool leerTodos(ClaseAsignada* claseAsignada, int cantidad);
	bool modificarClaseAsignada(ClaseAsignada& claseAsignada, int nRegistro);
	void modificarClaseAsignada();
	int getCantidad();
	
	int buscarPorDisciplinayNroSocio(int codDisciplina, int nroSocio);

	//INFORMES
	void sociosPorDisciplinaActivos(int idD);

	void mostrarPorDisciplina();
};


#pragma once
#include "Rol.h"
class ArchivoRol
{
public:
	bool guardarRol(Rol& rol);
	Rol leerRol(int nRegistro);
	bool leerTodos(Rol* rol, int cantidad);
	bool modificarRol(Rol& rol, int nRegistro);
	int getCantidad();
	int buscarRegPorDni(std::string dni);

	//CONSULTA POR CARGO
	int getCantidadPorCargo(std::string cargo);
	void rolPorCargo();
	void copiarRolCargo(Rol* vRol, std::string cargo);
	void mostrarRol(Rol* vRol, int cant);
	
	//CONSULTA POR FECHA DE INGRESO
	int getCantidadPorFechaIngreso(Fecha fechaIngreso);
	void rolPorFechaIngreso();
	void copiarRolFechaIngreso(Rol* vRol, Fecha fechaIngreso);
	
	
	bool bajaLogica(int nRegistro);
	bool altaLogica(int nRegistro);
};


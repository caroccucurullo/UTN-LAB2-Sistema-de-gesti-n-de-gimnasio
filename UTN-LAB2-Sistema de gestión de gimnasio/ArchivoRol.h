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
	bool bajaLogica(int nRegistro);
	bool altaLogica(int nRegistro);
	
	//INFORMES
	void rolAltasAnuales();
	void rolBajasAnuales();
	void rolSueldoAnual();
};


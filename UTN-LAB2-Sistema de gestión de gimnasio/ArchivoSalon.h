#pragma once
#include "Salon.h"
class ArchivoSalon
{
public:
	bool guardarSalon(Salon& salon);
	Salon leerSalon(int nRegistro);
	bool leerTodos(Salon* salon, int cantidad);
	bool modificarSalon(Salon& salon, int nRegistro);
	int getCantidad();
	int buscarRegPorNombre(std::string nombre);
	bool bajaLogica(int nRegistro);
	bool altaLogica(int nRegistro);
};


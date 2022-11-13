#pragma once
#include "Socio.h"
class ArchivoSocios
{
public:
	bool guardarSocio(Socio &socio);
	Socio leerSocio(int nRegistro);
	bool leerTodos(Socio* socio, int cantidad);
	bool modificarSocio(Socio& socio, int nRegistro);
	int getCantidad();
	int buscarRegPorDni(std::string dni);
	bool bajaLogica(int nRegistro);
	bool altaLogica(int nRegistro);
};


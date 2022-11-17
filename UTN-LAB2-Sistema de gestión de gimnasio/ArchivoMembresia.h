#pragma once
#include "Membresia.h"
class ArchivoMembresia
{
public:
	bool guardarMembresia(Membresia& membresia);
	void guardarMembresia();
	Membresia leerMembresia(int nRegistro);
	bool leerTodas(Membresia* membresia, int cantidad);
	bool modificarMembresia(Membresia& membresia, int nRegistro);
	void modificarMembresia();
	int getCantidad();
	int buscarRegPorNombre(std::string nombre);
	bool bajaLogica(int nRegistro);
	void bajaMembresia();
	bool altaLogica(int nRegistro);
	void altaMembresia();
};


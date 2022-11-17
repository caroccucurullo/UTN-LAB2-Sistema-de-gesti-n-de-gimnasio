#pragma once
#include "Membresia.h"
class ArchivoMembresias
{
public:
	bool guardarMembresia(Membresia& membresia);
	Membresia leerMembresia(int nRegistro);
	bool leerTodas(Membresia* membresia, int cantidad);
	bool modificarMembresia(Membresia& membresia, int nRegistro);
	int getCantidad();
	int buscarRegPorNombre(std::string nombre);
	bool bajaLogica(int nRegistro);
	bool altaLogica(int nRegistro);
};
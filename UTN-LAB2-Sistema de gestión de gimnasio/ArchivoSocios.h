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
	
	
	///Consultas
	int buscarRegPorDni(std::string dni);///Por Dni
	int buscarRegPorNumSocio(int numSocio);///Por Nro Socio
	///Por Edad
	int getCantidadEdad(int edad);
	void sociosPorEdad();
	void copiarSocio(Socio* vSocio, int edad);
	void mostrarSocio(Socio* vSocio, int cant);
	///Por Disciplina
	int getCantidadDis(std::string nombre);
	//void sociosPorDis();
	//void copiarSocioDis(Socio* vSocio, std::string nombre);
	//void mostrarSocioDis(Socio* vSocio, int cant);
	///Por Membresia
	
	bool bajaLogica(int nRegistro);
	bool altaLogica(int nRegistro);
};


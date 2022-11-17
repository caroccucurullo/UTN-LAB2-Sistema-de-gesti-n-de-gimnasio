#pragma once
#include "Socio.h"
#include "ArchivoClaseAsignada.h"
#include "ArchivoDisciplina.h"
#include "ArchivoMembresia.h"
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
	int getCantidadSocioPorDis(std::string nombre);
	void sociosPorDis();
	void copiarSocioDis(Socio* vSocio, std::string nombre);
	///Por Membresia
	int getCantidadSocioPorMembresia(int idMem);
	void sociosPorMembresia();
	void copiarSocioMembresia(Socio* vSocio, int idMem);
	
	bool bajaLogica(int nRegistro);
	bool altaLogica(int nRegistro);

	void ordenarPorNombre();
	void ordenarPorEdad();
	void mostrarPorEstado();
	void mostrarPorAptoMedico();
};


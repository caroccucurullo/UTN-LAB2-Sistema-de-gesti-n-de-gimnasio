#pragma once
#include "Socio.h"
#include "ArchivoClaseAsignada.h"
#include "ArchivoDisciplina.h"
#include "ArchivoMembresia.h"
#include "funciones.h"
class ArchivoSocios
{
public:
	//GUARDAR PROFESOR
	bool guardarSocio(Socio &socio);
	void guardarSocio();//FUNCION A LLAMAR EN EL MENU
	//LEE PROFESOR, 1 SOLO REGISTRO
	Socio leerSocio(int nRegistro);
	//COPIA TODOS LOS REGISTROS EN UN VECTOR
	bool leerTodos(Socio* socio, int cantidad);
	//MODIFICAR SOCIO, TODO EL REGISTRO.
	bool modificarSocio(Socio& socio, int nRegistro);
	void modificarSocio();//FUNCION A LLAMAR EN EL MENU
	//OBTIENE LA CANTIDAD DE REGISTROS DEL ARCHIVO
	int getCantidad();
	//BAJA LOGICA POR DNI
	bool bajaLogica(int nRegistro);
	void bajaSocio();//FUNCION A LLAMAR EN EL MENU
	//ALTA LOGICA POR DNI, PONE TRUE EN EL REGISTRO DE SOCIO
	bool altaLogica(int nRegistro);
	void altaSocio();//FUNCION A LLAMAR EN EL MENU
	
	
	///Consultas
	///Por Dni
	int buscarRegPorDni(std::string dni);
	void consultaPorDni();//FUNCION A LLAMAR EN EL MENU
	///Por Nro Socio
	int buscarRegPorNumSocio(int numSocio);
	void consultaPorNumSocio();//FUNCION A LLAMAR EN EL MENU
	///Por Edad
	int getCantidadEdad(int edad);
	void sociosPorEdad();//FUNCION A LLAMAR EN EL MENU
	void copiarSocio(Socio* vSocio, int edad);
	void mostrarSocio(Socio* vSocio, int cant);
	///Por Disciplina
	int getCantidadSocioPorDis(std::string nombre);
	void sociosPorDis();//FUNCION A LLAMAR EN EL MENU
	void copiarSocioDis(Socio* vSocio, std::string nombre);
	///Por Membresia
	int getCantidadSocioPorMembresia(int idMem);
	void sociosPorMembresia();//FUNCION A LLAMAR EN EL MENU
	void copiarSocioMembresia(Socio* vSocio, int idMem);
	
	//INFORMES
	void sociosAltasMensuales(int anio, int mes);
	void sociosBajasMensuales(int anio, int mes);
	void sociosAltasAnuales(int anio);
	void sociosBajasAnuales(int anio);
	void sociosPorMenbresiaActivos(int idM);
	
	//Listado
	void ordenarPorNombre();
	void ordenarPorEdad();
	void mostrarPorEstado();
	void mostrarPorAptoMedico();
};


#pragma once
#include "Rol.h"
class ArchivoRol
{
public:
	//GUARDAR ROL
	bool guardarRol(Rol& rol);
	void guardarRol();//FUNCION A LLAMAR EN EL MENU
	//LEER ROL, 1 REGISTRO
	Rol leerRol(int nRegistro);
	//LEER ROL, TODOS LOS REGISTROS
	bool leerTodos(Rol* rol, int cantidad);
	//MODIFICAR ROL, TODO EL REGISTRO
	bool modificarRol(Rol& rol, int nRegistro);
	void modificarRol();//FUNCION A LLAMAR EN EL MENU
	
	//OBTIENE LA CANTIDAD DE REGISTROS DEL ARCHIVO
	int getCantidad();
	
	//CONSULTA POR DNI
	int buscarRegPorDni(std::string dni);
	void consultaPorDni();//FUNCION A LLAMAR EN EL MENU

	//CONSULTA POR CARGO
	int getCantidadPorCargo(std::string cargo);
	void rolPorCargo();//FUNCION A LLAMAR EN EL MENU
	void copiarRolCargo(Rol* vRol, std::string cargo);
	void mostrarRol(Rol* vRol, int cant);
	
	//CONSULTA POR FECHA DE INGRESO
	int getCantidadPorFechaIngreso(Fecha fechaIngreso);
	void rolPorFechaIngreso();//FUNCION A LLAMAR EN EL MENU
	void copiarRolFechaIngreso(Rol* vRol, Fecha fechaIngreso);
	
	//BAJA DE REGISTRO POR DNI
	bool bajaLogica(int nRegistro);
	void bajaRol();
	//ALTA DE REGISTRO POR DNI
	bool altaLogica(int nRegistro);
	void altaRol();
};


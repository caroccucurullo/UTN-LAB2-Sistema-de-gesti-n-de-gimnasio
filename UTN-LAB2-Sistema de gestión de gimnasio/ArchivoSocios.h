#pragma once
#include "Socio.h"
#include "ArchivoClaseAsignada.h"
#include "ArchivoDisciplina.h"
#include "ArchivoMembresia.h"
#include "funciones.h"
#include "Cargar.h"
class ArchivoSocios
{
public:
	//GUARDAR SOCIO
	bool guardarSocio(Socio &socio);
	void guardarSocio();//FUNCION A LLAMAR EN EL MENU
	//LEE SOCIO, 1 SOLO REGISTRO
	Socio leerSocio(int nRegistro);
	//COPIA TODOS LOS REGISTROS EN UN VECTOR
	bool leerTodos(Socio* socio, int cantidad);
	//MODIFICAR SOCIO, TODO EL REGISTRO.
	bool modificarSocio(Socio& socio, int nRegistro);
	void modificarSocio();//FUNCION A LLAMAR EN EL MENU
	void modificarSocioConOpciones();
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
	void sociosPorEdad();//FUNCION A LLAMAR EN EL MENU
	///Por Disciplina
	void sociosPorDisciplina();//FUNCION A LLAMAR EN EL MENU
	///Por Membresia
	void sociosPorMembresia();//FUNCION A LLAMAR EN EL MENU
	
	//INFORMES
	void sociosAltasMensuales();
	void sociosBajasMensuales();
	void sociosAltasAnuales();
	void sociosBajasAnuales();
	void sociosActivosPorMembresia();
	
	//Listado
	void ordenarPorNombre();
	void ordenarPorEdad();
	void mostrarPorEstado();
	void mostrarPorAptoMedico();

	//Otras Funciones
	int ultimoSocio();
};


#pragma once
#include "Salon.h"
#include "ArchivoDisciplina.h"
#include "ArchivoClaseAsignada.h"
class ArchivoSalon
{
public:
	//GUARDAR PROFESOR
	bool guardarSalon(Salon& salon);
	void guardarSalon();//FUNCION A LLAMAR EN EL MENU
	//LEE PROFESOR, 1 SOLO REGISTRO
	Salon leerSalon(int nRegistro);
	//COPIA TODOS LOS REGISTROS EN UN VECTOR
	bool leerTodos(Salon* salon, int cantidad);
	//MODIFICAR SALON, TODO EL REGISTRO.
	bool modificarSalon(Salon& salon, int nRegistro);
	void modificarSalon();//FUNCION A LLAMAR EN EL MENU
	
	//OBTIENE LA CANTIDAD DE REGISTROS DEL ARCHIVO
	int getCantidad();
	
	int buscarRegPorNombre(std::string nombre);

	//CONSULTA POR CUPO
	void SalonPorCupoHorario();//FUNCION A LLAMAR EN EL MENU
	int calcularCupoPorHorario(Salon& salon, int horario, Fecha& fecha, Disciplina* vDis);
	
	
	//BAJA LOGICA POR NOMBRE
	bool bajaLogica(int nRegistro);
	void bajaSalon();//FUNCION A LLAMAR EN EL MENU

	//ALTA LOGICA POR NOMBRE
	bool altaLogica(int nRegistro);
	void altaSalon();//FUNCION A LLAMAR EN EL MENU
};


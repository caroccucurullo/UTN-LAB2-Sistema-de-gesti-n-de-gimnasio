#pragma once
#include "Profesor.h"
#include "ArchivoDisciplina.h"
#include "funciones.h"
class ArchivoProfesor
{
public:
	//GUARDAR PROFESOR
	bool guardarProfesor(Profesor& profesor);
	void guardarProfesor();//FUNCION A LLAMAR EN EL MENU
	//LEE PROFESOR, 1 SOLO REGISTRO
	Profesor leerProfesor(int nRegistro);
	//COPIA TODOS LOS REGISTROS EN UN VECTOR
	bool leerTodos(Profesor* profesor, int cantidad);
	//MODIFICAR PROFESOR, TODO EL REGISTRO
	bool modificarProfesor(Profesor& profesor, int nRegistro);
	void modificarProfesor();//FUNCION A LLAMAR EN EL MENU
	//OBTIENE LA CANTIDAD DE REGISTROS DEL ARCHIVO
	int getCantidad();
	//Consulta Por DNI
	int buscarRegPorDni(std::string dni);
	void consultaPorDni();//FUNCION A LLAMAR EN EL MENU
	
	//CONSULTA POR DISCIPLINA
	int getCantidadProfePorDis(std::string nombre);
	void ProfePorDis();//FUNCION A LLAMAR EN EL MENU
	void copiarProfeDis(Profesor* vProfe, std::string nombre);
	void mostrarProfe(Profesor* vProfe, int cant);
	//CONSULTA POR TURNO
	int getCantidadProfePorTurno(std::string turno);
	void ProfePorTurno();//FUNCION A LLAMAR EN EL MENU
	void copiarProfeTurno(Profesor* vProfe, std::string turno);

	//BAJA POR DNI
	bool bajaLogica(int nRegistro);
	void bajaProfesor();//FUNCION A LLAMAR EN EL MENU
	//ALTA POR DNI
	bool altaLogica(int nRegistro);
	void altaProfesor();//FUNCION A LLAMAR EN EL MENU

	//INFORMES
	void profesorAltasAnuales(int anio);
	void profesorBajasAnuales(int anio);
	void profesorSueldoAnual(int idP);

	//LISTADO
	void ordenarPorApellido();
    void ordenarPorDisciplina();
};


#pragma once
#include "Profesor.h"
#include "ArchivoDisciplina.h"
#include "funciones.h"
#include "Cargar.h"
class ArchivoProfesor
{
public:
	//GUARDAR PROFESOR
	bool guardarProfesor(Profesor& profesor);
	void guardarProfesor();//FUNCION A LLAMAR EN EL MENU
	//VALIDAR DATOS
	bool validarDatosProfesor(Profesor& profesor);
	//LEE PROFESOR, 1 SOLO REGISTRO
	Profesor leerProfesor(int nRegistro);
	//COPIA TODOS LOS REGISTROS EN UN VECTOR
	bool leerTodos(Profesor* profesor, int cantidad);
	//MODIFICAR PROFESOR, TODO EL REGISTRO
	bool modificarProfesor(Profesor& profesor, int nRegistro);
	void modificarProfesor();
	void modificarProfesorConOpciones();//FUNCION A LLAMAR EN EL MENU
	//OBTIENE LA CANTIDAD DE REGISTROS DEL ARCHIVO
	int getCantidad();
	//Consulta Por DNI
	int buscarRegPorDni(std::string dni);
	void consultaPorDni();//FUNCION A LLAMAR EN EL MENU

	//BUSCAR PROFE POR ID
	int buscarRegPorID(int id);
	
	//CONSULTA POR DISCIPLINA
	void profePorDisciplina();//FUNCION A LLAMAR EN EL MENU
	
	void mostrarProfe(Profesor* vProfe, int cant);
	//CONSULTA POR TURNO
	void profePorTurno();//FUNCION A LLAMAR EN EL MENU

	//BAJA POR DNI
	bool bajaLogica(int nRegistro);
	void bajaProfesor();//FUNCION A LLAMAR EN EL MENU
	//ALTA POR DNI
	bool altaLogica(int nRegistro);
	void altaProfesor();//FUNCION A LLAMAR EN EL MENU

	//INFORMES
	void profesorAltasAnuales();
	void profesorBajasAnuales();
	void profesorSueldoAnual();

	//LISTADO
	void ordenarPorApellido();
    void ordenarPorDisciplina();
	void ordenarPorSueldo();
	void mostrarProfesoresPorEstado();
	void mostrarProfesoresPorTurno();

	//Otras funciones
	int ultimoProfesor();
};


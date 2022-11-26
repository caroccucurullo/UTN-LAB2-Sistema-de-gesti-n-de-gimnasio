#pragma once
#include "Disciplina.h"
#include "ArchivoSalon.h"
class ArchivoDisciplina
{
public:
	//GUARDAR DISCIPLINA
	bool guardarDisciplina(Disciplina& disciplina);
	void guardarDisciplina();//FUNCION A LLAMAR EN EL MENU
	//LEER DISCIPLINA, 1 REGISTRO
	Disciplina leerDisciplina(int nRegistro);
	//LEER TODOS LOS REGISTROS
	bool leerTodas(Disciplina* disciplina, int cantidad);
	//MODIFICAR 1 REGISTRO.
	bool modificarDisciplina(Disciplina& disciplina, int nRegistro);
	void modificarDisciplina();//FUNCION A LLAMAR EN EL MENU
	//OBTIENE CANTIDAD DE REGISTROS DEL ARCHIVO
	int getCantidad();
	
	int buscarRegPorCod(int cod);
	int buscarRegPorNombre(std::string nombre);
	//int buscarRegPorSalonyHorario(int idSalon, int horario);

	//CONSULTA POR SALONES
	//int getCantidadSalon(std::string nombreSalon);
	//void disciplinasPorSalon();//FUNCION A LLAMAR EN EL MENU
	//void copiarDisciplinaPorSalon(Disciplina* vDisciplina, std::string nombreSalon);

	//CONSULTA POR HORARIO
	//int getCantidadPorHorario(int horarioInicio);
	//void disciplinasPorHorario();//FUNCION A LLAMAR EN EL MENU
	//void copiarDisciplinaHorario(Disciplina* vDisciplina, int horarioInicio);
	//void mostrarDisciplina(Disciplina* vDisciplina, int cant);


	bool bajaLogica(int nRegistro);
	void bajaDisciplina();//FUNCION A LLAMAR EN EL MENU
	bool altaLogica(int nRegistro);
	void altaDisciplina();//FUNCION A LLAMAR EN EL MENU

	//LISTAS
	//void ordenarPorDisciplina();
	//void mostrarPorHorarioAscendente();
};
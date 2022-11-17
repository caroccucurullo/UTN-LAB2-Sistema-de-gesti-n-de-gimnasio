#pragma once
#include "Disciplina.h"
#include "ArchivoSalon.h"
class ArchivoDisciplina
{
public:
	bool guardarDisciplina(Disciplina& disciplina);
	Disciplina leerDisciplina(int nRegistro);
	bool leerTodas(Disciplina* disciplina, int cantidad);
	bool modificarDisciplina(Disciplina& disciplina, int nRegistro);
	int getCantidad();
	int buscarRegPorCod(int cod);
	int buscarRegPorNombre(std::string nombre);
	int buscarRegPorSalonyHorario(int idSalon, int horario);

	//CONSULTA POR SALONES
	int getCantidadSalon(std::string nombreSalon);
	void disciplinasPorSalon();
	void copiarDisciplinaPorSalon(Disciplina* vDisciplina, std::string nombreSalon);

	//CONSULTA POR HORARIO
	int getCantidadPorHorario(int horarioInicio);
	void disciplinasPorHorario();
	void copiarDisciplinaHorario(Disciplina* vDisciplina, int horarioInicio);
	void mostrarDisciplina(Disciplina* vDisciplina, int cant);


	bool bajaLogica(int nRegistro);
	bool altaLogica(int nRegistro);

	void ordenarPorDisciplina();
	void mostrarPorHorarioAscendiente();
};


#pragma once
#include "Disciplina.h"
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
	bool bajaLogica(int nRegistro);
	bool altaLogica(int nRegistro);
};


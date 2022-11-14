#pragma once
#include "Disciplina.h"
class ArchivoDisciplina
{
public:
	bool guardarSocio(Disciplina& disciplina);
	Disciplina leerSocio(int nRegistro);
	bool modificarSocio(Disciplina& disciplina, int nRegistro);
	int getCantidad();
	int buscarRegPorCod(std::string cod);
};


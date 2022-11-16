#include "ClaseAsignada.h"

ClaseAsignada::ClaseAsignada(int codDisciplina, int nroSocio, Fecha fechaAsignada)
{
	_codDisciplina = codDisciplina;
	_nroSocio = nroSocio;
	_fechaAsignada = fechaAsignada;
	_estado = true;
}

void ClaseAsignada::mostrar()
{
	std::cout << "Codigo Disciplina: ";
	std::cin >> _codDisciplina;
	std::cout << "Nro Socio: ";
	std::cin >> _nroSocio;
	std::cout << "Fecha de Asignacion: ";
	_fechaAsignada.Cargar();
}

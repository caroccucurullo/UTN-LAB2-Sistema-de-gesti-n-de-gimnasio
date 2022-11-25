#include "ClaseAsignada.h"

ClaseAsignada::ClaseAsignada(int codDisciplina, int nroSocio, int idProf, int hIni, int hFin, Fecha fechaAsignada)
{
	_codDisciplina = codDisciplina;
	_nroSocio = nroSocio;
	_idProfesor = idProf;
	_horarioInicio = hIni;
	_horarioFin = hFin;
	_fechaAsignada = fechaAsignada;
	_estado = true;
}

void ClaseAsignada::mostrar()
{
	std::cout << "Codigo Disciplina: ";
	std::cin >> _codDisciplina;
	std::cout << "Nro Socio: ";
	std::cin >> _nroSocio;
	std::cout << "ID Profesor: ";
	std::cin >> _idProfesor;
	std::cout << "Horario de Inicio: ";
	std::cin >> _horarioInicio;
	std::cout << "Horario de Fin: ";
	std::cin >> _horarioFin;
	std::cout << "Fecha de Asignacion: " << _fechaAsignada.toString() << std::endl;
}

void ClaseAsignada::cargar()
{
	std::cout << "Codigo Disciplina: ";
	std::cin >> _codDisciplina;
	std::cout << "Nro Socio: ";
	std::cin >> _nroSocio;
	std::cout << "ID Profesor: ";
	std::cin >> _idProfesor;
	std::cout << "Horario de Inicio: ";
	std::cin >> _horarioInicio;
	_horarioFin = _horarioInicio + 1;
}

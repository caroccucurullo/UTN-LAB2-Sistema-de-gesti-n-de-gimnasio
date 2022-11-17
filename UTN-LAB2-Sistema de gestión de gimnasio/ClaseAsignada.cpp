#include "ClaseAsignada.h"

ClaseAsignada::ClaseAsignada(int codDisciplina, int nroSocio, int idSalon, Fecha fechaAsignada)
{
	_codDisciplina = codDisciplina;
	_nroSocio = nroSocio;
	_idSalon = idSalon;
	_fechaAsignada = fechaAsignada;
	_estado = true;
}

void ClaseAsignada::mostrar()
{
	std::cout << "Codigo Disciplina: ";
	std::cin >> _codDisciplina;
	std::cout << "Nro Socio: ";
	std::cin >> _nroSocio;
	std::cout << "Id Salon: ";
	std::cin >> _idSalon;
	std::cout << "Fecha de Asignacion: ";
	_fechaAsignada.Cargar();
}

void ClaseAsignada::cargar()
{
	std::cout << "Codigo Disciplina: ";
	std::cin >> _codDisciplina;
	std::cout << "Nro Socio: ";
	std::cin >> _nroSocio;
	std::cout << "ID Salon: ";
	std::cin >> _idSalon;
}

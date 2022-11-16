#include "Disciplina.h"

Disciplina::Disciplina(int cod, int hIni, int hFin, std::string nombre, int idProf, int idSalon) {
    _codigo = cod;
    _horarioInicio = hIni;
    _horarioFin = hFin;
    strcpy(_nombre, nombre.c_str());
    _idProfesor = idProf;
    _idSalon = idSalon;
	estado = true;
}

void Disciplina::MostrarDisciplina() {
    std::cout << "Codigo: " << _codigo << std::endl;
    std::cout << "Horario inicio: " << _horarioInicio << std::endl;
    std::cout << "Horario fin: " << _horarioFin << std::endl;
    std::cout << "Nombre: " << _nombre << std::endl;
    std::cout << "Id profesor: " << _idProfesor << std::endl;
    std::cout << "Salon: " << _idSalon << std::endl;
}

std::string Disciplina::MostrarDisciplinasDatos()
{
	std::string cadena;
	cadena = std::to_string(getCodigo()) + "," + std::to_string(getHorarioInicio()) + ","
		+ std::to_string(getHorarioFin()) + "," + (getNombre()) + ","
		+ std::to_string(getIdProfesor()) + "," + std::to_string(getSalon());
	return cadena;
}

void Disciplina::CargarDisciplina()
{
	std::string cadena;
	std::cout << "Codigo: ";
	std::cin >> _codigo;
	std::cout << "Horario inicio: ";
	std::cin >> _horarioInicio;
	std::cout << "Horario fin: ";
	std::cin >> _horarioFin;
	std::cin.ignore();
	std::cout << "Nombre: ";
	std::getline(std::cin, cadena);
	setNombre(cadena);
	std::cout << "Id profesor: ";
	std::cin >> _idProfesor;
	std::cout << "Id Salon: ";
	std::cin >> _idSalon;
}

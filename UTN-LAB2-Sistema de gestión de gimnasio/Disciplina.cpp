#include "Disciplina.h"

Disciplina::Disciplina(int cod, std::string nombre, int idSalon) {
    _codigo = cod;
    strcpy(_nombre, nombre.c_str());
    _idSalon = idSalon;
	estado = true;
}

void Disciplina::MostrarDisciplina() {
    std::cout << "Codigo: " << _codigo << std::endl;
    std::cout << "Nombre: " << _nombre << std::endl;
    std::cout << "Salon: " << _idSalon << std::endl;
}
std::string Disciplina::MostrarDisciplinasFormatoComas()
{
    std::string cadena;
    cadena = std::to_string(getCodigo()) + "," + (getNombre()) + ","
		+ std::to_string(getIdSalon());
	return cadena;
}

void Disciplina::CargarDisciplina()
{
	std::string cadena;
	std::cout << "Codigo: ";
	std::cin >> _codigo;
	std::cin.ignore();
	std::cout << "Nombre: ";
	std::getline(std::cin, cadena);
	setNombre(cadena);
	std::cout << "Id Salon: ";
	std::cin >> _idSalon;
}

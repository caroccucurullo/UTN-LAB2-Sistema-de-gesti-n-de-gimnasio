#include "Profesor.h"
#include "ArchivoProfesor.h"
#include "ArchivoDisciplina.h"

Profesor::Profesor(int id, int idDis, std::string turno, Fecha fIn, float s) {
	_id = id;
	_idDisciplina = idDis;
	strcpy(_turno, turno.c_str());
	_fIngreso = fIn;
	_sueldo = s;
}

void Profesor::MostrarProfesor() {
	std::cout << "ID: " << _id << std::endl;
	Persona::MostrarPersona();
	std::cout << "ID Disciplina: " << _idDisciplina << std::endl;
	std::cout << "Turno: " << _turno << std::endl;
	std::cout << "Fecha de ingreso: " << getFechaIngreso().toString() << std::endl;
	if (!_estado) std::cout << "Fecha de Egreso: " << getFechaEgreso().toString() << std::endl;
	std::cout << "Sueldo: " << _sueldo << std::endl;
}

void Profesor::cargarProfesor() {
	std::string cadena;
	std::cout << "ID: ";
	std::cin >> _id;
	std::cin.ignore();
	Persona::CargarPersona();
	std::cout << "Id Disciplina: ";
	std::cin >> _idDisciplina;
	std::cin.ignore();
	std::cout << "Turno: ";
	std::getline(std::cin, cadena);
	setTurno(cadena);
	std::cout << "Ingrese el sueldo: ";
	std::cin >> _sueldo;
}

void Profesor::ordenarPorApellido(){

	ArchivoProfesor archivo;
	int cantidad = archivo.getCantidad();
	Profesor* profesores = new Profesor[cantidad];

	completarVector(profesores, cantidad);
	ordenarVectorPorApellido(profesores, cantidad);
	mostrarVector(profesores, cantidad);

	delete[] profesores;
}

void Profesor::ordenarPorDisciplina() {

	ArchivoProfesor archivo;
	int cantidad = archivo.getCantidad();
	Profesor* profesores = new Profesor[cantidad];

	completarVector(profesores, cantidad);
	ordenarVectorPorDisciplina(profesores, cantidad);
	mostrarVector(profesores, cantidad);

	delete[] profesores;
}


//Funciones auxiliares de la clase

void completarVector(Profesor* profesor, int cantidad)
{
    ArchivoProfesor archivo;

    for (int i = 0; i < cantidad; i++)
    {
        profesor[i] = archivo.leerProfesor(i);
    }
}

void ordenarVectorPorApellido(Profesor* profesor, int cantidad)
{
	Profesor aux;
	for (int i = 0; i < cantidad - 1; i++)
	{
		for (int j = i + 1; j < cantidad; j++)
		{
			if (strcmp(profesor[i].getApellido().c_str(), profesor[j].getApellido().c_str()) > 0)
			{
				aux = profesor[i];
				profesor[i] = profesor[j];
				profesor[j] = aux;
			}
		}
	}
}

void ordenarVectorPorDisciplina(Profesor* profesor, int cantidad)
{
	ArchivoDisciplina archivo;
	Disciplina disciplina;

	int cantidadDisciplina = archivo.getCantidad();

	for(int i = 0; i < cantidadDisciplina; i++)
	{
		disciplina = archivo.leerDisciplina(i);

		for (int j = 0; j < cantidad; j++)
		{
			if (profesor[j].getIdDisciplina() == disciplina.getCodigo())
			{
				profesor[j].MostrarProfesor();
			}
		}
	}
}

void mostrarVector(Profesor* profesor, int cantidad)
{
	for (int i = 0; i < cantidad; i++)
	{
		profesor[i].MostrarProfesor();
	}
}

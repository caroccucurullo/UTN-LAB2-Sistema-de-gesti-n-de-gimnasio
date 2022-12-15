#include "Socio.h"
#include "Profesor.h"
#include "Disciplina.h"
#include "ArchivoSocios.h"
#include "ArchivoProfesor.h"
#include "ArchivoDisciplina.h"
#include "ArchivoSalon.h"

void completarVectorSocios(Socio* socios, int cantidad)
{
    ArchivoSocios archivoSocios;

    for (int i = 0; i < cantidad; i++)
    {
        socios[i] = archivoSocios.leerSocio(i);
    }
}

void ordenarPorNombreDescendiente(Socio* socios, int cantidad){
    Socio aux;
    for (int i = 0; i < cantidad; i++)
    {
        for (int j = 0; j < cantidad - 1; j++)
        {
            if (strcmp(socios[j].getNombre().c_str(), socios[j + 1].getNombre().c_str()) > 0)
            {
                aux = socios[j];
                socios[j] = socios[j + 1];
                socios[j + 1] = aux;
            }
        }
    }
}

void ordenarPorEdadDescendiente(Socio* socios, int cantidad)
{
    Socio aux;

    for (int i = 0; i < cantidad; i++)
    {
        for (int j = 0; j < cantidad - 1; j++)
        {
            if (socios[j].getEdad() > socios[j + 1].getEdad())
            {
                aux = socios[j];
                socios[j] = socios[j + 1];
                socios[j + 1] = aux;
            }
        }
    }
}

void mostrarVectorSocios(Socio* socios, int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        socios[i].MostrarSocio();
		std::cout << std::endl;
    }
}

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
        bool hay = false;
		disciplina = archivo.leerDisciplina(i);
        
        std::cout << "Disciplina " << disciplina.getNombre()<<":" << std::endl;
		for (int j = 0; j < cantidad; j++)
		{
			if (profesor[j].getIdDisciplina() == disciplina.getCodigo())
			{
                hay = true;
                std::cout << std::endl;
				profesor[j].MostrarProfesor();
                std::cout << std::endl;
			}
		}
        if (!hay) std::cout<< "No hay profesores" << std::endl << std::endl;
	}
}

void mostrarVector(Profesor* profesor, int cantidad)
{
	for (int i = 0; i < cantidad; i++)
	{
		profesor[i].MostrarProfesor();
        std::cout << std::endl;
	}
}

void ordenarVectorPorSueldo(Profesor* profesor, int cantidad){
    Profesor aux;
    for (int i = 0; i < cantidad - 1; i++)
    {
        for (int j = i + 1; j < cantidad; j++)
        {
            if (profesor[i].getSueldo() < profesor[j].getSueldo())
            {
                aux = profesor[i];
                profesor[i] = profesor[j];
                profesor[j] = aux;
            }
        }
    }
}

void mostrarVectorPorEstado(Profesor* profesor, int cantidad, bool estado)
{
    bool hay = false;
    for (int i = 0; i < cantidad; i++)
    {
        if (profesor[i].getEstado() == estado)
        {
            hay = true;
            profesor[i].MostrarProfesor();
            std::cout << std::endl;
        }
    }
    if (!hay) std::cout << "No hay registros." << std::endl;
}

void mostrarProfesorPorTurno(Profesor* profesor, int cantidad, std::string turno)
{
    for (int i = 0; i < cantidad; i++)
    {
        if (profesor[i].getTurno() == turno)
        {
            profesor[i].MostrarProfesor();
            std::cout << std::endl;
        }
    }
}

void mostrarDisciplinaPorSalon(int cantDisciplina, int cantSalon){
    ArchivoDisciplina archivo;
    ArchivoSalon archivoSalon;
    Disciplina disciplina;
    Salon salon;

    for (int i = 0; i < cantSalon; i++)
    {
        salon = archivoSalon.leerSalon(i);

        for (int j = 0; j < cantDisciplina; j++)
        {
            disciplina = archivo.leerDisciplina(j);

            if (salon.getId() == disciplina.getIdSalon())
            {
                disciplina.MostrarDisciplina();
            }
        }
    }
}

//void ordenarPorHorario(Disciplina* disciplina, int cantidad){
//    Disciplina aux;
//    for (int i = 0; i < cantidad - 1; i++)
//    {
//        for (int j = i + 1; j < cantidad; j++)
//        {
//            if (disciplina[i].getHorarioInicio() > disciplina[j].getHorarioInicio())
//            {
//                aux = disciplina[i];
//                disciplina[i] = disciplina[j];
//                disciplina[j] = aux;
//            }
//        }
//    }
//}

void mostrarVectorDisciplina(Disciplina* disciplina, int cant){
    for (int i = 0; i < cant; i++)
    {
        disciplina[i].MostrarDisciplina();
    }
}

///OTRAS FUNCIONES
std::string setPrecision(float p, int precision)
{
    std::string peso(std::to_string(p));
    peso.resize(precision);
    return peso;
}
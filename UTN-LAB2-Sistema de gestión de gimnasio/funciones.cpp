#include "Socio.h"
#include "Profesor.h"
#include "Disciplina.h"
#include "ArchivoSocios.h"
#include "ArchivoProfesor.h"
#include "ArchivoDisciplina.h"

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
            if (strcmp(socios[j].getNombre().c_str(), socios[j + 1].getNombre().c_str()) < 0)
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
            if (socios[j].getEdad() < socios[j + 1].getEdad())
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
    }
}


//std::string Socio::setPrecision(float p)
//{
//    std::string peso(std::to_string(p));
//    peso.resize(5);
//    return peso;
//}

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

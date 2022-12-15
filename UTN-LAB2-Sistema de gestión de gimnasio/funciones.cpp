#include "funciones.h"

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
                std::cout << std::endl;
            }
        }
    }
}

void mostrarVectorDisciplina(Disciplina* disciplina, int cantDisciplina, ClaseAsignada* clase, int cantidadClase){
    bool* vIdDisciplina = new bool[cantDisciplina] {};
    if (vIdDisciplina == nullptr) return;
    for (int x = 8;x < 24;x++) {
        bool hay = false;
        std::cout << "Clases de las " << x << " hs:"<<std::endl;
        for (int y = 0;y < cantidadClase;y++) {
            if (!vIdDisciplina[clase[y].getCodDisciplina() - 1] && clase[y].getHorarioInicio() == x) {
                hay = true;
                std::cout<<disciplina[clase[y].getCodDisciplina() - 1].getNombre() << std::endl;
                vIdDisciplina[clase[y].getCodDisciplina() - 1] = true;
            }
        }
        if (!hay) std::cout << "No hay clases." << std::endl;
        std::cout << std::endl;
    }
    delete[] vIdDisciplina;
}

int cantidadClaseAsignadaPorFecha(ClaseAsignada* clase, int cantidadClase, Fecha& fecha)
{
	int cantidad = 0;
    for (int x = 0;x < cantidadClase;x++) {
        if (clase[x].getFechaAsignada() == fecha) cantidad++;
    }
    return cantidad;
}

void copiarClaseAsignadaPorFecha(ClaseAsignada* clase, ClaseAsignada* vClase, int cantidadClase, Fecha& fecha)
{
	int j = 0;
	for (int i = 0; i < cantidadClase; i++)
	{
		if (clase[i].getFechaAsignada() == fecha)
		{
			vClase[j] = clase[i];
			j++;
		}
	}
}

///OTRAS FUNCIONES
std::string setPrecision(float p, int precision)
{
    std::string peso(std::to_string(p));
    peso.resize(precision);
    return peso;
}
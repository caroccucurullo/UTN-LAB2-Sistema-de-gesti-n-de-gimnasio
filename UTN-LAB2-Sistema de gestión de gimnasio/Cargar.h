#pragma once
#include "ArchivoSocios.h"

class Cargar
{
public:
	void CargarPersona(Socio& socio);
	void CargarPersona(Profesor& profesor);
	//Carga Socio con nro de socio automatico.
	void CargarSocio(Socio& socio);
	//Carga Profesor
	void cargarProfesor(Profesor& profesor);

	
	//Otras funciones
	bool validarDigitosDni(std::string cadena);
};


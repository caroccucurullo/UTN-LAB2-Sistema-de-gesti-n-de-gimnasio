#include "Persona.h"

Persona::Persona(std::string n, std::string a, Fecha nac, std::string d, Contacto contacto) {
	strcpy(_nombre, n.c_str());
	strcpy(_apellido, a.c_str());
	_fnac = nac;
	_edad = calcularEdad();
	strcpy(_dni, d.c_str());
	_contacto = contacto;
	_estado = true;
}

int Persona::calcularEdad()
{
	Fecha hoy;
	hoy.establecerFechaHoy();
	_edad = hoy.getAnio() - _fnac.getAnio();
	if (hoy.getMes() < _fnac.getMes())
		_edad--;
	else if (hoy.getMes() == _fnac.getMes() && hoy.getDia() < _fnac.getDia())
		_edad--;
	return _edad;
}

void Persona::MostrarPersona()
{
	std::cout << "Nombre: " << _nombre << std::endl;
	std::cout << "Apellido: " << _apellido << std::endl;
	std::cout << "Fecha de nacimiento: " << getFechaNac().toString() << std::endl;
	std::cout << "Edad: " << _edad << std::endl;
	std::cout << "DNI: " << _dni << std::endl;
	std::cout << "Contacto: " << std::endl;
	getContacto().Mostrar();
}

std::string Persona::MostrarPersonaFormatoComas() {
	
	std::string cadena;
	cadena = getNombre() + "," + getApellido() + "," + getFechaNac().toString() + "," + std::to_string(getEdad()) + "," + getDni() + "," + getContacto().MostrarFormatoPorComas();
	return cadena;
}


void Persona::CargarPersona() {
	std::cin.ignore();
	std::string cadena;
	std::cout << "Nombre: ";
	std::getline(std::cin, cadena);
	setNombre(cadena);
	std::cout << "Apellido: ";
	std::getline(std::cin, cadena);
	setApellido(cadena);
	std::cout << "Fecha de nacimiento: "<<std::endl;
	_fnac.Cargar();
	/*std::cout << "Edad: ";
	std::cin >> _edad;*/
	_edad = calcularEdad();
	std::cin.ignore();
	std::cout << "DNI: ";
	std::getline(std::cin, cadena);
	setDni(cadena);
	std::cout << "Contacto: "<<std::endl;
	_contacto.cargar();
}

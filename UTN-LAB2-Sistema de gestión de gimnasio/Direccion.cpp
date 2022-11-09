#include "Direccion.h"

Direccion::Direccion(std::string calle, std::string num, std::string loc)
{
	strcpy(_calle,calle.c_str());
	strcpy(_num,num.c_str());
	strcpy(_localidad,loc.c_str());
}

void Direccion::setCalle(std::string calle)
{
	strcpy(_calle, calle.c_str());
}

void Direccion::setNum(std::string num)
{
	strcpy(_num, num.c_str());
}

void Direccion::setLocalidad(std::string loc)
{
	strcpy(_localidad, loc.c_str());
}

std::string Direccion::getCalle()
{
	std::string calle(_calle);
	return calle;
}

std::string Direccion::getNum()
{
	std::string num(_num);
	return num;
}

std::string Direccion::getLocalidad()
{
	std::string localidad(_localidad);
	return localidad;
}

std::string Direccion::mostrar()
{
	std::string cadena;
	cadena = getCalle() + "," + getNum() + "," + getLocalidad();
	return cadena;
}

void Direccion::cargar()
{
	std::string cadena;
	//std::cin.ignore();
	std::cout << "Calle: ";
	std::getline(std::cin, cadena);
	setCalle(cadena);
	std::cout << "Numero: ";
	std::getline(std::cin, cadena);
	setNum(cadena);
	std::cout << "Localidad: ";
	std::getline(std::cin, cadena);
	setLocalidad(cadena);
}

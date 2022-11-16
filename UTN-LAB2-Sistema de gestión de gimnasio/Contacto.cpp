#include "Contacto.h"
Contacto::Contacto(std::string calle, std::string num, std::string loc, std::string tel, std::string email)
{
	strcpy(_calle, calle.c_str());
	strcpy(_num, num.c_str());
	strcpy(_localidad, loc.c_str());
	strcpy(_tel, tel.c_str());
	strcpy(_email, email.c_str());
}

void Contacto::setCalle(std::string calle)
{
	strcpy(_calle, calle.c_str());
}

void Contacto::setNum(std::string num)
{
	strcpy(_num, num.c_str());
}

void Contacto::setLocalidad(std::string loc)
{
	strcpy(_localidad, loc.c_str());
}

void Contacto::setTel(std::string tel)
{
	strcpy(_tel, tel.c_str());
}

void Contacto::setEmail(std::string email)
{
	strcpy(_email, email.c_str());
}

std::string Contacto::getCalle()
{
	std::string calle(_calle);
	return calle;
}

std::string Contacto::getNum()
{
	std::string num(_num);
	return num;
}

std::string Contacto::getLocalidad()
{
	std::string localidad(_localidad);
	return localidad;
}

std::string Contacto::getTel()
{
	std::string tel(_tel);
	return tel;
}

std::string Contacto::getEmail()
{
	std::string email(_email);
	return email;
}

std::string Contacto::MostrarFormatoPorComas()
{
	std::string cadena;
	cadena = getCalle() + "," + getNum() + "," + getLocalidad() + "," + getTel() + "," + getEmail();
	return cadena;
}

void Contacto::Mostrar()
{
	std::cout << "Calle: "<<_calle<<std::endl;
	std::cout << "Numero: "<<_num<<std::endl;
	std::cout << "Localidad: "<<_localidad<<std::endl;
	std::cout << "Telefono: "<<_tel<<std::endl;
	std::cout << "Email: "<<_email<<std::endl;
}

void Contacto::cargar()
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
	std::cout << "Telefono: ";
	std::getline(std::cin, cadena);
	setTel(cadena);
	std::cout << "Email: ";
	std::getline(std::cin, cadena);
	setEmail(cadena);
}

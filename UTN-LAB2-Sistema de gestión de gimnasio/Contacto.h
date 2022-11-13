#pragma once
#include <iostream>
#include <string>
#include <cstring>
class Contacto
{
private:
	char _calle[30], _num[5], _localidad[50], _tel[15], _email[50];
public:
	Contacto(std::string calle = "", std::string num = "", std::string loc = "", std::string tel="", std::string email="");
	void setCalle(std::string calle);
	void setNum(std::string num);
	void setLocalidad(std::string loc);
	void setTel(std::string tel);
	void setEmail(std::string email);

	std::string getCalle();
	std::string getNum();
	std::string getLocalidad();
	std::string getTel();
	std::string getEmail();

	std::string MostrarFormatoPorComas();
	void Mostrar();
	void cargar();
};


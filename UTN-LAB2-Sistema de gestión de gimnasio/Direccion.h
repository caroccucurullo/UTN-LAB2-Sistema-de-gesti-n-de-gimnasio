#pragma once
#include <iostream>
#include <string>
#include <cstring>
class Direccion
{
private:
	char _calle[30], _num[5], _localidad[50];
public:
	Direccion(std::string calle="",std::string num="",std::string loc="");
	void setCalle(std::string calle);
	void setNum(std::string num);
	void setLocalidad(std::string loc);

	std::string getCalle();
	std::string getNum();
	std::string getLocalidad();

	std::string mostrar();
	void cargar();
};


#pragma once
#include <iostream>
#include "Fecha.h"
class ClaseAsignada
{
private:
	int _codDisciplina, _nroSocio, _idSalon;
	Fecha _fechaAsignada;
	bool _estado;
public:
	ClaseAsignada(int codDisciplina = 0, int nroSocio = 0,int idSalon=0, Fecha fechaAsignada = Fecha());
	void setCodDisciplina(int cod) { _codDisciplina = cod; }
	void setNroSocio(int nSocio) { _nroSocio = nSocio; }
	void setIdSalon(int idSalon) { _idSalon = idSalon; }
	void setFechaAsignada(Fecha fA) { _fechaAsignada = fA; }
	void setEstado(bool estado) { _estado = estado; }

	int getCodDisciplina() { return _codDisciplina; }
	int getNroSocio() { return _nroSocio; }
	int getIdSalon() { return _idSalon; }
	Fecha getFechaAsignada() { return _fechaAsignada; }
	bool getEstado() { return _estado; }

	void mostrar();
};


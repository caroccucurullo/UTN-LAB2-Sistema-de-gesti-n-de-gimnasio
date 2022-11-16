#pragma once
#include <iostream>
#include "Fecha.h"
class ClaseAsignada
{
private:
	int _codDisciplina, _nroSocio;
	Fecha _fechaAsignada;
	bool _estado;
public:
	ClaseAsignada(int codDisciplina = 0, int nroSocio = 0, Fecha fechaAsignada = Fecha());
	void setCodDisciplina(int cod) { _codDisciplina = cod; }
	void setNroSocio(int nSocio) { _nroSocio = nSocio; }
	void setFechaAsignada(Fecha fA) { _fechaAsignada = fA; }
	void setEstado(bool estado) { _estado = estado; }

	int getCodDisciplina() { return _codDisciplina; }
	int getNroSocio() { return _nroSocio; }
	Fecha getFechaAsignada() { return _fechaAsignada; }
	bool getEstado() { return _estado; }

	void mostrar();
};


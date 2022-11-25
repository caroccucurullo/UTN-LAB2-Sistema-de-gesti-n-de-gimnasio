#pragma once
#include <iostream>
#include "Fecha.h"
class ClaseAsignada
{
private:
	int _codDisciplina, _nroSocio;
	int _idProfesor;
	int _horarioInicio;
	int _horarioFin;
	Fecha _fechaAsignada;
	bool _estado;
public:
	ClaseAsignada(int codDisciplina = 0, int nroSocio = 0,int idProf=0, int hIni=0, int hFin=0, Fecha fechaAsignada = Fecha());
	void setCodDisciplina(int cod) { _codDisciplina = cod; }
	void setNroSocio(int nSocio) { _nroSocio = nSocio; }
	int getIdProfesor() { return _idProfesor; }
	int getHorarioInicio() { return _horarioInicio; }
	int getHorarioFin() { return _horarioFin; }
	void setFechaAsignada(Fecha fA) { _fechaAsignada = fA; }
	void setEstado(bool estado) { _estado = estado; }

	int getCodDisciplina() { return _codDisciplina; }
	int getNroSocio() { return _nroSocio; }
	void setIdProfesor(int idProf) { _idProfesor = idProf; }
	void setHorarioInicio(int hIni) { _horarioInicio = hIni; }
	void setHorarioFin(int hFin) { _horarioFin = hFin; }
	Fecha getFechaAsignada() { return _fechaAsignada; }
	bool getEstado() { return _estado; }

	void mostrar();
	void cargar();
};


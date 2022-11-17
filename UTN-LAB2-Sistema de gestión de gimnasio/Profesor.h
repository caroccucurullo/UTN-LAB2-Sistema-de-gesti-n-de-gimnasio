#pragma once
#include <iostream>
#include <string.h>
#include <cstring>
#include "Persona.h"

/* Profesor : Persona:
-ID
-Disciplina
-Horario entrada
-Horario salida
-Fecha de ingreso
-Sueldo */

class Profesor : public Persona {

private:
    int _id;
    int _idDisciplina;
    int _turnoId;
    Fecha _fIngreso;
    Fecha _fEgreso;
    float _sueldo;

public:
    Profesor(int id = 0, int idDis = 0, int turnoId = 0, Fecha fIn = Fecha(), float s = 0);
    int getId() { return _id; }
    int getIdDisciplina() { return _idDisciplina; }
    int getTurnoId() { return _turnoId; }
	Fecha getFechaIngreso() { return _fIngreso; }
	Fecha getFechaEgreso() { return _fEgreso; }
    float getSueldo() { return _sueldo; }
	
    void setId(int id) { _id = id; }
    void setIdDisciplina(int id) { _idDisciplina = id; }
    void setTurnoId(int turnoId) { _turnoId = turnoId; }
	void setFechaIngreso(Fecha fi) { _fIngreso = fi; }
    void setFechaEgreso(Fecha fe) { _fEgreso = fe; }
    void setSueldo(float s) { _sueldo = s; }
	
    void MostrarProfesor();
	void cargarProfesor();


};

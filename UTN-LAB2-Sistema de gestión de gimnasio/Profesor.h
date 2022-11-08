#ifndef PROFESOR_H_INCLUDED
#define PROFESOR_H_INCLUDED

#include <iostream>
#include <string.h>
#include "Persona.h"
using namespace std;

/* Profesor : Persona:
    -ID
-Disciplina
-Horario entrada
-Horario salida
-Fecha de ingreso
-Sueldo */

class Profesor : public Persona {

private:
    int id;
    char disciplina[20];
    int horarioEntrada;
    int horarioSalida;
    char fechaIngreso[20];
    float sueldo;
    Persona persona;

public:
    Profesor(int i = 0, char d[20], int he = 0, int hs = 0, char fi[20], float s = 0);
    int getId() { return id; }
    const char *getDisciplina() { return disciplina; }
    int getHorarioEntrada() { return horarioEntrada; }
    int getHorarioSalida() { return horarioSalida; }
    const char *getFechaIngreso() { return fechaIngreso; }
    float getSueldo() { return sueldo; }
    void setId(int i) { id = i; }
    void setDisciplina(const char *d) { strcpy(disciplina, d); }
    void setHorarioEntrada(int he) { horarioEntrada = he; }
    void setHorarioSalida(int hs) { horarioSalida = hs; }
    void setFechaIngreso(const char *fi) { strcpy(fechaIngreso, fi); }
    void setSueldo(float s) { sueldo = s; }
    void MostrarProfesor();
	void cargarProfesor();
};

#endif // PROFESOR_H_INCLUDED

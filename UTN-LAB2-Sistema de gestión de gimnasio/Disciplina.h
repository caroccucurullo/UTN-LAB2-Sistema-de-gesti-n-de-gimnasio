#pragma once
#include <iostream>
#include <string.h>
#include <cstring>

class Disciplina {

private:
    int codigo;
    int horarioInicio;
    int horarioFin;
    char nombre[20];
    int idProfesor;
    int salon;

public:
    Disciplina(int c = 0, int hi = 0, int hf = 0, const char* n="", int id = 0, int s = 0);
    int getCodigo() { return codigo; }
    int getHorarioInicio() { return horarioInicio; }
    int getHorarioFin() { return horarioFin; }
    const char *getNombre() { return nombre; }
    int getIdProfesor() { return idProfesor; }
    int getSalon() { return salon; }
    void setCodigo(int c) { codigo = c; }
    void setHorarioInicio(int hi) { horarioInicio = hi; }
    void setHorarioFin(int hf) { horarioFin = hf; }
    void setNombre(const char *n) { strcpy(nombre, n); }
    void setIdProfesor(int id) { idProfesor = id; }
    void setSalon(int s) { salon = s; }
    void MostrarDisciplina();
};



#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

class Disciplina {

private:
    int _codigo;
    int _horarioInicio;
    int _horarioFin;
    char _nombre[20];
    int _idProfesor;
    int _idSalon;
    bool estado;

public:
    Disciplina(int cod = 0, int hIni = 0, int hFin = 0, std::string nombre="", int idProf = 0, int idSalon = 0);
	
    int getCodigo() { return _codigo; }
    int getHorarioInicio() { return _horarioInicio; }
    int getHorarioFin() { return _horarioFin; }
    std::string getNombre() { std::string nombre(_nombre); return nombre; }
    int getIdProfesor() { return _idProfesor; }
    int getSalon() { return _idSalon; }
    bool getEstado() { return estado; }
	
    void setCodigo(int cod) { _codigo = cod; }
    void setHorarioInicio(int hIni) { _horarioInicio = hIni; }
    void setHorarioFin(int hFin) { _horarioFin = hFin; }
    void setNombre(std::string nombre) { strcpy(_nombre, nombre.c_str()); }
    void setIdProfesor(int idProf) { _idProfesor = idProf; }
    void setIdSalon(int idSalon) { _idSalon = idSalon; }
    void setEstado(bool e) { estado = e; }
	
    void MostrarDisciplina();
    std::string MostrarDisciplinasDatos();
    void CargarDisciplina();
};



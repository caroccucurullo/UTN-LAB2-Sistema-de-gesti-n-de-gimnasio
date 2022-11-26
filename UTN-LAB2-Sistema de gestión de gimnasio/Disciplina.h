#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

class Disciplina {

private:
    int _codigo;
    char _nombre[20];
    int _idSalon;
    bool estado;

public:
    Disciplina(int cod = 0, std::string nombre="", int idSalon = 0);
	
    int getCodigo() { return _codigo; }
    
    std::string getNombre() { std::string nombre(_nombre); return nombre; }
    
    int getIdSalon() { return _idSalon; }
    bool getEstado() { return estado; }
	
    void setCodigo(int cod) { _codigo = cod; }
    
    void setNombre(std::string nombre) { strcpy(_nombre, nombre.c_str()); }
    
    void setIdSalon(int idSalon) { _idSalon = idSalon; }
    void setEstado(bool e) { estado = e; }
	
    void MostrarDisciplina();
    std::string MostrarDisciplinasFormatoComas();
    void CargarDisciplina();
};



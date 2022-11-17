#pragma once
#include <iostream>
#include <string>
#include <cstring>

class Turno {
    private:
        int _idTurno;
        char _nombre[20];
    public:
        //Turno(int idTurno = 0, std::string nombre = "");
        void setIdTurno(int idTurno) { _idTurno = idTurno; }
        void setNombre(std::string nombre) { strcpy(_nombre, nombre.c_str()); }
        int getIdTurno() { return _idTurno; }
        std::string getNombre() { return _nombre; }
        
        void MostrarTurno();
        void CargarTurno();
};
#pragma once
#include<iostream>
#include <string>

class Fecha{
    public:
        int  getDia();
        int  getMes();
        int  getAnio();
        void setDia(int dia);
        void setMes(int mes);
        void setAnio(int anio);
             Fecha(int dia, int mes, int anio);
             Fecha();
        std::string toString();
        void Cargar();
    private:
        int _dia, _mes, _anio;

};


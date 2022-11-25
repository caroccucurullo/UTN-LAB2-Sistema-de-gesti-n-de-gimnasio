#include "fecha.h"
#include <ctime>
using namespace std;

int  Fecha::getDia(){
    return _dia;
}
int  Fecha::getMes(){
    return _mes;
}
int  Fecha::getAnio(){
    return _anio;
}
void Fecha::setDia(int dia){
    /*while (dia < 1 || dia>31) {
		std::cout << "Dia invalido, ingrese nuevamente: ";
		std::cin >> dia;
    }*/
    switch (getMes())
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
    {
        while (dia < 1 || dia>31) {
            std::cout << "Dia invalido, ingrese nuevamente: ";
            std::cin >> dia;
        }
        _dia = dia;
    }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
    {
        while (dia < 1 || dia>30) {
            std::cout << "Dia invalido, ingrese nuevamente: ";
            std::cin >> dia;
        }
        _dia = dia;
    }
        break;
    case 2:
    {
        if (esBisiesto(getAnio())) {
            while (dia < 1 || dia>29) {
                std::cout << "Dia invalido, ingrese nuevamente: ";
                    std::cin >> dia;
            }
            _dia = dia;
        }
        else {
            while (dia < 1 || dia>28) {
                std::cout << "Dia invalido, anio bisiesto, ingrese nuevamente: ";
                std::cin >> dia;
            }
            _dia = dia;
        }
    }
        break;
    }
}
void Fecha::setMes(int mes){
    while (mes < 1 || mes>12) {
        std::cout << "Mes invalido, ingrese nuevamente: ";
        std::cin >> mes;
    }
    _mes = mes;
}
void Fecha::setAnio(int anio){
    while (anio < 1) {
        std::cout << "Anio invalido, ingrese nuevamente: ";
        std::cin >> anio;
    }
    _anio = anio;
}
Fecha::Fecha(int dia, int mes, int anio){
    _dia = dia;
    _mes = mes;
    _anio = anio;
}
Fecha::Fecha(){
    time_t rawtime;
    struct tm timeinfo;

    time (&rawtime);
    timeinfo = *(localtime (&rawtime));

    _dia = timeinfo.tm_mday;
    _mes = timeinfo.tm_mon + 1;
    _anio = timeinfo.tm_year + 1900;
}
string Fecha::toString(){
    string fecha;
    fecha = to_string(_dia) + "/" + to_string(_mes) + "/" + to_string(_anio);
    return fecha;
}

void Fecha::Cargar()
{
    int d,m,a;
    char letra;
    std::cout << "Dia: ";
    std::cin >> d;
    std::cout << "Mes: ";
    std::cin >> m;
    std::cout << "Anio: ";
    std::cin >> a;
    setAnio(a);
    setMes(m);
    setDia(d);

    std::cout << toString() << " Datos ingresados correctamente?(y/n): ";
    std::cin >> letra;
    while (letra!='y'&&letra!='n'&&letra!='Y'&&letra!='N')
    {
        std::cout << "Letra incorrecta. Escriba 'y' o 'n': ";
        std::cin >> letra;

    }
    if (letra == 'n' || letra == 'N') {
        Cargar();
    }
    else {
        return;
    }
}

void Fecha::establecerFechaHoy()
{
    time_t rawtime;
    struct tm timeinfo;

    time(&rawtime);
    timeinfo = *(localtime(&rawtime));

    _dia = timeinfo.tm_mday;
    _mes = timeinfo.tm_mon + 1;
    _anio = timeinfo.tm_year + 1900;
}

bool Fecha::esBisiesto(int a) {
    bool bisiesto = false;
    if (a % 4 == 0) bisiesto = true;
    if ((a % 100 == 0) && (a % 400 != 0)) bisiesto = false;
    return bisiesto;
}

bool Fecha::operator==(Fecha fecha)
{
    if (_dia == fecha.getDia() && _mes == fecha.getMes() && _anio == fecha.getAnio()) return true;
    return false;
}

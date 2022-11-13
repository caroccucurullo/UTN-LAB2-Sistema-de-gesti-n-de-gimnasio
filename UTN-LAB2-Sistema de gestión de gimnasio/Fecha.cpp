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
    _dia = dia;
}
void Fecha::setMes(int mes){
    _mes = mes;
}
void Fecha::setAnio(int anio){
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
    int num;
    std::cout << "Dia: ";
    std::cin >> num;
    setDia(num);
    std::cout << "Mes: ";
    std::cin >> num;
    setMes(num);
    std::cout << "Anio: ";
    std::cin >> num;
    setAnio(num);
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

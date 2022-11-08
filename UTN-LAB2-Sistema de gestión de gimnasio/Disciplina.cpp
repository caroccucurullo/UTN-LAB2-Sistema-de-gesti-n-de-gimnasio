#include <cstring>
#include <iostream>
#include "Disciplina.h"

Disciplina::Disciplina(int c, int hi, int hf, char n[20], int id, int s) {
    codigo = c;
    horarioInicio = hi;
    horarioFin = hf;
    strcpy(nombre, n);
    idProfesor = id;
    salon = s;
}

void Disciplina::MostrarDisciplina() {
    cout << "Codigo: " << codigo << endl;
    cout << "Horario inicio: " << horarioInicio << endl;
    cout << "Horario fin: " << horarioFin << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Id profesor: " << idProfesor << endl;
    cout << "Salon: " << salon << endl;
}

bool Disciplina::operator >(Disciplina& d) {
    if (codigo > d.codigo) {
        return true;
    }
    else {
        return false;
    }
}

bool Disciplina::operator ==(Disciplina& d) {
    if (codigo == d.codigo) {
        return true;
    }
    else {
        return false;
    }
}

istream& operator>>(istream& is, Disciplina& d) {
    cout << "Codigo: ";
    is >> d.codigo;
    cout << "Horario inicio: ";
    is >> d.horarioInicio;
    cout << "Horario fin: ";
    is >> d.horarioFin;
    cout << "Nombre: ";
    is >> d.nombre;
    cout << "Id profesor: ";
    is >> d.idProfesor;
    cout << "Salon: ";
    is >> d.salon;
    return is;
}

ostream& operator<<(ostream& os, Disciplina& d) {
    os << "Codigo: " << d.codigo << endl;
    os << "Horario inicio: " << d.horarioInicio << endl;
    os << "Horario fin: " << d.horarioFin << endl;
    os << "Nombre: " << d.nombre << endl;
    os << "Id profesor: " << d.idProfesor << endl;
    os << "Salon: " << d.salon << endl;
    return os;
}

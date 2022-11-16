#pragma once
#include <iostream>
#include <string>
#include <cstring>
/* MEMBRESÍA:
    -Nombre
    -Cantidad de clases
    -Valor
    -ID
 */

class Membresia {
private:
    char nombre[20];
    int cantidadClases;
    float valor;
    int id;
    bool estado;
public:
    Membresia(std::string n = "", int cc = 0, float v = 0, int i = 0);
    std::string getNombre() { std::string n(nombre); return n; }
    int getCantidadClases() { return cantidadClases; }
    float getValor() { return valor; }
    int getId() { return id; }
    bool getEstado() { return estado; }
	
    void setNombre(std::string n) { strcpy(nombre, n.c_str()); }
    void setCantidadClases(int cc) { cantidadClases = cc; }
    void setValor(float v) { valor = v; }
    void setId(int i) { id = i; }
    void setEstado(bool e) { estado = e; }
	
    void MostrarMembresia();
    std::string MostrarMembresiasDatos();
    void CargarMembresia();
};


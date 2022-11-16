#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
/* SALON:
    -ID
-Cupo
-Nombre */
class Salon {
private:
    int id;
    int cupo;
    char nombre[20];
    bool estado;
	
public:
    Salon(int i = 0, int c = 0, std::string n = "");
    int getId() { return id; }
    int getCupo() { return cupo; }
    std::string getNombre() { std::string n(nombre); return n; }
    bool getEstado() { return estado; }
	
    void setId(int i) { id = i; }
    void setCupo(int c) { cupo = c; }
    void setNombre(std::string n) { strcpy(nombre, n.c_str()); }
    void setEstado(bool estado) { estado = estado; }
	
    void MostrarSalon();
    std::string MostrarSalonesDatos();
    void CargarSalon();
};


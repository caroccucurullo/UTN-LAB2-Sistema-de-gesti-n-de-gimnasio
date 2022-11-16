#include "ArchivoSalones.h"

bool ArchivoSalones::guardarSalon(Salon& salon)
{
    FILE* p = fopen("salones.dat", "ab");
    if (p == nullptr) return false;
    bool ok = fwrite(&salon, sizeof(Salon), 1, p);
    fclose(p);
    return ok;
}

Salon ArchivoSalones::leerSalon(int nRegistro)
{
    Salon salon;
    FILE* p = fopen("salones.dat", "rb");
    if (p == nullptr) return false;
    fseek(p, nRegistro * sizeof(Salon), 0);
    bool leyo = fread(&salon, sizeof(Salon), 1, p);
    fclose(p);
    return salon;
}

bool ArchivoSalones::leerTodos(Salon* salon, int cantidad)
{
    FILE* p = fopen("salones.dat", "rb");
    if (p == nullptr) return false;
    bool leyo = fread(salon, sizeof(Salon), cantidad, p);
    fclose(p);
    return leyo;
}

bool ArchivoSalones::modificarSalon(Salon& salon, int nRegistro)
{
    FILE* p = fopen("salones.dat", "rb + ");
    if (p == nullptr) return false;
    fseek(p, nRegistro * sizeof(Salon), SEEK_SET);
    bool ok = fwrite(&salon, sizeof(Salon), 1, p);
    fclose(p);
    return ok;
}

int ArchivoSalones::getCantidad()
{
    int cant = 0;
    FILE* p = fopen("salones.dat", "rb");
    fseek(p, 0, 2);
    cant = ftell(p) / sizeof(Salon);
    fclose(p);
    return cant;
}

int ArchivoSalones::buscarRegPorNombre(std::string nombre)
{
    int cant = getCantidad();
    Salon salon;
    for (int x = 0;x < cant;x++) {
        salon = leerSalon(x);
        if (salon.getNombre() == nombre) return x;
    }
    return -1;
}

bool ArchivoSalones::bajaLogica(int nRegistro)
{
    Salon salon;
    salon = leerSalon(nRegistro);
    bool flag;
    FILE* p = fopen("salones.dat", "rb+");
    if (p == nullptr) return false;
    fseek(p, nRegistro * sizeof(Salon), 0);
    salon.setEstado(false);
    flag = fwrite(&salon, sizeof(Salon), 1, p);
    fclose(p);
    return flag;
}

bool ArchivoSalones::altaLogica(int nRegistro)
{
    Salon salon;
    salon = leerSalon(nRegistro);
    bool flag;
    FILE* p = fopen("salones.dat", "rb+");
    if (p == nullptr) return false;
    fseek(p, nRegistro * sizeof(Salon), 0);
    salon.setEstado(true);
    flag = fwrite(&salon, sizeof(Salon), 1, p);
    fclose(p);
    return flag;
}


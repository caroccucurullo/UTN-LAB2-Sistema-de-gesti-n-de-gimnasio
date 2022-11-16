#include "ArchivoSalon.h"

bool ArchivoSalon::guardarSalon(Salon& salon)
{
    FILE* p = fopen("salones.dat", "ab");
    if (p == nullptr) return false;
    bool ok = fwrite(&salon, sizeof(Salon), 1, p);
    fclose(p);
    return ok;
}

Salon ArchivoSalon::leerSalon(int nRegistro)
{
    Salon salon;
    FILE* p = fopen("salones.dat", "rb");
    if (p == nullptr) return salon;
    fseek(p, nRegistro * sizeof(Salon), 0);
    bool leyo = fread(&salon, sizeof(Salon), 1, p);
    fclose(p);
    return salon;
}

bool ArchivoSalon::leerTodos(Salon* salon, int cantidad)
{
    FILE* p = fopen("salones.dat", "rb");
    if (p == nullptr) return false;
    bool leyo = fread(salon, sizeof(Salon), cantidad, p);
    fclose(p);
    return leyo;
}

bool ArchivoSalon::modificarSalon(Salon& salon, int nRegistro)
{
    FILE* p = fopen("salones.dat", "rb + ");
    if (p == nullptr) return false;
    fseek(p, nRegistro * sizeof(Salon), SEEK_SET);
    bool ok = fwrite(&salon, sizeof(Salon), 1, p);
    fclose(p);
    return ok;
}

int ArchivoSalon::getCantidad()
{
    int cant = 0;
    FILE* p = fopen("salones.dat", "rb");
    fseek(p, 0, 2);
    cant = ftell(p) / sizeof(Salon);
    fclose(p);
    return cant;
}

int ArchivoSalon::buscarRegPorNombre(std::string nombre)
{
    int cant = getCantidad();
    Salon salon;
    for (int x = 0;x < cant;x++) {
        salon = leerSalon(x);
        if (salon.getNombre() == nombre) return x;
    }
    return -1;
}

//CONSULTA POR CUPO
int ArchivoSalon::calcularCupoPorIDyHorario(int idSalon, int horario)
{
    Salon salon = leerSalon(idSalon);
    int cupo = salon.getCupo();

    ArchivoDisciplina arDis;
    Disciplina disciplina = arDis.leerDisciplina(arDis.buscarRegPorSalonyHorario(idSalon, horario));

    ArchivoClaseAsignada arClA;
    ClaseAsignada clA;
    int cantClA = arClA.getCantidad();
    for (int x = 0;x < cantClA;x++) {
        clA = arClA.leerClaseAsignada(x);
        if (clA.getIdSalon() == salon.getId() && clA.getCodDisciplina() == disciplina.getIdSalon()) cupo--;
    }
    return cupo;
}

void ArchivoSalon::SalonPorCupoHorario()
{
    std::string cadena;
    std::cout << "Ingrese nombre Salon: ";
    std::getline(std::cin, cadena);
    int horario;
    std::cout << "Ingrese horario: ";
    std::cin >> horario;
    ArchivoSalon arSalon;
    Salon salon = arSalon.leerSalon(arSalon.buscarRegPorNombre(cadena));
    int idSalon = salon.getId();
    std::cout << "El cupo del salon " << salon.getNombre() << " en el horario de " << horario << "hs es " << calcularCupoPorIDyHorario(idSalon, horario) << "." << std::endl;
}

bool ArchivoSalon::bajaLogica(int nRegistro)
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

bool ArchivoSalon::altaLogica(int nRegistro)
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
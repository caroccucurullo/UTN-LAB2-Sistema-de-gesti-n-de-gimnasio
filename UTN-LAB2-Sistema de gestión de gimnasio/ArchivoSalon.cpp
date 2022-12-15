#include "ArchivoSalon.h"

bool ArchivoSalon::guardarSalon(Salon& salon)
{
    FILE* p = fopen("salones.dat", "ab");
    if (p == nullptr) return false;
    bool ok = fwrite(&salon, sizeof(Salon), 1, p);
    fclose(p);
    return ok;
}

void ArchivoSalon::guardarSalon()
{
	Salon salon;
    salon.CargarSalon();
	if (guardarSalon(salon))
		std::cout << "Salon guardado correctamente" << std::endl;
	else
        std::cout << "Error al guardar el salon" << std::endl;
}

Salon ArchivoSalon::leerSalon(int nRegistro)
{
    Salon salon;
    FILE* p = fopen("salones.dat", "rb");
    if (p == nullptr) return salon;
    fseek(p, nRegistro * sizeof(Salon), 0);
    fread(&salon, sizeof(Salon), 1, p);
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

void ArchivoSalon::modificarSalon()
{
    std::string cadena;
	std::cout << "Ingrese el nombre del salon a modificar: ";
    std::cin.ignore();
	std::getline(std::cin, cadena);
    std::cout << "Ingrese modificaciones a continuacion..." << std::endl;
    Salon salon;
    salon.CargarSalon();
	if (modificarSalon(salon, buscarRegPorNombre(cadena)))
		std::cout << "Salon modificado correctamente" << std::endl;
	else
		std::cout << "Error al modificar el salon" << std::endl;
}

int ArchivoSalon::getCantidad()
{
    int cant = 0;
    FILE* p = fopen("salones.dat", "rb");
    if (p == nullptr) return cant;
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

void ArchivoSalon::SalonPorCupoHorario()
{
    ArchivoDisciplina arDis;
    int cantDisciplina = arDis.getCantidad();
    int cantSalon = getCantidad();
    if (cantSalon > 0 && cantDisciplina > 0) {
        Disciplina* vDis = new Disciplina[cantDisciplina];
        if (vDis == nullptr) return;
        arDis.leerTodas(vDis, cantDisciplina);
        std::string cadena;
        Fecha fecha;
        int horario;
        std::cout << "Ingrese nombre del Salon: ";
        std::cin.ignore();
        std::getline(std::cin, cadena);
        std::cout << "Ingrese fecha: "<<std::endl;
        fecha.Cargar();
        std::cout << "Ingrese horario: ";
        std::cin >> horario;
        Salon salon = leerSalon(buscarRegPorNombre(cadena));
        int resultado = calcularCupoPorHorario(salon, horario, fecha, vDis);
		system("cls");
        std::cout << "Fecha " << fecha.toString() << std::endl;
		std::cout << "El cupo del salon " << salon.getNombre() << " en el horario " << horario << "hs es de " << resultado<<" lugares." << std::endl;
    }
    else {
        std::cout << "No hay registros en el archivo." << std::endl;
    }
}

int ArchivoSalon::calcularCupoPorHorario(Salon& salon, int horario, Fecha& fecha, Disciplina* vDis)
{
    int cupo = salon.getCupo();
    ArchivoClaseAsignada arCla;
    int cantCla = arCla.getCantidad();
	ClaseAsignada* vCla = new ClaseAsignada[cantCla];
    if (vCla == nullptr) return -1;
    arCla.leerTodos(vCla, cantCla);
    for (int x = 0;x < cantCla;x++) {
        if (vCla[x].getFechaAsignada() == fecha && vCla[x].getHorarioInicio() == horario) {
            if (vDis[vCla[x].getCodDisciplina() - 1].getIdSalon() == salon.getId()) {
                cupo--;   
            }
        }
    }
	return cupo;
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

void ArchivoSalon::bajaSalon()
{
    std::string nombre;
    std::cout << "Ingrese nombre de salon a dar de baja: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);
    if (bajaLogica(buscarRegPorNombre(nombre))) std::cout << "Salon dado de baja." << std::endl;
    else std::cout << "Error al dar de baja." << std::endl;
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

void ArchivoSalon::altaSalon()
{
    std::string nombre;
    std::cout << "Ingrese nombre de salon a dar de alta: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);
    if (altaLogica(buscarRegPorNombre(nombre))) std::cout << "Salon dado de alta." << std::endl;
    else std::cout << "Error al dar de alta." << std::endl;
}

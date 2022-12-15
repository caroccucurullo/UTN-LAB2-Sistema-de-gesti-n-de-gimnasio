#include "ArchivoDisciplina.h"
#include "ArchivoSalon.h"
#include "funciones.h"

bool ArchivoDisciplina::guardarDisciplina(Disciplina& disciplina)
{
    FILE* pDis = fopen("disciplinas.dat", "ab");
    if (pDis == nullptr) return false;
    bool ok = fwrite(&disciplina, sizeof(Disciplina), 1, pDis);
    fclose(pDis);
    return ok;
}
void ArchivoDisciplina::guardarDisciplina()
{
    Disciplina disciplina;
    disciplina.CargarDisciplina();
	if (guardarDisciplina(disciplina))
		std::cout << "Disciplina guardada correctamente" << std::endl;
	else
        std::cout << "Error al guardar la disciplina" << std::endl;
}
Disciplina ArchivoDisciplina::leerDisciplina(int nRegistro)
{
    Disciplina disciplina;
    FILE* pDis = fopen("disciplinas.dat", "rb");
    if (pDis == nullptr) return disciplina;
    fseek(pDis, nRegistro * sizeof(Disciplina), 0);
    fread(&disciplina, sizeof(Disciplina), 1, pDis);
    fclose(pDis);
    return disciplina;
}
bool ArchivoDisciplina::leerTodas(Disciplina* disciplina, int cantidad)
{
    FILE* pDis = fopen("disciplinas.dat", "rb");
    if (pDis == nullptr) return false;
    bool leyo = fread(disciplina, sizeof(Disciplina), cantidad, pDis);
    fclose(pDis);
    return leyo;
}
bool ArchivoDisciplina::modificarDisciplina(Disciplina& disciplina, int nRegistro)
{
    FILE* p = fopen("disciplinas.dat", "rb+");
    if (p == nullptr) return false;
    fseek(p, nRegistro * sizeof(Disciplina), SEEK_SET);
    bool ok = fwrite(&disciplina, sizeof(Disciplina), 1, p);
    fclose(p);
    return ok;
}
void ArchivoDisciplina::modificarDisciplina()
{
    std::string nombre;
    std::cout << "Ingrese nombre de disciplina a modificar: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);
    std::cout << "Ingrese modificaciones a continuacion..." << std::endl;
    Disciplina disciplina;
    disciplina.CargarDisciplina();
	if (modificarDisciplina(disciplina, buscarRegPorNombre(nombre)))
		std::cout << "Disciplina modificada correctamente" << std::endl;
	else
		std::cout << "Error al modificar la disciplina" << std::endl;
	
}
int ArchivoDisciplina::getCantidad()
{
    int cant = 0;
    FILE* p = fopen("disciplinas.dat", "rb");
    if (p == nullptr) return cant;
    fseek(p, 0, 2);
    cant = ftell(p) / sizeof(Disciplina);
    fclose(p);
    return cant;
}
int ArchivoDisciplina::buscarRegPorCod(int cod)
{
    int cant = getCantidad();
    Disciplina disciplina;
    for (int x = 0;x < cant;x++) {
        disciplina = leerDisciplina(x);
        if (disciplina.getCodigo() == cod) return x;
    }
    return -1;
}
int ArchivoDisciplina::buscarRegPorNombre(std::string nombre)
{
    int cant = getCantidad();
    Disciplina disciplina;
    for (int x = 0;x < cant;x++) {
        disciplina = leerDisciplina(x);
        if (disciplina.getNombre() == nombre) return x;
    }
    return -1;
}

//int ArchivoDisciplina::buscarRegPorSalonyHorario(int idSalon, int horario)
//{
//    int cant = getCantidad();
//    Disciplina disciplina;
//    for (int x = 0;x < cant;x++) {
//        disciplina = leerDisciplina(x);
//        if (disciplina.getIdSalon()==idSalon&&disciplina.getHorarioInicio()==horario) return x;
//    }
//    return -1;
//}

//CONSULTA POR SALONES
void ArchivoDisciplina::disciplinasPorSalon()
{
    ArchivoSalon arSalon;
    std::string cadena;
    int cantDisciplina = getCantidad();
    int cantSalon = arSalon.getCantidad();
    if (cantDisciplina > 0 && cantSalon > 0) {
        Disciplina* vDisciplina = new Disciplina[cantDisciplina];
        if(vDisciplina==nullptr) {
            std::cout << "No se pudo abrir el archivo de registros." << std::endl;
            return;
        }
        leerTodas(vDisciplina, cantDisciplina);
        std::cout << "Ingrese nombre del Salon: ";
	    std::cin.ignore();
	    std::getline(std::cin, cadena);
        while (arSalon.buscarRegPorNombre(cadena) == -1) {
            std::cout << "Nombre incorrecto. Ingrese nuevamente: ";
            std::getline(std::cin, cadena);
        }
        system("cls");
        Salon salon = arSalon.leerSalon(arSalon.buscarRegPorNombre(cadena));
        std::cout << "Disciplinas del Salon " << salon.getNombre() << std::endl;
        for (int x = 0;x < cantDisciplina;x++) {
            if (vDisciplina[x].getIdSalon() == salon.getId()) {
				std::cout << vDisciplina[x].getNombre() << std::endl;
            }
        }
        delete[] vDisciplina;
    }
    else {
        std::cout << "No hay registros en el archivo." << std::endl;
    }
}

//CONSULTA POR HORARIO
void ArchivoDisciplina::disciplinasPorHorario()
{
    ArchivoClaseAsignada arCla;
	int cantCla = arCla.getCantidad();
	int cantDisciplina = getCantidad();
    if (cantDisciplina > 0 && cantCla > 0) {
		ClaseAsignada* vCla = new ClaseAsignada[cantCla];
        if(vCla==nullptr) {
            std::cout << "No se pudo abrir el archivo de registros." << std::endl;
            return;
        }
		Disciplina* vDisciplina = new Disciplina[cantDisciplina];
        if (vDisciplina == nullptr) {
            std::cout << "No se pudo abrir el archivo de registros." << std::endl;
            return;
        }
        bool* vIdDisciplina = new bool[cantDisciplina] {};
        if (vIdDisciplina == nullptr) return;
        bool hay = false;
        Fecha fecha;
        int horarioInicio;
		std::cout << "Ingrese fecha de la clase: " << std::endl;
        fecha.Cargar();
		std::cout << "Ingrese horario de inicio de la clase: ";
		std::cin >> horarioInicio;
        arCla.leerTodos(vCla, cantCla);
        leerTodas(vDisciplina, cantDisciplina);
		system("cls");
		std::cout << "Clases del " << fecha.toString() << " a las " << horarioInicio << std::endl;
        for (int x = 0;x < cantCla;x++) {
			if (vCla[x].getFechaAsignada() == fecha && vCla[x].getHorarioInicio() == horarioInicio) {
				for (int y = 0;y < cantDisciplina;y++) {
					if (!vIdDisciplina[vCla[x].getCodDisciplina()-1] && vCla[x].getCodDisciplina() == vDisciplina[y].getCodigo()) {
                        hay = true;
                        vIdDisciplina[vCla[x].getCodDisciplina() - 1] = true;
						std::cout << vDisciplina[y].getNombre() << std::endl;
					}
				}
			}
        }
		if (!hay) std::cout << "No hay clases asignadas en ese horario." << std::endl;
		delete[] vCla;
		delete[] vDisciplina;
        delete[] vIdDisciplina;
	}
    else {
		std::cout << "No hay registros en el archivo . " << std::endl;
    }
}

bool ArchivoDisciplina::bajaLogica(int nRegistro)
{
    Disciplina disciplina;
    disciplina = leerDisciplina(nRegistro);
    bool flag;
    FILE* p = fopen("disciplinas.dat", "rb+");
    if (p == nullptr) return false;
    fseek(p, nRegistro * sizeof(Disciplina), 0);
    disciplina.setEstado(false);
    flag = fwrite(&disciplina, sizeof(Disciplina), 1, p);
    fclose(p);
    return flag;
}
void ArchivoDisciplina::bajaDisciplina()
{
    std::string nombre;
    std::cout << "Ingrese nombre de disciplina a modificar: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);
	if (bajaLogica(buscarRegPorNombre(nombre))) std::cout << "Disciplina dada de baja" << std::endl;
	else std::cout << "No se pudo dar de baja" << std::endl;
}
bool ArchivoDisciplina::altaLogica(int nRegistro)
{
    Disciplina disciplina;
    disciplina = leerDisciplina(nRegistro);
    bool flag;
    FILE* p = fopen("disciplinas.dat", "rb+");
    if (p == nullptr) return false;
    fseek(p, nRegistro * sizeof(Disciplina), 0);
    disciplina.setEstado(true);
    flag = fwrite(&disciplina, sizeof(Disciplina), 1, p);
    fclose(p);
    return flag;
}

void ArchivoDisciplina::altaDisciplina()
{
    std::string nombre;
    std::cout << "Ingrese nombre de disciplina a modificar: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);
	if (altaLogica(buscarRegPorNombre(nombre))) std::cout << "Disciplina dada de alta" << std::endl;
	else std::cout << "No se pudo dar de alta" << std::endl;
}

void ArchivoDisciplina::ordenarPorDisciplina()
{
    ArchivoSalon archivoSalon;
    int cantDisciplina = getCantidad();
    int cantSalon = archivoSalon.getCantidad();

    mostrarDisciplinaPorSalon(cantDisciplina, cantSalon);
}

void ArchivoDisciplina::mostrarPorHorarioAscendente()
{
    ArchivoDisciplina archivoDisciplina;
	ArchivoClaseAsignada archivoClaseAsignada;
    int cantDisciplina = archivoDisciplina.getCantidad();
	int cantCla = archivoClaseAsignada.getCantidad();
    if (cantDisciplina > 0 && cantCla > 0) {
        Disciplina* disciplina= new Disciplina[cantDisciplina];
        if (disciplina == nullptr) return;
	    ClaseAsignada* claseAsignada= new ClaseAsignada[cantCla];
        if (claseAsignada == nullptr) return;
        archivoDisciplina.leerTodas(disciplina, cantDisciplina);
		archivoClaseAsignada.leerTodos(claseAsignada, cantCla);
        Fecha fecha;
        std::cout << "Ingrese fecha de la clase: " << std::endl;
        fecha.Cargar();
        int cantClaseAsignadaPorFecha = cantidadClaseAsignadaPorFecha(claseAsignada, cantCla, fecha);
        ClaseAsignada* vCla = new ClaseAsignada[cantClaseAsignadaPorFecha];
        if (vCla == nullptr) return;
        copiarClaseAsignadaPorFecha(claseAsignada, vCla, cantCla, fecha);

        system("cls");
        std::cout << "Fecha " << fecha.toString() << std::endl << std::endl;;
        mostrarVectorDisciplina(disciplina, cantDisciplina,vCla, cantClaseAsignadaPorFecha);

        delete[] disciplina;
        delete[] claseAsignada;
        delete[] vCla;
    }
    else {
        std::cout << "No hay registros en los archivos." << std::endl;
    }
}

#include "ArchivoDisciplina.h"

bool ArchivoDisciplina::guardarDisciplina(Disciplina& disciplina)
{
    FILE* p = fopen("disciplinas.dat", "ab");
    if (p == nullptr) return false;
    bool ok = fwrite(&disciplina, sizeof(Disciplina), 1, p);
    fclose(p);
    return ok;
}
Disciplina ArchivoDisciplina::leerDisciplina(int nRegistro)
{
    Disciplina disciplina;
    FILE* p = fopen("disciplinas.dat", "rb");
    if (p == nullptr) return disciplina;
    fseek(p, nRegistro * sizeof(Disciplina), 0);
    bool leyo = fread(&disciplina, sizeof(Disciplina), 1, p);
    fclose(p);
    return disciplina;
}
bool ArchivoDisciplina::leerTodas(Disciplina* disciplina, int cantidad)
{
    FILE* p = fopen("disciplinas.dat", "rb");
    if (p == nullptr) return false;
    bool leyo = fread(disciplina, sizeof(Disciplina), cantidad, p);
    fclose(p);
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
int ArchivoDisciplina::getCantidad()
{
    int cant = 0;
    FILE* p = fopen("disciplinas.dat", "rb");
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

int ArchivoDisciplina::buscarRegPorSalonyHorario(int idSalon, int horario)
{
    int cant = getCantidad();
    Disciplina disciplina;
    for (int x = 0;x < cant;x++) {
        disciplina = leerDisciplina(x);
        if (disciplina.getIdSalon()==idSalon&&disciplina.getHorarioInicio()==horario) return x;
    }
    return -1;
}

//CONSULTA POR SALONES
int ArchivoDisciplina::getCantidadSalon(std::string nombreSalon)
{
    ArchivoSalon arSalon;
	Salon salon = arSalon.leerSalon(arSalon.buscarRegPorNombre(nombreSalon));
	int cant = getCantidad();
	Disciplina disciplina;
	int cantSalon = 0;
	for (int x = 0;x < cant;x++) {
		disciplina = leerDisciplina(x);
		if (disciplina.getIdSalon() == salon.getId()) cantSalon++;
	}
	return cantSalon;
}
void ArchivoDisciplina::disciplinasPorSalon()
{
    std::string cadena;
    std::cout << "Ingrese nombre del Salon: ";
	std::cin >> cadena;
	int cant = getCantidadSalon(cadena);
	Disciplina* vDisciplina = new Disciplina[cant];
	if (vDisciplina == nullptr) return;
	copiarDisciplinaPorSalon(vDisciplina, cadena);
	mostrarDisciplina(vDisciplina, cant);
	delete[] vDisciplina;
}
void ArchivoDisciplina::copiarDisciplinaPorSalon(Disciplina* vDisciplina, std::string nombreSalon)
{
    ArchivoSalon arSalon;
    Salon salon = arSalon.leerSalon(arSalon.buscarRegPorNombre(nombreSalon));
    int cant = getCantidad();
    Disciplina disciplina;
    for (int x = 0;x < cant;x++) {
        disciplina = leerDisciplina(x);
		if (disciplina.getIdSalon() == salon.getId()) vDisciplina[x] = disciplina;
    }
}

//CONSULTA POR HORARIO
int ArchivoDisciplina::getCantidadPorHorario(int horarioInicio)
{
	int cant = getCantidad(), cantPorHorario = 0;
	Disciplina disciplina;
	for (int x = 0;x < cant;x++) {
		disciplina = leerDisciplina(x);
		if (disciplina.getHorarioInicio() == horarioInicio) cantPorHorario++;
	}
	return cantPorHorario;
}
void ArchivoDisciplina::disciplinasPorHorario()
{
    int horarioInicio;
    std::cout << "Ingrese horario: ";
    std::cin >> horarioInicio;
	int cantHorario = getCantidadPorHorario(horarioInicio);
	Disciplina* vDisciplina = new Disciplina[cantHorario];
	if (vDisciplina == nullptr) return;
	copiarDisciplinaHorario(vDisciplina, horarioInicio);
	mostrarDisciplina(vDisciplina, cantHorario);
	delete[] vDisciplina;
}
void ArchivoDisciplina::copiarDisciplinaHorario(Disciplina* vDisciplina, int horarioInicio)
{
    int cant = getCantidad();
    Disciplina disciplina;
    for (int x = 0;x < cant;x++) {
        disciplina = leerDisciplina(x);
        if (disciplina.getHorarioInicio() == horarioInicio) vDisciplina[x] = disciplina;
    }
}
void ArchivoDisciplina::mostrarDisciplina(Disciplina* vDisciplina, int cant)
{
    for (int x = 0;x < cant;x++) {
        vDisciplina[x].MostrarDisciplina();
        std::cout << std::endl;
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
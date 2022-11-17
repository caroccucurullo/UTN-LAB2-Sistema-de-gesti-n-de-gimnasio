# include "Turno.h"
# include "ArchivoTurno.h"

bool ArchivoTurno::guardarTurno(Turno& turno) {
    FILE* p = fopen("turnos.dat", "ab");
	if (p == nullptr) return false;
	bool ok = fwrite(&turno, sizeof(Turno), 1, p);
	fclose(p);
	return ok;
}

Turno ArchivoTurno::leerTurno(int nRegistro) {
    Turno turno;
    FILE* p = fopen("turnos.dat", "rb");
    if (p == nullptr) return turno;
    fseek(p, nRegistro * sizeof(Turno), 0);
    bool leyo = fread(&turno, sizeof(Turno), 1, p);
    fclose(p);
    return turno;
}

bool ArchivoTurno::leerTodos(Turno* turno, int cantidad) {
    FILE* p = fopen("turnos.dat", "rb");
    if (p == nullptr) return false;
    bool leyo = fread(turno, sizeof(Turno), cantidad, p);
    fclose(p);
    return leyo;
}

bool ArchivoTurno::modificarTurno(Turno& turno, int nRegistro) {
    FILE* p = fopen("turnos.dat", "rb+");
    if (p == nullptr) return false;
    fseek(p, nRegistro * sizeof(Turno), SEEK_SET);
    bool ok = fwrite(&turno, sizeof(Turno), 1, p);
    fclose(p);
    return ok;
}

int ArchivoTurno::getCantidad() {
    int cant = 0;
    FILE* p = fopen("turnos.dat", "rb");
    fseek(p, 0, 2);
    cant = ftell(p) / sizeof(Turno);
    fclose(p);
    return cant;
}
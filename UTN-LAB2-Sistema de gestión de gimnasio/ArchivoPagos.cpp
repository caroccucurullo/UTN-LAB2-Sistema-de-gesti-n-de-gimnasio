#include "ArchivoPagos.h"


bool ArchivoPagos::guardarPago(Pago& pago)
{
	FILE* p = fopen("pagos.dat", "ab");
    if (p == nullptr) return false;
    bool ok = fwrite(&pago, sizeof(Pago), 1, p);
    fclose(p);
    return ok;
}

Pago ArchivoPagos::leerPago(int nRegistro)
{
	Pago pago;
	FILE* p = fopen("pagos.dat", "rb");
	if (p == nullptr) return pago;
	fseek(p, nRegistro * sizeof(Pago), 0);
	bool leyo = fread(&pago, sizeof(Pago), 1, p);
	fclose(p);
	return pago;
}

bool ArchivoPagos::leerTodos(Pago* pago, int cantidad)
{
	FILE* p = fopen("pagos.dat", "rb");
	if (p == nullptr) return false;
	bool leyo = fread(pago, sizeof(Pago), cantidad, p);
	fclose(p);
	return leyo;
}

bool ArchivoPagos::modificarPago(Pago& pago, int nRegistro)
{
	FILE* p = fopen("pagos.dat", "rb+");
	if (p == nullptr) return false;
	fseek(p, nRegistro * sizeof(Pago), SEEK_SET);
	bool ok = fwrite(&pago, sizeof(Pago), 1, p);
	fclose(p);
	return ok;
}

int ArchivoPagos::getCantidad()
{
	int cant = 0;
	FILE* p = fopen("pagos.dat", "rb");
	fseek(p, 0, 2);
	cant = ftell(p) / sizeof(Pago);
	fclose(p);
	return cant;
}
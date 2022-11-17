#include "ArchivoPagos.h"


bool ArchivoPagos::guardarPago(Pago& pago)
{
	FILE* p = fopen("pagos.dat", "ab");
    if (p == nullptr) return false;
    bool ok = fwrite(&pago, sizeof(Pago), 1, p);
    fclose(p);
    return ok;
}

void ArchivoPagos::guardarPago()
{
	Pago pago;
	pago.CargarPago();
	if (guardarPago(pago)) std::cout << "Guardado correctamente." << std::endl;
	else std::cout << "Error al guardar." << std::endl;
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

void ArchivoPagos::modificarPago()
{
	int nroSocio;
	std::cout << "Ingrese el nro de socio de pago a modificar: ";
	std::cin >> nroSocio;
	std::cout << "Ingrese modificaciones a continuacion..." << std::endl;
	Pago pago;
	pago.CargarPago();
	if (modificarPago(pago, buscarPorNroSocio(nroSocio))) std::cout << "Modificado correctamente." << std::endl;
	else std::cout << "Error al modificar." << std::endl;
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

int ArchivoPagos::buscarPorNroSocio(int nroSocio)
{
	int cant = getCantidad();
	Pago pago;
	for (int x = 0;x < cant;x++) {
		pago = leerPago(x);
		if (pago.getNroSocio() == nroSocio) return x;
	}
	return -1;
}

//INFORMES
void ArchivoPagos::recaudacionPorMembresia(int idM, int anio, int mes)
{
	std::cout << "Ingrese el id de la membresia: " <<std::endl;
	std::cin >> idM;
	std::cout <<  "Ingrese el anio: " << std::endl;
	std::cin >> anio;
	std::cout <<  "Ingrese el mes: " << std::endl;
	std::cin >> mes;
	
	int cant = getCantidad();
	Pago pago;
	float total = 0;
	
	for (int x = 0;x < cant;x++) {
		pago = leerPago(x);
		if (pago.getIdMembresia() == idM && pago.getFechaDePago().getAnio() == anio
			&& pago.getFechaDePago().getMes() == mes) {
			total += pago.getValor();
		}
	}

	std::cout << "Recaudacion de la membresia "<</*membresia*/ " del mes " << mes << " del anio " << anio << "es de : " << total << std::endl;
}

void ArchivoPagos::recaudacionAnual(int anio)
{
	std::cout << "Ingrese el anio: " << std::endl;
	std::cin >> anio;
	
	int cant = getCantidad();
	Pago pago;
	float total = 0;
	
	for (int x = 0;x < cant;x++) {
		pago = leerPago(x);
		if (pago.getFechaDePago().getAnio() == anio) {
			total += pago.getValor();
		}
	}

	std::cout << "Recaudacion del anio " << anio << "es de: " << total << std::endl;
}

void ArchivoPagos::recaudacionMensual(int anio, int mes)
{
	std::cout << "Ingrese el anio: " << std::endl;
	std::cin >> anio;
	std::cout << "Ingrese el mes: " << std::endl;
	std::cin >> mes;
	
	int cant = getCantidad();
	Pago pago;
	float total = 0;
	
	for (int x = 0;x < cant;x++) {
		pago = leerPago(x);
		if (pago.getFechaDePago().getAnio() == anio && pago.getFechaDePago().getMes() == mes) {
			total += pago.getValor();
		}
	}

	std::cout << "Recaudacion del mes " << mes << " del anio " << anio << "es de: " << total << std::endl;
}

void ArchivoPagos::membresiaMasVendidaAnual(int anio)
{
	std::cout << "Ingrese el anio: " << std::endl;
	std::cin >> anio;

	int cant = getCantidad();
	Pago pago;
	int idM = 0;
	int cantM = 0;
	int idM2 = 0;
	int cantM2 = 0;
	int idM3 = 0;
	int cantM3 = 0;
	
	for (int x = 0;x < cant;x++) {
		pago = leerPago(x);
		if (pago.getFechaDePago().getAnio() == anio) {
			switch (pago.getIdMembresia())
			{
			case 1:
				idM = pago.getIdMembresia();
				cantM++;
				break;
			case 2:
				idM2 = pago.getIdMembresia();
				cantM2++;
				break;
			case 3:
				idM3 = pago.getIdMembresia();
				cantM3++;
				break;
			}
		}
	}
	
	if (cantM > cantM2 && cantM > cantM3) {
		std::cout << "La membresia mas vendida del anio " << anio << " es la membresia " << idM << std::endl;
	}
	else if (cantM2 > cantM && cantM2 > cantM3) {
		std::cout << "La membresia mas vendida del anio " << anio << " es la membresia " << idM2 << std::endl;
	}
	else if (cantM3 > cantM && cantM3 > cantM2) {
		std::cout << "La membresia mas vendida del anio " << anio << " es la membresia " << idM3 << std::endl;
	}
	else {
		std::cout << "No hay membresia mas vendida" << std::endl;
	}
	
}

void ArchivoPagos::membresiaMasVendidaMensual(int anio, int mes)
{
	std::cout << "Ingrese el anio: " << std::endl;
	std::cin >> anio;
	std::cout << "Ingrese el mes: " << std::endl;
	std::cin >> mes;

	int cant = getCantidad();
	Pago pago;
	int idM = 0;
	int cantM = 0;
	int idM2 = 0;
	int cantM2 = 0;
	int idM3 = 0;
	int cantM3 = 0;

	for (int x = 0;x < cant;x++) {
		pago = leerPago(x);
		if (pago.getFechaDePago().getAnio() == anio && pago.getFechaDePago().getMes() == mes) {
			switch (pago.getIdMembresia())
			{
			case 1:
				idM = pago.getIdMembresia();
				cantM++;
				break;
			case 2:
				idM2 = pago.getIdMembresia();
				cantM2++;
				break;
			case 3:
				idM3 = pago.getIdMembresia();
				cantM3++;
				break;
			}
		}
	}

	if (cantM > cantM2 && cantM > cantM3) {
		std::cout << "La membresia mas vendida del mes " << mes << " del anio " << anio << " es la membresia " << idM << std::endl;
	}
	else if (cantM2 > cantM && cantM2 > cantM3) {
		std::cout << "La membresia mas vendida del mes " << mes << " del anio " << anio << " es la membresia " << idM2 << std::endl;
	}
	else if (cantM3 > cantM && cantM3 > cantM2) {
		std::cout << "La membresia mas vendida del mes " << mes << " del anio " << anio << " es la membresia " << idM3 << std::endl;
	}
	else {
		std::cout << "No hay membresia mas vendida" << std::endl;
	}
}


void ArchivoPagos::membresiaMenosVendidaAnual(int anio)
{
	std::cout << "Ingrese el anio: " << std::endl;
	std::cin >> anio;

	int cant = getCantidad();
	Pago pago;
	int idM = 0;
	int cantM = 0;
	int idM2 = 0;
	int cantM2 = 0;
	int idM3 = 0;
	int cantM3 = 0;

	for (int x = 0;x < cant;x++) {
		pago = leerPago(x);
		if (pago.getFechaDePago().getAnio() == anio) {
			switch (pago.getIdMembresia())
			{
			case 1:
				idM = pago.getIdMembresia();
				cantM++;
				break;
			case 2:
				idM2 = pago.getIdMembresia();
				cantM2++;
				break;
			case 3:
				idM3 = pago.getIdMembresia();
				cantM3++;
				break;
			}
		}
	}

	if (cantM < cantM2 && cantM < cantM3) {
		std::cout << "La membresia menos vendida del anio " << anio << " es la membresia " << idM << std::endl;
	}
	else if (cantM2 < cantM && cantM2 < cantM3) {
		std::cout << "La membresia menos vendida del anio " << anio << " es la membresia " << idM2 << std::endl;
	}
	else if (cantM3 < cantM && cantM3 < cantM2) {
		std::cout << "La membresia menos vendida del anio " << anio << " es la membresia " << idM3 << std::endl;
	}
	else {
		std::cout << "No hay membresia menos vendida" << std::endl;
	}
}

void ArchivoPagos::membresiaMenosVendidaMensual(int anio, int mes)
{
	std::cout << "Ingrese el anio: " << std::endl;
	std::cin >> anio;
	std::cout << "Ingrese el mes: " << std::endl;
	std::cin >> mes;

	int cant = getCantidad();
	Pago pago;
	int idM = 0;
	int cantM = 0;
	int idM2 = 0;
	int cantM2 = 0;
	int idM3 = 0;
	int cantM3 = 0;

	for (int x = 0;x < cant;x++) {
		pago = leerPago(x);
		if (pago.getFechaDePago().getAnio() == anio && pago.getFechaDePago().getMes() == mes) {
			switch (pago.getIdMembresia())
			{
			case 1:
				idM = pago.getIdMembresia();
				cantM++;
				break;
			case 2:
				idM2 = pago.getIdMembresia();
				cantM2++;
				break;
			case 3:
				idM3 = pago.getIdMembresia();
				cantM3++;
				break;
			}
		}
	}

	if (cantM < cantM2 && cantM < cantM3) {
		std::cout << "La membresia menos vendida del mes " << mes << " del anio " << anio << " es la membresia " << idM << std::endl;
	}
	else if (cantM2 < cantM && cantM2 < cantM3) {
		std::cout << "La membresia menos vendida del mes " << mes << " del anio " << anio << " es la membresia " << idM2 << std::endl;
	}
	else if (cantM3 < cantM && cantM3 < cantM2) {
		std::cout << "La membresia menos vendida del mes " << mes << " del anio " << anio << " es la membresia " << idM3 << std::endl;
	}
	else {
		std::cout << "No hay membresia menos vendida" << std::endl;
	}
}

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
	fread(&pago, sizeof(Pago), 1, p);
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

void ArchivoPagos::pagosDelMes()
{
	Fecha fechaActual;
	int cantPagoMes = getCantidadPagoMes(fechaActual);
	Pago* vPago = new Pago[cantPagoMes];
	if (vPago == nullptr) return;
	Pago pago;
	int cant = getCantidad();
	for (int x = 0;x < cant;x++) {
		pago = leerPago(x);
		if (pago.getFechaDePago().getMes() == fechaActual.getMes()) {
			vPago[x] = pago;
		}
	}
	for (int x = 0;x < cant;x++) {
		vPago[x].MostrarPago();
		std::cout << std::endl;
	}
	delete[] vPago;
}

int ArchivoPagos::getCantidadPagoMes(Fecha fechaActual)
{
	int cant = getCantidad();
	Pago pago;
	int contPagoMes = 0;
	for (int x = 0;x < cant;x++) {
		pago = leerPago(x);
		if (pago.getFechaDePago().getMes() == fechaActual.getMes()) contPagoMes++;
	}
	return contPagoMes;
}

void ArchivoPagos::consultarPago()
{
	std::string dni;
	std::cout << "Ingrese DNI a consultar: ";
	std::cin.ignore();
	std::getline(std::cin, dni);
	ArchivoSocios arSocio;
	Socio socio = arSocio.leerSocio(arSocio.buscarRegPorDni(dni));
	int cant = getCantidad();
	Pago pago, ultimoPago;
	for (int x = 0;x < cant;x++) {
		pago = leerPago(x);
		if (pago.getNroSocio() == socio.getNroSocio()) ultimoPago = pago;
	}
	std::cout << "El ultimo pago realizado fue el " << ultimoPago.getFechaDePago().toString() << std::endl;
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

void ArchivoPagos::pagosAnualesSocio()
{
	int anio;
	std::cout << "Ingrese anio a evaluar: ";
	std::cin >> anio;
	std::string dni;
	std::cout << "Ingrese DNI de socio a evaluar: ";
	std::cin.ignore();
	std::getline(std::cin, dni);
	ArchivoSocios arSocio;
	Socio socio = arSocio.leerSocio(arSocio.buscarRegPorDni(dni));
	Pago pago;
	int cant = getCantidad();
	float pagoAnual = 0;
	for (int x = 0;x < cant;x++) {
		pago = leerPago(x);
		if (pago.getNroSocio() == socio.getNroSocio() && pago.getFechaDePago().getAnio() == anio) pagoAnual += pago.getValor();
	}
	std::cout << "El pago Anual("<<anio<<") de " << socio.getDni() << " es de " << pagoAnual << "$." << std::endl;
}

void ArchivoPagos::pagosDelMes()
{
	Fecha fechaActual;
	int cantPagoMes = getCantidadPagoMes(fechaActual);
	Pago* vPago = new Pago[cantPagoMes];
	if (vPago == nullptr) return;
	Pago pago;
	int cant = getCantidad();
	for (int x = 0;x < cant;x++) {
		pago = leerPago(x);
		if (pago.getFechaDePago().getMes() == fechaActual.getMes()) {
			vPago[x] = pago;
		}
	}
	for (int x = 0;x < cant;x++) {
		vPago[x].MostrarPago();
		std::cout << std::endl;
	}
	delete[] vPago;
}
int ArchivoPagos::getCantidadPagoMes(Fecha fechaActual)
{
	int cant = getCantidad();
	Pago pago;
	int contPagoMes = 0;
	for (int x = 0;x < cant;x++) {
		pago = leerPago(x);
		if (pago.getFechaDePago().getMes() == fechaActual.getMes()) contPagoMes++;
	}
	return contPagoMes;
}

//INFORMES

void ArchivoPagos::pagosAnualesSocio()
{
	int anio;
	std::cout << "Ingrese anio a evaluar: ";
	std::cin >> anio;
	std::string dni;
	std::cout << "Ingrese DNI de socio a evaluar: ";
	std::cin.ignore();
	std::getline(std::cin, dni);
	ArchivoSocios arSocio;
	Socio socio = arSocio.leerSocio(arSocio.buscarRegPorDni(dni));
	Pago pago;
	int cant = getCantidad();
	float pagoAnual = 0;
	for (int x = 0;x < cant;x++) {
		pago = leerPago(x);
		if (pago.getNroSocio() == socio.getNroSocio() && pago.getFechaDePago().getAnio() == anio) pagoAnual += pago.getValor();
	}
	std::cout << "El pago Anual(" << anio << ") de " << socio.getDni() << " es de " << pagoAnual << "$." << std::endl;
}

void ArchivoPagos::recaudacionPorMembresia()
{
	int idM, anio, mes;
	
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

void ArchivoPagos::recaudacionAnual()
{
	int anio;
	
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

void ArchivoPagos::recaudacionMensual()
{
	int anio, mes;
	
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

void ArchivoPagos::membresiaMasVendidaAnual()
{
	int anio;
	
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

void ArchivoPagos::membresiaMasVendidaMensual()
{
	int anio, mes;
	
	std::cout << "Ingrese el anio: " << std::endl;
	std::cin >> anio;
	std::cout << "Ingrese el mes: " << std::endl;
	std::cin >> mes;

	int cant = getCantidad();
	Pago pago;
	int cantM = 0;
	int cantM2 = 0;
	int cantM3 = 0;

	for (int x = 0;x < cant;x++) {
		pago = leerPago(x);
		if (pago.getFechaDePago().getAnio() == anio && pago.getFechaDePago().getMes() == mes) {
			switch (pago.getIdMembresia())
			{
			case 1:
	
				cantM++;
				break;
			case 2:
	
				cantM2++;
				break;
			case 3:

				cantM3++;
				break;
			}
		}
	}

	if (cantM > cantM2 && cantM > cantM3) {
		std::cout << "La membresia mas vendida del mes " << mes << " del anio " << anio << " es la membresia ORO"<< std::endl;
	}
	else if (cantM2 > cantM && cantM2 > cantM3) {
		std::cout << "La membresia mas vendida del mes " << mes << " del anio " << anio << " es la membresia PLATA"<< std::endl;
	}
	else if (cantM3 > cantM && cantM3 > cantM2) {
		std::cout << "La membresia mas vendida del mes " << mes << " del anio " << anio << " es la membresia BRONCE" << std::endl;
	}
	else {
		std::cout << "No hay membresia mas vendida" << std::endl;
	}
}


void ArchivoPagos::membresiaMenosVendidaAnual()
{
	int anio;
	
	std::cout << "Ingrese el anio: " << std::endl;
	std::cin >> anio;

	int cant = getCantidad();
	Pago pago;

	int cantM = 0;
	int cantM2 = 0;
	int cantM3 = 0;
	
	for (int x = 0;x < cant;x++) {
		pago = leerPago(x);
		if (pago.getFechaDePago().getAnio() == anio) {
			switch (pago.getIdMembresia())
			{
			case 1:
				cantM++;
				break;
			case 2:
				cantM2++;
				break;
			case 3:
				cantM3++;
				break;
			}
		}
	}

	if (cantM < cantM2 && cantM < cantM3) {
		std::cout << "La membresia menos vendida del anio " << anio << " es la membresia ORO" << std::endl;
	}
	else if (cantM2 < cantM && cantM2 < cantM3) {
		std::cout << "La membresia menos vendida del anio " << anio << " es la membresia PLATA" << std::endl;
	}
	else if (cantM3 < cantM && cantM3 < cantM2) {
		std::cout << "La membresia menos vendida del anio " << anio << " es la membresia BRONCE" << std::endl;
	}
	else {
		std::cout << "No hay membresia menos vendida" << std::endl;
	}
}

void ArchivoPagos::membresiaMenosVendidaMensual()
{
	int anio, mes;
	
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

//CONSULTAS

void ArchivoPagos::consultarPago()
{
	std::string dni;
	std::cout << "Ingrese DNI a consultar: ";
	std::cin.ignore();
	std::getline(std::cin, dni);
	ArchivoSocios arSocio;
	Socio socio = arSocio.leerSocio(arSocio.buscarRegPorDni(dni));
	int cant = getCantidad();
	Pago pago, ultimoPago;
	for (int x = 0;x < cant;x++) {
		pago = leerPago(x);
		if (pago.getNroSocio() == socio.getNroSocio()) ultimoPago = pago;
	}
	std::cout << "El ultimo pago realizado fue el " << ultimoPago.getFechaDePago().toString() << std::endl;
}

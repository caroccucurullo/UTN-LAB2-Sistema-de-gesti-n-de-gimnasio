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
	int ultimoRegistro = getCantidad();
	pago.setId(ultimoRegistro+1);
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
	int opcion1, subopcion1, nroSocio, nRegistro = -1;
	Fecha fecha;
	Pago pago;
	do {
		std::cout << "Modificar Pago con Opciones" << std::endl;
		std::cout << "1) Ingresar modificaciones" << std::endl;
		std::cout << "2) Aplicar modificaciones" << std::endl;
		std::cout << "0) Salir." << std::endl;
		std::cin >> opcion1;
		system("cls");
		switch (opcion1)
		{
			case 1:
			{
				std::cout << "1) Buscar por Nro Socio y Fecha: " << std::endl;
				std::cout << "0) Volver." << std::endl;
				std::cin >> subopcion1;
				system("cls");
				switch(subopcion1){
					case 1:
					{
						std::cout << "Ingresar numero de Socio: ";
						std::cin>>nroSocio;
						std::cout<<"Ingresar fecha de pago: ";
						fecha.Cargar();
						nRegistro = buscarRegPorNroSocioyFecha(nroSocio, fecha);
					}
					break;
				}
				if(nRegistro!=-1){
					pago = leerPago(nRegistro);
					int subopcion2;
					system("cls");
					do {
						system("cls");
						std::cout << "Que desea cambiar?" << std::endl;
						std::cout << "1) Membresia" << std::endl;
						std::cout << "2) Valor" << std::endl;
						std::cout << "3) Fecha" << std::endl;
						std::cout << "0) Volver." << std::endl;
						std::cin >> subopcion2;
						system("cls");
						switch(subopcion2){
							case 1:
							{
								std::string cadena;
								ArchivoMembresia arMem;
								std::cout << "Nombre Membresia: ";
								std::cin.ignore();
								std::getline(std::cin, cadena);

								while (arMem.buscarRegPorNombre(cadena) == -1) {
									std::cout << "Nombre incorrecto. Ingrese nuevamente: ";
									std::getline(std::cin, cadena);
								}
								pago.setIdMembresia(arMem.buscarRegPorNombre(cadena) + 1);
							}
							break;
							case 2:
							{
								float valor;
								std::cout<<"Ingresar Valor nuevo: ";
								std::cin>>valor;
								pago.setValor(valor);
							}
							break;
							case 3:
							{
								std::cout << "Ingrese la nueva fecha: "<<std::endl;
								fecha.Cargar();
								pago.setFechaAsignada(fecha);
							}
							break;
						}
					} while (subopcion2 != 0);
				}
				else{
					std::cout << "No existe el registro." << std::endl;
					system("pause>nul");
				}
			}
			break;
			case 2:
			{
				if (nRegistro != -1) {
					if (modificarPago(pago, nRegistro)) std::cout << "Pago " << pago.getId() << " modificado correctamente." << std::endl;
					else std::cout << "No se pudo modificar pago " << pago.getId() << "." << std::endl;
					system("pause>nul");
				}
			}
			break;
		}
		system("cls");
	} while (opcion1 != 0);
}

int ArchivoPagos::getCantidad()
{
	int cant = 0;
	FILE* p = fopen("pagos.dat", "rb");
	if (p == nullptr) return cant;
	fseek(p, 0, 2);
	cant = ftell(p) / sizeof(Pago);
	fclose(p);
	return cant;
}
//BUSCAR REGISTRO POR NROSOCIO Y FECHA
int ArchivoPagos::buscarRegPorNroSocioyFecha(int nSocio, Fecha& fecha){
	int cantidad = getCantidad();
	Pago pago;
	for(int x=0;x<cantidad;x++){
		pago = leerPago(x);
		if (pago.getFechaDePago().getAnio() == fecha.getAnio() && pago.getFechaDePago().getMes() == fecha.getMes() && pago.getNroSocio() == nSocio) return x;
	}
	return -1;
}

int ArchivoPagos::getCantidadPagoMes(Fecha fechaActual)
{
	int cant = getCantidad();
	Pago pago;
	int contPagoMes = 0;
	for (int x = 0;x < cant;x++) {
		pago = leerPago(x);
		if (pago.getFechaDePago().getMes() == fechaActual.getMes()
			&& pago.getFechaDePago().getAnio() == fechaActual.getAnio()) contPagoMes++;
	}
	return contPagoMes;
}

void ArchivoPagos::pagosDelMes()
{
	Fecha fechaActual;
	int cantPagoMes = getCantidadPagoMes(fechaActual);
	Pago* vPago = new Pago[cantPagoMes];
	if (vPago == nullptr) return;
	Pago pago;
	int cant = getCantidad();
	int contPagoMes = 0;
	for (int x = 0;x < cant;x++) {
		pago = leerPago(x);
		if (pago.getNroSocio() > 0 && pago.getFechaDePago().getMes() == fechaActual.getMes()
			&& pago.getFechaDePago().getAnio() == fechaActual.getAnio()) {
			vPago[contPagoMes] = pago;
			contPagoMes++;
		}
	}
	for (int x = 0;x < cantPagoMes;x++) {
		vPago[x].MostrarPago();
		std::cout << std::endl;
	}
	delete[] vPago;
}

void ArchivoPagos::todosLosPagos()
{
	int cant = getCantidad();
	Pago pago;
	for (int x = 0;x < cant;x++) {
		pago = leerPago(x);
		pago.MostrarPago();
		std::cout << std::endl;
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
	
	std::string cadena;
	ArchivoMembresia arMem;
	std::cout << "Nombre Membresia: ";
	std::cin.ignore();
	std::getline(std::cin, cadena);

	while (arMem.buscarRegPorNombre(cadena) == -1) {
		std::cout << "Nombre incorrecto. Ingrese nuevamente: ";
		std::getline(std::cin, cadena);
	}
	Membresia mem = arMem.leerMembresia(arMem.buscarRegPorNombre(cadena));

	std::cout <<  "Ingrese el anio: " << std::endl;
	std::cin >> anio;
	std::cout <<  "Ingrese el mes: " << std::endl;
	std::cin >> mes;
	
	int cant = getCantidad();
	Pago pago;
	float total = 0;
	
	for (int x = 0;x < cant;x++) {
		pago = leerPago(x);
		if (pago.getIdMembresia() == mem.getId() && pago.getFechaDePago().getAnio() == anio
			&& pago.getFechaDePago().getMes() == mes) {
			total += pago.getValor();
		}
	}

	std::cout << "Recaudacion de la membresia "<<mem.getNombre()<< " del mes " << mes << " del anio " << anio << " es de : " << total << std::endl;
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

	std::cout << "Recaudacion del anio " << anio << " es de: " << total << std::endl;
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

	std::cout << "Recaudacion del mes " << mes << " del anio " << anio << " es de: " << total << std::endl;
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
		std::cout << "La membresia menos vendida del mes " << mes << " del anio " << anio << " es la membresia ORO" << std::endl;
	}
	else if (cantM2 < cantM && cantM2 < cantM3) {
		std::cout << "La membresia menos vendida del mes " << mes << " del anio " << anio << " es la membresia PLATA" << std::endl;
	}
	else if (cantM3 < cantM && cantM3 < cantM2) {
		std::cout << "La membresia menos vendida del mes " << mes << " del anio " << anio << " es la membresia BRONCE" << std::endl;
	}
	else {
		std::cout << "No hay membresia menos vendida" << std::endl;
	}
}


#pragma once
#include "Pago.h"

class ArchivoPagos
{
public:
	bool guardarPago(Pago& pago);
	Pago leerPago(int nRegistro);
	bool leerTodos(Pago* pago, int cantidad);
	bool modificarPago(Pago& pago, int nRegistro);
	int getCantidad();

	//LISTAS
	//listasr los pagos del mes
	
	//CONSULTAS
	//consultar ultimo pago del socio
	
	//INFORMES
	//consultar los pagos de un socio anual
	void recaudacionPorMembresia(int idM, int anio, int mes);
	void recaudacionAnual(int anio);
	void recaudacionMensual(int anio, int mes);
	void membresiaMasVendidaAnual(int anio);
	void membresiaMasVendidaMensual(int anio, int mes);
	void membresiaMenosVendidaAnual(int anio);
	void membresiaMenosVendidaMensual(int anio, int mes);
};
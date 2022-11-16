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
	
	//INFORMES
	void recaudacionPorMembresia(int idM, int anio, int mes);
	void recaudacionAnual(int anio);
	void recaudacionMensual(int anio, int mes);
	void membresiaMasVendidaAnual(int anio);
	void membresiaMasVendidaMensual(int anio, int mes);
	void membresiaMenosVendidaAnual(int anio);
	void membresiaMenosVendidaMensual(int anio, int mes);
};
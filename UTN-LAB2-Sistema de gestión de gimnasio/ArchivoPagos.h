#pragma once
#include "Pago.h"

class ArchivoPagos
{
public:
	//GUARDAR 1 REGISTRO
	bool guardarPago(Pago& pago);
	void guardarPago();//FUNCION A LLAMAR EN EL MENU
	//LEER 1 REGISTRO
	Pago leerPago(int nRegistro);
	//LEER TODO EL REGISTRO
	bool leerTodos(Pago* pago, int cantidad);
	//MODIFICAR TODO 1 REGISTRO
	bool modificarPago(Pago& pago, int nRegistro);
	void modificarPago();//FUNCION A LLAMAR EN EL MENU
	//OBTIENE LA CANTIDAD DE REGISTROS DEL ARCHIVO
	int getCantidad();
	
	int buscarPorNroSocio(int nroSocio);
	
	//INFORMES
	void recaudacionPorMembresia(int idM, int anio, int mes);
	void recaudacionAnual(int anio);
	void recaudacionMensual(int anio, int mes);
	void membresiaMasVendidaAnual(int anio);
	void membresiaMasVendidaMensual(int anio, int mes);
	void membresiaMenosVendidaAnual(int anio);
	void membresiaMenosVendidaMensual(int anio, int mes);
};
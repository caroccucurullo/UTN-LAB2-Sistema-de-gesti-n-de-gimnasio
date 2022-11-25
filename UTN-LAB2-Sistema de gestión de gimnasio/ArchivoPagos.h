#pragma once
#include "Pago.h"
#include "ArchivoSocios.h"


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

	//LISTAS
	void pagosDelMes();
	int getCantidadPagoMes(Fecha fechaActual);
	
	//CONSULTAS
	void consultarPago();
	int buscarPorNroSocio(int nroSocio);
	
	//INFORMES
	void pagosAnualesSocio();
	void recaudacionPorMembresia();
	void recaudacionAnual();
	void recaudacionMensual();
	void membresiaMasVendidaAnual();
	void membresiaMasVendidaMensual();
	void membresiaMenosVendidaAnual();
	void membresiaMenosVendidaMensual();
};
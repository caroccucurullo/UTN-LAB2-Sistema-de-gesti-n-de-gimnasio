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
};
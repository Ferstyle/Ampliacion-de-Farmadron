/******************************************
* NOMBRE: #Fernando#
* PRIMER APELLIDO: #Garcia-Mascaraque#
* SEGUNDO APELLIDO: #Santillana#
* DNI: #50878079#
* EMAIL: #fergms1988@gmail.com#
*******************************************/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Farmadron.h"
#include "Drones.h"
#include "drones.h"
#include "Pacientes.h"


typedef TipoPaciente datoPaciente[20];
typedef TipoAlmacen datoAlmacen[1];
typedef TipoDrones datoDron[15];
typedef TipoPedido datoPedido[100];
typedef TipoFiltro datoFecha[50];


void InGestion(datoPaciente paci, datoAlmacen almac, datoPedido cedu, datoFecha fch, datoDron dron );
void OrdenarFechas(datoPedido cedu, datoFecha fch, int  & totalreg);
void FijarTabla(int orden, datoFecha fch );





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
#include "DatosInternos.h"

typedef TipoAlmacen dataDepot[1];
typedef TipoDrones dataDrones[15];
typedef TipoPaciente dataPaciente[20];
typedef TipoPedido dataPedido [100];

void AltaNewPedido(dataPedido alb, dataDepot depot );
int BuscaReg( int & numregistro, int numalmacen,  dataPedido alb);
int BuscaRef (int & numreferencia, dataPedido alb);
void ListadoPedido(dataPedido alb, dataDepot depot);

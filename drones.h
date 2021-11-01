
/******************************************
* NOMBRE: #Fernando#
* PRIMER APELLIDO: #Garcia-Mascaraque#
* SEGUNDO APELLIDO: #Santillana#
* DNI: 
* EMAIL: #fergms1988@gmail.com#
*******************************************/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Farmadron.h"
#include "Pacientes.h"
#include "DatosInternos.h"

typedef TipoAlmacen datoAlmacen[1];
typedef TipoDrones datoDron[15];

void AltaNewDron(datoDron dron, datoAlmacen depot );
int BuscaReg( int & numregistro, int numalmacen,  datoDron dron);
int BuscaRef (int & numreferencia, datoDron dron);
void ListadoDrones(datoDron dron, datoAlmacen depot);
void BajaDron(datoDron dron, datoAlmacen depot);

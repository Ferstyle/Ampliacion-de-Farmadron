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
#include "drones.h"
#include "DatosInternos.h"

typedef TipoAlmacen datoAlmacen[1];
typedef TipoPaciente datoPaciente[20];

void AltaPaciente(datoPaciente patient , datoAlmacen depot );
int Buscaregistro( int & numregistro, int numalmacen,  datoPaciente patient );
int Buscaref (int & numreferencia, datoPaciente patient);

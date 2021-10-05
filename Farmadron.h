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
#include <math.h>

typedef int TipoDiasConPedidos[31];

/*  Campos y datos del pedido  */

typedef char TipoAlturaAlm[17];
typedef char TipoDescripcionAlm[49];


typedef struct TipoAlmacen {
  int idAlmacen ;
  int altura;
  TipoDescripcionAlm municipio;


};
typedef TipoAlmacen TipoDepot[1];

/*  Campos y datos del pedido  */

typedef char TipoNumSerDron[50];
typedef char TipoAliasDron[50];
typedef int TipoKmIniHDron[49];
typedef int TipoKmHRevDron[49];
typedef int TipoMtrosIniVerDron[49];
typedef int TipoMtrosVRevDron[49];
typedef char TipoCadena[21];

typedef struct TipoDrones {
  int idDron ;
  int InformeMantenimiento;
  TipoCadena cadena;
  TipoAliasDron alias;
  TipoNumSerDron numSerDron;
  int reg_dron;
  int almacen;
  int distancia;
  int angulo;
  int KmH;
  int KmRevH;
  int MetrosV;
  int MetrosRevV;
  int proxRevHor;
  int proxRevV;
  float porcentUtilH;
  float porcentUtilV;


};
typedef TipoDrones TipoDron[15];

/*  Campos y datos del pedido  */

typedef char TipoAliasDron[50];

typedef char TipoNumSerDron[50];

typedef char TipoFarmaco[21];
typedef struct TipoPedido {
  int regPedido;
  int idPedido;
  int idPaciente;
  int idDron ;
  int ruta;
  int dia;
  int mes;
  int anio;
  int almacen;
  TipoNumSerDron numSerDron;
  TipoAliasDron alias;
  TipoFarmaco farmaco;
  int peso;
  float distancia;
  int altura;
  int units;
  int ctdPedidos;
  int numDet;
  int idAlmacen;

};
typedef TipoPedido TipoCedula[100];

/* Campos y datos del paciente */

typedef char TipoCadena[21];

typedef struct TipoPaciente {
  int idclave ;
  TipoCadena cadena;
  int angulo ;
  int distancia;
  int almacen;
  int reg_paciente;
  int altura;
  int ruta;
};
typedef TipoPaciente TipoTarjetas[20];

/*   Array de Fechas    */

typedef struct TipoFechas {
  int dia;
  int mes;
  int anio;
};
typedef TipoFechas TipoRegistroFecha[30];


/*  Array de Filtro con fechas   */

typedef struct TipoFiltro {
  int dia;
  int mes;
  int anio;
  int registro;
  int pedido;
  int paciente;
  int almacen ;
  int dron;
  int peso ;
  int angulo ;
  int distancia ;
  int altura;
  int KmH;
  int KmRevH;
  int MetrosV;
  int MetrosRevV;
  int proxRevHor;
  int proxRevV;
  float porcentUtilH;
  float porcentUtilV;
  char alias;
  char idDron;
};
typedef TipoFiltro TipoFiltradoFecha[50];

/* Array General tipo registro */

typedef struct TipoGestion {

  TipoTarjetas datoPaciente;
  TipoCedula datoPedido;
  TipoRegistroFecha filtraFecha;
  TipoFiltradoFecha comunicaFecha;
  TipoDepot datoAlmacen;
  TipoDron datoDron;

  /*  Funciones del programa  */

  int MenuPrincipal();
  int BuscarPedido( int  & numReg );
  int NumPedido( int  & numberPedido );
  void NuevoPedido();
  void ListadoPedidos();
  void AsignarDron();
  void FechasEnvio(int contEnvios);
  int FechaAcertada(int & newDia, int newMes, int newAnio);
  void DtlFarmaco(int numberEnv, int pacReg, int numberPedido);
  void OrdenarFechas();
  void FijarTabla(int orden );
  void InformeMantenimiento();
  void BorrarDatos();

};


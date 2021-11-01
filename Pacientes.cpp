/******************************************
* NOMBRE: #Fernando#
* PRIMER APELLIDO: #Garcia-Mascaraque#
* SEGUNDO APELLIDO: #Santillana#
* DNI: 
* EMAIL: #fergms1988@gmail.com#
*******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "DatosInternos.h"
#include "Pacientes.h"


typedef TipoPaciente dataPaciente[20];
dataPaciente patient ;
typedef TipoAlmacen dataDepot[1];


/*  Procedimiento pantalla de teclear los nuevos pacientes  */

void AltaPaciente(dataPaciente patient, dataDepot depot ) {
  int numregistro = 1 ;
  char pacienteopc = 'X';
  char datosOK = 'X';
  int maxlongitud = 20 ;
  int maxdistancia = 0 ;
  int maxangulo = 0 ;
  int maxaltura = 0;
  int auxalmacen = 0 ;
  int numreferencia = 0 ;

  system("cls");

  if ( numregistro > 20) {
    printf(" Supera el limite maximo de registros");
    datosOK = 'S';
  };

  printf("\n");

  printf("Alta nuevo paciente: \n" );

  printf("Codigo Almacen? (1) ");
  scanf("%d", &auxalmacen);
  if (depot[auxalmacen-1].idAlmacen != auxalmacen )  {
    printf( "\n Este Almacen no existe.. \n");
    system("pause");
    return;
  } else {

    printf( " ===>  Almacen.: %s \n" , depot[auxalmacen-1].municipio );
  };
  printf("\n Datos Paciente:\n");

  while (toupper(pacienteopc) != 'N') {
    pacienteopc = 'X';
    datosOK = 'X';

    Buscaregistro(numregistro, auxalmacen,  patient );
    Buscaref( numreferencia, patient);

    while ( toupper(datosOK) != 'S') {
      maxlongitud = 20 ;
      maxdistancia = 0 ;

      while (maxlongitud > 19) {
        fflush(stdin);
        patient[numreferencia].idclave = numregistro ;
        patient[numreferencia].reg_paciente = numreferencia ;
        patient[numreferencia].almacen = auxalmacen ;


        printf("Identificador (entre 1 y 20 caracteres) ? ");
        scanf( " %[^\n]s" , &patient[numreferencia].cadena ) ;
        maxlongitud = strlen(patient[numreferencia].cadena);
        if (maxlongitud > 19) {
          printf( "\n Excede el maximo de caracteres permitido\n");
        }
      }
      do {
        fflush(stdin);

        printf( "Distancia (hasta 10000 metros a plena carga) ? ");
        scanf( " %d", &patient[numreferencia].distancia ) ;
        maxdistancia=patient[numreferencia].distancia;
        if (maxdistancia < 1 || maxdistancia > 10000 ) {
          printf( "\n Excede el maximo de distancia permitida\n");
        };
      } while (  maxdistancia < 1 || maxdistancia > 10000 ) ;

      do {
        fflush(stdin);

        printf("\xb5ngulo (entre 0 y 2000 pi /1000 radianes) ? ");
        scanf( " %d" , &patient[numreferencia].angulo ) ;
        maxangulo=patient[numreferencia].angulo;
        if (maxangulo < 1 || maxangulo > 2000 ) {
          printf( "\n Excede el maximo de angulo permitido\n");
        };

      } while (  maxangulo < 1 || maxangulo > 2000 ) ;


      do {
        fflush(stdin);

        printf("Altura sobre el nivel del mar (metros)? ");
        scanf( " %d" , &patient[numreferencia].altura ) ;
        maxangulo=patient[numreferencia].altura;
        if (maxaltura < 0 || maxaltura > 5000 ) {
          printf( "\n Excede el maximo de altura permitido\n");
        };

      } while (  maxaltura < 0 || maxaltura > 5000 ) ;
      printf("\n Datos correctos S/N? ");
      scanf( " %c" , &datosOK );

    }
    printf("\n Otro Paciente S/N? ");
    scanf( " %c" , &pacienteopc );
  }

}


/* ********************************************************************************/
/*  Busca el ultimo registro paciente dentro de cada almacen para la numneracion  */
/* ********************************************************************************/

int Buscaregistro( int & numregistro, int numalmacen, dataPaciente patient) {
  int ind0 = 0 ;


  while ( ind0 <= patient[ind0].reg_paciente) {      // recorremos toda el array hasta encontrar el ultimo numero de paciente asigando

    if ( patient[ind0].almacen == numalmacen ) {
      do {
        if ( patient[ind0].idclave > 0) {
          numregistro = patient[ind0].idclave + 1;
        };
        ind0++;
      } while (patient[ind0].almacen == numalmacen);
    } else {
      ;
      ind0++;
    };
  }
  return numregistro ;
}

int Buscaref (int & numreferencia, dataPaciente patient) {
  int ind0 = 0;
  while (ind0 < 101) {

    if ( patient[ind0].reg_paciente == ind0 ) {
      ind0++;
    } else {
      numreferencia = ind0 ;
      ind0 = 200 ;
    };
  }

  return numreferencia;
}

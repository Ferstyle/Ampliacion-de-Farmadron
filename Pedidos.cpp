/******************************************
* NOMBRE: #Fernando#
* PRIMER APELLIDO: #Garcia-Mascaraque#
* SEGUNDO APELLIDO: #Santillana#
* DNI: #50878079#
* EMAIL: #fergms1988@gmail.com#
*******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "DatosInternos.h"


typedef TipoPedido dataPedido[100];
dataPedido alb;
typedef TipoAlmacen dataDepot[1];
int opcion;

/*  Procedimiento pantalla de teclear los nuevos drones  */

void AltaNewPedido(dataPedido alb, dataDepot depot ) {
  int numregi = 1 ;
  int maxlongitud = 7 ;
  char dronOpc = 'X';
  char datosOK = 'X';
  char alias = ' ';
  char numSerDron = ' ';
  int maxKmH = 0 ;
  int maxKmRevH = 0 ;
  int maxMetrosV = 0 ;
  int maxMetrosRevV = 0 ;
  int auxalmacen = 0 ;
  int numRefe = 0 ;


  system("cls");


  if ( numregi > 15) {
    printf(" Supera el limite maximo de registros");
    datosOK = 'S';
  };

  printf("\n");

  printf("Alta nuevo dron: \n" );

  printf("Codigo Almacen? (1) ");
  scanf("%d", &auxalmacen);
  if (depot[auxalmacen-1].idAlmacen != auxalmacen )  {
    printf( "\n Este Almacen no existe.. \n");
    system("pause");
    return;
  } else {

    printf( " ===>  Almacen.: %s \n" , depot[auxalmacen-1].municipio );
  };


  while (toupper(dronOpc) != 'N') {
    dronOpc = 'X';
    datosOK = 'X';

    BuscaReg(numregi, auxalmacen,  alb );
    BuscaRef( numRefe, alb);

    while ( toupper(datosOK) != 'S') {
      maxlongitud = 11 ;
      maxKmH = 0 ;
      maxKmRevH = 0 ;
      maxMetrosV = 0 ;
      maxMetrosRevV = 0 ;

      while (maxlongitud > 7) {
        fflush(stdin);
        dron[numRef].idDron = numregistro ;
        dron[numRef].reg_dron = numRef ;
        dron[numRef].almacen = auxalmacen ;


        printf("Numero de serie del dron (tres letras + cuatro numeros) ? ");
        scanf( " %s" , &dron[numRef].numSerDron ) ;
        maxlongitud = strlen(dron[numRef].numSerDron);
        if (maxlongitud > 7) {
          printf( "\n Excede el maximo de caracteres permitido\n");
        }
      }
      do {
        fflush(stdin);

        printf( "Alias? (entre 1 y 10 caracteres)? ");
        scanf( " %s", &dron[numRef].alias ) ;
        maxlongitud= strlen (dron[numRef].alias);
        if (maxlongitud > 10) {
          printf( "\n Excede el maximo de caracteres permitido\n");
        };
      } while (  maxlongitud < 1 || maxlongitud > 10 ) ;

      do {
        fflush(stdin);

        printf("KM iniciales horizontal? (=0 si es nuevo)  ? ");
        scanf( " %d" , &dron[numRef].KmH ) ;
        maxKmH=dron[numRef].KmH;
        if (maxKmH < 0 || maxKmH > 100000 ) {
          printf( "\n Excede el máximo de Km horizontales permitido\n");
        };

      } while (  maxKmH < 0 || maxKmH > 100000 ) ;

      /**********************************************************/
      do {
        fflush(stdin);
        printf("KM horizontales entre revisiones? ");
        scanf( " %d" , &dron[numRef].KmRevH ) ;
        maxKmRevH=dron[numRef].KmRevH;
        if (maxKmRevH < 1 || maxKmRevH > 600 ) {
          printf( "\n Excede el maximo de Km horizontales entre revisiones permitido permitido\n");
        };

      } while (  maxKmRevH < 1 || maxKmRevH > 600 ) ;

      /***********************************************************/
      do {
        fflush(stdin);
        printf("Metros iniciales vertical? (=0 si es nuevo)? ");
        scanf( " %d" , &dron[numRef].MetrosV ) ;
        maxMetrosV=dron[numRef].MetrosV;
        if (maxMetrosV < 0 || maxMetrosV > 100000 ) {
          printf( "\n Excede el maximo de Metros iniciales ne vertical permitido\n");
        };

      } while (  maxMetrosV < 0 || maxMetrosV > 100000 ) ;


      /***********************************************************/
      do {
        fflush(stdin);
        printf("Metros verticales entre revisiones?  ");
        scanf( " %d" , &dron[numRef].MetrosRevV ) ;
        maxMetrosRevV=dron[numRef].MetrosRevV;
        if (maxMetrosRevV < 1 || maxMetrosRevV > 5000) {
          printf( "\n Excede el maximo de Metros iniciales ne vertical entre revisiones permitido\n");
        };

      } while (  maxMetrosRevV < 1 || maxMetrosRevV > 5000 ) ;
      printf("\n Datos correctos S/N? ");
      scanf( " %c" , &datosOK );

      /******************************************************************/
    }
    printf("\n Otro Dron S/N? ");
    scanf( " %c" , &dronOpc );
  }
}

/*  Busca el último registro dron en el almacen para la numeración   */

int BuscaReg( int & numregistro, int numalmacen, dataPedido pedido) {
  int indice = 0 ;


  while ( indice <= dron[indice].reg_dron) {      // recorremos toda el array hasta encontrar el ultimo numero de dron asignado

    if ( dron[indice].almacen == numalmacen ) {
      do {
        if ( dron[indice].idDron > 0) {
          numregistro = dron[indice].idDron + 1;
        };
        indice++;
      } while (dron[indice].almacen == numalmacen);
    } else {
      ;
      indice++;
    };
  }
  return numregistro ;
}

int BuscaRef (int & numRef, dataPedido p) {
  int indice = 0;
  while (indice < 101) {

    if ( dron[indice].reg_dron == indice ) {
      indice++;
    } else {
      numRef = indice ;
      indice = 200 ;
    };
  }

  return numRef;
}

/*  Procedimiento listado por pantalla de drones y borrado   */

void BajaPedido(dataPedido p, dataDepot depot) {

  int indice = 0 ;
  int indDron = 0;
  int idDron=0;
  int indAlmacen = 0;
  int auxalmacen = 0 ;
  int auxdron = 0;
  bool existe = false ;
  int numregistro = 1 ;
  int maxlongitud = 7 ;
  char dronOpc = 'X';
  char datosOK = 'X';
  char alias = ' ';
  char numSerDron = ' ';
  int maxKmH = 0 ;
  int maxKmRevH = 0 ;
  int maxMetrosV = 0 ;
  int maxMetrosRevV = 0 ;
  int numRef = 0 ;
  int opcion;

  system("cls");

  printf( " Menu Borrar Drones \n");


  do {

    printf("Codigo Almacen? (1)\n ");
    scanf("%d", &auxalmacen);
    if (auxalmacen != 1 ) {
      printf("\n\nNumero incorrecto - fuera de rango, debe ser 1\n");
    };
  } while (auxalmacen !=1);

  for (int i=0; i <=1 ; i++) {

    if (depot[i].idAlmacen == auxalmacen )  {

      existe = true;
    };
  };

  if ( existe == false ) {

    printf( "Este Almacen no existe.. \n");
    system("pause");
    return;
  };


  do {
    if ( dron[indDron].idDron==(indDron +1)) {
      if (dron[indDron].idDron == 1) {

        printf( "\nRef  Numero Serie      Alias      KmH      KmRevH      MetrosV     MetrosRevV\n\n");

      };
      printf(" %d\t", dron[indDron].idDron);
      printf("%7s", dron[indDron].numSerDron);
      printf("%18s", dron[indDron].alias);
      printf("%8d", dron[indDron].KmH);
      printf("%10d", dron[indDron].KmRevH);
      printf("%12d", dron[indDron].MetrosV);
      printf("%12d\n", dron[indDron].MetrosRevV);

    };
    indDron++;


  } while ( dron[indDron].idDron<=(indDron +1) );

//SI, JODER!!

  printf("\nDron a borrar(posicion)?");

  scanf( "%d", &indDron) ;
  if (indDron==0||indDron>15) {
    printf ("Fuera de rango, introducir una posicion valida.\n");
    system("pause");
    return;
  }

  if ( indDron < indDron+1 ) {

    dron[indDron-1].idDron= 0;
    strcpy (dron[indDron-1].numSerDron, " ");
    strcpy (dron[indDron-1].alias, " ");
    dron[indDron-1].KmH=0;
    dron[indDron-1].KmRevH=0;
    dron[indDron-1].MetrosV=0;
    dron[indDron-1].MetrosRevV=0;
    dron[indDron-1].proxRevHor=0;
    dron[indDron-1].proxRevV=0;
    dron[indDron-1].porcentUtilH=0;
    dron[indDron-1].porcentUtilV=0;

    printf("Dron borrado. \n");
    system("pause");


  } else {
    printf("Ese dron no existe, intentelo de nuevo.");
    system("pause");

  }
}







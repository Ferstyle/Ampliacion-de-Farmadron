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
#include <math.h>
#include "Farmadron.h"
#include "drones.h"
#include "Pacientes.h"
#include "Calendario.h"
#include <Windows.h>


void obtenerFechaHoraActual(int &year, int &month, int &day,  int &hour, int &min, int &sec) {
  SYSTEMTIME str_t;
  GetSystemTime(&str_t);
  year=str_t.wYear;
  month=str_t.wMonth;
  day=str_t.wDay;
  hour=str_t.wHour +1;
  min=str_t.wMinute;
  sec=str_t.wSecond;
}


typedef int TipoDiasConPedidos[31];

TipoDiasConPedidos DiasConPedidos;


/* -- Busca el último registro de pedido del vector para la numeración  --  */

int TipoGestion::BuscarPedido( int & buscareg) {
  int ind0 = 0 ;

  while ( ind0 <= 100) {   /* Recorro toda el vector hasta encontrar el último pedido */


    if (datoPedido[ind0].regPedido == (ind0 + 1)) {
      ind0++;

      buscareg = ind0 ;
    } else {
      buscareg = buscareg +1;
      ind0 = 200;
    };
  };

  return( buscareg ) ;

}


/*  Busca el último número de pedido del vector para la numeración   */

int TipoGestion::NumPedido( int & numberPedido) {
  int ind0 = 0 ;

  while ( ind0 <= 200) {  /* Recorro todo el vector hasta encontrar el ultimo numero de pedido asignado */

    if (datoPedido[ind0].regPedido == (ind0 + 1 )) {
      numberPedido = datoPedido[ind0].idPedido ;
      ind0++;
    } else {
      numberPedido = datoPedido[ind0-1].idPedido + 1;
      ind0 = 250;
    };
  };
  return( numberPedido ) ;
}

/*  Funcion para detectar si la fecha es correcta de acuerdo con los formatos y día/mes/año     */

int TipoGestion::FechaAcertada(int & newDia, int newMes, int newAnio) {

  // Función para calcular el número de días de cada mes y  en función del año bisiesto

  switch (newMes) {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    newDia = 31;
    break;
  case 4:
  case 6:
  case 9:
  case 11:
    newDia = 30;
    break;
  case 2:
    if (newAnio%4 == 0  && newAnio%100 != 0 || newAnio%400 == 0) {
      newDia = 29 ;
    } else {
      newDia = 28 ;
    };
    break;
  default:
    newDia = 30 ;
  };
  return newDia;

}

/*  Procedimiento para detectar teclear los campos de la fecha y cargar los vectores de fechas     */

void TipoGestion::FechasEnvio( int contEnvios ) {

  /* Función para introducir y controlar los errores de tecla del usuario y que las fechas tengan los formatos correctos */

  int dia2, mes2, anio2, newDia, newMes, newAnio, frecuencia, ind0, ind1, ind2, auxdron;
  bool pruebaFecha = true;
  dia2 = 1 ;
  while (pruebaFecha) {

    if (contEnvios > 1 ) {

      do {

        printf("Numero de dias entre cada env\xa1o? (entre 1 y 15 dias)? ");
        scanf( " %d" , &frecuencia ) ;
        if (frecuencia < 0 || frecuencia > 15) {
          printf( "\n Valor no permitido debe ser entre 1 y 15 \n" );
        }
      } while (frecuencia < 0 || frecuencia > 15);
      fflush(stdin);
      printf("Dia del primer env\xa1o? ");
      scanf( " %d" , &dia2 ) ;
      printf("Mes del primer env\xa1o? ");
      scanf( " %d" , &newMes ) ;
      printf("A\xa4o del primer env\xa1o? ");
      scanf( " %d" , &newAnio ) ;
    } else if (contEnvios == 0) {
      system("cls");
      fflush(stdin);
      printf( " %s", "Lista mensual de pedidos por dron:" );
      printf( "Dron a mostrar? " );
      scanf( "%2d", &auxdron);
      printf( "Selecci\xa2n Mes ? " );
      scanf( "%2d", &newMes);
      printf( "Selecci\xa2n Ano ? " ) ;
      scanf( "%4d", &newAnio);
    } else {
      fflush(stdin);
      printf("Dia del env\xa1o? ");
      scanf( " %d" , &dia2 ) ;
      printf("Mes del env\xa1o? ");
      scanf( " %d" , &newMes ) ;
      printf("A\xa4o del env\xa1o? ");
      scanf( " %d" , &newAnio ) ;
    };

    FechaAcertada(newDia, newMes, newAnio);

    if (dia2 <= 0 || dia2 > newDia || newMes <= 0 || newMes > 12 || newAnio < 2020) {
      printf("\n La fecha es incorrecta\n");
      system("pause");
    } else {
      pruebaFecha = false;

      filtraFecha[0].dia = dia2;
      filtraFecha[0].mes = newMes;
      filtraFecha[0].anio = newAnio;
    };
  };
  if (contEnvios > 1) {
    for (int j = 0 ; j <= contEnvios-2 ; j++) {
      mes2 = newMes ;
      anio2 = newAnio ;
      dia2 = dia2 + frecuencia;
      if (dia2 > FechaAcertada(newDia, newMes, newAnio)) {
        if (newMes == 12) {
          newMes = 1 ;
          newAnio++ ;
        } else {
          newMes++;
        };
        newDia = dia2- newDia;
      } else {
        newDia =  dia2;
      };

      filtraFecha[j+1].dia = newDia;
      filtraFecha[j+1].mes = newMes;
      filtraFecha[j+1].anio = newAnio;

      dia2 = newDia ;
      mes2 = newMes ;
      anio2 = newAnio ;

    };
  };
  ind0 = 0 ;
  ind1 = 0 ;
  ind2 = 0 ;

  while (ind0 < 100 ) {

    if ( datoPedido[ind0].mes == filtraFecha[0].mes &&
         datoPedido[ind0].anio == filtraFecha[0].anio ) {

      DiasConPedidos[ind2] = datoPedido[ind0].dia ;
    } else {
      DiasConPedidos[ind2] = 0;
    };
    ind2++;

    if ( datoPedido[ind0].dia == filtraFecha[0].dia &&
         datoPedido[ind0].mes == filtraFecha[0].mes &&
         datoPedido[ind0].anio == filtraFecha[0].anio ) {

      comunicaFecha[ind1].dia = filtraFecha[0].dia ;
      comunicaFecha[ind1].mes = filtraFecha[0].mes;
      comunicaFecha[ind1].anio = filtraFecha[0].anio;
      comunicaFecha[ind1].registro = datoPedido[ind0].regPedido;
      comunicaFecha[ind1].pedido = datoPedido[ind0].idPedido;
      comunicaFecha[ind1].paciente = datoPedido[ind0].idPaciente;
      comunicaFecha[ind1].dron = datoPedido[ind0].idDron;
      comunicaFecha[ind1].almacen = datoPedido[ind0].idAlmacen;
      comunicaFecha[ind1].peso = datoPedido[ind0].peso;
      ind1++;
    } else {

      comunicaFecha[ind1].dia = 0 ;
      comunicaFecha[ind1].mes = 0;
      comunicaFecha[ind1].anio = 0;
      comunicaFecha[ind1].registro = 0;
      comunicaFecha[ind1].pedido = 0;
      comunicaFecha[ind1].paciente = 0 ;
      comunicaFecha[ind1].dron = 0 ;
      comunicaFecha[ind1].almacen = 0;
      comunicaFecha[ind1].peso = 0;
    };
    ind0++;
  }

}

/*  Procedimiento pantalla de teclear e introducir los campos de un pedido  */

void TipoGestion::NuevoPedido() {
  int numberPedido = 0 ;
  int buscareg = 0;
  int auxalmacen = 0;
  int auxPaciente = 0 ;
  int ind0 = 0 ;
  char otroPedido = 'X';

  system("cls");

  while (toupper(otroPedido) != 'N') {

    BuscarPedido(buscareg);
    NumPedido(numberPedido);

    if ( numberPedido > 100) {
      printf("\n Supera el limite m\xa0ximo de pedidos..\n");
      system("pause");
      return;
    } else {
    } ;

    printf("\n");
    printf("Nuevo Pedido: \n" );
    printf("Codigo Almacen? (1) ");
    scanf("%d", &auxalmacen);
    if (auxalmacen < 1 || auxalmacen > 1) {
      printf( "\n Numero incorrecto - fuera de rango debe ser  1\n");
      system("pause");
      return;
    };
    if (datoAlmacen[auxalmacen-1].idAlmacen != auxalmacen )  {
      printf( "Este Almacen no existe.. \n\n");
      system("pause");
      return;
    } else {
      printf( "> Almacen.: %s \n" ,datoAlmacen[auxalmacen-1].municipio );
    };

    printf("Ref Paciente (entre 1 y 20) ? ");
    scanf( " %d" , &auxPaciente ) ;


    do {
      if (auxPaciente == datoPaciente[ind0].idclave  && datoPaciente[ind0].almacen == auxalmacen) {
        printf( "> Paciente.: %s \n" , datoPaciente[ind0].cadena );
        ind0 = 125;
      };

      if ( ind0 == 100) {
        printf( "\n Esta referencia no existe. \n");
        system("pause");
        return;
      };
      ind0 ++;
    } while ( ind0 <= 100 );

    datoPedido[buscareg-1].idAlmacen = auxalmacen;
    datoPedido[buscareg-1].idPaciente = auxPaciente;

    printf("Numero de env\xa1os? ");
    scanf( " %d" , &datoPedido[buscareg-1].ctdPedidos ) ;

    FechasEnvio(datoPedido[buscareg-1].ctdPedidos);

    DtlFarmaco(datoPedido[buscareg-1].ctdPedidos, buscareg, numberPedido );

    printf("\n Otro Pedido (S/N)? ");
    scanf( " %c" , &otroPedido );
    system("cls");

  }

}

/*  Procedimiento teclear los detalles de los farmacos  */

void TipoGestion::DtlFarmaco(int numberEnv, int pacReg, int numberPedido) {
  char otroFarmaco = 'X';
  int ind1 = 0;
  int auxPedido = 0;
  int auxTotal = 0;
  int auxFecha = 0;
  int auxPaciente = datoPedido[pacReg-1].idPaciente ;
  int pesoTotal = 0;
  int pesoEnvio = 0;
  int maxFarmaco = 1;

  while (toupper(otroFarmaco) != 'N' ) {

    while (toupper(otroFarmaco) != 'N' && pesoEnvio < 3000  && pesoTotal < 3000 && maxFarmaco < 6) {
      printf(" (N: %d) Nombre f\xa0rmaco (entre 1 y 20 caracteres) ? ", maxFarmaco );
      scanf( " %[^\n]s" , &datoPedido[pacReg-1].farmaco ) ;

      do {
        pesoTotal = 0;
        do {
          fflush(stdin);
          printf("Peso f\xa0rmaco (menos de 3000 gramos ) ? ");
          scanf( " %d" , &datoPedido[pacReg-1].peso ) ;
          if (datoPedido[pacReg-1].peso < 1 || datoPedido[pacReg-1].peso > 3000 ) {
            printf( "\n Excede el peso permitido o datos incorrectos \n");
          };
        } while ( datoPedido[pacReg-1].peso < 1 || datoPedido[pacReg-1].peso > 3000 ) ;


        fflush(stdin);
        printf("Unidades de f\xa0rmaco ? ");
        scanf( " %d" , &datoPedido[pacReg-1].units ) ;
        pesoTotal =  datoPedido[pacReg-1].peso*datoPedido[pacReg-1].units ;
        if (datoPedido[pacReg-1].units < 1 || datoPedido[pacReg-1].units > 100 ) {
          printf( "\n Excede de la cantidad permitida o datos incorrectos \n");
        };
        if (pesoTotal > 3000) {
          printf( "\n Excede del peso permitido de env\xa1o \n");
        };
      } while ( datoPedido[pacReg-1].units < 1 || datoPedido[pacReg-1].units > 100 || pesoTotal > 3000) ;

      pesoEnvio = pesoEnvio + pesoTotal;

      if (pesoEnvio > 3000 || pesoTotal > 3000) {

        printf( "\n El pedido excede del peso permitido de env\xa1o de 3000 gramos \n");
        printf( "\n Este ultimo f\xa0rmaco se borrara del pedido !!!! \n");

        datoPedido[pacReg-1].regPedido = 0 ;
        datoPedido[pacReg-1].idPedido = 0 ;
        datoPedido[pacReg-1].idPaciente = 0;
        datoPedido[pacReg-1].dia = 0 ;
        datoPedido[pacReg-1].mes = 0 ;
        datoPedido[pacReg-1].anio = 0 ;
        strcpy(datoPedido[pacReg-1].farmaco, " ");
        datoPedido[pacReg-1].peso = 0 ;
        datoPedido[pacReg-1].units = 0 ;
        datoPedido[pacReg-1].idAlmacen = 0;
        return ;
      };

      ind1 = pacReg;
      auxPedido = numberPedido;
      auxTotal = ( pacReg-1) + numberEnv ;
      auxFecha = 0 ;
      for (int j = pacReg-1 ; j < auxTotal  ; j++) {

        datoPedido[j].regPedido = pacReg ;
        datoPedido[j].idPedido = auxPedido ;
        datoPedido[j].idPaciente = auxPaciente;
        datoPedido[j].dia = filtraFecha[auxFecha].dia ;
        datoPedido[j].mes = filtraFecha[auxFecha].mes ;
        datoPedido[j].anio = filtraFecha[auxFecha].anio ;
        strcpy(datoPedido[j].farmaco, datoPedido[ind1-1].farmaco);
        datoPedido[j].peso = datoPedido[ind1-1].peso ;
        datoPedido[j].units = datoPedido[ind1-1].units ;
        datoPedido[j].idAlmacen = datoPedido[ind1-1].idAlmacen;

        pacReg++;
        auxPedido++;
        auxFecha++;
      }
      fflush(stdin);
      printf("\n Otro f\xa0rmaco (S/N)? ");
      scanf( " %c" , &otroFarmaco );
      maxFarmaco = maxFarmaco + 1 ;


    };
    if (maxFarmaco > 5) {
      printf( "\n No permitido mayor de 5 f\xa0rmacos por pedido \n");
      otroFarmaco = 'N';
      system("pause");
    };
  }
}



/*  Asignacion de drones a los pedidos  */

void TipoGestion::AsignarDron() {

  int fchindice = 0 ;
  int newDia, newMes, newAnio ;
  int pesoTotal = 0;
  float totaldistancia=0;
  int totalaltura=0;
  int auxPedido;
  int auxalmacen = 0 ;
  int auxdron = 0;
  int auxruta=0;
  int ruta;
  int distanciaruta=0;
  int totnumrutas=0;
  int indpaciente = 0 ;
  int indAlmacen= 0;
  int indDron = 0;


  system("cls");

  printf( "  Asignar drones a pedidos de un dia :");

  do {

    printf("Codigo Almacen? (1) ");
    scanf("%d", &auxalmacen);
    if (auxalmacen < 1 || auxalmacen > 1) {
      printf( "\n Numero incorrecto - fuera de rango debe ser 1\n");
      system("pause");
      return;
    };


    if (datoAlmacen[auxalmacen-1].idAlmacen != auxalmacen )  {

      printf( "Este Almacen no existe.. \n\n");
      system("pause");
      return;
    } else {

      printf( "> Almacen.: %s \n" ,datoAlmacen[auxalmacen-1].municipio );
    };


  } while (auxalmacen < 1 || auxalmacen > 1);

  FechasEnvio(1);

  newDia = comunicaFecha[0].dia ;
  newMes = comunicaFecha[0].mes ;
  newAnio = comunicaFecha[0].anio ;

  if (newDia > 31 || newMes > 12 ||comunicaFecha[fchindice].registro == 0 ) {


    printf("\n No hay Pedidos para listar \n");
    system("pause");
    return;

  };

  if ( auxalmacen == comunicaFecha[fchindice].almacen) {


    printf("ALMACEN - %s\t", datoAlmacen[comunicaFecha[fchindice].almacen-1].municipio);
    printf("Dia:%d/%d/%d\n", comunicaFecha[fchindice].dia,comunicaFecha[fchindice].mes,comunicaFecha[fchindice].anio);


  };

  while (comunicaFecha[fchindice].registro > 0
         && newDia == comunicaFecha[fchindice].dia
         && newMes == comunicaFecha[fchindice].mes
         && newAnio == comunicaFecha[fchindice].anio
         && auxalmacen == comunicaFecha[fchindice].almacen ) {


    for (int i = 0 ; i <= datoPaciente[i].reg_paciente ; i++) {

      if (datoPaciente[i].idclave == comunicaFecha[fchindice].paciente && datoPaciente[i].almacen == auxalmacen) {
        indpaciente = i ;
      };

    };

    for (int i = 0 ; i <= datoDron[i].reg_dron ; i++) {

      if (datoDron[i].idDron == comunicaFecha[fchindice].dron && datoDron[i].almacen == auxalmacen) {
        indDron = i ;
      };

    };

    distanciaruta = 0 ;
    for (int i = 0 ; i < totnumrutas ; i++) {
      auxruta = comunicaFecha[i].registro ;
      if (comunicaFecha[i].registro == 0) {
        ruta = ruta +1;
      }
    }

    printf("\nPedido %d - Ruta %d - Cliente %d \n ",

           datoPedido[comunicaFecha[fchindice].registro-1].idPedido,
           datoPedido[comunicaFecha[fchindice].registro-1].ruta,
           datoPaciente[indpaciente].idclave);

    printf( "Ubicaci\xa2n destino: Distancia: %5d, Angulo: %4d y Altura: %d \n",

            datoPaciente[indpaciente].distancia,
            datoPaciente[indpaciente].angulo,
            datoPaciente[indpaciente].altura );
    auxPedido = comunicaFecha[fchindice].pedido;
    pesoTotal = 0 ;
    totaldistancia = 0 ;
    totalaltura = 0;
    ruta=0;

    while ( auxPedido == comunicaFecha[fchindice].pedido) {

      printf("%2d  Unidades ",  datoPedido[comunicaFecha[fchindice].registro-1].units);
      printf("%-20s",  datoPedido[comunicaFecha[fchindice].registro-1].farmaco);
      printf("Peso: %4d gramos\n",  datoPedido[comunicaFecha[fchindice].registro-1].units * datoPedido[comunicaFecha[fchindice].registro-1].peso);

      pesoTotal =  pesoTotal + (datoPedido[comunicaFecha[fchindice].registro-1].peso * datoPedido[comunicaFecha[fchindice].registro-1].units) ;

      totaldistancia =  totaldistancia + (datoPaciente[indpaciente].distancia/1000.0*2.0 ) ;

      totalaltura= totalaltura + ((datoPaciente[indpaciente].altura-datoAlmacen[indAlmacen].altura)*2) ;

      ruta= ruta + datoPedido[comunicaFecha[fchindice].registro-1].ruta;

      fchindice++;
    }


    printf("Peso Total del Envio ..:     %4d gramos \n" , pesoTotal );
    printf("\nASIGNADO DRON: %s - TOTAL RUTA %d HORIZONTAL= %f  Km\n",datoPedido[comunicaFecha[fchindice-1].registro-1].numSerDron,ruta,totaldistancia);
    printf("                         TOTAL RUTA %d VERTICAL  = %d  mt\n",datoPedido[comunicaFecha[fchindice-1].registro-1].ruta,totalaltura);

    ;
  }

  printf("\n");
  system("pause");

}

/*  Procedimiento informe de Mantenimiento  */

void TipoGestion::InformeMantenimiento() {
  int totnumrutas = 0;
  int ind1 = 0 ;
  int pesoTotal = 0 ;
  int fchindice = 0 ;
  int pesoruta = 0 ;
  int auxruta = 0 ;
  int distanciaruta = 0;
  int ruta = 0 ;
  int newMes, newAnio ;
  int auxPedido = 0 ;
  int auxalmacen = 0 ;
  float distaAB = 0 ;
  float anguloAB = 0 ;
  int i = 0;
  int ind0 = 0 ;
  int indDron = 0;
  int idDron=0;
  int indAlmacen = 0;

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


  int year, month, day,  hour,  min,   sec;
  obtenerFechaHoraActual(year, month, day, hour, min, sec);

  system("cls");

  printf( "  Informe de Mantenimiento:");


  do {

    printf("\nCodigo Almacen? (1) ");
    scanf("%d", &auxalmacen);
    if (auxalmacen < 1 || auxalmacen > 1) {
      printf( "\n Numero incorrecto - fuera de rango debe ser 1\n");
      system("pause");
      return;
    };


    if (datoAlmacen[auxalmacen-1].idAlmacen != auxalmacen )  {

      printf( "Este Almacen no existe.. \n\n");
      system("pause");
      return;
    } else {

      printf( "====> Almacen.: %s - HOY: %d/%d/%d \n" ,datoAlmacen[auxalmacen-1].municipio,day,month,year);
    };


  } while (auxalmacen < 1 || auxalmacen > 1);


  do {
    if ( datoDron[indDron].idDron==(indDron +1)) {
      if (datoDron[indDron].idDron == 1) {

        printf( "\n   DRON S/N        DRON ALIAS      KMTOTALESH    MTOTALESV    \n\n");

      };
      printf(" %d  ", datoDron[indDron].idDron);
      printf(" %7s", datoDron[indDron].numSerDron);
      printf("%18s", datoDron[indDron].alias);
      printf("    %8d", datoDron[indDron].KmH);
      printf("  %12d\n", datoDron[indDron].MetrosV);

    };
    indDron++;

  } while ( datoDron[indDron].idDron<=(indDron +1) );

  printf("\nMOTORES HORIZONTALES\n\n");

  printf( "\n   DRON S/N        KMTOTALESH      PROXIMA REVISION    PORCENTAJE UTIL   \n\n");
  do {

    printf(" %d  ", datoDron[indDron-3].idDron);
    printf(" %7s", datoDron[indDron-3].numSerDron);
    printf("      %8d", datoDron[indDron-3].KmH);
    printf("       %12d", datoDron[indDron-3].proxRevHor);
    printf("         %12f\n", datoDron[indDron-3].porcentUtilH);

    indDron++;

  } while ( datoDron[indDron-3].idDron<=(indDron+1) );

  printf("\nMOTORES VERTICALES\n\n");

  printf( "\n   DRON S/N         MTOTALESV       PROXIMA REVISION    PORCENTAJE UTIL   \n\n");

  do {

    printf(" %d  ", datoDron[indDron-6].idDron);
    printf(" %7s", datoDron[indDron-6].numSerDron);
    printf("      %8d", datoDron[indDron-6].MetrosV);
    printf("       %12d", datoDron[indDron-6].proxRevV);
    printf("         %12f\n", datoDron[indDron-6].porcentUtilV);

    indDron++;

  } while ( datoDron[indDron-6].idDron<=(indDron +1) );

  printf("\n");
  system("pause");

}

/*  Procedimiento MENU PRINCIPAL     */

int TipoGestion::MenuPrincipal() {
  char teclaopc = 'X';
   char masPedidos = 'X';
  while (toupper(teclaopc) != 'S' ) {
    system("cls");
    printf( "\n\n\t============================================================\n" );
    printf( "\t|    GESTION de FarmaDrones:  Distribuci\xa2n de f\xa0rmacos     |\n" );
    printf( "\t============================================================\n" );
    printf( "\t|   >Listar almacen                           (Pulsar I)   |\n" );
    printf( "\t|   >Alta dron                                (Pulsar A)   |\n" );
    printf( "\t|   >Alta paciente                            (Pulsar P)   |\n" );
    printf( "\t|   >Baja dron                                (Pulsar B)   |\n" );
    printf( "\t|   >Nuevo pedido                             (Pulsar N)   |\n" );
    printf( "\t|   >Asignar drones                           (Pulsar D)   |\n" );
    printf( "\t|   >Lista mensual de pedidos por dron        (Pulsar L)   |\n" );
    printf( "\t|   >Informe de mantenimiento                 (Pulsar R)   |\n" );
    printf( "\t|   >Salir                                    (Pulsar S)   |\n" );
    printf( "\t------------------------------------------------------------\n" );
    printf( "\t|   Teclear una opci\xa2n valida      (I|A|P|B|N|D|L|R|G|S)?  |\n");
    printf( "\t------------------------------------------------------------\n" );
    fflush(stdin);
    scanf( " %c" , &teclaopc );

    switch (toupper(teclaopc)) {
    case 'I':
      InGestion(datoPaciente, datoAlmacen, datoPedido, comunicaFecha , datoDron);
      break;
    case 'A':
      AltaNewDron(datoDron,datoAlmacen);
      break;
    case 'P':
      AltaPaciente(datoPaciente, datoAlmacen);
      break;
    case 'B':
      BajaDron(datoDron, datoAlmacen);
      break;
    case 'N':
      NuevoPedido();
      break;
    case 'D':
      AsignarDron();
      break;
    case 'L':
      do {
        FechasEnvio( 0);
        calendario( filtraFecha[0].mes, filtraFecha[0].anio, masPedidos, DiasConPedidos);
      } while (toupper(masPedidos) != 'N');
      break;
    case 'R':
      InformeMantenimiento();
      break;

    default:
      printf(" Salir de la aplicacion ");
      return 0 ;
    };
  };

  return 0 ;
}



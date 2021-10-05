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

typedef TipoPaciente datoPaciente[20];
typedef TipoAlmacen datoAlmacen[1];
typedef TipoDrones datoDron[15];
typedef TipoPedido datoPedido[100];
typedef TipoFiltro datoFecha[50];

void InGestion(datoPaciente paci, datoAlmacen almac, datoPedido cedu, datoFecha fch, datoDron dron) {
  int indPaciente = 0;
  int indAlmacen = 0;
  int indDron = 0;
  int ftrAlmacen = 0 ;
  int totalreg = 0 ;
  int imprime = 0 ;

  /* Creo el vector de pacientes  */

  paci[0].idclave = 1 ;
  strcpy(paci[0].cadena, "David San Miguel");
  paci[0].angulo = 45;
  paci[0].distancia = 2970 ;
  paci[0].altura = 717;
  paci[0].almacen = 1;
  paci[0].reg_paciente = 0 ;

  paci[1].idclave = 2 ;
  strcpy(paci[1].cadena, "Roberto Rodriguez");
  paci[1].angulo = 875;
  paci[1].distancia = 7600;
  paci[1].altura = 1031;
  paci[1].almacen = 1;
  paci[1].reg_paciente = 1 ;

  paci[2].idclave = 3 ;
  strcpy(paci[2].cadena, "Roberto Estaras");
  paci[2].angulo = 1098;
  paci[2].distancia =6123 ;
  paci[2].altura = 812;
  paci[2].almacen = 1;
  paci[2].reg_paciente = 2 ;

  paci[3].idclave = 4 ;
  strcpy(paci[3].cadena, "Susana ColldeForns");
  paci[3].angulo = 1205;
  paci[3].distancia = 6680 ;
  paci[3].altura = 935;
  paci[3].almacen = 1;
  paci[3].reg_paciente = 3 ;

  paci[4].idclave = 5 ;
  strcpy(paci[4].cadena, "Eugenio Hernandez");
  paci[4].angulo = 1610;
  paci[4].distancia = 5020;
  paci[4].altura = 759;
  paci[4].almacen = 1 ;
  paci[4].reg_paciente = 4 ;

  /* cargo un vector de Almacen */

  almac[0].idAlmacen = 1 ;
  strcpy(almac[0].municipio, "Torrelaguna" );
  almac[0].altura= 737 ;

  /* cargo los datos en el vector de Pedidos */

  cedu[0].regPedido = 1 ;
  cedu[0].idPedido = 1;
  cedu[0].idPaciente = 1 ;
  cedu[0].idDron= 1;
  cedu[0].ruta= 1;
  cedu[0].dia = 5 ;
  cedu[0].mes = 2 ;
  cedu[0].anio = 2021 ;
  strcpy(cedu[0].farmaco, "AntiCovid2020" );
  cedu[0].peso = 20 ;
  cedu[0].units = 5;
  strcpy(cedu[0].numSerDron, "ABC9876" );
  strcpy(cedu[0].alias, "Pepedron" );
  cedu[0].ctdPedidos = 3;
  cedu[0].numDet = 1;
  cedu[0].idAlmacen = 1 ;

  cedu[1].regPedido = 2 ;
  cedu[1].idPedido = 2;
  cedu[1].idPaciente = 1 ;
  cedu[1].idDron= 2;
  cedu[1].ruta= 1;
  cedu[1].dia = 10 ;
  cedu[1].mes = 2 ;
  cedu[1].anio = 2021 ;
  strcpy(cedu[1].farmaco, "Zanamivir" );
  cedu[1].peso = 100 ;
  cedu[1].units = 1;
  strcpy(cedu[1].numSerDron, "GGH4451" );
  strcpy(cedu[1].alias, "Bisdron" );
  cedu[1].ctdPedidos = 3;
  cedu[1].numDet = 1;
  cedu[1].idAlmacen = 1 ;

  cedu[2].regPedido = 3 ;
  cedu[2].idPedido = 3;
  cedu[2].idPaciente = 3 ;
  cedu[2].idDron= 3;
  cedu[2].ruta= 1;
  cedu[2].dia = 18 ;
  cedu[2].mes = 3 ;
  cedu[2].anio = 2021 ;
  strcpy(cedu[2].farmaco, "Peramivir" );
  cedu[2].peso = 90 ;
  cedu[2].units = 1;
  strcpy(cedu[2].numSerDron, "GGK4451" );
  strcpy(cedu[2].alias, "Bisdron1" );
  cedu[2].ctdPedidos = 3;
  cedu[2].numDet = 1;
  cedu[2].idAlmacen = 1 ;

  cedu[3].regPedido = 4 ;
  cedu[3].idPedido = 4;
  cedu[3].idPaciente = 4 ;
  cedu[3].idDron= 2;
  cedu[3].ruta= 1;
  cedu[3].dia = 20 ;
  cedu[3].mes = 3 ;
  cedu[3].anio = 2021 ;
  strcpy(cedu[3].farmaco, "Zanamivir" );
  cedu[3].peso = 45 ;
  cedu[3].units = 2;
  strcpy(cedu[3].numSerDron, "GGH4451" );
  strcpy(cedu[3].alias, "Bisdron" );
  cedu[3].ctdPedidos = 7;
  cedu[3].numDet = 1;
  cedu[3].idAlmacen = 1 ;

  cedu[4].regPedido = 5 ;
  cedu[4].idPedido = 5;
  cedu[4].idPaciente = 4 ;
  cedu[4].idDron= 2;
  cedu[4].ruta= 1;
  cedu[4].dia = 20 ;
  cedu[4].mes = 3 ;
  cedu[4].anio = 2021 ;
  strcpy(cedu[4].farmaco, "Baloxavir" );
  cedu[4].peso = 45 ;
  cedu[4].units = 2;
  strcpy(cedu[4].numSerDron, "GGH4451" );
  strcpy(cedu[4].alias, "Bisdron" );
  cedu[4].ctdPedidos = 7;
  cedu[4].numDet = 1;
  cedu[4].idAlmacen = 1 ;

  cedu[5].regPedido = 6 ;
  cedu[5].idPedido = 6;
  cedu[5].idPaciente = 2 ;
  cedu[5].idDron= 3;
  cedu[5].ruta= 1;
  cedu[5].dia = 20 ;
  cedu[5].mes = 3 ;
  cedu[5].anio = 2021 ;
  strcpy(cedu[5].farmaco, "Amantadina" );
  cedu[5].peso = 110 ;
  cedu[5].units = 1;
  strcpy(cedu[5].numSerDron, "GGK4451" );
  strcpy(cedu[5].alias, "Bisdron1" );
  cedu[5].ctdPedidos = 1;
  cedu[5].numDet = 1;
  cedu[5].idAlmacen = 1 ;

  cedu[6].regPedido = 7 ;
  cedu[6].idPedido = 7;
  cedu[6].idPaciente = 2 ;
  cedu[6].idDron= 3;
  cedu[6].ruta= 1;
  cedu[6].dia = 20 ;
  cedu[6].mes = 3 ;
  cedu[6].anio = 2021 ;
  strcpy(cedu[6].farmaco, "Marboxil" );
  cedu[6].peso = 20;
  cedu[6].units = 2;
  strcpy(cedu[6].numSerDron, "GGK4451" );
  strcpy(cedu[6].alias, "Bisdron1" );
  cedu[6].ctdPedidos = 1;
  cedu[6].numDet = 1;
  cedu[6].idAlmacen = 1 ;

  cedu[7].regPedido = 8 ;
  cedu[7].idPedido = 8 ;
  cedu[7].idPaciente = 1 ;
  cedu[7].idDron= 3;
  cedu[7].ruta= 1;
  cedu[7].dia = 20 ;
  cedu[7].mes = 3 ;
  cedu[7].anio = 2021 ;
  strcpy(cedu[7].farmaco, "Oseltamivir" );
  cedu[7].peso = 70 ;
  cedu[7].units = 3;
  strcpy(cedu[7].numSerDron, "GGK4451" );
  strcpy(cedu[7].alias, "Bisdron1" );
  cedu[7].ctdPedidos = 1;
  cedu[7].numDet = 1;
  cedu[7].idAlmacen = 1 ;

  cedu[8].regPedido = 9 ;
  cedu[8].idPedido = 9 ;
  cedu[8].idPaciente = 4 ;
  cedu[8].idDron= 2;
  cedu[8].ruta= 1;
  cedu[8].dia = 25 ;
  cedu[8].mes = 3 ;
  cedu[8].anio = 2021 ;
  strcpy(cedu[8].farmaco, "Baloxavir" );
  cedu[8].peso = 45 ;
  cedu[8].units = 2 ;
  strcpy(cedu[8].numSerDron, "GGH4451" );
  strcpy(cedu[8].alias, "Bisdron" );
  cedu[8].ctdPedidos = 7;
  cedu[8].numDet = 1;
  cedu[8].idAlmacen = 1 ;

  cedu[9].regPedido = 10 ;
  cedu[9].idPedido = 10 ;
  cedu[9].idPaciente = 3 ;
  cedu[9].idDron= 1;
  cedu[9].ruta= 1;
  cedu[9].dia = 28 ;
  cedu[9].mes = 3 ;
  cedu[9].anio = 2021 ;
  strcpy(cedu[9].farmaco, "Peramivir" );
  cedu[9].peso = 90 ;
  cedu[9].units = 1;
  strcpy(cedu[9].numSerDron, "ABC9876" );
  strcpy(cedu[9].alias, "Pepedron" );
  cedu[9].ctdPedidos = 1;
  cedu[9].numDet = 1;
  cedu[9].idAlmacen = 1 ;

  cedu[10].regPedido = 11 ;
  cedu[10].idPedido = 11 ;
  cedu[10].idPaciente = 3 ;
  cedu[10].idDron= ' ';
  cedu[10].ruta= 1;
  cedu[10].dia = 25 ;
  cedu[10].mes = 4 ;
  cedu[10].anio = 2021;
  strcpy(cedu[10].farmaco, "Rimantadina" );
  cedu[10].peso = 15 ;
  cedu[10].units = 1;
  strcpy(cedu[10].numSerDron, "" );
  strcpy(cedu[10].alias, "" );
  cedu[10].ctdPedidos = 1;
  cedu[10].numDet = 1;
  cedu[10].idAlmacen = 1 ;

  cedu[11].regPedido = 12 ;
  cedu[11].idPedido = 12;
  cedu[11].idPaciente = 5 ;
  cedu[11].idDron= ' ';
  cedu[11].ruta= 2;
  cedu[11].dia = 28 ;
  cedu[11].mes = 4 ;
  cedu[11].anio = 2021 ;
  strcpy(cedu[11].farmaco, "AntiCovid2021" );
  cedu[11].peso = 40 ;
  cedu[11].units = 1;
  strcpy(cedu[11].numSerDron, "" );
  strcpy(cedu[11].alias, "" );
  cedu[11].ctdPedidos = 1;
  cedu[11].numDet = 1;
  cedu[11].idAlmacen = 1 ;

  cedu[12].regPedido = 13 ;
  cedu[12].idPedido = 13;
  cedu[12].idPaciente = 5 ;
  cedu[12].idDron= ' ';
  cedu[12].ruta= 2;
  cedu[12].dia = 30 ;
  cedu[12].mes = 4 ;
  cedu[12].anio = 2021 ;
  strcpy(cedu[12].farmaco, "AntiCovid2021" );
  cedu[12].peso = 40 ;
  cedu[12].units = 1;
  strcpy(cedu[12].alias, "" );
  cedu[12].ctdPedidos = 1;
  cedu[12].numDet = 1;
  cedu[12].idAlmacen = 1 ;

  cedu[13].regPedido = 14 ;
  cedu[13].idPedido = 14;
  cedu[13].idPaciente = 5 ;
  cedu[13].idDron= ' ';
  cedu[13].ruta= 2;
  cedu[13].dia = 2 ;
  cedu[13].mes = 5 ;
  cedu[13].anio = 2021 ;
  strcpy(cedu[13].farmaco, "AntiCovid2021" );
  cedu[13].peso = 40 ;
  cedu[13].units = 1;
  strcpy(cedu[13].alias, "" );
  cedu[13].ctdPedidos = 4;
  cedu[13].numDet = 1;
  cedu[13].idAlmacen = 1 ;

  cedu[14].regPedido = 15 ;
  cedu[14].idPedido = 15;
  cedu[14].idPaciente = 5 ;
  cedu[14].idDron= 2;
  cedu[14].ruta= 2;
  cedu[14].dia = 4 ;
  cedu[14].mes = 5 ;
  cedu[14].anio = 2021 ;
  strcpy(cedu[14].farmaco, "AntiCovid2021" );
  cedu[14].peso = 40 ;
  cedu[14].units = 1;
  strcpy(cedu[14].numSerDron, "GGH4451" );
  strcpy(cedu[14].alias, "" );
  cedu[14].ctdPedidos = 4;
  cedu[14].numDet = 1;
  cedu[14].idAlmacen = 1 ;

  cedu[15].regPedido = 16 ;
  cedu[15].idPedido = 16;
  cedu[15].idPaciente = 2 ;
  cedu[15].idDron= ' ';
  cedu[15].ruta= 1;
  cedu[15].dia = 4 ;
  cedu[15].mes = 5 ;
  cedu[15].anio = 2021 ;
  strcpy(cedu[15].farmaco, "Antiacido" );
  cedu[15].peso = 25 ;
  cedu[15].units = 2;
  strcpy(cedu[15].numSerDron, "GGK4451" );
  strcpy(cedu[15].alias, "" );
  cedu[15].ctdPedidos = 4;
  cedu[15].numDet = 1;
  cedu[15].idAlmacen = 1 ;

  cedu[16].regPedido = 17 ;
  cedu[16].idPedido = 17 ;
  cedu[16].idPaciente = 2 ;
  cedu[16].idDron= ' ';
  cedu[16].ruta= 1;
  cedu[16].dia = 4 ;
  cedu[16].mes = 5 ;
  cedu[16].anio = 2021 ;
  strcpy(cedu[16].farmaco, "Jarabe" );
  cedu[16].peso = 290 ;
  cedu[16].units = 1;
  strcpy(cedu[16].numSerDron, "GGK4451" );
  strcpy(cedu[16].alias, "" );
  cedu[16].ctdPedidos = 4;
  cedu[16].numDet = 1;
  cedu[16].idAlmacen = 1 ;

  cedu[17].regPedido = 18 ;
  cedu[17].idPedido = 18 ;
  cedu[17].idPaciente = 3 ;
  cedu[17].idDron= ' ';
  cedu[17].ruta= 1;
  cedu[17].dia = 4 ;
  cedu[17].mes = 5 ;
  cedu[17].anio = 2021 ;
  strcpy(cedu[17].farmaco, "Ibuprofeno" );
  cedu[17].peso = 120 ;
  cedu[17].units = 1 ;
  strcpy(cedu[17].numSerDron, "GGK4451" );
  strcpy(cedu[17].alias, "" );
  cedu[17].ctdPedidos = 1;
  cedu[17].numDet = 1;
  cedu[17].idAlmacen = 1 ;

  cedu[18].regPedido = 19 ;
  cedu[18].idPedido = 19 ;
  cedu[18].idPaciente = 4 ;
  cedu[18].idDron= ' ';
  cedu[18].ruta= 1;
  cedu[18].dia = 15 ;
  cedu[18].mes = 5 ;
  cedu[18].anio = 2021 ;
  strcpy(cedu[18].farmaco, "Baloxavir" );
  cedu[18].peso = 45 ;
  cedu[18].units = 1 ;
  strcpy(cedu[18].numSerDron, "GGK4451" );
  strcpy(cedu[18].alias, "" );
  cedu[18].ctdPedidos = 7;
  cedu[18].numDet = 1;
  cedu[18].idAlmacen = 1 ;

  cedu[19].regPedido = 20 ;
  cedu[19].idPedido = 20 ;
  cedu[19].idPaciente = 4 ;
  cedu[19].idDron= ' ';
  cedu[19].ruta= 1;
  cedu[19].dia = 20 ;
  cedu[19].mes = 5 ;
  cedu[19].anio = 2021 ;
  strcpy(cedu[19].farmaco, "Baloxavir" );
  cedu[19].peso = 45 ;
  cedu[19].units = 1;
  strcpy(cedu[19].numSerDron, "" );
  strcpy(cedu[19].alias, "" );
  cedu[19].ctdPedidos = 7;
  cedu[19].numDet = 1;
  cedu[19].idAlmacen = 1 ;

  cedu[20].regPedido = 21 ;
  cedu[20].idPedido = 21 ;
  cedu[20].idPaciente = 4 ;
  cedu[20].idDron= ' ';
  cedu[20].ruta= 1;
  cedu[20].dia = 25 ;
  cedu[20].mes = 5 ;
  cedu[20].anio = 2021 ;
  strcpy(cedu[20].farmaco, "Baloxavir" );
  cedu[20].peso = 45 ;
  cedu[20].units = 1 ;
  strcpy(cedu[20].alias, "" );
  cedu[20].ctdPedidos = 7;
  cedu[20].numDet = 1;
  cedu[20].idAlmacen = 1 ;

  cedu[21].regPedido = 22 ;
  cedu[21].idPedido = 22 ;
  cedu[21].idPaciente = 4 ;
  cedu[21].idDron= ' ';
  cedu[21].ruta= 1;
  cedu[21].dia = 30 ;
  cedu[21].mes = 5 ;
  cedu[21].anio = 2021 ;
  strcpy(cedu[21].farmaco, "Baloxavir" );
  cedu[21].peso = 45 ;
  cedu[21].units = 1 ;
  strcpy(cedu[21].alias, "" );
  cedu[21].ctdPedidos = 7;
  cedu[21].numDet = 1;
  cedu[21].idAlmacen = 1 ;

  /* cargo el vector drones */

  strcpy (dron[0].numSerDron, "ABC9876");
  strcpy (dron[0].alias, "Pepedron");
  dron[0].idDron= 1;
  dron[0].KmH = 4060 ;
  dron[0].KmRevH = 400 ;
  dron[0].MetrosV = 62100 ;
  dron[0].MetrosRevV = 10000;
  dron[0].almacen = 1;
  dron[0].reg_dron = 0 ;
  dron[0].proxRevHor = 4500 ;
  dron[0].porcentUtilH = 60.0*100.0/400.0-100.0 ;
  dron[0].proxRevV = 70000 ;
  dron[0].porcentUtilV = 2100.0*100.0/10000.0 ;

  strcpy (dron[1].numSerDron, "GGH4451");
  strcpy (dron[1].alias, "Bisdron");
  dron[1].idDron= 2;
  dron[1].KmH = 2990 ;
  dron[1].KmRevH = 500 ;
  dron[1].MetrosV = 35000 ;
  dron[1].MetrosRevV = 6000;
  dron[1].almacen = 1;
  dron[1].reg_dron = 1 ;
  dron[1].proxRevHor = 3500 ;
  dron[1].porcentUtilH = 44.0*100.0/500.0-100.0 ;
  dron[1].proxRevV = 36000 ;
  dron[1].porcentUtilV = 572.0*100.0/6000.0 ;

  strcpy (dron[2].numSerDron, "GGK4451");
  strcpy (dron[2].alias, "Bisdron1");
  dron[2].idDron= 3;
  dron[2].KmH = 3045 ;
  dron[2].KmRevH = 500 ;
  dron[2].MetrosV = 34160 ;
  dron[2].MetrosRevV = 6000;
  dron[2].almacen = 1;
  dron[2].reg_dron = 2 ;
  dron[2].proxRevHor = 3500 ;
  dron[2].porcentUtilH = 90.0*100.0/500.0-100.0 ;
  dron[2].proxRevV = 36000 ;
  dron[2].porcentUtilV = 440.0*100.0/6000.0 ;

  system("cls");

  printf("\n\n  =>DATOS ACTUALES \n\n" );

  do {

    if (almac[indAlmacen].idAlmacen == indAlmacen +1) {
      printf("\t==============================\n");
      printf("\t|  Descripcion: %s  |\n" , almac[indAlmacen].municipio);
      printf("\t|  Altura: %d mts           |\n" , almac[indAlmacen].altura);
      printf("\t==============================\n");

    }
    do {

      if ( paci[indPaciente].almacen == indAlmacen +1) {

        if (paci[indPaciente].idclave ==  1) {

          printf("\n  =>CLIENTES\n\n");
          printf("\t======================================================================\n");
          printf("\t|Ref.      Identificador         Distancia      \xb5ngulo       Altura  |\n");
          printf("\t======================================================================\n");
        };


        printf("\t|  %d |", paci[indPaciente].idclave);
        printf("|    %-20s |", paci[indPaciente].cadena);
        printf("| %5d |", paci[indPaciente].distancia);
        printf("|      %4d   |", paci[indPaciente].angulo);
        printf("|    %4d   |\n", paci[indPaciente].altura);

      };

      indPaciente++;


    } while (paci[indPaciente].idclave== (indPaciente +1) );



    ftrAlmacen = indAlmacen +1 ;
    totalreg = 0;
    for (int j = 0; j < 25 ; j++) {
      fch[j].registro = 0;
      fch[j].dia = 0 ;
      fch[j].mes = 0 ;
      fch[j].anio = 0 ;
      fch[j].pedido = 0 ;
    };

    OrdenarFechas(cedu, fch, totalreg);

    for (int i = 0; i < totalreg ; i++) {

      if (fch[i].pedido == ftrAlmacen ) {

        if (imprime == 0) {
          printf("\t======================================================================\n\n");
          printf("  =>PEDIDOS \n\n");
          printf("\t=================================================================================\n");
          printf("\t|Cliente        Fecha            Farmaco          Peso   Unidades       Dron    |\n"  );
          printf("\t=================================================================================\n");
          imprime++;
        };

        printf("\t|   %2d    |   %2d/%02d/%4d  |" , cedu[fch[i].registro-1].idPaciente,  cedu[fch[i].registro-1].dia,   cedu[fch[i].registro-1].mes ,  cedu[fch[i].registro-1].anio ) ;
        printf(" %-20s|" , cedu[fch[i].registro-1].farmaco) ;
        printf("%5d  |   %2d   |  %10s  |\n" , cedu[fch[i].registro-1].peso, cedu[fch[i].registro-1].units, cedu[fch[i].registro-1].alias) ;

      };
    };
    totalreg = 0;
    indAlmacen++;
    imprime=0;


    if ( dron[indDron].idDron==(indDron +1)) {
      if (dron[indDron].idDron == 1) {
        printf("\t=================================================================================\n\n");

        printf("  =>DRONES\n\n");

        printf("\t=================================================================================\n");
        printf( "\t|Ref  Numero Serie      Alias         KmH       KmRevH     MetrosV   MetrosRevV |\n");
        printf("\t=================================================================================\n");
      };
      printf("\t| %d |\t", dron[indDron].idDron);
      printf("%8s   |", dron[indDron].numSerDron);
      printf(" %9s  |", dron[indDron].alias);
      printf("%8d   |", dron[indDron].KmH);
      printf("%8d   |", dron[indDron].KmRevH);
      printf("%8d   |", dron[indDron].MetrosV);
      printf("%8d   |\n", dron[indDron].MetrosRevV);

    };

    indDron++;

  } while ( dron[indDron].idDron<=(indDron +1) );

  printf("\t=================================================================================\n");




  system("pause");
}

void OrdenarFechas(datoPedido cedu, datoFecha fch, int & totalreg ) {

  int ind0 = 0 ;


  do {

    fch[ind0].registro = cedu[ind0].regPedido;
    fch[ind0].dia = cedu[ind0].dia ;
    fch[ind0].mes = cedu[ind0].mes ;
    fch[ind0].anio = cedu[ind0].anio ;
    fch[ind0].pedido = cedu[ind0].idAlmacen;
    totalreg = totalreg + 1;
    ind0++;

  } while (cedu[ind0].regPedido > ind0 );

  /*    ORDENO FECHAS    */

  for (int i = 0 ; i < totalreg; i++) {

    for (int y = 0 ; y < totalreg; y++) {
      if ( fch[y].anio >  fch[y+1].anio) {
        FijarTabla( y , fch);
      } else if ( fch[y].anio ==  fch[y+1].anio && fch[y].mes >  fch[y+1].mes) {

        FijarTabla( y , fch);

      } else if ( fch[y].anio ==  fch[y+1].anio &&
                  fch[y].mes  ==  fch[y+1].mes &&
                  fch[y].dia >  fch[y+1].dia) {

        FijarTabla( y , fch);
      };

    };
  };

}

void FijarTabla(int orden, datoFecha fch ) {

  int dia2 = 0;
  int mes2 = 0;
  int anio2 = 0;
  int auxreg = 0;
  int auxalma = 0;

  anio2 = fch[orden+1].anio;
  mes2 =  fch[orden+1].mes;
  dia2 =  fch[orden+1].dia;
  auxreg =  fch[orden+1].registro ;
  auxalma = fch[orden+1].pedido ;

  fch[orden+1].anio =  fch[orden].anio;
  fch[orden+1].mes  =  fch[orden].mes;
  fch[orden+1].dia =   fch[orden].dia;
  fch[orden+1].registro =  fch[orden].registro;
  fch[orden+1].pedido =  fch[orden].pedido;

  fch[orden].anio = anio2 ;
  fch[orden].mes = mes2 ;
  fch[orden].dia = dia2 ;
  fch[orden].registro = auxreg ;
  fch[orden].pedido = auxalma ;

}








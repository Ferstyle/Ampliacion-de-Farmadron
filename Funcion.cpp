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
#include "Funcion.h"

float calculos(float distanciaA, float anguloA, float distanciaB, float anguloB, int operacion) {
  float xA = 0;
  float xB = 0;
  float yA = 0;
  float yB = 0;
  float resultadoA = 0 ;
  float resultadoB = 0 ;
  float distaAB = 0 ;
  float anguloAB = 0 ;
  float pendiente = 0 ;

  resultadoA = (anguloA * 3.1415)/1000;
  resultadoB = (anguloB * 3.1415)/1000;
  xA = distanciaA * cos( resultadoA);
  yA = distanciaA * sin( resultadoA);
  xB = distanciaB * cos( resultadoB);
  yB = distanciaB * sin( resultadoB);
  pendiente = (yB-yA)/(xB-xA) ;
  anguloAB = atan((yB-yA)/(xB-xA));
  anguloAB =  anguloAB * 180 / 3.1416;


  /* Cálculo de distancia entre dos paciente; operación = 1 */

  if (operacion == 1) {
    distaAB = sqrt(pow((xB-xA),2) + pow((yB - yA),2));
    return distaAB;
  };

  /* Cálculo del angulo  entre dos puntos; operación = 2*/

  if (operacion == 2) {
    if ( pendiente < 0) {
      anguloAB = anguloAB + 360;
    } else {
      anguloAB = anguloAB + 180;
    };
    anguloAB = anguloAB /180 * 1000 ;
    return anguloAB ;
  };

  /* Cálculo del angulo final desde la ultima entrega al almacen; operación = 3 */

  if (operacion == 3) {
    if (anguloA >= 0 && anguloA <= 500) {
      anguloAB = anguloAB + 180;
    } else if (anguloA >= 501 && anguloA <= 1000) {
      anguloAB = 180 - anguloAB;
    } else if (anguloA >= 1001 && anguloA <= 1500) {
      anguloAB = anguloAB ;
    } else {
      anguloAB = 360 - anguloAB;
    };
    anguloAB = anguloAB /180 * 1000 ;
    return anguloAB ;
  };

  return anguloAB;

}



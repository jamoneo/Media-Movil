/* ========================================================================== */
/*                                                                           */
/*   Media_Movil.c                                                                */
/*   (c) 2019 Jose Angel Moneo                                               */
/*                                                                            */
/*   Clase Media Movil                                                          */
/* ========================================================================== */

#include "Media_Movil.h"



void Media_Movil::init(int muestras){
   if (muestras>MUESTRAS_MM_MAX)
      {Serial.println("Espacio insuficiente para la media movil");
       Muestras=MUESTRAS_MM_MAX;
      } 
   else    Muestras=muestras;
   for(int h=0;h<MUESTRAS_MM_MAX;h++)     Medidas[h]=0; //borra tabla de medias
    S_Medidas=0; //Borra la suma de valores
   Pini=0;
  // Pfin=Muestras; //iniciamos los punteros de la cola
}


void  Media_Movil::Media(float valor)
{  int Pfin;
   //SE saca el primer dato más antiguo de la cola
  S_Medidas-=Medidas[Pini]; //Resta el valor más inicio (antiguo) de la cola

// Tomamos el indice del final de cola para almacenar dato más reciente
 Pfin=Pini+Muestras-1; //Punto final de la cola
 // Si el puntero pasa del maximo de la tabla se corrige 
 if(Pfin>(Muestras-1)) Pfin-=Muestras;
 S_Medidas+=Medidas[Pfin]=valor;  //Almacenamos el último valor
//Avance puntero cola
 Pini++;
  if(Pini==Muestras) Pini=0; //Se reinicia si llegamos al final de la tabla

  return;
}

//toma la media movil actual
float Media_Movil::get()
{  return S_Medidas/(Muestras-1);}

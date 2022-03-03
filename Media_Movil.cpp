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

#ifdef ESP_H
void  Media_Movil::Media(long valor)
#else
void  Media_Movil::Media(float valor)
#endif
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
#ifdef ESP_H
long Media_Movil::get()
#else
float Media_Movil::get()
#endif
{  return S_Medidas/(Muestras-1);}

#ifdef ESP_H
long Media_Movil::get_Mediana()
#else
float Media_Movil::get_Mediana()
#endif
{int i, j, l, m,kth;

  #ifdef ESP_H
   long x;
  #else
   float x;
  #endif
  kth=Muestras/2;

  l = 0;
  m = Muestras - 1;
  while (l < m)
  {
    x = Medidas[kth];
    i = l;
    j = m;
    do
    {
      while (Medidas[i] < x) i++;
      while (x < Medidas[j]) j--;
      if (i <= j)
      {
        #ifdef ESP_H
          long t = Medidas[j];
        #else
          float t = Medidas[j];
        #endif
        Medidas[j] = Medidas[i];
        Medidas[i] = t;
        i++;
        j--;
      }
    }
    while (i <= j);
    if (j < kth) l = i;
    if (kth < i) m = j;
  }
  return Medidas[kth];

  
}

//toma la media movil actual
float Media_Movil::get()
{  return S_Medidas/(Muestras-1);}

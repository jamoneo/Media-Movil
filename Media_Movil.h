//  Clase Media_Movil.h
// (c) Jose Angel Moneo (2019)
//
// devuelve su media movil
//  v1.1
 // (c)  José Angel Moneo (2019)
// Mediante init se puede definir el numero de muestras en la media movil
// El numero máximo de muestras reservadas en la tabla es de 100 por defecto
// definidad mediante MUESTRAS_MAX . 
// Si se desea reducir espacio o ampliar la tabla, habrá que redefinir esta constante 
// en el programa principal


#ifndef _Media_Movil_class_H
#define _Media_Movil_class_H

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

//Numero de muestras por defecto
#ifndef MUESTRAS_MM_MAX
   #define MUESTRAS_MM_MAX 100
#endif


class Media_Movil
{ private:
   float  Medidas[MUESTRAS_MM_MAX];  //Tabla de valores de las últimas medidas para media para 20 variables con una media de 20 maxima
   float S_Medidas;  //Suma de las medidas
   int Muestras;
   int Pini; //indexadores a tabla
public:
   
   Media_Movil(){}; //constructor para servo. indicamos el las salidas del servo
   void init(int muestras);
   void  Media(float valor);  //almacena un nuevo valor y devuelve la media movil actual
   float get();  //devuelve la media movil actual
	};
  #endif


   

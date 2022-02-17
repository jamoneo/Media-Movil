#include "Media_Movil.h"
//opcionalmente se puede definir el tamaño maximo del buffer de media
// por defecto está en 100
// #define MUESTRAS_MAX 25  
   
Media_Movil Media_A;  //Media movil

void setup() {
//Asignamos e iniciamos la media movil para 50 muestras. Puede llegar a 200 sin asignar buffer maximo
   Media_A.init(50); 
}

void loop() {
 // Tomamos el dato y lo añadimos a la media
  Media_A.Media(analogRead(0));
 // Muestra el valor de la entrada pasado por la media movil
  Serial.println(Media_A.get()); 
}

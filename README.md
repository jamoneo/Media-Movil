# Media-Movil
Media Movil Class. Permite realizar una media movil de los datos según se recogen, para luego procesarlos.
El número de muestras de la media es configurable, pudiendo admitir hasta 100.
Este numero maximo de espacio en memoria puede ser reconfigurado mediante

   #define MUESTRAS_MM_MAX 100
  
puesto en el porgrama main, antes de #include Media_Movil.h  

Funciones:

     void init(int muestras); //Inicializa la media a un número de muestras
     void  Media(float valor);  //almacena un nuevo valor y devuelve la media movil actual
     float get();  //devuelve la media movil actual

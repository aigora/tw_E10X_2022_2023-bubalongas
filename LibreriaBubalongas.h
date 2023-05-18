#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_FILAS 18
#define NUM_COLUMNAS 24

typedef struct{
	char mes[10];
	int anyo; 
}date;

typedef struct{
	char tipo[50];
	float magnitud;
	date fecha; 
}generacion_2122;

float maxtipo(generacion_2122 matriz[][NUM_COLUMNAS], int filas, int columnas)
{ 
  int i, anyo;
  float max;
  char mes[10];
  
  max=matriz[filas][columnas].magnitud;
  
  for(i=1; i<columnas; i++)
  {
  	if(matriz[filas][i].magnitud>max)
  	{
  		max=matriz[filas][i].magnitud;
  		anyo=matriz[filas][i].fecha.anyo;
  		strcpy(mes, matriz[filas][i].fecha.mes);
    }
  	  
  }
  
  printf("El maximo en hidraulica es %f y se dio en %s del %i\n", max, mes, anyo);
  
  return max;
}

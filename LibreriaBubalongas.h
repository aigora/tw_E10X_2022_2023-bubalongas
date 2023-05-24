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
  int i, ano=0;
  float max=0;
  char mes[10];
  
  max=matriz[filas][0].magnitud;
  ano=matriz[filas][0].fecha.anyo;
  strcpy(mes, matriz[filas][0].fecha.mes);
  
  for(i=1; i<columnas; i++)
  {
  	if(matriz[filas][i].magnitud>max)
  	{
  		max=matriz[filas][i].magnitud;
  		ano=matriz[filas][i].fecha.anyo;
  		strcpy(mes, matriz[filas][i].fecha.mes);
    }
  }
  
  printf("\nEl maximo en %s es %f y se dio en %s del %i\n\n", matriz[filas][0].tipo, max, mes, ano);
  
  return max;
}

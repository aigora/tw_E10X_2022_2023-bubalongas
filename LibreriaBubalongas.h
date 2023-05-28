#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

float mediatipo(generacion_2122 matriz[][NUM_COLUMNAS], int filas, int columnas) 
{
    int i;
    float media = 0, suma = 0;
    
    for(i = 0; i < columnas; i++)
    {
    	suma += matriz[filas][i].magnitud;
	}
	
	media = suma / columnas;
	
	printf("\nLa media en %s es %f\n\n", matriz[filas][0].tipo, media);
	
	return media;
}

float modatipo(generacion_2122 matriz[][NUM_COLUMNAS], int filas, int columnas)//esta mal
{ 
  int i, ano = 0;
  float moda = 0;
  char mes[10];
  
  moda = matriz[filas][0].magnitud;
  ano = matriz[filas][0].fecha.anyo;
  strcpy(mes, matriz[filas][0].fecha.mes);
  
  for(i = 1; i < columnas; i++)
  {
  	if(matriz[filas][i].magnitud > moda)
  	{
  		moda = matriz[filas][i].magnitud;
  		ano = matriz[filas][i].fecha.anyo;
  		strcpy(mes, matriz[filas][i].fecha.mes);
    }
  }
  
  printf("\nLa moda en %s es %f y se dio en %s del %i\n\n", matriz[filas][0].tipo, moda, mes, ano);
  
  return moda;
}
  
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


float mintipo(generacion_2122 matriz[][NUM_COLUMNAS], int filas, int columnas) 
{
    int i, ano = 0;
    float min = 0;
    char mes[10];
  
    min = matriz[filas][0].magnitud;
    ano = matriz[filas][0].fecha.anyo;
    strcpy(mes, matriz[filas][0].fecha.mes);
  
    for (i = 1; i < columnas; i++) 
	{
        if (matriz[filas][i].magnitud < min) 
		{
            min = matriz[filas][i].magnitud;
            ano=matriz[filas][i].fecha.anyo;
            strcpy(mes, matriz[filas][i].fecha.mes);
        }
    }
  
    printf("\nEl valor minimo en %s es %f y se dio en %s del %i\n\n", matriz[filas][0].tipo, min, mes, ano);
    

    return min;
}

float sumtipo(generacion_2122 matriz[][NUM_COLUMNAS], int filas, int columnas) 
{
    int i;
    float sum = 0;
    
    for(i = 0; i < columnas; i++)
    {
    	sum += matriz[filas][i].magnitud;
	}
	
	printf("\nEl sumatorio de %s es %f\n\n", matriz[filas][0].tipo, sum);
	
	return sum;
}

float medianatipo(generacion_2122 matriz[][NUM_COLUMNAS], int filas, int columnas) 
{
	int i;
	float mediana = 0;
	
	mediana = (matriz[filas][11].magnitud + matriz[filas][12].magnitud) / 2.0;
	
	printf("\nLa mediana en %s es %f\n\n", matriz[filas][0].tipo, mediana);
	
	return mediana;
}

float varianzatipo(generacion_2122 matriz[][NUM_COLUMNAS], int filas, int columnas) 
{
	int i;
    float media = 0, suma = 0, varianza = 0, varianza_numerador = 0;
    
    for(i = 0; i < columnas; i++)
    {
    	suma += matriz[filas][i].magnitud;
	}
	
	media = suma / columnas;
	
	for(i = 0; i < columnas; i++)
    {
    	varianza_numerador += pow(matriz[filas][i].magnitud - media, 2);
	}
	
	varianza = varianza_numerador / columnas;
	
	printf("\nLa varianza en %s es %f\n\n", matriz[filas][0].tipo, varianza);
	
	return varianza;
}

float destipicatipo(generacion_2122 matriz[][NUM_COLUMNAS], int filas, int columnas) 
{
	int i;
    float media = 0, suma = 0, varianza = 0, varianza_numerador = 0, desviaciontipica = 0;
    
    for(i = 0; i < columnas; i++)
    {
    	suma += matriz[filas][i].magnitud;
	}
	
	media = suma / columnas;
	
	for(i = 0; i < columnas; i++)
    {
    	varianza_numerador += pow(matriz[filas][i].magnitud - media, 2);
	}
	
	varianza = varianza_numerador / columnas;
	
	desviaciontipica = sqrt(varianza);
	
	printf("\nLa desviacion tipica en %s es %f\n\n", matriz[filas][0].tipo, desviaciontipica);
	
	return desviaciontipica;
}

//falta ordenar ambas, para los meses

float mediacolumna(generacion_2122 matriz[NUM_FILAS][NUM_COLUMNAS], int filas, int columnas) 
{
    int i;
    float media = 0, suma = 0;
    
    for(i = 0; i < filas; i++)
    {
    	suma += matriz[i][columnas].magnitud;
	}
	
	media = suma / filas;
	
	printf("\nLa media en %s-%i es %f\n\n", matriz[0][columnas].fecha.mes, matriz[0][columnas].fecha.anyo, media);
	
	return media;
}

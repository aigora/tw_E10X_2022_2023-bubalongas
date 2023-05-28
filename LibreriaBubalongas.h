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

// 1.1 MEDIA POR FILA
float mediatipo(generacion_2122 matriz[][NUM_COLUMNAS], int filas, int columnas, FILE *ptranscrip) 
{
    int i;
    float media = 0, suma = 0;
    
    for(i = 0; i < columnas; i++)
    {
    	suma += matriz[filas][i].magnitud;
	}
	
	media = suma / columnas;
	
	printf("\nLa media en %s es %f\n\n", matriz[filas][0].tipo, media);
	
	ptranscrip = fopen("TrancripcionProyecto.txt", "a");
  
    fprintf(ptranscrip, "La media en %s es %f\n", matriz[filas][0].tipo, media);
    
	fclose(ptranscrip);
	
	return media;
}

// 1.2 MODA POR FILA
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

// 1.3 MAXIMO POR FILA
float maxtipo(generacion_2122 matriz[][NUM_COLUMNAS], int filas, int columnas, FILE *ptranscrip)
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
  
  ptranscrip = fopen("TrancripcionProyecto.txt", "a");
  
  fprintf(ptranscrip, "El maximo en %s es %f y se dio en %s del %i\n", matriz[filas][0].tipo, max, mes, ano);
    
  fclose(ptranscrip);
  
  return max;
}

// 1.4 MINIMO POR FILA
float mintipo(generacion_2122 matriz[][NUM_COLUMNAS], int filas, int columnas, FILE *ptranscrip) 
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
    
	ptranscrip = fopen("TrancripcionProyecto.txt", "a");
  
    fprintf(ptranscrip, "El valor minimo en %s es %f y se dio en %s del %i\n", matriz[filas][0].tipo, min, mes, ano);
    
	fclose(ptranscrip);

    return min;
}

// 1.5 SUMA POR FILA
float sumtipo(generacion_2122 matriz[][NUM_COLUMNAS], int filas, int columnas, FILE *ptranscrip) 
{
    int i;
    float sum = 0;
    
    for(i = 0; i < columnas; i++)
    {
    	sum += matriz[filas][i].magnitud;
	}
	
	printf("\nEl sumatorio de %s es %f\n\n", matriz[filas][0].tipo, sum);
	
	ptranscrip = fopen("TrancripcionProyecto.txt", "a");
  
    fprintf(ptranscrip, "El sumatorio de %s es %f\n", matriz[filas][0].tipo, sum);
    
	fclose(ptranscrip);
	
	return sum;
}

// 1.6 MEDIANA POR FILA
float medianatipo(generacion_2122 matriz[][NUM_COLUMNAS], int filas, int columnas, FILE *ptranscrip) 
{
	int i;
	float mediana = 0;
	
	mediana = (matriz[filas][11].magnitud + matriz[filas][12].magnitud) / 2.0;
	
	printf("\nLa mediana en %s es %f\n\n", matriz[filas][0].tipo, mediana);
	
	ptranscrip = fopen("TrancripcionProyecto.txt", "a");
  
    fprintf(ptranscrip, "La mediana en %s es %f\n", matriz[filas][0].tipo, mediana);
    
	fclose(ptranscrip);	
	
	return mediana;
}

// 1.7 VARIANZA POR FILA
float varianzatipo(generacion_2122 matriz[][NUM_COLUMNAS], int filas, int columnas, FILE *ptranscrip) 
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
	
	ptranscrip = fopen("TrancripcionProyecto.txt", "a");
  
    fprintf(ptranscrip, "La varianza en %s es %f\n", matriz[filas][0].tipo, varianza);
    
	fclose(ptranscrip);	
	
	return varianza;
}

// 1.8 DESVIACION TIPICA POR FILA
float destipicatipo(generacion_2122 matriz[][NUM_COLUMNAS], int filas, int columnas, FILE *ptranscrip) 
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
	
	ptranscrip = fopen("TrancripcionProyecto.txt", "a");
  
    fprintf(ptranscrip, "La desviacion tipica en %s es %f\n", matriz[filas][0].tipo, desviaciontipica);
    
	fclose(ptranscrip);	
	
	return desviaciontipica;
}

// 1.9 ORDENAR DE MAYOR A MENOR POR FILAS
void ordenar_max_min_filas(generacion_2122 matriz[][NUM_COLUMNAS], int filas, int columnas, FILE *ptranscrip)
{

	int i,j,k=24, ano_mayor;
	float v[24], mayor;
	char cadenaaux[10];
	date fechas[24];
	
	for (i=0; i < k; i++)
	{
		v[i]=matriz[filas][i].magnitud;
	}
	
	for (i=0; i < k; i++)
	{
		fechas[i].anyo=matriz[filas][i].fecha.anyo;
		strcpy(fechas[i].mes, matriz[filas][i].fecha.mes);
	}
	
	
	for( j=0; j<k-1; j++)
	{
		for (i=0; i < k-1; i++)
		{
			if (v[i]< v[i+1])
				{
				mayor = v[i];
				v[i] =v[i+1];
				v[i+1]=mayor;
				ano_mayor = fechas[i].anyo;
				fechas[i].anyo = fechas[i+1].anyo;
				fechas[i+1].anyo = ano_mayor;
				strcpy(cadenaaux, fechas[i].mes);
				strcpy(fechas[i].mes, fechas[i+1].mes);
				strcpy(fechas[i+1].mes, cadenaaux);
				}
		}
		
   	}
	for (i=0; i< k; i++)
		printf ("%d) %f en %s-%i\n", i+1, v[i], fechas[i].mes, fechas[i].anyo);
	printf("\n\n");
	
	ptranscrip = fopen("TrancripcionProyecto.txt", "a");
  
    for (i=0; i< k; i++)
		fprintf(ptranscrip, "%d) %f en %s-%i\n", i+1, v[i], fechas[i].mes, fechas[i].anyo);
    
	fclose(ptranscrip);
	
}

// 1.10 ORDENAR DE MENOR A MAYOR POR FILAS
void ordenar_min_max_filas(generacion_2122 matriz[][NUM_COLUMNAS], int filas, int columnas, FILE *ptranscrip)
{
	//NECESITO COPIAR VECTOR DEL EXCEL 
	int i,j,mayor,k=24;
	float v[24];
	
	for(j =0; j < k-1; j++)
	{
		for (i=0; i < k-1; i++)
		{
			if (v[i]> v[i+1])
			{
				mayor = v[i];
				v[i] =v[i+1];
				v[i+1]=mayor;
			}
		}
	}
	for (i=0; i< k; i++)
		printf ("%d) %d\n", i+1, v[i]);
	printf("\n\n");

}

// 2.1 MEDIA POR COLUMNAS
float mediacolumna(generacion_2122 matriz[NUM_FILAS][NUM_COLUMNAS], int filas, int columnas, FILE *ptranscrip) 
{
    int i;
    float media = 0, suma = 0;
    
    for(i = 0; i < filas; i++)
    {
    	suma += matriz[i][columnas].magnitud;
	}
	
	media = suma / filas;
	
	printf("\nLa media en %s-%i es %f\n\n", matriz[0][columnas].fecha.mes, matriz[0][columnas].fecha.anyo, media);
	
	ptranscrip = fopen("TrancripcionProyecto.txt", "a");
  
    fprintf(ptranscrip, "La media en %s-%i es %f\n", matriz[0][columnas].fecha.mes, matriz[0][columnas].fecha.anyo, media);
    
	fclose(ptranscrip);
  	 
	return media;
}

// 2.2 MAXIMO POR COLUMNAS
float maxcolumnas(generacion_2122 matriz[NUM_FILAS][NUM_COLUMNAS], int filas, int columnas, FILE *ptranscrip)
{ 
	int i, ano=0;
  	float max=0;
  	char mes[10];
  	char tipo[100];
  
 	max=matriz[0][columnas].magnitud;
  	ano=matriz[0][columnas].fecha.anyo;
  	strcpy(mes, matriz[0][columnas].fecha.mes);
  	strcpy(tipo, matriz[filas][0].tipo);
  
  	for(i=1; i<filas; i++)
  	{
  		if(matriz[i][columnas].magnitud>max)
  		{
  			max=matriz[i][columnas].magnitud;
  			ano=matriz[i][columnas].fecha.anyo;
  			strcpy(mes, matriz[i][columnas].fecha.mes);
  			strcpy(tipo, matriz[i][columnas].tipo);
    	}
  	}
  
  	printf("\nEl maximo en %s del %i es %f y se dio en %s\n\n", mes, ano, max, tipo);
  
  	ptranscrip = fopen("TrancripcionProyecto.txt", "a");
  
  	fprintf(ptranscrip, "El maximo en %s del %i es %f y se dio en %s\n", mes, ano, max, tipo);
    
  	fclose(ptranscrip);
  
  	return max;
}

// 2.3 MINIMO POR COLUMNAS
float mincolumnas(generacion_2122 matriz[NUM_FILAS][NUM_COLUMNAS], int filas, int columnas, FILE *ptranscrip)
{ 
	int i, ano=0;
  	float min=0;
  	char mes[10];
  	char tipo[100];
  
 	min=matriz[0][columnas].magnitud;
  	ano=matriz[0][columnas].fecha.anyo;
  	strcpy(mes, matriz[0][columnas].fecha.mes);
  	strcpy(tipo, matriz[filas][0].tipo);
  
  	for(i=1; i<filas; i++)
  	{
  		if(matriz[i][columnas].magnitud < min)
  		{
  			min=matriz[i][columnas].magnitud;
  			ano=matriz[i][columnas].fecha.anyo;
  			strcpy(mes, matriz[i][columnas].fecha.mes);
  			strcpy(tipo, matriz[i][columnas].tipo);
    	}
  	}
  
  	printf("\nEl minimo en %s del %i es %f y se dio en %s\n\n", mes, ano, min, tipo);
  
  	ptranscrip = fopen("TrancripcionProyecto.txt", "a");
  
  	fprintf(ptranscrip, "El minimo en %s del %i es %f y se dio en %s\n", mes, ano, min, tipo);
    
  	fclose(ptranscrip);
  
  	return min;
}

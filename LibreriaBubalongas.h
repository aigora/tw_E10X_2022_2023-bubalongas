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
float modatipo(generacion_2122 matriz[][NUM_COLUMNAS], int filas, int columnas, FILE *ptranscrip)
{ 
  int i, j;
  float moda = 0;
  
  for (i = 1; i < columnas; i++) 
  {
  	for (j = i + 1; j < columnas; j++) 
  	{
  		if (matriz[filas][i].magnitud == matriz[filas][j].magnitud)
  		{
  			printf("La moda es %f", matriz[filas][i].magnitud);
			
			moda = 1;	
		}
	}
  }
  
  if (!moda)
	{
        printf("\nNo hay moda.\n\n");
    }
  
  ptranscrip = fopen("TrancripcionProyecto.txt", "a");
  
  fprintf(ptranscrip, "No hay moda.\n");
    
  fclose(ptranscrip);

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
  
    fprintf(ptranscrip, "La ordenación de mayor a menor en %s es: \n", matriz[filas][0].tipo);
    
    for (i=0; i< k; i++)
		fprintf(ptranscrip, "%d) %f en %s-%i\n", i+1, v[i], fechas[i].mes, fechas[i].anyo);
    
    fprintf(ptranscrip, "\n\n");
	fclose(ptranscrip);
	
}

// 1.10 ORDENAR DE MENOR A MAYOR POR FILAS
void ordenar_min_max_filas(generacion_2122 matriz[][NUM_COLUMNAS], int filas, int columnas, FILE *ptranscrip)
{
	 
	int i,j,ano_mayor,k=24;
	float v[24], menor;
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

	for(j =0; j < k-1; j++)
	{
		for (i=0; i < k-1; i++)
		{
			if (v[i]> v[i+1])
			{
				menor = v[i];
				v[i] =v[i+1];
				v[i+1]=menor;
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
  
    fprintf(ptranscrip, "La ordenación de menor a mayor en %s es: \n", matriz[filas][0].tipo);
    
    for (i=0; i< k; i++)
		fprintf(ptranscrip, "%d) %f en %s-%i\n", i+1, v[i], fechas[i].mes, fechas[i].anyo);
    
    fprintf(ptranscrip, "\n\n");
    
	fclose(ptranscrip);

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

// 2.2 MODA POR COLUMNAS
float modacolumnas(generacion_2122 matriz[NUM_FILAS][NUM_COLUMNAS], int filas, int columnas, FILE *ptranscrip)
{ 
  int i, j;
  float moda = 0;
  
  for (i = 1; i < filas; i++) 
  {
  	for (j = i + 1; j < filas; j++) 
  	{
  		if (matriz[i][columnas].magnitud == matriz[j][columnas].magnitud)
  		{
  			printf("La moda es %f", matriz[i][columnas].magnitud);
			
			moda = 1;	
		}
	}
  }
  
  if (!moda)
	{
        printf("\nNo hay moda.\n\n");
    }
  
  ptranscrip = fopen("TrancripcionProyecto.txt", "a");
  
  fprintf(ptranscrip, "No hay moda.\n");
    
  fclose(ptranscrip);

  return moda;
}

// 2.3 MAXIMO POR COLUMNAS
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
  
  	printf("\nEl maximo en %s-%i es %f y se dio en %s\n\n", mes, ano, max, tipo);
  
  	ptranscrip = fopen("TrancripcionProyecto.txt", "a");
  
  	fprintf(ptranscrip, "El maximo en %s-%i es %f y se dio en %s\n", mes, ano, max, tipo);
    
  	fclose(ptranscrip);
  
  	return max;
}

// 2.4 MINIMO POR COLUMNAS
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
  
  	printf("\nEl minimo en %s-%i es %f y se dio en %s\n\n", mes, ano, min, tipo);
  
  	ptranscrip = fopen("TrancripcionProyecto.txt", "a");
  
  	fprintf(ptranscrip, "El minimo en %s-%i es %f y se dio en %s\n", mes, ano, min, tipo);
    
  	fclose(ptranscrip);
  
  	return min;
}


// 2.5 SUMATORIO POR COLUMNAS
float sumatoriocolumnas(generacion_2122 matriz[NUM_FILAS][NUM_COLUMNAS], int filas, int columnas, FILE *ptranscrip)
{
	int i;
    float sum = 0;
    
    for(i = 0; i < filas; i++)
    {
    	sum += matriz[i][columnas].magnitud;
	}
	
	printf("\nEl sumatorio de %s-%i es %f\n\n", matriz[0][columnas].fecha.mes, matriz[0][columnas].fecha.anyo, sum);	
	
  	ptranscrip = fopen("TrancripcionProyecto.txt", "a"); 
  
  	fprintf(ptranscrip, "El sumatorio de %s-%i es %f\n", matriz[0][columnas].fecha.mes, matriz[0][columnas].fecha.anyo, sum);
    
  	fclose(ptranscrip);
  	
  	return sum;
}


// 2.6 MEDIANA POR COLUMNAS
float medianacolumnas(generacion_2122 matriz[NUM_FILAS][NUM_COLUMNAS], int filas, int columnas, FILE *ptranscrip) 
{
	int i;
	float mediana = 0;
	
	mediana = (matriz[9][columnas].magnitud);
	
	printf("\nLa mediana en %s-%i es %f\n\n", matriz[0][columnas].fecha.mes, matriz[0][columnas].fecha.anyo, mediana);
	
	ptranscrip = fopen("TrancripcionProyecto.txt", "a");
  
    fprintf(ptranscrip, "La mediana en %s-%i es %f\n", matriz[0][columnas].fecha.mes, matriz[0][columnas].fecha.anyo, mediana);
    
	fclose(ptranscrip);	
	
	return mediana;
}

// 2.7 VARIANZA POR COLUMNAS
float varianzacolumnas(generacion_2122 matriz[NUM_FILAS][NUM_COLUMNAS], int filas, int columnas, FILE *ptranscrip) 
{
	int i, ano=0;
    float media = 0, suma = 0, varianza = 0, varianza_numerador = 0;
    char mes[10];
    
    ano=matriz[0][columnas].fecha.anyo;
  	strcpy(mes, matriz[0][columnas].fecha.mes);
    
    for(i = 0; i < filas; i++)
    {
    	suma += matriz[i][columnas].magnitud;
	}
	
	media = suma / filas;
	
	for(i = 0; i < filas; i++)
    {
    	varianza_numerador += pow(matriz[i][columnas].magnitud - media, 2);
	}
	
	varianza = varianza_numerador / filas;
	
	printf("\nLa varianza en %s-%i es %f\n\n", mes, ano, varianza);
	
	ptranscrip = fopen("TrancripcionProyecto.txt", "a");
  
    fprintf(ptranscrip, "\nLa varianza en %s-%i es %f\n\n", mes, ano, varianza);
    
	fclose(ptranscrip);	
	
	return varianza;
}

// 2.8 DESVIACIÓN TÍPICA POR COLUMNAS
float destipicacolumnas(generacion_2122 matriz[NUM_FILAS][NUM_COLUMNAS], int filas, int columnas, FILE *ptranscrip) 
{
	int i, ano=0;
    float media = 0, suma = 0, varianza = 0, varianza_numerador = 0, desviaciontipica = 0;
    char mes[10];
    
    ano=matriz[0][columnas].fecha.anyo;
  	strcpy(mes, matriz[0][columnas].fecha.mes);
    
    for(i = 0; i < filas; i++)
    {
    	suma += matriz[i][columnas].magnitud;
	}
	
	media = suma / filas;
	
	for(i = 0; i < filas; i++)
    {
    	varianza_numerador += pow(matriz[i][columnas].magnitud - media, 2);
	}
	
	varianza = varianza_numerador / filas;
	
	desviaciontipica = sqrt(varianza);
	
	printf("\nLa desviacion tipica en %s-%i es %f\n\n", mes, ano, desviaciontipica);
	
	ptranscrip = fopen("TrancripcionProyecto.txt", "a");
  
    fprintf(ptranscrip, "La desviacion tipica en en %s-%i es %f\n\n", mes, ano, desviaciontipica);
    
	fclose(ptranscrip);	
	
	return desviaciontipica;
}

// 2.9 ORDENAR DE MÁXIMO A MÍNIMO POR COLUMNAS
void ordenar_max_min_columnas(generacion_2122 matriz[NUM_FILAS][NUM_COLUMNAS], int filas, int columnas, FILE *ptranscrip)
{
	int i,j,k=17;
	float v[17], mayor;
	char cadenaaux[50];
	generacion_2122 tipos[50];
	
	for (i=0; i < k; i++)
	{
		v[i]=matriz[i][columnas].magnitud;
	}

	
	for (i=0; i < k; i++)
	{
		strcpy(tipos[i].tipo, matriz[i][0].tipo);
	}
	

	for(j =0; j < k-1; j++)
	{
		for (i=0; i < k-1; i++)
		{
			if (v[i]< v[i+1])
			{
				mayor = v[i];
				v[i] =v[i+1];
				v[i+1]=mayor;
				strcpy(cadenaaux, tipos[i].tipo);
				strcpy(tipos[i].tipo, tipos[i+1].tipo);
				strcpy(tipos[i+1].tipo, cadenaaux);
			}
		}
	}
	
	
	for (i=0; i< k; i++)
		printf ("%d) %f en %s\n", i+1, v[i], tipos[i].tipo);
	printf("\n\n");
	
	ptranscrip = fopen("TrancripcionProyecto.txt", "a");
	
	fprintf(ptranscrip, "La ordenación de menor a mayor en %s-%i es: \n", matriz[0][columnas].fecha.mes, matriz[0][columnas].fecha.anyo);
  
    for (i=0; i< k; i++)
		fprintf(ptranscrip, "%d) %f en %s\n", i+1, v[i], tipos[i].tipo);
		
	fprintf(ptranscrip, "\n\n");
    
	fclose(ptranscrip);
}

// 2.10 ORDENAR DE MENOR A MAYOR POR COLUMNAS
void ordenar_min_max_columnas(generacion_2122 matriz[NUM_FILAS][NUM_COLUMNAS], int filas, int columnas, FILE *ptranscrip)
{
	int i,j,k=17;
	float v[17], menor;
	char cadenaaux[50];
	generacion_2122 tipos[50];
	
	for (i=0; i < k; i++)
	{
		v[i]=matriz[i][columnas].magnitud;
	}

	
	for (i=0; i < k; i++)
	{
		strcpy(tipos[i].tipo, matriz[i][0].tipo);
	}
	

	for(j =0; j < k-1; j++)
	{
		for (i=0; i < k-1; i++)
		{
			if (v[i]> v[i+1])
			{
				menor = v[i];
				v[i] =v[i+1];
				v[i+1]=menor;
				strcpy(cadenaaux, tipos[i].tipo);
				strcpy(tipos[i].tipo, tipos[i+1].tipo);
				strcpy(tipos[i+1].tipo, cadenaaux);
			}
		}
	}
	
	
	for (i=0; i< k; i++)
		printf ("%d) %f en %s\n", i+1, v[i], tipos[i].tipo);
	printf("\n\n");
	
	ptranscrip = fopen("TrancripcionProyecto.txt", "a");
	
	fprintf(ptranscrip, "La ordenación de menor a mayor en %s-%i es: \n", matriz[0][columnas].fecha.mes, matriz[0][columnas].fecha.anyo);
  
    for (i=0; i< k; i++)
		fprintf(ptranscrip, "%d) %f en %s\n", i+1, v[i], tipos[i].tipo);
		
	fprintf(ptranscrip, "\n\n");
    
	fclose(ptranscrip);

}

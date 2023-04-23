#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char mes[10];
	int anyo; 
}date;

typedef struct{
	char tipo[50];
	float magnitud;
	date fecha; 
}generacion_2122;



int main()
{
  generacion_2122 generacion[18][24];
  int nLineas, i=0, j, k,l;
  char x, strFechas[24][10], titulo[80];
  FILE *pf;
  pf = fopen("C:/Users/hecto/Downloads/ProyectoInforREE.csv", "r");
  
  if (pf == NULL)
  {
  	printf("No se pudo abrir el archivo.\n");
  	return 1;
  }
  
  	while (fscanf(pf, "%c", &x) != EOF)
	{
		if (x == '\n') 
	       ++nLineas;
	    if (nLineas==4)
	      break;
	}
//	printf("El documento tiene %i lineas", nLineas);
		
	while (i<6)
	{
		fscanf(pf, "%c", &x);
		i++;
	}
	i=0;
	while (i<24)
	{
		
		fscanf(pf, "%[^-]-%[^;];", generacion[0][i].fecha.mes, strFechas[i]);
		i++;
	}

	for(i=0; strFechas[23][i] != '\n'; i++);
	
	strFechas[23][i]='\0';
	
//	for(i=0; i<24; i++)
//	{
//		printf("Fecha %i: %s %s ", i+1, generacion[0][i].fecha.mes, strFechas[i]);
//	}
	for(i=0; i<24; i++)
	{
		for(j=0; j<18; j++)
		{
			strcpy(generacion[j][i].fecha.mes, generacion[0][i].fecha.mes);
		}
	}
	
	for(i=0; i<24; i++)
	{
		for(j=0; j<18; j++)
		{
			generacion[j][i].fecha.anyo = atoi(strFechas[i]);
		}
	}
	
	for(i=0; i<24; i++)
	{
		printf("Fecha %i: %s %i ", i+1, generacion[4][i].fecha.mes, generacion[4][i].fecha.anyo);
	}
	
	fclose(pf);
  
  
  return 0;
 }

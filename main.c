#include <stdio.h>
#include <string.h>
#include <locale.h>

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
  char x, titulo[80];
  
  setlocale(LC_CTYPE,"spanish");
  setlocale(LC_NUMERIC, "spanish");
  
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
	fscanf(pf, "%[^-]-%i;", generacion[0][i].fecha.mes, &generacion[0][i].fecha.anyo);
	i++;
  }

  for(i=0; i<24; i++)
  {
	for(j=0; j<18; j++)
	{
		strcpy(generacion[j][i].fecha.mes, generacion[0][i].fecha.mes); //Podemos crear nosotros una funcion que haga lo mismo sin tener que usar la libreria string.h
	}
  }
	
  for(i=0; i<24; i++)
  {
	for(j=0; j<18; j++)
	{
		generacion[j][i].fecha.anyo = generacion[0][i].fecha.anyo;
	}
  }
	
//  for(i=0; i<24; i++)
//  {
//	printf("Fecha %i: %s %i ", i+1, generacion[4][i].fecha.mes, generacion[4][i].fecha.anyo);
//  }
//	

  fscanf(pf, "%c", &x);
  printf("%c", x);

  i=0;
  
  while (i<18)
  {
	fscanf(pf, "%[^;]", generacion[i][0].tipo);
//	printf("%s\n", generacion[i][0].tipo);
	for(j=0; j<24; j++)
	{
		fscanf(pf, ";%f", &generacion[i][j].magnitud);
//		printf("%f  ", generacion[i][j].magnitud);
	}	
//	printf("\n");
	fscanf(pf, "%c", &x);
	i++;
  }
  for(i=0; i<18; i++)
  {
	for(j=0; j<24; j++)
	{
		strcpy(generacion[i][j].tipo, generacion[i][0].tipo); //Podemos crear nosotros una funcion que haga lo mismo sin tener que usar la libreria string.h
	}
  }
  
//  printf("Tipo %s %f ", generacion[0][0].tipo, generacion[0][0].magnitud);
  for(i=0; i<18; i++)
  {
	printf("Tipo %s: ", generacion[i][0].tipo);
	for(j=0; j<24; j++)
	{
		printf("%f ", generacion[i][j].magnitud);
	}
  printf("\n");
  }
	
  fclose(pf);
  
  
  return 0;
 }

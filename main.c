#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "LibreriaBubalongas.h"

#define NUM_FILAS 18
#define NUM_COLUMNAS 24



//FUNCIONES
void operacionesfilas();
void operacionescolumnas();

int main()
{
  generacion_2122 generacion[NUM_FILAS][NUM_COLUMNAS];
  int nLineas, i=0, j, k,l;
  char x, titulo[80];
  int op, num, ano, mes, mes2;
  
  setlocale(LC_CTYPE,"spanish");
  setlocale(LC_NUMERIC, "spanish");
  
  FILE *pf, *ptranscrip;
  pf = fopen("ProyectoInforREE.csv", "r");
  
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
//  printf("%c", x);

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

//  printf("Tipo %s %i \n", generacion[0][0].fecha.mes, generacion[0][0].fecha.anyo);

//  for(i=0; i<18; i++)
//  {
//	printf("Tipo %s: ", generacion[i][0].tipo);
//	for(j=0; j<24; j++)
//	{
//		printf("%f ", generacion[i][j].magnitud);
//	}
//  printf("\n");
//  }


	
  fclose(pf);
  
  ptranscrip = fopen("TrancripcionProyecto.txt", "w");
  
  fprintf(ptranscrip, "Esta es la transcripción del programa:\n");
  
  fclose(ptranscrip);
  
  do{
	system("cls");
  printf("ESTE PROGRAMA TIENE LA FUNCIÓN DE REALIZAR UN AMPLIO ESTUDIO ESTÁDISTICO CON RESPECTO \nA LOS VALORES RECOGIDOS POR LA RED ELÉCTRICA ESPAÑOLA ENTRE EL AÑO 2021 Y 2022. \n");
  printf("Para comenzar con el estudio, por favor escoja entre las siguientes opciones:\n");
  printf("1. Tipo de generación eléctrica.\n");
  printf("2. Fecha de generación.\n");
  printf("3. Salir.\n");
  scanf("%d", &op);
  system("cls");
  
  switch(op){
  	
	case 1:
	do{
  		printf("¿Qué tipo de generación desea estudiar?\n");
  		printf("1. Hidráulica\n");
  		printf("2. Turbinación bombeo\n");
  		printf("3. Nuclear\n");
  		printf("4. Carbón\n");
  		printf("5. Fuel+Gas\n");
  		printf("6. Motores Diesel\n");
  		printf("7. Turbnina de gas\n");
  		printf("8. Turbina de vapor\n");
  		printf("9. Ciclo combinado\n");
  		printf("10. Hidroeólica\n");
  		printf("11. Eólica\n");
  		printf("12. Solar fotovoltaica\n");
  		printf("13. Solar térmica\n");
  		printf("14. Otras renovables\n");
  		printf("15. Cogeneración\n");
  		printf("16. Residuos no renovables\n");
  		printf("17. Residuos renovables\n");
  		printf("18. VOLVER ATRÁS\n");
  		scanf("%d", &num);
  		
  		switch(num)
		  	{
  			case 1:
  				operacionesfilas(generacion, 0);
  				break;
  			case 2:
  				operacionesfilas(generacion, 1);
  				break;
  			case 3:
  				operacionesfilas(generacion, 2);
  				break;
  			case 4:
  				operacionesfilas(generacion, 3);
  				break;
  			case 5:
  				operacionesfilas(generacion, 4);
  				break;
  			case 6:
  				operacionesfilas(generacion, 5);
  				break;
  			case 7:
  				operacionesfilas(generacion, 6);
  				break;
  			case 8:
  				operacionesfilas(generacion, 7);
  				break;
  			case 9:
  				operacionesfilas(generacion, 8);
  				break;
  			case 10:
  				operacionesfilas(generacion, 9);
  				break;
  			case 11:
  				operacionesfilas(generacion, 10);
  				break;
  			case 12:
  				operacionesfilas(generacion, 11);
  				break;
  			case 13:
  				operacionesfilas(generacion, 12);
  				break;
  			case 14:
  				operacionesfilas(generacion, 13);
  				break;
  			case 15:
  				operacionesfilas(generacion, 14);
  				break;
  			case 16:
  				operacionesfilas(generacion, 15);
  				break;
  			case 17:
  				operacionesfilas(generacion, 16);
  				break;
  			case 18:
  				break;
  			default:
  				system("cls");
            	printf("Opción no válida. Por favor seleccione una opción válida.\n");
            	break;
  			}
	}while(num!=18);
  		
  	break;
  
  	case 2:
  	do{
	  
  		printf("Escoja el año que quiera estudiar:\n");
  		printf("1. 2021\n");
  		printf("2. 2022\n");
  		printf("3. VOLVER ATRÁS\n");
  		scanf("%d", &ano);
  		system("cls");
		  
		  switch(ano){
  			
			case 1:
				printf("Ahora escoja el mes en el que desea realizar el estudio\n");
				printf("1. Enero\n");
				printf("2. Febrero\n");
				printf("3. Marzo\n");
				printf("4. Abril\n");
				printf("5. Mayo\n");
				printf("6. Junio\n");
				printf("7. Julio\n");
				printf("8. Agosto\n");
				printf("9. Septiembre\n");
				printf("10. Octubre\n");
				printf("11. Noviembre\n");
				printf("12. Diciembre\n");
				scanf("%d", &mes);
				
				switch(mes){
		  			case 1:
		  				operacionescolumnas(generacion, 0);
		  				break;
		  			case 2:
		  				operacionescolumnas(generacion, 1);
		  				break;
		  			case 3:
		  				operacionescolumnas(generacion, 2);
		  				break;
		  			case 4:
		  				operacionescolumnas(generacion, 3);
		  				break;
		  			case 5:
		  				operacionescolumnas(generacion, 4);
		  				break;
		  			case 6:
		  				operacionescolumnas(generacion, 5);
		  				break;
		  			case 7:
		  				operacionescolumnas(generacion, 6);
		  				break;
		  			case 8:
		  				operacionescolumnas(generacion, 7);
		  				break;
		  			case 9:
		  				operacionescolumnas(generacion, 8);
		  				break;
		  			case 10:
		  				operacionescolumnas(generacion, 9);
		  				break;
		  			case 11:
		  				operacionescolumnas(generacion, 10);
		  				break;
		  			case 12:
		  				operacionescolumnas(generacion, 11);
		  				break;
		  			case 13:
		  				break;
		  			default:
		  				break;
					}
					
			break;
  			
			case 2:
				printf("Ahora escoja el mes en el que desea realizar el estudio\n");
				printf("1. Enero\n");
				printf("2. Febrero\n");
				printf("3. Marzo\n");
				printf("4. Abril\n");
				printf("5. Mayo\n");
				printf("6. Junio\n");
				printf("7. Julio\n");
				printf("8. Agosto\n");
				printf("9. Septiembre\n");
				printf("10. Octubre\n");
				printf("11. Noviembre\n");
				printf("12. Diciembre\n");
				scanf("%d", &mes2);
				
				switch(mes2){
		  			case 1:
		  				operacionescolumnas(generacion, 12);
		  				break;
		  			case 2:
		  				operacionescolumnas(generacion, 13);
		  				break;
		  			case 3:
		  				operacionescolumnas(generacion, 14);
		  				break;
		  			case 4:
		  				operacionescolumnas(generacion, 15);
		  				break;
		  			case 5:
		  				operacionescolumnas(generacion, 16);
		  				break;
		  			case 6:
		  				operacionescolumnas(generacion, 17);
		  				break;
		  			case 7:
		  				operacionescolumnas(generacion, 18);
		  				break;
		  			case 8:
		  				operacionescolumnas(generacion, 19);
		  				break;
		  			case 9:
		  				operacionescolumnas(generacion, 20);
		  				break;
		  			case 10:
		  				operacionescolumnas(generacion, 21);
		  				break;
		  			case 11:
		  				operacionescolumnas(generacion, 22);
		  				break;
		  			case 12:
		  				operacionescolumnas(generacion, 23);
		  				break;
		  			case 13:
		  				break;
		  			default:
		  				break;
					}
			case 3:
				break;
			default:
				system("cls");
            	printf("Opción no válida. Por favor seleccione una opción válida.\n");
            	break;
  	}
    }while(ano!=3);
  	break;
	default:
		system("cls");
        printf("Opción no válida. Por favor seleccione una opción válida.\n");
    	break;
        
	}
	
	}while(op!=3);
	
	printf("Fin del programa.\n");
	
	
	ptranscrip = fopen("TrancripcionProyecto.txt", "a");
  
    fprintf(ptranscrip, "\nFin del programa.\n");
  
    fclose(ptranscrip);
	
  return 0;
}

//FUNCION PARA ELEGIR ESTUDIO ESTADISTICO

void operacionesfilas(generacion_2122 generacion[][NUM_COLUMNAS], int tipo, FILE *ptranscrip)
{
	int op2;
	int columnas;
	system("cls");
  do{
	printf("¿Qué tipo de estudio estadístico desea hacer? \n");
	printf("1. Media\n");
	printf("2. Moda\n");
	printf("3. Hallar maximo\n");
	printf("4. Hallar minimo\n");
	printf("5. Sumatorio\n");
	printf("6. Mediana\n");
	printf("7. Varianza\n");
	printf("8. Desviación típica\n");
	printf("9. Ordenar de mayor a menor\n");
	printf("10. Ordenar de menor a mayor\n");
	printf("11. VOLVER ATRÁS\n");
	scanf("%i", &op2);
	
	switch(op2)
	{
		case 1:
			columnas=24;
			mediatipo(generacion, tipo, columnas, ptranscrip);
			break;
		case 2:
			columnas=24;
			modatipo(generacion, tipo, columnas);//Esta mal
			break;
		case 3:
			columnas=24;
			maxtipo(generacion, tipo, columnas, ptranscrip);
			break;
		case 4:
			columnas=24;
			mintipo(generacion, tipo, columnas, ptranscrip);
			break;
		case 5:
			columnas=24;
			sumtipo(generacion, tipo, columnas, ptranscrip);
			break;
		case 6:
			columnas=24;
			medianatipo(generacion, tipo, columnas, ptranscrip);
			break;
		case 7:
			columnas=24;
			varianzatipo(generacion, tipo, columnas, ptranscrip);
			break;
		case 8:
			columnas=24;
			destipicatipo(generacion, tipo, columnas, ptranscrip);
		case 9:
			columnas=24;
			ordenar_max_min_filas(generacion, tipo, columnas, ptranscrip);
			break;
		case 10:
			columnas=24;
			ordenar_min_max_filas(generacion, tipo, columnas, ptranscrip);
			break;
		case 11:
			system("cls");
			break;
		default:
			system("cls");
			printf("Opción no válida. Por favor seleccione una opción válida.\n");
			break;
	}	
  }while (op2!=11);
}



void operacionescolumnas(generacion_2122 generacion[][NUM_COLUMNAS], int fecha, FILE *ptranscrip)
{
	int op2;
	int filas;
	system("cls");
  do{
	printf("¿Qué tipo de estudio estadístico desea hacer? \n");
	printf("1. Media\n");
	printf("2. Moda\n");
	printf("3. Hallar maximo\n");
	printf("4. Hallar minimo\n");
	printf("5. Sumatorio\n");
	printf("6. Mediana\n");
	printf("7. Varianza\n");
	printf("8. Desviación típica\n");
	printf("9. Ordenar de mayor a menor\n");
	printf("10. Ordenar de menor a mayor\n");
	printf("11. VOLVER ATRÁS\n");
	scanf("%i", &op2);
	
	switch(op2)
	{
		case 1:
			filas=17;
			mediacolumna(generacion, filas, fecha, ptranscrip);
			break;
		case 2:
			break;
		case 3:
			filas=17;
			maxcolumnas(generacion, filas, fecha, ptranscrip);
			break;
		case 4:
			filas=17;
			mincolumnas(generacion, filas, fecha, ptranscrip);
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			system("cls");
			break;
		default:
			system("cls");
			printf("Opción no válida. Por favor seleccione una opción válida.\n");
			break;
	}	
  }while (op2!=11);
}



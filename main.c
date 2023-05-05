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
  
/*printf("Tipo %s %f ", generacion[0][0].tipo, generacion[0][0].magnitud);
  for(i=0; i<18; i++)
  {
	printf("Tipo %s: ", generacion[i][0].tipo);
	for(j=0; j<24; j++)
	{
		printf("%f ", generacion[i][j].magnitud);
	}
  printf("\n");
  }*/
	
  fclose(pf);
  
  int op, letra, ano;
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
  		printf("14. Otras reonvavbles\n");
  		printf("15. Cogeneración\n");
  		printf("16. Residuos no renovables\n");
  		printf("17. Residuos renovavles\n");
  		printf("18. VOLVER ATRÁS\n");
  		scanf("%d", &letra);
  		
  		switch(letra)
		  	{
  			case 1:
  				break;
  			case 2:
  				break;
  			case 3:
  				break;
  			case 4:
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
  				break;
  			case 12:
  				break;
  			case 13:
  				break;
  			case 14:
  				break;
  			case 15:
  				break;
  			case 16:
  				break;
  			case 17:
  				break;
  			case 18:
  				break;
  			default:
  				system("cls");
            	printf("Opción no válida. Por favor seleccione una opción válida.\n");
            	break;
  			}
	}while(letra!=18);
  		
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
				int mes;
				scanf("%d", &mes);
				
				switch(mes){
		  			case 1:
		  				break;
		  			case 2:
		  				break;
		  			case 3:
		  				break;
		  			case 4:
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
		  				break;
		  			case 12:
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
				int mes2;
				scanf("%d", &mes2);
				
				switch(mes2){
		  			case 1:
		  				break;
		  			case 2:
		  				break;
		  			case 3:
		  				break;
		  			case 4:
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
		  				break;
		  			case 12:
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

  return 0;
}



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUM_COD 5

typedef struct Descuentos{
	char cod[5];
	float desc;
}Descuentos;

typedef struct Recibo{
	char menu[13]; //Dos opciones : ADULTO o INFANTIL
	char principal[20]; // Elección tipo de Cachopo
	char carne[20]: // Elección tipo de carne
	char guarn[20]; // Elección de guarnición
	char extra[20[; // Elección de EXTRA de ingredientes
	char bebiida[20]; // Elección de bebida
	float preio; 
}Recibo;
	


char inicio( int a){
	if (a == 0)
		printf("¿ Que desea tomar?\n");
	else ( printf("¿Desea algo mas?\n"));
}

void intro();
int meninicio() {
	int opcion;

	printf("1-Escoger menu\n");
	printf("2-Mostrar lista pedidos\n");
	printf("3-Pagar\n");
	printf("4- Salir\n");
	scanf("%d", &opcion);
	system("cls");
	return opcion;
}

float codigoprom(Descuentosx[], int a);
float conttot(Recibo x[], int a);




void main() {
	int fin = 0, i=0, j=0;
	float total;
	struct Descuentos lista[NUM_COD] = {{ "A100",0.85 },
	{ "B200",0.90 },
	{ "C300",0.95 },
	{ "EMPL", 0.50 },
	{ "JEFE", 0.00 } };
	bool cont =true;
	
	while (cont) {

		total = 0;
		fin = 0;
		i = 0;
		intro();
		
		while(fin == 0){
	            inicio(i);
		

		switch (meninicio()) {
		case 1: printf(" Escoger Menu\n"); break;
		case 2: printf("Mostrar lista de pedidos\n"); break; 
		
		case 3: { //PAGAR
			total = conttot(ticket, i);

			total = total * codigoprom (lista, NUM_COD);
			printf("TOTAL : $%.2f\n", total);
			fin =1;
		}break;
		case 4: {
			printf("Esperamos volver a verle pronto. \n");
			fin = 1; 
			cont = false;
		}break;
		} //salir del switch-case
			
	}//Salir del while (fin ==0)
	system("pause");
     } // Salir del while(cont)
}//salir del main




float codigoprom(Descuentos x[], int a){
	int opcion, j, fin =0;
	float desc;
	char codigo[5];
	
	while (fin==0){
		printf("TIENE ALGUN CODIGO PROMOCIONAL QUE DESEE USAR?\n");
		printf("1-Si, quiero usar codigo promocional\n");
		printf("2-No, realizar el pago\n");
		scanf("%d", &opcion);
		
		getchar();
		intro();
		switch (opcion) {
		case 2: {
			desc = 1;
			fin = 1;
		}break;
		case 1: {
			printf("Introduzca su codigo\n");
			gets(codigo);
			/*printf("%s\n", codigo);
			printf("%s\n", x[0].cod);
			printf("%s\n", x[1].cod);
			printf("%s\n", x[2].cod);*/

			for (j = 0; j < a; j++) {
				if (strcmp(codigo, x[j].cod) == 0) {
					printf("Ese codigo tiene un %.0f porciento de descuento en el total de su compra\n", 100 - (100 * x[j].desc));
					desc = x[j].desc;
					fin++;;
					break;
				}
			}
			if (fin == 0) // Comprobacion de que ningún descuento coincide
				printf("Ese codigo no es valido\n");
		}break; 
		}
	}
	return desc;

}

float conttot(Recibo x[], int a){
	int j;
	float total=0;
	
	for (j = 0; j < a; j++) {
		total = total + x[j].precio;
	}
	printf("TOTAL: %.2f\n", total);
	return total;

	intro();
}


void intro(){
	system("cls");
	printf("Bienvenido a...\n");
	printf("                                                   _\n");
	printf("      _____   ____          _____   _____   _____ |/  ____\n");
	printf("|| / ||    | ||    ||    | ||    | ||    | ||    |   ||    \n");
	printf("||/_ ||____| ||    ||____| ||    | ||____| ||    |   ||____   \n");
	printf("||  |||    | ||    ||    | ||    | ||      ||    |        || \n");
	printf("||  |||    | ||___ ||    | ||____| ||      ||____|    ____|| (R)      \n");
	printf("\n");
}


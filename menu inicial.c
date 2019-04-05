#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

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
void main() {
	int fin = 0;
	do {
		printf("Bienvenido a Kachopos \n");

		switch (meninicio()) {
		case 1: printf(" Escoger Menu\n"); break;
		case 2: printf("Mostrar lista de pedidos\n"); break; 
		
		case 3: printf("Pagar\n"); break; 
		case 4: {
			printf("Esperamos volver a verle pronto. \n");
			fin = 1; }
		}
	} while (fin != 1);

}


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_COD 5

typedef struct Descuentos {
	char cod[5];
	float desc;
}Descuentos;
typedef struct Recibo {
	char menu[13];//adulto o niño
	char principal[20];//tipo de cachopo
	char carne[20];//tipo de carne
	char guarn[20];//guarnicion
	char extra[20];//Elige si desea extra de ingredientes, y al hacerlo 
	char bebida[20];//agua, cerveza o refresco
	float precio;
}Recibo;

char inicio(int a) {
	if (a == 0)
		printf("Que desea tomar?\n");
	else(printf("Desea algo mas?\n"));
}
void intro();
int meninicio() {
	int opcion;

	printf("1-Escoger menu\n");
	printf("2-Mostrar lista pedidos\n");
	printf("3-Pagar\n");
	printf("4- Salir del programa\n");
	scanf("%d", &opcion);
	system("cls");
	intro();
	return opcion;

}

void menu(Recibo *x);
void principal(Recibo *x);
void carne(Recibo *x);
void guarnicion(Recibo *x);
void extra(Recibo *x);
void bebida(Recibo *x);
void listacompra(Recibo x[], int a);
float codigoprom(Descuentos x[], int a);
float conttot(Recibo x[], int a);
void histoTicket(Recibo x[], int a, float b);


void main() {
	int i = 0, j = 0, fin;
	float total;
	struct Recibo ticket[100];
	struct Descuentos lista[NUM_COD] = { { "A100",0.85 },
	{ "B200",0.90 },
	{ "C300",0.95 },
	{ "EMPL", 0.50 },
	{ "JEFE", 0.00 } };
	system("color 1e");
	bool cont = true;


	while (cont) {

		total = 0;
		fin = 0;
		i = 0;
		intro();


		while (fin == 0) {
			inicio(i);

			switch (meninicio()) {
			case 1: {//Escoger menú
				menu(&ticket[i]);
				if (strcmp(ticket[i].menu, "Infantil") == 0) {
					strcpy(ticket[i].principal, "Cachopito");
					strcpy(ticket[i].carne, "Ternera");
					strcpy(ticket[i].guarn, "Patatas fritas");
					strcpy(ticket[i].extra, "Medio");
					strcpy(ticket[i].bebida, "Agua");
					ticket[i].precio = 6.00;
				}
				else {
					principal(&ticket[i]);
					if (strcmp(ticket[i].principal, "Vegano") != 0)
						carne(&ticket[i]);
					guarnicion(&ticket[i]);
					extra(&ticket[i]);
					bebida(&ticket[i]);
				}
				(i)++;


			}break;
			case 2: {//Mostrar lista pedidos
				listacompra(ticket, i);



			}break;
			case 3: {//Pagar
				total = conttot(ticket, i);

				total = total*codigoprom(lista, NUM_COD);
				histoTicket(ticket, i, total);
				printf("TOTAL: $ %.2f\n", total);
				fin = 1;

			}break;
			case 4: {
				fin = 1;
				cont = false;
			}break;
			}//switch

		}//while(1)
		system("pause");

	}
}//main


void menu(Recibo *x) {
	int opcion;
	printf("Escoja menu\n");
	printf("1-Adulto\n");
	printf("2-Infantil $6.00 (Cachopito(Clasico mini de ternera) con patatas fritas y agua mineral)\n");
	scanf("%d", &opcion);

	intro();
	switch (opcion) {
	case 1: {
		strcpy(x->menu, "Adulto");
	}break;
	case 2: {
		strcpy(x->menu, "Infantil");

	}break;
	}
	getchar();
}

void principal(Recibo *x) {
	int opcion;
	printf("Que cachopo va a tomar?\n");
	printf("1-Clasico $7.00 (Jamon serrano, queso y pimientos)\n");
	printf("2-Pijin $8.50 (Cebolla caramelizada, queso de cabra y foie)\n");
	printf("3-De la tierra $8.00 (Jamon iberico, champinones al ajillo y queso manchego)\n");
	printf("4-Tierra y mar $7.50 (Salmon ahumado, esparragos, boletus y queso)\n");
	printf("5-Vegano $7.00 (Carne de seitan, champinones, queso vegano y pimietos)\n");
	scanf("%d", &opcion);

	intro();
	switch (opcion) {
	case 1: {
		strcpy(x->principal, "Clasico");
		x->precio = 7;
	}break;
	case 2: {
		strcpy(x->principal, "Pijin");
		x->precio = 8.5;
	}break;
	case 3: {
		strcpy(x->principal, "De la tierra");
		x->precio = 8;
	}break;
	case 4: {
		strcpy(x->principal, "Tierra y mar");
		x->precio = 7.5;
	}break;
	case 5: {
		strcpy(x->principal, "Vegano");
		strcpy(x->carne, "Seitan");
		x->precio = 7.00;
	}break;
	}
	getchar();
}

void carne(Recibo *x) {
	int opcion;
	printf("Que carne desea tomar?\n");
	printf("1-Ternera\n");
	printf("2-Presa iberica (+$1.00)\n");
	printf("3-Pavo\n");
	scanf("%d", &opcion);

	intro();
	switch (opcion) {
	case 1: {
		strcpy(x->carne, "Ternera");
	}break;
	case 2: {
		strcpy(x->carne, "Presa iberica");
		x->precio++;
	}break;
	case 3: {
		strcpy(x->carne, "Pavo");
	}break;
	}
	getchar();
}

void guarnicion(Recibo *x) {
	int opcion;
	printf("Desea patatas fritas o ensalada con su cachopo?\n");
	printf("1-Patatas fritas\n");
	printf("2-Ensalada\n");
	scanf("%d", &opcion);

	intro();
	switch (opcion) {
	case 1: {
		strcpy(x->guarn, "Patatas fritas");
	}break;
	case 2: {
		strcpy(x->guarn, "Ensalada");
	}break;
	}
	getchar();
}

void extra(Recibo *x) {
	int opcion;
	printf("Desea cantidad extra de ingredientes? +$1.50\n");
	printf("1-Si\n");
	printf("2-No\n");
	scanf("%d", &opcion);

	intro();
	switch (opcion) {
	case 1: {
		strcpy(x->extra, "Extra");
		x->precio = x->precio + 1.5;
	}break;
	case 2: {
		strcpy(x->extra, "Normal");
	}break;
	}
	getchar();
}

void bebida(Recibo *x) {
	int opcion;
	printf("Escoja su bebida\n");
	printf("1-Agua\n");
	printf("2-Cerveza\n");
	printf("3-Refresco\n");
	scanf("%d", &opcion);

	intro();
	switch (opcion) {
	case 1: {
		strcpy(x->bebida, "Agua");
	}break;
	case 2: {
		strcpy(x->bebida, "Cerveza");
	}break;
	case 3: {strcpy(x->bebida, "Refresco");
	}break;
	}
	getchar();
}


void listacompra(Recibo x[], int a) {
	int j;
	float total;
	for (j = 0; j < a; j++) {
		printf("Menu ");
		printf("%s ", x[j].menu);
		printf("%s ", x[j].principal);
		printf("%s ", x[j].carne);
		printf("%s ", x[j].extra);
		printf("%s ", x[j].guarn);
		printf("%s\n", x[j].bebida);
	}
	total = conttot(x, a);
	system("pause");
	intro();
}
float codigoprom(Descuentos x[], int a) {
	int opcion, j, fin = 0;
	float desc;
	char codigo[5];

	while (fin == 0) {
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
			if (fin == 0)
				printf("Ese codigo no es valido\n");
		}break;
		}
	}
	return desc;

}

float conttot(Recibo x[], int a) {
	int j;
	float total = 0;
	for (j = 0; j < a; j++) {
		total = total + x[j].precio;
	}
	printf("TOTAL: %.2f\n", total);
	return total;

	intro();
}

void histoTicket(Recibo x[], int a, float b) {
	int i = 0;
	FILE *historial;
	historial = fopen("histoTicket.txt", "a");
	if (histoTicket == NULL) {
		printf("ERROR NO SE ABRE EL REGISTRO DE COMPRAS\n");
		return;
	}

	for (i = 0; i < a; i++) {
		fprintf(historial, "%s", "Menu");
		fprintf(historial, " %s ", x[i].menu);
		fprintf(historial, "%s ", x[i].principal);
		fprintf(historial, "%s ", x[i].carne);
		fprintf(historial, "%s ", x[i].guarn);
		fprintf(historial, "%s ", x[i].extra);
		fprintf(historial, "%s\n", x[i].bebida);
	}
	fprintf(historial, "TOTAL:%.2f\n", b);
	fprintf(historial, "\n");

	fclose(historial);
}

void intro() {
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

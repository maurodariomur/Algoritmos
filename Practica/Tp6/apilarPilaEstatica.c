#include "pilaEstatica.h"

//declaracion del prototipado
void permitirProceso();
void continuarProceso();
void moduloAbarcador();
void menu();
void mostrarInicializacion();
float ingresarNumeros();
void eliminarNumeros(tPila*);
void mostrarTope(tPila);
void mostrarPila(tPila);


int acceso;
float n;

//declaracion de la funcion principal
int main(){
	moduloAbarcador();
	return 0;
}

void moduloAbarcador(){
	permitirProceso();
	mostrarInicializacion();
	while(acceso==1){
		menu();
		continuarProceso();
	}
}

void permitirProceso(){
	printf("Desea Agregar Datos: 1-SI o 0-NO: ");
	scanf("%d",&acceso);
}

void mostrarInicializacion(){
	inicializarPila(pila);
}

void continuarProceso(){
	printf("Desea continuar agregando Datos: 1-SI o 0-NO: ");
	scanf("%d",&acceso);
}

void menu(){
	int eleccion;
	printf("\n\t\t***Seleccion de Opciones***\t\n");
	printf("\n\t||\t1.Agregar y Apilar Numeros\t\t||");
	printf("\n\t||\t2.Desapilar\t\t\t\t||");
	printf("\n\t||\t3.Mostrar Tope de la Pila\t\t||");
	printf("\n\t||\t4.Mostrar Pila\t\t\t\t||");
	printf("\n\t\t\t...Seleccionar: ");
	scanf("%d",&eleccion);
	system("cls");
	switch(eleccion){
		case 1:
			ingresarNumeros();
			break;
		case 2:
			eliminarNumeros(&pila);
			break;
		case 3:
			mostrarTope(pila);
			break;
		case 4:
			mostrarPila(pila);
			break;
		default:
			printf("\n\tNo existe esta opcion\n");
			break;
	}
}

float ingresarNumeros(){
	printf("Ingresar numero del Usuario: ");
	fflush(stdin);
	scanf("%f",&n);
	pushPila(n);
}

void eliminarNumeros(tPila * pPila){
	popPila(pPila);
}

void mostrarTope(tPila pila){
	mostrarTopePila(pila);
}

void mostrarPila(tPila pila){
	visualizarPila(pila);
}

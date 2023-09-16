/*
 En el puerto de la ciudad se apilan contenedores a medida que van llegando, hasta un máximo de 8. Cada 
contenedor tiene un número de identificación que se registra. Elaborar un programa que permita 
gestionar el ingreso y egreso de contenedores, teniendo en cuenta las funciones básicas necesarias para 
la implementación mediante vectores.

Obj:Elaborar un programa que permita gestionar el ingreso y egreso de contenedores, 
teniendo en cuenta las funciones básicas necesarias para la implementación mediante vectores.

Nombre: ControlContenedores;

Estrategia:	iniciarProceso();
			continuarProceso();
			inicializarPila();
			seleccionEnMenu();
			ingresarContenedor();
			apilarContenedores();
			desapilarContenedores();
			pilaVacia();
			mostrarPilaVacia();
			pilaLlena();
			mostrarPilaContenedor();
			topeContenedor();
			mostrarTopeContenedor();
*/


#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<locale.h>

//declaracion de constante
#define MAX 8

//declaracion de Dato Personalizado
typedef int tVector[MAX];

//declaracion de estructura
typedef struct{
	tVector contenedor;
	int tope;
}tContenedores;

//declaracion de prototipados
void iniciarProceso();
void continuarProceso();
void inicializarPila();
void seleccionEnMenu();
void ingresarContenedor();
void apilarContenedores(int);
void desapilarContenedores();
bool pilaVacia(tContenedores);
void mostrarPilaVacia();
bool pilaLlena(tContenedores);
void mostrarPilaContenedor();
int topeContenedor(tContenedores);
void mostrarTopeContenedor();

//declaracion de Variables
tContenedores contenedores;
int continuar;

//declaracion de Funcion Principal
int main(){
	setlocale(LC_ALL,"spanish");
	iniciarProceso();
	return 0;
}

//declaracion de procedimientos
void iniciarProceso(){
	continuarProceso();
	inicializarPila();
	while(continuar==1){
		seleccionEnMenu();
		continuarProceso();
	}
}

void continuarProceso(){
	printf("\n\tDesea Agregar Datos: 1-Si o 0-No ");
	scanf("%d",&continuar);
}

void inicializarPila(){
	contenedores.tope=-1;
	printf("\n\tPila Inicializada\n");
}

void seleccionEnMenu(){
	int eleccion;
	printf("\n\t\t***Seleccion de Opciones***\t\n");
	printf("\n\t||\t1.Agregar y Apilar \t\t\t||");
	printf("\n\t||\t2.Desapilar \t\t\t\t||");
	printf("\n\t||\t3.Pila Vacia o No\t\t\t||");
	printf("\n\t||\t4.Mostrar Lista de Contenedores\t\t||");
	printf("\n\t||\t5.Mostrar el Ultimo Elemento\t\t||");
	printf("\n\t\t\t...Seleccionar: ");
	scanf("%d",&eleccion);
	system("cls");
	switch(eleccion){
		case 1:
			ingresarContenedor();
			break;
		case 2:
			desapilarContenedores();
			break;
		case 3:
			mostrarPilaVacia();
			break;
		case 4:
			mostrarPilaContenedor(contenedores);
			break;
		case 5:
			mostrarTopeContenedor();
			break;
	}
}

bool pilaVacia(tContenedores pContenedores){
	return(pContenedores.tope==-1);
}

void mostrarPilaVacia(){
	if(pilaVacia(contenedores)){
		printf("\n\tLa pila esta vacia");
	}
	else{
		printf("\n\tLa pila no esta vacia");
	}
}

bool pilaLlena(tContenedores pContenedores){
	return(pContenedores.tope==MAX-1);
}

void ingresarContenedor(){
	int nroContenedor;
	printf("\n\tAgregar Contenedor: ");
	scanf("%d",&nroContenedor);
	apilarContenedores(nroContenedor);
}

void apilarContenedores(int pNroContenedor){
	if(!pilaLlena(contenedores)){
		contenedores.tope+=1;
		contenedores.contenedor[contenedores.tope]=pNroContenedor;
		printf("\n\tContenedor apilado");
	}
	else{
		printf("\n\tNo se puede apilar");
	}	
}

int topeContenedor(tContenedores pContenedores){
	return ( pContenedores.contenedor[pContenedores.tope]);
}

void  desapilarContenedores(){
	if(!pilaVacia(contenedores)){
		float EliminarC = topeContenedor(contenedores);
		contenedores.contenedor[contenedores.tope]=0;
		contenedores.tope=contenedores.tope-1;
		printf("\n\tSe Elimino un Contenedor");
	}
	else{
		printf("\nNo hay Contenedor para quitar\n");
	}
}

void mostrarPilaContenedor(){
	int i;
	for(i=0;i<MAX;i++){
			printf("\nEl contenedor Nro. %d es el %d",contenedores.contenedor[i],i+1);		
	}
}

void mostrarTopeContenedor(){
	printf("\nEl  contenedor Nro %d es el Tope",contenedores.contenedor[contenedores.tope]);
}

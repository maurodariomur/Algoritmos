/*
Escribir un TDA para cargar y mostrar los elementos de una pila estática de elementos de tipo cadena de 
caracteres. Luego desarrolle un programa para probar dicho TDA.
*/

//interfaz
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define MAX 12

typedef char tString[100];
typedef float tNumeros[MAX];

typedef struct{
	tNumeros numeros;
	int tope;
}tPila;

tPila pila;
void inicializarPila(tPila);
bool pilaVacia(tPila);
bool pilaLlena(tPila);
void pushPila(float);
void popPila();
float mostrarTopePila(tPila);
void visualizarPila();

//Implementacion

void inicializarPila(tPila pPila){
	pPila.tope=-1;
	printf("\n\tSe Inicializo Pila...\n");
}

bool pilaVacia(tPila pPila){
	pPila.tope==-1;
}

bool pilaLlena(tPila pPila){
	pPila.tope==MAX-1;
}

void pushPila(float pElemet){	
	if(!pilaLlena(pila)){
		pila.tope+=1;
		pila.numeros[pila.tope]=pElemet;
		printf("Elemento insertado!\n"); 		
	} else {
		printf("No hay lugar disponible!\n");
	}
}

void popPila(tPila * pPila){
	if(!pilaVacia(*pPila)) {
		float elimElement= mostrarTopePila(*pPila);
		pPila->numeros[pPila->tope]=0;
		pPila->tope=pPila->tope-1;
		printf("\nSe elimino el elemento\n"); 
	} else {
		printf("\nNo hay elementos para quitar!\n");
	}
}

float mostrarTopePila(tPila  pPila){
	return printf("El tope es %.2f\n",pPila.numeros[pPila.tope]);
}

void visualizarPila(){
	if( !pilaVacia(pila) ){
		int i;
		for(i=0;i<MAX;i++){
		printf("\n la pila %d es %.2f\n",i+1,pila.numeros[i+1]);
		}
	}else{
		printf("\nNo hay elementos para visualizar!\n");
	}
}

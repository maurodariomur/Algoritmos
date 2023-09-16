/*
. Escribir un programa que permita determinar si un número entero ingresado por teclado, existe en un 
vector. Para ello será necesario, disponer de lo siguiente:
a) Una función que permita cargar elementos en un vector de números enteros.
b) Una función que permita visualizar los elementos almacenados en el vector.
c) Una función que devuelva verdadero en el caso que el elemento a buscar exista en el vector, y falso 
en caso contrario
*/

#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 5

//declaracion de dato personalizado
typedef int tVector[MAX];

//declaracion de prototipado
void moduloAbarcador();
void ingresarNumerosInt();
void mostrarNumerosCargados();
int ingresarNumeroVerificar();
bool busquedaSecuencial(tVector,int);
void permitirProceso();
void continuarProceso();
bool determinarExistenciaNumero(tVector,int);

//declaracion de variables globales
tVector vectorNumeroEntero;
int i,numero,continuar;
bool result;

//declaracion de funcion principal
int main(){
	moduloAbarcador();
	return 0;
}

void permitirProceso(){
	printf("Desea Comprobar si el numero existe en el Vector: 1-SI o 0-NO: ");
	scanf("%d",&continuar);
}

void continuarProceso(){
	printf("Desea continuar con la comprobacion de numero En El Vector: 1-SI o 0-NO: ");
	scanf("%d",&continuar);
}

void moduloAbarcador(){
	int numero;
	ingresarNumerosInt();
	mostrarNumerosCargados();	
	permitirProceso();
	while(continuar){
	numero=ingresarNumeroVerificar();	
	busquedaSecuencial(vectorNumeroEntero,numero);
	determinarExistenciaNumero(vectorNumeroEntero,numero);
	continuarProceso();	
	}
	
}

void ingresarNumerosInt(){
	for(i=0;i<MAX;i++){
		printf("Ingrese un Numero Entero: ");
		scanf("%d",&vectorNumeroEntero[i]);
	}
}

void mostrarNumerosCargados(){
	printf("\n\tLos Valores del Vector: \n");
	for(i=0; i<MAX;i++){
		printf("\t\t\t\t|%d|\n",vectorNumeroEntero[i]);
	}
	printf("\n");
}


int ingresarNumeroVerificar(){
	int numero=0;
	printf("Numero a comprobar: ");
	scanf("%d",&numero);
	return numero;
}

bool busquedaSecuencial(tVector pVectorNumeroEntero,int pNumero){
	result = false;
	i = 0;
	while((pVectorNumeroEntero[i]<pNumero)&&(i<= MAX)){
		i++;	
	}
	if(pVectorNumeroEntero[i]==pNumero){
		result = true;	
	}
	return result;
}
	

bool determinarExistenciaNumero(tVector pVectorNumeroEntero,int pNumero){	
		printf("Existe el %d ? %s\n\n", pNumero, busquedaSecuencial(pVectorNumeroEntero,pNumero)? "si": "no" );		
}


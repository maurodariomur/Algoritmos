/*
 En un gimnasio se apilan discos con pesos diferentes en forma desordenada. Los pesos de los discos varían 
de 10 a 100 Kg., con un máximo de 12 discos en la pila. Se pide diseñar un programa que disponga de un 
menú para invocar las funciones que permitan: 
cargar la pila con los pesos de los discos 
listar los pesos de los discos apilados a medida que cada gimnasta quita un disco, este debe ser eliminado de la pila
detectar cuál es el disco que se encuentra en el tope
 mostrar la cantidad de discos apilados
calcular el promedio de pesos de los discos que tiene la pila
*/

#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<locale.h>
#include<stdlib.h>

//declaracion de constante
#define DISCOS 12

//declaracion de Dato Perzonalizado
typedef float tVector[DISCOS];


//declaracion de estructura
typedef struct{
	tVector discosKg;
	int tope;
} tPilaGym;

//Declaracion del Prototipado
void iniciarProceso();
void continuarProceso();
void seleccionEnMenu();
void inicializarPila();
bool pilaVacia( tPilaGym );
bool pilaLlena( tPilaGym );
void ingresarPesoDisco();
void apilarDiscos( float );
void desapilarDiscos();
float elementoTope( tPilaGym );
void mostrarPila(tPilaGym);
void ultimoDiscoInsertado();
void mostrarPilaVacia();
void acumPesosPila();
float calcularPromedio(float);
void mostrarPromedio();
void contadorDiscos();

//Declaracion de las variables
tPilaGym pilaDiscos;
int elemento,i,contandoDiscos;
char continuar;
float discos,totalDiscos,promedio;
//Declaracion de la funcion Principal
int main(){
	setlocale(LC_ALL,"spanish");
	iniciarProceso();
	return 0;
}

void iniciarProceso(){
	continuarProceso();
	inicializarPila();
	while(continuar=='s' || continuar=='S'){
		seleccionEnMenu();
		continuarProceso();
	}
}

void continuarProceso(){
	printf("\n\tDesea ingresar Datos: S-N: ");
	fflush(stdin);
	scanf("%c",&continuar);
}

void inicializarPila(){
	pilaDiscos.tope=-1;
	printf("\n\tPila Inicializada\n");
}

void seleccionEnMenu(){
	printf("\n\t||1.Ingresar Peso y Apilar\t||");
	printf("\n\t||2.Mostrar Pila Vacia\t\t||");
	printf("\n\t||3.Desapilar Discos\t\t||");
	printf("\n\t||4.Mostrar Elemento Tope\t||");
	printf("\n\t||5.Mostrar Pila de Discos\t||");
	printf("\n\t||5.Mostrar Promedio de Pila\t||");	
	printf("\n\t\tSeleccione la Opcion: ");
	scanf("%d",&elemento);
	system("cls");
	switch(elemento){
		
		case 1:
			ingresarPesoDisco();
			break;
		case 2:
			mostrarPilaVacia();
			break;
		case 3:
			desapilarDiscos();
			break;
		case 4:
			ultimoDiscoInsertado();
			break;
		case 5:
			mostrarPila(pilaDiscos);
			break;
		case 6:
			mostrarPromedio();
			break;	
	}
}

void ingresarPesoDisco(){
	printf("Seleccione el peso a apilar: ");
	scanf("%f",&discos);
	apilarDiscos(discos);
}

void apilarDiscos(float pDiscos){
	if(!pilaLlena(pilaDiscos)){
		contandoDiscos+=1;
		totalDiscos+=discos;
		pilaDiscos.tope+=1;
		pilaDiscos.discosKg[pilaDiscos.tope]=pDiscos;
		printf("\n\tDisco Apilado\n");
	}
	else {
		printf("\nNo hay lugar disponible\n");
}
}

void desapilarDiscos(){
	int discoPorEliminar;
	if(!pilaVacia(pilaDiscos)){
		discoPorEliminar = elementoTope(pilaDiscos);
		pilaDiscos.discosKg[pilaDiscos.tope]=0;
		pilaDiscos.tope=pilaDiscos.tope-1;
		contandoDiscos-=1;
		totalDiscos-=discos;
		printf("\n\tSe Elimino un Discos");
	}
	else{
		printf("\nNo hay discos para quitar\n");
	}
}

bool pilaVacia(tPilaGym pPilaDiscos){
	return(pPilaDiscos.tope==-1);
}

bool pilaLlena(tPilaGym pPilaDiscos){
	return(pPilaDiscos.tope==DISCOS-1);
}

float elementoTope(tPilaGym pPilaDiscos){
	return(pPilaDiscos.discosKg[pPilaDiscos.tope]);
}

void mostrarPila(tPilaGym pPilaDiscos){
	if(!pilaVacia(pPilaDiscos)){
		for(i=0;i<=pPilaDiscos.tope;i++){
			printf("\nNumero del Disco %d |%.2f|\n",i+1,pPilaDiscos.discosKg[i]);
		}
	}
}

void ultimoDiscoInsertado(){
	printf("\n\tEl disco tope es %.2f",elementoTope(pilaDiscos));
}

void mostrarPilaVacia(){
	if(pilaVacia(pilaDiscos)){
		printf("\n\tLa Pila se encuentra Vacia\n");
	}
	else{
		printf("\n\tLa Pila no esta Vacia\n");	
	}
}

float calcularPromedio(float pTotalDiscos){
	return (pTotalDiscos/contandoDiscos);
}

void mostrarPromedio(){
	printf("\nLa cantidad de discos es %d",contandoDiscos);
	printf("\nEl promedio de la pila es %.2f",totalDiscos);
	printf("\nEl promedio de la pila es %.2f",calcularPromedio(totalDiscos));
}

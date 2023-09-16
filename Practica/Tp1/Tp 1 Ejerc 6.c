/*
En el estacionamiento de un shopping, existe solo un carril en el que entran hasta 20 automóviles. Los 
vehículos llegan por el extremo sur del estacionamiento y salen por el extremo norte del mismo. El
empleado de la cochera registra las matrículas que están en el carril. Se solicita escribir un programa que 
permita al usuario ingresar las matrículas de los automóviles en una cola hasta que la misma se llene o el 
usuario haya decidido no ingresar más elementos (vehículos). Además, se pide generar un listado de todos 
los automóviles que están en el carril y se desea saber cuánta disponibilidad hay en ese carril. Utilizar 
implementación con frente fijo.
*/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

//declaracion de constante
#define AUTO 20

//declaracion de Dato Perzonalizado
typedef int tVector[AUTO];

//declaracion de estructura
typedef struct{
	tVector automoviles;
	int frente;
	int final;
}tEstacionamiento;

//declaracion del Prototipado
void iniciarProceso();
void continuarProceso();
void inicializarCola();
void seleccionEnMenu();
bool colaVacia(tEstacionamiento);
bool colaLlena(tEstacionamiento);
void ingresarAutomoviles();
void aumentoDeAutomovilesCarril(int);
int contadorAutos(int);
void eliminarAutomovilCarril();
void mostrarPrimerAutomovil(tEstacionamiento);
void mostrarListaAutomoviles(tEstacionamiento);

//declaracion de variables
tEstacionamiento cocheras;
int continuar,contAuto;

//declaracion de Funcion Principal
int main(){
	setlocale(LC_ALL,"spanish");
	iniciarProceso();
	return 0;
}

//declaracion de Procedimientos
void iniciarProceso(){
	continuarProceso();
	inicializarCola();
	while(continuar==1){
		seleccionEnMenu();
		continuarProceso();
	}
}

void continuarProceso(){
	printf("\n\tDesea Agregar Datos: 1-Si o 0-No: ");
	scanf("%d",&continuar);
}

void inicializarCola(){
	cocheras.frente=-1;
	cocheras.final=-1;
	printf("\n\tSe inicializo cola\n");
}

void seleccionEnMenu(){
	int eleccion;
	printf("\n\t\tSELECCIÓN DE OPCIONES\n");
	printf("\n\t||1.Agregar Automoviles a la Cola\t\t||");
	printf("\n\t||2.Eliminar a Automovil de la Cola\t\t||");
	printf("\n\t||3.Mostrar Lista de Automoviles\t\t||");
	printf("\n\t||4.Mostrar a el Primer Automovil\t\t||");
	printf("\n\t\t\tSelecciona: ");
	scanf("%d",&eleccion);
	system("cls");
	
	switch(eleccion){
		case 1:
			ingresarAutomoviles();
			break;
		case 2:
			eliminarAutomovilCarril();
			break;
		case 3:
			mostrarListaAutomoviles(cocheras);
			break;
		case 4:
			mostrarPrimerAutomovil(cocheras);
			break;
	}
}

bool colaVacia(tEstacionamiento pCocheras){
	
	return(pCocheras.frente==-1 && pCocheras.final==-1);

}

bool colaLlena(tEstacionamiento pCocheras){
	
	return(pCocheras.final== (AUTO-1));
	
}

void ingresarAutomoviles(){
	int carro;
	printf("\n\tIngresar Matricula Automovil: ");
	scanf("%d",&carro);
	aumentoDeAutomovilesCarril(carro);
}

void aumentoDeAutomovilesCarril(int pCarro){
	if(colaLlena(cocheras)){
		printf("No hay lugares disponibles");
	}
	else{
		contAuto+=1;
		cocheras.final+=1;
		cocheras.automoviles[cocheras.final]=pCarro;
		if(cocheras.final==0){
			cocheras.frente=0;
		}
		printf("\n\tDisponible para Auto %d",pCarro);
		printf("\n\tHay Disponible %d espacios",contadorAutos(contAuto));
	}
}

int contadorAutos(int pContAuto){
	return (AUTO-pContAuto);
}

void eliminarAutomovilCarril(){
	int elimAuto;
	int i;
	if(colaVacia(cocheras)){
		printf("\n\tNo hay elementos para eliminar");
	}
	else{
		contAuto-=1;
		elimAuto=cocheras.automoviles[cocheras.frente];
		cocheras.automoviles[cocheras.frente]=0;
	
		for(i=cocheras.frente;i<=cocheras.final-1;i++){
			cocheras.automoviles[i]= cocheras.automoviles[i+1];
		}
		
		cocheras.automoviles[cocheras.final]=0;
		
		if(cocheras.frente==cocheras.final){
			inicializarCola();
		}
		else{
			cocheras.final=cocheras.final-1;
		}
		
		printf("\n\tElemento eliminado: %d",elimAuto);
	}
}

void mostrarListaAutomoviles(tEstacionamiento pCocheras){
	int i;
	if( colaVacia(pCocheras) ) {
		printf("No hay Autos para visualizar\n");
	} else {
		printf("Autos: \n");
		for(i= pCocheras.frente; i<= pCocheras.final; i++ ) {
			printf("%d | ", pCocheras.automoviles[i]);
		}
		printf("\n");
	}
}

void mostrarPrimerAutomovil(tEstacionamiento pCocheras){
	printf("Primer Automovil: %d\n", pCocheras.automoviles[pCocheras.frente]);
}

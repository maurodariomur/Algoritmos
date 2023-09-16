/*
En un depósito se ubican las cajas de televisores LED en pilas de hasta 20 como máximo, no se puede
apilar una caja grande sobre otra más chica. Escribir un programa que permita:
Ingresar y almacenar el dato referido a las pulgadas de los distintos televisores, según se van apilando. 
Obtener un listado de todos los televisores apilados
Una consulta que a partir del ingreso de un valor x de pulgadas retorne la cantidad de televisores con
más de x pulgadas que se encuentran apilados
Conforme se vayan retirando las cajas, detectar las pulgadas del televisor que queda en el tope.
*/

#include<stdio.h>
#include<stdbool.h>
#include<locale.h>
#include<stdlib.h>

//declaracion de la  constante
#define TV 20

//declaracion de Dato Perzonalizado
typedef float tVector[TV];

//declaracion de la Estructura
typedef struct{
	tVector tvLed;
	int tope;
}tDTv;

//declaracion del propotipado
void iniciarProceso();
void continuarProceso();
void seleccionEnMenu();
void inicializarPila();
void agregarTelevisores();
void apilarTelevisores(float);
bool sinTelevisores(tDTv);
bool tvLlenos(tDTv);
void desapilarTelevisores();
float topeTelevisores(tDTv);
void mostrarListaTv();
void mostrarTopeTv();

//declaracion de variables
tDTv televisoresLed;
int continuar;
float pulgadas;

//declaracion de la Funcion Principal
int main(){
	setlocale(LC_ALL,"spanish");
	iniciarProceso();
	return 0;
}

//declaracion de los procedimientos
void iniciarProceso(){
	continuarProceso();
	inicializarPila();
	while(continuar==1){
		seleccionEnMenu();
		continuarProceso();
	}
}

void continuarProceso(){
	printf("\n\tDesea Ingresar Datos: ");
	scanf("%d",&continuar);
}

void inicializarPila(){
	televisoresLed.tope=-1;
	printf("\n\tPila Inicializada\n");
}

void seleccionEnMenu(){
	int eleccion;
	printf("\n\t\t***Seleccion de Opciones***\t\n");
	printf("\n\t||\t1.Agregar y Apilar TV\t\t\t\t||");
	printf("\n\t||\t2.Desapilar TV\t\t\t\t\t||");
	printf("\n\t||\t3.Pila Vacia o No\t\t\t\t||");
	printf("\n\t||\t4.Mostrar Lista de Mayor a Menor\t\t||");
	printf("\n\t||\t5.Mostrar el Ultimo Elemento y Max Tv\t\t||");
	printf("\n\t\t\t...Seleccionar: ");
	scanf("%d",&eleccion);
	system("cls");
	switch(eleccion){
		case 1:
			agregarTelevisores();
			break;
		case 2:
			desapilarTelevisores();
			break;
		case 3:
			sinTelevisores(televisoresLed);
			break;
		case 4:
			mostrarListaTv(televisoresLed);
			break;
		case 5:
			mostrarTopeTv();
			break;
	}
}

bool sinTelevisores(tDTv pTelevisoresLed){
	return(pTelevisoresLed.tope==-1);
}

bool tvLlenos(tDTv pTelevisoresLed){
	return(pTelevisoresLed.tope==TV-1);
}

void agregarTelevisores(){
	printf("\n\tAgregar Pulgadas de la Tv Led: ");
	scanf("%f",&pulgadas);
	apilarTelevisores(pulgadas);
}

void apilarTelevisores(float pPulgadas){
	if(!tvLlenos(televisoresLed)){
		if(pPulgadas>televisoresLed.tvLed[televisoresLed.tope]){
			televisoresLed.tope+=1;
			televisoresLed.tvLed[televisoresLed.tope]=pPulgadas;
			printf("\n\tTV apilada");
		}
		else{
				printf("\n\tNo se puede apilar");
		}
	}	
	}

float topeTelevisores(tDTv pTelevisoresLed){
	return ( pTelevisoresLed.tvLed[pTelevisoresLed.tope]);
}

void  desapilarTelevisores(){
	if(!sinTelevisores(televisoresLed)){
		float EliminarTv = topeTelevisores(televisoresLed);
		televisoresLed.tvLed[televisoresLed.tope]=0;
		televisoresLed.tope=televisoresLed.tope-1;
		printf("\n\tSe Elimino una Television");
	}
	else{
		printf("\nNo hay TV para quitar\n");
	}
}

void mostrarListaTv(){
	int i;
	for(i=0;i<TV;i++){
		printf("\n%d con %.2f Pulgadas",i+1,televisoresLed.tvLed[i]);
	}
}

void mostrarTopeTv(){
	int i;
	printf("\nTv de %.2f Pulgadas es el Tope",televisoresLed.tvLed[televisoresLed.tope]);
	for(i=0;i<TV;i++){
		if(televisoresLed.tvLed[i]>=20){
			printf("\n\tLas Tv con mayor a 20 Pulgadas son %.2f",televisoresLed.tvLed[i]);
		}
	}
}


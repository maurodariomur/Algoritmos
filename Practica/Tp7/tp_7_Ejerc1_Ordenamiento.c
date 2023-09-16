/*
	Escribir un programa que permita ingresar 10 valores reales por teclado. Luego escribir funciones que 
permitan:
a) Ordenar un vector de menor a mayor por el método directo de burbuja. 
b) Ordenar un vector de menor a mayor por el método directo de selección. 
c) Ordenar un vector de menor a mayor por el método directo de inserción.
*/

#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<locale.h>
#define MAX 5

//declaracion de de dato personalizado
typedef float tVector[MAX];

//declaracion del prototipado
void moduloAbarcador();
void continuarProceso();
void menu();
void ingresarValores();
void mostrarValores(tVector);
void metodoBurbuja(tVector);
void metodoSeleccion(tVector);
void metodoInsercion(tVector);

//declaracion de variables globales
tVector vectorReales;
int continuar,i=0;

//declaracion de la funcion principal
int main(){
	setlocale(LC_ALL,"spanish");
	moduloAbarcador();
	return 0;
}

//implementacion de prototipado
void moduloAbarcador(){
	continuarProceso();
	ingresarValores();
	mostrarValores(vectorReales);
	while(continuar==1){
		menu();
		continuarProceso();
	}
}

void continuarProceso(){
	printf("Desea Ingresar Datos: 1-SI o 0-NO: ");
	scanf("%d",&continuar);
}

void ingresarValores(){
	for(i=0;i<MAX;i++){
		printf("Ingrese el valor: ");
		scanf("%f",&vectorReales[i]);
	}
}

void mostrarValores(tVector pVectorReales){
	for(i=0;i<MAX;i++){
		printf("\n\tEl valor ingresado es: %.2f\n",pVectorReales[i]);
	}
}

void menu(){
	int eleccion;
	printf("\t\t\t\tSeleccion de Opciones\n");
	printf("\t1.Ordenar un vector de menor a mayor por el método directo de burbuja\n");
	printf("\t2.Ordenar un vector de menor a mayor por el método directo de selección\n");
	printf("\t3.Ordenar un vector de menor a mayor por el método directo de inserción\n");
	printf("\t\t\t\t\tSelecione una Opcion: ");
	scanf("%d",&eleccion);
	switch(eleccion){
		case 1:
			metodoBurbuja(vectorReales);
			mostrarValores(vectorReales);	
			break;
		case 2: 
			ingresarValores();
			metodoSeleccion(vectorReales);
			mostrarValores(vectorReales);	
			break;
		case 3:
			ingresarValores();
			metodoInsercion(vectorReales);
			mostrarValores(vectorReales);		
			break;
		default:
			printf("\n\tNo existe esta Opcion...\n");
			break;
	}
}

void metodoBurbuja(tVector pVectorReales){
	int i, j;
	float aux;
	for(i=0;i<MAX-1;i++){
		for(j=0;j<MAX-1;j++){
			if(pVectorReales[j]>pVectorReales[j+1]){
				aux=pVectorReales[j];
				pVectorReales[j]=pVectorReales[j+1];
				pVectorReales[j+1]=aux;
			}		
		}				
	}		
}

void metodoSeleccion(tVector pVectorReales){
	int i,j,posMenor;
	float valorMenor, aux;
	for(i=0;i<MAX-1;i++){
		valorMenor=pVectorReales[i];
		posMenor=i;
		for(j=i+1;j<MAX;j++){
			if(pVectorReales[j]<valorMenor){
				valorMenor=pVectorReales[j];
				posMenor=j;
			}
		}
		
		if(posMenor!=i){
			aux=pVectorReales[i];
			pVectorReales[i]=pVectorReales[posMenor];
			pVectorReales[posMenor]=aux;
		}			
	}
}

void metodoInsercion(tVector pVectorReales){
	int i, j;
	float aux;
	for(i=1;i<MAX;i++){
		aux = pVectorReales[i];
		j=i-1;
		while((j>=0)&&pVectorReales[j]>aux){
			pVectorReales[j+1]=pVectorReales[j];
			j = j-1;
		}		
		pVectorReales[j+1]=aux;		
	}
}

/*
 Escribir un programa que permita ingresar por teclado la cantidad de elementos de un vector, y cada uno 
de los valores de los elementos del vector. Además, escribir funciones para obtener: 
a) el máximo valor almacenado en el vector
b) el mínimo valor almacenado en el vector
c) la media de todos los valores
d) la semisuma (promedio entre el máximo y mínimo).
*/

#include<stdio.h>
#include<string.h>
#include<stdbool.h>


//declaracion de dato personalizado
typedef int tVector[100];

//declaracion del prototipado
void ingresarCantidadElemV();
void ingresarValorElem(int);
void mostrarElemVector();
int menorElemento(tVector);
int mayorElemento(tVector);
void mostrarElMinimo(int);
void mostrarElMax(int);
void calcularLaMedia(int,tVector);
float calcularSemiSuma(int,int);
void mostrarSemiSuma(int,int);

//declaracion de variables globales
tVector vectorEnteros;
int i,max;

//declaracion de funcion principal
int main(){
	int menor,mayor,acumulador;
	ingresarCantidadElemV();
	ingresarValorElem(max);
	mostrarElemVector();
	menor=menorElemento(vectorEnteros);
	mayor=mayorElemento(vectorEnteros);
	mostrarElMinimo(menor);
	mostrarElMax(mayor);
	calcularLaMedia(acumulador,vectorEnteros);
	mostrarSemiSuma(mayor,menor);
	return 0;
}

//implementacion del prototipado
void ingresarCantidadElemV(){
	printf("Ingrese la cantidad de elementos que tendra el Vector: ");
	scanf("%d",&max);
}

void ingresarValorElem(int max){
	for(i=0;i<max;i++){
		printf("Ingrese el Valor del Elemento: ");
		scanf("%d",&vectorEnteros[i]);
	}
}

void mostrarElemVector(){
		printf("\n\tLos valores de los elementos son: \n");
		for(i=0;i<max;i++){
		printf("\t\t\t\t\t\t|\t%d\t|\n",vectorEnteros[i]);
	}
}


int menorElemento(tVector pVectorEnteros){
	int menor = pVectorEnteros[0];
	for( i=0; i<max; i++) {
		if(pVectorEnteros[i] < menor) {
			menor=pVectorEnteros[i];
		}
	}
	return menor;
}

int mayorElemento(tVector pVectorEnteros){
	int mayor= pVectorEnteros[0];
	
	for(i=0;i<max;i++){
		if(pVectorEnteros[i] > mayor){
			mayor= pVectorEnteros[i];
		}
	}
	return mayor;
}

void mostrarElMinimo(int menor){
	printf("\tEl menor elemento es %d\n",menor);	
}

void mostrarElMax(int mayor){
	printf("\tEl mayor elemento es %d\n",mayor);
}

void calcularLaMedia(int acumuladorEnteros,tVector pVectorEnteros){
	acumuladorEnteros=0;
	for(i=0;i<max;i++){
		acumuladorEnteros+=pVectorEnteros[i];
	}
	int media=acumuladorEnteros/max;
	printf("La media es %d\n",media);
}

float calcularSemiSuma(int mayor,int menor){
	return (mayor+menor)/2;
}

void mostrarSemiSuma(int mayor,int menor){
	printf("La semi suma es de %.2f",calcularSemiSuma(mayor,menor));
}

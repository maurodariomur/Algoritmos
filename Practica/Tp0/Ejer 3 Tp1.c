/*
Escribir una función cargarVector que permita almacenar valores que el usuario introduce por teclado. 
Luego escribir la función sumaDeVectores que reciba dos vectores A y B como parámetros de entrada, y 
permita visualizar la suma de cada elemento de A y B. Hacer uso de estas funciones invocándolas desde 
la función main.
*/

#include<stdio.h>

//declaracion de la constante
#define VECTOR 2

//declaracion de dato perzonalizado
typedef float tvector[VECTOR];
typedef float tvector2[VECTOR];
typedef float tvector3[VECTOR];

//declaracion del prototipado
void ingresarNumeros();
float sumaDeVectores(float vector1[VECTOR],float vector2[VECTOR]);
void mostrarResultados();

//declaracion de variables globales
float suma=0;
int i;
tvector vector1;
tvector2 vector2;
tvector3 vector3;

//declaracion de la funcion principañ
int main(){
	ingresarNumeros();
 	sumaDeVectores(vector1,vector2);
 	mostrarResultados();
	return 0;
}

//declaracion del Prototipado
void ingresarNumeros(){
	for(i=0;i<VECTOR;i++){
		printf("Ingrese numero del Vector A: ");
		scanf("%f",&vector1[i]);	
	}
	for(i=0;i<VECTOR;i++){
		printf("Ingrese numero del Vector B: ");
		scanf("%f",&vector2[i]);	
	}
}

float sumaDeVectores(float vector1[VECTOR],float vector2[VECTOR]){
	for(i=0;i<VECTOR;i++){
		vector3[i]=(float)vector1[i]+vector2[i];
	}
	return(vector3[i]);
}

void mostrarResultados(){
	for(i=0;i<VECTOR;i++){
		printf("\n\tDesarrollo y Resultados\n");
		printf("\n%.2f+%.2f=%.2f\n",vector1[i],vector2[i],vector3[i]);
	}
}

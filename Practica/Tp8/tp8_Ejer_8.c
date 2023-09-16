/*
Escribir un programa que permita el ingreso de dos valores enteros (la base entera y el exponente entero 
positivo), calcule la potencia y muestre los resultados por pantalla. Utilizar funci�n recursiva. 
La definici�n recursiva de la operaci�n exponenciaci�n entera, es decir calcular la potencia de ab, se deriva 
de la definici�n de la potencia como una multiplicaci�n abreviada y la aplicaci�n de la propiedad asociativa 
de la multiplicaci�n.
*/

#include<stdio.h>
#include<string.h>
#include<stdbool.h>

//declaracion del prototipado
void ingresarValoresEnteros();
int calcularPotencia(int,int);

//declracion de variables globales;
int exponente,base;

//declaracion de la funcion principal
int main(){
	ingresarValoresEnteros();
	printf("El resultado de la potencia es %d",calcularPotencia(base,exponente));
	return 0;
}

void ingresarValoresEnteros(){
	printf("Ingresar numero como base: ");
	scanf("%d",&base);
	printf("Ingresar numero como exponente: ");
	scanf("%d",&exponente);
}

int calcularPotencia(int b,int e){
	if(e>0){
		return b*(calcularPotencia(b,e-1));
	}else{
		return 1;
	}
}

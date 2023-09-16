/*
Codificar un programa que, a partir del ingreso por teclado de un número entero positivo, permita calcular 
su factorial y visualizar el resultado por pantalla. Utilizar una función recursiva para el cálculo factorial.
*/

#include<stdio.h>

//declaracion del protipado
int ingresarNumero();
int realizarFactorial(int);

//declaracion de funcion Principal
int main(){
	int factorial;
	factorial=ingresarNumero();
	printf("El resultado es %d",realizarFactorial(factorial));
	return 0;
}

int ingresarNumero(){
	int numero;
	printf("Ingresar Numero para Fatorial: ");
	scanf("%d",&numero);
	return numero;
}

int realizarFactorial(int factorial){
	if(factorial>0){
		return (realizarFactorial(factorial-1)*factorial);
	}else{
		return 1;
	}
}


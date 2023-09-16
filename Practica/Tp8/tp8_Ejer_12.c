/*
Codificar un programa que, a partir del ingreso de un n�mero entero positivo, calcule y muestre los 
n�meros de la sucesi�n de Fibonacci. Utilizar una funci�n recursiva.
*/

#include<stdio.h>

//declaracion de prototipado
int ingresarValores();
int realizarFibonacci(int);

int main(){
	int n;
	n=ingresarValores();
	printf("El resultado %d",realizarFibonacci(n));
	return 0;
}

int ingresarValores(){
	int numero;
	printf("Ingresar Valor:");
	scanf("%d",&numero);
	return numero;
}

int realizarFibonacci(int n){
	if(n==0){
		return 0;
	}else{
		if(n==1){
			return 1;
		}else{
			if(n>1){
				return(realizarFibonacci(n-1)+realizarFibonacci(n-2));
			}
		}
	}
}

/*
Escribir un programa que permita ingresar un número entero positivo y luego, mediante una función 
recursiva, muestre el número de forma invertida. Ej.: 123 - 321.
*/
#include<stdio.h>

int ingresarNumero();
int realizarInverso(int);

int main(){
	int numero;
	numero=ingresarNumero();
	realizarInverso(numero);
	return 0;
}

int ingresarNumero(){
	int valorPositivo;
	printf("Ingresar numero positivo: ");
	scanf("%d",&valorPositivo);
	return valorPositivo;
}

int realizarInverso(int valorPositivo){
	printf("%d",valorPositivo%10);
	if(valorPositivo>10){
		realizarInverso(valorPositivo/10);
	}		
}


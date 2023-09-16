/*
Escribir un programa que permita ingresar un n�mero entero positivo y luego, mediante una funci�n 
recursiva, muestre el n�mero de forma invertida. Ej.: 123 - 321.
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


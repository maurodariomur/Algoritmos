/*
Escribir un programa que, a partir del ingreso de un n�mero entero, y mediante la utilizaci�n de una 
funci�n recursiva verEnBinario, permita visualizar el n�mero binario equivalente por pantalla.
*/

#include<stdio.h>

int ingresarNumeroEntero();
void pasajeBinario(int);

int main(){
	int numero;
	numero=ingresarNumeroEntero();
	pasajeBinario(numero);
	return 0;
}

int ingresarNumeroEntero(){
	int numeroDecimal;
	printf("Ingrese el Num. Decimal: ");
	scanf("%d",&numeroDecimal);
	return numeroDecimal;
}

void pasajeBinario(int numeroBinario){
	if(numeroBinario>1){
		pasajeBinario(numeroBinario/2);
	}
	printf("%d",(numeroBinario%2));
}

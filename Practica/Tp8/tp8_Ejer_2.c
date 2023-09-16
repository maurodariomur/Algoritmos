/*
Escribir un programa que, a partir del ingreso de un número entero, y mediante la utilización de una 
función recursiva verEnBinario, permita visualizar el número binario equivalente por pantalla.
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

/*
Escribir un programa que permita mostrar por pantalla una cuenta regresiva, a partir de un valor ingresado 
por teclado. Programar una funci�n recursiva que, al llegar la cuenta a cero, informe que el tiempo se ha 
agotado.
*/
#include<stdio.h>
#include<stdlib.h>

int ingresarNumero();
void realizarRecursividad(int);

int main(){
	int numero;
	numero=ingresarNumero();
	realizarRecursividad(numero);
	return 0;
}

int ingresarNumero(){
	int numero;
	printf("Valor para iniciar cuenta regresiva: ");
	scanf("%d",&numero);
	return numero;
}

void realizarRecursividad(int numero){
	if(numero>=0){
		printf("%d\n",numero);
		realizarRecursividad(numero-1);
	}else{
		printf("\tTiempo Agotado\n");
	}
}

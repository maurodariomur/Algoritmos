/*Escribir un programa que permita mostrar por pantalla una cuenta regresiva, a partir de un valor ingresado
por teclado. Programar una función recursiva que, al llegar la cuenta a cero, informe que el tiempo se ha
agotado. 
*/
#include<stdio.h>

//declaracion del prototipado
int ingresarValorTeclado(int);
void mostrarValores(int);

//declaracion de la funcion principal
int  main(){
	int valor=1;
	ingresarValorTeclado(valor);
	mostrarValores(valor);
	return 0;
}

int ingresarValorTeclado(int valor){
		printf("\tIngresar Valor Deseado: ");
		scanf("%d",&valor);
}

void mostrarValores(int valor){
	if(valor!=0){
		("%d",valor-1);
		mostrarValores(valor);
		printf("\nTiempo agotado");		
	}	
}

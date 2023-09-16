/*
 Desarrollar un TDA �operacionesConDosValores� que declare e implemente las siguientes funciones para 
comparar dos valores enteros:
a) calcular el mayor valor
b) calcular el menor valor
c) determinar si los valores son iguales
d) intercambiar los valores ?Recuerde que deber� usar pasaje de valores por referencia
Luego escriba un programa para probar dicha librer�a (TDA) que permita el ingreso de dos valores enteros 
y mediante la utilizaci�n de las funciones del TDA permita visualizar cu�l es el mayor valor, cu�l es el 
menor, o si los valores son iguales. Por �ltimo, utilice la funci�n para intercambiar y verifique que los 
valores se intercambien.
*/

#include<stdbool.h>

int numeroMayor(int,int);
int numerosMenor(int,int);
bool numerosIguales(int,int);
void intercambioPorReferencia(int * ,int * );

//Implementacion
int numeroMayor(int num1,int num2){
		if(num1>num2){
			return num1;	
		}else{
			return num2;
		}

}

int numerosMenor(int num1,int num2){
	if(num1<num2){
		return num1;	
	}else{
		return num2;
	}
}

bool numerosIguales(int num1,int num2){
		return num1==num2;	
}

void intercambioPorReferencia(int * x,int * y){
	int aux;
	aux=*x;
	*x=*y;
	*y=aux;
}

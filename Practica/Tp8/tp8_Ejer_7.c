/*
El siguiente pseudocódigo corresponde a una función que permite sumar los elementos de un vector en 
forma recursiva:
Función: sumaVec
Datos de entrada: un vector de números enteros, representado por la 
pareja de datos <v, n>. como precondición se considera que el vector ya 
tiene cargados un conjunto de valores válidos y que n es un valor 
comprendido entre el cero (el vector puede estar vacío) y NMAX (la 
dimensión máxima del array). 
Datos de salida: la suma de los elementos del vector, es decir, 
sumaVec(v, n) = ?v[i], i = 0, …, n
Función sumaVec ( v: tArray; n: Entero): Entero
*/

#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define NMAX 5

//declaracion de dato personalizado
typedef int tVector[NMAX];
tVector vectorInt={2,6,3,2,8}; 

void cargaValoresVector();
int sumaVector(tVector,int);

//declaracion de funcion principal
int main(){
	int n=4;
	cargaValoresVector();
	printf("\nEl resultado de la suma es %d\n",sumaVector(vectorInt,n));
	return 0;
}

//implementacion del prototipado
void cargaValoresVector(){
	int i;
	for(i=0;i<NMAX;i++){
		vectorInt[i];
	}
}

int sumaVector(tVector pV,int n){
	int i;
	if(n<0){
		return 0;	
	}else{
		printf("\nLa suma es %d en la posicion %d",pV[n],n);
		return sumaVector(pV,n-1)+pV[n];
			
	}
}

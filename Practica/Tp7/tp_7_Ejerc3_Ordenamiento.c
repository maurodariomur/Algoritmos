/*
Escribir un programa que permita generar un arreglo de 10 valores enteros que se generen de forma 
aleatoria. Luego: 
a) Escribir una función para ordenar de menor a mayor los elementos del vector por el método 
logarítmico Shell.
b) Escribir una función para ordenar de mayor a menor los elementos del vector por el método 
logarítmico QuickSort
*/
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define MAX 5

//declaracion de dato personalizado
typedef int tVector[MAX];

//declaracion del prototipado
void ingresarValores(tVector);
void mostrarElementos(tVector);
void metodoShell(tVector);
void quickSort(tVector, int, int);

//declaracion de las variables globales
tVector n,n2;

//declaracion de la funcion principal
int main(){
	ingresarValores(n);
	metodoShell(n);
	mostrarElementos(n);
	ingresarValores(n2);
	quickSort(n2,0,MAX-1);
	mostrarElementos(n2);
	return 0;
}

void ingresarValores(tVector n){
	int i;
	int lim_inferior = 0;
	int lim_superior = 10;
	for(i=0;i<MAX;i++){
		n[i]=( lim_inferior + rand() % ( lim_superior + 1 - lim_inferior ) ) * 1;
	}
}

void mostrarElementos(tVector pNumeros){
	int i;
	for(i=0;i<MAX;i++){
		printf("\nNumero: %d en la posicion %d \n",pNumeros[i],i+1);
	}
} 

void metodoShell(tVector pNumeros){
    int i, aux;
    int valorMax;
    bool bandera;
    valorMax = MAX;
    while (valorMax>1){
        valorMax = valorMax/2;
        bandera = true;
        while(bandera==true){
            bandera = false;
            i=0;
            while((i+valorMax)<=MAX){
                if(pNumeros[i]>pNumeros[i+valorMax]){
                    aux = pNumeros[i];
                    pNumeros[i] = pNumeros[i+valorMax];
                    pNumeros[i+valorMax] = aux;
                    bandera = true;
                }
            	i++;
            }
        }
    }
}

void quickSort(tVector pNumero, int pIn, int pFin){
    int inicio, final, pivot, medio;
    if(pIn<pFin){
        pivot = pNumero[pFin];  
        inicio = pIn;
        final = pFin;
        while(inicio<final){
            while(final>inicio && pNumero[inicio]>pivot){
                inicio++;
            } 
			if(final>inicio){
                pNumero[final] = pNumero[inicio];
                final--;
            }
            while(inicio<final && pNumero[final]<pivot){
                final--;
            } 
			if(inicio<final){
                pNumero[inicio] = pNumero[final];
                inicio++;
            }
        }
    	pNumero[final] = pivot;
        medio = final;
        quickSort(pNumero, pIn, medio-1);
        quickSort(pNumero, medio+1, pFin);
    }
}




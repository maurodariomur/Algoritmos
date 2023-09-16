/*
a) Escribir una función para ordenar los elementos por algún método de ordenación. 
b) Escribir una función para mostrar los elementos ordenados. 
c) Escribir una función que reciba un valor a buscar y un vector en donde buscar el ese elemento, y realice 
la búsqueda a través del método de búsqueda binaria. En el caso que el elemento exista en el vector, 
se debe retornar la posición dentro del vector, o -1 en caso contrario.
d) En el programa principal, se deben utilizar las funciones y mostrar por pantalla el resultado de la 
búsqueda, indicando si el elemento ha sido encontrado o no.
*/

#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define MAX 5

//declaracion de dato personalizado
typedef int tVector[MAX];

//declaracion del prototipado
void ingresarValores();
void metodoBurbuja(tVector);
void mostrarElementos(tVector);
int seleccionNumero(int);
int busquedaBinaria(tVector,int);
bool comprobarExistencia(tVector,int);


tVector n;

//declaracion de la funcion principal
int main(){
	int numero;
	ingresarValores();
	metodoBurbuja(n);
	mostrarElementos(n);
	numero=seleccionNumero(numero);
	printf("El numero encontrado en la posicion es %d",busquedaBinaria(n,numero));
	return 0;
}

void ingresarValores(){
	int i;
	for(i=0;i<MAX;i++){
		printf("Ingrese numeros: ");
		scanf("%d",&n[i]);
	}
}

void metodoBurbuja(tVector pNumeros){
	int i,j;
	int aux=0;
	for(i=0;i<MAX-1;i++){
		for(j=0;j<MAX-1;j++){
			if(pNumeros[j]>pNumeros[j+1]){
				aux=pNumeros[j];
				pNumeros[j]=pNumeros[j+1];
				pNumeros[j+1]=aux;
			}
		}
	}
}

void mostrarElementos(tVector numeros){
	int i;
	for(i=0;i<MAX;i++){
		printf("\nNumero: %d en la posicion %d \n",numeros[i],i+1);
	}
} 

int seleccionNumero(int numeroComprobar){
	printf("Numero a Comprobar ");
	scanf("%d",&numeroComprobar);
	return numeroComprobar;
}

int busquedaBinaria(tVector pNumero,int pElemento){
	int inferior=0;
	int superior=MAX;
	int media,entero;
	bool existe=false;
	while((!existe)&&(superior>=inferior)){
		media=( superior+inferior)/2;
		if(pNumero[media]==pElemento){
			existe=true;
		} else {
			if(pElemento>pNumero[media]){
				inferior=media+1;				
			} else {
				superior=media-1;
			}	
		}
	}
	if(existe){
		entero=media;
	}else{
		entero=-1;
	}
	return entero;
}


/*
 Escribir una función generarVectorPares que genere un vector con los números pares comprendidos 
entre 1 y 100. Luego, escribir una función maximo que reciba un vector como parámetro y retorne el 
máximo elemento del arreglo. Probar la función maximo en la función principal, utilizando el vector de 
números pares generado anteriormente.
*/
#include<stdio.h>
#include<string.h>

//declaracion de la constante
#define VECTOR 50

//declaracion del dato personalizado
typedef int tvector[VECTOR];

//declaracion del prototipado
void inicializarVariables();
void generarVectoresPares();
int maximo(int vectorNumPares[VECTOR]);

//declaracion de las variables globales
int i,maxElemento;
tvector vectorNumPares;

//declaracion de la funcion principal
int main(){
	inicializarVariables();
	generarVectoresPares();
	maximo(vectorNumPares);
	return 0;
}

//declaracion de los procedimientos

void inicializarVariables(){
	for(i=0;i<=VECTOR;i++){
		vectorNumPares[i]=0;
	}
}
void generarVectoresPares(){
	for(i=1;i<=VECTOR;i++){
		vectorNumPares[i]=i*2;
		printf("%d\t",vectorNumPares[i]);
	}
	
}

int maximo(int vectorNumPares[VECTOR]){
	for(i=1;i>=VECTOR;i++){
		if(vectorNumPares[i]>maxElemento){
			maxElemento=vectorNumPares[i];
		}
		return(maxElemento);
	}
	printf("\n\tEl mayor Numero es %d",maxElemento);
}


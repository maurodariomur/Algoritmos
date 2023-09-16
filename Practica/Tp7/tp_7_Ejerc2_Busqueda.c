/*
Escribir una función que permita encontrar un valor en un arreglo de números reales, según el método de 
búsqueda binaria. La función debe devolver true en el caso que el elemento a buscar exista dentro del 
arreglo y false en caso contrario. Probar la función en el bloque principal de un programa C
*/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 5

//delcaracion de dato personalizado
typedef float tVector[MAX];

//declaracion del prototipado
void generarNumerosAleatorios(tVector);
void mostrarVectorFloat();
float ingresarNumeroVerificar();
bool busquedaBinaria(tVector,float);
bool determinarExistenciaReal(tVector,float);

//declaracion de variables globales
tVector vectorReales;
int i=0;

//declaracion de la funcion principal
int main(){
	float numReal;
	generarNumerosAleatorios(vectorReales);
	mostrarVectorFloat();
	numReal=ingresarNumeroVerificar();
	busquedaBinaria(vectorReales,numReal);
	determinarExistenciaReal(vectorReales,numReal);
	return 0;
}

//implementacion del prototipado
void generarNumerosAleatorios(tVector pVectorReales){
	int lim_inferior = 0;
	int lim_superior = 10;
	for(i=0;i<MAX;i++){
		pVectorReales[i] = ( lim_inferior + rand() % ( lim_superior + 1 - lim_inferior ) ) * 1.25;
		//pVectorReales[i] =(((float) rand())/((float)RAND_MAX)*10+1)
		;
	}
}

void mostrarVectorFloat(){
	printf("\n\tLos Valores del Vector: \n");
	printf("\t\t\t\t---------\n");
	for(i=0; i<MAX;i++){
		printf("\t\t\t\t| %.2f\t|\n",vectorReales[i]);
		printf("\t\t\t\t---------\n");
	}
	printf("\n");
}

float ingresarNumeroVerificar(){
	float numReal=0;
	printf("Numero a comprobar: ");
	scanf("%f",&numReal);
	return numReal;
}

bool busquedaBinaria(tVector pVectorReales ,float pNumReal){
	int extInf = 0;
	int extSup = MAX;
	int posMed;
	bool existe = false;
	
	while((!existe) && (extSup >= extInf)){
		posMed=(extSup + extInf)/2.00;
		if(pVectorReales[posMed]==pNumReal) {
			existe = true;
		} else {
			if( pNumReal > pVectorReales[posMed] ) {
				extInf = posMed + 1;				
			} else {
				extSup = posMed - 1;
			}	
		}
	}	
	return existe;	
}

bool determinarExistenciaReal(tVector pVectorReales,float pNumReal){
		printf("Existe el %.2f ? %s\n\n", pNumReal, busquedaBinaria(pVectorReales,pNumReal)==true? "true": "false" );	
}


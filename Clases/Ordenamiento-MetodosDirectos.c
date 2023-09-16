#include <stdio.h>	
#include <stdbool.h>
#include <stdlib.h>
#define MAX 7

/* Declaración de tipos de datos personalizados */
typedef float tVectorFloat [MAX];

/* Declaración de prototipos */
void cargarVectorDesordenadoRandom( tVectorFloat );
void cargarVectorOrdenado( tVectorFloat );
void mostrarElementos( tVectorFloat );
void seleccionDirecta( tVectorFloat );
void insercionDirecta( tVectorFloat );
void intercambioDirecto( tVectorFloat );
void intercambioDirectoOptimizado( tVectorFloat );

/* Declaración de tipos de variables */
tVectorFloat v1, v2, v3, v4;

int main() {
	
	printf("------------------------------------------------------\n");
	printf(" *** METODO SELECCION DIRECTA *** \n");
	printf("------------------------------------------------------\n");
			
	cargarVectorDesordenadoRandom( v1 );
	printf("Antes de ordenar: \n");
	mostrarElementos( v1 );
	
	seleccionDirecta( v1 );
	printf("Despues de ordenar: \n");
	mostrarElementos( v1 );
	
	
	printf("------------------------------------------------------\n");
	printf(" *** METODO INSERCION DIRECTA *** \n");
	printf("------------------------------------------------------\n");
			
	cargarVectorDesordenadoRandom( v2 );
	printf("Antes de ordenar: \n");
	mostrarElementos( v2 );
	
	insercionDirecta( v2 );
	printf("Despues de ordenar: \n");
	mostrarElementos( v2 );
	
	printf("------------------------------------------------------\n");
	printf(" *** METODO INTERCAMBIO DIRECTO *** \n");
	printf("------------------------------------------------------\n");
			
	cargarVectorDesordenadoRandom( v3 );
	printf("Antes de ordenar: \n");
	mostrarElementos( v3 );
	
	intercambioDirecto( v3 );
	printf("Despues de ordenar: \n");
	mostrarElementos( v3 );
	
	printf("------------------------------------------------------\n");
	printf(" *** METODO INTERCAMBIO DIRECTO OPTIMIZADO *** \n");
	printf("------------------------------------------------------\n");
			
	cargarVectorDesordenadoRandom( v4 );
	printf("Antes de ordenar: \n");
	mostrarElementos( v4 );
	
	intercambioDirectoOptimizado( v4 );
	printf("Despues de ordenar: \n");
	mostrarElementos( v4 );
	
	return 0;
}

void cargarVectorOrdenado( tVectorFloat pVector ) {
	pVector[0] = 4;
	pVector[1] = 5;
	pVector[2] = 7;
	pVector[3] = 1;
	pVector[4] = 9;
	pVector[5] = 8;
	pVector[6] = 2;
}

void cargarVectorDesordenadoRandom( tVectorFloat pVector ) {
	int i;
	int lim_inferior = 0;
	int lim_superior = 10;
	
	srand( time( NULL ) );
	
	for( i=0; i<MAX; i++) {
		pVector[i] = ( lim_inferior + rand() % ( lim_superior + 1 - lim_inferior ) ) * 1.25;
	}	
}

void mostrarElementos( tVectorFloat pVector ) {
	int i;
	printf("\nElementos: \n | ");
	for( i=0; i<MAX; i++) {
		printf("%.2f | ", pVector[i]);
	}
	printf("\n");
}

void seleccionDirecta( tVectorFloat pVector ) {
	int i, j, posMenor;
	float valorMenor, aux;
	
	for ( i=0; i<MAX-1; i++ ) { // pasadas
		valorMenor = pVector[i];
		posMenor = i;
	
		for( j=i+1; j<MAX; j++) {
			if( pVector[j] < valorMenor ) {
				valorMenor = pVector[j];
				posMenor = j;
			}
		}
		
		if( posMenor != i ) {
			aux = pVector[i];
			pVector[i] = pVector[posMenor];
			pVector[posMenor] = aux;
		}			
	}
}

void insercionDirecta( tVectorFloat pVector ) {
	int i, j;
	
	float aux;
	
	
	for ( i=1; i<MAX; i++ ) {
		
		aux = pVector[i];
		
		j = i-1;
		
		while( (j>=0) && pVector[j]>aux ) {
			pVector[j+1] = 	pVector[j];
			j = j-1;
		}		
		
		pVector[j+1]  = aux;		
	}
		
}

void intercambioDirecto( tVectorFloat pVector ) {
	int i, j;
	float aux;
	
	for( i=0; i<MAX-1; i++ ) {
		
		for( j=0; j<MAX-1; j++ ) {
			
			if( pVector[j] > pVector[j+1] ) {
				aux =  pVector[j];
				pVector[j] =  pVector[j+1];
				pVector[j+1] = aux;
			}		
		}				
	}		
}

void intercambioDirectoOptimizado( tVectorFloat pVector ) {
	int i, j;
	float aux;
	bool flag = false;
	
	i = 0;
	while( (flag == false) && ( i<MAX ) ) {
		flag = true;
		for( j=0; j<MAX-1; j++ ) {
			
			if( pVector[j] > pVector[j+1] ) {
				aux =  pVector[j];
				pVector[j] =  pVector[j+1];
				pVector[j+1] = aux;
				flag = false;
			}		
		}					
		i = i+1;
	}	
	
}







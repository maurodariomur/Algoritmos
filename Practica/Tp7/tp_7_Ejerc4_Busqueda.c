/*
4. Dada una matriz A de 5 filas y 4 columnas, determinar el valor máximo y mínimo de la matriz, indicando 
además las posiciones en las que se encuentran estos valores.
*/

#include<stdio.h>
#include<string.h>
#define MAXF 5
#define MAXC 4

//declaracion de dato personalizado

typedef int tMatriz[MAXF][MAXC];
typedef int tVector[MAXF];

//declaracion de prototipado
void generarNumerosAleatorios();
void mostrarNumerosAleatorios();
void mayorElemento();
void menorElemento();

//declaracion de variables globlales
tMatriz matrizNumReales;
tVector vectorNumReales;
int i,j;

//declaracion de funcion principal
int main(){
	generarNumerosAleatorios();
	mostrarNumerosAleatorios();
	mayorElemento();
	menorElemento();
	return 0;
}

//implementacion del prototipado

void generarNumerosAleatorios(){
	int lim_inferior = 0;
	int lim_superior = 10;
	for(i=0;i<MAXF;i++){
		for(j=0;j<MAXC;j++){
			matrizNumReales[i][j] = ( lim_inferior + rand() % ( lim_superior + 1 - lim_inferior ) ) * 1;
		}	
	}
}

void mostrarNumerosAleatorios(){
	for(i=0;i<MAXF;i++){
		for(j=0;j<MAXC;j++){
			printf("\nEl elemento %d,esta en la posicion %d-%d\n",matrizNumReales[i][j],i+1,j+1);
		}	
	}
}

void mayorElemento(){
	int mayor=	matrizNumReales[0][0];
	int fila=0;
	int columna=0;
	for(i=0;i<MAXF;i++){
		for(j=0;j<MAXC;j++){
			if(matrizNumReales[i][j]>mayor){
				mayor=matrizNumReales[i][j];
				fila=i+1;
				columna=j+1;
			}	
		}	
	}
	printf("\n\n\tEL MAYOR ELEMENTO ES %d EN LA POSICION %d-%d\n",mayor,fila,columna);
}

void menorElemento(){
	int menor=matrizNumReales[0][0];
	int fila=0;
	int columna=0;
	for(i=0;i<MAXF;i++){
		for(j=0;j<MAXC;j++){
			if(matrizNumReales[i][j]<menor){
				menor=matrizNumReales[i][j];
				fila=i+1;
				columna=j+1;
			}	
		}	
	}
	printf("\n\n\tEL MENOR ELEMENTO ES %d EN LA POSICION %d-%d\n",menor,fila,columna);
}


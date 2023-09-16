/*
 Realizar un programa que permita visualizar una pirámide de asteriscos. Para ello se debe solicitar el 
ingreso de un número entero que representa la cantidad de filas que tendrá la pirámide. La primera fila de 
la pirámide debe tener un solo asterisco centrado, en la 2da fila, el doble de la primera más uno, y así 
sucesivamente. Por ejemplo, si se introduce el 5, el resultado sería:
Se debe incluir una función dibujarLinea que reciba como parámetro la cantidad de asteriscos de la línea 
por dibujar, y una función dibujarPiramide que reciba como parámetro la cantidad de filas de la pirámide
*/

#include<stdio.h>
#include<string.h>

//declaracion del Prototipado
void ingresarDatos();
void dibujarLinea(int);
void dibujarPiramide(int);

//declaracion de variables globales
int i,j,n;

int main(){
	ingresarDatos();
	dibujarLinea(j);
	//dibujarPiramide(n);
	return 0;
}

void ingresarDatos(){
	printf("Ingresar cantidad de Filas de la piramide: ");
	scanf("%d",&n);
}

void dibujarPiramide(pN){
		for(j=0;j<pN-i;j++){
			printf(" ");
		}	
		
}

void dibujarLinea(int pJ){
	for(i=0;i<=n;i++){
		for(pJ=0;pJ<2*i-1;pJ++){
		printf("*");
		}
		printf("\n");
		dibujarPiramide(n);
	}
}

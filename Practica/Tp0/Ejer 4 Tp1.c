/*
 Realizar un programa que permita visualizar una pir�mide de asteriscos. Para ello se debe solicitar el 
ingreso de un n�mero entero que representa la cantidad de filas que tendr� la pir�mide. La primera fila de 
la pir�mide debe tener un solo asterisco centrado, en la 2da fila, el doble de la primera m�s uno, y as� 
sucesivamente. Por ejemplo, si se introduce el 5, el resultado ser�a:
Se debe incluir una funci�n dibujarLinea que reciba como par�metro la cantidad de asteriscos de la l�nea 
por dibujar, y una funci�n dibujarPiramide que reciba como par�metro la cantidad de filas de la pir�mide
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

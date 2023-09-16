/*
Escribir un programa que, a partir del ingreso de dos n�meros enteros positivos, calcule el producto de los 
mismos utilizando una funci�n recursiva. Tener presente que la definici�n recursiva de la multiplicaci�n 
de dos n�meros a y b, se deriva de la definici�n de la multiplicaci�n como una suma abreviada y la 
aplicaci�n de la propiedad asociativa de la suma.
*/

#include<stdio.h>
#include<string.h>

void ingresarValores();
int multiplicacion(int,int);

int numeroA,numeroB,cont;

int main(){
	ingresarValores();
	printf("\n\tOperacion: %d . %d\n",numeroA,numeroB);
	//multiplicacion(numeroA,numeroB);
	printf("\n\tOperacion: %d \n",multiplicacion(numeroA,numeroB));
	return 0;
}

void ingresarValores(){
	printf("Ingresar numero A: ");
	scanf("%d",&numeroA);
	printf("Ingresar numero B: ");
	scanf("%d",&numeroB);
}

int multiplicacion(int numeroA,int numeroB){ 
	if(numeroB>0){
		return numeroA + multiplicacion(numeroA,numeroB-1);
	}else{
		return 0;
	}
}

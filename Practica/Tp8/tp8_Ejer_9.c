/*
Escribir un programa que, mediante funciones, determine la suma de “N” números naturales. Mostrar la 
serie de los números desde 1 hasta N y el resultado de la suma.
*/
#include<stdio.h>

//declaracion de prototipado
int ingresarValorNatural();
int sumaNatural(int);

int main(){
	int n;
	n=ingresarValorNatural();
	printf("\n\tLa suma es %d",sumaNatural(n));
	return 0;
}

int ingresarValorNatural(){
	int natural;
	printf("Ingresar el numero Natural: ");	
	scanf("%d",&natural);	
	return natural;
}

int sumaNatural(int numNatural){
	if(numNatural>0){
		return (sumaNatural(numNatural-1)+numNatural);
	}else{
		return 0;
	}
}

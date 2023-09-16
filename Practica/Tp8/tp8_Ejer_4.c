/*
Escribir una función que calcule la división entera entre 2 números de manera recursiva. Recordar que la 
división matemática se define como una operación aritmética, que consiste en saber cuántas veces un 
número (divisor) está contenido en otra cifra (dividendo)
*/

#include<stdio.h>

void ingresarValores();
int dividir(int,int);

int divisor,dividiendo;

int main(){
	ingresarValores();
	printf("\n\tOperacion: %d : %d\n",dividiendo,divisor);
	printf("\n\tEl resultado de la division es: %d\n",dividir(dividiendo,divisor));
	return 0;
}

void ingresarValores(){
	printf("Ingresar dividiendo: ");
	scanf("%d",&dividiendo);	
	printf("Ingresar divisor: ");
	scanf("%d",&divisor);

}

int dividir(int dividiendo,int divisor){
		if(dividiendo>=divisor){
			return (dividir(dividiendo-divisor,divisor)+1);
			
		}else{
			return 0;
		}
}
	

/*
Escribir una funci�n que calcule la divisi�n entera entre 2 n�meros de manera recursiva. Recordar que la 
divisi�n matem�tica se define como una operaci�n aritm�tica, que consiste en saber cu�ntas veces un 
n�mero (divisor) est� contenido en otra cifra (dividendo)
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
	

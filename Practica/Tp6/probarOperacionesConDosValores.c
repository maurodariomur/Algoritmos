/*
 Desarrollar un TDA “operacionesConDosValores” que declare e implemente las siguientes funciones para 
comparar dos valores enteros:
a) calcular el mayor valor
b) calcular el menor valor
c) determinar si los valores son iguales
d) intercambiar los valores ?Recuerde que deberá usar pasaje de valores por referencia
Luego escriba un programa para probar dicha librería (TDA) que permita el ingreso de dos valores enteros 
y mediante la utilización de las funciones del TDA permita visualizar cuál es el mayor valor, cuál es el 
menor, o si los valores son iguales. Por último, utilice la función para intercambiar y verifique que los 
valores se intercambien.
*/

#include<stdio.h>
#include"operacionesConDosValores.h"

//declaracion del prototipado
void moduloAbarcador();
void permitirProceso();
void continuarProceso();
void menu();
void calcularElNumMayor();
void calcularElNumMenor();
bool calcularIgualdad();
void realizarIntercambioValores();

//declaracion de variables globales
int numero1,numero2;
char continuar;
//declaracion de la funcion principal
int main(){
	moduloAbarcador();
	return 0;
}

void permitirProceso(){
	printf("\n\tDesea Agregar Datos: s-SI o n-NO: ");
	fflush(stdin);
	scanf("%c",&continuar);
}

void continuarProceso(){
	printf("\n\tDesea continuar Agregando Datos: s-SI o n-NO: ");
	fflush(stdin);
	scanf("%c",&continuar);
}

void moduloAbarcador(){
	permitirProceso();
	while(continuar=='s'){
		menu();
		continuarProceso();
	}
}

void menu(){
	int eleccion;
	printf("\n\t\t***Seleccion de Opciones***\t\n");
	printf("\n\t||\t1.Determinar El Mayor\t\t\t||");
	printf("\n\t||\t2.Determinar si es Menor\t\t||");
	printf("\n\t||\t3.Determinar si es Igual\t\t||");
	printf("\n\t||\t4.Realizar el Intercambio\t\t||");
	printf("\n\t\t\t...Seleccionar: ");
	scanf("%d",&eleccion);
	switch(eleccion){
		case 1:
			calcularElNumMayor();
			break;
		case 2:
			calcularElNumMenor();
			break;
		case 3:
			calcularIgualdad();
			break;
		case 4:
			realizarIntercambioValores();
			break;
		default:
			printf("\tNo existe esta opcion\n");
			break;
	}
}

float ingresarNumeros(){
	printf("Ingrese el Numero 1: ");
	scanf("%d",&numero1);
	printf("Ingrese el Numero 2: ");
	scanf("%d",&numero2);
	return numero1,numero2;
}

void calcularElNumMayor(){
	if(ingresarNumeros()){
		printf("\n\tEl mayor numero es : %d\n",numeroMayor(numero1,numero2));
	}else{
		printf("\n\tNo hay numeros vuelva a menu\n");
	}	
}

void calcularElNumMenor(){
		if(ingresarNumeros()){
		printf("\n\tEl menor numero es:%d\n",numerosMenor(numero1,numero2));
	}else{
		printf("\n\tNo hay numeros vuelva a menu\n");
	}
} 

bool calcularIgualdad(){
		if(ingresarNumeros()){
			printf("%s",(numerosIguales(numero1,numero2))? "Estos numeros son iguales":"Estos Numeros son diferentes");
	}
} 

void realizarIntercambioValores(){
		if(ingresarNumeros()){
			printf("\n\tNumero 1 es %d, y Numero 2 es %d\n",numero1,numero2);
			intercambioPorReferencia(&numero1,&numero2);
			printf("\n\tEl intercambio es de numero 1 es %d, y el intercambio de 2 es %d\n",numero1,numero2);
	}else{
		printf("\n\tNo hay numeros vuelva a menu\n");
	}
}  

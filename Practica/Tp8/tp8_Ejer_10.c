/*
Escribir un programa que permita ingresar una palabra y determinar si es palíndroma.
*/

#include<stdio.h>
#include<string.h>
#include<stdbool.h>

//declaracion de dato perosonalizado
typedef char tString[10];

//declaracion de prototipado
void ingresarPalabra();
int  calcularLargo(tString);
bool realizarIntercambioL(tString,int,int);

//declaracion de variables globales
tString palabra;

//declaracion de la funcion principal
int main(){
	int inicio=0;
	ingresarPalabra();
	printf("La palabra %s",realizarIntercambioL(palabra,inicio,calcularLargo(palabra))?"es palindrome":"no es palindrome");
	return 0;
}

//implementacion de prototipado
void ingresarPalabra(){
	printf("Ingrese la palabra palidroma: ");
	fflush(stdin);
	scanf("%[^\n]s",&palabra);
}

int calcularLargo(tString pPalabra){
	int largo;
	largo=strlen(pPalabra)-1;
	return largo;
}

bool realizarIntercambioL(tString pPalabra,int inicio,int final){
	if(inicio>=final){
		return true;
	}else{
		if(pPalabra[inicio]==pPalabra[final]){
			realizarIntercambioL( pPalabra,inicio+1,final-1);
		}else{
			return false;
		}
	}
}

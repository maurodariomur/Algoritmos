#include<stdio.h>
#include<string.h>
#include"operacionesBasicas.h"

//declaracion del prototipado
void moduloAbarcador();
void permitirProceso();
void continuarProceso();
float ingresarNumeros();
void menu();
void sumaNumeros();
void restaNumeros();
void productoNumeros();
void divisionNumeros();

//declaracion de variables globales 
char continuar;
float numero1,numero2;

//declaracion de la funcion Principal
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
	printf("\n\t||\t1.Sumar Numeros\t\t\t||");
	printf("\n\t||\t2.Restar Numeros\t\t||");
	printf("\n\t||\t3.Multiplicar Numeros\t\t||");
	printf("\n\t||\t4.Dividir Numeros\t\t||");
	printf("\n\t\t\t...Seleccionar: ");
	scanf("%d",&eleccion);
	switch(eleccion){
		case 1:
			sumaNumeros();
			break;
		case 2:
			restaNumeros();
			break;
		case 3:
			 productoNumeros();
			break;
		case 4:
			divisionNumeros();
			break;
		default:
			printf("\tNo existe esta opcion\n");
			break;
	}
}

float ingresarNumeros(){
	printf("Ingrese el Numero 1: ");
	scanf("%f",&numero1);
	printf("Ingrese el Numero 2: ");
	scanf("%f",&numero2);
	return numero1,numero2;
}

void sumaNumeros(){
	if(ingresarNumeros()){
		printf("\n\tLa suma de los numeros es de: %.2f\n",sumaReales(numero1,numero2));
	}else{
		printf("\n\tNo hay numeros vuelva a menu\n");
	}	
}

void restaNumeros(){
		if(ingresarNumeros()){
		printf("\n\tLa resta de los numeros es de: %.2f\n",restaReales(numero1,numero2));
	}else{
		printf("\n\tNo hay numeros vuelva a menu\n");
	}
} 

void productoNumeros(){
		if(ingresarNumeros()){
		printf("\n\tEl producto de los numeros es de: %.2f\n",productoReales(numero1,numero2));
	}else{
		printf("\n\tNo hay numeros vuelva a menu\n");
	}
} 

void divisionNumeros(){
		if(ingresarNumeros()){
		printf("\n\tLa division de los numeros es de: %.2f\n",divisionReales(numero1,numero2));
	}else{
		printf("\n\tNo hay numeros vuelva a menu\n");
	}
}  

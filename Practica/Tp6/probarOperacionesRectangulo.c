#include<stdio.h>
#include<string.h>
#include"operacionesRectangulo.h"

//declaracion del prototipado
void moduloAbarcador();
void permitirProceso();
void continuarProceso();
void ingresarDatosRectangulo();
void calcularPerimetroYArea();

//declaracion de variables globales 
int continuar;
float ladoA,ladoB,ancho;

//declaracion de la funcion Principal
int main(){
	moduloAbarcador();
	return 0;
}

void permitirProceso(){
	printf("\n\tDesea Agregar Datos: 1-SI o 0-NO: ");
	scanf("%d",&continuar);
}

void continuarProceso(){
	printf("\n\tDesea continuar Agregando Datos: 1-SI o 0-NO: ");
	scanf("%d",&continuar);
}

void moduloAbarcador(){
	permitirProceso();
	while(continuar==1){
		ingresarDatosRectangulo();
		calcularPerimetroYArea();
		continuarProceso();
	}
}

void ingresarDatosRectangulo(){
	printf("Ingrese el lado A del rectangulo: ");
	scanf("%f",&ladoA);
	printf("Ingrese el lado B del rectangulo: ");
	scanf("%f",&ladoB);
	printf("Ingrese el ancho del rectangulo: ");
	scanf("%f",&ancho);
}

void calcularPerimetroYArea(){
	printf("\n\tEl perimetro del rectangulo es %.2f cm;\n",perimetroDeRectanulo(ladoA,ladoB));
	printf("\tEl area del rectangulo es %.2f cm.",areaRectangulo(ancho,ladoA));	
} 

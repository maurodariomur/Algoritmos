/*
La represa Yaciretá tiene capacidad en su exclusa para 30 embarcaciones medianas. Las embarcaciones 
llegan por un extremo y salen por el otro. Prefectura debe registrar el nombre de las embarcaciones que 
se anotan para cruzar por día. Se necesita generar un listado de todas las embarcaciones anotadas en la 
fecha para cruzar y la disponibilidad de lugar en esa fecha. Utilizar la implementación con frente fijo.
*/

#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>

//declaracion de constante
#define MAXEM 30

//declaracion de dato Personalizado
typedef char tString[40];
typedef tString tLista[MAXEM];

//declaracion de Estructura
typedef struct{
	tLista nombre;
	int frente;
	int final;
}tPrefectura;

//declaracion de Prototipado
void iniciarProceso();
void continuarProceso();
void inicializarCola();
void seleccionEnMenu();
bool colaVacia(tPrefectura);
bool colaLlena(tPrefectura);
void agregarEnPrefectura();
void listaDeEmbarcaciones(tString);
void eliminarEmbarcaciones();
void mostrarPrimerEmbarcacion(tPrefectura);
void mostrarEmbarcaciones(tPrefectura);

//declaracion de variables
tPrefectura prefectura;
int continuar;

//declaracion de Funcion Principal
int main(){
	setlocale(LC_ALL,"spanish");
	iniciarProceso();
	return 0;
}

//declaracion de Procedimientos
void iniciarProceso(){
	continuarProceso();
	inicializarCola();
	while(continuar==1){
		seleccionEnMenu();
		continuarProceso();
	}
}

void continuarProceso(){
	printf("\n\tDesea Agregar Datos: 1-SI o 0-NO: ");
	scanf("%d",&continuar);
}

void inicializarCola(){
	prefectura.frente=-1;
	prefectura.final=-1;
	printf("\n\tSe inicializar la Cola\n");
}

void seleccionEnMenu(){
	int eleccion;
	printf("\n\t\tSELECCIÓN DE OPCIONES\n");
	printf("\n\t||1.Agregar Embarcacion a la Cola\t\t||");
	printf("\n\t||2.Eliminar Embarcacion de la Cola\t\t||");
	printf("\n\t||3.Mostrar Lista de Embarcaciones\t\t||");
	printf("\n\t||4.Mostrar Primer Embarcacion\t\t\t||");
	printf("\n\t\t\tSelecciona: ");
	scanf("%d",&eleccion);
	system("cls");
	switch(eleccion){
		case 1:
			agregarEnPrefectura();
			break;
		case 2:
			eliminarEmbarcaciones();
			break;
		case 3:
			mostrarEmbarcaciones(prefectura);
			break;
		case 4:
			mostrarPrimerEmbarcacion(prefectura);
			break;
	}
}

void agregarEnPrefectura(){
	char cadena[40];
	
	printf("Nombre de la Embarcacion: ");
	fflush(stdin);
	scanf("%[^\n]s",&cadena);
	listaDeEmbarcaciones(cadena);	
}

bool colaVacia(tPrefectura pPrefectura) {
	return ( pPrefectura.frente == -1 && pPrefectura.final == -1 );
}

bool colaLlena(tPrefectura pPrefectura)  {
	return ( pPrefectura.final == (MAXEM-1) );
}

void listaDeEmbarcaciones(tString pCadena){
	if(colaLlena(prefectura)){
		printf("No hay lugares disponibles");
	}
	else{
		//Hay lugar para Insertar
		
		//Actualizar el indice Final
		prefectura.final+=1;
		
		//Almacenar el elemento en la Lista
		strcpy(prefectura.nombre[prefectura.final],pCadena);
		
		//Verificar si se esta insetando el primer elemento
		if(prefectura.final==0){
			//Es el primer elemento
			prefectura.frente=0;
		}
		printf("\n\t Turno para la Embarcacion %s\n",pCadena);
		
	int fecha;
	printf("\n\t\tSELECCIÓN DE OPCIONES\n");
	printf("\n\t||1.Lunes\t\t||");
	printf("\n\t||2.Martes\t\t||");
	printf("\n\t||3.Miercoles\t\t||");
	printf("\n\t||4.Jueves\t\t||");
	printf("\n\t||5.Viernes\t\t||");
	printf("\n\t||6.Sabado\t\t||");
	printf("\n\t||7.Domingo\t\t||");
	printf("\n\t\t\tSelecciona: ");
	scanf("%d",&fecha);
	switch(fecha){
		case 1:
			printf("Seleccionó El dia LUNES la Embaracion %s",pCadena);
			break;
		case 2:
			printf("Seleccionó El dia MARTES la Embaracion %s",pCadena);
			break;
		case 3:
			printf("Seleccionó El dia MIERCOLES la Embaracion %s",pCadena);
			break;
		case 4:
			printf("Seleccionó El dia JUEVES la Embaracion %s",pCadena);
			break;
		case 5:
			printf("Seleccionó El dia VIERES la Embaracion %s",pCadena);
			break;
		case 6:
			printf("Seleccionó El dia SABADO la Embaracion %s",pCadena);
			break;
		case 7:
			printf("Seleccionó El dia DOMINGO la Embaracion %s",pCadena);
			break;
		}
	}
}

void eliminarEmbarcaciones(){
	tString embarcacionSuprimir = " ";
	int i;
	if( colaVacia( prefectura ) ) {
		printf("No hay embarcaciones para eliminar\n");
	} 
	else {
		/* Hay elementos por eliminar */
		
		/* Resguardar el elemento por eliminar */
		strcpy( embarcacionSuprimir, prefectura.nombre[prefectura.frente] );
		
		/* Borrar el elemento que se encuentra en el frente */
		strcpy(prefectura.nombre[prefectura.frente], " ");
		
		/* Reacomodar la lista */
		for( i= prefectura.frente; i< prefectura.final; i++ ) {
			strcpy( prefectura.nombre[i], prefectura.nombre[i+1] );			
		}
		
		/* Borrar el valor duplicado del final */
		strcpy(prefectura.nombre[prefectura.final], " ");
		
		/* Verificar si la cola tiene un solo elemento, y actualizar índices */
		if( prefectura.frente == prefectura.final ) {
			/* 	Significa que se elimina el único elemento en la cola,
				por lo que hay que inicializar la cola nuevamente */
			inicializarCola();
		} 
		else {
			prefectura.final = prefectura.final - 1;
		}
		
		/* Emitir mensaje de confirmación */
		printf("Embarcacion eliminada: %s\n",embarcacionSuprimir);
	}

}

void mostrarPrimerEmbarcacion(tPrefectura pPrefectura){
	if(colaVacia(prefectura)){
		printf("\n\tNo hay primer Embarcacion para visualizar\n");
	}
	else{
		printf("Primer Embarcacion: %s\n", pPrefectura.nombre[pPrefectura.frente]);
	}
	
}

void mostrarEmbarcaciones(tPrefectura pPrefectura){
	int i;
	if( colaVacia(pPrefectura) ) {
		printf("No hay Embarcaciones para visualizar\n");
	} 
	else {
		printf("Embarcacion: \n");
		for( i= pPrefectura.frente; i<= pPrefectura.final; i++ ) {
			printf("%s | ", pPrefectura.nombre[i]);
		}
		printf("\n");
	}
}

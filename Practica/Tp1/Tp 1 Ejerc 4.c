/*En una librería, al no tener más lugar en los estantes, se van acomodando los libros en pilas de hasta 30 
libros como máximo. Escribir un programa que permita:
ingresar los ISBN de los libros
listar los últimos 5 libros apilados
eliminar de la pila los libros a medida que se solicitan
detectar cual es ISBN del libro que está en el TOPE
*/

#include<stdio.h>
#include<stdbool.h>
#include<locale.h>
#include<stdlib.h>

//declaracion de la constante
#define LIBROS 5

//declaracion de dato perzonalizado
typedef int tVector[LIBROS];

//declaracion de la Estructura
typedef struct{
	tVector libreria;
	int tope;
}tPilaLibros;

//declaracion del Prototipado
void iniciarProceso();
void continuarProceso();
void inicializarPilaLibros();
void seleccionEnMenu();
void ingresarISBNLibros();
void apilarLibros(int);
void desapilarLibros();
bool sinLibros(tPilaLibros);
bool maximoLibros(tPilaLibros);
int libroTope(tPilaLibros);
void mostrarPilaLibros();
void mostrarISBNLibroTope();

//declaracion de las variables
tPilaLibros libros;
int continuar;

//declaracion de la funcion principal
int main(){
	setlocale(LC_ALL,"spanish");
	iniciarProceso();
	return 0;
}

//declaracion de los procedimientos 
void iniciarProceso(){
	continuarProceso();
	inicializarPilaLibros();
	while(continuar==1){
		seleccionEnMenu();
		continuarProceso();
	}
}

void continuarProceso(){
	printf("\n\tDesea Ingresar Datos: 1-Si o 2-No: ");
	scanf("%d",&continuar);
}

void inicializarPilaLibros(){
	libros.tope=-1;
	printf("\n\tPila de Libros Inicializada\n");
}

void seleccionEnMenu(){
	int eleccion;
	printf("\n\t\tSelección de Opciones\t");
	printf("\n\t||1.Agregar y Apilar Libros\t\t\t||");
	printf("\n\t||2.Solicitar Libro\t\t\t\t||");
	printf("\n\t||3.Mostrar Si la Pila esta Vacia o No\t\t||");
	printf("\n\t||4.Mostrar Lista de los ultimos 5 Libros\t||");
	printf("\n\t||5.Mostrar Top,Ultimo Libro\t\t\t||");
	printf("\n\t\t\tSeleccione: ");
	scanf("%d",&eleccion);
	system("cls");
	switch(eleccion){
		case 1:
			ingresarISBNLibros();
			break;
		case 2:
			desapilarLibros();
			break;
		case 3:
			sinLibros(libros);
			break;
			
		case 4: 
		 	mostrarPilaLibros();
		 	break;
		case 5:
			mostrarISBNLibroTope();
			break;
	}
}

bool sinLibros(tPilaLibros pLibros){
	if(pLibros.tope==-1){
		printf("\n\tLa pila esta vacia");
	}
	else{
		printf("\n\tLa pila no esta vacia");
	}
	return(pLibros.tope==-1);
}

bool maximoLibros(tPilaLibros pLibros){
	return(pLibros.tope==LIBROS-1);
}

void ingresarISBNLibros(){
	int isbn;
	printf("Ingresar el ISBN del Libro: ");
	scanf("%d",&isbn);
	apilarLibros(isbn);
}

void apilarLibros(int pIsbn){
	if(!maximoLibros(libros)){
		libros.tope+=1;
		libros.libreria[libros.tope]=pIsbn;
		printf("\n\tLibro Apilado");
	}
	else{
		printf("\n\t El Libro no puede ser apilado");
	}
}

int libroTope(tPilaLibros pLibros){
	return(pLibros.libreria[pLibros.tope]);
}

void desapilarLibros(){
	if(!sinLibros(libros)){
		int EliminarLibro = libroTope(libros);
		libros.libreria[libros.tope]=0;
		libros.tope-=1;
		printf("\n\tSe elimino un Libro");
	}
	else{
		printf("\n\tNo hay Libros para quitar\n");
	}
}

void mostrarPilaLibros(){
	int i;
	for(i=0;i<LIBROS;i++){
		if(i>3 && !i==0){
			printf("\n\tEl ISBN del Libro es %d y el numero es %d",libros.libreria[i],i+1);
		}
		
	}	
}

void mostrarISBNLibroTope(){
	printf("\n\t El tope es el Libro con el ISBN %d",libros.libreria[libros.tope]);
}

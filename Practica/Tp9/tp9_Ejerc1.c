/*
Diagramar el árbol de búsqueda binaria que corresponde en cada caso, si sus elementos son insertados
de la siguiente manera: 
a) 54 -72 -25 -10 -15 -5
b) 74 -22 125 -10 -150 35
*/

#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

//declararcion de estructura

typedef struct{
	int numeros;
}tDatosNum;

typedef struct nodoArbol{
	tDatosNum datoNumero;
	struct nodoArbol* hijoIzq;
	struct nodoArbol* hijoDer;
}tArbolNum;

//declarcion de prototipado
void moduloAbarcador();
void permitirProceso();
void continuarProceso();
void crearArbolVacio(tArbolNum**);
bool arbolVacio(tArbolNum*);
void menu();
tDatosNum ingresarNumero();
void insertarValor(tArbolNum**,tDatosNum);
void recorrerEnPreorden( tArbolNum * );
void recorrerEnPostorden( tArbolNum * );
void recorrerEnInorden( tArbolNum * );
bool buscarValor(tArbolNum*,int);
int cantidadNodos(tArbolNum*);
tArbolNum * buscarMin( tArbolNum*);
void eliminarElemento( tArbolNum **, int );


//declaracion de variables globales
tArbolNum* arbolNumerico;
int continuar;

//declaracion de variables globales;
int main(){
	moduloAbarcador();
	return 0;
}

void moduloAbarcador(){
	permitirProceso();
	crearArbolVacio(&arbolNumerico);
	while(continuar==1){
		menu();
		continuarProceso();
	}
}

void permitirProceso(){
	printf("Desea comenzar a trabajar con Arbol:1-SI o 0-NO: ");
	scanf("%d",&continuar);
}

void crearArbolVacio(tArbolNum** pArbol){
	*pArbol = NULL;
	printf("Arbol vacio creado!\n");
}

void continuarProceso(){
	printf("Desea continuar trabajando con Arbol:1-SI o 0-NO: ");
	scanf("%d",&continuar);
}

void menu(){
	tDatosNum dn;
	int eleccion,n;
	printf("\t\t\t\t\t====================");
	printf("\n\t\t\t\t\tSeleccione Su Opción\n");
	printf("\t\t\t\t\t====================\n");
	printf("\n\t||1.Respuesta para saber si el arbol se encuetra vacio.\t\t\t||");
	printf("\n\t||2.Agregar valor.\t\t\t||");
	printf("\n\t||3.Realizar recorrido en forma de PreOrden.\t\t\t||");
	printf("\n\t||4.Realizar recorrido en forma de PosOrden.\t||");
	printf("\n\t||5.Realizar recorrido en forma de InOrden.\t||");
	printf("\n\t||6.Buscar Existencia de Valor.\t\t||");
	printf("\n\t||7.Saber Cantidad de Nodos.\t||");
	printf("\n\t||8.Buscar Valor Min.\t||");
	printf("\n\t||9.Eliminar Valor.\t||");
	printf("\n\t\t\t\t\tSu Elección Es: ");
	scanf("%d",&eleccion);
	system("cls");
	switch(eleccion){
		case 1:
			printf("El arbol esta vacio? %s\n", arbolVacio(arbolNumerico)? "Si se encuentra Vacio":"No no se encuentra Vacio");
			break;
		case 2:
			dn=ingresarNumero();
			insertarValor(&arbolNumerico,dn);
			break;
		case 3:
			recorrerEnPreorden(arbolNumerico);
			break;
		case 4:
			recorrerEnPostorden(arbolNumerico);
			break;
		case 5:
			recorrerEnInorden(arbolNumerico);
			break;
		case 6:
			printf("Existe el: ");
			scanf("%d",&n);
				printf("El valor %d? %s\n",n, buscarValor(arbolNumerico,n)? "Si se encuentra":"No, no se encuentra");
			break;
		case 7:
			printf("Cantidad de nodos: %d\n", cantidadNodos(arbolNumerico));
			break;
		case 8:
			printf("Nodo Min: %d\n", buscarMin(arbolNumerico)->datoNumero.numeros);
			break;
		case 9:
			printf("Eliminar el: ");
			scanf("%d",&n);
			eliminarElemento(&arbolNumerico,n);
			break;
		default:
			printf("\n\tNO EXISTE LA OPCION SELECCIONADA...\n");
			break;	
	}
}

bool arbolVacio(tArbolNum* pArbol){
	return pArbol==NULL;
}

tDatosNum ingresarNumero(){
	tDatosNum valorNumerico;
	printf("Ingresar valor Numerico: ");
	scanf("%d",&valorNumerico.numeros);
	return valorNumerico;
}

void insertarValor(tArbolNum** pArbol,tDatosNum pDato){
	if(arbolVacio(* pArbol)){
	(*pArbol) = (tArbolNum *) malloc(sizeof(tArbolNum));
	if(*pArbol!=NULL){
		(*pArbol)->datoNumero=pDato;
		(*pArbol)->hijoIzq=NULL;
		(*pArbol)->hijoDer = NULL;
	} else {
		printf("No hay memoria disponible!\n");
	}						
	}else{
		if(pDato.numeros<(*pArbol)->datoNumero.numeros){
			// el dato que quiero insertar es menor que el nodo actual
			insertarValor(&((*pArbol)->hijoIzq),pDato );
		}else{
			// el dato que quiero insertar es mayor que el nodo actual
			if(pDato.numeros>(*pArbol)->datoNumero.numeros){
				insertarValor(&((*pArbol)->hijoDer),pDato);	
				// el dato que quiero insertar es igual que el nodo actual
			} else{
				printf("Valor duplicado, no es posible insertar!\n");
			}
		}
	}
}

void recorrerEnPreorden(tArbolNum * pArbol){
	if( pArbol != NULL ){
		printf("%d\n", pArbol->datoNumero.numeros);
		recorrerEnPreorden( pArbol->hijoIzq);
		recorrerEnPreorden( pArbol->hijoDer);
	}
}

void recorrerEnPostorden(tArbolNum * pArbol){
	if( pArbol != NULL ) {
		recorrerEnPostorden( pArbol->hijoIzq);
		recorrerEnPostorden( pArbol->hijoDer);
		printf("%d\n", pArbol->datoNumero.numeros);
	}
}

void recorrerEnInorden(tArbolNum * pArbol){
	if( pArbol != NULL ) {
		recorrerEnInorden( pArbol->hijoIzq);
		printf("%d\n", pArbol->datoNumero.numeros);
		recorrerEnInorden( pArbol->hijoDer);	
	}
}

bool buscarValor(tArbolNum* pArbol,int valorBuscado){
		if( arbolVacio(pArbol)) {
		return false;
	} else {
		if( valorBuscado < pArbol->datoNumero.numeros ) {
			buscarValor( pArbol->hijoIzq,valorBuscado);
		} else {
			if(valorBuscado > pArbol->datoNumero.numeros){
				buscarValor( pArbol->hijoDer,valorBuscado);
			} else {
				// Se encontró un nodo con el código igual al código buscado
				return true;
			}
		}
	}
}

int cantidadNodos(tArbolNum* pArbol){
		if(pArbol != NULL){
		return 1 + cantidadNodos(pArbol->hijoIzq) + cantidadNodos( pArbol->hijoDer);
	}
	return 0;
}

tArbolNum * buscarMin(tArbolNum*pArbol){
		if( arbolVacio(pArbol)) {
		return NULL;
	} else {
		if( !arbolVacio(pArbol->hijoIzq)) {
			return buscarMin( pArbol->hijoIzq);
		}else {
			return pArbol;
		}
	}
}

void eliminarElemento(tArbolNum ** pArbol, int valorEliminar){
		tArbolNum * aux;
		if( arbolVacio(*pArbol)){
		// No existe el nodo que se quiere eliminar
		printf("No existe el elemento que se desea eliminar\n");		
	} else {		
		if( valorEliminar < (*pArbol)->datoNumero.numeros){
			eliminarElemento( &((*pArbol)->hijoIzq) ,valorEliminar);
		} else {
			if( valorEliminar > (*pArbol)->datoNumero.numeros ) {
				eliminarElemento( &((*pArbol)->hijoDer) ,valorEliminar);
			} else {
				// Se encontró el nodo que se desea eliminar
				if( (*pArbol)->hijoIzq== NULL) {
					aux = *pArbol;
					*pArbol = (*pArbol)->hijoDer;
					free(aux);
				} else {
					if( (*pArbol)->hijoDer== NULL) {
						aux = *pArbol;
						*pArbol = (*pArbol)->hijoIzq;
						free(aux);
					} else {
						// significa que el nodo por eliminar tiene 2 hijos
						aux = buscarMin( (*pArbol)->hijoDer);
						(*pArbol)->datoNumero = aux->datoNumero;
						eliminarElemento( &((*pArbol)->hijoDer) , (*pArbol)->datoNumero.numeros);
					} 										
				}
			}
		}	
	}
}

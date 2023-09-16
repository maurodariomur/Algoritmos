//Interfaz 
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

//delcaracion de dato personalizado
typedef char tString[100];

//declaracion de estructura
typedef struct{
	tString arrayLista;
}tDato;

typedef struct nodo{
	tDato dato;
	struct nodo *siguiente;
}tLista;

//declaracion del prototipado
void inicializarLista(tLista**);
bool listaVacia(tLista*);
void agregarPrimeroLista(tDato,tLista**);
void agregarAdelanteLista(tDato,tLista**);
void agregarEnLista(tDato,tLista**);
void eliminarLista(tLista**);
void ingresarEncuestadoPosicion(tDato,tLista**);
void insertarPosicionK(int *,tDato,tLista**);
void eliminarListaPosicion(tLista**);
void eliminarPosicionK(int *,tLista**);
void visualizarLista(tLista*);


//Implementacion
void inicializarLista(tLista ** pLista){
	*pLista=NULL;
	printf("INICIALIZACION DE LA LISTA!...\n");
}

bool listaVacia(tLista * pLista){
	return pLista==NULL;
}

void agregarPrimeroLista(tDato pDatoAgregar,tLista** pLista){
	tLista * nuevoNodo;
	nuevoNodo =(tLista *)malloc(sizeof(tLista));
	nuevoNodo->dato=pDatoAgregar;
	nuevoNodo->siguiente=NULL;
	(*pLista)=nuevoNodo;
	
	printf("Primer elemento insertado! ... \n");
}

void agregarAdelanteLista(tDato pDatoAgregar,tLista** pLista){
	tLista * nuevoNodo;
	nuevoNodo=(tLista*)malloc(sizeof(tLista));
	nuevoNodo->dato = pDatoAgregar;
	nuevoNodo->siguiente = (*pLista);
	(*pLista)=nuevoNodo;
	printf("Elemento insertado! ... \n");
}

void agregarEnLista(tDato pDatoAgregar ,tLista**pLista){
	if(listaVacia((*pLista))){
		agregarPrimeroLista(pDatoAgregar,(pLista));
	} else {
		agregarAdelanteLista(pDatoAgregar,(pLista));
	}
}

void eliminarLista(tLista ** pLista){
	if( !listaVacia( *pLista )) {
		tLista * nodoSuprimir;
		nodoSuprimir = (*pLista);
		(*pLista) = (*pLista)->siguiente;
		printf("Se elimino el producto: %s ... \n", nodoSuprimir->dato.arrayLista);
		free(nodoSuprimir);
		nodoSuprimir = NULL;
	} else {
		printf("No hay productos! ... \n");
	}
}

void ingresarEncuestadoPosicion(tDato pDatoAgregar,tLista**pLista ){
	int n;
	if(listaVacia(*pLista)){
		printf("\n\t¡Lista Vacia!...\n\n");
	}else{
		printf("En que posicion desea Insertar al Encuestado: ");
		insertarPosicionK(&n,pDatoAgregar,(pLista));
	}
}

void insertarPosicionK(int * n,tDato pDatoAgregar,tLista**pLista){
	scanf("%d",n);
	int cont=*n;
	tLista * aux;
	tLista * nuevoNodo;
	int i;	
	aux = (*pLista);
	for( i=1; i<cont-1; i++) {
		aux = aux->siguiente;
	}
	nuevoNodo = ( tLista * ) malloc( sizeof( tLista ) );
	nuevoNodo->dato= pDatoAgregar;
	nuevoNodo->siguiente = aux->siguiente;
	aux->siguiente = nuevoNodo;
	printf("Se inserto %s en la posicion %d! ... \n", pDatoAgregar.arrayLista,*n);	
}

void eliminarListaPosicion(tLista** pLista){
		if(listaVacia(*pLista)){
		printf("\n\tNo hay Elementos para eliminar\n");
	}
	else{
		int posicion;
        printf("\n\tIngrese la posicion del Elemento que desea eliminar: ");
        eliminarPosicionK(&posicion,(pLista));
	}
}

void eliminarPosicionK(int * k,tLista** pLista){
	scanf("%d",k);
	int i, cont = *k;
    tLista *aux;
    tLista * elementElim;   
	aux = (*pLista);
    for(i=1;i<cont-1;i++){
        aux=aux->siguiente;
    }
	elementElim=aux->siguiente;
    aux->siguiente=elementElim->siguiente;
    printf("\nEl elemento %s Fue eliminado de la lista\n",elementElim->dato.arrayLista);
    free(elementElim);
    elementElim = NULL;
}

void visualizarLista(tLista * pLista){
	tLista * aux;	
	aux = pLista;
	if( !listaVacia( aux ) ) {
		while( aux != NULL ) {
			printf("||%s||\n", aux->dato.arrayLista);
			aux = aux->siguiente;
		}
		printf("\n");
	} else {
		printf("Lista sin elementos \n");
	}
}



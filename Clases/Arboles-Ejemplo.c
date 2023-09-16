#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/* Declaración de tipos de datos personalizados */
typedef char tString [25];

typedef struct {
	int codigo;
	tString descripcion;
} tDatos;

typedef struct nodoArbol {
	tDatos datos;
	struct nodoArbol * hijoIzquierdo;
	struct nodoArbol * hijoDerecho;
}tArbol;

/* Declaración de prototipos */
void crearArbolVacio( tArbol ** );
bool arbolVacio( tArbol * );
void insertarElemento( tArbol **, tDatos );
void recorrerEnPreorden( tArbol * );
void recorrerEnPostorden( tArbol * );
void recorrerEnInorden( tArbol * );
bool buscarElemento( tArbol *, int );
int cantidadNodos( tArbol * );
tArbol * buscarMin( tArbol * );
void eliminarElemento( tArbol **, int );

/* Declaración de variables */
tArbol * arbol;

/* Bloque principal */
int main() {
	tDatos datos;
	
	crearArbolVacio( &arbol );
	printf("El arbol esta vacio? %s\n", arbolVacio(arbol) == true ? "si" : "no"   );
	
	datos.codigo = 74;
	strcpy(datos.descripcion, "descripcion 1");	
	insertarElemento( &arbol, datos);
	
	datos.codigo = -22;
	strcpy(datos.descripcion, "descripcion 2");	
	insertarElemento( &arbol, datos);
		
	datos.codigo = 125;
	strcpy(datos.descripcion, "descripcion 3");	
	insertarElemento( &arbol, datos);
	
	
	printf("El arbol esta vacio? %s\n", arbolVacio(arbol) == true ? "si" : "no"   );
	
	printf("Preorden\n");
	recorrerEnPreorden( arbol );
	
	printf("Postorden\n");
	recorrerEnPostorden( arbol );
	
	printf("Inorden\n");
	recorrerEnInorden( arbol );
	
	printf("Existe el 74? %d\n", buscarElemento( arbol, 74));
	printf("Existe el 100? %d\n", buscarElemento( arbol, 100));
	
	printf("Cantidad de nodos: %d\n", cantidadNodos( arbol ));
	
	printf("Nodo Min: %d\n", buscarMin(arbol)->datos.codigo);
	
	eliminarElemento( &arbol, 125 );
	recorrerEnInorden( arbol );
	
	return 0;
}

/* Implementación de funciones */
void crearArbolVacio( tArbol ** pArbol ) {
	*pArbol = NULL;
	printf("Arbol vacio creado!\n");
}

bool arbolVacio( tArbol * pArbol ) {
	return pArbol == NULL;
}

void insertarElemento( tArbol ** pArbol, tDatos pDatos ) {
	if( arbolVacio( * pArbol ) ) {
		( *pArbol ) = ( tArbol * ) malloc( sizeof( tArbol ));
		if( *pArbol != NULL) {
			( *pArbol )->datos = pDatos;
			( *pArbol )->hijoIzquierdo = NULL;
			( *pArbol )->hijoDerecho = NULL;
		} else {
			printf("No hay memoria disponible!\n");
		}						
	} else {
		if( pDatos.codigo < (*pArbol)->datos.codigo ) {
			// el dato que quiero insertar es menor que el nodo actual
			insertarElemento(  &((*pArbol)->hijoIzquierdo)  , pDatos  );
		} else {
			// el dato que quiero insertar es mayor que el nodo actual
			if( pDatos.codigo > (*pArbol)->datos.codigo ) {
				insertarElemento(  &((*pArbol)->hijoDerecho)  , pDatos  );	
				// el dato que quiero insertar es igual que el nodo actual
			}  else {
				printf("Valor duplicado, no es posible insertar!\n");
			}
		}
	}
}

void recorrerEnPreorden( tArbol * pArbol ) {
	if( pArbol != NULL ) {
		printf("%d - %s\n", pArbol->datos.codigo, pArbol->datos.descripcion );
		recorrerEnPreorden( pArbol->hijoIzquierdo );
		recorrerEnPreorden( pArbol->hijoDerecho );
	}
}

void recorrerEnPostorden( tArbol * pArbol ) {
	if( pArbol != NULL ) {
		recorrerEnPostorden( pArbol->hijoIzquierdo );
		recorrerEnPostorden( pArbol->hijoDerecho );
		printf("%d - %s\n", pArbol->datos.codigo, pArbol->datos.descripcion );
	}
}

void recorrerEnInorden( tArbol * pArbol ) {
	if( pArbol != NULL ) {
		recorrerEnInorden( pArbol->hijoIzquierdo );
		printf("%d - %s\n", pArbol->datos.codigo, pArbol->datos.descripcion );
		recorrerEnInorden( pArbol->hijoDerecho );	
	}
}

bool buscarElemento( tArbol * pArbol, int pCodigo ) {
	if( arbolVacio(pArbol)) {
		return false;
	} else {
		if( pCodigo < pArbol->datos.codigo ) {
			buscarElemento( pArbol->hijoIzquierdo,  pCodigo);
		} else {
			if( pCodigo > pArbol->datos.codigo ) {
				buscarElemento( pArbol->hijoDerecho,  pCodigo);
			} else {
				// Se encontró un nodo con el código igual al código buscado
				return true;
			}
		}
	}
}

int cantidadNodos( tArbol * pArbol ) {
	// siguiendo el recorrido en preorden
	if( pArbol != NULL) {
		return 1 + cantidadNodos( pArbol->hijoIzquierdo) + cantidadNodos( pArbol->hijoDerecho);
	}	
}

tArbol * buscarMin( tArbol * pArbol ) {
	if( arbolVacio(pArbol)) {
		return NULL;
	} else {
		if( !arbolVacio(pArbol->hijoIzquierdo)) {
			return buscarMin( pArbol->hijoIzquierdo );
		}else {
			return pArbol;
		}
	}
		
}

void eliminarElemento( tArbol ** pArbol, int pCodigo ) {
	tArbol * aux;
	
	if( arbolVacio(*pArbol)) {
		// No existe el nodo que se quiere eliminar
		printf("No existe el elemento que se desea eliminar\n");		
	} else {		
		if( pCodigo < (*pArbol)->datos.codigo ) {
			eliminarElemento( &((*pArbol)->hijoIzquierdo) , pCodigo);
		} else {
			if( pCodigo > (*pArbol)->datos.codigo ) {
				eliminarElemento( &((*pArbol)->hijoDerecho) , pCodigo);
			} else {
				// Se encontró el nodo que se desea eliminar
				if( (*pArbol)->hijoIzquierdo == NULL) {
					aux = *pArbol;
					*pArbol = (*pArbol)->hijoDerecho;
					free(aux);
				} else {
					if( (*pArbol)->hijoDerecho == NULL) {
						aux = *pArbol;
						*pArbol = (*pArbol)->hijoIzquierdo;
						free(aux);
					} else {
						// significa que el nodo por eliminar tiene 2 hijos
						aux = buscarMin( (*pArbol)->hijoDerecho  );
						(*pArbol)->datos = aux->datos;
						eliminarElemento( &((*pArbol)->hijoDerecho) , (*pArbol)->datos.codigo );
					} 										
				}
			}
		}	
	}
}


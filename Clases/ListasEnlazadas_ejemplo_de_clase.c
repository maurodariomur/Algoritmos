#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/* Declaración de tipos de datos personalizados */
typedef char tString[25];

typedef struct {
	int codigo;
	tString descripcion;
}tDato;

typedef struct nodo {
	tDato dato;
	struct nodo * siguiente;
} tLista;

/* Declaración de prototipos */
void inicializarLista();
bool listaVacia( tLista * );

void insertarPrimerProducto( tDato );
void insertarProductoAdelante( tDato );
void insertarProducto( tDato );

void eliminarPrimerProducto();

void visualizarProductos( tLista * );

void insertarProductoPos( tDato, int );

void eliminarProductoPos( int );

int cantidadNodos( tLista * );

/* Declaración de variables */
tLista * listaProductos;

/* Bloque principal */
int main() {
	tDato producto;
		
	inicializarLista();
	
	producto.codigo = 895;
	strcpy( producto.descripcion, "doritos" );
	
	insertarProducto(producto);
	
	producto.codigo = 794;
	strcpy( producto.descripcion, "kit kat" );
	
	insertarProducto(producto);
	
	producto.codigo = 125;
	strcpy( producto.descripcion, "alfajor" );
	
	insertarProducto(producto);
	
	visualizarProductos( listaProductos );
	
	printf("\tCantidad de nodos: %d\n", cantidadNodos(listaProductos));
	
	
	producto.codigo = 304;
	strcpy( producto.descripcion, "chocolinas" );
	
	insertarProductoPos( producto, 2 );
	
	printf("\tCantidad de nodos: %d\n", cantidadNodos(listaProductos));
	
	visualizarProductos( listaProductos );
				
	eliminarProductoPos( 3 );
	
	visualizarProductos( listaProductos );
	
	eliminarPrimerProducto();
	
	visualizarProductos( listaProductos );
	
	return 0;
}

/* Implementación de funciones */

void inicializarLista() {
	listaProductos = NULL;
	printf("Lista inicializada ... \n");
}

bool listaVacia( tLista * pListaProductos )  {
	return pListaProductos == NULL;
}

void insertarPrimerProducto( tDato datoProducto )  {
	tLista * nuevoNodo;
	
	/* Se reserva memoria para el nuevo nodo y se asigna esa memoria al puntero */
	nuevoNodo = ( tLista * ) malloc(sizeof( tLista ));
	
	/* Se asigna valores al componente correspondiente al dato */
	nuevoNodo->dato = datoProducto;
	
	/* Se asigna una dirección al componente correspondiente al siguiente nodo */
	nuevoNodo->siguiente = NULL;
	
	listaProductos = nuevoNodo;
	
	printf("Primer elemento insertado! ... \n");
	
}

void insertarProductoAdelante( tDato datoProducto )  {
	tLista * nuevoNodo;
	
	/* Se reserva memoria para el nuevo nodo y se asigna esa memoria al puntero */
	nuevoNodo = ( tLista * ) malloc(sizeof( tLista ));
	
	/* Se asigna valores al componente correspondiente al dato */
	nuevoNodo->dato = datoProducto;
	
	/* Se asigna una dirección al componente correspondiente al siguiente nodo */
	nuevoNodo->siguiente = listaProductos;
	
	/* Como nuevoNodo tiene la lista completa entonces le asigno la misma memoria a la lista goblal */ 
	listaProductos = nuevoNodo;
	
	printf("Elemento insertado! ... \n");
	
}

void insertarProducto( tDato datoProducto )  {
	if( listaVacia( listaProductos ) ) {
		insertarPrimerProducto( datoProducto );
	} else {
		insertarProductoAdelante( datoProducto );
	}
}

void eliminarPrimerProducto()  {
	if( !listaVacia( listaProductos )) {
		/* Es posible eliminar el primer nodo */
		
		tLista * nodoSuprimir;
		
		nodoSuprimir = listaProductos;
	
		listaProductos = listaProductos->siguiente;
		
		printf("Se elimino el producto: %s ... \n", nodoSuprimir->dato.descripcion);
		
		free(nodoSuprimir);
		
		nodoSuprimir = NULL;
		
	} else {
		printf("No hay productos! ... \n");
	}		
}

void visualizarProductos( tLista * pLista )  {
	tLista * aux;
	
	aux = pLista;
	
	if( !listaVacia( aux ) ) {
		
		printf("\nProductos disponibles\n");
		printf("---------------------\n");
		printf("Codigo | Descripcion\n");
		
		while( aux != NULL ) {
			printf("%d | %s\n", aux->dato.codigo, aux->dato.descripcion );
			aux = aux->siguiente;
		}
		printf("\n");
		
	} else {
		printf("Lista sin productos\n");
	}
		
}

void insertarProductoPos( tDato datoProducto, int pos )  {
	/* 	Completar para que si pos==1 entonces se invoque a insertarProducto()
		sino, (si pos > 1 y pos es menor o igual a la cantidad de nodos + 1) ejecutar este código 
		En el caso de que pos sea >= cantidad de nodos + 1 entonces emitir un mensaje que no es posible insertar */
	
	tLista * aux;
	tLista * nuevoNodo;
	int i;
	
	aux = listaProductos;
	
	/* 	Nos desplazamos hasta el nodo que se encuentra en la posición anterior 
		a la posición en la cual queremos insertar */
	for( i=1; i<pos-1; i++) {
		aux = aux->siguiente;
	}
	
	/* Reservar memoria para el nuevo nodo */
	nuevoNodo = ( tLista * ) malloc( sizeof( tLista ) );
	
	nuevoNodo->dato = datoProducto;
	nuevoNodo->siguiente = aux->siguiente;
	
	aux->siguiente = nuevoNodo;
	
	printf("Se inserto %s en la posicion %d! ... \n", datoProducto.descripcion, pos);	
}

void eliminarProductoPos( int pos )  {
	/*  Completar para que si pos==1 entonces se invoque a eliminarPrimerProducto(),
		caso contrario ejecutar este código	*/
		
	if( !listaVacia( listaProductos ) ) { 
	
		if( pos == 1 ) {
			eliminarPrimerProducto();
		} else {
			// completar para validar que pos > 1 && pos <= cantidadNodos
			
			tLista * aux;
			tLista * nodoSuprimir;
			int i;
			
			aux = listaProductos;
			
			/* 	Nos desplazamos hasta el nodo que se encuentra en la posición anterior 
				a la posición en la cual queremos eliminar */
			for( i=1; i<pos-1; i++) {
				aux = aux->siguiente;
			}
			
			nodoSuprimir = aux->siguiente;
			
			aux->siguiente = nodoSuprimir->siguiente;
			
			printf("Se elimino %s de la posicion %d! ... \n", nodoSuprimir->dato.descripcion, pos);
			
			free(nodoSuprimir);
			
			nodoSuprimir = NULL;
		}		
	} else {
		printf("No hay productos! ... \n");
	}
	
	
	
}

int cantidadNodos( tLista * pLista ) {
		int cantNodos = 0;
		
		if( ! listaVacia( pLista ) ) {
			tLista * aux;
				
			aux = pLista;
			
			while( aux != NULL ) {
				cantNodos++;
				aux = aux->siguiente;
			}	
						
		}		
		
		return cantNodos;		
}
	
	



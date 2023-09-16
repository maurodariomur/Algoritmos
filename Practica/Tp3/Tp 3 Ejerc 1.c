/*Crear un tipo de dato tListaProductos para un nodo que permita almacenar los siguientes datos de un 
producto: codProducto, descripción, precio unitario. Luego, declarar un puntero a una variable de ese tipo, 
y crear el primer nodo de la lista a partir del ingreso de datos por teclado. Por último, mostrar los datos 
del primer nodo almacenado.
*/

#include <stdio.h>
#include<locale.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

//declaracion de Dato Personalizado
typedef char tString[50];

//declaracion de Estructuras
typedef struct {
	tString descripcion;
	int codProducto;
	float precioUnitario;
}tListaProductos;

typedef struct nodo {
	tListaProductos productos;
	struct nodo * siguiente;
} tLista;

//Declaracion del Prototipado
void iniciarProceso();
void continuarProceso();
void inicializarLista();
void seleccionMenu();
bool listaVacia(tLista *);
void ingresarDatosProd(tLista *);
void insertarProductos();
void eliminarPrimerProducto();
void insertarProdPosicion();
void insertarProdK(int *);
void eliminarProdPosicion();
void eliminarProdK(int *);
void visualizarProductos(tLista *);


//declaracion de Variables
tLista * lista;
int continuar;

//declaracion funcion principal
int main() {
	setlocale(LC_ALL,"spanish");
	iniciarProceso();
	return 0;
}

//implementacion de funciones
void iniciarProceso(){
	continuarProceso();
	inicializarLista();
	while(continuar==1){
		seleccionMenu();
		continuarProceso();
	}
}

void continuarProceso(){
	printf("\n\tDesea Agregar Datos: 1-SI o 0-NO: ");
	scanf("%d",&continuar);
}


void inicializarLista() {
	lista = NULL;
	printf("Lista inicializada ... \n");
}

void seleccionMenu(){
	int eleccion;
		printf("\t\t\t\t\t====================");
	printf("\n\t\t\t\t\tSeleccione Su Opción\n");
	printf("\t\t\t\t\t====================\n");
	printf("\n\t||1.Insertar un producto en la lista.\t\t\t\t\t\t||");
	printf("\n\t||2.Insertar un producto en una determinada posición dentro de la lista.\t||");
	printf("\n\t||3. Eliminar el primer producto de la lista.\t\t\t\t\t||");
	printf("\n\t||4. Eliminar un producto de una determinada posición de la lista.\t\t||");
	printf("\n\t||5. Visualizar todos los datos de los productos que están en la lista.\t\t||");
	printf("\n\t\t\t\t\tSu Elección Es: ");
	scanf("%d",&eleccion);
	system("cls");
	switch(eleccion){
		case 1:
			insertarProductos();
			break;
		case 2:
			insertarProdPosicion();
			break;
		case 3:
			eliminarPrimerProducto();
			break;
		case 4:
			eliminarProdPosicion();
			break;
		case 5:
			visualizarProductos(lista);
			break;
		default:
			printf("\n\tSu Opcion no existe\n");
			break;
	}
}

bool listaVacia(tLista * pLista){
	return(pLista==NULL);
}

void ingresarDatosProd(tLista * pLista){
	printf("Ingrese codigo del Producto: ");
	scanf("%d",&pLista->productos.codProducto);
	printf("Ingrese descripcion del Producto: ");
	fflush(stdin);
	scanf("%[^\n]s",&pLista->productos.descripcion);
	printf("Ingrese el precio unitario del Producto: ");
	scanf("%f",&pLista->productos.precioUnitario);
}

void insertarProductos(){
 // Se crea el nodo que se va a agregar;
        tLista *nuevoNodo;
    // Se asigna un espacio de memoria el nodo 
        nuevoNodo = (tLista *) malloc(sizeof(tLista));
    // Se asignan los valores al dato
        ingresarDatosProd(nuevoNodo);
    // Se identifica si es el primer nodo Ã³ se agrega adelante
        if(lista==NULL){
            nuevoNodo->siguiente = NULL;
        }else{
            nuevoNodo->siguiente = lista;
        }
    // Acomodamos la lista para apuntar al nuevo nodo 
        lista = nuevoNodo;
        printf("\nProducto Insertado con exito!\n\n");
}

void eliminarPrimerProducto(){
	if(listaVacia(lista)){
		printf("No hay productos para eliminar");
	}
	else{
		tLista * productoElim;
		productoElim=lista;
		lista=lista->siguiente;
		printf("Producto %d con descripcion %s fue eliminado",productoElim->productos.codProducto,productoElim->productos.descripcion);
		free(productoElim);
		productoElim=NULL;
	}
}

void insertarProdPosicion(){
	int posicionInsert;
	printf("En que posicion desea insertar el Producto: ");
	insertarProdK(&posicionInsert);
}

void insertarProdK(int * k){
	scanf("%d",k);
	int cont=*k;
	tLista * aux;
	tLista * nuevoNodo;
	
	int i;
	aux=lista;
	for(i=1;i<cont-1;i++){
		aux=aux->siguiente;
	}
	nuevoNodo=(tLista	*) malloc(sizeof(tLista));
    ingresarDatosProd(nuevoNodo);
    nuevoNodo->siguiente = aux->siguiente;
    aux->siguiente = nuevoNodo;
    printf("\nProducto insertado en la posicion %d\n", *k);
}

void eliminarProdPosicion(){
	if(listaVacia(lista)){
		printf("No hay elementos para eliminar");
	}
	else{
		int posicion;
        printf("\n\nIngrese la posicion del producto que desea eliminar: ");
        eliminarProdK(&posicion);
	}
}

void eliminarProdK(int * k){
	scanf("%d",k);
	int i, cont = *k;
    tLista *aux;
    tLista *productoElim;
        
	aux = lista;
    for(i=1;i<cont-1;i++){
        aux=aux->siguiente;
    }
    productoElim = aux->siguiente;
    aux->siguiente=productoElim->siguiente;
    printf("\nEl producto %s fue eliminado de la lista\n", productoElim->productos.descripcion);
    free(productoElim);
    productoElim= NULL;
}

 void visualizarProductos(tLista *pLista){
    tLista *auxilar;
    auxilar=pLista;
    if(listaVacia(auxilar)){
        printf("No hay prductos para mostrar\n\n");
    }
	else{
        printf("\n\n\t\t***Productos en lista***\n\n");
        while(auxilar != NULL){
            printf("  ID: %d\t || Producto: %s\t || Precio: %.2f\n", auxilar->productos.codProducto, auxilar->productos.descripcion,auxilar->productos.precioUnitario);
            auxilar = auxilar->siguiente;
        } printf("\n\n");
    }
}

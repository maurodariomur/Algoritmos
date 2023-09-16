/*Desarrollar un programa para la gestión de las ventas de un supermercado mediante la implementación 
de una pila. Cada nodo deberá contener los siguientes datos asociados a un producto: código del producto, 
código de rubro, cantidad, precio unitario y descripción. Además de programar todas las operaciones 
básicas, se solicita:
a) Escribir una función que calcule y retorne el monto total recaudado.
b) Implementar un menú principal que contenga todas las operaciones disponibles
*/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

//declaracion de la estructura
 typedef char tString [50];
 
typedef struct{
	int codProducto;
	int codRubro;
	int cantidad;
	float precioUni;
	tString descripcion;
 }tProducto;
 
typedef struct nodo{
	tProducto producto;
	struct nodo * siguiente;
 }tPilaProduct;
 
//declaracion del prototipado
void moduloAbarcador();
void iniciarProceso();
void continuarProceso();
void inicializarPila();
void seleccionEnMenu();
bool pilaVacia(tPilaProduct *);
tProducto ingresarDatosProductos();
void apilarProductos(tProducto);
void desapilarProductos();
tPilaProduct *tope(tPilaProduct *);
float calcularTotalRecaudado(tPilaProduct *);
void mostrarTotalRecaudado(tPilaProduct *);
void mostrarProductosPila(tPilaProduct *);
void mostrarTopePila();

//declaracion de variables globales
tPilaProduct * pila;
int continuar;

//declaracion de la funcion principal
int main(){
	setlocale(LC_ALL, "spanish"); 
	moduloAbarcador();
	return 0;
}

//desarrollo de los modulos
void moduloAbarcador(){
	iniciarProceso();
	inicializarPila();
	while(continuar==1){
		seleccionEnMenu();
		continuarProceso();
	}
}

void iniciarProceso(){
	printf("\n\tDesea Ingresar Datos,1-SI o 0-NO: ");
	scanf("%d",&continuar);
}

void continuarProceso(){
	printf("\n\tDesea continuar con el proceso,1-SI o 0-NO: ");
	scanf("%d",&continuar);
}

void inicializarPila(){
	pila=NULL;
	printf("\n\tPila Inicializada\n");
}

void seleccionEnMenu(){
	tProducto p;
	int eleccion;
	printf("\t\t\t\t\t====================");
	printf("\n\t\t\t\t\tSeleccione Su Opción\n");
	printf("\t\t\t\t\t====================\n");
	printf("\n\t||1.Insertar producto en la Pila.\t\t\t   ||");
	printf("\n\t||2.Eliminar producto en de la Pila.\t\t\t   ||");
	printf("\n\t||3.Mostrar Tope Pila.\t\t\t\t\t   ||");
	printf("\n\t||4.Visualizar total Recaudado de Los Productos.\t   ||");
	printf("\n\t||5.Visualizar todos los datos de los Productos de la Pila.||");
	printf("\n\t\t\t\t\tSu Elección Es: ");
	scanf("%d",&eleccion);
	system("cls");
	switch(eleccion){
		case 1:
			p=ingresarDatosProductos();
			apilarProductos(p);		
			break;	
		case 2:
			desapilarProductos();
			break;
		case 3:
			mostrarTopePila();
			break;
		case 4:
			mostrarTotalRecaudado(pila);
			break;
		case 5:
			mostrarProductosPila(pila);
			break;
		default:
			printf("\n\tNO EXISTE LA OPCION SELECCIONADA...,disculpeme hasta aca llego mi cabeza\n");
			break;
	}
}

bool pilaVacia(tPilaProduct * pPila){
	return(pPila==NULL);
}
tProducto ingresarDatosProductos(){
	tProducto datoProduct;
	printf("Ingresar Codigo Del Producto: ");
	scanf("%d",&datoProduct.codProducto);
	printf("Ingresar Codigo de Rubro: ");
	scanf("%d",&datoProduct.codRubro);
	printf("Ingresar Cantidad De Productos: ");
	scanf("%d",&datoProduct.cantidad);
	printf("Ingresar precio Unitario: ");
	scanf("%f",&datoProduct.precioUni);
	printf("Ingresar Descripcion del Producto: ");
	fflush(stdin);
	scanf("%[^\n]s",&datoProduct.descripcion);
	return datoProduct;
}

void  apilarProductos(tProducto pDatProduct){
	tPilaProduct * nuevoNodo;
	nuevoNodo = ( tPilaProduct * ) malloc( sizeof( tPilaProduct));
	nuevoNodo->producto = pDatProduct;
	nuevoNodo->siguiente = pila; 
	pila = nuevoNodo;
	printf("Producto insertado!\n");
}

void desapilarProductos(){
tPilaProduct * nodoSuprimir;	
	if( !pilaVacia( pila ) ) {	
	nodoSuprimir = pila;
	pila =pila->siguiente;	
	printf( "\n\t\t\tProducto eliminado:\n\n ||Codigo Producto:%d||Codigo Rubro: %d||Cantidad Productos: %d||Precio Unirario: %.2f||Descripción:%s||\n", nodoSuprimir->producto.codProducto,nodoSuprimir->producto.codRubro,nodoSuprimir->producto.cantidad,nodoSuprimir->producto.precioUni,nodoSuprimir->producto.descripcion);	
	free(nodoSuprimir);		
	nodoSuprimir = NULL;			
	}else{
		printf("No hay Productos para eliminar!\n");
	}
}

tPilaProduct * tope( tPilaProduct * pPila){
	return pPila;
}
void mostrarTotalRecaudado(tPilaProduct *pPila){
    if(!pilaVacia(pPila)){
        printf("\n\tEl total recaudado es de %.2f\n\n",calcularTotalRecaudado(pPila));
    }else{
        printf("\n\t*** No hay datos de productos ***\n\n");
        }
}
    
float calcularTotalRecaudado(tPilaProduct * pPila){
	float totalRecaudado = 0;
	float totalProductos=0;
    tPilaProduct *aux;
    aux = pPila;
    while(aux != NULL){
    	totalProductos=aux->producto.cantidad*aux->producto.precioUni; 
		totalRecaudado+=totalProductos;
		aux=aux->siguiente;
    }
   
    return(totalRecaudado);
}

void mostrarTopePila(){
	if(tope(pila)){
		printf("||Codigo Producto:%d||Codigo Rubro: %d||Cantidad Productos: %d||Precio Unitario: %.2f||Descripción:%s||\n",pila->producto.codProducto,pila->producto.codRubro,pila->producto.cantidad,pila->producto.precioUni,pila->producto.descripcion);	
	}else{
		printf("No hay tope para visualizar ...\n");
	}

}

void mostrarProductosPila(tPilaProduct * pPila){
	tPilaProduct * aux;	
	aux = pPila;
	if( !pilaVacia( pPila )) {
		printf("\n\t\tLos Productos son...\n");
		while( aux != NULL ) {
		printf("||Codigo Producto:%d||Codigo Rubro: %d||Cantidad Productos: %d||Precio Unitario: %.2f||Descripción:%s||\n", aux->producto.codProducto,aux->producto.codRubro,aux->producto.cantidad,aux->producto.precioUni,aux->producto.descripcion);
		aux = aux->siguiente;
		}	
	} else {
		printf("No hay Productos para visualizar ...\n");
	}
}

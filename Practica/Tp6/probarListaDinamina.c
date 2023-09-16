#include "listaDinamica.h"

void moduloAbarcador();
void permitirProceso();
void continuarProceso();
void inicializar();
void menu();
tDato ingresarDatosLista();
void listado(tDato);
void insertarCualquierPosicion();
void eliminarNombre();
void eliminarEnPosicion();
void mostrarLista();

tLista * listaClientes;
tDato cliente;

int acceso;

int main(){
	moduloAbarcador();
	return 0;
}

void moduloAbarcador(){
	permitirProceso();
	inicializar();
	while(acceso==1){
		menu();
		continuarProceso();
	}
}

void permitirProceso(){
	printf("Desea Agregar Datos:1-SI o 0-NO: ");
	scanf("%d",&acceso);
}

void continuarProceso(){
	printf("Desea continuar agregando Datos:1-SI o 0-NO: ");
	scanf("%d",&acceso);
}

void inicializar(){
	inicializarLista(&listaClientes);
}

void menu(){
	int eleccion;
	tDato c;
	printf("\t\t\t\t\t====================");
	printf("\n\t\t\t\t\tSeleccione Su Opción\n");
	printf("\t\t\t\t\t====================\n");
	printf("\n\t||1.Insertar elemento al principio.\t\t\t\t\t\t||");
	printf("\n\t||2.Insertar elemento en una determinada posición dentro de la lista.\t\t||");
	printf("\n\t||3.Eliminar el primer elemento de la lista.\t\t\t\t\t||");
	printf("\n\t||4.Eliminar un eliminar de una determinada posición de la lista.\t\t||");
	printf("\n\t||5.Visualizar todos los datos de los elementos que están en la lista.\t\t||");
	printf("\n\t\t\t\t\tSu Elección Es: ");
	scanf("%d",&eleccion);
	system("cls");
	switch(eleccion){
		case 1:
			c=ingresarDatosLista();
			listado(c);	
			break;
		case 2:
			insertarCualquierPosicion(c);
			break;	
		case 3:
			eliminarNombre();
			break;
		case 4:
			eliminarEnPosicion();
			break;
		case 5:
			mostrarLista();
			break;
		default:
			printf("\n\tNO EXISTE LA OPCION SELECCIONADA...\n");
			break;
	}
}

tDato ingresarDatosLista(){
	tDato clienteLocal;
	printf("Ingresar nombre del Cliente: ");
	fflush(stdin);
	scanf("%[^\n]s",&clienteLocal.arrayLista);
	return clienteLocal;
}

void listado(tDato clienteLocal){
	agregarEnLista(clienteLocal,&listaClientes);
}

void insertarCualquierPosicion(tDato clienteLocal){
	ingresarEncuestadoPosicion(ingresarDatosLista(),&listaClientes);
}

void eliminarNombre(){
	eliminarLista(&listaClientes);	
}

void eliminarEnPosicion( ){
	eliminarListaPosicion(&listaClientes);
}

void mostrarLista(){
	visualizarLista(listaClientes); 
}


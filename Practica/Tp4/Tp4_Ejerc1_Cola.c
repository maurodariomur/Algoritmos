/*
1. En la recepción de un banco, la recepcionista entrega un ticket con el número de atención a cada persona. 
El sistema almacena los siguientes datos de cada turno: número de turno, nombre del cliente y motivo (1.
transacción 2. consulta). Además de las operaciones básicas para el manejo de la cola con punteros, se 
solicita disponer de:
a) una función que devuelva la cantidad de personas que están esperando un turno para realizar una 
“transacción”
b) una función que devuelva la cantidad de personas que están esperando un turno para realizar una 
“consulta”
c) un listado que permita visualizar el orden, nombre y motivo de cada persona en la cola.
d) Implementar un menú principal que contenga todas las operaciones disponibles.
*/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

//declaracion de la estructura
typedef char tString [50];

typedef struct{
	int numeroTurno;	
	tString nombre;
	int motivo;
 }tCliente;
 
typedef struct nodo{
	tCliente clienteBanco;
	struct nodo * siguiente;
}tClientes;
 
typedef struct {
	tClientes * principio;
	tClientes * final;
}tCola;
 
//declaracion del prototipado
void moduloAbarcador();
void iniciarProceso();
void continuarProceso();
void inicializarCola();
void seleccionEnMenu();
bool colaVacia(tCola);
tCliente ingresarDatosCliente();
void pushCliente(tCliente);
void popCliente();
void mostrarClientes(tCola);
tClientes * primerCliente(tCola);
void mostrarPrimerCliente();
void mostrarTotalClientes1(tCola);
int calcularTotalClientes1(tCola);
void mostrarTotalClientes2(tCola);
int calcularTotalClientes2(tCola);

//declaracion de variables globales
tCola colaClientes;
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
	inicializarCola();
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

void inicializarCola(){
	colaClientes.principio=NULL;
	colaClientes.final=NULL;
	printf("\n\tCola Inicializada\n");
}

void seleccionEnMenu(){
	tCliente c;
	int eleccion;
	printf("\t\t\t\t\t====================");
	printf("\n\t\t\t\t\tSeleccione Su Opción\n");
	printf("\t\t\t\t\t====================\n");
	printf("\n\t||1.Insertar Cliente en la Cola.\t\t\t||");
	printf("\n\t||2.Eliminar Cliente en la Cola.\t\t\t||");
	printf("\n\t||3.Mostrar Primer Cliente en la Cola.\t\t\t||");
	printf("\n\t||4.Mostrar Total Clientes Transacciones en la Cola.\t||");
	printf("\n\t||5.Mostrar Total Clientes Consultas en la Cola.\t||");
	printf("\n\t||6.Vizualizar Datos De Clientes en la Cola.\t\t||");
	printf("\n\t\t\t\t\tSu Elección Es: ");
	scanf("%d",&eleccion);
	system("cls");
	switch(eleccion){
		case 1:
			c=ingresarDatosCliente();
			pushCliente(c);		
			break;	
		case 2:
			popCliente();
			break;
		case 3:
			mostrarPrimerCliente();
			break;
		case 4:
			mostrarTotalClientes1(colaClientes);
			break;
		case 5:
			mostrarTotalClientes2(colaClientes);
			break;
		case 6:
			mostrarClientes(colaClientes);
			break;
		default:
			printf("\n\tNO EXISTE LA OPCION SELECCIONADA...\n");
			break;
	}
}

bool colaVacia(tCola pColaClientes){
	return(pColaClientes.principio==NULL && pColaClientes.final==NULL);
}
tCliente ingresarDatosCliente(){
	tCliente datoCliente;
	printf("Ingresar numero de Turno: ");
	fflush(stdin);
	scanf("%d",&datoCliente.numeroTurno);
	printf("Ingresar Nombre Del Cliente: ");
	fflush(stdin);
	scanf("%[^\n]s",&datoCliente.nombre);
	printf("Ingresar motivo del Turno,1.transacción o 2. consulta: ");
	scanf("%d",&datoCliente.motivo);
	return datoCliente;
}

void pushCliente(tCliente pDataCustomer){
	tClientes * nuevoNodo;
	nuevoNodo =(tClientes *) malloc(sizeof(tClientes));	
	nuevoNodo->clienteBanco = pDataCustomer;
	nuevoNodo->siguiente = NULL;
	if(colaVacia(colaClientes)){
		colaClientes.principio = nuevoNodo;
		colaClientes.final = nuevoNodo;
	} else {
		colaClientes.final->siguiente = nuevoNodo;
		colaClientes.final = nuevoNodo;
	}
	printf("\n\tCliente insertado! \n");
}

void popCliente(){
	if(colaVacia(colaClientes)) {
		printf("\n\tNo hay clientes para eliminar\n");
	} else {
		tClientes * clienteSup;
		clienteSup = colaClientes.principio;
		if( colaClientes.principio == colaClientes.final ) {
			inicializarCola();
		} else {
			colaClientes.principio = clienteSup->siguiente;			
		}
		printf("\n\t||Nro Turno:%d||Nombre:%s||Motivo:%d||\n", clienteSup->clienteBanco.numeroTurno,clienteSup->clienteBanco.nombre,clienteSup->clienteBanco.motivo);
		free(clienteSup);
		clienteSup = NULL;		
	} 	
}

void mostrarClientes(tCola pColaClientes){
	if(colaVacia(pColaClientes)) {
		printf("No hay clientes para visualizar! \n");
	} else {
		tClientes * aux;
		aux = pColaClientes.principio;
		
		printf("\n\t\t\t *** Clientes *** \n");
		while( aux != NULL ) {
			printf("\n\t||Nro Turno:%d||Nombre:%s||Motivo:%d||\n", aux->clienteBanco.numeroTurno,aux->clienteBanco.nombre,aux->clienteBanco.motivo);
			aux = aux->siguiente;
		}		
	}
}

tClientes * primerCliente(tCola pColaClientes){
	if(!colaVacia(pColaClientes)){
		return pColaClientes.principio;	
	}else{
		return NULL;
	}	
}

void mostrarPrimerCliente(){
		if(primerCliente(colaClientes)){
			printf("\n\t||Nro Turno:%d||Nombre:%s||Motivo:%d||\n",colaClientes.principio->clienteBanco.numeroTurno,colaClientes.principio->clienteBanco.nombre,colaClientes.principio->clienteBanco.motivo);
	}else{
		printf("No hay Cliente para visualizar ...\n");
	}
}

void mostrarTotalClientes1(tCola pColaClientes){
    if(!colaVacia(pColaClientes)){
        printf("\n\tEl Total de Turnos De Clientes para Transacciones es: %d\n\n",calcularTotalClientes1(pColaClientes));
    }else{
        printf("\n\t*** No hay datos a mostrar ***\n\n");
        }
    }

int calcularTotalClientes1(tCola pColaClientes){
    tClientes *auxiliar;
    auxiliar =pColaClientes.principio;
    int totalClientes=0;
    while(auxiliar != NULL){
		if(auxiliar->clienteBanco.motivo==1){
            totalClientes+=1;
            } 
			auxiliar=auxiliar->siguiente;
    	}	
    return(totalClientes);
}

void mostrarTotalClientes2(tCola pColaClientes){
    if(!colaVacia(pColaClientes)){
        printf("\n\tEl Total de Turnos De Clientes para Consultas es: %d\n\n",calcularTotalClientes2(pColaClientes));
    }else{
        printf("\n\t*** No hay datos a mostrar ***\n\n");
        }
    }

int calcularTotalClientes2(tCola pColaClientes){
    tClientes *auxiliar;
    auxiliar =pColaClientes.principio;
    int totalClientesConsultas=0;
    while(auxiliar != NULL){
		if(auxiliar->clienteBanco.motivo==2){
            totalClientesConsultas+=1;
            } 
			auxiliar=auxiliar->siguiente;
    	}	
    return(totalClientesConsultas);
}

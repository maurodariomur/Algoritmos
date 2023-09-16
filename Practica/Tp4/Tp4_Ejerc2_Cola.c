/*
2. Se necesita procesar los datos de los llamados que ingresan al call center de una empresa de 
telecomunicaciones. Para ello se implementa una cola, en donde cada nodo contiene los siguientes datos: 
nombre y apellido, número de teléfono, DNI, código de lugar de procedencia (01-Corrientes 02-Chaco).
Se solicita escribir las funciones para: 
a) Conocer la cantidad de llamadas provenientes de cada lugar de procedencia y la cantidad total 
de llamadas en cola de espera.
b) Generar un listado que incluya los números telefónicos de las llamadas provenientes de 
Corrientes
*/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

//declaracion de la estructura
typedef char tString [50];
typedef int tNum[100];

typedef struct{
	tString nomYApe;
	tNum numeroCel;
	tNum dni;
	int codProcedencia;
 }tCliente;
 
typedef struct nodo{
	tCliente clienteCall;
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
void mostrarTotalLlamadas1(tCola);
int calcularTotalLlamadas1(tCola);
void mostrarTotalLlamadas2(tCola);
int calcularTotalLlamadas2(tCola);
void mostrarListadoCtes(tCola);

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
	printf("\n\t||4.Mostrar Total Clientes Corrientes en la Cola.\t||");
	printf("\n\t||5.Mostrar Total Clientes Chaco en la Cola.\t\t||");
	printf("\n\t||6.Vizualizar Datos De Clientes Ctes en la Cola.\t||");
	printf("\n\t||7.Vizualizar Datos De Clientes en la Cola.\t\t||");
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
			mostrarTotalLlamadas1(colaClientes);
			break;
		case 5:
			mostrarTotalLlamadas2(colaClientes);
			break;
		case 6:
			mostrarListadoCtes(colaClientes);
			break;	
		case 7:
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
	printf("Ingresar Nombre y Apellido Del Cliente: ");
	fflush(stdin);
	scanf("%[^\n]s",&datoCliente.nomYApe);
	printf("Ingresar Numero Telefonico del Cliente: ");
	fflush(stdin);
	scanf("%[^\n]s",&datoCliente.numeroCel);
	printf("Ingresar D.N.I del Cliente,sin puntos: ");
	fflush(stdin);
	scanf("%[^\n]s",&datoCliente.dni);
	printf("Ingresar codigo de Procedencia,1-Corrientes o 2-Chaco: ");
	scanf("%d",&datoCliente.codProcedencia);
		return datoCliente;
}

void pushCliente(tCliente pDataCustomer){
	tClientes * nuevoNodo;
	nuevoNodo =(tClientes *) malloc(sizeof(tClientes));	
	nuevoNodo->clienteCall = pDataCustomer;
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
		printf("\n\t||Nombre y Apellido:%s||Cel:%s||D.N.I:%s||Codig Procedencia: %d||\n", clienteSup->clienteCall.nomYApe,clienteSup->clienteCall.numeroCel,clienteSup->clienteCall.dni,clienteSup->clienteCall.codProcedencia);
		free(clienteSup);
		clienteSup = NULL;		
	} 	
}

void mostrarClientes(tCola pColaClientes){
	if(!colaVacia(pColaClientes)) {
		tClientes * aux;
		aux = pColaClientes.principio;
		printf("\n\t\t\t *** Clientes *** \n");
		while( aux != NULL ) {
			printf("\n\t||Nombre y Apellido:%s||Cel:%s||D.N.I:%s||Codig Procedencia: %d||\n",aux->clienteCall.nomYApe,aux->clienteCall.numeroCel,aux->clienteCall.dni,aux->clienteCall.codProcedencia);
			aux = aux->siguiente;
		}	
	} else {
		printf("No hay clientes para visualizar! \n");
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
			printf("\n\t||Nombre y Apellido:%s||Cel:%s||D.N.I:%s||Codig Procedencia: %d||\n",colaClientes.principio->clienteCall.nomYApe,colaClientes.principio->clienteCall.numeroCel,colaClientes.principio->clienteCall.dni,colaClientes.principio->clienteCall.codProcedencia);
	}else{
		printf("No hay Cliente para visualizar ...\n");
	}
}

void mostrarTotalLlamadas1(tCola pColaClientes){
    if(!colaVacia(pColaClientes)){
        printf("\n\tEl Total de Llamadas De Clientes de Corrientes es: %d\n\n",calcularTotalLlamadas1(pColaClientes));
    }else{
        printf("\n\t*** No hay datos a mostrar ***\n\n");
        }
    }

int calcularTotalLlamadas1(tCola pColaClientes){
    tClientes *auxiliar;
    auxiliar =pColaClientes.principio;
    int totalLlamadas1=0;
    while(auxiliar != NULL){
		if(auxiliar->clienteCall.codProcedencia==1){
            totalLlamadas1+=1;
            } 
			auxiliar=auxiliar->siguiente;
    	}	
    return(totalLlamadas1);
}

void mostrarTotalLlamadas2(tCola pColaClientes){
    if(!colaVacia(pColaClientes)){
        printf("\n\tEl Total de Llamadas De Clientes De Chaco es: %d\n\n",calcularTotalLlamadas2(pColaClientes));
    }else{
        printf("\n\t*** No hay datos a mostrar ***\n\n");
        }
    }

int calcularTotalLlamadas2(tCola pColaClientes){
    tClientes *auxiliar;
    auxiliar =pColaClientes.principio;
    int totalLlamadas2=0;
    while(auxiliar != NULL){
		if(auxiliar->clienteCall.codProcedencia==2){
            totalLlamadas2+=1;
            } 
			auxiliar=auxiliar->siguiente;
    	}	
    return(totalLlamadas2);
}

void mostrarListadoCtes(tCola pColaClientes){
        tClientes *aux;
        aux = pColaClientes.principio;
        if(colaVacia(colaClientes)){
            printf("\n\t*** No hay datos para mostrar ***\n\n");
        }else{
            printf("\n\n\t\t*** Listado De Los numeros telefonicos de Corrientes ***\n\n");
            while(aux != NULL){
                if(aux->clienteCall.codProcedencia==1){
                	printf("\n\t||Nombre y Apellido:%s||Cel:%s||D.N.I:%s||Codig Procedencia: %d||\n",aux->clienteCall.nomYApe,aux->clienteCall.numeroCel,aux->clienteCall.dni,aux->clienteCall.codProcedencia);
                } 
			aux = aux->siguiente;
            } printf("\n\n"); 	
        }
    }  

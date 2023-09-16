/*
3. Se requiere gestionar la asignación de documentos que se envían a una impresora. Los documentos se 
imprimen a medida que van llegando, y salen de la cola de impresión una vez impresos. Los datos que se 
requieren para el procesamiento de la impresión de los documentos son: IP de la PC que envía el 
documento, Nombre del documento, Tipo de documento (01. docx - 02.pdf - 03.jpg - 04.png - 05.xlsx), 
tamaño en bytes. Se solicita realizar las funciones necesarias para que la impresora emita los siguientes 
informes:
a) La cantidad de documentos de formato de imágenes que se encuentran en cola de impresión.
b) El tamaño total de todos los documentos que se encuentran en cola de impresión (expresado en 
megabytes).
c) El próximo documento a ser impreso.
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
	tNum ip;
	tString nom;
	int tipoDocumento;
	float bytes;
 }tDocumento;
 
typedef struct nodo{
	tDocumento docImprimir;
	struct nodo * siguiente;
}tDocIMpresiones;
 
typedef struct {
	tDocIMpresiones * principio;
	tDocIMpresiones * final;
}tCola;
 
//declaracion del prototipado
void moduloAbarcador();
void iniciarProceso();
void continuarProceso();
void inicializarCola();
void seleccionEnMenu();
bool colaVacia(tCola);
tDocumento ingresarDatosDoc();
void pushDocumentos(tDocumento);
void popDocumentos();
void mostrarDocumentos(tCola);
tDocIMpresiones * primerDocumento(tCola);
void mostrarPrimerDocumento();
void mostrarTotalDocumentos(tCola);
int calcularTotalDocumentos(tCola);
void mostrarTotalDocMgB(tCola);
float calcularTotalDocMgB(tCola);

//declaracion de variables globales
tCola colaDocumentos;
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
	colaDocumentos.principio=NULL;
	colaDocumentos.final=NULL;
	printf("\n\tCola Inicializada\n");
}

void seleccionEnMenu(){
	tDocumento d;
	int eleccion;
	printf("\t\t\t\t\t====================");
	printf("\n\t\t\t\t\tSeleccione Su Opción\n");
	printf("\t\t\t\t\t====================\n");
	printf("\n\t||1.Insertar Documento en la Cola.\t\t\t||");
	printf("\n\t||2.Eliminar Documento en la Cola.\t\t\t||");
	printf("\n\t||3.Mostrar Proximo Documento a Imprimir en la Cola.\t||");
	printf("\n\t||4.Mostrar Total de Documentos Imagen en la Cola.\t||");
	printf("\n\t||5.Mostrar Total De Documentos en MegaBytes en la Cola.||");
	printf("\n\t||6.Vizualizar Datos De Documentos en la Cola.\t\t||");
	printf("\n\t\t\t\t\tSu Elección Es: ");
	scanf("%d",&eleccion);
	system("cls");
	switch(eleccion){
		case 1:
			d=ingresarDatosDoc();
			pushDocumentos(d);		
			break;	
		case 2:
			popDocumentos();
			break;
		case 3:
			mostrarPrimerDocumento();
			break;
		case 4:
			mostrarTotalDocumentos(colaDocumentos);
			break;
		case 5:
			mostrarTotalDocMgB(colaDocumentos);
			break;
		case 6:
			mostrarDocumentos(colaDocumentos);
			break;
		default:
			printf("\n\tNO EXISTE LA OPCION SELECCIONADA...\n");
			break;
	}
}

bool colaVacia(tCola pColaDocumentos){
	return(pColaDocumentos.principio==NULL && pColaDocumentos.final==NULL);
}
tDocumento ingresarDatosDoc(){
	tDocumento datoDocumento;
	printf("Ingresar el IP de La PC: ");
	fflush(stdin);
	scanf("%[^\n]s",&datoDocumento.ip);
	printf("Ingresar Nombre del Documento: ");
	fflush(stdin);
	scanf("%[^\n]s",&datoDocumento.nom);
	printf("Ingresar Tipo de Documento,1.docx-2.pdf-3.jpg-4.png-5.xlsx: ");
	scanf("%d",&datoDocumento.tipoDocumento);
	printf("Ingresar MegaBytes del Documento: ");
	scanf("%f",&datoDocumento.bytes);
		return datoDocumento;
}

void pushDocumentos(tDocumento pDataDoc){
	tDocIMpresiones * nuevoNodo;
	nuevoNodo =(tDocIMpresiones *) malloc(sizeof(tDocIMpresiones));	
	nuevoNodo->docImprimir = pDataDoc;
	nuevoNodo->siguiente = NULL;
	if(colaVacia(colaDocumentos)){
		colaDocumentos.principio = nuevoNodo;
		colaDocumentos.final = nuevoNodo;
	} else {
		colaDocumentos.final->siguiente = nuevoNodo;
		colaDocumentos.final = nuevoNodo;
	}
	printf("\n\tDocumento en cola para imprimir!\n");
}

void popDocumentos(){
	if(colaVacia(colaDocumentos)) {
		printf("\n\tNo hay Documentos para imprimir\n");
	} else {
		tDocIMpresiones * documentoElim;
		documentoElim = colaDocumentos.principio;
		if( colaDocumentos.principio == colaDocumentos.final ) {
			inicializarCola();
		} else {
			colaDocumentos.principio = documentoElim->siguiente;			
		}
		printf("\n\t||IP:%s||Nombre:%s||Tipo Documento:%d||MegaBytes: %.2f||\n",documentoElim->docImprimir.ip,documentoElim->docImprimir.nom,documentoElim->docImprimir.tipoDocumento,documentoElim->docImprimir.bytes);
		free(documentoElim);
		documentoElim = NULL;		
	} 	
}

void mostrarDocumentos(tCola pColaDocumentos){
	if(!colaVacia(pColaDocumentos)) {
		tDocIMpresiones * aux;
		aux = pColaDocumentos.principio;
		printf("\n\t\t\t *** Documentos *** \n");
		while( aux != NULL ) {
			printf("\n\t||IP:%s||Nombre:%s||Tipo Documento:%d||MegaBytes: %.2f||\n",aux->docImprimir.ip,aux->docImprimir.nom,aux->docImprimir.tipoDocumento,aux->docImprimir.bytes);
			aux = aux->siguiente;
		}	
	} else {
		printf("No hay Documentos para visualizar! \n");
	}
}

tDocIMpresiones * primerDocumento(tCola pColaDocumentos){
	if(!colaVacia(pColaDocumentos)){
		return pColaDocumentos.principio;	
	}else{
		return NULL;
	}	
}

void mostrarPrimerDocumento(){
		if(primerDocumento(colaDocumentos)){
			printf("\n\t||IP:%s||Nombre:%s||Tipo Documento:%d||MegaBytes: %.2f||\n",colaDocumentos.principio->docImprimir.ip,colaDocumentos.principio->docImprimir.nom,colaDocumentos.principio->docImprimir.tipoDocumento,colaDocumentos.principio->docImprimir.bytes);
	}else{
		printf("No hay Primer Documento para visualizar ...\n");
	}
}

void mostrarTotalDocumentos(tCola pColaDocumentos){
    if(!colaVacia(pColaDocumentos)){
        printf("\n\tEl Total de Documentos formato Imagen es: %d\n\n",calcularTotalDocumentos(pColaDocumentos));
    }else{
        printf("\n\t*** No hay datos a mostrar ***\n\n");
        }
    }

int calcularTotalDocumentos(tCola pColaDocumentos){
    tDocIMpresiones *auxiliar;
    auxiliar =pColaDocumentos.principio;
    int totalDoc3=0;
    while(auxiliar != NULL){
		if(auxiliar->docImprimir.tipoDocumento==3){
            totalDoc3+=1;
            } 
			auxiliar=auxiliar->siguiente;
    	}	
    return(totalDoc3);
}

void mostrarTotalDocMgB(tCola pColaDocumentos){
    if(!colaVacia(pColaDocumentos)){
        printf("\n\tEl Total de Documentos expresado en MegaBytes es:%.2f\n\n",calcularTotalDocMgB(pColaDocumentos));
    }else{
        printf("\n\t*** No hay datos a mostrar ***\n\n");
        }
    }

float calcularTotalDocMgB(tCola pColaDocumentos){
    tDocIMpresiones *auxiliar;
    auxiliar =pColaDocumentos.principio;
    int totalDocBytes=0;
    while(auxiliar != NULL){
            totalDocBytes+=auxiliar->docImprimir.bytes;
			auxiliar=auxiliar->siguiente;
    	}	
    return(totalDocBytes);
}
 

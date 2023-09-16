/*
3. Se dispone de un archivo en el cual se tienen registrados los datos de todos los documentos que se envían 
a imprimir en una impresora. Los datos que se almacenan son: IP de la PC que envía el documento, 
Nombre del documento, Tipo de documento (01. docx - 02.pdf - 03.jpg - 04.png - 05.xlsx), tamaño en 
bytes. El archivo se encuentra ordenado ascendentemente por la IP de la PC que envía el documento. 
El formato del registro del archivo es el siguiente:
|IP de la PC que envía el documento|Nombre del documento| Tipo de documento Tamaño en bytes|
Se solicita realizar un corte de control en el archivo Documentos.dat a efectos de realizar las funciones necesarias 
para generar un listado de los documentos impresos por IP para mostrar.
*/
#include<stdio.h>
#include<string.h>
#include<locale.h>

//declaracion del protipado
void iniciarProceso(); 
void ingresarDatosRegistro();
void finalizarProceso();
void grabarRegistroDocumento();
void permitirProceso();
void continuarProceso();

typedef char tString[50];

//declaracion de tipo Datos
typedef struct{
	int ip;
	tString nomDoc;
	int tipoDoc;
	float tamByte;
}tr_documento;

tr_documento vr_documento; /*declaracion variable de tipo registro*/
FILE * vf_documento;/*declaracion variable de tipo fichero*/

//declaracion de variables globales
int continuar;

int main(){
	setlocale(LC_ALL,"spanish");
	iniciarProceso();
	permitirProceso();
	while(continuar==1){
		ingresarDatosRegistro();
		grabarRegistroDocumento();
		continuarProceso();
	}
	finalizarProceso();
	return 0;
}

void permitirProceso(){
	printf("Ingresar Datos, 1-SI o 0-NO: ");
	scanf("%d",&continuar);
}

void continuarProceso(){
	printf("Continuar con el ingreso de Datos, 1-SI o 0-NO: ");
	scanf("%d",&continuar);
}

void iniciarProceso() {
/* Se abre un archivo nuevo y se asigna a la variable archivo */
vf_documento = fopen("Documentos.dat", "ab");
printf("\n\t\tArchivo creado de Documentos...\n");
}

void ingresarDatosRegistro(){  
		printf("Ingrese IP: ");
		scanf("%d",&vr_documento.ip);
		printf("Ingrese Nombre Del Documento: ");
		fflush(stdin);
    	scanf("%[^\n]s",&vr_documento.nomDoc);
		printf("Ingrese tipo Documento,1. docx -2.pdf -3.jpg -4.png -5.xlsx: ");
    	scanf("%d",&vr_documento.tipoDoc);
    	printf("Ingrese tamaño en Bytes:  ");
    	scanf("%f",&vr_documento.tamByte);
}
	
void grabarRegistroDocumento() {
/* Se graba 1 registro en el archivo de Usuario */
fwrite( &vr_documento, sizeof( tr_documento ), 1, vf_documento);
printf( "\tRegistro del Documento insertado! \n" );
}

void finalizarProceso() {
	fclose(vf_documento);
}

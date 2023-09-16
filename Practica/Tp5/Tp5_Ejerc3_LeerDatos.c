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
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include<locale.h>

//declaracion del protipado
void iniciarProcesoLectura();
void leerRegistro();
void procesarCorte();
void finalizarProcesoLectura();

//declaracion del Prototipado Especificas a la Consigna
void principioCorte();
void unDocumento();
void finCorte();


//declaracion de tipos de datos
typedef char tString[50];
typedef struct{
	int ip;
	tString nomDoc;
	int tipoDoc;
	float tamByte;
}tr_documento;

tr_documento vr_documento; /*declaracion variable de tipo registro*/
FILE * vf_documento;/*declaracion variable de tipo fichero*/

//declaracion de variables globales
int	codCampoControl;
int totalDocumentos,totalDocumentosGeneral,totalImagenes;
float totalBytes,totalBytesImagen,totalBytesDocumentos,auxiliarBytes;

//declaracion de funcion principal
int main() {
	setlocale(LC_ALL,"spanish");
	iniciarProcesoLectura();
	procesarCorte();
	finalizarProcesoLectura();
	return 0;
}

//Implementación de funciones
void iniciarProcesoLectura() {
	vf_documento = fopen("Documentos.dat", "rb");
	fread(&vr_documento, sizeof(tr_documento), 1, vf_documento);
	totalDocumentosGeneral=0;
	totalImagenes=0;
	totalBytesImagen=0;
	totalBytesDocumentos=0;
	printf("\n\t\t *** Documentos impresos **** \n");
	printf(" ----------------------------------------------------------------------------\n");
	printf("\tIP\t\t\tDocumento \t\t\tTamaño (bytes)\n");
	printf(" ----------------------------------------------------------------------------\n");
}

void procesarCorte() {
	while(!feof(vf_documento)) {		
		principioCorte();
		while(!feof(vf_documento) && vr_documento.ip== codCampoControl){
			unDocumento();
			fread(&vr_documento, sizeof(tr_documento), 1, vf_documento);
		}
		finCorte();
	}	
}

void principioCorte(){	 
	totalDocumentos=0;
	totalBytes=0;

	codCampoControl=vr_documento.ip;
	printf("\n\t%d",codCampoControl);
}

void unDocumento(){
	if(vr_documento.ip){
		totalDocumentos+=1;
		totalBytes+=vr_documento.tamByte;
		if(vr_documento.tipoDoc==3){
			totalImagenes++;
			totalBytesImagen+=vr_documento.tamByte;
		}
		totalDocumentosGeneral++;
		totalBytesDocumentos+=vr_documento.tamByte;
	}
	printf("\t\t%s \t\t\t\t%.2fKB\n",vr_documento.nomDoc,vr_documento.tamByte);
}

void finCorte() {
	printf("_____________________________________________________________________________\n");
	printf("\nCantidad de documentos\nimpresos PC:\t %d %d\t\t\t\t\t\t %.2fKB\n",codCampoControl,totalDocumentos,totalBytes);
	printf("_____________________________________________________________________________\n");
}

void finalizarProcesoLectura() {
	printf("\n\tTotal de archivos de imágenes impresos: %d \t\t%.2fKB\n",totalImagenes,totalBytesImagen);
	printf("\n\tTotal de documentos impresos: %d \t\t\t%.2fKB\n",totalDocumentosGeneral,totalBytesDocumentos);
	fclose(vf_documento);	
}


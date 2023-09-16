/*
Se tiene registrada la información sobre las notas de los exámenes finales de los alumnos de la facultad 
durante el presente año, en un archivo ordenado en forma ascendente por número de libreta. De cada 
alumno se conoce el: 
|Número de Libreta|Nombre y apellido|Código de Materia|Nota Obtenida|
Se pide:
a) Listar un renglón por alumno con el promedio de notas obtenida.
b) Informar el total de alumnos.
c) Informar el alumno con mejor nota promedio.
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
void unAlumno();
void determinarMejorPromedio();
void finCorte();


//declaracion de tipos de datos
typedef char tString[50];

typedef struct{
	int nroLibreta;
	tString nomYApe;
	int codMateria;
	float notaObtenida;
}tr_alumno;

tr_alumno vr_alumno; /*declaracion variable de tipo registro*/
FILE * vf_alumno;/*declaracion variable de tipo fichero*/

//declaracion de variables globales
int	codCampoControl,totalAlumnos,cantidadPruebas,acumAlumno;
float totalNotas,promedioNota,cantidadNotas;
float mejorPromedio;

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
	vf_alumno = fopen("libretaAlumnos.dat", "rb");
	fread(&vr_alumno, sizeof(tr_alumno), 1, vf_alumno);
	mejorPromedio=0;
	totalAlumnos=0;
	printf("\n\t\t *** Listado de promedios *** \n");
	printf(" -------------------------------------------------------------------------\n");
	printf("\tNumero de Libreta \t|\tNota Promedio\t \n");
}

void procesarCorte() {
	while(!feof(vf_alumno)) {		
		principioCorte();
		while(!feof(vf_alumno) && vr_alumno.nroLibreta == codCampoControl){
			unAlumno();
			fread(&vr_alumno, sizeof(tr_alumno), 1, vf_alumno);
		}
		finCorte();
	}	
}

void principioCorte() {	 
	cantidadNotas=0;
	promedioNota=0;
	totalNotas=0;
	codCampoControl=vr_alumno.nroLibreta;
}

void unAlumno() {	
	if(vr_alumno.codMateria){
		cantidadNotas++;
		totalNotas+=vr_alumno.notaObtenida;
		promedioNota=totalNotas/cantidadNotas;	
	}			
}

void determinarMejorPromedio(){
	if(promedioNota>mejorPromedio){
		mejorPromedio=promedioNota;
	}	
}

void finCorte() {
	totalAlumnos++;
	determinarMejorPromedio();
	printf("\t%d\t\t\t %.2f\n",codCampoControl,promedioNota);	
}

void finalizarProcesoLectura() {	
	printf("\n\tTotal Alumnos: %d\n",totalAlumnos);
	printf("\n\tMejor Promedio es: %.2f\n",mejorPromedio);
	fclose(vf_alumno);	
}


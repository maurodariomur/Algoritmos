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
#include<stdio.h>
#include<string.h>
#include<locale.h>

//declaracion del protipado
void iniciarProceso(); 
void ingresarDatosRegistro();
void finalizarProceso();
void grabarRegistroAlumno();
void permitirProceso();
void continuarProceso();

typedef char tString[50];

//declaracion de tipo Datos
typedef struct{
	int nroLibreta;
	tString nomYApe;
	int codMateria;
	float notaObtenida;
}tr_alumno;

tr_alumno vr_alumno; /*declaracion variable de tipo registro*/
FILE * vf_alumno;/*declaracion variable de tipo fichero*/

//declaracion de variables globales
int continuar;

int main(){
	setlocale(LC_ALL,"spanish");
	iniciarProceso();
	permitirProceso();
	while(continuar==1){
		ingresarDatosRegistro();
		grabarRegistroAlumno();
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
vf_alumno = fopen("libretaAlumnos.dat", "ab");
printf("\n\t\tArchivo creado de Alumnos...\n");
}

void ingresarDatosRegistro(){  
		printf("Ingrese Nro. de Libreta: ");
    	scanf("%d",&vr_alumno.nroLibreta);
		printf("Ingrese Nombre y Apellido: ");
		fflush(stdin);
    	scanf("%[^\n]s",&vr_alumno.nomYApe);
		printf("Ingrese el codigo materia: ");
    	scanf("%d",&vr_alumno.codMateria);
    	printf("Ingrese nota Obtenida:  ");
    	scanf("%f",&vr_alumno.notaObtenida);
}
	
void grabarRegistroAlumno() {
/* Se graba 1 registro en el archivo de Usuario */
fwrite( &vr_alumno, sizeof( tr_alumno ), 1, vf_alumno );
printf( "\tRegistro del alumno insertado! \n" );
}

void finalizarProceso() {
	fclose(vf_alumno);
}

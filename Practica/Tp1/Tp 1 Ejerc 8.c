/*En el Call Center de una empresa telefónica, un asesor tiene N llamadas en cola de espera y debe atender 
por hora no más de 40 llamadas. El sistema registra el número de teléfono de los usuarios en espera. Se 
desea: obtener la cantidad de llamadas en espera en esa hora, eliminar las llamadas de la cola de espera 
a medida que se vayan atendiendo (utilizar la implementación con frente móvil) y generar un listado con 
todos los números que fueron atendidos durante una hora.
*/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

//Declaracion de Constante
#define REGISTRO 40

//Declaracion de Dato Personalizado
typedef int tVector[REGISTRO];

//Declaracion de La Estructura
typedef struct{
	
	tVector llamadas;
	int frente;
	int final;
	
}tCallCenter;

//Declaracion de Prototipados
void iniciarProceso();
void continuarProceso();
void inicializarTelefono();
void seleccionEnMenu();
bool sinLlamadas(tCallCenter);
bool contestadorLleno(tCallCenter);
void ingresarLlamadas();
void colaDeLlamadas(int);
void elimanarLlamadasHora();
void primeraLlamadaCola(tCallCenter);
void mostrarColaDeLlamadas(tCallCenter);

//Declaracion de variables
tCallCenter asesor;
int continuar;

//Declaracion De Funcion Principal
int main(){
	setlocale(LC_ALL,"spanish");
	iniciarProceso();
	return 0;
}

//declaracion de procedimientos
void iniciarProceso(){
	continuarProceso();
	inicializarTelefono();
	while(continuar==1){
		seleccionEnMenu();
		continuarProceso();
	}
}

void continuarProceso(){
	printf("\n\tDesea Ingresar Datos: 1-SI o 0-NO: ");
	scanf("%d",&continuar);
}

void inicializarTelefono(){
	asesor.frente=-1;
	asesor.final=-1;
	printf("\n\tSe Inicializo Cola...\n");
}

void seleccionEnMenu(){
	int eleccion;
	printf("\n\t\tSELECCIÓN DE OPCIONES\n");
	printf("\n\t||1.Registar Numero Telefonico a la Cola\t\t||");
	printf("\n\t||2.Eliminar a Numero Telefonico de la Cola\t\t||");
	printf("\n\t||3.Mostrar Lista de Numeros Telefonicos\t\t||");
	printf("\n\t||4.Mostrar a el Primer NUmero Telefonico\t\t||");
	printf("\n\t\t\tSelecciona: ");
	scanf("%d",&eleccion);
	system("cls");
	
	switch(eleccion){
		case 1:
			ingresarLlamadas();
			break;
		case 2:
			elimanarLlamadasHora();
			break;
		case 3:
			mostrarColaDeLlamadas(asesor);
			break;
		case 4:
			primeraLlamadaCola(asesor);
			break;
	}
}

bool sinLlamadas(tCallCenter pAsesor){
	
	return(pAsesor.frente==-1 && pAsesor.final==-1);

}

bool contestadorLleno(tCallCenter pAsesor){

	return(pAsesor.final=(REGISTRO-1));
	
}

void ingresarLlamadas(){
	long controlNum;
	printf("Llamada que se registro: ");
	scanf("%d",&controlNum);
	colaDeLlamadas(controlNum);
}

void colaDeLlamadas(int pControlNum){
	if(!contestadorLleno(asesor)){
		asesor.final+=1;
		asesor.llamadas[asesor.final]=pControlNum;
		
		if(asesor.final==0){
			asesor.frente=0;
		}
		printf("\n\tDisponible para Registrar %d",pControlNum);
	}
	else{
		printf("No es posible registrar Numeros");
	}
}

void elimanarLlamadasHora(){
	int numEliminar,i;
	if(!sinLlamadas(asesor)){
		
		numEliminar=asesor.llamadas[asesor.frente];
		asesor.llamadas[asesor.frente]=0;
		
		for(i=asesor.frente;i<=asesor.final-1;i++){
			asesor.llamadas[i]= asesor.llamadas[i+1];
		}
		
		asesor.llamadas[asesor.final]=0;
		
		if(asesor.frente==asesor.final){
			inicializarTelefono();
		}
		else{
			asesor.frente-=1;
		}
		printf("Numero Eliminado: %d\n",numEliminar);
	}
	else{
		printf("No hay numeros para Eliminar\n");
	}
}

void mostrarColaDeLlamadas(tCallCenter pAsesor){
	if(sinLlamadas(asesor)){
		printf("\n\tNo hay llamadas a mostrar");
	}
	else{
		printf("Llamadas a mostrar: \n");
		int i;
		for(i=pAsesor.frente;i<=pAsesor.final;i++){
			printf("| %d | ",pAsesor.llamadas[i]);
		}
	}
	
}

void primeraLlamadaCola(tCallCenter pAsesor){
	printf("La primera llamada fue del numero %d",pAsesor.llamadas[pAsesor.frente]);
}

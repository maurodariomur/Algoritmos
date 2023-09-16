/*
En una clínica la secretaria hace un listado con los nombres y apellidos de los pacientes que van llegando 
para luego ser atendidos en ese orden. El médico atiende un máximo de 20 pacientes por día. Se solicita: 
generar un listado de todos los pacientes que van a ser atendidos en el día, conocer si hay turnos 
disponibles, y realizar una función para borrar de la lista los pacientes a medida que son atendidos (utilizar 
la implementación con frente móvil).

Objetivo: generar un listado de todos los pacientes que van a ser atendidos en el día, conocer si hay turnos 
disponibles, y realizar una función para borrar de la lista los pacientes a medida que son atendidos

Nombre:listaPacientes;

Estrategia: iniciarProceso();
			continuarProceso();
			inicializarCola();
			colaVacia();
			colaLlena();
			agregarPaciente();
			eliminarPacienteFF();
			mostrarPrimerPaciente();
			mostrarPacientes();
*/

//declaracion de bibliotescas
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

//declaracion de constante
#define MAXP 8

//declaracion de dato Personalizado
typedef char tString[40];
typedef tString tLista[MAXP];

//declaracion de Estructura
typedef struct{
	tLista nomYApe;
	int frente;
	int final;
}tPacientes;

//declaracion de Prototipado
void iniciarProceso();
void continuarProceso();
void inicializarCola();
void seleccionEnMenu();
bool colaVacia(tPacientes);
bool colaLlena(tPacientes);
void agregarPaciente();
void listaDePacientesC(tString);
void eliminarPacienteFF();
void mostrarPrimerPaciente(tPacientes);
void mostrarPacientes(tPacientes);

//declaracion de variables
tPacientes pacientesFF;
int continuar;

//declaracion de Funcion Principal
int main(){
	setlocale(LC_ALL,"spanish");
	iniciarProceso();
	return 0;
}

//declaracion de Procedimientos
void iniciarProceso(){
	continuarProceso();
	inicializarCola();
	while(continuar==1){
		seleccionEnMenu();
		continuarProceso();
	}
}

void continuarProceso(){
	printf("\n\tDesea Agregar Datos: 1-SI o 0-NO: ");
	scanf("%d",&continuar);
}

void inicializarCola(){
	pacientesFF.frente=-1;
	pacientesFF.final=-1;
	printf("\n\tSe inicializar la Cola\n");
}

void seleccionEnMenu(){
	int eleccion;
	printf("\n\t\tSELECCIÓN DE OPCIONES\n");
	printf("\n\t||1.Agregar Paciente a la Cola\t\t||");
	printf("\n\t||2.Eliminar a Paciente de la Cola\t||");
	printf("\n\t||3.Mostrar Lista de Pacientes\t\t||");
	printf("\n\t||4.Mostrar a el Primer Pacientes\t||");
	printf("\n\t\t\tSelecciona: ");
	scanf("%d",&eleccion);
	system("cls");
	switch(eleccion){
		case 1:
			agregarPaciente();
			break;
		case 2:
			eliminarPacienteFF();
			break;
		case 3:
			mostrarPacientes(pacientesFF);
			break;
		case 4:
			mostrarPrimerPaciente(pacientesFF);
			break;
	}
}

void agregarPaciente(){
	char cadenaNP[40];
	
	printf("Nombre y Apellido del Paciente: ");
	fflush(stdin);
	scanf("%[^\n]s",&cadenaNP);
	listaDePacientesC(cadenaNP);	
}

bool colaVacia(tPacientes pPacientesFF) {
	return ( pPacientesFF.frente == -1 && pPacientesFF.final == -1 );
}

bool colaLlena(tPacientes pPacientesFF)  {
	return ( pPacientesFF.final == (MAXP-1) );
}

void listaDePacientesC(tString pCadenaNP){
	if(colaLlena(pacientesFF)){
		printf("No hay lugares disponibles");
	}
	else{
		//Hay lugar para Insertar
		
		//Actualizar el indice Final
		pacientesFF.final+=1;
		
		//Almacenar el elemento en la Lista
		strcpy(pacientesFF.nomYApe[pacientesFF.final],pCadenaNP);
		
		//Verificar si se esta insetando el primer elemento
		if(pacientesFF.final==0){
			//Es el primer elemento
			pacientesFF.frente=0;
		}
		printf("\n\t Turno para el paciente %s\n",pCadenaNP);
	}
}

void eliminarPacienteFF(){
	tString pacienteSuprimir = " ";
	int i;
	if( colaVacia( pacientesFF ) ) {
		printf("No hay elementos para eliminar\n");
	} else {
		/* Hay elementos por eliminar */
		
		/* Resguardar el elemento por eliminar */
		strcpy( pacienteSuprimir, pacientesFF.nomYApe[pacientesFF.frente] );
		
		/* Borrar el elemento que se encuentra en el frente */
		strcpy(pacientesFF.nomYApe[pacientesFF.frente], " ");
		
		/* Reacomodar la lista */
		for( i= pacientesFF.frente; i< pacientesFF.final; i++ ) {
			strcpy( pacientesFF.nomYApe[i], pacientesFF.nomYApe[i+1] );			
		}
		
		/* Borrar el valor duplicado del final */
		strcpy(pacientesFF.nomYApe[pacientesFF.final], " ");
		
		/* Verificar si la cola tiene un solo elemento, y actualizar índices */
		if( pacientesFF.frente == pacientesFF.final ) {
			/* 	Significa que se elimina el único elemento en la cola,
				por lo que hay que inicializar la cola nuevamente */
			inicializarCola();
		} else {
			pacientesFF.final = pacientesFF.final - 1;
		}
		
		/* Emitir mensaje de confirmación */
		printf("Elemento eliminado: %s\n", pacienteSuprimir);
	}

}

void mostrarPrimerPaciente(tPacientes pPacientesFF){
	printf("Primer Paciente: %s\n", pPacientesFF.nomYApe[pPacientesFF.frente]);
}

void mostrarPacientes(tPacientes pPacientesFF){
	int i;
	if( colaVacia(pPacientesFF) ) {
		printf("No hay Pacientes para visualizar\n");
	} else {
		printf("Pacientes: \n");
		for( i= pPacientesFF.frente; i<= pPacientesFF.final; i++ ) {
			printf("%s | ", pPacientesFF.nomYApe[i]);
		}
		printf("\n");
	}
}

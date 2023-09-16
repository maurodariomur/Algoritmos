#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#include <ctype.h>
#include<graphics.h>
#include<windows.h>

//declaracion de constantes
typedef char tString[30];

//declaracion de tipo de estructura
typedef struct{
	int numeroParticipante;
	float calculos1;
	float calculos2;
	tString nombre;
	int edad;
}tr_jugador;

typedef struct nodo{
	tr_jugador jugador;
	struct nodo * siguiente;
}tColaJugadores;
 
typedef struct {
	tColaJugadores * frente;
	tColaJugadores * final;
}tCola;

tCola cola; /*declaracion variable de tipo registro*/
FILE * archivo;/*declaracion variable de tipo fichero*/

//declaracion del prototipado general
void inicializarCola();
void iniciarProcesoLectura();
void iniciarPresentacion();
void procesarCorte();
void principioCorte();
void finDeCorte();
void procesarRegistroParticipantes();
void finalizarProcesoLectura();

//declaracion del prototipado de consignas
void unJugador();
void interfaz();
void seleccionEnMenu();
void mostrarSumaNumeros();
void mostrarRestaNumeros();
void sleep(time_t seconds);
void realizarConteo(int);
int cronometro();
void determinarMejorPuntaje();
bool colaVacia(tCola);

//declaracion variables globales
char opcion;
float resultado,jugador1;
int campoControlJugador,puntos,	operacionSuma,operacionResta,operaciones,mayorPuntaje,totalGeneralParticipantes;
int i,largo;
tString nombre,nombreMejorPuntj;
tr_jugador jugador;

int main(){
	system("color 5");
	setlocale(LC_ALL,"spanish");
	iniciarProcesoLectura();
	procesarCorte();
	finalizarProcesoLectura();
	return 0;
}

void iniciarPresentacion(){
	initwindow(600,500,"C:\Users\Usuario\Documents\Lic. en Sistemas\Segundo Cutrimestre\AEDII\Proyecto",300,100);
	readimagefile("presentacion.jpg",1,1);
	void readimafile(const char*filename=0,int left=0, int top=0,int right=)
}

void iniciarProcesoLectura(){
	archivo= fopen("elMundoDeLasMates.dat","rb");
	printf("\n Registros del Archivo\n" );
	fread(&jugador, sizeof(tr_jugador), 1 , archivo);
	totalGeneralParticipantes=0;
	printf("\n\t=====================================================================================\n");
	printf("\t\t\t\t\tJugadores y Sus Operaciones\t\t");
	printf("\n\t=====================================================================================\n");
}


void procesarCorte(){
	interfaz();
	while(!feof(archivo)){
		principioCorte();
		while(!feof(archivo) && jugador.numeroParticipante == campoControlJugador){
			unJugador();
			fread(&jugador, sizeof(tr_jugador), 1 , archivo);
		}
		finDeCorte();
	}
}

void principioCorte(){
	resultado=0;
	puntos=0;
	operacionSuma=0;
	operacionResta=0;
	campoControlJugador=jugador.numeroParticipante;
	int i,largo=0;
	strcpy(nombre,jugador.nombre);
	largo=strlen(nombre);
	for(i = 0; i<largo; i++) {
		nombre[i] = toupper(nombre[i]);
	}
	printf("\n\t%d)-%s.",campoControlJugador,nombre);
}

void interfaz(){
	int c, m=6;
	system("cls");
	system("color 05");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t EL MUNDO DE LAS MATES");
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t!CARGANDO JUEGO...¡\n");
    Sleep(200);

	for(c=15;c<=90; c++){
    	printf("%c",61);
  		Sleep(100); 
	}
  printf("\a");system("cls");
}

void unJugador(){
	int eleccion;
	int numero=3, nI;
	printf("\n\tPor favor seleccione una Opción...\n");
	printf("\n\t==========================\t");
	printf("\n\t||1.Sumar Numeros\t||");
	printf("\n\t||2.Restar Numeros\t||");
	printf("\n\t==========================\t");
	printf("\n\t\tSelección: ");
	scanf("%d",&eleccion);
	switch(eleccion){
		case 1:
			realizarConteo(numero);
			mostrarSumaNumeros();	
			break;
		case 2:
			realizarConteo(numero);
			mostrarRestaNumeros();
			break;	
		default:
			printf("\n\tEsa Opcion no Existe...\n");
			break;
	}
}

void mostrarSumaNumeros(){
	operacionSuma++;
	printf("\t\t%.2f + %.2f=",jugador.calculos1,jugador.calculos2);
	resultado=jugador.calculos1 + jugador.calculos2;
	fflush(stdin);
	scanf("%f",&resultado);
	if(resultado!=jugador.calculos1 + jugador.calculos2){
		cronometro();
		printf("\n\tSu respuesta fue incorrecta, la respuesta es %.2f...\n",resultado=jugador.calculos1 + jugador.calculos2);
		printf("\n\t!Práctica más...!\n");
		}else{
			cronometro();
			printf("\n\t!Muy Bien tu respuesta fue correcta...!\n");
			puntos++;		
		}
	
}
	
void mostrarRestaNumeros(){
	operacionResta++;
	resultado=jugador.calculos1 - jugador.calculos2;
	printf("\t\t%.2f - %.2f= ",jugador.calculos1,jugador.calculos2);
	fflush(stdin);
	scanf("%f",&resultado);
		
	if(resultado==jugador.calculos1 - jugador.calculos2){
		cronometro();
		printf("\n\t!Muy Bien tu respuesta fue correcta...!\n");
			puntos++;
		}else{
			cronometro();
			printf("\n\tSu respuesta fue incorrecta, la respuesta es %.2f...\n",resultado=jugador.calculos1 - jugador.calculos2);
			printf("\n\t!Práctica más...!\n");
		}
		
}
		
void realizarConteo(int numero){
	if(numero>0){
		printf("\t\tComienza en:|%d|\n",numero);
		sleep(1);
		realizarConteo(numero-1);
	}else{
		printf("\t\t!Comenzó El Juego...¡\n");
	}
}

int cronometro(){
	int segundos=0,minutos=0,horas=0;
	system("pause->NULL");
	while(segundos!=4){
		segundos++;
		if(segundos==5){
			segundos=0;
		}
		system("cls");
		printf("\n\n\t\t\t\t\t\t\t[%.2d:%.2d:%.2d]",horas,minutos,segundos);
		Sleep(1000);
	}
}

void determinarMejorPuntaje(){
	if(puntos>mayorPuntaje){
		mayorPuntaje=puntos;
		strcpy(nombreMejorPuntj,nombre);
	}	
}
void finDeCorte(){
	totalGeneralParticipantes++;
	operaciones=operacionSuma+operacionResta;
	determinarMejorPuntaje();
	printf("\n\t_________________________________________________________________________________\n");
	printf("\tCantidad de operaciones realizadas %d\n",operaciones);
	printf("\tEl total Acumulado de puntos es de %d por el Jugador",puntos);
	printf("\n\t_________________________________________________________________________________\n");
}

void finalizarProcesoLectura(){
	printf("\n\t\t\t\tCANTIDAD DE PARTICIPANTES %d \n",totalGeneralParticipantes);
	printf("\n\t\t\t\tMEJOR PUNTAJE ES %s CON : %d PTOS.\n",nombreMejorPuntj,mayorPuntaje);
	printf("\n\t*********************************************************************************\n");
	fclose(archivo);
}

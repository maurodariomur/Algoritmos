#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

//declaracion de dato Personalizado
typedef char tString[30];

//declaracion Estructura
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

//declaracion del prototipado
void iniciarProceso();
void continuarProceso();
void grabarRegistroParticipante(tr_jugador);
void cargaInterfaz();
void finalizarProceso();

//declaracion del Prototipado De Funciones Especificas
void moduloAbarcador();
void seleccionEnMenu();
void botInteractivo();
void inicializarCola();
int ingresarValor();
int realizarInverso(int);
tr_jugador ingresarDatosRegistro();
void pushColaJugadores(tr_jugador);
void explicacionSuma();
void explicacionResta();
bool colaVacia(tCola);
void eliminarNumeros();
void mostrarCola(tCola);
tColaJugadores * principioJugador(tCola);
void mostrarPrimerJugador();
 
//delclaracion de variables globales
char opcion;
tr_jugador jugador;

int main(){
	setlocale(LC_ALL,"spanish");
	iniciarProceso();
	cargaInterfaz();
	moduloAbarcador();
	return 0;
}

void iniciarProceso(){
/* Se abre un archivo nuevo y se asigna a la variable archivo */
	archivo = fopen("elMundoDeLasMates.dat", "wb");
	printf("\nArchivo creado con Exito...!\n");
}

void continuarProceso(){
	printf("\n\tDesea ingresar Datos: S-N: ");
	fflush(stdin);
	scanf("%c",&opcion);
}

void cargaInterfaz(){
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

void moduloAbarcador(){
	continuarProceso();
	botInteractivo();
	inicializarCola();
	while(opcion=='s'|| opcion=='S'){
		seleccionEnMenu();
		continuarProceso();
	}
	
}

void inicializarCola(){
	cola.frente=NULL;
	cola.final=NULL;
	printf("\n\tSe inicializo cola...!\n");
}

void botInteractivo(){
	system("cls");
	printf("\n\t!Hola Soy Bot-Pancho!... BIENVENIDO EL MUNDO DE LAS MATES.\n\tYo sere tu ayudante guiandote con tus elecciones (°w°)...\n");
	system("pause");
}

void seleccionEnMenu(){
	int eleccion,numero;
	printf("\n\t\t======================");
	printf("\n\t\tEstas son sus Opciones");
	printf("\n\t\t======================\n");
	printf("\n\t||1.Explicación de la Suma de Números\t||");
	printf("\n\t||2.Explicación de la Resta de Números\t||");
	printf("\n\t||3.Ingrese Datos Para los Cálculos\t||");
	printf("\n\t||4.Ingrese Número para Rercusividad\t||");
	printf("\n\t||5.Eliminar Números\t\t\t||");	
	printf("\n\t||6.Mostrar Números En Cola\t\t||");
	printf("\n\t||7.Mostrar el Primer Jugador\t\t||");
	printf("\n\t\t\tSeleccione: ");
	scanf("%d",&eleccion);
	system("cls");
	printf("Usted seleccionó la Opcion %d\n\n",eleccion);
	switch(eleccion){
		tr_jugador j;
		case 1:
			explicacionSuma();
			break;
		case 2:
			explicacionResta();
			break;
		case 3:
			j=ingresarDatosRegistro();
			pushColaJugadores(j);
			grabarRegistroParticipante(j);
			break;
		case 4:
			numero=ingresarValor();
			realizarInverso(numero);
			break;
		case 5:
			eliminarNumeros();
			break;
		case 6:
			mostrarCola(cola);
			break;		
		case 7:
			mostrarPrimerJugador();
			break;
		default:
			printf("\n\tNo Existe La Opción Seleccionada\n");
			break;	
	}
}

void explicacionSuma(){
	printf("\n\tLlamamos suma a la acción de añadir, juntar o agregar elementos,\n\tcuando realizamos esta acción estamos uniendo cantidades o conjuntos \n\ty para ello siempre debe haber un mínimo de dos elementos.\n\n");
}

void explicacionResta(){
	printf("\n\tLa resta o sustracción es una operación matemática que consiste en sacar, quitar,\n\treducir o separar algo de un todo. Restar es una de las \n\toperaciones básicas de las matemáticas junto a la suma, que es su proceso inverso.\n\n");
}

bool colaVacia(tCola pCola){
	return(pCola.frente==NULL && pCola.final==NULL);
}

int ingresarValor(){
	int valorInverso;
	printf("Ingresar numero para encontrar su Inverso: ");
	scanf("%d",&valorInverso);
	return valorInverso;
}

int realizarInverso(int valorInverso){
	printf("%d",valorInverso%10);
	if(valorInverso>10){
		realizarInverso(valorInverso/10);
	}		
}

tr_jugador ingresarDatosRegistro(){  
	tr_jugador jugadorModLocal;
		printf("Ingrese Numero Participante: ");
		scanf("%d",&jugadorModLocal.numeroParticipante);
		printf("Ingrese Su Nombre participante: ");
		fflush(stdin);
		scanf("%[^\n]s",&jugadorModLocal.nombre);
		printf("Ingrese su edad Participante: ");
		scanf("%d",&jugadorModLocal.edad);	
		printf("Ingrese numero A: ");
		scanf("%f",&jugadorModLocal.calculos1);	
		printf("Ingrese numero B: ");
		scanf("%f",&jugadorModLocal.calculos2);
		return jugadorModLocal;
}
	
void pushColaJugadores(tr_jugador pJugadorModLocal){
	tColaJugadores * nuevoNodo;
	nuevoNodo =(tColaJugadores *) malloc(sizeof(tColaJugadores));	
	nuevoNodo->jugador = pJugadorModLocal;
	nuevoNodo->siguiente = NULL;
	if(colaVacia(cola)){
		cola.frente = nuevoNodo;
		cola.final = nuevoNodo;
	} else {
		cola.final->siguiente = nuevoNodo;
		cola.final = nuevoNodo;
	}
	printf("\n\tJugador insertado! \n");
}

void eliminarNumeros(){
	float numEliminar1,numEliminar2;
		if(colaVacia(cola)) {
		printf("\n\tNo hay Jugadores para imprimir\n");
	} else {
		tColaJugadores * jugadorElim;
		jugadorElim = cola.frente;
		if( cola.frente == cola.final ) {
			inicializarCola();
		} else {
			cola.frente = jugadorElim->siguiente;			
		}
		printf("\n\t||Nombre:%s||Edad:%d||\n",jugadorElim->jugador.nombre,jugadorElim->jugador.edad);
		free(jugadorElim);
		jugadorElim = NULL;		
	} 	
}

void mostrarCola(tCola pCola){
	if(!colaVacia(cola)) {
		tColaJugadores * aux;
		aux = pCola.frente;
		printf("\n\t\t\t *** Jugadores *** \n");
		while( aux != NULL ) {
			printf("\n\t||Nombre:%s||Numero A:%.2f||Numero B: %.2f||\n",aux->jugador.nombre,aux->jugador.calculos1,aux->jugador.calculos2);
			aux = aux->siguiente;
		}	
	} else {
		printf("\n\tNo hay Jugadores para visualizar!\n");
	}	
}

tColaJugadores * principioJugador(tCola pCola){
	if(!colaVacia(pCola)){
		return pCola.frente;	
	}else{
		return NULL;
	}	
}

void mostrarPrimerJugador(){
		if(principioJugador(cola)){
			printf("\n\t||Nombre:%s||Edad:%d||\n",cola.frente->jugador.nombre,cola.frente->jugador.edad);
	}else{
		printf("No hay Primer Jugador para visualizar ...\n");
	}
}

void grabarRegistroParticipante(tr_jugador jugadorModLocal){
/* Se graba 1 registro en el archivo del Participante */
	fwrite( &jugadorModLocal, sizeof( tr_jugador ), 1, archivo);
	printf( "\tRegistro del Participante insertado! \n" );
}

void finalizarProceso() {
	fclose(archivo);
}

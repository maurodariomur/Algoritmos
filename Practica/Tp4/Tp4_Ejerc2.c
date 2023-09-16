/*
La registración a un evento de informática se realiza a través de la inscripción online mediante un 
formulario web. Para ello se registran los datos de los inscriptos en una pila con los siguientes datos: DNI,
Nombre y Apellido, e-mail, Código de Categoría (01-Estudiantes 02-Profesionales 03-Público en general) 
y Monto Abonado. El valor de la inscripción es de $200 para los estudiantes y $350 para profesionales y el 
público en general, valor que se abona al momento de la inscripción (tener en cuenta esto al momento de 
apilar inscriptos). Realizar las funciones necesarias para obtener:
a) la cantidad de Profesionales que se inscribieron al evento, y el porcentaje que representan sobre el total de inscriptos
b) el monto recaudado de inscriptos de la categoría Estudiantes
c) el total recaudado en concepto de inscripciones
Tener en cuenta que se deben realizar las operaciones básicas necesarias para la manipulación de la pila con 
punteros.
*/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

//declaracion de la estructura
typedef char tString [100];
typedef int tDocumento [40];
typedef struct{
	 tDocumento dni;
	tString nomYApe;
	tString email;
	int codigoCategoria;
	int montoAbonado;
 }tInscripto;
 
typedef struct nodo{
	tInscripto inscripto;
	struct nodo * siguiente;
 }tInscripciones;
 
//declaracion del prototipado
void moduloAbarcador();
void iniciarProceso();
void continuarProceso();
void inicializarPila();
void seleccionEnMenu();
bool pilaVacia(tInscripciones *);
tInscripto ingresarDatosPersona();
void apilarInscriptos(tInscripto);
void desapilarInscriptos();
tInscripciones *tope(tInscripciones *);
float calcularTotalRecaudado(tInscripciones *);
void mostrarTotalRecaudado(tInscripciones *);
void mostrarInscriptosPila(tInscripciones *);
void mostrarTopePila();
void mostrarPromedioProfesionales(tInscripciones *);
float calcularPromedioProfesionales(tInscripciones *);
int calcularGeneralInscriptos(tInscripciones * pPilaInscripcion);
void mostrarTotalRecaudadoEstudiantes(tInscripciones * );
int calcularRecaudadoEstudiantes(tInscripciones *);
void mostrarRecaudadoGeneral(tInscripciones *);
int calcularRecaudadoGeneral(tInscripciones *);

//declaracion de variables globales
tInscripciones * pilaInscripcion;
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
	inicializarPila();
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

void inicializarPila(){
	pilaInscripcion=NULL;
	printf("\n\tPila Inicializada\n");
}

void seleccionEnMenu(){
	tInscripto i;
	int eleccion;
	printf("\t\t\t\t\t====================");
	printf("\n\t\t\t\t\tSeleccione Su Opción\n");
	printf("\t\t\t\t\t====================\n");
	printf("\n\t||1.Insertar Inscripto en la Pila.\t\t\t    ||");
	printf("\n\t||2.Eliminar Inscripto en de la Pila.\t\t\t    ||");
	printf("\n\t||3.Mostrar Tope Pila.\t\t\t\t\t    ||");
	printf("\n\t||4.Visualizar Total Profesionales con respecto al resto.   ||");
	printf("\n\t||5.Visualizar Total Recaudado Por Estudiantes\t\t    ||");
	printf("\n\t||6.Visualizar Total Recaudato a Nivel General\t\t    ||");
	printf("\n\t||7.Visualizar todos los datos de los Inscriptos de la Pila.||");
	printf("\n\t\t\t\t\tSu Elección Es: ");
	scanf("%d",&eleccion);
	system("cls");
	switch(eleccion){
		case 1:
			i=ingresarDatosPersona();
			apilarInscriptos(i);		
			break;	
		case 2:
			desapilarInscriptos();
			break;
		case 3:
			mostrarTopePila();
			break;
		case 4:
			mostrarPromedioProfesionales(pilaInscripcion);
			break;
		case 5:
			mostrarTotalRecaudadoEstudiantes(pilaInscripcion);
			break;
		case 6:
			mostrarRecaudadoGeneral(pilaInscripcion);
			break;
		case 7:
			mostrarInscriptosPila(pilaInscripcion);
			break;
		default:
			printf("\n\tNO EXISTE LA OPCION SELECCIONADA...\n");
			break;
	}
}

bool pilaVacia(tInscripciones * pPilaInscripcion){
	return(pPilaInscripcion==NULL);
}
tInscripto ingresarDatosPersona(){
	tInscripto datoInscripto;
	printf("Ingresar DNI: ");
	fflush(stdin);
	scanf("%[^\n]s",&datoInscripto.dni);
	printf("Ingresar Nombre y Apellido: ");
	fflush(stdin);
	scanf("%[^\n]s",&datoInscripto.nomYApe);
	printf("Ingresar E-mail: ");
	fflush(stdin);
	scanf("%[^\n]s",&datoInscripto.email);
	printf("Ingresar codigo Categoria,1-Estudiantes,2-Profesionales,3-Público en general: ");
	scanf("%d",&datoInscripto.codigoCategoria);
	printf("Ingresar Monto Abonado : ");
	scanf("%d",&datoInscripto.montoAbonado);
	return datoInscripto;
}

void  apilarInscriptos(tInscripto pDatInscripto){
	tInscripciones * nuevoNodo;
	nuevoNodo = ( tInscripciones * ) malloc( sizeof( tInscripciones));
	nuevoNodo->inscripto = pDatInscripto ;
	nuevoNodo->siguiente = pilaInscripcion; 
	pilaInscripcion = nuevoNodo;
	printf("Inscripto Insertado insertado!\n");
}

void desapilarInscriptos(){
tInscripciones * nodoSuprimir;	
	if( !pilaVacia( pilaInscripcion ) ) {	
	nodoSuprimir = pilaInscripcion;
	pilaInscripcion =pilaInscripcion->siguiente;	
	printf( "\n\t\t\tInscripto eliminado:\n\n ||DNI:%s||Nombre y Apellido: %s||E-mail: %s||Codigo Categoria: %d||Monto Abonado:%d||\n", nodoSuprimir->inscripto.dni,nodoSuprimir->inscripto.nomYApe,nodoSuprimir->inscripto.email,nodoSuprimir->inscripto.codigoCategoria,nodoSuprimir->inscripto.montoAbonado);	
	free(nodoSuprimir);		
	nodoSuprimir = NULL;			
	}else{
		printf("No hay Inscriptos para eliminar!\n");
	}
}

tInscripciones * tope( tInscripciones * pPilaInscripcion){
	return pPilaInscripcion;
}

void mostrarTopePila(){
	if(tope(pilaInscripcion)){
		printf( "\n\t||DNI:%s||Nombre y Apellido: %s||E-mail: %s||Codigo Categoria: %d||Monto Abonado:%d||\n", pilaInscripcion->inscripto.dni,pilaInscripcion->inscripto.nomYApe,pilaInscripcion->inscripto.email,pilaInscripcion->inscripto.codigoCategoria,pilaInscripcion->inscripto.montoAbonado);	
	}else{
		printf("No hay tope para visualizar ...\n");
	}
}

void mostrarInscriptosPila(tInscripciones * pPilaInscripcion){
	tInscripciones * aux;	
	aux = pPilaInscripcion;
	if( !pilaVacia( pPilaInscripcion )) {
		printf("\n\t\tLos Inscriptos son...\n");
		while( aux != NULL ) {
		printf("||DNI:%s||Nombre y Apellido: %s||E-mail: %s||Codigo Categoria: %d||Monto Abonado:%d||\n\n", aux->inscripto.dni, aux->inscripto.nomYApe, aux->inscripto.email,aux->inscripto.codigoCategoria,aux->inscripto.montoAbonado);
		aux = aux->siguiente;
		}	
	} else {
		printf("No hay Inscriptos para visualizar ...\n");
	}
}

void mostrarPromedioProfesionales(tInscripciones * pPilaInscripcion){
    if(!pilaVacia(pPilaInscripcion)){
        printf("\n\tEl promedio de Profesionales respecto al resto es: %.2f\n\n", calcularPromedioProfesionales(pPilaInscripcion));
    }else{
        printf("\n\t*** No hay datos a mostrar ***\n\n");
        }
    }

float calcularPromedioProfesionales(tInscripciones * pPilaInscripcion){
    tInscripciones *aux;
    aux = pPilaInscripcion;
    int contadorGeneralPersonas=0; 
	int contadorProfesionales = 0;
    while(aux != NULL){
        contadorGeneralPersonas++;
		if(aux->inscripto.codigoCategoria==2){
            contadorProfesionales++;
            } 
			aux=aux->siguiente;  
    	}
		
    return(contadorProfesionales*100.0/calcularGeneralInscriptos(pPilaInscripcion));
}

int calcularGeneralInscriptos(tInscripciones * pPilaInscripcion){
    tInscripciones *aux;
    aux = pPilaInscripcion;
    int contadorGeneralPersonas=0;
	while(aux != NULL){
        contadorGeneralPersonas++;
		aux=aux->siguiente;  
    	}	
    return(contadorGeneralPersonas);
}

void mostrarTotalRecaudadoEstudiantes(tInscripciones * pPilaInscripcion){
    if(!pilaVacia(pPilaInscripcion)){
        printf("\n\tEl Total Recaudado por los Estudiantes es: %d\n\n", calcularRecaudadoEstudiantes(pPilaInscripcion));
    }else{
        printf("\n\t*** No hay datos a mostrar ***\n\n");
        }
    }

int calcularRecaudadoEstudiantes(tInscripciones * pPilaInscripcion){
    tInscripciones *auxiliar;
    auxiliar = pPilaInscripcion;
    int totalRecaudado1=0; 
    while(auxiliar != NULL){
		if(auxiliar->inscripto.codigoCategoria==1){
            totalRecaudado1+=auxiliar->inscripto.montoAbonado;
            } 
			auxiliar=auxiliar->siguiente;
    	}	
    return(totalRecaudado1);
}

void mostrarRecaudadoGeneral(tInscripciones * pPilaInscripcion){
    if(!pilaVacia(pPilaInscripcion)){
        printf("\n\tEl Total Recaudado General es: %d\n\n", calcularRecaudadoGeneral(pPilaInscripcion));
    }else{
        printf("\n\t*** No hay datos a mostrar ***\n\n");
        }
    }

int calcularRecaudadoGeneral(tInscripciones * pPilaInscripcion){
    tInscripciones *auxiliar;
    auxiliar = pPilaInscripcion;
    int totalRecaudadoGeneral=0; 
    while(auxiliar != NULL){
            totalRecaudadoGeneral+=auxiliar->inscripto.montoAbonado;
			auxiliar=auxiliar->siguiente;
    	}	
    return(totalRecaudadoGeneral);
}

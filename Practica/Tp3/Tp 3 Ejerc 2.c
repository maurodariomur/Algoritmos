/* El departamento de alumnado necesita trabajar con los datos de los alumnos de la materia AEDII, para 
ello implementa una lista simplemente enlazada, donde cada nodo guarda el número de libreta 
universitaria y el nombre del alumno. Se pide crear las funciones necesarias para:
a) Generar la lista.
b) Insertar el primer alumno (nodo) de la lista.
c) Insertar alumnos al principio de la lista.
d) Eliminar el primer alumno de la lista.
e) Insertar un alumno en una determinada posición dentro de la lista.
f) Eliminar un alumno de una determinada posición de la lista.
g) Visualizar todos los datos de los alumnos que están en la lista.
Además, crear una función que retorne la cantidad de alumnos que contiene la lista e implementar un 
menú principal que contenga todos los ítems anteriormente solicitados.
*/

#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>

typedef char tString[50];

typedef struct{
	tString nombreAlum;
	int libretaUni;
}tDatoAlumno;

typedef struct nodo{
	tDatoAlumno alumno;
	struct nodo * siguiente;
}tListaAlum;

//declaracion del Prototipado
void iniciarProceso();
void continuarProceso();
void inicializarLista();
void seleccionMenu();
bool listaVacia(tListaAlum *);
void ingresarDatosAlum(tListaAlum *);
void insertarAlumnos();
void eliminarPrimerAlumno();
void insertarAlumPosicion();
void insertarAlumK(int *);
void eliminarAlumPosicion();
void eliminarAlumK(int *);
int contadorAlumnos(tListaAlum *);
void mostrarCantidadAlumnos();
int visualizarAlum(tListaAlum *);

//declaracion de variables globales
tListaAlum * listaAlumnos;
int continuar,contadorAlum;

//declaracion de funcion principal
int main(){
	setlocale(LC_ALL,"spanish");
	iniciarProceso();
	return 0;
}

//implementacion de procedimientos-funciones
void iniciarProceso(){
	continuarProceso();
	inicializarLista();
	while(continuar==1){
		seleccionMenu();
		continuarProceso();
	}
}

void continuarProceso(){
	printf("\n\tDesea Ingresar Alumno:1-SI o 0-NO: ");
	scanf("%d",&continuar);
}

void inicializarLista(){
	listaAlumnos=NULL;
	printf("\n\tInicializacion de la Lista...\n");
}

void seleccionMenu(){
	int eleccion;
	printf("\t\t\t\t\t====================");
	printf("\n\t\t\t\t\tSeleccione Su Opción\n");
	printf("\t\t\t\t\t====================\n");
	printf("\n\t||1.Insertar primer Alumno en la lista.\t\t\t\t\t\t||");
	printf("\n\t||2.Insertar un Alumno en una determinada posición dentro de la lista.\t\t||");
	printf("\n\t||3. Eliminar el primer Alumno de la lista.\t\t\t\t\t||");
	printf("\n\t||4. Eliminar un Alumno de una determinada posición de la lista.\t\t||");
	printf("\n\t||5. Visualizar todos los datos de los Alumnos que están en la lista.\t\t||");
	printf("\n\t\t\t\t\tSu Elección Es: ");
	scanf("%d",&eleccion);
	system("cls");
	switch(eleccion){
		case 1:
			insertarAlumnos();
			break;
		case 2:
			insertarAlumPosicion();
			break;	
		case 3:
			eliminarPrimerAlumno();
			break;
		case 4:
			eliminarAlumPosicion();
			break;
		case 5:
			visualizarAlum(listaAlumnos);
			contadorAlumnos(listaAlumnos);
			mostrarCantidadAlumnos();
			break;
		default:
			printf("\n\tNO EXISTE LA OPCION SELECCIONADA...,disculpeme hasta aca llego mi cabeza\n");
			break;
	}
}

bool listaVacia(tListaAlum * pListaAlumnos){
	return(pListaAlumnos==NULL);
}

void ingresarDatosAlum(tListaAlum * pListaAlumnos){
	printf("Ingrese la Libreta Universitaria del Alumno: ");
	scanf("%d",&pListaAlumnos->alumno.libretaUni);
	printf("Ingrese el Nombre y Apellido del Alumno: ");
	fflush(stdin);
	scanf("%[^\n]s",&pListaAlumnos->alumno.nombreAlum);
}

void insertarAlumnos(){
	tListaAlum * nuevoNodo;
	nuevoNodo=(tListaAlum *)malloc(sizeof(tListaAlum));
	ingresarDatosAlum(nuevoNodo);
	if(listaVacia==NULL){
		nuevoNodo->siguiente=NULL;
	}else{
		nuevoNodo->siguiente=listaAlumnos;
	}
	listaAlumnos=nuevoNodo;
	printf("\n\tAlumno Insertado con exito!");
}

void eliminarPrimerAlumno(){
	if(listaVacia(listaAlumnos)){
		printf("No hay alumnos para eliminar");
	}else{
		tListaAlum * alumElim;
		
		alumElim=listaAlumnos;
		
		listaAlumnos=listaAlumnos->siguiente;
		printf("El Alumno %s numero %d fue eliminado",alumElim->alumno.nombreAlum,alumElim->alumno.libretaUni);
		free(alumElim);
		alumElim=NULL;
	}
}

void insertarAlumPosicion(){
	int posicionInsert;
	printf("En que posicion desea insertar al Alumno: ");
	insertarAlumK(&posicionInsert);
}

void insertarAlumK(int *k){
	scanf("%d",k);
	int cont=*k;
	tListaAlum * aux;
	tListaAlum * nuevoNodo;
	
	int i;
	aux=listaAlumnos;
	for(i=1;i<cont-1;i++){
		aux=aux->siguiente;
	}
	nuevoNodo=(tListaAlum	*) malloc(sizeof(tListaAlum));
    ingresarDatosAlum(nuevoNodo);
    nuevoNodo->siguiente = aux->siguiente;
    aux->siguiente = nuevoNodo;
    printf("\nAlumno insertado en la posicion %d\n", *k);
}

void eliminarAlumPosicion(){
		if(listaVacia(listaAlumnos)){
		printf("No hay alumnos para eliminar");
	}
	else{
		int posicion;
        printf("\n\nIngrese la posicion del alumno que desea eliminar: ");
        eliminarAlumK(&posicion);
	}
}

void eliminarAlumK(int * k){
	scanf("%d",k);
	int i, cont = *k;
    tListaAlum *aux;
    tListaAlum * alumElim;
        
	aux = listaAlumnos;
    for(i=1;i<cont-1;i++){
        aux=aux->siguiente;
    }
   	alumElim=aux->siguiente;
    aux->siguiente=alumElim->siguiente;
    printf("\nEl Alumno %s fue eliminado de la lista\n", alumElim->alumno.nombreAlum);
    free(alumElim);
    alumElim = NULL;
}

int contadorAlumnos(tListaAlum * pListaAlumnos){
	tListaAlum *aux;
	aux=pListaAlumnos;
	contadorAlum=0;
	  if(listaVacia(aux)){
        printf("No hay Alumnos para mostrar\n\n");
    }
	else{
        printf("\n\n\t\t***Alumnos en lista***\n\n");
        while(aux!= NULL){
            contadorAlum+=1;
			aux = aux->siguiente;
        } 
        return contadorAlum;
    }
}

int visualizarAlum(tListaAlum *pListaAlumnos){
    tListaAlum *auxilar;
    auxilar=pListaAlumnos;
    if(listaVacia(auxilar)){
        printf("No hay Alumnos para mostrar\n\n");
    }
	else{
        printf("\n\n\t\t***Alumnos en lista***\n\n");
        while(auxilar != NULL){
            printf("  Nro Libreta: %d\t || Nombre: %s\t||", auxilar->alumno.libretaUni, auxilar->alumno.nombreAlum);
			auxilar = auxilar->siguiente;
        } printf("\n\n");
    }
    
}

void mostrarCantidadAlumnos(){
	printf("La cantidad de estudiantes es de %d",contadorAlum);
}

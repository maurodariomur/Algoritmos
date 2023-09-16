#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 10

typedef char t_string [50];

typedef struct {
	int dni;
	t_string nombre;	
}t_persona;

typedef t_persona listaPersona[MAX];
typedef t_string listadoNombres[MAX];

t_string aux_name;

listadoNombres nombres={"Persona 1","Persona 2","Persona 3","Persona 4","Persona 5","Persona 6","Persona 7","Persona 8","Persona 9","Persona 10"};

void inicializarLista();
void cargarLista(listaPersona);
void mostrar(listaPersona);
int busquedaBinaria(listaPersona, int);
void ordenacionPorIntercambio(listaPersona , t_persona );

int main(){
	t_persona personaBuscada;
	personaBuscada.dni=5;
	listaPersona lista;
	inicializarLista(lista);
	cargarLista(lista);
	mostrar(lista);
	printf("\n\nLa persona con DNI 5 se encuentra en la posicion: %d\n", busquedaBinaria(lista, personaBuscada.dni));
	printf("Su nombre es %s\n", aux_name);
	return 0;
}

void inicializarLista(listaPersona pListaPersona) {
	int i;
	t_persona p;
	for(i=0;i<MAX;i++){	
		pListaPersona[i]=p;
	}
}

void mostrar(listaPersona pListaPersona){
	int i;
	for(i=0;i<MAX;i++){	
		printf ("\n persona dni:%d , nombre:%s",pListaPersona[i].dni,pListaPersona[i].nombre);
	}
}

void cargarLista(listaPersona pListaPersona){
	int i=0;
	t_persona persona;
	t_string nombre;
	for(i=0;i<MAX;i++){
		
		persona.dni = i+1;			
    	strcpy(persona.nombre, nombres[i]);
       
        pListaPersona[i]=persona;
	      
	}
}

int busquedaBinaria(listaPersona p_v, int dni) {	
	int extInf, extSup;
	int posMed;
	bool encontrado;
	int result = -1; 
	extInf = 0;
	extSup = MAX-1;
	encontrado = false;
	while ((!encontrado) && (extSup >= extInf)) {
		posMed = (extSup + extInf) / 2;
		if (dni == p_v[posMed].dni) {
			encontrado = true;
			strcpy(aux_name, p_v[posMed].nombre);
		} 
		else {
			if (dni > p_v[posMed].dni) {
				/* se actualizan los extremos del intervalo */
				extInf = posMed + 1;
			} else {
				extSup= posMed - 1;
			}			
		}	
	} 
	if (encontrado) {
		result = posMed+1;
	} else {
		result = -1;
	}
	return result;
}

/*
En un concurso de baile en el que hay 10 participantes que bailan 7 estilos diferentes, se almacenan las 
puntuaciones (números reales con 1 dígito para la parte decimal (*)) en una matriz de 10 filas por 7 
columnas. La puntuación final de cada participante se obtiene como la suma de sus puntuaciones 
excluyendo la mayor y la menor (con lo cual se suman 5 puntuaciones para cada participante). Diseñar un 
programa que indique quien es el ganador del concurso. 
(*) La matriz debe ser cargada con cualquier expresión matemática que genere número reales
correspondientes a la puntuación.
*/

#include<stdio.h>
#include<string.h>
#define MAXF 2
#define MAXC 2

//declaracion de dato personalizado

typedef float tMatriz[MAXF][MAXC];
typedef float tVector[MAXF];

//declaracion de prototipado
void generarNumerosAleatorios();
void mostrarNumerosAleatorios();
float mayorElemento();
float menorElemento();
void mostrarMayorMenor(int,int);
void calcularPuntosParticipantes(float,float);

//declaracion de variables globlales
tMatriz matrizNumReales;
tVector vectorNumReales;
int i,j;

//declaracion de funcion principal
int main(){
	float menor,mayor;
	generarNumerosAleatorios();
	mostrarNumerosAleatorios();
	mostrarMayorMenor(menor,mayor);
	//calcularPuntosParticipantes(mayor,menor);
	return 0;
}

//implementacion del prototipado
void generarNumerosAleatorios(){
	int lim_inferior = 1;
	int lim_superior = 10;
	for(i=0;i<MAXF;i++){
		for(j=0;j<MAXC;j++){
			matrizNumReales[i][j] = ( lim_inferior + rand() % ( lim_superior + 1 - lim_inferior ) ) * 1.25;
		}	
	}
}

void mostrarNumerosAleatorios(){
	for(i=0;i<MAXF;i++){
		for(j=0;j<MAXC;j++){
			printf("\nEl puntaje es %.2f,de la posicion %d-%d\n",matrizNumReales[i][j],i+1,j+1);
		}	
	}
}

float mayorElemento(){
	float mayor;
	for(i=0;i<MAXF;i++){	
		mayor=matrizNumReales[0][0];
		int fila=0;
		int columna=0;
		for(j=0;j<MAXC;j++){
			if(matrizNumReales[i][j]>mayor){
				mayor=matrizNumReales[i][j];
				fila=i+1;
				columna=j+1;
			}	
		}
		printf("\n\n\tEL MAYOR PUNTAJE ES %.2f EN LA POSICION %d\n",mayor,fila);	
	}
	return mayor;
	
}

float menorElemento(){
	float menor;
	for(i=0;i<MAXF;i++){
		menor=matrizNumReales[0][0];
		int fila=0;
		int columna=0;
		for(j=0;j<MAXC;j++){
			if(matrizNumReales[i][j]<menor){
				menor=matrizNumReales[i][j];
				fila=i+1;
				columna=j+1;
			}	
		}
		printf("\n\n\tEL MENOR PUNTAJE ES %.2f EN LA POSICION %d\n",menor,fila);	
	}
	return menor;
	
}

void mostrarMayorMenor(int mayor,int menor){
	menorElemento(menor);
	mayorElemento(mayor);
	calcularPuntosParticipantes(mayor,menor);
	
}

void calcularPuntosParticipantes(float mayor,float menor){
	for(i=0;i<MAXF;i++){
		float semiSuma,total=0;
		float puntos=0;
		for(j=0;j<MAXC;j++){
			if(matrizNumReales[i][j]){
				semiSuma=mayor+menor;
				puntos+=matrizNumReales[i][j];
				total=puntos-semiSuma;	
			}	
		}
		printf("\n\n\tLa semi suma es %d es %.2f\n",i+1,semiSuma);		
		printf("\n\n\tEL Puntaje del Participante %d es %.2f\n",i+1,total);	
	}
	
}

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
#define MAXC 7

//declaracion de dato personalizado

typedef float tMatriz[MAXF][MAXC];
typedef float tVector[MAXF];

//declaracion de prototipado
void generarNumerosAleatorios();
void mostrarNumerosAleatorios();
void mayorElemento();
void menorElemento();
void mostrarMayorMenor(int,int);
void calcularPuntosParticipantes();

//declaracion de variables globlales
tMatriz matrizNumReales;
tVector vectorNumReales;

tVector menores = { 0.0, 0.0};
tVector mayores = { 0.0, 0.0};

int i,j;

//declaracion de funcion principal
int main(){
	float menor,mayor;
	generarNumerosAleatorios();
	mostrarNumerosAleatorios();
	mostrarMayorMenor(menor,mayor);
	
	
	// muestro menores
	for(i=0; i<MAXF; i++){ 
		printf("%.2f | ", menores[i]);
	}
	
	printf("\n");
	
	// muestro mayores
	for(i=0; i<MAXF; i++){ 
		printf("%.2f | ", mayores[i]);
	}
	
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

void mayorElemento(){
	float mayor;
	int participante;
	int estilo;
	for(i=0;i<MAXF;i++){	
		mayores[i]=matrizNumReales[0][0];
		participante=1;
		estilo=1;
		for(j=0;j<MAXC;j++){
			if(matrizNumReales[i][j]>mayores[i]){
				mayores[i]=matrizNumReales[i][j];
				participante=i+1;
				estilo=j+1;
			}	
		}	
	}
}

void menorElemento(){
	float menor;
	int participante;
	int estilo;
	for(i=0;i<MAXF;i++){
		menores[i]=matrizNumReales[0][0];
		participante=1;
		estilo=1;
		for(j=0;j<MAXC;j++){
			if(matrizNumReales[i][j] < menores[i]){
				menores[i] = matrizNumReales[i][j];
				participante = i+1;
				estilo = j+1;
			}	
		}	
	}

}

void mostrarMayorMenor(int mayor,int menor){
	menorElemento();
	mayorElemento();
	calcularPuntosParticipantes(mayor,menor);
	
}

void calcularPuntosParticipantes(){

	float semiSuma;
	float puntos;
	
	for(i=0;i<MAXF;i++){
		semiSuma=0;
		puntos=0;
		
		for(j=0;j<MAXC;j++){		
				semiSuma = semiSuma + matrizNumReales[i][j];			
				
		}
		
		puntos = semiSuma - menores[i] - mayores[i];
		printf("\n\n\tLa semi suma es %d es %.2f\n",i+1,semiSuma);		
		printf("\n\n\tEL Puntaje del Participante %d es %.2f\n",i+1,puntos);	
	}
	
}

#include <stdio.h>	
#include <stdlib.h>


/* Interfaz */
void inicializarDado(int, int);
int lanzarDado();
int valorActual();

int limiteInf;
int limiteSup;

/* Implementaci�n */
void inicializarDado(int pLimiteInf, int pLimiteSup){	
	/* 	falta validar que el p_limite_superior > p_limite_inferior
		y que corresponda a un intervalo de 6 n�meros */
	limiteInf = pLimiteInf;
	limiteSup = pLimiteSup;
}
		
int lanzarDado() {	
	/*  la funci�n srand recibe como par�metro un n�mero que se utilizar� 
		como semilla del inicial para las cuentas de los n�meros aleatorios. 
		A esta funci�n s�lo debemos llamarla una vez en nuestro programa. */
	srand(time(NULL));
	
	/*  numeros aleatorios entre M y N: 
		M + (N+1-M) � dicho de otra manera:
		limite_inferior + rand() % (limite_superior + 1 - limite_inferior)*/
	return limiteInf + rand() % (limiteSup + 1 - limiteInf); 
}

int valorActual() {
	return lanzarDado();
}



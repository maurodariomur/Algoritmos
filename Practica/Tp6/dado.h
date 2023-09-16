#include <stdio.h>	
#include <stdlib.h>


/* Interfaz */
void inicializarDado(int, int);
int lanzarDado();
int valorActual();

int limiteInf;
int limiteSup;

/* Implementación */
void inicializarDado(int pLimiteInf, int pLimiteSup){	
	/* 	falta validar que el p_limite_superior > p_limite_inferior
		y que corresponda a un intervalo de 6 números */
	limiteInf = pLimiteInf;
	limiteSup = pLimiteSup;
}
		
int lanzarDado() {	
	/*  la función srand recibe como parámetro un número que se utilizará 
		como semilla del inicial para las cuentas de los números aleatorios. 
		A esta función sólo debemos llamarla una vez en nuestro programa. */
	srand(time(NULL));
	
	/*  numeros aleatorios entre M y N: 
		M + (N+1-M) ó dicho de otra manera:
		limite_inferior + rand() % (limite_superior + 1 - limite_inferior)*/
	return limiteInf + rand() % (limiteSup + 1 - limiteInf); 
}

int valorActual() {
	return lanzarDado();
}



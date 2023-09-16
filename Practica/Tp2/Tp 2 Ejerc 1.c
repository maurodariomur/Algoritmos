#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

typedef char tString[25];

void itemA();
void itemB();
void itemC();
void itemD();
void itemE();

tString * apuntCadena;
float * apunFloat;
bool * apunBool;
int * apunInt;
char * apunChar;

int main(){
	itemA();
	itemB();
	itemC();
	itemD();
	itemE();
	return 0;
}

void itemA(){
	apuntCadena=(tString *)malloc(sizeof(tString));
	strcpy((*apuntCadena), "Maria Acosta");
	printf("\nEl contenido de la variable apuntada es: %s\n",*apuntCadena);
	printf("\nEl contenido de la variable apuntada es: %p\n",apuntCadena);
	printf("\nEl contenido de la variable apuntada es: %p\n",&apuntCadena);
}

void itemB(){
	apunFloat=(float *)malloc(sizeof(float));
	*apunFloat=20.5;
	printf("\nEl contenido de la variable apuntada es: %.2f\n",*apunFloat);
	printf("\nEl contenido de la variable apuntada es: %p\n",apunFloat);
	printf("\nEl contenido de la variable apuntada es: %p\n",&apunFloat);
}

void itemC(){
	apunBool=(bool *)malloc(sizeof(bool));
	*apunBool=true;
	printf("\nEl contenido de la variable apuntada es: %d\n",*apunBool);
	printf("\nEl contenido de la variable apuntada es: %p\n",apunBool);
	printf("\nEl contenido de la variable apuntada es: %p\n",&apunBool);
}

void itemD(){
	apunInt=(int *)malloc(sizeof(int));
	*apunInt=7350;
	printf("\nEl contenido de la variable apuntada es: %d\n",*apunInt);
	printf("\nEl contenido de la variable apuntada es: %p\n",apunInt);
	printf("\nEl contenido de la variable apuntada es: %p\n",&apunInt);
}

void itemE(){
	apunChar=(char *)malloc(sizeof(char));
	*apunChar='z';
	printf("\nEl contenido de la variable apuntada es: %c\n",*apunChar);
	printf("\nEl contenido de la variable apuntada es: %p\n",apunChar);
	printf("\nEl contenido de la variable apuntada es: %p\n",&apunChar);
}


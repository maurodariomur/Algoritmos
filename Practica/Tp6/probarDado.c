#include<stdio.h>
#include "dado.h"
#include<cstdlib>

//declaracion del prototipado 
int main(){
	int i;
	for(i=0,i<10,i++){
		printf("lanzamiento del dado %d",lanzamientoDado(i));
	}
	return 0;
}

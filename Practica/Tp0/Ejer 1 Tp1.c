/*. Realizar un programa para calcular la remuneración semanal de los empleados de una fábrica. El valor de 
la hora laboral es de $350 hasta 35 hs trabajadas, por encima de este valor se considera hora extra y el 
valor es de $525. Los datos que se ingresan son: apellido y nombre, y cantidad de horas trabajadas en la 
semana. Se debe incluir una función salarioSemanal que reciba la cantidad de horas trabajadas y retorne 
el salario del trabajador. El programa debe permitir realizar el cálculo tantas veces como el usuario lo 
desee*/

#include<stdio.h>
#include<string.h>

//delcaracion de dato personalizado
typedef char tString;

//declaracion del prototipado
void iniciarProceso();
void continuarProceso();
void ingreseDatosTrabajador();
float salarioSemanal(int);
void mostrarSueldo();

//declaracion de las variables globales
int continuar,horaLaboral,sueldo,total,cantidadHoras;
tString ApeYNom[30];

//declaracion de la funcion Principal
int main(){
	iniciarProceso();
	return 0;
}

//declaracion de los procedimientos
void iniciarProceso(){
	continuarProceso();
	while(continuar==1){
		ingreseDatosTrabajador();
		salarioSemanal(horaLaboral);
		mostrarSueldo();
		continuarProceso();
	}
}

void continuarProceso(){
	printf("\nDesea Ingresar Datos:1-Si o 0-No: ");
	scanf("%d",&continuar);
}

void ingreseDatosTrabajador(){
	printf("Ingresar Apellido y Nombre: ");
	fflush(stdin);
	scanf("%[^\n]s",&ApeYNom);
	printf("Cantidad de Horas Trabajadas: ");
	scanf("%d",&horaLaboral);
}

float salarioSemanal(int pHoraLaboral){
	int horaExtra=35;
	if(pHoraLaboral<=35){
		return sueldo=pHoraLaboral*350;	
	}
	else{
		if(pHoraLaboral>35){
			cantidadHoras=pHoraLaboral-horaExtra;
			total=cantidadHoras*525;
			return sueldo=pHoraLaboral*350+cantidadHoras;
		}
		
	}
}

void mostrarSueldo(){
		if(horaLaboral<=35){
			printf("\n\tLa hora Laboral es de $350 y el sueldo es de $%d\n",sueldo);
		}
		else{
			if(horaLaboral>35){
				printf("\n\tLa cantidad de horas extras realizadas es de %d hrs",cantidadHoras);
				printf("\n\tLa hora Laboral extra es de $525,la cantidad ganada por horas extras es de $%d",total);
				printf("\n\tLo obtenido es en total es $%d\n",sueldo);
			}
		}
}


/*
Un Instituto médico realiza una encuesta sobre nutrición. Para procesar los datos de los encuestados 
requiere un sistema, que implemente una lista enlazada. Para ello se capturan los siguientes datos: código 
de sexo (F. Femenino, M. Masculino), código de rango de edad (01. Menor de 15 años, 02. Entre 15 y 30 
años, 03. Más de 30 años), peso y altura. El sistema debe calcular el IMC (índice de masa corporal) antes 
de insertar un elemento en la lista, y almacenar la clasificación del IMC (string) como parte contenida de 
cada nodo.
Fórmula del IMC = kg / m2
Clasificaciones Mujeres Varones
Peso bajo < 20 < 19
Peso normal 20 - 25 19 - 24
Sobrepeso >25 >24
Se solicita realizar las funciones necesarias para que los usuarios del sistema puedan obtener los 
siguientes informes: 
a) La cantidad total de encuestados.
b) El promedio de pesos de las personas de peso bajo, que sean menores de 15 años.
c) Un listado de los datos correspondientes a las personas que tienen sobrepeso
*/

#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>

//declaracion de Dato Personalizado
 typedef char tString [50];
 
typedef struct {
	char codSexo;
	int codEdad;	
	float peso;
	float altura;
	tString IMCDesc;
}tEncuestado;

typedef struct nodo{
	tEncuestado encuestado;
	struct nodo *siguiente;
}tListaEncuesta;

//declaracion del Prototipado
void iniciarProceso();
void permitirProceso();
void continuarProceso();
void inicializarLista();
void menu();
tEncuestado ingresarDatosPersona();
void insertarPrimerEncuestado(tEncuestado);
void insertarEncuestadoAdelante(tEncuestado);
void insertarDatosEncuesta( tEncuestado);
void eliminarPrimeraPersonaEncuestada();
void ingresarEncuestadoPosicion();
void insertarPosicionK(int *,tEncuestado);
void eliminarEncuestadoPosicion();
void eliminarEncuestadoK(int *);
void contadorTotalEncuestados(tListaEncuesta *);
void calcularPersonasPsBj(tListaEncuesta *);
void promedioPesoBajoMenores(tListaEncuesta *);
float calcularPromedioPesoBajoMenores(tListaEncuesta *);
void mostrarListadoSobrepeso(tListaEncuesta *);
void visualizarLista(tListaEncuesta * );


//declaracion de variables Goblales
tListaEncuesta * encuesta;
int continuar;
float imc;
int cantidadEncuestados;


//declaracion de funcion Pricipal
int main(){
	setlocale(LC_ALL, "spanish");
	iniciarProceso();
	return 0;
}

//declaracion de procedimientos
void iniciarProceso(){
	permitirProceso();
	inicializarLista();
	while(continuar==1){
		menu();
		continuarProceso();
	}
}

void permitirProceso(){
	printf("\n\tDesea Ingresar Datos: 1-SI o 0-NO: ");
	scanf("%d",&continuar);
}

void continuarProceso(){
	printf("\n\tDesea seguir agregando Datos: 1-SI o 0-NO: ");
	scanf("%d",&continuar);
}

void inicializarLista(){
	encuesta=NULL;
	printf("INICIALIZACION DE LA LISTA!...\n");
}

void menu(){
	tEncuestado e1;
	int eleccion;
	printf("\t\t\t\t\t====================");
	printf("\n\t\t\t\t\tSeleccione Su Opción\n");
	printf("\t\t\t\t\t====================\n");
	printf("\n\t||1.Insertar encuestado al principio.\t\t\t\t\t\t||");
	printf("\n\t||2.Insertar Encuestado en una determinada posición dentro de la lista.\t\t||");
	printf("\n\t||3.Eliminar el primer Encuestado de la lista.\t\t\t\t\t||");
	printf("\n\t||4.Eliminar un Encuestado de una determinada posición de la lista.\t\t||");
	printf("\n\t||5.Mostrar Total De Encuestados.\t\t\t\t\t\t||");
	printf("\n\t||6.Mostrar los Encuestados con Bajo Peso.\t\t\t\t\t||");
	printf("\n\t||7.Mostrar Total de Personas con SobrePeso.\t\t\t\t\t||");
	printf("\n\t||8.Visualizar todos los datos de los Encuestados que están en la lista.\t||");
	printf("\n\t\t\t\t\tSu Elección Es: ");
	scanf("%d",&eleccion);
	system("cls");
	switch(eleccion){
		case 1:
			e1 = ingresarDatosPersona();
			insertarDatosEncuesta( e1 );		
			break;
		case 2:
			ingresarEncuestadoPosicion();
			break;	
		case 3:
			eliminarPrimeraPersonaEncuestada();
			break;
		case 4:
			eliminarEncuestadoPosicion();
			break;
		case 5:
			contadorTotalEncuestados(encuesta);
			break;
		case 6:	
			promedioPesoBajoMenores(encuesta);
			break;
		case 7:
			mostrarListadoSobrepeso(encuesta);
			break;
		case 8:
			visualizarLista(encuesta);
			break;
		default:
			printf("\n\tNO EXISTE LA OPCION SELECCIONADA...,disculpeme hasta aca llego mi cabeza\n");
			break;
	}
}

bool listaVacia(tListaEncuesta * pEncuesta){
	return(pEncuesta==NULL);
}

tEncuestado ingresarDatosPersona(){
	tEncuestado e;
	printf("Ingrese su Genero: M-masculino o F-Femenino: ");
	fflush(stdin);
	scanf("%c", &e.codSexo);
	printf("Ingrese su Edad: 1)-Menor de 15 años 2)-Entre 15 y 30 años 3)-Más de 30 años: ");
	scanf("%d",&e.codEdad);
	printf("Ingrese su Peso: ");
	scanf("%f", &e.peso);
	printf("Ingrese su Altura: ");
	scanf("%f", &e.altura);	
	imc=e.peso/pow(e.altura,2);
	if((e.codSexo=='f'|| e.codSexo=='F') && (imc<20)){
			strcpy(e.IMCDesc,"Peso bajo");
		}else{
			if((e.codSexo=='f' || e.codSexo=='F') && (imc>=20 && imc<=25)){
				strcpy(e.IMCDesc,"Peso normal");	
			}else{
				if((e.codSexo=='f' || e.codSexo=='F')&& (imc>25)){
					strcpy(e.IMCDesc,"Sobrepeso");
				}
			}				
		}
	if((e.codSexo=='m'|| e.codSexo=='M') && (imc<19)){
			strcpy(e.IMCDesc,"Peso bajo");
		}else{
			if((e.codSexo=='m' || e.codSexo=='M') && (imc>=10 && imc<=24)){
				strcpy(e.IMCDesc,"Peso normal");	
			}else{
				if((e.codSexo=='m' || e.codSexo=='M') && (imc>24)){
					strcpy(e.IMCDesc,"Sobrepeso");
				}
			}				
		}
	return e;		
}



void insertarPrimerEncuestado(tEncuestado e){
	tListaEncuesta * nuevoNodo;
	nuevoNodo=(tListaEncuesta *)malloc(sizeof(tListaEncuesta));	
	nuevoNodo->encuestado= e;
	nuevoNodo->siguiente=NULL;
	encuesta=nuevoNodo;
	
	printf("\n\tLa primera persona encuestada a sido insertada! ... \n");
	
}

void insertarPersonaEncuestadaAdelante(tEncuestado e){
	tListaEncuesta * nuevoNodo;
	nuevoNodo=(tListaEncuesta *)malloc(sizeof(tListaEncuesta));
	nuevoNodo->encuestado= e;
	nuevoNodo->siguiente=encuesta;
	encuesta=nuevoNodo;
	
	printf("\n\tLa persona encuestada a sido insertada! ... \n");
}

void insertarDatosEncuesta(tEncuestado personaEncuestada){	
	if( listaVacia( encuesta ) ) {
	 	insertarPrimerEncuestado( personaEncuestada );
	} else {
		 insertarPersonaEncuestadaAdelante( personaEncuestada );
	}
}

void eliminarPrimeraPersonaEncuestada(){
	if(!listaVacia(encuesta)){
		tListaEncuesta * encuestadoSuprimir;
		encuestadoSuprimir=encuesta;
		encuesta=encuesta->siguiente;
		printf("Se elimino la Persona Encuestada: \n\t||Genero: %c||Edad: %d||Peso: %.2f||Altura:%.2fMts||IMC:%s\n",encuestadoSuprimir->encuestado.codSexo,encuestadoSuprimir->encuestado.codEdad,encuestadoSuprimir->encuestado.peso,encuestadoSuprimir->encuestado.altura,encuestadoSuprimir->encuestado.IMCDesc);
		free(encuestadoSuprimir);
	}else{
		printf("\n\tNo Hay Persona Encuestada para Eliminar de la Lista\n\n");
	}
}

void ingresarEncuestadoPosicion(){
	tEncuestado e;
	int n;
	if(listaVacia(encuesta)){
		printf("\n\t¡Lista Vacia!... ,Usted volvio a menu, seleccione 1\n\n");
		menu();
	}else{
		printf("En que posicion desea Insertar al Encuestado: ");
		insertarPosicionK(&n,e);
	}
}

void insertarPosicionK(int *n,tEncuestado e){
	scanf("%d",n);
	int cont=*n;
	tListaEncuesta *nuevoNodo;
	tListaEncuesta *aux;
	aux=encuesta;
	int i;
	for(i=1;i<cont-1;i++){
		aux=aux->siguiente;
	}
	nuevoNodo=(tListaEncuesta	*) malloc(sizeof(tListaEncuesta));
	nuevoNodo->encuestado=ingresarDatosPersona();
	nuevoNodo->siguiente=aux->siguiente;
	aux->siguiente=nuevoNodo;
    printf("\n\tPersona Encuestada insertado en la posicion %d\n",*n);
}

void eliminarEncuestadoPosicion(){
		if(listaVacia(encuesta)){
		printf("\n\tNo hay Personas Encuestadas para eliminar\n");
	}
	else{
		int posicion;
        printf("\n\tIngrese la posicion del Encuestado que desea eliminar: ");
        eliminarEncuestadoK(&posicion);
	}
}

void eliminarEncuestadoK(int * k){
	scanf("%d",k);
	int i, cont = *k;
    tListaEncuesta *aux;
    tListaEncuesta * encuestadoElim;
        
	aux = encuesta;
    for(i=1;i<cont-1;i++){
        aux=aux->siguiente;
    }
   	encuestadoElim=aux->siguiente;
    aux->siguiente=encuestadoElim->siguiente;
    printf("\nEl Encuestado Genero:%c, Edad:%d, Peso:%.2f, Altura:%.2f. Fue eliminado de la lista\n", encuestadoElim->encuestado.codSexo,encuestadoElim->encuestado.codEdad,encuestadoElim->encuestado.peso,encuestadoElim->encuestado.altura);
    free(encuestadoElim);
    encuestadoElim = NULL;
}

void visualizarLista( tListaEncuesta * pEncuesta ){
	tListaEncuesta * aux;
	aux = pEncuesta;
	if( !listaVacia( aux ) ) {
		printf("\n\t\t\t\tPersonas Encuestadas\n");
		printf("\t\t\t\t--------------------\n");
		while( aux != NULL ) {
			printf("\n\t||Genero: %c||Edad: %d||Peso: %.2f||Altura:%.2f m.||IMC:%s\n", aux->encuestado.codSexo,aux->encuestado.codEdad,aux->encuestado.peso,aux->encuestado.altura,aux->encuestado.IMCDesc);
			aux = aux->siguiente;
		}
		printf("\n\n");
	} else {
		printf("\n\tNo hay personas Encuestadas para mostrar\n");
	}
}

void contadorTotalEncuestados(tListaEncuesta *pEncuesta){
	tListaEncuesta*contador;
	contador=pEncuesta;
	int contadorEncuestados;
	if(!listaVacia(contador)){
		while(contador!=NULL){
			contadorEncuestados++;
			contador=contador->siguiente;		
		}
	printf("\n\tLa cantidad de personas es de %d\n",contadorEncuestados);
	}else{
		
		printf("\n\tNo hay personas para Contar\n");
	}
}

void promedioPesoBajoMenores(tListaEncuesta *pEncuesta){
    if(!listaVacia(pEncuesta)){
        printf("\n\tEl promedio de Peso Bajo de las personas menores de 15: %.2f\n\n", calcularPromedioPesoBajoMenores(pEncuesta));
    }else{
        printf("\n\t*** No hay datos de encuestados ***\n\n");
        }
    }

float calcularPromedioPesoBajoMenores(tListaEncuesta * pEncuesta){
    int contadorPsBj = 0;
    float totalPeso = 0;
    tString pesoAuxilar;
    strcpy(pesoAuxilar, "Peso bajo");
    tListaEncuesta *aux;
    aux = pEncuesta;
    while(aux != NULL){
        if((strcmp(aux->encuestado.IMCDesc, pesoAuxilar)==0) && aux->encuestado.codEdad == 1){
            totalPeso += aux->encuestado.peso;
            contadorPsBj++;
            }
            aux=aux->siguiente;
    	}
    return(totalPeso/contadorPsBj);
}

void mostrarListadoSobrepeso(tListaEncuesta *pEncuesta){
        tListaEncuesta *aux;
        aux = pEncuesta;
        tString pesoAuxilar;
        strcpy(pesoAuxilar, "Sobrepeso");
        if(listaVacia(aux)){
            printf("\n\t*** No hay datos para mostrar ***\n\n");
        }else{
            printf("\n\n\t\t*** Lista de encuestados que tienen Sobrepeso ***\n\n");
            while(aux != NULL){
                if((strcmp(aux->encuestado.IMCDesc, pesoAuxilar)==0)){
                        printf("\tSexo: %c || Rango de edad: %d || Peso: %.1fKg || Altura: %.2fm\n", aux->encuestado.codSexo,aux->encuestado.codEdad,aux->encuestado.peso,aux->encuestado.altura);
                } aux = aux->siguiente;
            } printf("\n\n"); 	
        }
    }      

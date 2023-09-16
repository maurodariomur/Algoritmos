/*
a) El detalle de usuarios por cada país, agregar *** delante del email para los casos que correspondan a conexiones desde un automóvil.
b) Obtener la cantidad de usuarios por país.
c) Obtener el total general de usuarios.
d) Identificar el país con mayor participación de usuarios del plan FREE.
e) Generar un informe con el siguiente formato de salida por pantalla:
*/
#include <stdio.h>
#include <string.h>
#include<locale.h>



//declaracion de tipos de datos
typedef char tString[30];

//declaracion de tipo Datos
typedef struct{
 	short codPais;
 	int numeroUsuario;
	tString email;
	tString apellido;
	tString nombre;
	short codDispositivo;
	short codTipoPlan;
}tr_usuarioMusic;

tr_usuarioMusic vr_usuarioMusic; /*declaracion variable de tipo registro*/
FILE * vf_usuarioMusic;/*declaracion variable de tipo fichero*/

//declaracion del protipado
void iniciarProcesoLectura();
void procesarCorte();
void finalizarProcesoLectura();

//declaracion del Prototipado Especificas a la Consigna
void principioCorte();
void unUsuario();
void determinarMayorParticipacion();
void finCorte();

//declaracion de variables globales
int	codCampoControlPais,totalUsuariosPais,mayorParticipacion,totalFree;
int totalGeneralUsuarios,mayorParticipacion,totalParticipacionFree,totalParticipacionPremium;

//declaracion de funcion principal
int main() {
	setlocale(LC_ALL,"spanish");
	iniciarProcesoLectura();
	procesarCorte();
	finalizarProcesoLectura();
	return 0;
}

//Implementación de funciones
void iniciarProcesoLectura() {
	vf_usuarioMusic = fopen("usuarios.dat", "rb");
	fread(&vr_usuarioMusic, sizeof(tr_usuarioMusic), 1, vf_usuarioMusic);
	totalGeneralUsuarios=0;
	mayorParticipacion=0;
	totalFree=0;
	printf("\n________________________________________________________________________________\n");
	printf("\n\t\tListado de usuarios de Spotigy que utilizaron la app en el dia de la fecha\n");
	printf("________________________________________________________________________________\n");
}

void procesarCorte() {
	while(!feof(vf_usuarioMusic)) {		
		principioCorte();
		while(!feof(vf_usuarioMusic) && vr_usuarioMusic.codPais == codCampoControlPais){
			unUsuario();
			fread(&vr_usuarioMusic, sizeof(tr_usuarioMusic), 1, vf_usuarioMusic);
		}
		finCorte();
	}	
}

void principioCorte() {	 
			switch(vr_usuarioMusic.codPais){
			case 1:printf("\nArgentina\n",vr_usuarioMusic.codPais);
			break;	
			case 2:printf("\nBrasil \n",vr_usuarioMusic.codPais);
			break;
			case 3:printf("\nMexico\n",vr_usuarioMusic.codPais);
			break;
			case 4:printf("\nEEUU\n",vr_usuarioMusic.codPais);
			break;
			case 5:printf("\nOtros\n",vr_usuarioMusic.codPais);
			break;
	}
	printf("\n\t\temail \t\t\tApellido y Nombre\t\t\tTipo de Plan\t\tDispositivo del cual se conecta\n");
	totalUsuariosPais=0;
	totalParticipacionFree=0;
	totalParticipacionPremium=0;
	codCampoControlPais =vr_usuarioMusic.codPais;
}

void unUsuario(){
	 if( vr_usuarioMusic.codPais) {
	 	totalUsuariosPais++;
	 }
	if(vr_usuarioMusic.codTipoPlan==1){
		totalParticipacionFree++;
	}
	if(vr_usuarioMusic.codTipoPlan==2 ||vr_usuarioMusic.codTipoPlan==3 ||vr_usuarioMusic.codTipoPlan==4 ){
		totalParticipacionPremium++;
	}	
	totalFree+=totalParticipacionFree;
	printf("\n\t %s,\t\t %s %s,\t\t\t%d\t\t\t%d",vr_usuarioMusic.email,vr_usuarioMusic.apellido,vr_usuarioMusic.nombre,vr_usuarioMusic.codTipoPlan,vr_usuarioMusic.codDispositivo);
	 
}

void determinarMayorParticipacion(){
	if(totalFree>mayorParticipacion){
		mayorParticipacion=totalFree;
	}
}
void finCorte() {
		totalGeneralUsuarios++;
	determinarMayorParticipacion();
	printf("\n___________________________________________________________________________\n");
	printf("\n\tTotal usuarios Plan FREE: %d\n",totalParticipacionFree);
	printf("\n\tTotal usuarios Plan PREMIUM: %d",totalParticipacionPremium);
		printf("\n___________________________________________________________________________\n");
}

void finalizarProcesoLectura(){	
	printf("\n\tCantidad de usuarios registrados en el archivo: %d",totalGeneralUsuarios);
			switch(vr_usuarioMusic.codPais){
			case 1:printf("\n\tPais con mayor participacion de usuarios de plan FREE %d-Argentina Usuarios %d\n",vr_usuarioMusic.codPais,mayorParticipacion);
			break;	
			case 2:printf("\n\tPais con mayor participacion de usuarios de plan FREE %d-Brasil Usuarios %d\n",vr_usuarioMusic.codPais,mayorParticipacion);
			break;
			case 3:printf("\n\tPais con mayor participacion de usuarios de plan FREE %d-Mexico Usuarios %d\n",vr_usuarioMusic.codPais,mayorParticipacion);
			break;
			case 4:printf("\n\tPais con mayor participacion de usuarios de plan FREE %d-EEUU Usuarios %d\n",vr_usuarioMusic.codPais,mayorParticipacion);
			break;
			case 5:printf("\n\tPais con mayor participacion de usuarios de plan FREE %d-Otros Usuarios %d\n",vr_usuarioMusic.codPais,mayorParticipacion);
			break;
	}
printf("\n___________________________________________________________________________\n");		
	fclose(vf_usuarioMusic);	
}


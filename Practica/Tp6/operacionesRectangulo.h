/*Desarrollar un TDA �operacionesRectangulo� que declare y defina (implemente): 
a) una funci�n para calcular el per�metro
b) una funci�n para calcular el �rea
Luego escriba un programa en �C� que permita probar ambas funciones del TDA (�rea y per�metro), el 
programa que prueba el TDA debe aceptar el ingreso de dos variables (base y altura), invocar ambas 
funciones, y mostrar el resultado de las operaciones del TDA
*/

float perimetroDelRectangulo(float,float);
float areaRectangulo(float,float);

//implementacion de los modulos
float perimetroDeRectanulo(float lado1,float lado2){
	return 2*lado1+2*lado2;
}

float areaRectangulo(float base,float altura){
	return base*altura;
}

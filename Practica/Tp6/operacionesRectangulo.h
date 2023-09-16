/*Desarrollar un TDA “operacionesRectangulo” que declare y defina (implemente): 
a) una función para calcular el perímetro
b) una función para calcular el área
Luego escriba un programa en “C” que permita probar ambas funciones del TDA (área y perímetro), el 
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

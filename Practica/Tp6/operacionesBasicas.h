/*
Escribir un TDA “operacionesBasicas” que permita calcular las operaciones de suma, resta, multiplicación 
y división de una calculadora para dos valores float. Luego desarrolle un programa en “C” que a partir del 
ingreso de dos variables reales y el operador (+: suma, -: resta, *: multiplicación, /: división), invoque al 
TDA y muestre los resultados de la operación seleccionada.
*/

float sumaReales(float,float);
float restaReales(float,float);
float productoReales(float,float);
float divisionReales(float,float);

//implementacion

float sumaReales(float num1,float num2){
	return num1+num2;
}
float restaReales(float num1,float num2){
	return num1-num2;
}
float productoReales(float num1,float num2){
	return num1*num2;
}
float divisionReales(float num1,float num2){
	return num1/num2;
}

/*Crea un programa que:
	1.- Pida al usuario ingresar los 16 valores de la matriz
	2.- Almacene cada valor en su posición correspondiente
	3.- Imprima la matriz completa al finalizar*/
#include <stdio.h>
//Definimos filas y columnas como constantes
#define FILAS 4
#define COLUMNAS 4
//Paso 1: Declaramos la matriz
int matriz[FILAS][COLUMNAS];
//Extraemos el total de filas de la matriz dividiendo el tamaño total en bytes de la matriz entre el tamaño en bytes de uno de sus elementos
int totalDeFilas = sizeof(matriz)/sizeof(matriz[0]);
/*Extraemos el total de columnas de la matriz dividiendo el tamaño en bytes de uno de sus elementos entre
el tamaño en bytes del tipo de dato de la matriz*/
int totalDeColumnas = sizeof(matriz[0])/sizeof(int);
//funcion para pedir valores al usuario
void pedirValores(){
	printf("Ingresa el valor para la posicion ");
}
//Paso 2: Declaramos una funcion para guardar en la matriz los valores ingresados
void guardarValoresEnLaMatriz(int filas, int columnas){
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < columnas; j++){
			pedirValores();
			printf("[%d,%d]: ",i,j );
			scanf("%d",&matriz[i][j]);
		}
	}
}
//Paso 3: Declaramos una funcion para imprimir la matriz en formato de tabla
void imprimirMatriz(int filas, int columnas){
	for(int i = 0; i < filas; i++){
		printf("[ ");
		for(int j = 0; j < columnas; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("]\n");
	}
}
//Funcion principal
int main(){
	guardarValoresEnLaMatriz(totalDeFilas, totalDeColumnas);
	imprimirMatriz(totalDeFilas, totalDeColumnas);
	return 0;
}

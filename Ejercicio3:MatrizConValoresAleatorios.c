/*Crea un programa que:

	1.- Llene una matriz de 4x4 con números aleatorios entre 0 y 9
	2.- Imprima la matriz
	3.- Muestre cuántos números pares e impares hay*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Definimos filas y columnas como constantes
#define FILAS 4
#define COLUMNAS 4
int pares = 0;
int impares = 0;
//Declaramos la matriz
int matriz[FILAS][COLUMNAS];
//Extraemos el total de filas de la matriz dividiendo el tamaño total en bytes de la matriz entre el tamaño en bytes de uno de sus elementos
int totalDeFilas = sizeof(matriz)/sizeof(matriz[0]);
/*Extraemos el total de columnas de la matriz dividiendo el tamaño en bytes de uno de sus elementos entre
el tamaño en bytes del tipo de dato de la matriz*/
int totalDeColumnas = sizeof(matriz[0])/sizeof(int);
//Paso 1: Declaramos una funcion para llenar nuestra matirz con elementos aleatorios de 0 a 9
void llenarMatriz(int filas, int columnas){
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < columnas; j++){
			matriz[i][j] = rand() % 9 + 1;//Numero aleatorio entre 0 y 9
		}
	}
}
//Paso 2: Declaramos una funcion para imprimir la matriz en formato de tabla
void imprimirMatriz(int filas, int columnas){
	for(int i = 0; i < filas; i++){
		printf("[ ");
		for(int j = 0; j < columnas; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("]\n");
	}
}
//Paso 3-1: Declaramos una funcion para que retorne cuantos numeros pares hay en la matriz
int numerosPares(int filas, int columnas, int pares){
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < columnas; j++){
			if(matriz[i][j]%2 == 0){
				pares++;
			}
		}
	}
	return pares;
}
//Paso 3-2: Declaramos una funcion para que retorne cuantos numeros impares hay en la matriz
int numerosImpares(int filas, int columnas, int impares){
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < columnas; j++){
			if(matriz[i][j]%2 != 0){
				impares++;
			}
		}
	}
	return impares;
}
//Funcion principal
int main(){
	//Inicializar semilla para numeros aleatorios
	srand(time(NULL));
	//Llamado de funciones
	llenarMatriz(totalDeFilas, totalDeColumnas);
	imprimirMatriz(totalDeFilas, totalDeColumnas);
	printf("En la matriz hay %d numeros pares y %d impares.\n",numerosPares(totalDeFilas, totalDeColumnas, pares),numerosImpares(totalDeFilas, totalDeColumnas, impares));
	return 0;
}

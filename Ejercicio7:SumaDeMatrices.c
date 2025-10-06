/*Implementa un programa que:
	1.- Cree dos matrices A y B de 4x4
	2.- Sume ambas matrices: C[i][j] = A[i][j] + B[i][j]
	3.- Muestre las tres matrices (A, B y C)*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Definimos filas y columnas como constantes
#define FILAS 4
#define COLUMNAS 4
//Declaramos las matrices A, B, C
int matrizA[FILAS][COLUMNAS];
int matrizB[FILAS][COLUMNAS];
int matrizC[FILAS][COLUMNAS];
//Extraemos el total de filas de la matriz dividiendo el tamaño total en bytes de la matriz entre el tamaño en bytes de uno de sus elementos
int totalDeFilas = sizeof(matrizA)/sizeof(matrizA[0]);
/*Extraemos el total de columnas de la matriz dividiendo el tamaño en bytes de uno de sus elementos entre
el tamaño en bytes del tipo de dato de la matriz*/
int totalDeColumnas = sizeof(matrizA[0])/sizeof(int);
//Paso 1: Declaramos una funcion para llenar matrices con elementos aleatorios de 0 a 5
void llenarMatriz(int matriz[][COLUMNAS], int filas, int columnas){
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < columnas; j++){
			matriz[i][j] = rand() % 5 + 1;//Numero aleatorio entre 0 y 5
		}
	}
}
//Declaramos una funcion para imprimir la matriz en formato de tabla
void imprimirMatriz(int matriz[][COLUMNAS], int filas,int columnas){
	for(int i = 0; i < filas; i++){
		printf("[ ");
		for(int j = 0; j < columnas; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("]\n");
	}
}
//Paso 2: Declaramos una funcion para la suma de matrices
void sumarMatrices(int matriz1[][COLUMNAS], int matriz2[][COLUMNAS], int filas,int columnas){
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < columnas; j++){
			matrizC[i][j] = matriz1[i][j] + matriz2[i][j];
		}
	}
}
//Funcion principal
int main(){
	//Inicializar semilla para numeros aleatorios
	srand(time(NULL));
	//Llenar matrizA y matrizB
	llenarMatriz(matrizA, totalDeFilas, totalDeColumnas);
	llenarMatriz(matrizB, totalDeFilas, totalDeColumnas);
	//Sumar matrizA y matrizB
	sumarMatrices(matrizA, matrizB, totalDeFilas, totalDeColumnas);
	//Paso 3: Mostrar matrizA, matrizB y matrizC
	printf("Matriz A:\n");
	imprimirMatriz(matrizA, totalDeFilas, totalDeColumnas);
	printf("Matriz B:\n");
	imprimirMatriz(matrizB, totalDeFilas, totalDeColumnas);
	printf("MatrizA + MatrizB = MatrizC:\n");
	imprimirMatriz(matrizC, totalDeFilas, totalDeColumnas);
	return 0;
}

/*Implementa un programa que:
	1.- Cree dos matrices A y B
	2.- Multiplique ambas matrices: C[i][j] = A[i][j] * B[i][j]
	3.- Muestre las tres matrices (A, B y C)*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Definimos filas y columnas como constantes
//#define FILAS 4
#define COLUMNAS 3
//Declaramos las matrices A, B,
int matrizA[2][COLUMNAS];
int matrizB[2][COLUMNAS];
int matrizC[2][COLUMNAS];
//Extraemos el total de filas de la matriz dividiendo el tamaño total en bytes de la matriz entre el tamaño en bytes de uno de sus elementos
int totalDeFilasA = sizeof(matrizA)/sizeof(matrizA[0]);
int totalDeFilasB = sizeof(matrizB)/sizeof(matrizB[0]);
int totalDeFilasC = sizeof(matrizC)/sizeof(matrizC[0]);
/*Extraemos el total de columnas de la matriz dividiendo el tamaño en bytes de uno de sus elementos entre
el tamaño en bytes del tipo de dato de la matriz*/
int totalDeColumnasA = sizeof(matrizA[0])/sizeof(int);
int totalDeColumnasB = sizeof(matrizB[0])/sizeof(int);
int totalDeColumnasC = sizeof(matrizC[0])/sizeof(int);
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
//Paso 2: Declaramos una funcion para la multiplicacion de matrices
void multiplicarMatrices(int matriz1[][COLUMNAS], int matriz2[][COLUMNAS], int filasA,int columnasA, int filasB,int columnasB){
	if(columnasA != filasB){
		printf("\n¡No es posible la multiplicacion!\nUna matriz A de dimension (mxn) solo puede multiplicarce por una matriz B de (nxp)\n");
		return;
	} else{
		for(int i = 0; i < filasA; i++){
			for(int j = 0; j < columnasB; j++){
				matrizC[i][j] = 0;
				for(int k = 0; k < columnasA; k++){
					matrizC[i][j] += matriz1[i][k] * matriz2[k][j];
				}
			}
		}
		printf("MatrizA * MatrizB = MatrizC:\n");
		imprimirMatriz(matrizC, totalDeFilasC, totalDeColumnasC);
	}
}
//Funcion principal
int main(){
	//Inicializar semilla para numeros aleatorios
	srand(time(NULL));
	//Llenar matrizA y matrizB
	llenarMatriz(matrizA, totalDeFilasA, totalDeColumnasA);
	llenarMatriz(matrizB, totalDeFilasB, totalDeColumnasB);
	//Paso 3: Mostrar matrizA y matrizB
	printf("Matriz A:\n");
	imprimirMatriz(matrizA, totalDeFilasA, totalDeColumnasA);
	printf("Matriz B:\n");
	imprimirMatriz(matrizB, totalDeFilasB, totalDeColumnasB);
	//Multiplicar matrizA * matrizB y mostrar resultado
	multiplicarMatrices(matrizA, matrizB, totalDeFilasA, totalDeColumnasA, totalDeFilasB, totalDeColumnasB);
	return 0;
}

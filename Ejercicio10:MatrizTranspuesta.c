/*Crea un programa que:
	1.- Genere una matriz A de 3x4
	2.- Calcule su transpuesta AT (que será 4x3)
	3.- Muestre ambas matrices*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Definimos filas y columnas como constantes
#define FILAS 3
#define COLUMNAS 4
//Declaramos las matrices A y T
int matrizA[FILAS][COLUMNAS];
int matrizT[COLUMNAS][FILAS];
//Extraemos el total de filas de la matriz dividiendo el tamaño total en bytes de la matriz entre el tamaño en bytes de uno de sus elementos
int totalDeFilasA = sizeof(matrizA)/sizeof(matrizA[0]);
int totalDeFilasT = sizeof(matrizT)/sizeof(matrizT[0]);
/*Extraemos el total de columnas de la matriz dividiendo el tamaño en bytes de uno de sus elementos entre
el tamaño en bytes del tipo de dato de la matriz*/
int totalDeColumnasA = sizeof(matrizA[0])/sizeof(int);
int totalDeColumnasT = sizeof(matrizT[0])/sizeof(int);
//Declaramos una funcion para llenar matrices con elementos aleatorios de 0 a 5
void llenarMatriz(int filas, int columnas, int matriz[][columnas]){
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < columnas; j++){
			matriz[i][j] = rand() % 5 + 1;//Numero aleatorio entre 0 y 5
		}
	}
}
//Declaramos una funcion para imprimir la matriz en formato de tabla
void imprimirMatriz(int filas,int columnas, int matriz[][columnas]){
	for(int i = 0; i < filas; i++){
		printf("[ ");
		for(int j = 0; j < columnas; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("]\n");
	}
}
//Paso 2: Declaramos una funcion para la matriz Transpuesta
void matrizTranspuesta(int filas,int columnas, int matriz[][columnas]){
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < columnas; j++){
			matrizT[j][i] = matriz[i][j];
		}
	}
	imprimirMatriz(totalDeFilasT, totalDeColumnasT, matrizT);
}
//Funcion principal
int main(){
	//Inicializar semilla para numeros aleatorios
	srand(time(NULL));
	//Paso 1: Llenar matrizA
	llenarMatriz(totalDeFilasA, totalDeColumnasA, matrizA);
	//Paso 3: Mostrar matrizA y matrizT
	printf("Matriz A:\n");
	imprimirMatriz(totalDeFilasA, totalDeColumnasA, matrizA);
	printf("Matriz Transpuesta:\n");
	matrizTranspuesta(totalDeFilasA, totalDeColumnasA, matrizA);
	return 0;
}

/*Para matrices cuadradas (n×n):
	Desarrolla un programa que:
	1.- Cree una matriz cuadrada de 4x4
	2.- Imprima los elementos de la diagonal principal (donde i == j)
	3.- Imprima los elementos de la diagonal secundaria (donde i + j == n-1)
	4.- Calcule la suma de cada diagonal*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Definimos filas y columnas como constantes
#define FILAS 3
#define COLUMNAS 4
//Declaramos la matriz A
int matrizA[FILAS][COLUMNAS];
//Extraemos el total de filas de la matriz dividiendo el tamaño total en bytes de la matriz entre el tamaño en bytes de uno de sus elementos
int totalDeFilasA = sizeof(matrizA)/sizeof(matrizA[0]);
/*Extraemos el total de columnas de la matriz dividiendo el tamaño en bytes de uno de sus elementos entre
el tamaño en bytes del tipo de dato de la matriz*/
int totalDeColumnasA = sizeof(matrizA[0])/sizeof(int);
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
//Paso 4-1: Declaramos una funcion para la suma de la diagonal pricipal
void sumarDiagonalPrincipal(int filas, int columnas, int matriz[][columnas]){
	if(filas != columnas){
		printf("¡No es una matriz cuadrada!\nNo se puede obtener la suma de la diagonal pricipal.\n");
		return;
	}else{
		int sumaDiagonalPrincipal = 0;
		printf("Los valores de la diagonal principal son: [ ");
		for(int i = 0; i < filas; i++){
			printf("%d ", matriz[i][i]);
			sumaDiagonalPrincipal += matriz[i][i];
		}
		printf("]\nLa suma de la diagonal principal es: %d\n", sumaDiagonalPrincipal);
	}
}
//Paso 4-2: Declaramos una funcion para la suma de la diagonal secundaria
void sumarDiagonalSecundaria(int filas, int columnas, int matriz[][columnas]){
	if(filas != columnas){
		printf("¡No es una matriz cuadrada!\nNo se puede obtener la suma de la diagonal secundaria.\n");
		return;
	}else{
		int sumaDiagonalSecundaria = 0;
		printf("Los valores de la diagonal secundaria son: [ ");
		for(int i = 0; i < filas; i++){
			for(int j = 0; j < columnas; j++){
				if(i+j == filas-1){
					printf("%d ", matriz[i][j]);
					sumaDiagonalSecundaria += matriz[i][j];
				}
			}
		}
		printf("]\nLa suma de la diagonal secundaria es: %d\n", sumaDiagonalSecundaria);
	}
}
//Funcion principal
int main(){
	//Inicializar semilla para numeros aleatorios
	srand(time(NULL));
	//Llenar matrizA y matrizB
	llenarMatriz(totalDeFilasA, totalDeColumnasA, matrizA);
	//Paso 1:Mostrar matrizA
	printf("Matriz A:\n");
	imprimirMatriz(totalDeFilasA, totalDeColumnasA, matrizA);
	//Paso 2: Mostrar los elementos de la diagonal principal y la suma de la misma
	sumarDiagonalPrincipal(totalDeFilasA, totalDeColumnasA, matrizA);
	//Paso 3: Mostrar los elementos de la diagonal secundaria y la suma de la misma
	sumarDiagonalSecundaria(totalDeFilasA, totalDeColumnasA, matrizA);
	return 0;
}

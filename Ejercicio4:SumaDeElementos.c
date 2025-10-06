/*Escribe un programa que:
	1.- Cree una matriz de 4x4 con valores aleatorios
	2.- Calcule la suma de todos los elementos
	3.- Calcule el promedio de los elementos
	4.- Muestre ambos resultados
Muestre ambos resultados*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Definimos filas y columnas como constantes
#define FILAS 4
#define COLUMNAS 4
int suma = 0;
float promedio = 0;
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
//Declaramos una funcion para imprimir la matriz en formato de tabla
void imprimirMatriz(int filas, int columnas){
	for(int i = 0; i < filas; i++){
		printf("[ ");
		for(int j = 0; j < columnas; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("]\n");
	}
}
//Paso 2: Declaramos una funcion para que retorne la suma de todos los numeros en la matriz
int sumaTotalDeLaMatriz(int filas, int columnas, int suma){
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < columnas; j++){
			suma += matriz[i][j];
		}
	}
	return suma;
}
//Paso 3: Declaramos una funcion para calcular y retornar el promedio de la suma de los numeros en la matriz
float promedioDeLaMatriz(int filas, int columnas, int suma){
	return suma/(float)(filas*columnas);
}
//Funcion principal
int main(){
	//Inicializar semilla para numeros aleatorios
	srand(time(NULL));
	//Llamado de funciones
	llenarMatriz(totalDeFilas, totalDeColumnas);
	imprimirMatriz(totalDeFilas, totalDeColumnas);
	suma = sumaTotalDeLaMatriz(totalDeFilas, totalDeColumnas, suma);
	promedio = promedioDeLaMatriz(totalDeFilas, totalDeColumnas, suma);
	//Paso 4: Mostrar ambos resultados
	printf("La suma de los elementos de la matriz es %d y el promedio es %f.\n",suma,promedio);
	return 0;
}

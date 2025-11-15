#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Estructura para crear un estudiante
struct Estudiante{
	char nombre[50];
	int edad;
	float promedio;
};
//Funcion para llenar los datos de los estudiantes
void pedirDatosDelEstudiante(int longitud, FILE *txt){
	txt  = fopen("datosEstudiantes.txt", "w");
	char nombre [50];
	int edad = 0, limpiarBufer, valido = 0;
	float promedio = 0;
	for(int i = 0; i < longitud; i++){
		do{
			system("clear");
			printf("\n** Datos para el estudiante %d **\n", i+1);
			printf("Ingrese el nombre: ");
			scanf("%49s", nombre);
			while ((limpiarBufer = getchar()) != '\n' && limpiarBufer != EOF);
			printf("Ingresa la edad: ");
			valido = scanf("%d", &edad);
			while ((limpiarBufer = getchar()) != '\n' && limpiarBufer != EOF);
			if(valido == 0){
				printf("Dato incorrecto... Intenta de nuevo!\n");
				getchar();
				continue;
			}
			printf("Ingresa el promedio: ");
			valido = scanf("%f", &promedio);
			while ((limpiarBufer = getchar()) != '\n' && limpiarBufer != EOF);
			if(valido == 0){
				printf("Dato incorrecto... Intenta de nuevo!\n");
				getchar();
				continue;
			}
			//Almacenar datos ingresados.
			if (txt != NULL){
				fprintf(txt,"%s %d %.2f\n",nombre, edad, promedio);
			}
		}while(valido == 0);
	}
	fclose(txt);
}
//Funcion para cargar datos desde el txt
void cargarDatosEstudiante(int longitud, struct Estudiante (*ptrEstudiantes)[longitud], FILE *txt){
	txt  = fopen("datosEstudiantes.txt", "r");
	char nombre [50];
	int edad = 0;
	float promedio = 0;
	for(int i = 0; i < longitud; i++){
		if(txt != NULL){
			fscanf(txt, "%49s%d%f", nombre, &edad, &promedio);
		}
		strcpy((*ptrEstudiantes)[i].nombre, nombre);
		(*ptrEstudiantes)[i].edad = edad;
		(*ptrEstudiantes)[i].promedio = promedio;
	}
	fclose(txt);
}
//Funcion para imprimir datos de los estudiantes
void imprimirDatosDelEstudiante(int longitud, struct Estudiante (*ptrEstudiantes)[longitud]){
	system("clear");
	for(int i = 0; i < longitud; i++){
		printf("\n** Datos del estudiante %d **\n", i+1);
		printf("Nombre: %s\n", (*ptrEstudiantes)[i].nombre);
		printf("Edad: %d\n", (*ptrEstudiantes)[i].edad);
		printf("Promedio: %.1f\n", (*ptrEstudiantes)[i].promedio);
	}
}
//Funcion para el promedio general del grupo
void promedioDelGrupo(int longitud, struct Estudiante (*ptrEstudiantes)[longitud], float *ptrPromedioGeneral){
	float suma = 0;
	for(int i = 0; i < longitud; i++){
		suma += (*ptrEstudiantes)[i].promedio;
	}
	*ptrPromedioGeneral = suma / longitud;
}
//Funcion para obtener estudiante de mejor promedio
void mejorPromedio(int longitud, struct Estudiante (*ptrEstudiantes)[longitud]){
	int i = 0, posicion = 0;
	float mejorPromedio = (*ptrEstudiantes)[i].promedio;
	for(i = 1 ; i < longitud; i++){
		if((*ptrEstudiantes)[i].promedio > mejorPromedio){
			mejorPromedio = (*ptrEstudiantes)[i].promedio;
			posicion = i;
		}
	}
	printf("*** El estudiante con mejor promedio es %s con una calificacion de %.1f ***\n",
	 (*ptrEstudiantes)[posicion].nombre, (*ptrEstudiantes)[posicion].promedio);
}
//Funcion principal
int main(){
	FILE *archivoTexto;
	struct Estudiante estudiantes[3];
	struct Estudiante (*ptrEstudiantes)[3] = &estudiantes;
	int longitud = sizeof(estudiantes)/sizeof(estudiantes[0]);
	float promedioGeneral = 0;
	pedirDatosDelEstudiante(longitud, archivoTexto);
	cargarDatosEstudiante(longitud, ptrEstudiantes, archivoTexto);
	imprimirDatosDelEstudiante(longitud, ptrEstudiantes);
	promedioDelGrupo(longitud, ptrEstudiantes, &promedioGeneral);
	printf("\n*** El promedio general del grupos es %.1f ***\n", promedioGeneral);
	mejorPromedio(longitud, ptrEstudiantes);
	return 0;
}

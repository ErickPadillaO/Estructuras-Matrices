/*Entrada: Un carácter (char) que representa el símbolo romano (I, V, X, L, C, D, M)*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
//Funcion que retorna el valor del numero romano a un digito en numero arabigo
int  romanoAEntero(char numeroRomano){
	switch(numeroRomano){
		case 'M':
			return 1000;
			break;
		case 'D':
			return 500;
			break;
		case 'C':
			return 100;
			break;
		case 'L':
			return 50;
			break;
		case 'X':
			return 10;
			break;
		case 'V':
			return 5;
			break;
		case 'I':
			return 1;
			break;
		default:
			return 0;
			break;
	}
}
//Funcion que retorna el valor de la cadena del numero romano en numero arabigo
int  calcularNumeroArabigo(char numeroRomano[]){
        int numeroArabigo = 0;
	int actual, siguiente, auxiliar;
        for(int i = 0; i < strlen(numeroRomano); i++){
		actual = romanoAEntero(numeroRomano[i]);
		siguiente = romanoAEntero(numeroRomano[i+1]);
		if(actual >= siguiente){
			numeroArabigo += actual;
		}else {
			auxiliar = siguiente - actual;
			numeroArabigo += auxiliar;
			i++;
		}
        }
        return numeroArabigo;
}
//Funcion para validar el caracter ingresado que pertenesca al sistema de numeros romanos
void validarNumeroRomano(char numeroRomano){
	char letrasNumerosRomanos[] = {'M','D','C','L','X','V','I'};
	int validar = 0;
	for(int i = 0; i < strlen(letrasNumerosRomanos); i++){
		if(numeroRomano == letrasNumerosRomanos[i]){
			validar++;
			break;
		}
	}
	if(validar == 0){
		printf("El numero NO es romano\n");
	} else {
		printf("El numero romano en arabigo es: %d\n", romanoAEntero(numeroRomano));
	}
}
//Funcion para convertir cadena en MAYUSCULAS
void numeroRomanoMayusculas(char numeroRomano[]){
        for(int i = 0; i < strlen(numeroRomano); i++){
                numeroRomano[i] = toupper(numeroRomano[i]);
        }
}
//Funcion para validar que la cadena de caracteres ingresados pertenesca al sistema de numeros romanos
void validarNumeroRomanoCadena(char numeroRomano[]){
        char letrasNumerosRomanos[] = {'M','D','C','L','X','V','I'};
        int operar = 0;
        for(int i = 0; i < strlen(numeroRomano); i++){
                int validar = 0;
                for(int j = 0; j < strlen(letrasNumerosRomanos); j++){
                        if(numeroRomano[i] == letrasNumerosRomanos[j]){
                                validar++;
                                break;
                        }
                }
                if(validar == 0){
                        printf("El numero NO es romano\n");
                        operar++;
                        break;
                }
        }
        if(operar == 0){
		printf("El numero arabigo es: %d\n", calcularNumeroArabigo(numeroRomano));
        }
}
//Funcion principal
int main(){
	char numeroRomano[30];
	printf("Ingresa el numero romano: ");
	scanf("%s",numeroRomano);
	numeroRomanoMayusculas(numeroRomano);
	printf("Ingresaste %s\n", numeroRomano);
	if(strlen(numeroRomano)<2){
		validarNumeroRomano(numeroRomano[0]);
	} else {
		validarNumeroRomanoCadena(numeroRomano);
	}
	return 0;
}

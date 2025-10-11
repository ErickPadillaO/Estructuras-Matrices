/*Entrada: Un carácter (char) que representa el símbolo romano (I, V, X, L, C, D, M).
	Solo algunas letras pueden ir antes de otras para restar. Las combinaciones de resta son:
		(IV)(4), (IX)(9), (XL)(40), (XC)(90), (CD)(400), y (CM)(900)*/

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
int main(){
	char numeroRomano;
	printf("Ingresa el numero romano: ");
	scanf("%c",&numeroRomano);
	numeroRomano = toupper(numeroRomano);
	printf("Ingresaste %c\n", numeroRomano);
	validarNumeroRomano(numeroRomano);
	return 0;
}

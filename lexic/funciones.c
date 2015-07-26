#include <stdio.h>
#include <stdlib.h>

#define TRUE 0
#define FALSE -100
#define NOT_FOUND -100
#define ERROR_STATE -200
#define INVALID_POSITION -1
/*
	La funcion recibe un apuntador a un entero
	
*/
void referencia(int* entero1)
{
	printf("Valor %d\n",*entero1);
	/*
	*entero1=valor actual de la variable.
	*/
	*entero1=150;
}

void aumentarMatriz(int* arreglo, int* x)
{
	*(arreglo+2)=152;
	printf("Matriz %d %d %d\n",*(arreglo+0),*(arreglo+1),*(arreglo+2));
}

int isLetter(char caracter)
{
	int c=(int)caracter;
	if((c>=65 && c<=90) || (c>=97 && c<=122))
		return TRUE;
	return FALSE;
}
int isDigit(char caracter)
{
	int c=(int)caracter;
	if((c>=48 && c<=57))
		return TRUE;
	return FALSE;
}

typedef struct _state State;
struct _state
{
	int stateNum;
	int isFinal;
	int isAcceptance;
};

State* createState(int value, int isFinal, int isAcceptance)
{
	State* state=((State*)malloc(sizeof(State)));
	state->stateNum=value;
	state->isFinal=isFinal;
	state->isAcceptance=isAcceptance;
	return state;
}
#include <stdio.h>
#include <stdlib.h>
#include "funciones.c"
#include "linked_list.c"
#include "transitions.c"

//Definition of a Macro, kinf of predefined function

#define getIntArraySize(x) sizeof(x)/sizeof(int)
#define getCharArraySize(x) (sizeof(x)/sizeof(char))-1

void sampleTablaTransiciones();
int main()
{
	printf("Parametros por referencia\n");
	/*
	Un puntero preserva la direccion de memoria de una variable:
	
	&	=	obtener la direccion de memoria de una variable
	*	=	acceder a el valor de la variable
	
	*/
	
	
	char inputFile[]="transitions.txt";
	int rows,cols;
	getStatesCount(inputFile,&rows,&cols);
	if(rows==ERROR_READING || cols==ERROR_READING)
	{
		printf("Error");
		return 0;
	}
	printf("MaxEstados %d  %d\n",rows,cols);
	
	defineMatrix(inputFile, rows, cols);
	
	
	
	/*
	Lista* lista=crearLista(agregarValorLista, imprimirLista, getValorLista);
	lista->getAt=getValorLista;
	lista->imprimir(lista);
	lista->add(lista,12);
	int xs=lista->getAt(lista,2);
	if(xs==NOT_FOUND)
		printf("Valor no encontrado\n");
	else
		printf("Valor %d \n", xs);
	sampleTablaTransiciones();*/
	
	
	return 0;
}


void sampleTablaTransiciones()
{
	State* states[3];
	states[0]=createState(0, FALSE, FALSE);
	states[1]=createState(1, TRUE, TRUE);
	states[1]=createState(ERROR_STATE, TRUE, TRUE);
	
	char letter='#';
	char digit='&';
	char underscore='_';
	char alfabeto[3];
	
	alfabeto[0]=digit;
	alfabeto[1]=letter;
	alfabeto[2]=underscore;
	
	int transiciones[3][3];
	
	transiciones[0][0]=ERROR_STATE;
	transiciones[0][1]=1;
	transiciones[0][2]=ERROR_STATE;
	transiciones[1][0]=1;
	transiciones[1][1]=1;
	transiciones[1][2]=1;
	transiciones[2][0]=ERROR_STATE;
	transiciones[2][1]=ERROR_STATE;
	transiciones[2][2]=ERROR_STATE;
	char input[]="asdf1524_/*___________";
	
	printf("\n entry size %d\n", getCharArraySize(input));
	
	
	int isvalid=isValidEntry(transiciones, input,0, getCharArraySize(input),0);
	if(isvalid==TRUE)
	{
		printf("ENTRY VALIDDDDDDDDDDD");
	}else
	{
		printf("Invalid entry");
	}
	
}
int getColumn(char c)
{
	if(isLetter(c)==TRUE)
		return 1;
	if(isDigit(c)==TRUE)
		return 0;
	if(c=='_')
		return 2;
	return INVALID_POSITION;
}

int isValidEntry(int matriz[3][3], char input[], int actual, int max, int state)
{
	if(actual>=max)
		return TRUE;
	int columnState=getColumn(input[actual]);
	if(columnState==INVALID_POSITION)
	{
		printf("\nINVALID POSITION FOUND %c %d \n", input[actual], actual);
		return FALSE;
	}
	int targetState=matriz[state][columnState];
	if(targetState==ERROR_STATE)
	{
		printf("\nERROR STATE ARRIVED\n");
		return FALSE;
	}
		
	return isValidEntry(matriz, input, ++actual, max, targetState);
}

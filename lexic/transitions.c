#include <stdlib.h>
#include <stdio.h>
#include "alfabet.c"

#define ERROR_READING -200
#define START_LINE 2
#define LINE 120
#define ERROR_STATE -1

void getStatesCount(FILE* file, int* rows, int* cols )
{
	*rows=ERROR_READING;
	*cols=ERROR_READING;
	if(file != NULL)
	{
		int x=fscanf(file,"%d,%d",rows,cols);
		if(x == 2)
		{
			//Read line jump, so that the next function can start reading the next line.
			char chara='.';
			fscanf(file,"\n", &chara);
			return;
		}		
		return;
	}
	return;
}

void fillMatrix(FILE* file, Lista* lista[], int rows, int cols)
{
	if(file != NULL)
	{
		int c=0;
		int num=-1;
		int rowc=0;
		int colc=0;
		
		while((c=fscanf(file,"%d,",&num))==1)
		{
			lista[rowc]->add(lista[rowc], num);
			if(colc+1 >= cols){
				rowc++;
				colc=0;
			}else
				colc++;
		}
		for(c=0;c<40;c++)
			lista[8]->add(lista[8], -1);
		
		/*for(c=0; c<rows; c++)
		{
			lista[c]->imprimir(lista[c]);
			printf("\n\n");
		}*/
		
	}
}

void defineMatrix(FILE* file, int rows, int cols, char alfabet[], int alfabetSize)
{
	Lista* states[rows];
	int i=0;
	for(i=0; i<rows; i++)
		states[i]=crearLista(agregarValorLista, imprimirLista, getValorLista);
	fillMatrix(file, states, rows, cols);
	char input[]="incluir";
	strupr(input);
	int state=IsValidEntry(states, input, 0, 7, rows, 0, alfabet, alfabetSize);
	if(state==ERROR_STATE)
		printf("ERROR_STATE\n");
	else
		printf("FINAL STATE %d\n", state);
}


int IsValidEntry(Lista* lista[], char input[], int posicion, int limite, int rows, int state, char alfabet[], int alfabetSize)
{
	
	int column=getAlfabetColumn(alfabet, input[posicion], alfabetSize);
	//printf("Column %d for character %c \n", column, input[posicion]);
	if(column==ERROR_STATE)
	{
		return ERROR_STATE;
	}
	
	int targetState=lista[state]->getAt(lista[state], column);
	if(targetState==ERROR_STATE)
	{
		printf("ERROR: ARRIVED TO ERROR STATE\n");
		return ERROR_STATE;
	}
	if(posicion+1 >=limite)
	{
		return state;
	}
	return IsValidEntry(lista,input, ++posicion, limite, rows, targetState, alfabet, alfabetSize);
}



#include <stdlib.h>
#include <stdio.h>
#include "alfabet.c"

#define ERROR_READING -200
#define START_LINE 2
#define LINE 120
#define ERROR_STATE -1

void getStatesCount(char inputFile[], int* rows, int* cols )
{
	FILE* file;
	*rows=ERROR_READING;
	*cols=ERROR_READING;
	file=fopen(inputFile, "r");
	if(file != NULL)
	{
		int x=fscanf(file,"%d,%d",rows,cols);
		if(x == 2)
		{
			fclose(file);
			return;
		}		
		fclose(file);
		return;
	}
	fclose(file);
	return;
}

void fillMatrix(char input[], Lista* lista[], int rows, int cols)
{
	FILE* file=fopen(input,"r");
	if(file != NULL)
	{
		char line[LINE];
		int c=0;
		int num=-1;
		int startPos=2;
		int counter=0;
		int rowc=0;
		int colc=0;
		
		while((c=fscanf(file,"%d,",&num))==1)
		{
			if(counter>=2)
			{
				lista[rowc]->add(lista[rowc], num);
				if(colc+1 >= cols){
					rowc++;
					colc=0;
				}else
					colc++;
			}
			counter++;
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

void defineMatrix(char inputFile[], int rows, int cols)
{
	Lista* states[rows];
	int i=0;
	for(i=0; i<rows; i++)
		states[i]=crearLista(agregarValorLista, imprimirLista, getValorLista);
	fillMatrix(inputFile, states, rows, cols);
	char input[]="incluir";
	
	int state=IsValidEntry(states, input, 0, 7, rows, 0);
	if(state==ERROR_STATE)
		printf("ERROR_STATE\n");
	else
		printf("FINAL STATE %d\n", state);
}


int IsValidEntry(Lista* lista[], char input[], int posicion, int limite, int rows, int state)
{
	
	int column=getCharColumn(input[posicion]);
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
	return IsValidEntry(lista,input, ++posicion, limite, rows, targetState);
}



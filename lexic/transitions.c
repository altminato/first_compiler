#include <stdlib.h>
#include <stdio.h>

#define ERROR_READING -200


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
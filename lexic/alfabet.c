#include <stdio.h>
#include <stdlib.h>

int getCharColumn(char input)
{
	if(input=='a' || input=='A')
		return 0;
	else if(input=='b' || input=='B')
		return 1;
	else if(input=='c' || input=='C')
		return 2;				
	else if(input=='d' || input=='D')
		return 3;
	else if(input=='e' || input=='E')
		return 4;
	else if(input=='f' || input=='F')
		return 5;
	else if(input=='g' || input=='G')
		return 6;
	else if(input=='h' || input=='H')
		return 7;
	else if(input=='i' || input=='I')
		return 8;
	else if(input=='j' || input=='J')
		return 9;
	else if(input=='k' || input=='K')
		return 10;
	else if(input=='l' || input=='L')
		return 11;
	else if(input=='m' || input=='M')
		return 12;
	else if(input=='n' || input=='N')
		return 13;
	else if(input=='o' || input=='O')
		return 14;
	else if(input=='p' || input=='P')
		return 15;
	else if(input=='q' || input=='Q')
		return 16;
	else if(input=='r' || input=='R')
		return 17;
	else if(input=='s' || input=='S')
		return 18;
	else if(input=='t' || input=='T')
		return 19;
	else if(input=='u' || input=='U')
		return 20;
	else if(input=='v' || input=='V')
		return 21;
	else if(input=='w' || input=='W')
		return 22;
	else if(input=='x' || input=='X')
		return 23;
	else if(input=='y' || input=='Y')
		return 24;
	else if(input=='z' || input=='Z')
		return 25;
	else if(input=='0')
		return 26;
	else if(input=='1')
		return 27;
	else if(input=='2')
		return 28;
	else if(input=='3')
		return 29;
	else if(input=='4')
		return 30;
	else if(input=='5')
		return 31;
	else if(input=='6')
		return 32;
	else if(input=='7')
		return 33;
	else if(input=='8')
		return 34;
	else if(input=='9')
		return 35;
	else if(input==' ')
		return 36;
	else if(input=='\r')
		return 37;
	else if(input=='\t')
		return 38;
	else if(input=='_')
		return 39;
	else 
		return -1;
	
}
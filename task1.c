#include <stdio.h>
#include <stdlib.h>

int calcPascNumResult(int a, int b, int c);

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		printf("Error: Enter value between 1 and 20\n");
		return 1;
	}

	int i,j,v,h, pascNum, rows, inputRows = strtol(argv[1], NULL, 10);
	rows = inputRows;
	v = rows - 1;

	if (inputRows >= 1 && inputRows <= 20 && argc == 2)
	{
		for (i=1; i<=inputRows; i++)
		{
			h = 0;
			for (j=1; j<=rows; j++)
			{
				pascNum = v - h;
				printf("%6d",calcPascNumResult(v, h, pascNum));
				h += 1;
			}
			printf("\n%*s",(i*3), "");
			v -= 1;
			rows -= 1;
		}
	}
	else
	{
		printf("Error: Enter value between 1 and 20\n");
		return 1;
	}
	return 0;
}
long calcPascNum(int a)
{
	int i;
	long factRow = 1;

	/*if(a <= 1)
	{
		return 1;
	}
	else
	{
		return (a * calcPascNum(a - 1));
	}*/
	for (i = 1; i <= a; i++)
	{
		factRow = factRow * i;
	}
	return factRow;
}
int calcPascNumResult(int a, int b, int c)
{
	if ((calcPascNum(b) * calcPascNum(c)) == 0)
	{
		return 1;
	}
	else
	{
		return calcPascNum(a) / (calcPascNum(b) * calcPascNum(c));
	}
	
}
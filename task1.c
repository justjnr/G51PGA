#include <stdio.h>
#include <stdlib.h>

long long calcPascNumResult(int a, int b, int c);
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
			for (j=1; j<=rows; j++)
			{
				pascNum = v - h;
				printf("%6lld   ",calcPascNumResult(v, h, pascNum));
				h += 1;
			}
			printf("\n%*s",(i*5), "");
			h = 0;
			v -= 1;
			rows -= 1;
			//printf("%d\n", rows);
		}
	}
	else
	{
		printf("Error: Enter value between 1 and 20\n");
		return 1;
	}
}
long long calcPascNum(int a)
{
	long long factRow = 0;

	if(a <= 1)
	{
		return 1;
	}
	factRow = a * calcPascNum(a - 1);
	return factRow;
}
long long calcPascNumResult(int a, int b, int c)
{
	return calcPascNum(a) / (calcPascNum(b) * calcPascNum(c));
}
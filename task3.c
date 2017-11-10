#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int* binToArray(int a);
int calcRules(int a, int b, int c, int binArray[]);

int main(int argc, char **argv)
{
	if (argc == 1 || argc == 2 || argc == 3)
	{
		printf("Error: Enter three parameters\n");
		return 1;
	}

	char *nd;
	int i, j, inputCell = strtol(argv[1], &nd, 10), inputGen = strtol(argv[2], &nd, 10), inputRuleSet = strtol(argv[3], &nd, 10);
	int r, b = 0, ba = 1;
	int middleCell;
	int cells[inputCell], nextCells[inputCell];
	int left, current, right, nextState;
	memset(cells, 0, sizeof(cells));
	memset(nextCells, 0, sizeof(nextCells));

	if (*nd != '\0')
	{
		printf("Error: Enter three parameters\n");
		return 1;
	}
	if (inputCell >= 1 && inputGen >= 1 && inputRuleSet >= 0 && inputRuleSet <= 255 && argc == 4)
	{
		if (inputRuleSet == 0)
	    {
	    	inputRuleSet = 8;
	    }
		// Convert to binary
		while (inputRuleSet >= 1)
	    {
	        r = inputRuleSet % 2;
	        b = b + r * ba;
	        inputRuleSet = inputRuleSet / 2;
	        ba = ba * 10;
	    }
	    //printf("%08d\n", b);
        int* binArray = binToArray(b);
    	//printf("Binary[%d, %d, %d, %d, %d, %d, %d, %d]\n", binArray[0], binArray[1], binArray[2], binArray[3], binArray[4], binArray[5], binArray[6], binArray[7]);
    	// Set initial row
		middleCell = inputCell / 2;
		cells[middleCell] = 1;
    	// For each row
		for (i = 0; i < inputGen; i++)
		{	
			// For each item in row
			for (j = 0; j < inputCell; j++)
			{
				//printf("*");
				//printf("Cell[%d] = %c ", j, cells[j]);
				//printf("%c ", newCells[k]);
				left = cells[j-1];
				if (j == 0)
				{
					left = cells[inputCell - 1];
				}
				right = cells[j+1];
				if (j == (inputCell - 1))
				{
					right = cells[0];
				}
				current = cells[j];
				nextState = calcRules(left, current, right, binArray);
				nextCells[j] = nextState;
				//char * charArray = binToChar(inputCell, cells, nextCells)
				if(cells[j] == 1)
				{
					printf("*");
				}
				else
				{
					printf(" ");
				}
				//printf("%d", cells[j]);
			}
			memcpy(cells, nextCells, sizeof(cells));
			printf("\n");
		}
		return 0;
	}
	else
	{
		printf("Error: Enter three parameters\n");
		return 1;
	}
}
int* binToArray(int a)
{
	int i, n = log10(a) + 1, *binArray = calloc(n, sizeof(int[8]));
	for (i = 0; i < n; ++i)
	{
		binArray[i] = a % 10;
		a = a / 10;
	}
	return binArray;
}
int calcRules(int a, int b, int c, int binArray[])
{
	if (a == 0 && b == 0 && c == 0)
	{
		return binArray[0];
	}
	else if (a == 0 && b == 0 && c == 1)
	{
		return binArray[1];
	}
	else if (a == 0 && b == 1 && c == 0)
	{
		return binArray[2];
	}
	else if (a == 0 && b == 1 && c == 1)
	{
		return binArray[3];
	}
	else if (a == 1 && b == 0 && c == 0)
	{
		return binArray[4];
	}
	else if (a == 1 && b == 0 && c == 1)
	{
		return binArray[5];
	}
	else if (a == 1 && b == 1 && c == 0)
	{
		return binArray[6];
	}
	else if (a == 1 && b == 1 && c == 1)
	{
		return binArray[7];
	}
	return 0;
}
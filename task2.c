#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include <stdbool.h>


int calcPrime(int a, int b);

int main(int argc, char **argv)
{
	if (argc == 1 || argc == 2)
	{
		printf("Error: Enter two parameters\n");
		return 1;
	}

	int inputPrimeOne = strtol(argv[1], NULL, 10), inputPrimeTwo = strtol(argv[2], NULL, 10);

	if (inputPrimeOne >= 2 && inputPrimeTwo <= 1000000 && argc == 3)
	{
		//for (i = inputPrimeOne; i <= inputPrimeTwo; i++)
		//{
			//printf("%d\n", calcPrime(inputPrimeOne, inputPrimeTwo));
			calcPrime(inputPrimeOne, inputPrimeTwo);
		//}
	}
	else
	{
		printf("Error: Enter two positive values between 2 and 1000000\n");
		return 1;
	}
}
int calcPrime(int a, int b)
{
	int i, j, isPrime;

	for (i = a; i <= b; i++)
	{
		isPrime = 0;
		for (j = 2; j <= i/2; j++)
		{
			if (i % j == 0)
			{
				isPrime = 1;
				break;
			}
		}
		if (isPrime == 0 && b!= 1)
		{
			printf("%d\n", i);
		}
	}
	return 0;
}
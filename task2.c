#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calcPrime(int a, int b);

int main(int argc, char **argv)
{
	if (argc == 1 || argc == 2)
	{
		printf("Error: Enter two parameters\n");
		return 1;
	}
	char *nd;
	int inputPrimeOne = strtol(argv[1], &nd, 10), inputPrimeTwo = strtol(argv[2], &nd, 10);

	if (*nd != '\0')
	{
		printf("Error: Enter two positive values between 2 and 1000000\n");
		return 1;
	}
	if (inputPrimeOne >= 2 && inputPrimeTwo <= 1000000 && argc == 3)
	{
		calcPrime(inputPrimeOne, inputPrimeTwo);
	}
	else
	{
		printf("Error: Enter two positive values between 2 and 1000000\n");
		return 1;
	}
}
/*int calcPrime(int a, int b)
{
	int i, j, isPrime;

	for (i = a; i <= b; i++)
	{
		isPrime = 0;
		for (j = 2; j <= i / 2; j++)
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
}*/
void calcPrime(int a, int b)
{
	int prime[(b-a)+ 1];
	memset(prime, 0, sizeof(prime));

	for (int i = a; i * i <= (b-a); i++)
	{
		if (prime[i] == 0)
		{
			for (int j = i * 2; j <= (b-a); j += i)
			{
				prime[j] = 1;
			}
		}
	}
	for (int i = a; i <= (b-a); i++)
	{
		if (prime[i] == 0)
		{
			printf("%d\n", i);
		}
	}
}
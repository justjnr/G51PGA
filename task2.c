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
void calcPrime(int a, int b)
{
	int i, k, prime[b + 1];
	memset(prime, 0, sizeof(prime));

	for (i = 2; i*i <= b; i++)
	{
		if (prime[i] == 0)
		{
			for (int j = i * 2; j <= b; j += i)
			{
				prime[j] = 1;
			}
		}
	}
	for (k = a; k <= b; k++)
	{
		if (prime[k] == 0)
		{
			printf("%d\n", k);
		}
	}
}
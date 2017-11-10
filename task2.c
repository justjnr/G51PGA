#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void calcPrime(int a, int b)
{
	int prime[b + 1];
	memset(prime, 0, sizeof(prime));

	for (int i = 2; i*i <= b; i++)
	{
		if (prime[i] == 0)
		{
			for (int j = i * 2; j <= b; j += i)
			{
				prime[j] = 1;
			}
		}
	}
	for (int k = a; k <= b; k++)
	{
		if (prime[k] == 0)
		{
			printf("%d\n", k);
		}
	}
}
/*void calcPrime(int a, int b)
{
	int limit = 1000000;
	double root = ceil(sqrt(b));
	int rootInt = root;
	int sieve[b];
	int primes[(b/2)+1];
 	int insert = 2;
	primes[0] = 2;
	primes[1] = 3;

	for (int i = 0; i < b; i++)
	{
 		sieve[i] = 0; //Not all compilers have false as the default boolean value
	}
	for (int j = 1; j <= rootInt; j++)
	{
 		for (int k = 1; k <= rootInt; k++)
		{
			//Main part of Sieve of Atkin
			int n = (4*j*j)+(k*k);

			if (n <= b && (n % 12 == 1 || n % 12 == 5))
			{
				sieve[n] = 1;
			}
			n = (3*j*j)+(k*k);
			if (n <= b && n % 12 == 7)
			{
				sieve[n] = 1;
			}
			n = (3*j*j)-(k*k);
			if (j > k && n <= b && n % 12 == 11)
			{
				sieve[n] = 1;
			}
		}
	}
	//Mark all multiples of squares as non-prime
	for (int l = 5; l <= rootInt; l++)
	{
		if (sieve[l] == 1)
		{
	 		for (int m = l*l; m < b; m += l*l)
	 		{
	 			sieve[m] = 0;
	 		}
		}
	}
	//Add into prime array
	for (int n = a; n < b; n++)
	{
		if (sieve[n] == 1)
		{
			primes[insert] = n;
			insert++;
		}
	}
	for (int p = 0; p < insert; p++)
	{
		printf("%d\n", primes[p]);
	}
}*/
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
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include <stdbool.h>


int calcPrime(int a, int b);
int calcPow(int a, int b);

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
			printf("%d", calcPrime(inputPrimeOne, inputPrimeTwo));
		//}
	}
	else
	{
		printf("Error: Enter two positive values between 1 and 1000000\n");
		return 1;
	}
}
int calcPrime(int a, int b)
{
	int i, isPrime;

	/*int isPrime(int a)
	{
		double aa = a;
		if (a == 1)
		{
			return 0;
		}
	    if (a == 2)
	    {
	    	return 1;
	    }
	    if (a % 2 == 0)
	    {
	    	return 0;
	    }
	    int boundary = floor(sqrt(aa));

	    for (int i = 3; i <= boundary; i += 2)
	    {
	        if (a % i == 0)
	        {
	        	return 0;
	        }
	    }

    	return 1;
	}*/

	for (i = a; i <= b; i++)
	{
		/*if (i <= 1)
		{
			isPrime = 0;
		}
		if (i <= 3)
		{
			isPrime = 1;
		}
		if (i % 2 == 0 || i % 3 == 0)
		{
			isPrime = 0;
		}
		for (int j = 5; j * j <= i; j = j+6)
		{
			if (i % j == 0 || i % (j+2) == 0)
			{
				isPrime = 0;
			}
		}*/
		//isPrime = 1;

		/*if ((calcPow(5, i - 1)) % i == 1)
		{
			isPrime = 1;
		}
		else
		{
			isPrime = 0;
		}*/

		if (isPrime(i) == 1)
		{
			printf("%d\n", i);
		}
	}
}
int calcPow(int a, int b)
{
	int i, num = 1;

	for (i = 0; i < b; i++)
	{
		num *= a;
	}
	return num;
}
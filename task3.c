#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc == 1 || argc == 2 || argc == 3)
	{
		printf("Error: Enter three parameters\n");
		return 1;
	}

	char *nd;
	int inputCell = strtol(argv[1], &nd, 10), inputGen = strtol(argv[2], &nd, 10), inputRuleSet = strtol(argv[3], &nd, 10);

	if (*nd != '\0')
	{
		printf("Error: Enter three parameters\n");
		return 1;
	}
	if (inputCell >= 0 && inputGen >= 1 && inputRuleSet >= 0 && inputRuleSet <= 255 && argc == 4)
	{
		printf("Acceptable\n");
		return 0;
	}
	else
	{
		printf("Error: Enter three parameters\n");
		return 1;
	}
}
#include <stdio.h>
#include <stdlib.h>

// My functions
int powerOfTwo (int num);

int main ()
{
	printf("Enter size of input:\n");
	int inputSize = 0;
	scanf("%d", &inputSize);
	if (inputSize <= 0)
	{
		printf("Invalid size\n");
		return 0;
	}
	int* arr = (int*)malloc(sizeof(int) * inputSize);
	printf("Enter numbers:\n");
	// putting the numbers in an array
	for (int i = 0; i < inputSize; i++)
	{
		if (!scanf("%d", &arr[i]))
		{

			free(arr);
			printf("Invalid number\n");
			return 0;
		}
	}
	int* pow = (int*)calloc(inputSize, sizeof(int));

	// calculating the powers of 2 of each element
	for (int i = 0; i < inputSize; i++)
	{
		pow[i] = powerOfTwo(arr[i]);
	}

	// summing the powers
	int sum = 0;
	for (int i = 0; i < inputSize; i++)
	{
		if (pow[i] < 0)
		{
			continue;
		}
		printf("The number %d is a power of 2: %d = 2^%d\n", arr[i], arr[i] ,pow[i]);
		sum += pow[i];
	}
	printf("Total exponent sum is %d\n", sum);
	free(pow);
	free(arr);
	return 0;
}

int powerOfTwo (int num)
{
	if (num == 0) return -1;
	if (num == 1) return 0;
	int cpy = num;
	int counter = 0;
	while (num > 0)
	{
		if (num == 1) return counter;
		if (num % 2)
		{
			return -1;
		}
		else
		{
			num = num / 2;
			counter++;
		}
	}
	if ((counter % 2) == 0 && cpy < 0) return -1;
	return counter;
}
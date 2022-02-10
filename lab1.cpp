#include <stdio.h>

void f(int *a)
{
	*a = 10;
}

void printArray(int arr[], int nSize)
{
	int i;
	for (i = 0; i < nSize; i++)
	{
		printf("%d ", arr[i]);
	}
}

void Ins_Sort(int arr[], int nSize)
{
	int i, j, temp;
	
	for (i = 0; i < nSize; i++)
	{
		j = i;
		while (arr[j] < arr[j - 1])
		{
			if (arr[j - 1] > arr[j])
			{
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
			j--;
			if (j == 0)
			{
				break;
			}
		}
	}
	printArray(arr, nSize);
}

int main(void)
{
	int a = 5;
	f(&a);
	printf("%d\n", a);
	
	int arr[] = {8, 3, 1, 11, 0, 2, 1, 5, 2, 9};
	Ins_Sort(arr, sizeof(arr)/sizeof(arr[0]));
	
	return 0;
}

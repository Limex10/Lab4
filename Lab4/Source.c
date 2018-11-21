#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "random.h"
#include "genlib.h"

#define FIELD 200

double getLowFromUser(void);
double getHighFromUser(void);

int main(void)
{
	double low, high;
	double numberValues;
	int numberValuesField[FIELD];
	double x[1000];
	double avrage;
	double median;
	double deviation;


	system("chcp 1252");
	system("cls");

	printf("Programmet beräknar medelvärde, standardavvikelse och medianvärdeför en mängd flyttalsvärden.\n");
	printf("Hur många värden skall skapas mellan 1 och 200: ");
	scanf_s("%lf", &numberValues);

	/*	printf("Ange min-värde: ");
	scanf_s("%f\n", &minValue);
	printf("Ange max-värde: ");
	scanf_s("%f", &maxValue);*/

	low = getLowFromUser();
	high = getHighFromUser();
	for (int i = 0; i < numberValues; i++)
	{
		x[i] = RandomReal(low, high);
		printf("%lf ", x[i]);
	}

	getchar();

	int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	int n = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, n);
	printf("Sorted array: \n");
	printArray(arr, n);
	
	return 0;
}

double getLowFromUser(void)
{
	double low;

	printf("Ange min-värde: ");
	scanf_s("%lf", &low);
	getchar();

	return low;
}

double getHighFromUser(void)
{
	double high;

	printf("Ange max-värde: ");
	scanf_s("%lf", &high);
	getchar();

	return high;
}

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(int arr[], int n)
{

	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
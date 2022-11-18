#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n, k;
	printf("vvedite razmer kvadratnoi matrici\n");
	scanf_s("%d", &n);
	int** a = (int**)malloc(n * sizeof(int*));
	for (int i(0); i < n; i++)
	{
		*(a + i) = (int*)malloc(n* sizeof(int));
	}
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < n; j++)
		{
			printf("a[%d%d]=", i + 1, j + 1);
			scanf_s("%d", &a[i][j]);
		}
	}
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < n; j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
	k = 0;
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < n; j++)
		{
			if (a[i][j] != a[j][i])
			{
				k = 1;
			}
		}
	}
	if (k == 0)
	{
		printf("simetrichna");
	}
	else
	{
		printf("nesimetrichna");
	}
	for (int i(0); i < n; i++)
	{
		free(a[i]);
	}
	free(a);
	return 0;
}
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int  n(0), m(0), c(0), q(0);
	printf("vvedite razmer\n");
	scanf_s("%d%d", &n, &m);
	int* s = (int*)malloc(n*sizeof(int));
	int ** a = (int**)malloc(n*sizeof(int*));
	for (int i(0); i < n; i++)
	{
		*(a + i) = (int*)malloc(m*sizeof(int));
	}
	int* b = (int*)malloc(m*sizeof(int));
	printf("vvedite elementi massiva\n");
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < m; j++)
		{
			printf("a[%d%d]=", i + 1, j+1);
			scanf_s("%d", (*(a+i)+j));
		}
	}   
	printf("massiv\n");
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < m; j++)
		{
			printf("%d\t", *(*(a+i)+j));
		}
		printf("\n");
	}
	for (int i(0); i < n; i++)
	{
		*(s + i) = 0;
		for (int j(0); j < m; j++)
		{
			if (*(*(a + i) + j) > 0 && *(*(a + i) + j) % 2 == 0)
			{
				*(s + i) += *(*(a + i) + j);
			}
		}
	}
	for (int i(0); i < n; i++)
	{
		for (int k(0); k < n - i - 1; k++)
		{
			if (*(s + k) > *(s + k + 1))
			{
				b = *(a + k + 1); 
				*(a + k + 1) = *(a + k);
				*(a + k) = b;
				c = *(s + k + 1);
				*(s + k + 1) = *(s + k);
				*(s + k) = c;
			}
		}
	}
	printf("novii massiv:\n");
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < m; j++)
		{
			printf("%d\t", *(*(a + i) + j));
		}
		printf("\n");
	}
	for (int i(0); i < n; i++)
	{
		free(*(a+i));
	}
	free(a);
	free(s);
	return 0;
}
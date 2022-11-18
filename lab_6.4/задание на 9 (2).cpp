#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	int n(0), z = 0;
	float max;
	srand(time(0));
	printf("vvedite kol-vo komand\n");
	scanf_s("%d", &n);
	float** a = (float**)malloc(n * sizeof(float*));
	for (int i(0); i < n; i++)
	{
		*(a + i) = (float*)malloc(5* sizeof(float));
	}
	float* s = (float*)malloc(n * sizeof(float));
	for (int i(0); i < n; i++)
	{
		printf("team %d:\n", i + 1);
		for (int j(0); j < 5; j++)
		{
			a[i][j] = 1 + rand() % 50;
			printf("%.2f\t", a[i][j]);
		}
		printf("\n");
	}
	for (int i(0); i < n; i++)
	{
		s[i] = 0;
		for (int j(0); j < 5; j++)
		{
			s[i] += a[i][j];
		}
	}
	printf("winners:\n");
		for (int k(0); k < 3; k++)
		{
			max = *(s+0);
			for (int i(0); i < n; i++)
			{
				if (*(s + i) > max)
				{
					max = *(s + i); 
					z = i;
				}
			}
			printf("team %d result %.2f\n", z + 1, max);
			max = 0; 
			s[z] = 0;
		}
		for (int i(0); i < n; i++)
		{
			free(a[i]);
		}
		free(a);
		free(s);
		return 0;
}
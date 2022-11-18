#include<stdio.h>
#include<locale.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    setlocale(0, "");
    int row(0), sum(0), i1(1);
    float* mas = (float*)calloc(row, sizeof(float));
    printf("vvedite kolvo elementov massiva\n");
    scanf_s("%d", &row);
    printf("massiv:\n");
    for (int i(0); i != row; ++i)
    {
        mas[i] = -50 + rand() % 101;
        printf("a[%d]=%.2f\n", i + 1, mas[i]);
    }
    int max = fabs(mas[0]);
    for (int i(0); i != row; ++i)
    {
        if (fabs(mas[i]) > max)
        {
            max = mas[i];
            i1 = i + 1;
        }
    }
    printf("nomer max po modulu:%d\n", i1);
    int i(0);
    while (i < row)
    {
        if (mas[i] < 0)
        {
            i++;
        }
        else
        {
            break;
        }
    }
    if (i == row)
    {
        printf("net poloz elementov\n");
    }
    else if (i == row - 1)
    {
        printf("net elementov posle poloz\n");
    }
    else
    {
        i++;
        while (i < row)
        {
            sum += mas[i];
            i++;
        }
        printf("summa posle pervogo poloz:%d", sum);
    }
    free(mas);
}

#include "unit_test.h"

void Equals(int a, int b)
{
    if (a == b)
    {
        printf("%d equals %d", a, b);
    }
    else
    {
        printf("%d not equals %d", a, b);
    }
}

void ArrayEquals(int *a, int *b, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (a[i] != b[i])
        {
            printf("array a not equals array b.", a, b);
            printf("array a is:");
            for (int j = 0; j < length; j++)
            {
                printf("%d ", a[j]);
            }
            printf(".array b is:");
            for (int k = 0; k < length; k++)
            {
                printf("%d ", b[k]);
            }
            printf(".");
            return;
        }
    }
    printf("array a equals array b");
}

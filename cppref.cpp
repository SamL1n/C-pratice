#include <stdio.h>
#include <stdlib.h>

void modifynum(int &i)
{
    i++;
}

void modifyp(int *&p)
{
    int *a = (int*)malloc(20);
    p = a;
}

int main()
{
    int a = 10;
    modifynum(a);
    printf("%d", a);
}
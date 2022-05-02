#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int *data;
    int length;
    int maxLength;
} SqList;

void InitList(SqList *list, int initSize)
{
    list->data = (int *)malloc(sizeof(int) * initSize);
    list->maxLength = initSize;
    list->length = 0;
}

void IncreaseSize(SqList *list, int size)
{
    int *p = list->data;
    list->data = (int *)malloc((list->maxLength + size) * sizeof(int));
    for (int i = 0; i < list->length; i++)
    {
        list->data[i] = p[i];
    }
    list->maxLength += size;
    free(p);
}

bool ListInsert(SqList *list, int i, int value)
{
    if (i < 1 || i > list->length + 1)
    {
        return false;
    }

    if (list->length == list->maxLength)
    {
        //如果顺序表存满了元素，则进行扩容
        IncreaseSize(list, 1);
    }

    list->data[i - 1] = value;
    list->length++;
    return true;
}

bool ListDelete(SqList *list, int i)
{
    if (i < 1 || i > list->length)
    {
        return false;
    }

    for (int j = i; j < list->length; j++)
    {
        list->data[j - 1] = list->data[j];
    }
    list->length--;
}

bool GetElem(SqList *list, int i, int *value)
{
    if (i < 1 || i > list->length)
    {
        return false;
    }
    *value = list->data[i - 1];
    return true;
}

int LocateElem(SqList *list, int value)
{
    for (int i = 0; i < list->length; i++)
    {
        if (list->data[i] == value)
        {
            return i+1;
        }
    }
    return 0;
}
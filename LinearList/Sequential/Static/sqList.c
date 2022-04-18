#include <stdio.h>
#include <stdbool.h>

#define MaxSize 10
typedef struct
{
    int data[MaxSize];
    int length;
} SqList;

void InitList(SqList *list)
{
    for (int i = 0; i < MaxSize; i++)
    {
        list->data[i] = 0;
    }
    list->length = 0;
}

//在顺序表位序为i的位置插入元素value。
// return：true表示插入成功，false表示插入失败
bool ListInsert(SqList *list, int i, int value)
{
    //当位序越界、顺序表已经存满元素时，插入失败
    if (i < 1 || i > list->length + 1 || list->length == MaxSize)
    {
        return false;
    }

    for (int j = list->length; j >= i; j--)
    {
        list->data[j] = list->data[j - 1];
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
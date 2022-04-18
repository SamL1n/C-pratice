#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int *data;
    int length;
    int maxLength;
} SqList;

void InitList(SqList *list, int initSize);
void IncreaseSize(SqList *list, int size);
bool ListInsert(SqList *list, int i, int value);
bool ListDelete(SqList *list, int i);
bool GetElem(SqList *list, int i, int *value);
int LocateElem(SqList *list, int value);
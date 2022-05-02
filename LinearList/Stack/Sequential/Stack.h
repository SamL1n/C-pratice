typedef int ElemType;
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INIT_SIZE 20

typedef struct
{
    ElemType data[INIT_SIZE];
    int top;
} SqStack;

void InitStack(SqStack *s)
{
    s->top = -1;
}

bool Push(SqStack *s, ElemType e)
{
    if (s->top == INIT_SIZE - 1)
    {
        return false;
    }
    s->top++;
    s->data[s->top] = e;
    return true;
}

bool Pop(SqStack *s, ElemType *e)
{
    if (s->top == -1)
    {
        return false;
    }
    *e = s->data[s->top];
    s->top--;
    return true;
}

bool Get(SqStack *s, ElemType *e)
{
    if (s->top == -1)
    {
        return false;
    }
    *e = s->data[s->top];
    return true;
}

bool IsEmpty(SqStack *s)
{
    return s->top == -1;
}

bool IsFull(SqStack *s)
{
    return s->top == INIT_SIZE - 1;
}


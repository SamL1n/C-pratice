typedef int ElemType;
#include <stdbool.h>
#define INIT_SIZE 10
#define STACK0 0
#define STACK1 1

typedef struct
{
    ElemType data[INIT_SIZE];
    int top0; // 0号栈下标
    int top1; // 1号栈下标
} ShStack;

void InitStack(ShStack *s)
{
    s->top1 = INIT_SIZE;
    s->top0 = -1;
}

bool push(ShStack *s, int stack, ElemType value)
{
    if (IsFull(s))
        return false;

    if (stack == STACK0)
    {
        s->top0++;
        s->data[s->top0] = value;
        return true;
    }
    else if (stack == STACK1)
    {
        s->top1--;
        s->data[s->top1] = value;
        return true;
    }
    else
    {
        return false;
    }
}

bool Pop(ShStack *s, int stack)
{
    if (stack == STACK0)
    {
        if (s->top0 == -1)
            return false;
        s->top0--;
    }
    else if (stack == STACK1)
    {
        if (s->top1 == INIT_SIZE)
            return false;
        s->top1--;
    }
    else
        return false;

    return true;
}

bool Get(ShStack *s, int stack, ElemType *e)
{
    if (stack == STACK0)
    {
        if(s->top0 == -1)
            return false;
        *e = s->data[s->top0];
    }
    else if(stack == STACK1)
    {
        if(s->top1 == INIT_SIZE)
            return false;
        *e = s->data[s->top1];
    }
    else
        return false;

    return true;
}

bool IsFull(ShStack *s)
{
    return s->top0 + 1 == s->top1;
}

bool IsEmpty(ShStack *s)
{
    return s->top0 == -1 && s->top1 == INIT_SIZE;
}
typedef int ElemType;
#include <stdlib.h>
#include <stdbool.h>

//不带头结点的链栈
typedef struct
{
    ElemType value;
    LNode *next;
} LNode, *StackList;

void InitStack(StackList s)
{
    s = NULL;
}

bool Push(StackList s, ElemType value)
{
    LNode *node = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
    {
        s = node;
        s->next = NULL;
        s->value = value;
    }
    else
    {
        node->next = s;
        node->value = value;
        s = node;
    }
    return true;
}

bool Pop(StackList s)
{
    if (s == NULL)
    {
        return false;
    }
    LNode *p = s;
    s = s->next;
    free(p);
    return true;
}

bool Get(StackList s, ElemType *e)
{
    if (s == NULL)
    {
        return false;
    }
    else
    {
        *e = s->value;
        return true;
    }
}

bool IsEmpty(StackList s)
{
    return s == NULL;
}

void DestroyStack(StackList s)
{
    while (s)
    {
        Pop(s);
    }
}
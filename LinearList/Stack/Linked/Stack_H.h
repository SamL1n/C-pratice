typedef int ElemType;
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
    ElemType value;
    LNode *next;
} LNode, *StackList;

void InitStack(StackList s)
{
    s = (LNode *)malloc(sizeof(LNode));
    s->next = NULL;
}

bool Push(StackList s, ElemType value)
{
    LNode *node;
    node = (LNode *)malloc(sizeof(LNode));
    if (s->next == NULL)
    {
        s->next = node;
        node->next = NULL;
    }
    else
    {
        node->next = s->next;
        s->next = node;
    }
    return true;
}

bool Pop(StackList s)
{
    if (s->next == NULL)
    {
        return false;
    }
    s->next = s->next->next;
    return true;
}

bool Get(StackList s, ElemType *e)
{
    if (s->next == NULL)
    {
        return false;
    }
    *e = s->next->value;
    return true;
}

bool IsEmpty(StackList s)
{
    return s->next == NULL;
}

void DestroyStack(StackList s)
{
    while (s->next != NULL)
    {
        Pop(s);
    }
}
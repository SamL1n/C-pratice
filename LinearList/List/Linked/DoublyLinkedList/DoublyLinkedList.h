typedef int ElemType;
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct LNode
{
    ElemType value;
    struct LNode *prior;
    struct LNode *next;
} LNode, *LinkList;

void InitLisk(LinkList L)
{
    L = (LNode *)malloc(sizeof(LNode));
    L->prior = NULL;
    L->next = NULL;
}

//头插法建立链表
LinkList List_HeadInsert(LinkList L, ElemType *arr, int length)
{
    InitLisk(L);
    LNode *node;
    ElemType e;
    for (int i = 0; i < length; i++)
    {
        e = arr[i];
        node = (LNode *)malloc(sizeof(LNode));
        node->value = e;
        node->next = L->next;
        node->prior = L;
        L->next = node;
    }
    return L;
}

//尾插法建立链表
LinkList List_TailInsert(LinkList L, ElemType *arr, int length)
{
    InitLisk(L);
    LNode *tail = L;
    LNode *node;
    ElemType e;
    for (int i = 0; i < length; i++)
    {
        e = arr[i];
        node = (LNode *)malloc(sizeof(LNode));
        node->value = e;
        node->next = NULL;
        node->prior = tail;
        tail->next = node;
        tail = node;
    }
    return L;
}

//根据位序查找结点
LNode *GetElem(LinkList L, int index, LNode *node)
{
    if (index < 0)
        return NULL;

    int n = 0;
    node = L;
    while (node != NULL && n < index)
    {
        node = node->next;
        n++;
    }
    return node;
}

//根据值查找结点
LNode *LocateElem(LinkList L, ElemType e)
{
    if (L->next == NULL)
        return NULL;
    LNode *node = L->next;
    while (node && node->value != e)
    {
        node = node->next;
    }
    return node;
}

bool Insert(LinkList L, int index, ElemType e)
{
    if (index < 1)
        return false;
    LNode *node;
    GetElem(L, index, node);
    if (node == NULL)
        return false;
    LNode *new_node = (LNode *)malloc(sizeof(LNode));
    new_node->next = node;
    new_node->prior = node->prior;
    node->prior = new_node;
    return true;
}

//根据位序删除结点
bool DelNode_i(LinkList L, int i)
{
    if (i < 1)
        return false;
    LNode *node;
    GetElem(L, i, node);
    if (node == NULL)
        return false;
    node->prior->next = node->next;
    node->next->prior = node->prior;
    free(node);
    return true;
}

//销毁链表
void DestroyList(LinkList L)
{
    while (L->next)
    {
        L = L->next;
        free(L->prior);
    }
    free(L);
}
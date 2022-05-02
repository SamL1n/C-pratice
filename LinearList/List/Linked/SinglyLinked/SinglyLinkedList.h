typedef int ElemType;
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct LNode
{
    ElemType data;
    LNode *next;
} LNode, *LinkList;

//初始化单链表（生成头节点，置空头节点的next指针）
void InitList(LinkList L)
{
    L = (LNode*)malloc(sizeof(LNode));
    L->next = NULL;
}

//头插法建立单链表
LinkList List_HeadInsert(LinkList L)
{
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL; //保证链表最后一个元素的next指针为空
    LNode *node;
    ElemType n;
    while (scanf("%d", &n), n != 9999)
    {
        node = (LNode *)malloc(sizeof(LNode));
        node->data = n;
        node->next = L->next;
        L->next = node;
    }
}

//尾插法建立单链表
LinkList List_TailInsert(LinkList L)
{
    ElemType n;
    L = (LNode *)malloc(sizeof(LNode));
    LNode *node;
    LNode *last_node = L;

    while (scanf("%d", &n), n != 9999)
    {
        node = (LNode *)malloc(sizeof(LNode));
        node->data = n;
        last_node->next = node;
        last_node = node;
    }
    last_node->next = NULL;
    return L;
}

//根据位序查找结点
LNode *GetElem(LinkList L, int index, LNode *node)
{
    if (index < 0)
        return NULL;

    int n = 0;
    node = L;
    while (node && n < index)
    {
        node = node->next;
        n++;
    }
    return node;
}

//根据值查找结点
LNode *LocateElem(LinkList L, ElemType e)
{
    LNode *node = L->next;
    while (node && node->data != e)
    {
        node = node->next;
    }
    return node;
}

//前插法
bool InsertNode_before(LinkList L, int i, ElemType e)
{
    if(i < 1)
        return false;
    LNode *node;
    GetElem(L, i, node);
    if (node == NULL)
        return false;

    LNode *new_node = (LNode *)malloc(sizeof(LNode));
    new_node->data = e;
    new_node->next = node->next;
    node->next = new_node;
    new_node->data = node->data;
    node->data = e;
    return true;
}

//后插法
bool InsertNode_after(LinkList L, int i, ElemType e)
{
    LNode *node;
    GetElem(L, i - 1, node);
    if (node == NULL)
        return false;
    LNode *new_node = (LNode *)malloc(sizeof(LNode));
    new_node->data = e;
    new_node->next = node->next;
    node->next = new_node;
    return true;
}

//根据位序删除结点
bool DelNode_i(LinkList L, int i)
{
    LNode *node;
    GetElem(L, i - 1, node);
    if (node == NULL)
        return false;
    LNode *del_node = node->next;
    node->next = del_node->next;
    free(del_node);
    return true;
}

//销毁链表
void DestroyList(LinkList L)
{
    LNode *prev = L;
    LNode *next = L->next;
    while (next)
    {
        free(prev);
        prev = next;
        next = next->next;
    }

    free(prev);
}
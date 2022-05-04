#include "DoublyLinkedList.h"

int main()
{
    LinkList L;
    ElemType a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    List_HeadInsert(L, a, 10);
    LNode *node = L->next;
    while (node)
    {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\n");

    GetElem(L, 3, node);
    printf("3  %d", node->value);
    DelNode_i(L, 3);
    GetElem(L, 3, node);
    printf("4  %d", node->value);
}
#include "list.h"

int main(){
    LinkList L;
    InitList(&L);
    ListInsert(&L,1,10);
    ListInsert(&L,1,20);
    printf("删除的元素为:%d\n",ListDelete(&L,2));
    ListInsert(&L,1,30);
    ListInsert(&L,1,40);
    printf("链表的元数个数为:%d\n",ListLength(L));
    ListPrint(L);
    printf("链表的第二个元素为:%d\n",GetElem(L,2));
    printf("最后一个是:%d\n",Create(&L,11,3));

    return 0;
}

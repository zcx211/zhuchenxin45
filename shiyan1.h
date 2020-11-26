#ifndef _LIST_H_
#define _LIST_H_

#include<stdio.h>
#include<stdlib.h>

#define ERROR 0
#define OK 1

typedef int ElemType;

typedef struct Node{
    ElemType data;
    struct Node *next;
}Node,*LinkList;

int InitList(LinkList *L);
int ListInsert(LinkList *L,int i,ElemType e);
int ListDelete(LinkList *L,int i);
int ListPrint(LinkList L);
int ListEmpty(LinkList L);
int GetElem(LinkList L,int i);
int LocateElem(LinkList L,int i);
int ListClean(LinkList *L);
int ListLength(LinkList L);
int Create(LinkList *L,int n,int m);

#endif

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct Dqueue{
    ElemType data;
    struct Dqueue *prev;
    struct Dqueue *next; 
}tq;

typedef struct Node{
    tq *first_head;
    tq *first_tail;
    tq *last_head;
    tq *last_tail;
}pNode;

typedef enum status{
    first,last
}status;

void InitQueue(pNode *p);
int Empty(pNode *p);
void PushQueue(pNode *p,ElemType e,status sign);
void PopQueue(pNode *p,ElemType *e,status sign);
void DestroyQueue(pNode *p);
void GetQueue(pNode *p,ElemType *e,status sign);
int LenQueue(pNode *p);
void PrintQueue(pNode *p);


#endif

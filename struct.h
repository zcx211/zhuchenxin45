#ifndef _LIST2_H
#define _LIST2_H
#include <stdlib.h>
#include <stdio.h>

typedef int DataType;

typedef struct node_{
    DataType data;
    struct node_ *next;
} Node;

typedef struct list_{
    Node *head;
    Node *tail;
    Node *current;
} List;

void InitList(List *);
void AddHead(List *, DataType);
void AddTail(List *, DataType);
void DelNode(List *, DataType);
Node *GetNode(List *, DataType);
int Length(List *);
void DispList(List *);

#endif

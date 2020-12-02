#ifndef _COMPUTE_H_
#define _COMPUTE_H_

#include<stdio.h>
#include<stdlib.h>

#define STACKSIZE 20
#define STACKINCREMENT 10
#define MAXBUFFER 100

static char str[MAXBUFFER];

typedef char ElemType;
typedef double DataType;

typedef struct{
    ElemType *base;
    ElemType *top;
    int StackSize;
}StackChar;

typedef struct{
    DataType *base;
    DataType *top;
    int StackSize;
}StackDouble;

void InitChar(StackChar *s);
void InitDouble(StackDouble *s);
void PopChar(StackChar *s,ElemType *e);
void PopDouble(StackDouble *s,DataType *e);
void PushChar(StackChar *s,ElemType e);
void PushDouble(StackDouble *s,DataType e);
int LenChar(StackChar s);
int LenDouble(StackDouble s);
void GetChar(StackChar s,ElemType *e);
double Calculate(StackChar S,StackDouble s,ElemType str[]);

#endif

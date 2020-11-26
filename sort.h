#ifndef _SORT_H_
#define _SORT_H_

#include<stdio.h>
#define N 10

void BubbleHL(int a[],int n);
void BubbleLH(int a[],int n);
void BubbleHLflag(int a[],int n);
void SelectSort(int a[],int n);
void InsertSort(int a[],int n);
int Partition(int a[],int low,int high);
void QuickSort(int a[],int low,int high);
void QSort(int a[],int n);

#endif

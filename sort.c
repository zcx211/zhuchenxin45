#include "sort.h"

void BubbleHL(int a[],int n){
    int i,j,temp;

    for(i = 0;i < n - 1;i++){
        for(j = 0;j < n - 1;j++){
            if(a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void BubbleLH(int a[],int n){
    int i,j,temp;

    for(i = 0;i < n - 1;i++){
        for(j = n - 1;j > i;j--){
            if(a[j-1] > a[j]){
                temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
            }
        }
    }
}

void BubbleHLflag(int a[],int n){
    int i,j,temp,flag;
    
    for(i = 0;i < n - 1;i++){
        flag = 0;

        for(j = 0;j < n - 1;j++){
            if(a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = 1;
            }
        }
        if(0 == flag){
            return;
        }
    }
}

void SelectSort(int a[],int n){
    int i,j,temp,min;

    for(i = 0;i < n - 1;i++){
        min = i;

        for(j = i + 1;j < n;j++){
            if(a[j] < a[min]){
                min = j;
            }
        }

        if(min != i){
            temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }
}

void InsertSort(int a[],int n){
    int i,j,temp;
    
    for(i = 1;i < n ;i++){
        if(a[i] < a[i-1]){
            temp = a[i];

            for(j = i - 1;a[j] > temp&&j >= 0;j--){
                a[j+1] = a[j];
            }

            a[j+1] = temp;
        }
    }
}

void QSort(int a[],int n){
    QuickSort(a,0,n - 1);
}

int Partition(int a[],int low,int high){
    int pivot = a[low];
    while(low < high){
        while(low < high&&a[high] >= pivot){
            high--;
        }

        a[low] = a[high];

        while(low < high&&a[low] <= pivot){
            low++;
        }

        a[high] = a[low];
    }

    a[low] = pivot;

    return low;
}

void QuickSort(int a[],int low,int high){
    if(low < high){
        int pivotpos = Partition(a,low,high);

        QuickSort(a,low,pivotpos - 1);
        QuickSort(a,pivotpos + 1,high);
    }
}

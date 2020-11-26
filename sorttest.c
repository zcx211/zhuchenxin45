#include "sort.h"

int main(){
    int a[N],i;

    printf("请输入一个数量不超过10的数组:\n");
    for(i = 0;i < 10;i++){
        scanf("%d",&a[i]);
    }
    
    printf("初始数据为:");
    for(i = 0;i < 10;i++){
        printf("%d ",a[i]);
    }
    printf("\n");

    //BubbleHL(a,N);
    //BubbleLH(a,N);
    //BubbleHLflag(a,N);
    //SelectSort(a,N);
    //InsertSort(a,N);
    QSort(a,N);

    printf("排序后数据为:");
    for(i = 0;i < 10;i++){
        printf("%d ",a[i]);
    }
    printf("\n");

    return 0;
}

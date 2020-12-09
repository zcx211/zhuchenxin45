#include "queue.h"

int main(){
    int t;
    int y;
    pNode m;
    InitQueue(&m);
    PushQueue(&m,80,last);
    PushQueue(&m,90,first);
    PushQueue(&m,70,last);
    PushQueue(&m,60,first);
    PrintQueue(&m);
    printf("队列的元素个数为%d\n",LenQueue(&m));
    GetQueue(&m,&t,first);
    printf("队头的元素为%d\n",t);
    GetQueue(&m,&y,last);
    printf("队尾的元素为%d\n",y);

    return 0;
}

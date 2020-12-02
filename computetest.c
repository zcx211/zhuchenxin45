#include "compute.h"

int main(){
    StackChar s1;
    StackDouble s2;

    InitChar(&s1);
    InitDouble(&s2);

    printf("最后的结果为:%f",Calculate(s1,s2,str));
    printf("\n");

    return 0;

}

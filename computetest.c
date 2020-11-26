#include "compute.c"

int main(){
    StackChar s1;
    StackDouble s2;

    InitChar(&s1);
    InitDouble(&s2);
    Transform(s1);

    printf("最后的结果为:%f",Calculate(s2,str));
    printf("\n");

    return 0;

}

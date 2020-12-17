#include "pointer.h"

void exchange(int var1,int var2,int var3){
    int temp;
    int *ptr_var1,*ptr_var2,*ptr_var3;

    ptr_var1 = &var1;
    ptr_var2 = &var2;
    ptr_var3 = &var3;
    printf("输入的三个数分别为:\nvar1=%d\nvar2=%d\nvar3=%d\n",var1,var2,var3);
    printf("输入的三个数地址分别为:\nvar1=%p\nvar2=%p\nvar3=%p\n",&ptr_var1,&ptr_var2,&ptr_var3);

    temp = var2;
    var2 = var1;
    var1 = temp;
    temp = var3;
    var3 = var1;
    var1 = temp;
    ptr_var1 = &var1;
    ptr_var2 = &var2;
    ptr_var3 = &var3;
    printf("输入的三个数分别为:\nvar1=%d\nvar2=%d\nvar3=%d\n",var1,var2,var3);
    printf("输入的三个数地址分别为:\nvar1=%p\nvar2=%p\nvar3=%p",&ptr_var1,&ptr_var2,&ptr_var3);
}

void swap(int *p1,int *p2){
    int *p;
    *p = (*p1);
    *p1 = (*p2);
    *p2 = (*p);
}

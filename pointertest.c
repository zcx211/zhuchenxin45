#include "pointer.h"

int main(){
    char *str;
    int m,n,var1,var2,var3,a,b,*pt1,*pt2;

    printf("请输入三个数:\n");
    scanf("%d %d %d",&var1,&var2,&var3);
    exchange(var1,var2,var3);
    printf("\n");

    printf("请输入两个数:\n");
    scanf("%d %d",&a,&b);
    pt1 = &a;
    pt2 = &b;
    if(a < b){
        swap(pt1,pt2);
    }
    printf("%d %d",*pt1,*pt2);
    printf("\n");

    printf("请输入你想申请的初始内存大小:");
    scanf("%d",&m);
    str = (char *)malloc(m);
    strcpy(str,"shujujiegou");
    printf("String = %s,Address = %p\n",str,&str);
    printf("请输入你想增加的内存大小:");
    scanf("%d",&n);
    str = (char *)realloc(str,m);
    strcat(str,".com");
    printf("String = %s,Address = %p\n",str,&str);
    free(str);
    printf("\n");

    return 0;
}

#include "struct.h"
int main(int argc, char **argv)
{
    List *list = (List *)malloc(sizeof(List));
    InitList(list);
    AddHead(list, 6);
    AddHead(list, 15);
    AddHead(list, 20);
    AddHead(list, 2);
    AddHead(list,8);
    DispList(list);
    printf("the list is %d\n", Length(list));
    return 0;
}

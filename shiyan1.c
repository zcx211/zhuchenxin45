#include "shiyan1.h"

int InitList(LinkList *L){
    (*L) = (LinkList)malloc(sizeof(Node));
    if(NULL == (*L)){
        return ERROR;
    }

    (*L)->next = NULL;
    
    return OK;    
}

int ListInsert(LinkList *L,int i,ElemType e){
    if(i < 1){
        return ERROR;
    }

    LinkList p,s;
    int j = 0;
    p = (*L);

    while(p != NULL&&j < i - 1){
        p = p->next;
        j++;
    }

    s = (LinkList)malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    p->next = s;

    return OK;
}

int ListDelete(LinkList *L,int i){
    if(i < 1){
        return ERROR;
    }

    LinkList p,q;
    int j = 0;
    int e;
    p = (*L);

    while(p != NULL&&j < i - 1){
        p = p->next;
        j++;
    }
    if(NULL == p&&NULL == p->next){
        return ERROR;
    }

    q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);

    return e;
}

int ListPrint(LinkList L){
    LinkList p;
    p = L->next;
    
    while(p){
        printf("%d ",p->data);
        p = p->next;
    }

    printf("\n");

    return OK;
}

int ListEmpty(LinkList L){
    if(NULL == L->next){
        return OK;
    }
    else{
        return ERROR;
    }
}

int GetElem(LinkList L,int i){
    if(i < 0){
        return ERROR;
    }

    LinkList p;
    int j = 0;
    p = L;

    while(p !=NULL&&j < i){
        p = p->next;
        j++;
    }

    return p->data;
}

int LocateElem(LinkList L,ElemType e){
    LinkList p;
    int j = 1;
    p = L->next;

    while(p != NULL&&p->data != e){
        p = p->next;
        j++;
    }
    
    return j;
}

int ListClean(LinkList *L){
    LinkList p,q;
    p = (*L)->next;
    while(p){
        q = p->next;
        free(q);
        p = q;
    }

    (*L)->next = NULL;

    return OK;
}

int ListLength(LinkList L){
    LinkList p;
    int j = 0;
    p = L->next;

    while(p){
        p = p->next;
        j++;
    }

    return j;
}

int Create(LinkList *L,int n,int m){
    LinkList p,s,q,temp;
    p = (*L);
    int i = 1;

    if(n != 0){
        while(i <= n){
            s = (LinkList)malloc(sizeof(Node));
            s->data = i++;
            p->next = s;
            p = s;
        }

        s->next = (*L)->next;
    }

    free(*L);
    q = s->next;

    while(q != q->next){
        q = q->next;
        temp = q->next;
        q->next = temp->next;

        free(temp);

        q = q->next;
    }

    return q->data;
}

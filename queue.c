#include "queue.h"

void InitQueue(pNode *p){
    if(NULL == p){
        printf("error\n");
        exit(1);
    }
    else{
        p->first_head = NULL;
        p->first_tail = NULL;
        p->last_head = NULL;
        p->last_tail = NULL;
    }
}

int Empty(pNode *p){
    return p->first_head == NULL;
}

void PushQueue(pNode *p,ElemType e,status sign){
    tq *tmp = (tq*)malloc(sizeof(tq)*1);

    tmp->data = e;
    tmp->next =NULL;

    if(Empty(p)){
        p->first_head = tmp;
        p->first_tail = tmp;
        p->last_head = tmp;
        p->last_tail = tmp;
    }
    else{
        if(sign == first){
            tmp->next = p->first_head;
            p->first_head->prev = tmp;
            p->first_tail = tmp;
            p->first_head = tmp;
        }
        else{
            tmp->prev = p->last_head;
            p->last_head->next = tmp;
            p->last_tail = tmp;
            p->last_head = tmp;
        }
    }
}

void PopQueue(pNode *p,ElemType *e,status sign){
    if(Empty(p)){
        printf("error\n");
        exit(1);
    }
    else{
        if(sign == first){
            *e = p->first_head->data;
            p->first_head = p->first_head->next;
        }
        else{
            *e = p->last_head->data;
            p->last_head = p->last_head->prev;
        }
    }
}

void DestroyQueue(pNode *p){
    tq *s = p->first_head;

    if(Empty(p)){
        printf("error\n");
        exit(1);
    }
    else{
        while(s){
            p->first_head = p->first_head->next;
            free(s);
            s = p->first_head;
        }

        p->first_head = NULL;
        p->first_tail = NULL;
        p->last_head = NULL;
        p->last_tail = NULL;
        printf("the queue is destroyed successfully\n");
    }
}

void GetQueue(pNode *p,ElemType *e,status sign){
    if(Empty(p)){
        printf("the queue is NULL\n");
        exit(1);
    }
    else{
        if(sign == first){
            *e = p->first_head->data;
        }
        else{
            *e = p->last_head->data;
        }
    }
}

int LenQueue(pNode *p){
    tq *s = p->first_head;
    
    int k = 0;

    while(s){
        k++;
        s = s->next;
    }

    return k;
}

void PrintQueue(pNode *p){
    tq *s = p->first_head;

    while(s){
        printf("%d ",s->data);
        s = s->next;
    }

    printf("\n");
}

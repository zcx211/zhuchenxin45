#include "struct.h"

void InitList(List *list){
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;

    return;
}

void AddHead(List *list, DataType data){

    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if(list->head == NULL){
        list->tail = node;
    }else{
        node->next = list->head;
    }
    list->head = node;

    return;
}

void AddTail(List *list, DataType data){

    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if(list->head == NULL){
        list->head = node;
    }else{
        list->tail->next = node;
    }
    list->tail = node;

    return;
}

void DelNode(List *list, DataType data){
    Node *prev = list->head;
    Node *node = prev->next;

    while(node != NULL)    
    if(node->data == data){
        prev->next = prev->next->next;
    }else{
        prev->next = node;
    }
}

Node *GetNode(List *list, DataType data){
    Node *node = (Node *)malloc(sizeof(Node));
    node = list->head;              
    while(node != NULL){
        if(data ==node->data){
                return node;           
        }else{
            node = node->next;                        
        }
    }
    return NULL;
}    
int Length(List *list) { 
    Node *node = (Node*)malloc(sizeof(Node));
    node = list->head;              
    int i = 0; 
    while(node != NULL){
        node = node->next;
        i++;
    }
    return i;
}

void DispList(List *list){
    Node *node = (Node *)malloc(sizeof(Node));
    node = list->head;
    int i = 0;
    while(node != NULL){
        printf("the %dth node: %d\n", i + 1, node->data);
        node = node->next;
        i++;
    }
    printf("display finished\n");
    return;
}

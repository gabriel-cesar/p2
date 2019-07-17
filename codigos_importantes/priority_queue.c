#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// FIFO = First In, First Out

typedef struct NODE{
    int item;
    int priority;
    struct NODE *next;
}NODE;

typedef struct priority_queue{
    struct NODE *head;
}priority_queue;

priority_queue *create_queue(){
    priority_queue *new_queue = (priority_queue*) malloc(sizeof(priority_queue));
    new_queue->head = NULL;

    return new_queue;
}

int maximum(priority_queue *pq){
    if (pq->head == NULL) {
        printf("Priority Queue underflow");
        return -1;
    } else {
        return pq->head->item;
    }
}

void enqueue(priority_queue *pq, int i, int p){
    NODE *new_node = (NODE*) malloc(sizeof(NODE));
    new_node->item = i;
    new_node->priority = p;

    if( (pq->head == NULL) || (p > pq->head->priority) ){
        new_node->next = pq->head;
        pq->head = new_node;
    } else{
        NODE *current = pq->head;

        while( (current->next != NULL) && (current->next->priority) > p ){
            current = current->next;
        }

        new_node->next = current->next;
        current->next = new_node;
    }
}

NODE* dequeue(priority_queue *pq){
    if (pq->head == NULL) {
        printf("Priority Queue underflow");
        return NULL;
    } else {
        NODE *node = pq->head;
        pq->head = pq->head->next;
        node->next = NULL;

        return node;
    }
}

void print_pq(priority_queue *pq){
    NODE *aux = pq->head;;

    while(aux != NULL){
        printf("%d\n", aux->item);

        aux = aux->next;
    }
}

int main(){
    int i, p;
    priority_queue *pq = create_queue();

    enqueue(pq, 10, 5);
    enqueue(pq, 15, 1);

    print_pq(pq);

    dequeue(pq);
    
    print_pq(pq);

    return 0;
}
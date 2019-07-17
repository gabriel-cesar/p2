#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10

// FIFO = First In, First Out

typedef struct QUEUE{
    int current_size;
    int head;
    int tail;
    int items[MAX_QUEUE_SIZE];
}QUEUE;

QUEUE *create_queue(){
    QUEUE *new_queue = (QUEUE*) malloc(sizeof(QUEUE));

    new_queue->current_size = 0;
    new_queue->head = 0;
    new_queue->tail = MAX_QUEUE_SIZE - 1;

    return new_queue;
}

void enqueue(QUEUE *queue, int item){
    if(queue->current_size >= MAX_QUEUE_SIZE){
        printf("Queue overflow\n");
    } else {
        queue->tail = (queue->tail + 1) % MAX_QUEUE_SIZE;
        queue->items[queue->tail] = item;
        queue->current_size++;
    }
}

int dequeue(QUEUE *queue){
    if(queue->current_size == 0){
        printf("Queue underflow\n");
        return -1;
    } else {
        int dequeued = queue->items[queue->head];
        // printf("dequeued: %d head %d\n", dequeued, queue->items[queue->head]);

        queue->head = (queue->head + 1) % MAX_QUEUE_SIZE;
        // printf("dequeued: %d head %d\n", dequeued, queue->items[queue->head]);
        queue->current_size--;

        return dequeued;
    }
}

void print_queue(QUEUE *queue){
    int i;

    for(i = 0; i < queue->current_size; i++){
        printf("%d\n", queue->items[queue->head + i]);
    }
}

int main(){
    QUEUE *queue = create_queue();

    enqueue(queue, 8);
    enqueue(queue, 10);
    enqueue(queue, 13);
    enqueue(queue, 15);
    enqueue(queue, 16);

    print_queue(queue);

    int dequeued = dequeue(queue);

    print_queue(queue);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 10

int cqueue[size];
int front = -1, rear = -1;

int isfull(){
    if((front == rear + 1) || (front == 0 && rear == size-1)) return 1;
    return 0;
}

int isempty(){
    if(front == -1){
        return 1;
    }
    return 0;
}


void enqueue(){
    int item;
    printf("enter item to add: ");
    scanf("%d", &item);

    if(isfull()){
        printf("queue overflow\n");
    }

    if(front == -1){
        front = 0;
    }
    rear = (rear + 1) % size;
    cqueue[rear] = item;
}

void dequeue(){
    if(isempty()){
        printf("queue underflow\n");
    }
    printf("deleted element is: %d", cqueue[front]);
    if(front == rear){
        front = -1;
        rear = -1;
    }
    front = (front + 1) % size;
}

void display(){
    int i;
    if(isempty()){
        printf("queue is empty\n");
    }

    for(i = front; i != rear; i = (i + 1) % size){
        printf("%d ", cqueue[i]);
    }
    printf("%d", cqueue[i]);
}

int main(){
    int choice;
    while(1){
        printf("\n-------------MENU--------------\n");
        printf("1. insert\n");
        printf("2. delete\n");
        printf("3. display\n");
        printf("4. exit\n");
        printf("\nenter ur choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: exit(0);
}}}
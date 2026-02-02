#include <stdio.h>
#include <stdlib.h>
#define size 10

int pq[size];
int front = -1, rear = -1;

int isfull(){
    if(rear == size - 1)
        return 1;
    return 0;
}

int isempty(){
    if(front == -1)
        return 1;
    return 0;
}

void enqueue(){
    int item, i;
    printf("enter item to add: ");
    scanf("%d", &item);

    if(isfull()){
        printf("priority queue overflow\n");
        return;
    }

    if(front == -1){   // first element
        front = 0;
        rear = 0;
        pq[rear] = item;
        return;
    }

    // shifting elements to maintain ascending order
    for(i = rear; i >= front && pq[i] > item; i--){
        pq[i + 1] = pq[i];
    }

    pq[i + 1] = item;
    rear++;
}

void dequeue(){
    if(isempty()){
        printf("priority queue underflow\n");
        return;
    }

    printf("deleted element is: %d\n", pq[front]);

    if(front == rear){
        front = -1;
        rear = -1;
    }
    else{
        front++;
    }
}

void display(){
    int i;
    if(isempty()){
        printf("priority queue is empty\n");
        return;
    }

    printf("priority queue elements are:\n");
    for(i = front; i <= rear; i++){
        printf("%d ", pq[i]);
    }
    printf("\n");
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
            default: printf("invalid choice\n");
        }
    }
}

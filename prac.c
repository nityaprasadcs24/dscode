#include <stdio.h>
#include <stdlib.h>
#define size 50

int q_arr[size];
int front = -1, rear = -1;

void enqueue(){
    int item;
    if(rear == size - 1){
        printf("queue overflow\n");
    }
    if(front == -1){
        front = 0;
    }
    printf("enter item to add: ");
    scanf("%d", &item);
    rear = rear + 1;
    q_arr[rear] = item;
    printf("successfully inserted %d", item);
}

void dequeue(){
    if(front == -1 || front > rear){
        printf("queue underflow\n");
    }

    printf("Deleted item is %d", q_arr[front]);
    front++;
}

void display(){
    if(front == -1){
        printf("queue is empty brah\n");
    }

    printf("queue is:\n");
    for(int i = front; i <= rear; i++){
        printf("%d ", q_arr[i]);
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
        }
    }
}


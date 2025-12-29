#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int stack[SIZE];
int top = -1;

void push(int value) {
    if (top == SIZE - 1) {
        printf("The stack is full, cannot push a value\n");
    } else {
        stack[++top] = value;
        printf("Value has been pushed into stack\n");
    }
}

void pop() {
    if (top == -1) {
        printf("The stack is empty, cannot pop a value\n");
    } else {
        printf("The popped value is %d\n", stack[top--]);
    }
}

void peek() {
    if (top == -1) {
        printf("Stack is empty, cannot peek\n");
    } else {
        printf("Top value is %d\n", stack[top]);
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int value, choice;

    while (1) {
        printf("\n MENU \n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

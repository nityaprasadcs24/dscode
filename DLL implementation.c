#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[100];
    struct Node *prev;
    struct Node *next;
} Node;

Node* createNode(char value[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    strcpy(newNode->data, value);
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void displayList(Node *head) {
    Node *temp = head;

    printf("\nDoubly Linked List Structure:\n");
    printf("-----------------------------------------------\n");
    printf("|%-12s|%-12s|%-10s|%-12s|\n",
           "Node Addr", "Prev Addr", "Data", "Next Addr");
    printf("-----------------------------------------------\n");

    while (temp != NULL) {
        printf("|%-12p|%-12p|%-10s|%-12p|\n",
               (void*)temp,
               (void*)temp->prev,
               temp->data,
               (void*)temp->next);
        temp = temp->next;
    }

    printf("-----------------------------------------------\n");
}

int main() {
    Node *N1 = createNode("Nitya");
    Node *N2 = createNode("smruthi");
    Node *N3 = createNode("Liesha");
    Node *N4 = createNode("Aditi");
    Node *N5 = createNode("Piggy");

    N1->next = N2;

    N2->prev = N1;
    N2->next = N3;

    N3->prev = N2;
    N3->next = N4;

    N4->prev = N3;
    N4->next = N5;

    N5->prev = N4;

    displayList(N1);

    free(N1);
    free(N2);
    free(N3);
    free(N4);
    free(N5);

    return 0;
}

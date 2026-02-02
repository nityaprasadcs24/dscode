#include <stdio.h> //firs
#include <stdlib.h>

// NODE IMPLEMENTATION FOR CIRCULAR LINKED LIST
struct Node {
    int data;
    struct Node *next;
};


void insertFirst(struct Node** head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); // ALLOCATE SPACE FOR NEW NODE
    new_node->data = new_data;
    
    if(*head == NULL) {
        // CASE 1: EMPTY LIST - NEW NODE POINTS TO ITSELF
        *head = new_node;
        new_node->next = *head;
    } else {
        // CASE 2: NON-EMPTY LIST
        struct Node* last = *head; 
        
        // FIND LAST NODE (WHICH POINTS TO HEAD IN CIRCULAR LIST)
        while(last->next != *head) {
            last = last->next;
        }
        
        // INSERT AT BEGINNING
        new_node->next = *head;     // NEW NODE POINTS TO CURRENT HEAD
        last->next = new_node;      // LAST NODE POINTS TO NEW NODE
        *head = new_node;           // UPDATE HEAD TO NEW NODE
    }
    
    printf("Inserted %d at beginning\n", new_data);
}


void insertLast(struct Node** head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    
    if(*head == NULL) {
        // CASE 1: EMPTY LIST - NEW NODE IS THE ONLY NODE
        *head = new_node;
        new_node->next = *head;
    } else {
        // CASE 2: NON-EMPTY LIST
        struct Node* last = *head;
        
        // FIND LAST NODE
        while(last->next != *head) {
            last = last->next;
        }
        
        // INSERT AT END
        last->next = new_node;      // LAST NODE POINTS TO NEW NODE
        new_node->next = *head;     // NEW NODE POINTS TO HEAD (CIRCULAR)
    }
    
    printf("Inserted %d at end\n", new_data);
}


void insertAt(struct Node** head, int position, int new_data) {
    // VALIDATE POSITION
    if(position <= 0) {
        printf("Invalid position %d. Position must be >= 1\n", position);
        return;
    }
    
    // SPECIAL CASE: INSERT AT BEGINNING (POSITION 1)
    if(position == 1) {
        insertFirst(head, new_data);
        return;
    }
    
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    
    struct Node* current = *head;
    int count = 1;
    
    // TRAVERSE TO NODE JUST BEFORE TARGET POSITION
    while(current != NULL && count < position - 1) {
        current = current->next;
        count++;
        
        // IF WE'RE BACK AT HEAD BEFORE REACHING POSITION, LIST IS TOO SMALL
        if(current == *head) {
            printf("Position %d exceeds list size\n", position);
            free(new_node);
            return;
        }
    }
    
    // CHECK IF POSITION IS VALID
    if(current == NULL) {
        printf("Invalid position %d\n", position);
        free(new_node);
        return;
    }
    
    // INSERT NEW NODE
    new_node->next = current->next;  // NEW NODE POINTS TO WHAT PREVIOUS NODE WAS POINTING TO
    current->next = new_node;        // PREVIOUS NODE POINTS TO NEW NODE
    
    printf("Inserted %d at position %d\n", new_data, position);
}

// ==================== DELETE FIRST NODE ====================
void deleteFirst(struct Node** head) {
    if(*head == NULL) {
        printf("List is empty - Cannot delete\n");
        return;
    }
    
    struct Node* toDelete = *head;
    
    // CASE 1: ONLY ONE NODE IN THE LIST
    if((*head)->next == *head) {
        *head = NULL;  // LIST BECOMES EMPTY
    } 
    // CASE 2: MULTIPLE NODES
    else {
        struct Node* last = *head;
        
        // FIND LAST NODE
        while(last->next != *head) {
            last = last->next;
        }
        
        // UPDATE HEAD AND LAST NODE
        *head = (*head)->next;  // HEAD NOW POINTS TO SECOND NODE
        last->next = *head;     // LAST NODE POINTS TO NEW HEAD
    }
    
    free(toDelete);  // FREE MEMORY OF DELETED NODE
    printf("Deleted first node\n");
}

// ==================== DELETE LAST NODE ====================
void deleteLast(struct Node** head) {
    if(*head == NULL) {
        printf("List is empty - Cannot delete\n");
        return;
    }
    
    struct Node* current = *head;
    struct Node* previous = NULL;
    
    // CASE 1: ONLY ONE NODE IN THE LIST
    if((*head)->next == *head) {
        free(*head);
        *head = NULL;
    } 
    // CASE 2: MULTIPLE NODES
    else {
        // TRAVERSE TO FIND LAST NODE AND SECOND-LAST NODE
        while(current->next != *head) {
            previous = current;       // SECOND-LAST NODE
            current = current->next;  // LAST NODE
        }
        
        // UPDATE SECOND-LAST NODE TO POINT TO HEAD
        previous->next = *head;
        
        // FREE LAST NODE
        free(current);
    }
    
    printf("Deleted last node\n");
}

// ==================== DELETE AT RANDOM POSITION ====================
void deleteAt(struct Node** head, int position) {
    // CHECK IF LIST IS EMPTY
    if(*head == NULL) {
        printf("List is empty - Cannot delete\n");
        return;
    }
    
    // VALIDATE POSITION
    if(position <= 0) {
        printf("Invalid position %d. Position must be >= 1\n", position);
        return;
    }
    
    // SPECIAL CASE: DELETE FIRST NODE (POSITION 1)
    if(position == 1) {
        deleteFirst(head);
        return;
    }
    
    struct Node* current = *head;
    struct Node* previous = NULL;
    int count = 1;
    
    // TRAVERSE TO THE TARGET POSITION
    do {
        previous = current;
        current = current->next;
        count++;
    } while(current != *head && count < position);
    
    // CHECK IF POSITION IS VALID
    if(count != position || current == *head) {
        printf("Position %d exceeds list size\n", position);
        return;
    }
    
    // DELETE THE NODE AT POSITION
    previous->next = current->next;  // BYPASS THE NODE TO BE DELETED
    free(current);                   // FREE MEMORY OF DELETED NODE
    
    printf("Deleted node at position %d\n", position);
}

// ==================== DISPLAY THE CIRCULAR LIST ====================
void displayList(struct Node* head) {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct Node* current = head;
    printf("Circular List: ");
    
    // USE DO-WHILE TO ENSURE AT LEAST ONE ITERATION FOR CIRCULAR LIST
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while(current != head);
    
    printf("(back to head)\n");
}

// ==================== COUNT NUMBER OF NODES ====================
void count_nodes(struct Node** head) {
    if(*head == NULL) {
        printf("Number of nodes: 0\n");
        return;
    }
    
    struct Node* current = *head;
    int count = 0;
    
    do {
        count++;
        current = current->next;
    } while(current != *head);
    
    printf("Number of nodes: %d\n", count);
}

// ==================== SEARCH FOR AN ITEM ====================
void search(struct Node** head) {
    if(*head == NULL) {
        printf("List is empty - Cannot search\n");
        return;
    }
    
    int item, found = 0, position = 1;
    printf("Enter the item you want to search: ");
    scanf("%d", &item);
    
    struct Node* current = *head;
    
    do {
        if(current->data == item) {
            printf("Item %d found at position %d\n", item, position);
            found = 1;
        }
        position++;
        current = current->next;
    } while(current != *head);
    
    if(!found) {
        printf("Item %d not found in the list\n", item);
    }
}

// ==================== REVERSE THE CIRCULAR LIST ====================
void reverse(struct Node** head) {
    if(*head == NULL || (*head)->next == *head) {
        // EMPTY LIST OR SINGLE NODE - ALREADY REVERSED
        printf("List reversed (or empty/single node)\n");
        return;
    }
    
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    struct Node* last = *head;
    
    // FIND THE LAST NODE FIRST
    while(last->next != *head) {
        last = last->next;
    }
    
    // REVERSE THE LINKS
    do {
        next = current->next;        // STORE NEXT NODE
        current->next = prev;        // REVERSE THE LINK
        prev = current;              // MOVE PREV FORWARD
        current = next;              // MOVE CURRENT FORWARD
    } while(current != *head);
    
    // UPDATE HEAD AND MAINTAIN CIRCULAR PROPERTY
    (*head)->next = prev;  // OLD HEAD NOW POINTS TO NEW HEAD
    *head = prev;          // UPDATE HEAD TO NEW FIRST NODE
    last->next = *head;    // LAST NODE POINTS TO NEW HEAD
    
    printf("List reversed\n");
}

// ==================== CONCATENATE TWO CIRCULAR LISTS ====================
void concatenate(struct Node** list1, struct Node* list2) {
    if(*list1 == NULL) {
        *list1 = list2;
        printf("Concatenated: First list was empty\n");
        return;
    }
    
    if(list2 == NULL) {
        printf("Concatenated: Second list was empty\n");
        return;
    }
    
    struct Node* last1 = *list1;
    struct Node* last2 = list2;
    
    // FIND LAST NODE OF FIRST LIST
    while(last1->next != *list1) {
        last1 = last1->next;
    }
    
    // FIND LAST NODE OF SECOND LIST
    while(last2->next != list2) {
        last2 = last2->next;
    }
    
    // CONNECT THE LISTS
    last1->next = list2;   // LAST OF LIST1 POINTS TO FIRST OF LIST2
    last2->next = *list1;  // LAST OF LIST2 POINTS TO FIRST OF LIST1
    
    printf("Concatenated two lists\n");
}

// ==================== MAIN FUNCTION ====================
int main() {
    // FIRST CIRCULAR LIST
    struct Node* head1 = NULL;
    printf("\n=== Operating on First Circular List ===\n");
    
    insertFirst(&head1, 10);
    insertFirst(&head1, 5);
    insertLast(&head1, 20);
    insertLast(&head1, 30);
    insertAt(&head1, 3, 15);  // INSERT 15 AT POSITION 3
    displayList(head1);
    
    count_nodes(&head1);
    
    deleteFirst(&head1);
    displayList(head1);
    
    deleteLast(&head1);
    displayList(head1);
    
    insertLast(&head1, 40);
    insertLast(&head1, 50);
    displayList(head1);
    
    deleteAt(&head1, 2);  // DELETE AT POSITION 2
    displayList(head1);
    
    // SEARCH OPERATION
    search(&head1);
    
    // REVERSE OPERATION
    reverse(&head1);
    displayList(head1);
    
    // SECOND CIRCULAR LIST
    struct Node* head2 = NULL;
    printf("\n=== Operating on Second Circular List ===\n");
    
    insertFirst(&head2, 100);
    insertLast(&head2, 200);
    insertLast(&head2, 300);
    displayList(head2);
    
    // CONCATENATE TWO LISTS
    printf("\n=== Concatenating Lists ===\n");
    concatenate(&head1, head2);
    displayList(head1);
    count_nodes(&head1);
    
    return 0;
}
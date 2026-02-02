#include <stdio.h>
#include <stdlib.h>

// NODE IMPLEMENTATION FOR DOUBLY LINKED LIST
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

// INSERT AT START FUNCTION
void insertFirst(struct Node** head, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); // ALLOCATE SPACE FOR NEW NODE
    new_node->data = new_data;
    new_node->prev = NULL;
    
    if(*head == NULL){
        new_node->next = NULL;      // ONLY NODE IN LIST
        *head = new_node;           // MAKE HEAD POINT TO NEW NODE
    }
    else{
        new_node->next = *head;     // NEW NODE POINTS TO CURRENT HEAD
        (*head)->prev = new_node;   // CURRENT HEAD'S PREV POINTS TO NEW NODE
        *head = new_node;           // UPDATE HEAD TO NEW NODE
    }
    printf("Inserted %d at beginning\n", new_data);
}

// INSERT AT END FUNCTION
void insertLast(struct Node** head, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    
    if(*head == NULL){                    // CHECK IF LIST IS EMPTY
        new_node->prev = NULL;           // FIRST NODE HAS NO PREV
        *head = new_node;                // MAKE HEAD POINT TO NEW NODE
    }
    else{
        struct Node* last = *head;
        while(last->next != NULL){       // TRAVERSE TO LAST NODE
            last = last->next;
        }
        last->next = new_node;           // LAST NODE POINTS TO NEW NODE
        new_node->prev = last;           // NEW NODE'S PREV POINTS TO LAST NODE
    }
    printf("Inserted %d at end\n", new_data);
}

// INSERT AT RANDOM USER-DEFINED POSITION
void insertAt(struct Node** head, int position, int new_data){
    if(position == 0){                    // POSITION 0 = INSERT AT BEGINNING
        insertFirst(head, new_data);
        return;
    }
    
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    
    struct Node* current = *head;
    for(int i = 0; current != NULL && i < position - 1; i++){    // TRAVERSE TO ONE NODE BEFORE TARGET
        current = current->next;
    }
    
    if(current == NULL){
        printf("Invalid position %d\n", position);     // CHECK IF POSITION EXISTS
        free(new_node); //dtm
        return;
    }
    
    new_node->next = current->next;   // NEW NODE POINTS TO WHAT CURRENT WAS POINTING TO
    new_node->prev = current;         // NEW NODE'S PREV POINTS TO CURRENT
    
    if(current->next != NULL){        // IF NOT INSERTING AT END
        current->next->prev = new_node;  // NEXT NODE'S PREV POINTS TO NEW NODE
    }
    
    current->next = new_node;         // CURRENT NODE POINTS TO NEW NODE
    printf("Inserted %d at position %d\n", new_data, position);
}

// DELETE FIRST NODE FUNCTION
void deleteFirst(struct Node** head){
    if(*head == NULL){
        printf("List is empty\n");
        return;
    }
    
    struct Node* temp = *head;
    *head = (*head)->next;             // MAKE HEAD POINT TO SECOND NODE
    
    if(*head != NULL){                 // IF LIST NOT EMPTY AFTER DELETION
        (*head)->prev = NULL;          // NEW HEAD'S PREV IS NULL
    }
    
    free(temp);                        // FREE MEMORY OF DELETED NODE
    printf("Deleted first node\n");
}

// DELETE LAST NODE FUNCTION
void deleteLast(struct Node** head){
     if(*head == NULL){
        printf("List is empty\n");
        return;
    }
    
    if((*head)->next == NULL){         // CHECK IF ONLY ONE NODE
        free(*head);
        *head = NULL;
        printf("Deleted last and only node\n");
        return;
    }
    
    struct Node* last = *head;
    while(last->next != NULL){         // TRAVERSE TO LAST NODE
        last = last->next;
    }
    
    last->prev->next = NULL;           // SECOND-LAST NODE'S NEXT IS NULL
    free(last);                        // FREE LAST NODE
    printf("Deleted last node\n");
}

// DELETE AT RANDOM POSITION
void deleteAt(struct Node** head, int position){
     if(*head == NULL){
        printf("List is empty\n");
        return;
    }
    
    if(position == 0){                 // POSITION 0 = DELETE FIRST NODE
        deleteFirst(head);
        return;
    }
    
    struct Node* current = *head;
    for(int i = 0; current != NULL && i < position; i++){    // TRAVERSE TO NODE TO BE DELETED
        current = current->next;
    }
    
    if(current == NULL){
        printf("Cannot delete at position %d; invalid.\n", position);
        return;
    }
    
    if(current->next != NULL){                 // IF NOT LAST NODE
        current->next->prev = current->prev;   // NEXT NODE'S PREV POINTS TO CURRENT'S PREV
    }
    
    if(current->prev != NULL){                 // IF NOT FIRST NODE
        current->prev->next = current->next;   // PREV NODE'S NEXT POINTS TO CURRENT'S NEXT
    }
    
    free(current);                            // FREE MEMORY OF NODE TO BE DELETED
    printf("Deleted node at position %d\n", position);
}

// DISPLAY THE LIST FUNCTION (FORWARD)
void displayList(struct Node* node){
    while(node != NULL){
        printf("%d <-> ", node->data);
        node = node->next;
    }
    printf("NULL \n"); 
}

// DISPLAY THE LIST FUNCTION (BACKWARD)
void displayListBackward(struct Node* node){
    if(node == NULL){
        printf("List is empty\n");
        return;
    }
    
    // FIRST GO TO LAST NODE
    while(node->next != NULL){
        node = node->next;
    }
    
    // NOW TRAVERSE BACKWARD USING PREV POINTERS
    printf("List (Backward): ");
    while(node != NULL){
        printf("%d <-> ", node->data);
        node = node->prev;
    }
    printf("NULL \n");
}

// SEARCH FOR AN ITEM'S POSITION 
void search(struct Node** head){
    struct Node* ptr = *head;
    int item, flag = 0, i = 0;

    if(ptr == NULL){
        printf("List is empty\n");
        return;
    }

    else{
        printf("\nEnter the item you want to search: \n");
        scanf("%d", &item);
        while(ptr != NULL){
        if(ptr -> data == item){
            printf("Item found at location %d\n", i);
            flag = 1;
        }
        i++;
        ptr = ptr -> next;
    }
    }
    if(flag == 0){
        printf("Item not found\n");
    }
}

// COUNT NUMBER OF NODES IN THE LIST
void count_nodes(struct Node** head){
    struct Node* temp = *head;
    int count = 0;

    while(temp != NULL){
        temp = temp -> next;  // TRAVERSE THROUGH THE LIST TILL LAST NODE IS REACHED
        count++;             // INCREMENT COUNT
    }

    printf("Number of nodes: %d\n", count);
}

// REVERSE THE LIST
void reverse(struct Node** head){
    struct Node* current = *head;
    struct Node* temp = NULL;
    
    if(*head == NULL || (*head)->next == NULL){
        printf("List reversed (or empty/single node)\n");
        return;
    }
    
    while(current != NULL){
        // SWAP NEXT AND PREV POINTERS
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        
        // MOVE TO NEXT NODE (USING PREV BECAUSE WE SWAPPED)
        current = current->prev;
    }
    
    // UPDATE HEAD TO NEW FIRST NODE
    if(temp != NULL){
        *head = temp->prev;
    }
    
    printf("List reversed\n");
}

// ATTACHING LIST1 TO LIST2; NO SORTING; ORDER MATTERS
void concatenate(struct Node** list1, struct Node* list2){
    if(*list1 == NULL){
        *list1 = list2;
        printf("Concatenated: First list was empty\n");
        return;
    }

    if(list2 == NULL){
        printf("Concatenated: Second list was empty\n");
        return;
    }

    struct Node* current = *list1;
    while(current->next != NULL){
        current = current->next;
    }

    current->next = list2;        // LAST OF LIST1 POINTS TO FIRST OF LIST2
    list2->prev = current;        // FIRST OF LIST2'S PREV POINTS TO LAST OF LIST1
    printf("Concatenated two lists\n");
}

// MERGING TWO PRE-SORTED LISTS TOGETHER TO FORM ONE SORTED LIST
void merge(struct Node** result, struct Node* list1, struct Node* list2){

    if(list1 == NULL){ 
        *result = list2; 
        return;               // IF LIST1 IS EMPTY, ONLY LIST2 GETS PRINTED AS RESULT
    }
    if(list2 == NULL){ 
        *result = list1; 
        return;              // IF LIST2 IS EMPTY, ONLY LIST1 GETS PRINTED AS RESULT
    }

    struct Node dummy;                                    // TEMPORARY NODE THAT SITS AT START
    struct Node* tail = &dummy;                          // TAIL ALWAYS POINTS TO LAST NODE IN MERGED LIST
    dummy.next = NULL;                                  
    dummy.prev = NULL;

    while(list1 != NULL && list2 != NULL){            // WHILE BOTH LISTS HAVE NODES  
        if(list1 -> data <= list2 -> data){          // IF LIST1'S DATA <= LIST2'S DATA
            tail->next = list1;
            list1->prev = tail;
            list1 = list1->next;                 // MOVE LIST1 FORWARD
        }
        else{
            tail->next = list2;               // ELSE LIST2'S DATA IS SMALLER
            list2->prev = tail;
            list2 = list2->next;             // MOVE LIST2 FORWARD
        }
        tail = tail->next;                 // MOVE TAIL FORWARD
    }

    // ATTACH REMAINING NODES
    if(list1 != NULL){
        tail->next = list1;
        list1->prev = tail;
    }
    else{
        tail->next = list2;
        if(list2 != NULL){
            list2->prev = tail;
        }
    }

    // SET UP HEAD AND FIRST NODE'S PREV
    *result = dummy.next;
    if(*result != NULL){
        (*result)->prev = NULL;
    }
}

int main(){
    printf("=== DOUBLY LINKED LIST OPERATIONS ===\n\n");

    // FIRST LIST
    struct Node* head = NULL;
    insertFirst(&head, 10);
    insertFirst(&head, 5);
    
    insertLast(&head, 20);
    insertLast(&head, 30);
    
    insertAt(&head, 2, 15);  // INSERT 15 AT POSITION 2 (0-BASED)
    insertAt(&head, 0, 1);   // INSERT 1 AT BEGINNING (POSITION 0)
    
    printf("\nDisplaying forward: ");
    displayList(head);
    
    printf("Displaying backward: ");
    displayListBackward(head);
    
    count_nodes(&head);
    
    // DELETE OPERATIONS
    printf("\n--- Testing Delete Operations ---\n");
    deleteFirst(&head);
    printf("After deleting first: ");
    displayList(head);
    
    deleteLast(&head);
    printf("After deleting last: ");
    displayList(head);
    
    deleteAt(&head, 1);  // DELETE AT POSITION 1
    printf("After deleting at position 1: ");
    displayList(head);
    
    // SEARCH
    search(&head);
    
    // REVERSE
    printf("\n--- Testing Reverse ---\n");
    reverse(&head);
    printf("After reverse: ");
    displayList(head);
    
    // SECOND LIST
    printf("\n--- Creating Second List ---\n");
    struct Node* head1 = NULL;
    insertFirst(&head1, 50);
    insertLast(&head1, 60);
    insertLast(&head1, 70);
    printf("Second list: ");
    displayList(head1);
    
    // CONCATENATE
    printf("\n--- Concatenating Lists ---\n");
    concatenate(&head, head1);
    printf("After concatenation: ");
    displayList(head);
    
    // MERGE SORTED LISTS
    printf("\n--- Testing Merge of Sorted Lists ---\n");
    struct Node* sorted1 = NULL;
    struct Node* sorted2 = NULL;
    
    // CREATE TWO SORTED LISTS
    insertLast(&sorted1, 10);
    insertLast(&sorted1, 30);
    insertLast(&sorted1, 50);
    
    insertLast(&sorted2, 20);
    insertLast(&sorted2, 40);
    insertLast(&sorted2, 60);
    
    printf("Sorted List 1: ");
    displayList(sorted1);
    printf("Sorted List 2: ");
    displayList(sorted2);
    
    struct Node* merged_list = NULL;
    merge(&merged_list, sorted1, sorted2);
    printf("Merged Sorted List: ");
    displayList(merged_list);
    
    return 0;
}
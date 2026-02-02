#include <stdio.h>
#include <stdlib.h>


//NODE IMPLEMENTATION (DEFINE STRUCTURE OF A NODE)

struct Node{
    int data;
    struct Node *next;
};

// INSERT AT START FUNCTION
void insertFirst(struct Node** head, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); //ALLOCATE SPACE FOR THE NEW NODE
    new_node -> data = new_data;
    new_node -> next = *head;
    *head = new_node;
}

// INSERT AT END FUNCTION
void insertLast(struct Node** head, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node -> data = new_data;
    new_node -> next = NULL;

    if(*head==NULL){       //CHECK IF LIST IS EMPTY
        *head = new_node;  //MAKES HEAD POINT TO THE NEW NODE 
        return;
    }

    struct Node* last = *head;
    while(last -> next != NULL){  //TRAVERSE THROUGH THE LIST UNTIL LAST IS AT THE LAST NODE
        last = last -> next;
    }

    last -> next = new_node;
}


// INSERT AT RANDOM USER-DEFINED POSITION
void insertAt(struct Node** head, int position, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node -> data = new_data;

    if(position == 0){            //IF ELEMENT IS TO BE INSERTED IN THE FIRST POSITION, USE SAME LOGIC AS insertFirst()
        new_node -> next = *head;
        *head = new_node;
        return;
    }

    struct Node* current = *head;
    for(int i = 0; current != NULL && i < position - 1; i++){    //TRAVERSE THROUGH THE LIST TO REACH ONE NODE BEFORE THE TARGET NODE
        current = current -> next;
    }

    if(current == NULL){
        printf("Invalid position %d", position);     //CHECK IF POSITION EXISTS
        return;
    }

    new_node -> next = current -> next;   //MAKE NEW NODE POINT TO WHAT THE PREVIOUS NODE WAS POINTING TO
    current -> next = new_node;          //MAKE THE PREVIOUS NODE POINT TO THE NEW NODE
}


//DELETE FIRST NODE FUNCTION
void deleteFirst(struct Node** head){
    if(*head == NULL){
        printf("list is empty");
        return;
    }

    struct Node* temp = *head;
    *head = (*head) -> next;             //MAKE HEAD POINT TO THE SECOND NODE(WHICH WILL BECOME THE NEW FIRST NODE)
    free(temp);                         //FREE/RELEASE THE MEMORY AT THE ADDRESS OF THE PREVIOUS FIRST NODE
    printf("Deleted first node\n");
}


//DELETE LAST NODE FUNCTION
void deleteLast(struct Node** head){
     if(*head == NULL){
        printf("list is empty");
        return;
    }

    if((*head) -> next == NULL){                    //CHECK IF THERE IS ONLY ONE NODE IN THE LIST
        free(*head);                               //FREE MEMORY AT ADDRESS OF THE ONLY NODE
        *head = NULL;                             //MAKE HEAD POINT TO NULL AS THERE ARE NO NODES NOW
        printf("Deleted last and only node\n");
    }

    struct Node* last = *head;                //GET TO THE SECOND LAST NODE
    while(last -> next -> next != NULL){
        last = last -> next;
    }

    free(last -> next);                   //FREE MEMORY STORED AT ADDRESS OF LAST NODE
    last -> next = NULL;                 //MAKE NEW LAST NODE POINT TO NULL
    printf("Deleted last node\n");
}


//DELETE AT RANDOM POSITION
void deleteAt(struct Node** head, int position){
     if(*head == NULL){
        printf("list is empty");
        return;
    }

    if(position == 0){                                                    //IF FIRST NODE GETTING DELETED, JUST CALL deleteFirst()
        deleteFirst(head);
        return;
    }

    struct Node* current = *head;
    for(int i = 0; current != NULL && i < position - 1; i++){        //GET *CURRENT TO ONE NODE BEFORE THE DESIRED NODE
        current = current -> next;
    }

    if(current == NULL || current -> next == NULL){
        printf("Cannot delete at position %d; invalid.", position);
        return;
    }

    struct Node* temp = current -> next;                       //ASSIGN TEMPORARY POINTER TO THE NODE BEING DELETED
    current -> next = current -> next -> next;                //MAKE *CURRENT POINT TO THE NODE AFTER THE ONE BEING DELETED
    free(temp);                                              //FREE MEMORY STORED AT NODE-TO-BE-DELETED
    printf("Deleted node at position %d\n", position);
}

//DISPLAY THE LIST FUNCTION
void displayList(struct Node* node){
    while(node != NULL){
        printf("%d -> ", node -> data);
        node = node -> next;
    }
    printf("NULL \n"); 
}


//SEARCH FOR AN ITEM'S POSITION 
void search(struct Node** head){
    struct Node* ptr = *head;
    int item, flag = 0, i = 0;

    if(ptr == NULL){
        printf("List is empty");
        return;
    }

    else{
        printf("\nEnter the item you want to search: \n");
        scanf("%d", &item);
        while(ptr != NULL){
        if(ptr -> data == item){
            printf("Item found at location %d", i + 1);
            flag = 1;
        }
        i++;
        ptr = ptr -> next;
    }
    }
    if(flag == 0){
        printf("item not found");
    }
}

//COUNT NUMBER OF NODES IN THE LIST
void count_nodes(struct Node** head){
    struct Node* temp = *head;
    int count = 0;

    while(temp != NULL){
        temp = temp -> next;  //TRAVERSE THROUGH THE LIST TILL LAST NODE IS REACHED
        count++;             //INCREMENT COUNT
    }

    printf("\nNumber of nodes: %d", count);
}


//REVERSE THE LIST
void reverse(struct Node** head){
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while(current != NULL){
        next = current -> next;         //STORE NEXT NODE
        current -> next = prev;        //REVERSE THE LINK

        prev = current;              //MOVE PREV FORWARD
        current = next;             //MOVE CURRENT FORWARD
    }
    *head = prev;                 //UPDATE THE HEAD POINTER
}


//ATTACHING LIST1 TO LIST2; NO SORTING; ORDER MATTERS
void concatenate(struct Node** list1, struct Node* list2){
    if(*list1 == NULL){
        *list1 = list2;
        return;
    }

    if(list2 == NULL){
        return;
    }

    struct Node* current = *list1;
    while(current -> next != NULL){
        current = current -> next;
    }

    current -> next = list2;
}


//MERGING TWO PRE-SORTED LISTS TOGETHER TO FORM ONE SORTED LIST
void merge(struct Node** result, struct Node* list1, struct Node* list2){

    if(list1 == NULL) *result = list2; return;               //IF LIST1 IS EMPTY, ONLY LIST2 GETS PRINTED AS RESULT
    if(list2 == NULL) *result = list1; return;              //IF LIST2 IS EMPTY, ONLY LIST1 GETS PRINTED AS RESULT

    struct Node dummy;                                    //TEMPORARY NODE THAT SITS AT THE START OF THE MERGED LIST
    struct Node* tail = &dummy;                          //POINTS TO THE DUMMY NODE; TAIL ALWAYS POINTS THE LAST NODE IN THE MERGED LIST
    dummy.next = NULL;                                  //INITIALIZES DUMMY SO WE CAN START WITH AN EMPTY LIST

    while(list1 != NULL && list2 != NULL){            //WHILE BOTH LISTS HAVE NODES PRESENT IN THEM  
        if(list1 -> data <= list2 -> data){          //IF LIST1'S FIRST ELEMENT IS LESSER THAN OR EQUAL TO LIST2'S FIRST ELEMENT, ATTACH IT TO THE END OF THE MERGED LIST
            tail -> next = list1;
            list1 = list1 -> next;                 //MOVE LIST1 FORWARD BY ONE NODE
        }
        else{
            tail -> next = list2;               //ELSE LIST2'S FIRST ELEMENT IS SMALLER, SO ATTACH IT TO THE END OF THE MERGED LIST
            list2 = list2 -> next;             //MOVE LIST2 FORWARD BY ONE NODE
        }
        tail = tail -> next;                 //MOVE TAIL ONE NODE FORWARD IN THE MERGED LIST
    }

    if(list1 != NULL){
        tail -> next = list1;            //IF THERE ANY REMAINING NODES IN LIST1, ATTACH THE ENTIRE REMAINING CHAIN TO THE END OF THE MERGED LIST 
    }
    else{
        tail -> next = list2;         //SAME FOR LIST2'S
    }

    *result = dummy.next;          //MAKE RESULT POINT TO THE ACTUAL START OF THE MERGED LIST 
}

int main(){

    //FIRST LIST
    struct Node* head = NULL;
    insertFirst(&head, 1);
    insertFirst(&head, 0);

    insertLast(&head, 2);
    insertLast(&head, 4);

    insertAt(&head, 3, 3);
    insertLast(&head, 7);
    displayList(head);
    

    //SECOND LIST
    struct Node* head1 = NULL;
    insertFirst(&head1, 10);
    insertFirst(&head1, 9);

    insertLast(&head1, 13);
    insertLast(&head1, 16);

    insertAt(&head1, 3, 15);
    insertAt(&head1, 2, 11);
    displayList(head1);


    //MERGED LIST
    struct Node* merged_list = NULL;
    merge(&merged_list, head, head1);
    displayList(merged_list);

}


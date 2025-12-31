#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void insertbeginning(int item)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
        return;
    }

    ptr->data = item;
    ptr->prev = NULL;

    if (head == NULL)
    {
        ptr->next = NULL;
        head = ptr;
    }
    else
    {
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
    }
    printf("\nNode Inserted");
}

void insertlast(int item)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp;

    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
        return;
    }

    ptr->data = item;
    ptr->next = NULL;

    if (head == NULL)
    {
        ptr->prev = NULL;
        head = ptr;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = ptr;
        ptr->prev = temp;
    }
    printf("\nNode Inserted");
}

void insert_specified(int item)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    int loc, i;

    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
        return;
    }

    printf("\nEnter location: ");
    scanf("%d", &loc);

    temp = head;
    for (i = 0; i < loc; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("\nCan't insert");
            return;
        }
    }

    ptr->data = item;
    ptr->next = temp->next;
    ptr->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = ptr;

    temp->next = ptr;
    printf("\nNode Inserted");
}

void beginning_delete()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\nUNDERFLOW");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
        printf("\nNode Deleted");
    }
    else
    {
        ptr = head;
        head = head->next;
        head->prev = NULL;
        free(ptr);
        printf("\nNode Deleted");
    }
}

void last_delete()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\nUNDERFLOW");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
        printf("\nNode Deleted");
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
            ptr = ptr->next;

        ptr->prev->next = NULL;
        free(ptr);
        printf("\nNode Deleted");
    }
}

void delete_specified()
{
    struct node *temp, *ptr;
    int val;

    if (head == NULL)
    {
        printf("\nUNDERFLOW");
        return;
    }

    printf("\nEnter value: ");
    scanf("%d", &val);

    temp = head;
    while (temp != NULL && temp->data != val)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("\nCan't delete");
        return;
    }

    if (temp->prev == NULL)
    {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
    }
    else
    {
        temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
    }

    free(temp);
    printf("\nNode Deleted");
}

void traverse()
{
    struct node *ptr = head;
    if (ptr == NULL)
    {
        printf("\nNothing to print");
        return;
    }

    printf("\nPrinting values:\n");
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    int choice, item;

    while (1)
    {
        printf("\n\n1.Insert at beginning");
        printf("\n2.Insert at end");
        printf("\n3.Insert after specified position");
        printf("\n4.Delete at beginning");
        printf("\n5.Delete at end");
        printf("\n6.Delete specified node");
        printf("\n7.Display");
        printf("\n8.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &item);
            insertbeginning(item);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &item);
            insertlast(item);
            break;

        case 3:
            printf("Enter value: ");
            scanf("%d", &item);
            insert_specified(item);
            break;

        case 4:
            beginning_delete();
            break;

        case 5:
            last_delete();
            break;

        case 6:
            delete_specified();
            break;

        case 7:
            traverse();
            break;

        case 8:
            exit(0);

        default:
            printf("\nInvalid choice");
        }
    }
}
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void beg_insert(int item)
{
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
        return;
    }

    ptr->data = item;

    if (head == NULL)
    {
        head = ptr;
        ptr->next = head;
    }
    else
    {
        temp = head;
        while (temp->next != head)
            temp = temp->next;

        ptr->next = head;
        temp->next = ptr;
        head = ptr;
    }
    printf("\nNode Inserted");
}

void last_insert(int item)
{
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
        return;
    }

    ptr->data = item;

    if (head == NULL)
    {
        head = ptr;
        ptr->next = head;
    }
    else
    {
        temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = ptr;
        ptr->next = head;
    }
    printf("\nNode Inserted");
}

void beg_delete()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\nUNDERFLOW");
    }
    else if (head->next == head)
    {
        free(head);
        head = NULL;
        printf("\nNode Deleted");
    }
    else
    {
        ptr = head;
        while (ptr->next != head)
            ptr = ptr->next;

        ptr->next = head->next;
        free(head);
        head = ptr->next;
        printf("\nNode Deleted");
    }
}

void last_delete()
{
    struct node *ptr, *preptr;
    if (head == NULL)
    {
        printf("\nUNDERFLOW");
    }
    else if (head->next == head)
    {
        free(head);
        head = NULL;
        printf("\nNode Deleted");
    }
    else
    {
        ptr = head;
        while (ptr->next != head)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = head;
        free(ptr);
        printf("\nNode Deleted");
    }
}

void search()
{
    struct node *ptr;
    int item, i = 1, flag = 0;

    if (head == NULL)
    {
        printf("\nEmpty List");
        return;
    }

    printf("\nEnter item to search: ");
    scanf("%d", &item);

    ptr = head;
    do
    {
        if (ptr->data == item)
        {
            printf("\nItem found at location %d", i);
            flag = 1;
            break;
        }
        ptr = ptr->next;
        i++;
    } while (ptr != head);

    if (flag == 0)
        printf("\nItem not found");
}

void traverse()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\nNothing to print");
        return;
    }

    ptr = head;
    printf("\nPrinting values:\n");
    do
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

int main()
{
    int choice, item;

    while (1)
    {
        printf("\n\n1.Insert at beginning");
        printf("\n2.Insert at end");
        printf("\n3.Delete from beginning");
        printf("\n4.Delete from end");
        printf("\n5.Search");
        printf("\n6.Traverse");
        printf("\n7.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &item);
            beg_insert(item);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &item);
            last_insert(item);
            break;

        case 3:
            beg_delete();
            break;

        case 4:
            last_delete();
            break;

        case 5:
            search();
            break;

        case 6:
            traverse();
            break;

        case 7:
            exit(0);

        default:
            printf("\nInvalid choice");
        }
    }
}
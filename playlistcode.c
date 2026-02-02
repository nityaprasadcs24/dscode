#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song {
    char title[50];
    char artist[50];
    int duration;
    struct song *next;
};

struct song *head = NULL;
struct song *current = NULL;

void playCurrent() {
    if (current == NULL) {
        printf("Playlist empty\n");
        return;
    }
    printf("\nNow Playing:\n");
    printf("%s %s %d\n", current->title, current->artist, current->duration);
}

void nextSong() {
    if (current == NULL) {
        printf("Playlist empty\n");
        return;
    }
    current = current->next;
    playCurrent();
}

void prevSong() {
    if (current == NULL) {
        printf("Playlist empty\n");
        return;
    }
    struct song *temp = current;
    while (temp->next != current)
        temp = temp->next;
    current = temp;
    playCurrent();
}

void addSong(int pos) {
    struct song *newNode = (struct song*)malloc(sizeof(struct song));
    printf("Enter title, artist, duration: ");
    scanf("%s %s %d", newNode->title, newNode->artist, &newNode->duration);

    if (head == NULL) {
        newNode->next = newNode;
        head = current = newNode;
        return;
    }

    struct song *temp = head;

    if (pos == 0) {
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
        return;
    }

    for (int i = 0; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteSong(int pos) {
    if (head == NULL) {
        printf("Playlist empty\n");
        return;
    }

    struct song *temp = head, *prev = NULL;

    if (pos == 0) {
        if (head->next == head) {
            free(head);
            head = current = NULL;
            return;
        }
        while (temp->next != head)
            temp = temp->next;
        temp->next = head->next;
        free(head);
        head = current = temp->next;
        return;
    }

    for (int i = 0; i < pos && temp->next != head; i++) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    if (temp == current)
        current = prev;
    free(temp);
}

void display() {
    if (head == NULL) {
        printf("Playlist empty\n");
        return;
    }

    struct song *temp = head;
    do {
        printf("%s %s %d\n", temp->title, temp->artist, temp->duration);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    int choice, pos;

    while (1) {
        printf("\n1.Add Song\n2.Delete Song\n3.Play Current\n4.Next\n5.Previous\n6.Display\n7.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter position: ");
                scanf("%d", &pos);
                addSong(pos);
                break;
            case 2:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteSong(pos);
                break;
            case 3:
                playCurrent();
                break;
            case 4:
                nextSong();
                break;
            case 5:
                prevSong();
                break;
            case 6:
                display();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}


struct Node* insertEnd(struct Node* head, int data) {

    struct Node* newNode = createNode(data);

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;

    return head;
}

// Reverse linked list using recursion
struct Node* reverse(struct Node* head) {

    
    if (head == NULL || head->next == NULL) {
        return head;
    }

    
    struct Node* newHead = reverse(head->next);

    
    head->next->next = head;

    
    head->next = NULL;

    return newHead;
}

// Print linked list
void printList(struct Node* head) {

    while (head != NULL) {
        printf("%d", head->data);

        if (head->next != NULL) {
            printf(" -> ");
        }

        head = head->next;
    }

    printf("\n");
}

int main() {

    struct Node* head = NULL;

    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 4);
    head = insertEnd(head, 5);

    printf("Original list: ");
    printList(head);

    head = reverse(head);

    printf("Reversed list: ");
    printList(head);

    return 0;
}

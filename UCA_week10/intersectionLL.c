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

struct Node* intersection(struct Node* head1, struct Node* head2) {

    struct Node* p = head1;
    struct Node* q = head2;

    struct Node* head = NULL;

    while (p != NULL && q != NULL) {

        if (p->data == q->data) {

            // Create a new node
            head = insertEnd(head, p->data);

            p = p->next;
            q = q->next;
        }

        else if (p->data < q->data) {
            p = p->next;
        }

        else {
            q = q->next;
        }
    }

    return head;
}

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

    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    // First list
    head1 = insertEnd(head1, 1);
    head1 = insertEnd(head1, 2);
    head1 = insertEnd(head1, 2);
    head1 = insertEnd(head1, 3);
    head1 = insertEnd(head1, 4);

    // Second list
    head2 = insertEnd(head2, 2);
    head2 = insertEnd(head2, 2);
    head2 = insertEnd(head2, 2);
    head2 = insertEnd(head2, 4);

    printf("List 1: ");
    printList(head1);

    printf("List 2: ");
    printList(head2);

    struct Node* result = intersection(head1, head2);

    printf("Intersection: ");
    printList(result);

    return 0;
}

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


int searchList(struct Node* list1, struct Node* list2) {

    
    if (list1 == NULL) {
        return 1;
    }

    struct Node* p = list2;

    while (p != NULL) {

        // Start comparing from this node of list2
        struct Node* q = p;
        struct Node* r = list1;

        while (q != NULL && r != NULL && q->data == r->data) {
            q = q->next;
            r = r->next;
        }

        // If we reached the end of list1,
        // the complete list1 was found
        if (r == NULL) {
            return 1;
        }

        // Try the next node of list2
        p = p->next;
    }

    return 0;
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

    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    
    list1 = insertEnd(list1, 10);
    list1 = insertEnd(list1, 20);

    
    list2 = insertEnd(list2, 5);
    list2 = insertEnd(list2, 10);
    list2 = insertEnd(list2, 20);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    if (searchList(list1, list2)) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }

    return 0;
}

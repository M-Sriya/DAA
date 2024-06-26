#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtMiddle(Node** head, int data, int position) {
    Node* newNode = createNode(data);
    Node* temp = *head;
    int count = 1;
    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Position not available in the list\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* temp = *head;
    if (temp == NULL) {
        *head = newNode;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    // Insert at beginning
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    printf("List after inserting at beginning: ");
    printList(head);

    // Insert at middle
    insertAtMiddle(&head, 40, 2);
    printf("List after inserting at middle: ");
    printList(head);

    // Insert at end
    insertAtEnd(&head, 50);
    printf("List after inserting at end: ");
    printList(head);

    // Insert at not available position
    insertAtMiddle(&head, 60, 10);
    printf("List after inserting at not available position: ");
    printList(head);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    (*head)->prev = newNode;
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to delete a node from the linked list
void deleteNode(struct Node** head, struct Node* delNode) {
    if (*head == NULL || delNode == NULL) {
        return;
    }
    if (*head == delNode) {
        *head = delNode->next;
    }
    if (delNode->next != NULL) {
        delNode->next->prev = delNode->prev;
    }
    if (delNode->prev != NULL) {
        delNode->prev->next = delNode->next;
    }
    free(delNode);
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the implementation
int main() {
    struct Node* head = NULL;
    insertAtBeginning(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtBeginning(&head, 4);
    printf("Original List: ");
    printList(head);
    deleteNode(&head, head);
    printf("List after deleting head node: ");
    printList(head);
    deleteNode(&head, head->next);
    printf("List after deleting second node: ");
    printList(head);
    return 0;
}

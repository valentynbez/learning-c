#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct entry {
    int value;
    struct entry *next;
} Entry;



void printList (Entry *list) {
    /**
        * Prints the list
        * @param list: pointer to the first element of the list
    */

    char * arrow = " -> ";
    Entry *current = list;
    while (current != NULL) {
        printf("%d", current->value);
        if (current->next != NULL) {
            printf("%s", arrow);
        }
        current = current->next;
    }

}

// Ex. 2
// Write a function called insertEntry to insert a new entry into a linked list. Have
// the procedure take as arguments a pointer to the list entry to be inserted (of type
// struct entry as defined in this chapter), and a pointer to an element in the list
// after which the new entry is to be inserted.
// Ex. 3
// The function developed in exercise 2 only inserts an element after an existing element
// in the list, thereby preventing you from inserting a new entry at the front of
// the list. How can you use this same function and yet overcome this problem?
Entry *insertValue(Entry *entry, int value) {
    /**
        * Inserts a new entry into the list
        * @param entry: pointer to the entry after which the new entry is to be inserted
        * @param value: value of the new entry
        * @return pointer to the new entry
    */

    Entry *newEntry = (Entry *) malloc(sizeof(Entry));
    newEntry->value = value;
    if (!entry) {
        newEntry->next = NULL;
    } else {
    newEntry->next = entry->next;
    entry->next = newEntry;
    }
}


Entry retrieveValue(Entry *list, int index) {
    /**
        * Retrieves the value at the given index
        * @param list: pointer to the first element of the list
        * @param index: index of the value to be retrieved
        * @return value at the given index
    */

    Entry *current = list;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return *current;
}

// Ex. 4
// Write a function called removeEntry to remove an entry from a linked list.The
// sole argument to the procedure should be a pointer to the list. Have the function
// remove the entry after the one pointed to by the argument. (Why can’t you
// remove the entry pointed to by the argument?) You need to use the special structure
// you set up in exercise 3 to handle the special case of removing the first element
// from the list.
void removeValue(Entry *list) {
    /**
        * Removes the given entry from the list
        * @param list: pointer to the entry to be removed
    */

    if (list->next == NULL) {
        return;
    }
    Entry *next = list->next;
    list->value = next->value;
    list->next = next->next;
    free(next);
}


// Ex. 5
// A doubly linked list is a list in which each entry contains a pointer to the preceding
// entry in the list as well as a pointer to the next entry in the list. Define the appropriate
// structure definition for a doubly linked list entry and then write a small program
// that implements a small doubly linked list and prints out the elements of the
// list.
struct DoubleLinkedList {
    int value;
    struct DoubleLinkedList *next;
    struct DoubleLinkedList *previous;
};



int main (){
    // Create the list
    Entry *first = NULL;
    Entry *second, *third, *fourth;

    // Insert elements into the list
    first = insertValue(first, 1);
    second = insertValue(first, 2);
    third = insertValue(second, 3);
    fourth = insertValue(third, 4);

    // Print the list
    printf("Linked list: ");
    printList(first);
    printf("\n");
    // Second element
    printf("Second element: %d\n", retrieveValue(first, 1).value);
    // Remove 1st and 3rd element
    removeValue(first);
    removeValue(third);
    // Print the list
    printf("Linked list after removal of 1st and 3rd: ");
    printList(first);
    printf("\n");

    // Double linked list
    struct DoubleLinkedList *firstDouble = (struct DoubleLinkedList *) malloc(sizeof(struct DoubleLinkedList));
    struct DoubleLinkedList *secondDouble = (struct DoubleLinkedList *) malloc(sizeof(struct DoubleLinkedList));

    firstDouble->value = 1;
    firstDouble->next = secondDouble;
    firstDouble->previous = NULL;
    secondDouble->value = 2;
    secondDouble->next = NULL;
    secondDouble->previous = firstDouble;

    // print list elements
    struct DoubleLinkedList *current = firstDouble;
    while (current != NULL) {
        printf("%d", current->value);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }

    return 0;

}
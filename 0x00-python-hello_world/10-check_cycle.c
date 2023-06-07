#include "lists.h"

/**
* check cycle - uses the "Floyd's cycle-finding algorythm to detect a cycle in the linked list. 
* Returns: 0
**/
/* Definition of a node in the linked list */
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/* Function to check if a linked list has a cycle */
int check_cycle(Node* list) {
    Node* slow = list;
    Node* fast = list;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            /* Cycle detected */
            return 1;
        }
    }

    /* No cycle found */
    return 0;
}

/* Helper function to create a new node */
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* Example usage */
int main() {
    /* Creating a linked list with a cycle */
    Node* head = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node2;

    /* Checking if the linked list has a cycle */
    int hasCycle = check_cycle(head);
    if (hasCycle) {
        printf("The linked list has a cycle.\n");
    } else {
        printf("The linked list does not have a cycle.\n");
    }

    /* Freeing the memory */
    node5->next = NULL;
    free(node5);
    free(node4);
    free(node3);
    free(node2);
    free(head);

    return 0;
}

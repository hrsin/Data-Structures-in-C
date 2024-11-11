#include <stdio.h>
#include <stdlib.h>
/* Defining the structure of a node in a singly linked list
   * |start| -> |data, next| -> |data, next| -> NULL
*/
typedef struct node {
    int data;
    struct node *next;
} node_t;
node_t *head = NULL;
/* Algorithm for traversing a linked list 
    * Step 1: Initialize a pointer = start
    * Step 2: Repeat step 3 n 4, while pointer != NULL
    * Step 3: Apply process to pointer -> data
    * Step 4: Set pointer = pointer -> next   
    * End of Loop
    * Step 5: Exit
*/
void traverse(node_t *head) {
    node_t *current = head;
    whille (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}
// Adding an item to the end of the list
void push(node_t *head, int val) {
    node_t *current = head;
    while (current->next != NULL) {
        current  = current->next;
    }
    current->next = (node_t *) malloc(sizeof(node_t));
    current->next->data = val;
    current->next->next = NULL;
}
/* Adding an item to the beginning of the list
    * Step 1: Create a new node
    * Step 2: Set the data of the new node to the value
    * Step 3: Set the next of the new node to the head
    * Step 4: Set the head to the new node
*/
// creating double pointer to head in the argument to update the head
void push_start(node_t ** head, int val) {
    node_t *newNode = (node_t *) malloc(sizeof(node_t));
    newNode->data= val;
    newNode->next= *head;
    *head = newNode;
}
/* Removing the first item from the list
    * Step 1: save the next item the head points to
    * Step 2: free the head
    * Step 3: set the head to the saved item
*/
int remove_first(node_t ** head) {
    int retval = -1;
    node_t *temp = NULL;
    if (*head==NULL) {
        return -1;
    }
    retval = (*head)->data;
    temp = (*head)->next;
    free(*head);
    *head = temp;
    return retval;
}
int remove_last(node_t * head) {
    int retval = 0;
    if (head->next == NULL) {
        retval = head->data;
        free(head);
        return retval;
    }
    node_t * temp = head;
    while (temp->next->next !=NULL) {
        temp = temp->next;
    }
    retval = temp->next->data;
    free(temp->next);
    temp->next = NULL;
    return retval;
}
int remove_by_index(node_t ** head, int n) {
    int retval = -1, i;
    node_t *current = *head;
    node_t *temp = NULL;
    if (n==0) {
        return remove_first(head);
    }
    if (current->next==NULL) {
        return -1;
    }
    for (i=0;i<n-1;i++) {
        if (current->next == NULL) {
            return -1;
        }
        current = current->next;
    }
    temp = current->next;
    retval = temp->data;
    current->next = temp->next;
    free(temp);
    return retval;
}
int remove_item(node_t ** head, int val) {
    int retval = -1;
    node_t *current = *head;
    node_t *temp = NULL;
    if (current->next == NULL || current == NULL) {
        return -1;
    }
    if (current->data == val) {
        return remove_first(head);
    }
    while(current->next->data != val) {
        current = current->next;
    }
    temp = current->next;
    retval = temp->data;
    current->next = temp->next;
    free(temp);
    return retval;
}
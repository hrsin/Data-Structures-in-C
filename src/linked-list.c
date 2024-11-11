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
int main() {
    int choice, val, index, retval;
    head = NULL;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add element at the end\n");
        printf("2. Add element at the beginning\n");
        printf("3. Remove first element\n");
        printf("4. Remove last element\n");
        printf("5. Remove element by index\n");
        printf("6. Remove element by value\n");
        printf("7. Display list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to add at the end: ");
                scanf("%d", &val);
                if (head == NULL) {
                    head = (node_t *) malloc(sizeof(node_t));
                    head->data = val;
                    head->next = NULL;
                } else {
                    push(head, val);
                }
                break;
            case 2:
                printf("Enter value to add at the beginning: ");
                scanf("%d", &val);
                push_start(&head, val);
                break;
            case 3:
                retval = remove_first(&head);
                if (retval == -1) printf("List is empty.\n");
                else printf("Removed first element: %d\n", retval);
                break;
            case 4:
                if (head == NULL) printf("List is empty.\n");
                else {
                    retval = remove_last(head);
                    printf("Removed last element: %d\n", retval);
                }
                break;
            case 5:
                printf("Enter index to remove: ");
                scanf("%d", &index);
                retval = remove_by_index(&head, index);
                if (retval == -1) printf("Index out of range.\n");
                else printf("Removed element at index %d: %d\n", index, retval);
                break;
            case 6:
                printf("Enter value to remove: ");
                scanf("%d", &val);
                retval = remove_item(&head, val);
                if (retval == -1) printf("Value not found in the list.\n");
                else printf("Removed element with value %d\n", retval);
                break;
            case 7:
                printf("Current list:\n");
                traverse(head);
                break;
            case 8:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
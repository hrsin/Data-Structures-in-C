#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    int priority;
    struct Node *next;
} node;
node *start = NULL;
void insert(int,int, node **);
void delete(node **);
void display(node *);
int main() {
    int choice, val,priority;
    while (1) {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Value to insert and its priority: ");
                scanf("%d %d", &val, &priority);
                insert(val, priority, &start);
                break;
            case 2:
                delete(&start);
                break;
            case 3:
                display(start);
                break; 
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}
// Ascending order priority queue
void insert(int val, int priority, node **start) {
    node *newN = (node *)malloc(sizeof(node));
    newN->data = val; 
    newN->priority = priority;
    if (*start == NULL || (*start)->priority > priority) {  // change the compare sign to change the priority order
        newN->next = *start;
        *start = newN;
    } else {
        node *iter = *start;
        while (iter->next !=NULL && newN->priority >= iter->next->priority) { // change the compare sign to change the priority order
            iter = iter->next;
        }
        newN->next = iter->next;
        iter->next = newN;
    }
}
void delete(node **start) {
    if (*start == NULL) {
        printf("Queue is empty\n");
    } else { 
        node *temp = *start;
        printf("Deleted element is %d\n", temp->data);
        *start = (*start)->next;
        free(temp);
    }
}
void display(node *start) {
    if (start == NULL) {
        printf("Queue is empty\n");
    } else {
        node *iter = start;
        while (iter != NULL) {
            printf("%d --> ", iter->data);
            iter = iter->next;
        }
        printf("NULL\n");
    }
}
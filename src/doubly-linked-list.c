#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} node;
node *insert_start(node *head, int val) {
    node *new = (node *)malloc(sizeof(node));
    new->data = val;
    if (head ==NULL) {
        new->next = NULL;
        new->prev = NULL;
        head=new;
        return head;
    } else {
        head->prev = new;
        new->next = head;
        new->prev = NULL;
        head = new;
        return head;
    }
}
node *delete_after(node *head, int val) {
    node *iter = head; // iterator node
    node *temp; // temporary node
    // list is empty
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return head;
    }
    // Only one node in the list
    if (head->next == NULL) {
        free(head);
        return head;
    }
    // iterate if the list is not empty until the value is found
    while(iter->data !=val) {
        iter = iter->next; // saving the node which contains the value
        temp = iter->next; // saving the node to be deleted in 'temp' node
    }
    if (temp==NULL) {
        printf("No node after the value.\n");
        return head;
    }
    printf("The node to be deleted is: %d\n", temp->data);
    iter->next = temp->next;
    temp->next->prev = iter;
    free(temp);
    return head;
}
void display(node *head) {
    node *iter = head;
    if (head == NULL) {
        printf("List is empty, nothing to display.\n");
        return head;
    }
    while(iter != NULL) {
        printf("%d->", iter->data);
        iter = iter->next;
    }
    printf("NULL\n");
}
int main() {
    int choice, data;
    node *head = NULL;
    while(1) {
        printf("List of Operations: \n1. Insert at the beginning \n2. Deleting after the value\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the data to be inserted:");
                scanf("%d", &data);
                head = insert_start(head, data);
                break;
            case 2:
                printf("Enter the data to be deleted:");
                scanf("%d", &data);
                head = delete_after(head, data);
                break;
            case 3:
                display(head);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice, choose the correct option");
                break;
        }

    } 
}

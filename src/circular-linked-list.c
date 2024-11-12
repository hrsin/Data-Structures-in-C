#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
} node;
node *insert_beg(node *head) {
    int data;
    node *ptr;
    printf("Enter the data: ");
    scanf("%d", &data);
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return head;
    }
    ptr = head; 
    while(ptr->next != head) {
        ptr = ptr->next; // traversing to the last node: ptr now points to the last node
    }
    ptr->next = newNode; // last node now points to the new node at the beginning
    newNode->next = head; // new node now points to the previously first node
    head = newNode; // assigned the new node as the head
    return head;   
}
node *insert_end(node *head) {
    node *new, *iter;
    int data;
    printf("Enter the data you want to insert at the end:");
    scanf("%d", &data);
    new = (node *)malloc(sizeof(node));
    new->data=data;
    if (head==NULL) {
        new->next = new;
        head = new;
        return head;
    }
    iter=head;
    while(iter->next!=head) {
        iter=iter->next;
    }
    iter->next = new;
    new->next = head;
    return head;

}
node *delete_beg(node *head) {
    if (head==NULL) {
        printf("List is empty");
        return head;
    }
    if(head->next==head) {
        free(head);
        return head;
    }
    node *iter = head;
    while(iter->next != head) {
        iter=iter->next;
    }
    iter->next = head->next;
    free(head);
    head = iter->next;
    return head;
}
node *delete_end(node *head) {
    node *iter = head, *prev = NULL;
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return NULL;
    }
    if (head->next == head) {
        // Only one node in the list
        free(head);
        return NULL;
    }
    while(iter->next != head) {
        prev = iter; // assigning second last node to the 'prev' node
        iter=iter->next; // assigning last node to the 'iter' node
    }
    prev->next = iter->next; // pointing second last node's next pointer to last node's next pointer which is the first node
    free(iter); // deleting the last node
    return head;
}
void display(node *head) {
    if (head==NULL) {
        printf("List is empty");
        return;
    }
    if (head->next == head) {
        printf("%d\n", head->data);
        return;
    }
    node *iter = head;
    while(iter!=head) {
        printf("%d ", iter->data);
        iter = iter->next;
    }
    printf("\n");
}
int main() {
    node *head = NULL;
    int choice;
    while (1) {
        printf("\nOperations Available: \n1. Insert at the beginning\n2. Insert at the end\n3. Delete from the beginning\n4. Delete from the end\n5. Display list \n6. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                head = insert_beg(head);
                break;
            case 2:
                head = insert_end(head);
                break;
            case 3:
                head = delete_beg(head);
                break;
            case 4:
                head = delete_end(head);
                break;
            case 5:
                display(head);
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice");
        }
    }
    return 0;
}
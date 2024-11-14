#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;
node *front = NULL;
node *rear = NULL;
void enqueue(int);
void dequeue();
void display();
int main() {
    int choice, val;
    while(1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }    
    return 0;
}
void enqueue(int val) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;
    if (front == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Element inserted successfully\n");
}
void dequeue() {
    if (front == NULL) {
        printf("No element to dequeue\n");
    } else {
        node *temp = front;
        printf("Element deleted is %d\n", temp->data);
        front = front->next;
        free(temp);
    }
}
void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else{
        while (front != NULL) {
            printf("%d -> ", front->data);
            front = front->next;
        }
        printf("NULL\n");
    }
}


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
                break;
            default:
                printf("Invalid choice\n");
                break;  
        }
    }
    return 0;
}
void enqueue(int val) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    if ((front==NULL)&& (rear == NULL)) {
        front=rear=newNode;
        rear->next = front;
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
}
void dequeue() {
    node *temp = front;
    if ((front == NULL) && (rear == NULL)) {
        printf("Queue is empty\n");
    } else if (front == rear) {
        printf("Deleted element is %d\n", temp->data);
        front = rear =NULL;
        free(temp);
    } else {
        printf("Deleted element is %d\n", temp->data);
        front = front->next;
        rear->next = front;
        free(temp);
    }
}
void display() {
    if (front == NULL && rear == NULL) {
        printf("Queue is empty\n");
    } else{
        node *temp = front;
        printf("(front)");
        while (temp->next != front) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("%d(rear)\n", temp->data);
    }
}
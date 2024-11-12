#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int stack[MAX], top = -1;
/* PUSH operation to insert an element into the stack
    1. if top=MAX-1
        print overflow, go to step 4
    [End of if]
    2. top = top + 1
    3. stack[top] = data
    4. Exit
*/
void push(int st[], int data) {
    if (top == MAX-1) {
        printf("Overflow\n");
        return;
    }
    top++;
    st[top] = data;
}

/* POP operation to delete an element from the stack
    1. if top=-1
        print underflow, go to step 4
    [End of if]
    2. set data = stack[top]
    3. set top = top - 1
    4. Exit
*/
int pop(int st[]) {
    int del;
    if ( top=-1) {
        printf("Underflow, No elements in the stacks\n");
        return -1;
    }
    del = st[top];
    top--;
    return del;
}

/* PEEK operation to display the top element of the stack
    1. if top=-1
        print stack is empty, go to step 3
    [End of if]
    2. print stack[top]
    3. Exit
*/
int peek(int st[]) {
    if (top==-1) {
        printf("Stack is empty\n");
        return -1;
    }
    return st[top];
}

void display(int st[]) {
    if (top==-1) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = top; i>=0;i--) {
        printf("%d\n", st[i]);
    }
    printf("\n");
}

int main() {
    int choice, data;
    while (1)
    {
        printf("List of Operations\n1. Push\n2. Pop\n3. Peek\n4. Display\n5.Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the data to be pushed: ");
                scanf("%d", &data);
                push(stack, data);
                break;
            case 2:
                data = pop(stack);
                if (data != -1) {
                    printf("The deleted element is %d\n", data);
                }
                break;
            case 3:
                data = peek(stack);
                if (data != -1) {
                    printf("The top element is %d\n", data);
                }
                break;
            case 4:
                display(stack);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    
    return 0;
}
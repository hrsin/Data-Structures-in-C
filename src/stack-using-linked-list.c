#include <stdio.h>
#include <stdlib.h>
typedef struct Stack {
    int data;
    struct Stack *next;
} node;



/* Push Operation on the stack
    * 1. Allocate memory for the new node.
    * 2. set new node =  data.
    * 3. if top=null
    *    set new node next = null.
    *    set top = new node.
    *    else
    *    set new node next = top.
    *    set top = new node.
    *    [end of if]
    * 4. Exit.
*/
node *push(node *top) {
    int val;
    node *new_node = (node *)malloc(sizeof(node));
    printf("Enter the data you want to push: ");
    scanf("%d", &val);
    new_node->data = val;
    if (top == NULL) {
        new_node->next = NULL;
    } else {
        new_node->next = top;
    }
    top = new_node;
    return top;
}
/* Pop Operation on the stack
    *1. if top = null
    *   print "Stack is empty".
    * goto step 5.
    * 2. set ptr = top.
    * 3. set top = top -> next.
    * 4. free(ptr)
    * 5. Exit.
*/
node *pop(node *top) {
    int data;
    node *temp = top;
    if (top == NULL) {
        printf("Stack is empty \n");
    } else {
        printf("The deleted element is: %d", top->data);
        top = top->next;
        free(temp);
    }
    return top;
}
node *display(node *top) {
    node *iter = top;
    if (top == NULL) {
        printf("Stack is empty.\n");
    }
    if (top->next == NULL) {
        printf("%d->NULL", top->data);
    } else {
        while(iter != NULL) {
            printf("%d->", iter->data);
            iter = iter->next;
        }
        printf("NULL\n");
    }
    return top;
}
node *peek(node *top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        printf("The top element is: %d\n", top->data);
    }
    return top;
}
int main() {
    int choice;
    node *top = NULL;
    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push(top);
                break;
            case 2:
                pop(top);
                break;
            case 3:
                display(top);
                break;
            case 4:
                peek(top);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
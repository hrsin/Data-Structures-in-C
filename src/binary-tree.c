#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} node;

void insert(node *, node *);
void inorder(node *);
void preorder(node *);
void postorder(node *);
node *getnode();

int main() {
    node *root = NULL;  // Root node of the binary tree
    int choice, value;

    while (1) {
        printf("\n1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                node *newNode = getnode();
                newNode->data = value;
                if (root == NULL) {
                    root = newNode;
                } else {
                    insert(root, newNode);
                }
                break;
            case 2:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

node *getnode() {
    node *newN = (node *)malloc(sizeof(node));
    newN->left = NULL;
    newN->right = NULL;
    return newN;
}

void insert(node *root, node *new1) {
    char c;
    printf("Enter the direction to insert the node (L/R) of %d: ", root->data);
    scanf(" %c", &c);  
    if (c == 'L' || c == 'l') {
        if (root->left == NULL) {
            root->left = new1;
        } else {
            insert(root->left, new1);
        }
    } else if (c == 'R' || c == 'r') {
        if (root->right == NULL) {
            root->right = new1;
        } else {
            insert(root->right, new1);
        }
    } else {
        printf("Invalid direction. Use 'L' or 'R'.\n");
    }
}

void inorder(node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

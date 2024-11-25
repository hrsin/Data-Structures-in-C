#include <stdio.h>
#include <stdlib.h>

void insert_pos(int arr[], int *num, int n);
void insert_mid(int arr[], int *num);
void delete_pos(int arr[], int *num);

int main() {
    int len, choice;   
    printf("Enter the length of the array: ");
    scanf("%d", &len);   
    int arr[len];
    int num = 0;  // Keeps track of the current number of elements in the array
    printf("\nOperations set\n");
    printf("1. Insert at a specific position\n");
    printf("2. Insert at the middle\n");
    printf("3. Delete from a specified position\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);    
    switch(choice) {
        case 1:
            insert_pos(arr, &num, len);
            break;
        case 2:
            insert_mid(arr, &num);
            break;
        case 3:
            delete_pos(arr, &num);
            break;
        default:
            printf("Invalid choice\n");
    }
    return 0;
}
void insert_pos(int arr[], int *num, int n) {
    int pos, val, i;   
    printf("Enter the current number of elements in the array: ");
    scanf("%d", num);  
    if (*num > n) {
        printf("Error: Number of elements exceeds array length.\n");
        return;
    }
    printf("Enter the elements of the array: ");
    for(i = 0; i < *num; i++) {
        scanf("%d", &arr[i]); // assigning elements to the array
    }
    printf("Enter the position to insert: ");
    scanf("%d", &pos);
    if (pos < 1 || pos > *num + 1) {
        printf("Error: Invalid position.\n");
        return;
    }
    printf("Enter the value to insert: ");
    scanf("%d", &val);
    for(i = *num; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = val;
    (*num)++; // incrementing the number of elements
    printf("Array after insertion: ");
    for(i = 0; i < *num; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
/* Algorithm to insert an element at the middle of an array
    * step 1: Set i=n
    * step 2: Repeat steps 3 and 4 while i>=mid
    * step 3: set arr[i+1] = arr[i]
    * step 4: decrement i
    * Exit loop
    * step 5: increment num
    * step 6: set arr[mid-1]=val
*/
void insert_mid(int arr[], int *num) {
    int val, i, mid;
    
    printf("Enter the current number of elements in the array: ");
    scanf("%d", num);
    
    printf("Enter the elements of the array: ");
    for(i = 0; i < *num; i++) {
        scanf("%d", &arr[i]);
    }
    
    mid = (*num) / 2;
    
    printf("Enter the value to insert at the middle: ");
    scanf("%d", &val);
    
    for(i = *num; i > mid; i--) {
        arr[i] = arr[i - 1];
    }
    
    arr[mid] = val;
    (*num)++;
    
    printf("Array after insertion: ");
    for(i = 0; i < *num; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void delete_pos(int arr[], int *num) {
    int pos, i;
    
    printf("Enter the current number of elements in the array: ");
    scanf("%d", num);
    
    printf("Enter the elements of the array: ");
    for(i = 0; i < *num; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the position to delete: ");
    scanf("%d", &pos);
    
    if (pos < 1 || pos > *num) {
        printf("Error: Invalid position.\n");
        return;
    }
    
    int val = arr[pos - 1];
    
    for(i = pos - 1; i < *num - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    (*num)--;
    
    printf("Deleted element: %d\n", val);
    printf("Array after deletion: ");
    for(i = 0; i < *num; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
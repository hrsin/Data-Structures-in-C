#include <stdio.h>
#include <stdlib.h>
int main() 
{
    int len,choice;
    printf("Enter the length of the array: ");
    scanf("%d", &len);
    int arr[len];
    printf("\nOperations set\n");
    printf("1. Insert at the position\n");
    printf("2. Insert at the middle\n");
    printf("3. Delete from the beginning\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            insert_pos(arr[len]);
            break;
        case 2:
            insert_mid(arr[len]);
            break;
        case 3:
            delete_pos(arr[len]);
            break;
        default:
            printf("Invalid choice\n");
    }
    return 0;
}
int insert_pos(n) {
    int arr[n];
    int i, pos, val, num;
    printf("Enter the elements of the array: ");
    scanf("%d", &num);
    for(i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\nEnter the position to insert:");
    scanf("%d", &pos);
    printf("\nEnter the value to insert:");
    scanf("%d", &val);
    for(i=num-1; i>pos-1;i--) {
        arr[i+1] = arr[i];
    }
    arr[pos-1] = val;
    num++;
    printf("\nArray after insertion is: ");
    for(i = 0; i < num; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
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
int insert_mid(n) {
    int arr[n];
    int i, pos, val, num, mid;
    printf("Enter the number of elements you want to insert: ");
    scanf("%d", & num);
    if(num%2==0) {
        mid=num/2;
    } else {
        mid = (num+1)/2;
    }
    for (i = 0; i<num-1; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the value you want insert at the middle: ");
    scanf("%d", &val);
    for (i=num-1; i>=mid-1;i --) {
        arr[i+1] = arr[i];
    }
    num++;
    arr[mid-1] = val;
    return 0;
}
int delete_pos(int arr[]) {
    int i, pos, num, val;
    printf("Enter the number of elements you want to insert: ");
    scanf("%d", &num);
    for (i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the position you want to delete: ");
    scanf("%d", &pos);
    if (pos>num+1) {
        printf("Invalid position\n");
    } else {
        val = arr[pos-1];
        for (i=pos-1;i<num-1;i++) {
            arr[i]=arr[i+1];
        }
        num--;
        printf("Delete element is: %d\n", val);
        printf("Array after deletion is: ");
        for (i=0;i<num;i++) {
            printf("%d ", arr[i]);
        }
    }
    
}




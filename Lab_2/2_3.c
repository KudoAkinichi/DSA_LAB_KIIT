#include <stdio.h>
#include <stdlib.h>

void traverse(int *arr, int size) {
    printf("Array elements: ");
    for(int i = 0;i < size;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int* insert(int *arr,int *size,int ele,int pos) {
    (*size)++;
    arr = (int *)realloc(arr,(*size)*sizeof(int));
    
    for (int i=(*size)-1;i>pos;i--) {
        arr[i] =arr[i-1];
    }
    arr[pos]=ele;
    
    return arr;
}

int* delete(int *arr,int *size,int pos) {
    for (int i = pos;i<(*size)-1;i++) {
        arr[i] = arr[i+1];
    }
    (*size)--;
    arr = (int *)realloc(arr,(*size)*sizeof(int));
    
    return arr;
}

int* merge(int *arr1,int size1,int *arr2,int size2) {
    int newSize = size1 + size2;
    int *mergedArr = (int *)malloc(newSize * sizeof(int));
    
    for (int i = 0; i < size1; i++) {
        mergedArr[i] = arr1[i];
    }
    for (int i = 0; i < size2; i++) {
        mergedArr[size1 + i] = arr2[i];
    }
    
    return mergedArr;
}

int main() {
    int *arr = NULL;
    int size = 0;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Print array elements\n");
        printf("2. Insert an element\n");
        printf("3. Delete an element\n");
        printf("4. Merge arrays\n");
        printf("5. Exit\n");
        
        char choice;
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        
        switch (choice) {
            case 1:
                if (size == 0) {
                    printf("Array is empty.\n");
                } else {
                    traverse(arr, size);
                }
                break;
            
            case 2:
                int ele, pos;
                printf("Enter the element to insert: ");
                scanf("%d", &ele);
                printf("Enter the position to insert: ");
                scanf("%d", &pos);
                if (pos < 0 || pos > size) {
                    printf("Invalid position.\n");
                } else {
                    arr = insert(arr, &size, ele, pos);
                    printf("Element inserted successfully.\n");
                }
                break;
            
            case 3:
                if (size == 0) {
                    printf("Array is empty.\n");
                } else {
                    printf("Enter the position to delete: ");
                    scanf("%d", &pos);
                    if (pos < 0 || pos >= size) {
                        printf("Invalid position.\n");
                    } else {
                        arr = delete(arr, &size, pos);
                        printf("Element deleted successfully.\n");
                    }
                }
                break;
            
            case 4: {
                int *arr2 = NULL;
                int size2 = 0;
                
                printf("Enter the number of elements for the second array: ");
                scanf("%d", &size2);
                arr2 = (int *)malloc(size2 * sizeof(int));
                
                printf("Enter the elements of the second array:\n");
                for (int i = 0; i < size2; i++) {
                    scanf("%d", &arr2[i]);
                }
                
                int *mergedArr = merge(arr, size, arr2, size2);
                printf("Arrays merged successfully.\n");
                
                printf("Merged array: ");
                for (int i = 0; i < size + size2; i++) {
                    printf("%d ", mergedArr[i]);
                }
                printf("\n");
                
                free(mergedArr);
                free(arr2);
                break;
            }
            
            case 5:
                free(arr);
                printf("Exiting the program.\n");
                return 0;
            
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}

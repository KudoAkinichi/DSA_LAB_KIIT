#include<stdio.h>
int main(){
    int *ptr,n;
    printf("Enter no. of elements:");
    scanf("%d",&n);
    ptr=(int*)malloc(n*sizeof(int));
    
    printf("Enter the elements of the array:\n");
    for(int i=0;i<n;i++)
    scanf("%d",(ptr+i));
    
    printf("Original array:\n");
    for(int i=0;i<n;i++){
        printf("%d\t",ptr[i]);
    }
    
    printf("\nReversed array is as follows:\n");
    for(int i=n-1;i>=0;i--){
        printf("%d\t",ptr[i]);
    }
    free(ptr);
}
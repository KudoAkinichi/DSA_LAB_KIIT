#include<stdio.h>
#include<stdlib.h>
int main(){
    int arr[20],n,i,j,k;
    printf("Enter no. of elements:");
    scanf("%d",&n);
    
    
    printf("Enter the elements of the array:\n");
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);

    for(i=0;i<n;i++){
        for(j=i+1;j<n-1;j++){
            if(arr[i]==arr[j]){
                for(k=j;k<n-1;k++)
                arr[k]=arr[k+1];
                n=n-1;
                j--;
            }
        }
    }
    
    printf("Unique elements of the array:\n");
    for(i=0;i<n;i++)
    printf("%d",arr[i]);
    
}
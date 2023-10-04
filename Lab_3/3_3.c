//WAP to represent the polynomial of single variable using 1-D array and perform the addition of two polynomial equations.

#include<stdio.h>
int main(){
    int maxd1;
    printf("Enter maximum degree of polynomial : ");
    scanf("%d", &maxd1);
    int poly1[maxd1];
    printf("Enter Polynimial 1:\n");
    for (int i = 0; i <= maxd1; i++){
        printf("Enter the Coefficient of x^%d: ", i);
        scanf("%d", &poly1[i]);
    }
    int poly2[maxd1];
    printf("Enter Polynimial 2:\n");
    for (int i = 0; i <= maxd1; i++){
        printf("Enter the Coefficient of x^%d:- ", i);
        scanf("%d", &poly2[i]);
    }
    int i;
    int maxd2 = maxd1;
    int arr[maxd2];

    for (i = 0; i <= maxd2; i++) {
        arr[i] = 0;
    }
    for (i = 0; i <= maxd1; i++) {
        arr[i] += poly1[i];
    }

    for (i = 0; i <= maxd1; i++) {
        arr[i] += poly2[i];
    }

    printf("Polynomial Equation after Addition:- ");
    for (i = maxd2; i >0 ; i--)
    {
        printf("%dx^%d + ", arr[i],i);
    }
    printf("%dx^%d  ", arr[i],i);
    return 0; 
}

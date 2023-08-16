#include <stdio.h>

void compareNumbers(int *num1, int *num2) {
    if (*num1 == *num2) {
        printf("Both numbers are equal.\n");
    } else if (*num1 > *num2) {
        printf("First number (%d) is greater than the second number (%d).\n", *num1, *num2);
    } else {
        printf("Second number (%d) is greater than the first number (%d).\n", *num2, *num1);
    }
}

int main() {
    int num1, num2;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    compareNumbers(&num1, &num2);

    return 0;
}
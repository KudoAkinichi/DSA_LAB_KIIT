#include <stdio.h>
#include <stdlib.h>

int isPrime(int num) {
    if (num <= 1) {
        return 0; // Not prime
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return 0; // Not prime
        }
    }
    return 1; // Prime
}

int main() {
    int n;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int *array = (int *)malloc(n * sizeof(int));
    
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &array[i]);
    }
    
    int sumPrime = 0;
    for (int i = 0; i < n; ++i) {
        if (isPrime(array[i])) {
            sumPrime += array[i];
        }
    }
    
    printf("Sum of prime elements: %d\n", sumPrime);
    
    free(array);
    
    return 0;
}
